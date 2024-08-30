# Motivation and Improvements
The development of Vehicular Ad-hoc Networks (VANETs) is essential for the future of intelligent transportation systems, aiming to improve road safety, traffic management, and operational efficiency. The thesis "Secure Blockchains for Cyber-Physical Systems" introduced a blockchain-based approach to securing VANETs by utilizing the concept of platoons and the removal of RSUs (Road Side Units) - a mechanism that is one of a kind and had never been proposed before. However, it left several critical areas unaddressed. These voids motivated us to build on this unique concept, addressing its shortcomings to make it more robust. This paper proposes enhancements to the original model, focusing on improving communication, coordination, and management within VANETs.

### Intra-Platoon Communication Gaps
1. **Limited Handling of Dynamic Events**: The original thesis lacked a comprehensive approach to managing dynamic events within a platoon, such as emergency braking or sudden vehicle failure. This deficiency could lead to delayed responses and compromise safety. We propose an enhanced intra-platoon communication model that prioritizes real-time event management to mitigate these risks.

2. **Static Trust Management**: The thesis proposed trust scores for maintaining platoon integrity but did not account for real-time adjustments based on ongoing events. Our approach introduces a dynamic trust management system that updates trust scores in real-time, ensuring more reliable decision-making within platoons.

### Absence of Inter-Platoon Communication Models
1. **Lack of Coordination Among Platoons**: With the removal of Roadside Units (RSUs) in the original thesis, the cost of network construction, setup, maintenance, and management has indeed drastically reduced. However, this also eliminated the means for vehicles to coordinate with each other, a role traditionally fulfilled by RSUs. The thesis failed to propose a solution to counter this defect, leaving a significant gap in the system.

2. **Critical Need for Inter-Platoon Communication**: Without inter-platoon communication, vehicles cannot coordinate for tasks such as lane changes, accident prevention, or traffic management. This void makes the VANET scheme proposed in the thesis incomplete, as inter-platoon communication is essential for avoiding accidents, managing traffic flow, and ensuring the overall functionality of the system. Our proposed model addresses this gap by introducing a robust inter-platoon communication protocol, which allows platoons to exchange critical information, make collective decisions, and operate in a coordinated manner without the need for RSUs. Our approach fills this void, ensuring that vehicles can operate cohesively in complex traffic scenarios.

### Event Logging and Accountability
1. **Enhanced Transparency**: While the original thesis suggested using blockchain for secure transactions, it did not fully explore event logging for accountability. Our model expands on this by implementing detailed event logging that tracks command execution and outcomes, ensuring transparency and accountability within the VANET system.

### Handling of Large Vehicles and Complex Traffic
1. **Addressing Large Vehicle Dynamics**: The thesis did not consider the unique challenges posed by large vehicles in mixed traffic. Our model introduces specific protocols for managing large vehicles, improving overall traffic safety and efficiency.

2. **Advanced Traffic Management**: The original traffic management strategies were oversimplified. Our approach incorporates advanced lane management, dynamic obstacle detection, and adaptive speed regulation to handle diverse and complex traffic conditions more effectively.

# Conclusion
The gaps identified in the original thesis motivated us to develop an enhanced model for VANET communication and management. Our proposed improvements aim to fill these voids, ensuring a more secure, efficient, and scalable VANET system. By incorporating comprehensive inter-platoon communication, dynamic trust management, and advanced traffic handling protocols, our model represents a significant advancement in the field of vehicular networks, paving the way for more reliable and safer smart transportation systems.

