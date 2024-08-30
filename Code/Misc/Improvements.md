# Improvements over the original thesis
### Intra-Platoon Communication Gaps
1. Limited Handling of Dynamic Events: The original thesis lacked a comprehensive approach to managing dynamic events within a platoon, such as emergency braking or sudden vehicle failure. This deficiency could lead to delayed responses and compromise safety. We propose an enhanced intra-platoon communication model that prioritizes real-time event management to mitigate these risks.

2. Static Trust Management: The thesis proposed trust scores for maintaining platoon integrity but did not account for real-time adjustments based on ongoing events. Our approach introduces a dynamic trust management system that updates trust scores in real-time, ensuring more reliable decision-making within platoons.

### Absence of Inter-Platoon Communication Models
1. Lack of Coordination Among Platoons: With the removal of Roadside Units (RSUs) in the original thesis, the cost of network construction, setup, maintenance, and management has indeed drastically reduced. However, this also eliminated the means for vehicles to coordinate with each other, a role traditionally fulfilled by RSUs. The thesis failed to propose a solution to counter this defect, leaving a significant gap in the system.

2. Critical Need for Inter-Platoon Communication: Without inter-platoon communication, vehicles cannot coordinate for tasks such as lane changes, accident prevention, or traffic management. This void makes the VANET scheme proposed in the thesis incomplete, as inter-platoon communication is essential for avoiding accidents, managing traffic flow, and ensuring the overall functionality of the system. Our proposed model addresses this gap by introducing a robust inter-platoon communication protocol, which allows platoons to exchange critical information, make collective decisions, and operate in a coordinated manner without the need for RSUs. Our approach fills this void, ensuring that vehicles can operate cohesively in complex traffic scenarios.

### Event Logging and Accountability
1. Enhanced Transparency: While the original thesis suggested using blockchain for secure transactions, it did not fully explore event logging for accountability. Our model expands on this by implementing detailed event logging that tracks command execution and outcomes, ensuring transparency and accountability within the VANET system.

### Handling of Large Vehicles and Complex Traffic
1. Addressing Large Vehicle Dynamics: The thesis did not consider the unique challenges posed by large vehicles in mixed traffic. Our model introduces specific protocols for managing large vehicles, improving overall traffic safety and efficiency.

2. Advanced Traffic Management: The original traffic management strategies were oversimplified. Our approach incorporates advanced lane management, dynamic obstacle detection, and adaptive speed regulation to handle diverse and complex traffic conditions more effectively.
