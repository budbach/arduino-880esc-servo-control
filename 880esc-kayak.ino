#include <Servo.h>


#define DEBUG 1    // SET TO 0 OUT TO REMOVE TRACES

#if DEBUG
#define D_SerialBegin(...) Serial.begin(__VA_ARGS__);
#define D_print(...)    Serial.print(__VA_ARGS__)
#define D_println(...)  Serial.println(__VA_ARGS__)
#else
#define D_SerialBegin(...)
#define D_print(...)
#define D_println(...)
#endif

Servo myservo;     // create Servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;          // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);                   // attaches the servo on pin 9 to the Servo object
  D_SerialBegin(115200);               // set the console baud rate
  D_println("setup complete");
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  D_print(F("Pin val "));
  D_println(val);
  val = map(val, 0, 1023, 50, 130);    // scale it for use with the servo (value between 50 and 130)
  D_print(F("Servo val "));
  D_println(val);
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there (not sure this is necessary)
}
