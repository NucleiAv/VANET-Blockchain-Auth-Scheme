# Design Architecture

#### 1. **Overview**
   The proposed design architecture focuses on enhancing VANETs (Vehicular Ad-hoc Networks) by addressing the limitations of the "Secure Blockchains for Cyber-Physical Systems" thesis. The enhancements include the removal of RSUs (Roadside Units), introducing a platoon-based communication system, and ensuring real-time, secure communication and coordination among vehicles.

#### 2. **System Components**
   - **Platoons**: Groups of vehicles traveling together, with a designated leader responsible for communication and command execution.
   - **Platoon Leaders**: Vehicles designated as leaders within each platoon, managing both intra-platoon and inter-platoon communications.
   - **Trust Authority (TA)**: A centralized entity responsible for managing vehicle registrations, maintaining pseudonym records, and auditing the system.
   - **Blockchain**: A distributed ledger system used for event logging, trust score management, and ensuring transparency and accountability within the system.

#### 3. **Key Architectural Features**
   - **Platoon Formation and Management**:
     - Vehicles form platoons based on proximity and similar travel paths. Each platoon has a leader responsible for issuing commands and verifying actions.
     - Platoon leaders are designated based on trust scores, with higher-scoring vehicles taking on leadership roles.

   - **Intra-Platoon Communication**:
     - Communication within a platoon is managed by the leader, who processes and broadcasts commands to ensure synchronized execution.
     - Each vehicle maintains a local copy of the blockchain, recording transactions and events within the platoon.

   - **Inter-Platoon Communication**:
     - Platoons communicate with each other using an Inter-Platoon Communication Protocol (IPCP), managed by platoon leaders.
     - In critical situations, such as emergencies or obstacles, leaders exchange "Command Exchange Requests" to synchronize actions across platoons.

   - **Trust Management and Pseudonym Handling**:
     - The Trust Authority (TA) maintains a record of vehicle pseudonyms, enabling traceability while preserving conditional privacy.
     - Vehicles can change pseudonyms over time, but the TA keeps track of current and past pseudonyms to ensure that reports can be validated regardless of the order they're received in.
     - Trust scores are dynamically adjusted based on vehicle behavior, with penalties for malicious actions or false signals.

   - **Event Logging and Blockchain Integration**:
     - All critical events, such as maneuvers, lane changes, and emergency responses, are logged as transactions on the blockchain.
     - The blockchain ensures that events are immutable, verifiable, and transparent, contributing to the overall security and reliability of the VANET system.

   - **Handling of Large Vehicles**:
     - Large vehicles are managed separately from standard platoons due to their size and braking characteristics.
     - These vehicles are assigned specific lanes or treated as dynamic obstacles, with platoons adjusting their behavior to accommodate them.

#### 4. **Consensus Mechanism**
   - The architecture uses a lightweight consensus mechanism tailored for VANETs, replacing traditional Proof-of-Work (PoW) with a more efficient method suitable for real-time transactions.
   - Consensus is reached quickly within and between platoons, ensuring that commands are executed promptly without significant computational overhead.

#### 5. **Security and Scalability**
   - The removal of RSUs significantly reduces the cost and complexity of deploying and maintaining the VANET system.
   - The system is scalable, capable of handling large numbers of vehicles without overloading communication channels or processing resources.
   - Security is reinforced through the use of blockchain technology, ensuring that all actions are traceable and verifiable, reducing the risk of attacks or malicious behavior.
