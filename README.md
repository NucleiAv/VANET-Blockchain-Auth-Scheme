# VANET-Blockchain-Auth-Scheme

**Techstack**: Python, C++, Solidity, Plexe, R, Shell, etc.

**Note** - This code/repository is a part of the on-going research on "_A Blockchain-based Privacy-Preserving Authentication Scheme for Secure Vehicular Communications_", which we - Anmol Vats, Suryansh Arya and Sharvil Bhatt - are integral members and under-graduate researchers of.

## VANET Security

Vehicular Ad Hoc Networks (VANETs) primarily aim to enhance road safety by minimizing accidents, improving traffic conditions, and saving lives. Besides safety, VANETs offer a variety of services such as internet access, weather updates, and geo-location information, adding comfort, convenience, and entertainment to the travel experience.

VANETs are guided by several standards, including IEEE 1609.x, 802.11p, and Wireless Access in Vehicular Environment (WAVE). WAVE, built on a layered architecture, enables devices compliant with IEEE 802.11 to operate in the Dedicated Short Range Communication (DSRC) band. The IEEE 1609 family specifies the architecture, protocol set, and interfaces, focusing on secure message exchange to ensure interoperability in VANET environments.

The VANET architecture includes On-Board Units (OBUs) in vehicles and Road Side Units (RSUs) along roads, though RSUs are less emphasized in newer models. VANET communication is categorized into Vehicle-to-Vehicle (V2V) and Vehicle-to-Infrastructure (V2I) interactions. Nodes, which represent vehicles or roadside equipment, use DSRC channels for communication.

Trust management is vital in VANETs for verifying the reliability of vehicles and the messages they exchange, thereby preventing false emergency alerts. While reputation certificates and digital signatures are promising approaches, many current schemes neglect privacy preservation, a critical issue due to the risk of disclosing sensitive information. Effective privacy preservation should address anonymity, unlinkability, and traceability while integrating with trust management.

Smart vehicles in a Vehicular Ad-hoc Network (VANET) are designed to enhance driving safety and efficiency through several key features:
- Equipped with basic sensors like front and rear radar to gather additional information from their surroundings.
- Positioning systems such as GPS for accurate navigation and driving assistance.
- Advanced communication systems with multiple interfaces, a central computing unit, and an Event Recording Device (ERD) similar to an aircraft's black box.

**Safety in VANETs** is paramount due to the direct risk to human lives. Unlike traditional networks, where confidentiality, integrity, and availability are the main concerns, VANETs focus on ensuring vital information remains unaltered and promptly delivered. The network's dynamic nature, with frequent vehicle arrivals and departures, short connection durations, and reliance on wireless communication, adds complexity to maintaining security, making VANETs susceptible to attacks that could have serious or even fatal consequences.

## Motivation and Contributions

The thesis _"Secure Blockchains for Cyber-Physical Systems"_ introduced a blockchain-based approach to securing VANETs by utilizing platoons and eliminating RSUs. However, it left critical gaps unaddressed, particularly the lack of inter-platoon communication, inadequate management of large vehicle dynamics, and insufficient traffic handling protocols. These shortcomings motivated us to enhance the existing scheme by introducing:
- Robust inter-platoon communication
- Dynamic trust management
- Advanced traffic management features

The contributions of this paper are as follows:
1. **Inter-Platoon Communication Protocol**: Enables seamless vehicle coordination for tasks like lane changes, accident prevention, and traffic management.
2. **Transparency and Accountability**: Introduces detailed event logging within the VANET system, tracking command execution and outcomes.
3. **Large Vehicle Dynamics Management**: Specialized protocols to manage large vehicle dynamics, improving traffic safety and efficiency.
4. **Advanced Traffic Management**: Integrates advanced lane management, dynamic obstacle detection, and adaptive speed regulation.

## Network Model

### Overview
The proposed design architecture enhances VANETs by addressing the limitations of [1]. The enhancements include:
- Removal of RSUs
- Introducing a platoon-based communication system
- Ensuring real-time, secure communication and coordination among vehicles.

### System Components
1. **Platoons**: Groups of vehicles traveling together based on speed, distance, and direction of travel.
   - Each platoon has a leader responsible for communication and command execution.
