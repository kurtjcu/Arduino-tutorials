# Arduino-tutorials
[Back to list of tutorials](../README.md)

## A simple reaction timer using Pixel LED's

### How to use it

1. Ensure you have the [FastLED library installed](../Libraries/)
2. Disconnect USB and / or any sources of power to the circuit.
3. Connect the strip of 10 APA leds to the arduino, GND and +ve go to GND and +5v the data and clock signals are written in the code at the top of the file.
4. Connect the Button so that one side goes to GND and the other side goes to the pin selected in the code.
5. Double check **ALL** your connections.
6. Connect the USB to the computer.
7. Compile and upload the code.

### How to play the game
1. Upload your code to the Arduino.
2. Connect the serial monitor to your arduino (use the tools menu or ctrl + shift + M).
3. Click the button and release it.
4. Get ready to play as the "get ready" LED sequence plays.
5. Once the LED's all flash green, press the button as quickly as you can.


### Description
As this program is a little larger than some of the others we have used we have used ["functions"](https://www.arduino.cc/en/Reference/FunctionDeclaration) to help keep our code
manageable and easier to read, especially in the main loop. As you can see almost half of the code is in the three functions at the bottom of the file.

### Hacking the code 

There are many things to hack in this program such as colours of LED's, the speeds at which they flash, and the messages that are outputted to the monitor.

Upload the code and play the game and deliberately cause an error by continually holding the button doen when starting the game or letting the game time out after starting it.
Take note of the warning flash.
A really good way to get to understand functions a little better is to copy the "warningFlash()" function and give it a slightly different name i.e. "warningFlashPink()". Make sure you copy the whole function including the closing parenthesis "}". once you have copied and renamed it change the colour of the LED's to pink.
Upload the code and play the game and deliberately cause an error by continually holding the button doen when starting the game or letting the game time out after starting it again. Did you notice any change? If not have a look abck through the main program to see where the "warningFlash()" function is triggered from and change **one** of these to the name of the new function you created "warningFlashPink()" in our case. Upload and test the changes by triggering the error where you changed the function call to your new function.




[Back to list of tutorials](../README.md)