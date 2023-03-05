# ESP32 setup
 - Model : `ESP32 DevKit v1, CH9102X` : [https://fr.aliexpress.com/item/1005004935498487.html](https://fr.aliexpress.com/item/1005004935498487.html)
 - Driver download : [https://www.wch.cn/downloads/CH343SER_ZIP.html](https://www.wch.cn/downloads/CH343SER_ZIP.html)
 - Arduino IDE board to setup : `ESP32 Dev Module`

# PlatformIO setup (for integraded dev in VS Code)
 - [https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/](https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/)

# INMP441 mic
The INMP441 is a high-performance, low power, digital-output, omnidirectional MEMS microphone with a bottom port. The complete INMP441 solution consists of a MEMS sensor, signal conditioning, an analog-to-digital converter, anti-aliasing filters, power management, and an industry-standard 24-bit I²S interface. The I²S interface allows the INMP441 to connect directly to digital processors, such as DSPs and microcontrollers, without the need for an audio codec in the system.

## Pins
 
| INMP441 |  ESP32
| --------| ---------------
| VDD     |  3.3
| GND     |  GND
| SD      |  IN (GPIO32)
| L/R     |  GND
| WS      |  WS (GPIO15)
| SCK     |  BCK (GPIO14)


SCK: Serial data clock for I²S interface
WS: Select serial data words for the I²S interface
L/R: Left / right channel selection
        When set to low, the microphone emits signals on one channel of the I²S frame.
        When the high level is set, the microphone will send signals on the other channel.
ExSD: Serial data output of the I²S interface
VCC: input power 1.8V to 3.3V
GND: Power groundHigh PSR: -75 dBFS.

# Arduino Audio Tools
 - FFT wiki page : [https://github.com/pschatzmann/arduino-audio-tools/wiki/FFT](https://github.com/pschatzmann/arduino-audio-tools/wiki/FFT)
 - Filters wiki page : [https://github.com/pschatzmann/arduino-audio-tools/wiki/Filters](https://github.com/pschatzmann/arduino-audio-tools/wiki/Filters)
 - Filter creation : [https://fiiir.com/](https://fiiir.com/)

# Interesting links

## Fastest FFT for Arduino in the world
 - [https://www.instructables.com/Faster-Than-the-Fastest-FFT-for-Arduino/](https://www.instructables.com/Faster-Than-the-Fastest-FFT-for-Arduino/)
 - [https://zestedesavoir.com/tutoriels/3939/jouons-a-implementer-une-transformee-de-fourier-rapide/](https://zestedesavoir.com/tutoriels/3939/jouons-a-implementer-une-transformee-de-fourier-rapide/)
 - [https://klafyvel.me/blog/articles/fft-arduino/](https://klafyvel.me/blog/articles/fft-arduino/)
 - [https://github.com/Klafyvel/AVR-FFT/](https://github.com/Klafyvel/AVR-FFT/)

## Less fast but fast anyway FFT for Arduino
 - [https://www.instructables.com/ApproxFFT-Fastest-FFT-Function-for-Arduino/](https://www.instructables.com/ApproxFFT-Fastest-FFT-Function-for-Arduino/)
 - [https://projecthub.arduino.cc/abhilashpatel121/f1b6ba36-bd96-4f7f-9a83-85c4925ff545](https://projecthub.arduino.cc/abhilashpatel121/f1b6ba36-bd96-4f7f-9a83-85c4925ff545)

## Another FFT library with bar graph visualizer example
 - [https://forum.arduino.cc/t/elm-chans-fft-library-for-arduino/56350](https://forum.arduino.cc/t/elm-chans-fft-library-for-arduino/56350)

## FastLED NeoMatrix
 - [https://github.com/marcmerlin/FastLED_NeoMatrix](https://github.com/marcmerlin/FastLED_NeoMatrix)

## Arduino pinout
![Arduino pinout](https://upload.wikimedia.org/wikipedia/commons/c/c9/Pinout_of_ARDUINO_Board_and_ATMega328PU.svg "Arduino pinout")

## ESP32 DevKit v1 pinout
![ESP32 DevKit v1 pinout](https://lastminuteengineers.b-cdn.net/wp-content/uploads/iot/ESP32-Pinout.png "ESP32 DevKit v1 pinout")

## SD card reader pinout
![https://alexlubbock.com/images/esp32-sd-card-wiring.jpg](https://alexlubbock.com/images/esp32-sd-card-wiring.jpg)

## Spectral analysis concept applied to audio
 - [https://www.ageofaudio.com/en/spectral-analysis-and-real-world-investigation/](https://www.ageofaudio.com/en/spectral-analysis-and-real-world-investigation/)