"# APSC103RideauCanalCode" 
"# APSC103RideauCanalCode" 

This is the code for Team 863-A's project for Science Rendez-Vous Kingston 2026. It was written in the Arduino IDE and should be uploaded to an Arduino Board. Ensure you have the Arduino IDE downloaded as you will need it to upload the code. For help uploading the code, see https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE

Before uploading the code, ensure the correct ports are assigned at the top of the code. You will need to define:

what port the first pump set is attached to

what port the second pump set is attached to

what port the button connected to the first pump set is attached to

what port the button connected to the second pump set is attached to

what port the stop button is attached to

what port the green (on) LED is attached to

what port the red (off) LED is attached to

The code initialises the serial monitor. In the event of an error with the state, it will output to the serial monitor that the state has an error and the attempted state. It will then exit the program with exit code 1.
