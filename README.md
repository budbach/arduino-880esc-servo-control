# Control HOBBYWING QuicRun WP 880 with an Arduino
Use an Arduino Nano to control a HOBBYWING QuicRun WP 880 Brushed ESC for DIY kayak trolling motor application

## Overview

The HOBBYWING QuicRun WP 880 Brushed Electronic Speed Controller (ESC) is widely used to control the speed of trolling motors in DIY motorized kayaks. A common method for speed adjustment involves using a low-cost "servo tester," which requires desoldering the potentiometer and replacing it with a new one. This project substitutes the servo tester with an Arduino Nano.

The example leverages the Arduino `Servo` library to control the ESC.

## Hardware Required
- Arduino Nano board
- Arduino screw terminal adapter (optional, but recommended)
- HOBBYWING QuicRun WP 880 Brushed ESC (HW 880)
- 10k ohm potentiometer (center detent preferred)
- Hook-up wires

## Circuit

The ESC "throttle control cable" consists of three wires: black, red, and white and is terminated with a 3-pin header. Rather than cutting off the header, I recomend 
cutting an end off a servo extention cable and using that to make the connection:

- **Black wire:** Ground — connect to GND.
- **Red wire:** Provides +6V DC — connect to VIN to power the Arduino Nano.
- **White wire:** PWM signal — connect to digital output pin 9 (D9) on the Arduino.

The potentiometer should be connected as follows:
- One outer pin to ground (GND).
- The other outer pin to power (5V).
- The center pin to an analog input (A0).

## How It Works

As the potentiometer is adjusted, it provides a voltage between 0V and 5V to the center pin. When centered, the potentiometer delivers approximately 2.5V. 

The Arduino measures the voltage from the potentiometer’s center pin (0V to 5V), which it converts to a value between 0 and 1023. When the potentiometer is centered, the Arduino reads a value of 512. Turning the knob to the maximum position yields a value of 1023, while the minimum position corresponds to a value of 0.

The HW 880 ESC's throttle operates similarly to a servo, where:
- Neutral is at 90°,
- Turning the knob above 90° moves the motor forward,
- Turning the knob below 90° moves the motor in reverse.

The further the knob is turned from 90°, the faster the motor turns in the corresponding direction. For the HW 880, the maximum reverse is around 50°, and the maximum forward is approximately 130°.

The Arduino’s `map()` function is used to convert the analog input range of 0 to 1023 into a degree range of 50 to 130.

For more information on how servo control works, refer to [this Wikipedia page](https://en.wikipedia.org/wiki/Servo_control).

## Note:
Some ESCs require a special initialization sequence. The HW 880 does not need anything other than a centered potentiometer and a PWM signal close to 90° to function correctly.
