# dial-scroll-wheel

Turn a dial to scroll up and down, and press a button to type a single character.


## Required Hardware

* Teensy LC (Teensy 3.2 should work also)

* rotary encoder with pushbutton, like [this one](TODO)

* micro USB cable


## Installing

You don't need to install anything to use the dial as a scroll wheel / keyboard. To upload new firmware, however, you will need to:

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software). You must install the offline IDE version, instead of using the online "Arduino Create" tool.

2. Install the [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) add-on to the Arduino IDE, to support the `Teensy LC` board.

3. TODO do the Encoder and Bounce libraries need to be manually installed?

## Running

1. Connect the device to the computer with a USB cable, if it wasn't already plugged in.

2. Launch the Arduino IDE. 

3. Open the file `dial-scroll-wheel.ino`. 

4. In the menu bar, select `Tools -> Board: -> "Teensy LC"`. 

5. Select `Tools -> USB Type: -> "Serial + Keyboard + Mouse + Joystick"`.

6. Go to `Tools -> Port` and select which port the device is connected to. The port name will vary, but might look something like `/dev/cu.usbmodem*` on a Mac, or `/dev/ttyACM*` in linux. You can check by unplugging the device and seeing which entry in the port list disappears.

8. Compile and upload the firmware by clicking the round arrow button, or by selecting `Sketch -> Upload` in the menu bar. Look for messages printed in the bottom part of the window. If the upload was successful, you can now use the reconfigured device. 
