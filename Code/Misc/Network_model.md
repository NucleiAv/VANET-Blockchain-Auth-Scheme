# Network Architecture 

1. **Platoon-Based Structure**
   - **Platoons**: Vehicles are organized into platoons, each led by a designated leader. Platoons consist of vehicles that are closely grouped together, moving in the same direction on a roadway. The leader vehicle is responsible for managing intra-platoon communication, coordinating maneuvers, and handling external communications with other platoons.

2. **Intra-Platoon Communication**
   - **Leader-Follower Model**: The platoon leader broadcasts commands to follower vehicles. These commands include maneuvers like lane changes, speed adjustments, or emergency stops. Intra-platoon communication ensures synchronized execution of these commands, maintaining the integrity and safety of the platoon.
   - **Trust Score Management**: Each vehicle within a platoon maintains a trust score, which is updated based on the execution of commands and adherence to protocols. Vehicles with higher trust scores may be selected for critical roles within the platoon, such as acting as a backup leader.

3. **Inter-Platoon Communication**
   - **Dynamic Grouping**: When platoons come within proximity of each other, the leaders of these platoons form an Inter-Platoon Communication Group (IPCG). This temporary communication group allows for real-time coordination between platoons, enabling efficient traffic management and collision avoidance.
   - **Command Exchange Protocol**: In critical situations (e.g., obstacle detection or the approach of an emergency vehicle), the affected platoon leader sends a "Command Exchange Request" to other leaders within the IPCG. This request is validated, and a consensus is reached on the appropriate action to take.
   - **Consensus Mechanism**: Once a consensus is reached, the command is executed across all involved platoons. If consensus cannot be achieved within a critical time window, the originating leader may execute the command with a "Caution Flag" indicating potential risks.

4. **Blockchain Integration**
   - **Local Blockchain Management**: Each platoon maintains a local blockchain to record transactions and events, such as vehicle joins, leaves, or maneuvers. This blockchain is decentralized, with each vehicle in the platoon holding a copy. The blockchain is updated in real-time to reflect the current state of the platoon.
   - **Event Logging**: All significant events, such as emergency maneuvers or trust score changes, are logged on the blockchain. This provides a transparent and immutable record that can be audited by a Trust Authority (TA) if needed.
   - **Trust Authority (TA)**: A central authority that holds records of vehicle pseudonyms and their mappings. The TA ensures that even as vehicles change pseudonyms, they remain traceable for auditing purposes. This prevents vehicles from evading accountability by frequently changing their identities.

5. **Security Considerations**
   - **Pseudonym Management**: Vehicles use pseudonyms to protect their privacy. The TA maintains a 1-to-1 mapping of pseudonyms from the vehicle's registration to its current identity. This allows for traceability in case of audits while ensuring that vehicles cannot hide malicious behavior by changing pseudonyms.
   - **Physical Attestation**: Vehicles use their physical attributes (e.g., speed, location) to verify the accuracy of information within the platoon. This mechanism helps detect false data, ensuring the reliability of the system.

6. **Emergency Response and Law Enforcement Integration**
   - **Priority Handling**: Emergency vehicles and law enforcement are given priority within the network. Upon detection, platoons automatically move aside and reduce speed to allow these vehicles to pass without obstruction.
   - **Critical Situation Override**: In extreme emergencies, any platoon leader can invoke a "Critical Situation Override" to bypass the consensus process. This allows for immediate action, which is crucial in life-threatening situations.

7. **Handling of Large Vehicles**
   - **Special Protocols**: Large vehicles, due to their size and movement restrictions, are treated differently within the network. They are assigned specific lanes and may form their platoons to avoid conflicts with smaller vehicles. Normal platoons treat these vehicles as dynamic obstacles, adjusting their maneuvers accordingly.

8. **Scalability and Efficiency**
   - **Reduced Overhead**: By removing RSUs, the network architecture significantly reduces the costs associated with setup, maintenance, and management. The system relies on direct vehicle-to-vehicle communication, which scales more efficiently as the number of vehicles increases.
   - **Time and Space Complexity**: The proposed architecture reduces the time complexity from O(N^2) to O(N) for communication and decision-making processes, allowing the system to handle large numbers of vehicles without significant delays or computational burdens.
