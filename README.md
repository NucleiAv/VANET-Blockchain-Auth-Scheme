# VANET-Blockchain-Auth-Scheme
Techstack - Python, C, Solidity, Plexe, etc

## Vanet Security
Vehicular Ad Hoc Networks (VANETs) primarily aim to enhance road safety by minimizing accidents, which in turn improves traffic conditions and saves lives. Besides safety, VANETs offer a variety of services such as internet access, weather updates, and geo-location information, adding comfort, convenience, and entertainment to the travel experience.

VANETs are guided by several standards, including IEEE 1609.x, 802.11p, and Wireless Access in Vehicular Environment (WAVE). WAVE, built on a layered architecture, enables devices compliant with IEEE 802.11 to operate in the Dedicated Short Range Communication (DSRC) band. The IEEE 1609 family specifies the architecture, protocol set, and interfaces, focusing on secure message exchange to ensure interoperability in VANET environments.

The VANET architecture includes On-Board Units (OBUs) in vehicles and Road Side Units (RSUs) along roads, though RSUs are less emphasized in newer models. VANET communication is categorized into Vehicle-to-Vehicle (V2V) and Vehicle-to-Infrastructure (V2I) interactions. Nodes, which represent vehicles or roadside equipment, use DSRC channels for communication.

Trust management is vital in VANETs for verifying the reliability of vehicles and the messages they exchange, thereby preventing false emergency alerts. While reputation certificates and digital signatures are promising approaches, many current schemes neglect privacy preservation, a critical issue due to the risk of disclosing sensitive information. Effective privacy preservation should address anonymity, unlinkability, and traceability while integrating with trust management.

Smart vehicles in a Vehicular Ad-hoc Network (VANET) are designed to enhance driving safety and efficiency through several key features. They are equipped with basic sensors like front and rear radar to gather additional information from their surroundings that drivers might miss. Positioning systems such as GPS are essential for accurate navigation and driving assistance. These vehicles also have advanced communication systems with multiple interfaces, a central computing unit, and an Event Recording Device (ERD) similar to an aircraft's black box, which records crucial data for post-incident analysis.

Safety in VANETs is paramount due to the direct risk to human lives. Unlike traditional networks, where confidentiality, integrity, and availability are the main concerns, VANETs focus on ensuring vital information remains unaltered and promptly delivered. The network's dynamic nature, with frequent vehicle arrivals and departures, short connection durations, and reliance on wireless communication, adds complexity to maintaining security, making VANETs susceptible to attacks that could have serious or even fatal consequences.

## Motivation and Our Contributions

The thesis "Secure Blockchains for Cyber-Physical Systems" introduced a pioneering blockchain-based approach to securing VANETs by utilizing platoons and eliminating RSUs. However, it left critical gaps unaddressed, particularly the lack of inter-platoon communication, inadequate management of large vehicle dynamics, and insufficient traffic handling protocols. These shortcomings motivated us to enhance the existing scheme by introducing robust inter-platoon communication, dynamic trust management, and advanced traffic management features, making the system more secure, efficient, and scalable for intelligent transportation.

The contributions of this article/paper are as follows -

1. Inter-Platoon Communication Protocol: We propose a novel protocol that enables seamless vehicle coordination for tasks like lane changes, accident prevention, and traffic management. This addresses a key gap in VANET schemes, allowing vehicles to operate cohesively without RSUs.

2. Transparency and Accountability: Our model introduces detailed event logging within the VANET system, enhancing transparency by tracking command execution and outcomes.

3. Large Vehicle Dynamics Management: Specialized protocols are introduced to manage large vehicle dynamics, improving traffic safety and efficiency.

4. Advanced Traffic Management: Our approach integrates advanced lane management, dynamic obstacle detection, and adaptive speed regulation to handle complex traffic conditions effectively.

## Network Model

