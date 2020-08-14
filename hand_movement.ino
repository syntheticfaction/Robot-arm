
 /*
 * Original sourse: https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
 * This is the Arduino code PAC6985 16 channel servo controller
 * watch the video for details and demo http://youtu.be/y8X9X10Tn1k
 *  * 
 * Written by Ahmad Nejrabi for Robojax Video channel www.Robojax.com
 * Date: Dec 15, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */
/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#include <AccelStepper.h>


AccelStepper stepper(1,10,9); 
#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    20
CRGB leds[NUM_LEDS];

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
// this is for the led so is not essential 
for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 50, 0, 255);
    FastLED.show();
    delay(40);
    
  }
  for (int i = 19; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 100);
    FastLED.show();
    delay(40);
    
  }
 stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

// the code inside loop() has been updated by Robojax
void loop() {
// the values set what motor output and the amouunt the servo turns or positioning
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 ); 
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 575);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 125 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 125 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 125);
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 125 );
pwm.setPWM(2 , 0, 575 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
 stepper.moveTo(200);
  while (stepper.currentPosition() != 200) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition(); 
   stepper.moveTo(-200);
  while (stepper.currentPosition() != 0) // Full speed basck to 0
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition(); 
   stepper.moveTo(60);
  while (stepper.currentPosition() != 60) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition();
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(5, 0, 150 );
delay(500);
pwm.setPWM(5, 0, 405 );
delay(500);
pwm.setPWM(5, 0, 150 );
delay(500);
pwm.setPWM(5, 0, 405 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(5, 0, 150 );
pwm.setPWM(6, 0, 575 );
delay(500);
pwm.setPWM(5, 0, 405 );
pwm.setPWM(6, 0, 300);
delay(500);
pwm.setPWM(5, 0, 150 );
pwm.setPWM(6, 0, 575 );
delay(500);
pwm.setPWM(5, 0, 405 );
pwm.setPWM(6, 0, 300 );
delay(500);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 125 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(5, 0, 150 );
pwm.setPWM(8, 0, 400 );
pwm.setPWM(6, 0, 500 );
pwm.setPWM(7, 0, 200 );
delay(1000);
 stepper.moveTo(200);
  while (stepper.currentPosition() != 200) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition(); 
   stepper.moveTo(-200);
  while (stepper.currentPosition() != 0) // Full speed basck to 0
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition(); 
   stepper.moveTo(60);
  while (stepper.currentPosition() != 60) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition();
delay(1000);
pwm.setPWM(0, 0, 575 );
pwm.setPWM(1, 0, 575 );
pwm.setPWM(2, 0, 575 );
pwm.setPWM(3, 0, 125 );
pwm.setPWM(4, 0, 125 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
pwm.setPWM(0, 0, 125 );
pwm.setPWM(1, 0, 125 );
pwm.setPWM(2, 0, 125 );
pwm.setPWM(3, 0, 575 );
pwm.setPWM(4, 0, 575 );
pwm.setPWM(5, 0, 300 );
pwm.setPWM(6, 0, 450 );
pwm.setPWM(7, 0, 350 );
pwm.setPWM(8, 0, 300 );
delay(1000);
 stepper.moveTo(200);
  while (stepper.currentPosition() != 200) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition(); 
   stepper.moveTo(-200);
  while (stepper.currentPosition() != 0) // Full speed basck to 0
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition(); 
   stepper.moveTo(60);
  while (stepper.currentPosition() != 60) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition();
  delay(1000);
}
