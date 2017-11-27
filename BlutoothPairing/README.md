# Arduino-tutorials
[Back to list of tutorials](../README.md)

## Start communicating using HC-05

### How to use it

To get 2 of the HC-05 Blutooth modules working with each other they first need to be paired, this involves getting the UUID from one unit in slave mode and settinga nother unit to be in master mode and giving it the UUID of the oen in slave mode.

Connections:
Use this connection diagram for setting up the HC-05.
[AT mode]("Setup HC-05 - Schematic.PNG"?raw=true)

Use this connection diagram once the HC-05's are setup and you are making a wireless bridge.
[Wireless bridge]("Normal use HC-05 - Schematic.PNG?" raw=true)

The process:


1. Load an "empty" sketch to the Arduino, you can use the one on this folder "Blank_Sketch.ino".
2. Disconnect USB from computer.
3. Connect the HC-05 as per the connection information above.
4. Double check the connections.
5. Hold down the microswitch on the Blutooth module and connect the USB to your PC.
6. Open a serial monitor to the Arduino (CTRL + SHIFT + M).
7. Select "Both NL & CR" on the bottom right of the serial monitor.
8. Select "38400 Baud" in the serial monitor as well.
9. Type in "AT" and you should recieve the message "OK" in your serial monitor.
10. Type in "AT+ROLE?" it should reply "+ROLE:0"
11. Type in "AT+ADDR?" write down the address it replies with you will need this for the master unit.
12. You have are now ready to set the master role on another HC-05 module.
13. Disconnect the USB.
14. Connect a second module the same way connected the first one.
15. Double check your connections.
16. Whilst holding the microswitch down connect the USB to the PC.
17. Type in "AT" and you should recieve the message "OK" in your serial monitor.
18. Type in "AT+ROLE=1" this will set the unit in master mode.
19. Type in "AT+CMODE=0" this will make the master connect to the slave automatically.
20. Type in "AT+BIND=XXXX,XX,XXXXXX" where the "XX" are to be replaced with the address you retrieved from the slave unit previously. (98d3:34:908ec2)
21. Disconnect the USB from the Arduino.
22. Connect each Arduino to a laptop and open a serial montor on each.
23. You should now be able to type on the serial montor and have it appear on the serial monitor on the other PC.





### Description
This time we are just using the Arduino and Blutooth module as a wireless serial bridge. This allows us to send text wirelessly to another PC.






[Back to list of tutorials](../README.md)