### Overview
The proposed design architecture focuses on enhancing VANETs (Vehicular Ad-hoc Networks) by addressing the limitations of [1]. The enhancements include the removal of RSUs (Roadside Units), introducing a platoon-based communication system, and ensuring real-time, secure communication and coordination among vehicles.
### System Components
1) Platoons: Groups of vehicles traveling together, based on their speed, distance and direction of travel, with a designated leader responsible for communication and command execution.
2) Platoon Leaders: Vehicles designated as leaders within each platoon, managing both intra-platoon and inter-platoon communications.
3) Trust Authority (TA): A centralized entity responsible for managing vehicle registrations, maintaining pseudonym records, and auditing the system.
4) Blockchain: A distributed ledger system used for event logging, trust score management, and ensuring transparency and accountability within the system.
### Key Architectural Features
• Platoon Formation and Management
– Vehicles form platoons based on proximity and similar travel paths. Each platoon has a leader responsible for issuing commands and verifying actions.
– Platoon leaders are designated based on trust scores, with higher-scoring vehicles taking on leadership roles.
• Intra-Platoon Communication
– Communication within a platoon is managed by the leader, who processes and broadcasts commands to ensure synchronized execution.
– Each vehicle maintains a local copy of the blockchain, recording transactions and events within the platoon.
• Inter-Platoon Communication
– Platoons communicate with each other using an Inter-Platoon Communication Protocol (IPCP), managed by platoon leaders.
– In critical situations, such as emergencies or obstacles, leaders exchange ”Command Exchange Requests” to synchronize actions across platoons.
• Trust Management and Pseudonym Handling
– The Trust Authority (TA) maintains a record of vehicle pseudonyms, enabling traceability while preserving conditional privacy.
– Vehicles can change pseudonyms over time, but the TA keeps track of current and past pseudonyms to ensure that reports can be validated regardless of the order they’re received in.
– Trust scores are dynamically adjusted based on vehicle behavior, with penalties for malicious actions or false signals.
• Event Logging and Blockchain Integration
– All critical events, such as maneuvers, lane changes, and emergency responses, are logged as transactions on the blockchain.
– The blockchain ensures that events are immutable, verifiable, and transparent, contributing to the overall security and reliability of the VANET system.
• Handling of Large Vehicles
– Large vehicles are managed separately from standard platoons due to their size and braking characteristics.
– These vehicles are assigned specific lanes or treated as dynamic obstacles, with platoons adjusting their behavior to accommodate them.
### Consensus Mechanism
• The architecture uses a lightweight consensus mechanism tailored for VANETs, replacing traditional Proof-of-Work (PoW) with a more efficient method suitable for real-time transactions.
• Consensus is reached quickly within and between platoons, ensuring that commands are executed promptly without significant computational overhead.
### Security and Scalability
• The removal of RSUs significantly reduces the cost and complexity of deploying and maintaining the VANET system.
• The system is scalable, capable of handling large numbers of vehicles without overloading communication channels or processing resources.
• Security is reinforced through the use of blockchain technology, ensuring that all actions are traceable and verifiable, reducing the risk of attacks or malicious behavior.
### Network Architecture
• Intra-Platoon Communication
– Leader-Follower Model: The platoon leader broadcasts commands to follower vehicles. These commands include maneuvers like lane changes, speed adjustments, or emergency stops. Intra-platoon communication ensures synchronized execution of these commands, maintaining the integrity and safety of the platoon.
– Trust Score Management: Each vehicle within a platoon maintains a trust score, which is updated based on the execution of commands and adherence to protocols. Vehicles with higher trust scores may be selected for critical roles within the platoon, such as acting as a backup leader.
• Inter-Platoon Communication
– Dynamic Grouping: Platoon leaders within communication range of each other come under an ”Inter-Platoon Communication Group” (IPCG). A leader can be in multiple IPCGs. Every platoon leader has its own IPCG range, as it is at the center of it’s own radio broadcasts. Within an IPCG, every other platoon leader is able to receive communication from the leader that ”owns” the IPCG (is situated at it’s center).
– Command Exchange Protocol: In critical situations (e.g., obstacle detection or the approach of an emergency vehicle), the affected platoon leader sends a ”Command Exchange Request” to other leaders within the IPCG. This request is validated, and a consensus is reached on the appropriate action to take.
– Consensus Mechanism: Once a consensus is reached, the command is executed across all involved platoons. If consensus cannot be achieved within a critical time window, the originating leader may execute the command with a ”Caution Flag” indicating potential risks.
• Blockchain Integration
– Local Blockchain Management: Each platoon maintains a local blockchain to record transactions and events, such as vehicle joins, leaves, or maneuvers. This blockchain is decentralized, with each vehicle in the platoon holding a copy. The blockchain is updated in real-time to reflect the current state of the platoon.
– Event Logging: All significant events, such as emergency maneuvers or trust score changes, are logged on the blockchain. This provides a transparent and immutable record that can be audited by a Trust Authority (TA) if needed.
– Trust Authority (TA): A central authority that holds records of vehicle pseudonyms and their mappings. The TA ensures that even as vehicles change pseudonyms, they remain traceable for auditing purposes. This prevents vehicles from evading accountability by frequently changing their identities.
• Security Consideration
– Pseudonym Management: Vehicles use pseudonyms to protect their privacy. The TA maintains a list of all known pseudonyms of the vehicles from registration to its current identity. This ensures conditional privacy, by hiding its identity from the rest of the network but not the TA.
– Physical Attestation: Vehicles use their physical attributes (e.g., speed, location) to verify the accuracy of information within the platoon. This mechanism helps detect false data, ensuring the reliability of the system.
• Emergency Response and Law Enforcement Integration
– Priority Handling: Emergency vehicles and law enforcement are given priority within the network. Upon detection, platoons automatically move aside and reduce speed to allow these vehicles to pass without obstruction.
• Handling of Large Vehicles
– Special Protocols: Large vehicles, due to their size and movement restrictions, are treated differently within the network. They are assigned specific lanes and may form their platoons to avoid conflicts with
smaller vehicles. Normal platoons treat these vehicles as dynamic obstacles, adjusting their maneuvers accordingly.
• Scalability and Efficiency
– Reduced Overhead: By removing RSUs, the network architecture significantly reduces the costs associated with setup, maintenance, and management. The system relies on direct vehicle-to-vehicle communication, which scales more efficiently as the number of vehicles increases.
