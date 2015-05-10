* LIN Features
============
The LIN (Local Interconnect Network) is a serial communications protocol which effi-ciently supports the control of mechatronics nodes in distributed automotive applications. The main properties of the LIN bus are:

• Single master with multiple slaves concept
• Low cost SOFT LIN implementation based on common UART communication
• Low cost single-wire implementation
• Speed up to 20 Kbit/s

* Controller Overview
=====================
The LIN/UART Controller is designed to match as closely as possible the LIN software application structure. The LIN software application is developed as independent tasks, several slave tasks and one master task. The controller conforms to this partitioning.
When the slave task is warned of an identifier presence, it has first to analyze it to know what to do with the response. Software flags identify the presence of one of the specific identifiers from 60 (0x3C) up to 63 (0x3F).

########################## UNDER CONSTRUCTION ...