2. **Platoon Leaders**: Vehicles designated as leaders within each platoon.
   - Manage both intra-platoon and inter-platoon communications.
3. **Trust Authority (TA)**: A centralized entity responsible for managing vehicle registrations, maintaining pseudonym records, and auditing the system.
4. **Blockchain**: A distributed ledger system used for event logging, trust score management, and ensuring transparency and accountability.

### Key Architectural Features

- **Platoon Formation and Management**  
  - Vehicles form platoons based on proximity and similar travel paths.
  - Each platoon has a leader responsible for issuing commands and verifying actions.
  - Platoon leaders are designated based on trust scores, with higher-scoring vehicles taking on leadership roles.

- **Intra-Platoon Communication**  
  - Communication within a platoon is managed by the leader, who processes and broadcasts commands to ensure synchronized execution.
  - Each vehicle maintains a local copy of the blockchain, recording transactions and events within the platoon.

- **Inter-Platoon Communication**  
  - Platoons communicate with each other using an Inter-Platoon Communication Protocol (IPCP), managed by platoon leaders.
  - In critical situations, leaders exchange “Command Exchange Requests” to synchronize actions across platoons.

- **Trust Management and Pseudonym Handling**  
  - The TA maintains a record of vehicle pseudonyms, enabling traceability while preserving conditional privacy.
  - Trust scores are dynamically adjusted based on vehicle behavior, with penalties for malicious actions or false signals.

- **Event Logging and Blockchain Integration**  
  - Critical events are logged as transactions on the blockchain.
  - The blockchain ensures that events are immutable, verifiable, and transparent.

- **Handling of Large Vehicles**  
  - Large vehicles are managed separately from standard platoons due to their size and braking characteristics.
  - These vehicles are assigned specific lanes or treated as dynamic obstacles, with platoons adjusting their behavior accordingly.

### Consensus Mechanism
- The architecture uses a lightweight consensus mechanism tailored for VANETs, replacing traditional Proof-of-Work (PoW) with a more efficient method.
- Consensus is reached quickly within and between platoons, ensuring prompt command execution without significant computational overhead.

### Security and Scalability
- Removal of RSUs reduces cost and complexity.
- The system is scalable, capable of handling large numbers of vehicles.
- Security is reinforced through blockchain technology, ensuring all actions are traceable and verifiable.

### Network Architecture

- **Intra-Platoon Communication**  
  - **Leader-Follower Model**: The platoon leader broadcasts commands to follower vehicles.
  - **Trust Score Management**: Vehicles maintain a trust score updated based on command execution and protocol adherence.

- **Inter-Platoon Communication**  
  - **Dynamic Grouping**: Platoon leaders within communication range form an "Inter-Platoon Communication Group" (IPCG).
  - **Command Exchange Protocol**: In critical situations, platoon leaders send a "Command Exchange Request" to other leaders within the IPCG.
  - **Consensus Mechanism**: Consensus is reached among platoons, or the originating leader executes a command with a “Caution Flag” if consensus cannot be achieved.

- **Blockchain Integration**  
  - **Local Blockchain Management**: Each platoon maintains a local blockchain to record transactions and events.
  - **Event Logging**: All significant events are logged on the blockchain, providing a transparent and immutable record.
  - **Trust Authority (TA)**: Central authority responsible for maintaining pseudonym mappings and ensuring vehicle traceability.

- **Security Consideration**  
  - **Pseudonym Management**: Vehicles use pseudonyms to protect privacy, and the TA maintains records for traceability.
  - **Physical Attestation**: Vehicles use their physical attributes to verify the accuracy of information within the platoon.

- **Emergency Response and Law Enforcement Integration**  
  - Emergency vehicles and law enforcement are given priority within the network.
  - Upon detection, platoons automatically adjust to allow emergency vehicles to pass.

- **Handling of Large Vehicles**  
  - Large vehicles are treated as dynamic obstacles, with platoons adjusting their behavior accordingly.

- **Scalability and Efficiency**  
  - **Reduced Overhead**: Direct vehicle-to-vehicle communication scales efficiently, reducing costs and maintenance.
  - **Efficient Communication**: The system relies on low-latency, real-time communications to maintain safety and performance.
