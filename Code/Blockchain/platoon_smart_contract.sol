// SPDX-License-Identifier: MIT
pragma solidity ^0.8.4;

// VANET contract that implements IVehicleFactory.

contract VANET {

    // Structure to define a Vehicle.
    struct Vehicle {
        uint trustScore;  // The trust score of the vehicle, used for various logic decisions.
        bool canOvertake; // Flag indicating whether the vehicle has permission to overtake another vehicle.
        bool isRestricted; // Indicates if the vehicle is in restricted status
        uint speed; // Speed of the vehicle
        uint x; // x coordinate of the vehicle
        uint y; // y coordinate of the vehicle
    }

    // Structure to define a Platoon.

    struct Platoon {
        uint id;             // Unique ID for the platoon.
        uint[] vehicleIds;   // Array to store the IDs of vehicles in the platoon.
        mapping(uint => bool) vehiclePresence; // Mapping to quickly check if a vehicle is part of the platoon.
        uint leaderId;       // ID of the platoon leader.
    }

    // Mapping to store vehicles by their ID.

    mapping(uint => Vehicle) public vehicles;
    uint public vehicleCount; // Counter to keep track of the number of vehicles created.

    // Mapping to store platoons by their ID.

    mapping(uint => Platoon) public platoons;
    uint public platoonCount; // Counter to keep track of the number of platoons created.

    // Constructor to initialize the contract with a dynamic number of vehicles.
    // This constructor takes an array of trust scores and creates the corresponding number of vehicles upon deployment.
    // Time Complexity: O(n) where n is the number of vehicles to be created.
    // Space Complexity: O(n) due to storage of n vehicles.

    constructor(uint[] memory _trustScores, uint[] memory _speed, uint[] memory _x, uint[] memory _y) {
        uint minLength = _trustScores.length;
        
        if (_speed.length < minLength) {
            minLength = _speed.length;
        }
        if (_x.length < minLength) {
            minLength = _x.length;
        }
        if (_y.length < minLength) {
            minLength = _y.length;
        }

        for (uint i = 0; i < minLength; i++) {
            createVehicle(_trustScores[i], _speed[i], _x[i], _y[i]);
        }
    }

    // Function to create a new vehicle.
    // Takes a trust score as input, increments the vehicle count, and stores the new vehicle in the mapping.
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    function createVehicle(uint _trustScore, uint _speed, uint _x, uint _y) public returns (uint) {
        vehicleCount++; // Increment vehicle counter.
        vehicles[vehicleCount] = Vehicle(_trustScore, false, false, _speed, _x, _y); // Create a new Vehicle struct and store it in the mapping.
        return vehicleCount; // Return the ID of the newly created vehicle.
    }

    // Function to check and set overtake permission for a vehicle.
    // Takes in the IDs of the vehicle requesting to overtake and the vehicle it wants to overtake.
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    function overtake(uint _vehicleId, uint _otherVehicleId) public {

        // Validate that the vehicle ID is within the range of existing vehicles.

        require(_vehicleId > 0 && _vehicleId <= vehicleCount, "Invalid vehicle ID");
        require(_otherVehicleId > 0 && _otherVehicleId <= vehicleCount, "Invalid other vehicle ID");
        
        // Ensure a vehicle isn't trying to overtake itself.

        require(_vehicleId != _otherVehicleId, "Cannot overtake itself");
        
        // The overtake logic: allow overtaking only if the requesting vehicle has a higher trust score.

        require(vehicles[_vehicleId].trustScore > vehicles[_otherVehicleId].trustScore, "Trust score is not sufficient to overtake.");
        
        // Grant overtake permission to the requesting vehicle and revoke it from the other vehicle.

        vehicles[_vehicleId].canOvertake = true;
        vehicles[_otherVehicleId].canOvertake = false;
    }

    // Function to create a new platoon.
    // Increments the platoon count and initializes a new platoon.
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    function createPlatoon() public returns (uint) {
        platoonCount++; // Increment platoon counter.
        platoons[platoonCount].id = platoonCount; // Initialize the new platoon with its ID.
        return platoonCount; // Return the ID of the newly created platoon.
    }


    // Function to join a platoon based on dynamic trust score comparison.
    // Takes in the IDs of the platoon and the vehicle that wants to join.
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1) (ignores the storage already used by vehicles in the platoon)

    function joinPlatoon(uint _platoonId, uint _vehicleId) public {

        // Validate that the platoon ID and vehicle ID are within valid ranges.

        require(_platoonId > 0 && _platoonId <= platoonCount, "Invalid platoon ID");
        require(_vehicleId > 0 && _vehicleId <= vehicleCount, "Invalid vehicle ID");

        // Ensure the vehicle can only join if it has the highest trust score in the platoon.

        require(vehicles[_vehicleId].trustScore >= 5, "Trust score is not sufficient to join the platoon.");
        
        // Add the vehicle to the platoon's vehicle list.

        platoons[_platoonId].vehicleIds.push(_vehicleId);

        // Mark the vehicle as present in the platoon using the mapping for quick lookup.

        platoons[_platoonId].vehiclePresence[_vehicleId] = true;

        // Update the platoon leader if necessary.

        updatePlatoonLeader(_platoonId);
    }

    // Function to leave a platoon if the trust score is above a threshold.
    // Takes in the IDs of the platoon and the vehicle that wants to leave.
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1) (ignores the storage already used by vehicles in the platoon)

    function leavePlatoon(uint _platoonId, uint _vehicleId) public {

        // Validate that the platoon ID and vehicle ID are within valid ranges.

        require(_platoonId > 0 && _platoonId <= platoonCount, "Invalid platoon ID");
        require(_vehicleId > 0 && _vehicleId <= vehicleCount, "Invalid vehicle ID");

        // Ensure the vehicle is actually part of the platoon before attempting to leave.

        require(platoons[_platoonId].vehiclePresence[_vehicleId], "Vehicle not in the platoon");
        
        // Ensure the vehicle has a sufficient trust score to leave the platoon.

        require(vehicles[_vehicleId].trustScore > 1, "Trust score is not sufficient to leave the platoon.");
        
        // Call the internal function to remove the vehicle from the platoon.

        removeVehicleFromPlatoon(_platoonId, _vehicleId);

        // Update the platoon leader if necessary.

        updatePlatoonLeader(_platoonId);
    }

   // Function to check if there is any possiblity to create a new platoon.
   // It checks this based on speed and distance contraints

    function logPlatoonPossibility(uint _vehicleId, uint _platoonId, bool canJoin) public returns (string memory) {
            if (canJoin) {
                if (platoonCount == 0) {
                    createPlatoon();
                    return "Platoon created successfully.";
                } else {
                    joinPlatoon(_platoonId, _vehicleId);
                    return "Joined the existing platoon successfully.";
                }
            } 
            else {
                return "Either distance is not in the vicinity of platoon or speed is too high/low with regard to the platoon the vehicle wishes to be a part of.";
            }
    }

    // Function to select two vehicles

    function selectTwoVehicles() public view returns (uint, uint) {
        require(vehicleCount >= 2, "Not enough vehicles registered");

        // Generate two random vehicle IDs

        uint vehicleId1 = uint(keccak256(abi.encodePacked(block.timestamp, block.difficulty))) % vehicleCount + 1;
        uint vehicleId2 = uint(keccak256(abi.encodePacked(block.timestamp, block.difficulty, vehicleId1))) % vehicleCount + 1;

        // Ensure the two IDs are not the same

        while (vehicleId1 == vehicleId2) {
            vehicleId2 = uint(keccak256(abi.encodePacked(block.timestamp, block.difficulty, vehicleId2))) % vehicleCount + 1;
        }

        return (vehicleId1, vehicleId2);
    }



    // Function to get a list of vehicles in a specific platoon.
    // Takes in the platoon ID and returns an array of vehicle IDs.
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    function getPlatoonVehicles(uint _platoonId) public view returns (uint[] memory) {

        // Validate that the platoon ID is within the range of existing platoons.

        require(_platoonId > 0 && _platoonId <= platoonCount, "Invalid platoon ID");

        // Return the list of vehicles in the specified platoon.

        return platoons[_platoonId].vehicleIds;
    }

    // Function to get the current platoon leader.
    // Takes in the platoon ID and returns the ID of the current platoon leader.
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    function getPlatoonLeader(uint _platoonId) public view returns (uint) {

        // Validate that the platoon ID is within the range of existing platoons.

        require(_platoonId > 0 && _platoonId <= platoonCount, "Invalid platoon ID");

        // Return the ID of the current platoon leader.

        return platoons[_platoonId].leaderId;
    }

    // Internal function to remove a vehicle from a platoon.
    // This is called within the leavePlatoon function to handle the actual removal process.
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1) (ignores the storage already used by vehicles in the platoon)

    function removeVehicleFromPlatoon(uint _platoonId, uint _vehicleId) internal {

        uint[] storage vehicleIds = platoons[_platoonId].vehicleIds; // Get the list of vehicles in the platoon.
        for (uint i = 0; i < vehicleIds.length; i++) {
            if (vehicleIds[i] == _vehicleId) {

                // If the vehicle is found, replace it with the last vehicle in the list to avoid gaps.

                vehicleIds[i] = vehicleIds[vehicleIds.length - 1];
                vehicleIds.pop(); // Remove the last vehicle, which is now duplicated.
                break;
            }
        }

        // Remove the vehicle presence record.
        delete platoons[_platoonId].vehiclePresence[_vehicleId];
    }

    // Internal function to get the maximum trust score among vehicles in a platoon.
    // Takes in the platoon ID and returns the maximum trust score.
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1)
    function getMaxTrustScore(uint _platoonId) internal view returns (uint) {
        uint maxTrustScore = 0;
        uint[] memory vehicleIds = platoons[_platoonId].vehicleIds;
        for (uint i = 0; i < vehicleIds.length; i++) {
            uint vehicleId = vehicleIds[i];
            if (vehicles[vehicleId].trustScore > maxTrustScore) {
                maxTrustScore = vehicles[vehicleId].trustScore;
            }
        }
        return maxTrustScore;
    }


    // Internal function to update the leader of a platoon.
    // This function selects the vehicle with the highest trust score as the new leader.
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1)

    function updatePlatoonLeader(uint _platoonId) internal {
        uint maxTrustScore = 0;
        uint newLeaderId = 0;
        uint[] memory vehicleIds = platoons[_platoonId].vehicleIds;
        for (uint i = 0; i < vehicleIds.length; i++) {
            uint vehicleId = vehicleIds[i];
            if (vehicles[vehicleId].trustScore > maxTrustScore) {
                maxTrustScore = vehicles[vehicleId].trustScore;
                newLeaderId = vehicleId;
            }
        }

        // Update the platoon's leader ID.
        platoons[_platoonId].leaderId = newLeaderId;
    }
    
    // Functions for intra-platoon communication protocol
    // Issues a command to the platoon
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1)

    function issueCommand(uint _platoonId, string memory _command) public {
        require(_platoonId > 0 && _platoonId <= platoonCount, "Invalid platoon ID");
        uint[] memory vehicleIds = platoons[_platoonId].vehicleIds;

        for (uint i = 0; i < vehicleIds.length; i++) {
            uint vehicleId = vehicleIds[i];
            if (!verifyCommand(vehicleId, _command)) {
                vehicles[vehicleId].isRestricted = true;
            }
        }

        // Run the Platoon Block Creation protocol
        runPlatoonBlockCreationProtocol(_platoonId);
    }

    // Verifies if a command is valid for a vehicle
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    function verifyCommand(uint _vehicleId, string memory _command) internal view returns (bool) {
        // Implement command verification logic here (dummy implementation for now)
        return true; // Assuming all commands are valid for simplicity
    }

    // Runs the Platoon Block Creation protocol
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1)

    function runPlatoonBlockCreationProtocol(uint _platoonId) internal {
        uint[] memory vehicleIds = platoons[_platoonId].vehicleIds;
        for (uint i = 0; i < vehicleIds.length; i++) {
            uint vehicleId = vehicleIds[i];
            if (vehicles[vehicleId].isRestricted) {
                emit RestrictedStatus(vehicleId);
                // Prevent further transactions from restricted vehicles
                // Other logic to handle restricted status
            }
        }
        electNewLeader(_platoonId);
    }

    // Elects a new leader based on trust scores
    // Time Complexity: O(n) where n is the number of vehicles in the platoon.
    // Space Complexity: O(1)

    function electNewLeader(uint _platoonId) internal {
        uint maxTrustScore = getMaxTrustScore(_platoonId);
        uint[] memory vehicleIds = platoons[_platoonId].vehicleIds;
        uint highestTrustVehicleId = 0;

        for (uint i = 0; i < vehicleIds.length; i++) {
            uint vehicleId = vehicleIds[i];
            if (vehicles[vehicleId].trustScore == maxTrustScore) {
                highestTrustVehicleId = vehicleId;
                break;
            }
        }

        if (highestTrustVehicleId != 0) {
            platoons[_platoonId].leaderId = highestTrustVehicleId;
            emit LeaderElected(highestTrustVehicleId);
        }
    }

    event RestrictedStatus(uint vehicleId);
    event LeaderElected(uint vehicleId);
}
