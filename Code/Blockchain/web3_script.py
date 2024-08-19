from web3 import Web3

# Connect to the Ganache local blockchain
w3 = Web3(Web3.HTTPProvider('http://127.0.0.1:7545'))

# Check if connected to the network
if not w3.is_connected():
    raise Exception("Failed to connect to the network")

# Replace with your contract's address and ABI
contract_address = "0x6DE47d335b1124C70a56A0442B22BF0D734b2E15"
contract_abi = [
	{
		"inputs": [],
		"name": "createPlatoon",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_trustScore",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_speed",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_x",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_y",
				"type": "uint256"
			}
		],
		"name": "createVehicle",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_platoonId",
				"type": "uint256"
			},
			{
				"internalType": "string",
				"name": "_command",
				"type": "string"
			}
		],
		"name": "issueCommand",
		"outputs": [],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_platoonId",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_vehicleId",
				"type": "uint256"
			}
		],
		"name": "joinPlatoon",
		"outputs": [],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_platoonId",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_vehicleId",
				"type": "uint256"
			}
		],
		"name": "leavePlatoon",
		"outputs": [],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_vehicleId",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_platoonId",
				"type": "uint256"
			},
			{
				"internalType": "bool",
				"name": "canJoin",
				"type": "bool"
			}
		],
		"name": "logPlatoonPossibility",
		"outputs": [
			{
				"internalType": "string",
				"name": "",
				"type": "string"
			}
		],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256[]",
				"name": "_trustScores",
				"type": "uint256[]"
			},
			{
				"internalType": "uint256[]",
				"name": "_speed",
				"type": "uint256[]"
			},
			{
				"internalType": "uint256[]",
				"name": "_x",
				"type": "uint256[]"
			},
			{
				"internalType": "uint256[]",
				"name": "_y",
				"type": "uint256[]"
			}
		],
		"stateMutability": "nonpayable",
		"type": "constructor"
	},
	{
		"anonymous": False,
		"inputs": [
			{
				"indexed": False,
				"internalType": "uint256",
				"name": "vehicleId",
				"type": "uint256"
			}
		],
		"name": "LeaderElected",
		"type": "event"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_vehicleId",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "_otherVehicleId",
				"type": "uint256"
			}
		],
		"name": "overtake",
		"outputs": [],
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"anonymous": False,
		"inputs": [
			{
				"indexed": False,
				"internalType": "uint256",
				"name": "vehicleId",
				"type": "uint256"
			}
		],
		"name": "RestrictedStatus",
		"type": "event"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_platoonId",
				"type": "uint256"
			}
		],
		"name": "getPlatoonLeader",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "_platoonId",
				"type": "uint256"
			}
		],
		"name": "getPlatoonVehicles",
		"outputs": [
			{
				"internalType": "uint256[]",
				"name": "",
				"type": "uint256[]"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [],
		"name": "platoonCount",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"name": "platoons",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "id",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "leaderId",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [],
		"name": "selectTwoVehicles",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [],
		"name": "vehicleCount",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"name": "vehicles",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "trustScore",
				"type": "uint256"
			},
			{
				"internalType": "bool",
				"name": "canOvertake",
				"type": "bool"
			},
			{
				"internalType": "bool",
				"name": "isRestricted",
				"type": "bool"
			},
			{
				"internalType": "uint256",
				"name": "speed",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "x",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "y",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	}
]  # ABI generated from your Solidity contract

# Instantiate the contract
contract = w3.eth.contract(address=contract_address, abi=contract_abi)

# Define the sender account (replace with your own account)
sender_account = w3.eth.accounts[0]

# Function to calculate Manhattan distance
def calculate_manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

# Function to execute selectTwoVehicles and process the result
def process_two_vehicles():
    # Call the selectTwoVehicles function
    vehicle_ids = contract.functions.selectTwoVehicles().call()

    # Fetch details of the two vehicles
    vehicle_1 = contract.functions.vehicles(vehicle_ids[0]).call()
    vehicle_2 = contract.functions.vehicles(vehicle_ids[1]).call()

    # Extract necessary data: speed, x, and y coordinates
    speed_1, x1, y1 = vehicle_1[3], vehicle_1[4], vehicle_1[5]
    speed_2, x2, y2 = vehicle_2[3], vehicle_2[4], vehicle_2[5]

    # Calculate Manhattan distance
    distance = calculate_manhattan_distance(x1, y1, x2, y2)

    # Check if the vehicles can join the platoon
    can_join = (distance < 5) and (speed_1 % 10 < 10) and (speed_2 % 10 < 10)

    return vehicle_ids[0], vehicle_ids[1], can_join

# Main function to execute the script
def main():
    vehicle_id_1, vehicle_id_2, can_join = process_two_vehicles()

    # Log the platoon possibility for one of the vehicles and platoon 1
    tx_hash = contract.functions.logPlatoonPossibility(vehicle_id_1, 1, can_join).transact({'from': sender_account})

    # Wait for the transaction to be mined
    receipt = w3.eth.wait_for_transaction_receipt(tx_hash)

    print(f"Transaction successful with hash: {tx_hash.hex()}")

if _name_ == "_main_":
    main()