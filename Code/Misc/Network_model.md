# Network Architecture 

1. **Intra-Platoon Communication**
   - **Leader-Follower Model**: The platoon leader broadcasts commands to follower vehicles. These commands include maneuvers like lane changes, speed adjustments, or emergency stops. Intra-platoon communication ensures synchronized execution of these commands, maintaining the integrity and safety of the platoon.
   - **Trust Score Management**: Each vehicle within a platoon maintains a trust score, which is updated based on the execution of commands and adherence to protocols. Vehicles with higher trust scores may be selected for critical roles within the platoon, such as acting as a backup leader.

2. **Inter-Platoon Communication**
   - **Dynamic Grouping**: Platoon leaders within communication range of each other come under an "Inter-Platoon Communication Group" (IPCG). A leader can be in multiple IPCGs. Every platoon leader has its own IPCG range, as it is at the center of it's own radio broadcasts. Within an IPCG, every other platoon leader is able to receive communication from the leader that "owns" the IPCG (is situated at it's center).
   - **Command Exchange Protocol**: In critical situations (e.g., obstacle detection or the approach of an emergency vehicle), the affected platoon leader sends a "Command Exchange Request" to other leaders within the IPCG. This request is validated, and a consensus is reached on the appropriate action to take.
   - **Consensus Mechanism**: Once a consensus is reached, the command is executed across all involved platoons. If consensus cannot be achieved within a critical time window, the originating leader may execute the command with a "Caution Flag" indicating potential risks.

3. **Blockchain Integration**
   - **Local Blockchain Management**: Each platoon maintains a local blockchain to record transactions and events, such as vehicle joins, leaves, or maneuvers. This blockchain is decentralized, with each vehicle in the platoon holding a copy. The blockchain is updated in real-time to reflect the current state of the platoon.
   - **Event Logging**: All significant events, such as emergency maneuvers or trust score changes, are logged on the blockchain. This provides a transparent and immutable record that can be audited by a Trust Authority (TA) if needed.
   - **Trust Authority (TA)**: A central authority that holds records of vehicle pseudonyms and their mappings. The TA ensures that even as vehicles change pseudonyms, they remain traceable for auditing purposes. This prevents vehicles from evading accountability by frequently changing their identities.

4. **Security Considerations**
   - **Pseudonym Management**: Vehicles use pseudonyms to protect their privacy. The TA maintains a list of all known pseudonyms of the vehicles from registration to its current identity. This ensures conditional privacy, by hiding its identity from the rest of the network but not the TA.
   - **Physical Attestation**: Vehicles use their physical attributes (e.g., speed, location) to verify the accuracy of information within the platoon. This mechanism helps detect false data, ensuring the reliability of the system.

5. **Emergency Response and Law Enforcement Integration**
   - **Priority Handling**: Emergency vehicles and law enforcement are given priority within the network. Upon detection, platoons automatically move aside and reduce speed to allow these vehicles to pass without obstruction.

6. **Handling of Large Vehicles**
   - **Special Protocols**: Large vehicles, due to their size and movement restrictions, are treated differently within the network. They are assigned specific lanes and may form their platoons to avoid conflicts with smaller vehicles. Normal platoons treat these vehicles as dynamic obstacles, adjusting their maneuvers accordingly.

7. **Scalability and Efficiency**
   - **Reduced Overhead**: By removing RSUs, the network architecture significantly reduces the costs associated with setup, maintenance, and management. The system relies on direct vehicle-to-vehicle communication, which scales more efficiently as the number of vehicles increases.
   - **Time and Space Complexity**: The proposed architecture reduces the time complexity from O(N^2) to O(N) for communication and decision-making processes, allowing the system to handle large numbers of vehicles without significant delays or computational burdens.
