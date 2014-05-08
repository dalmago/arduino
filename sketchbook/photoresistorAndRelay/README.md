======================
Photoresistor and Relay
======================

Activate a 5v electronic relay (with a transistor) when the LDR (photoresistor)
has some shadow on it.

Usage
=====

- Plug the 3,3v from arduino on the LDR. Then plug a resistor in serie with the
LDR and plug on the ground. 
- Plug the pin between the resistor and the LDR at
the analog input set as "LDR". As we are using the analog input with 3,3v, 
plug a 3,3v pin from the Arduino at the AREF pin. 
- Plug the "relay" pin in the transistor that will activate the relay.
