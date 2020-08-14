#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    20
CRGB leds[NUM_LEDS];

#define DRIVER_STEP_PIN   10
#define DRIVER_DIR_PIN    9
#define DRIVER_EN_PIN     8
#define POT_PIN           A15
 
#define DRIVER_PULSE_PERIOD_US  1600
#define STEPS_PER_ANALOG_VALUE  0.1
 
enum Driver_pulse_state_enum {PULSE_IDLE, PULSE_HIGH, PULSE_LOW};
 
unsigned long time_now = 0;
uint16_t driver_pulse_hold_time_us = DRIVER_PULSE_PERIOD_US/2;
uint8_t driver_pulse_state = PULSE_IDLE;
uint16_t target_pos = 512*STEPS_PER_ANALOG_VALUE;
uint16_t actual_pos = 512*STEPS_PER_ANALOG_VALUE;
int pos_error = 0;
#include <Wire.h>

#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define FREQUENCY             50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


int control1 = A0;
int control2 = A1;
int control3 = A2;
int control4 = A3;
int control5 = A4;
int control6 = A5;
int control7 = A6;
int control8 = A7;
int control9 = A8;
int motor1 = 0;
int motor2 = 1;
int motor3 = 2;
int motor4 = 3;
int motor5 = 4;
int motor6 = 5;
int motor7 = 6;
int motor8 = 7;
int motor9 = 8;
 
void setup() {
 // controls the leds colour and movement 
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
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
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}


void moveMotor(int controlIn, int motorOut)
{
  int pulse_wide, pulse_width, potVal;
  
  // Read values from potentiometer
  potVal = analogRead(controlIn);
  
  // Convert to pulse width
  pulse_wide = map(potVal, 0, 1023, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);

  pinMode(DRIVER_STEP_PIN, OUTPUT);
    pinMode(DRIVER_DIR_PIN, OUTPUT);
    pinMode(DRIVER_EN_PIN, OUTPUT);
 
    digitalWrite(DRIVER_EN_PIN, HIGH);


    
}

void loop() {
 // asigns the servo motors output to the pot
  moveMotor(control1, motor1);
  moveMotor(control2, motor2);
  moveMotor(control3, motor3);
  moveMotor(control4, motor4);
  moveMotor(control5, motor5);
  moveMotor(control6, motor6);
  moveMotor(control7, motor7);
  moveMotor(control8, motor8);
  moveMotor(control9, motor9);

  
 target_pos = analogRead(POT_PIN)*STEPS_PER_ANALOG_VALUE;
    pos_error = target_pos - actual_pos;
 
    if((pos_error) && (driver_pulse_state == PULSE_IDLE)){
        write_pulse_high();
    }
 
    if((micros() - time_now > driver_pulse_hold_time_us) && (driver_pulse_state == PULSE_LOW)){
        write_pulse_high();
    }
 
    if((micros() - time_now > driver_pulse_hold_time_us) && (driver_pulse_state == PULSE_HIGH)){
        write_pulse_low();
    }
}
 
void write_pulse_high(void){
    driver_pulse_state = PULSE_HIGH;
 
    if(pos_error > 0){
        digitalWrite(DRIVER_DIR_PIN, HIGH);
        actual_pos += 1;
    }
    else if(pos_error < 0){
        digitalWrite(DRIVER_DIR_PIN, LOW);
        actual_pos -= 1;
    }
 
    digitalWrite(DRIVER_STEP_PIN, HIGH);
        time_now = micros();
    }
 
void write_pulse_low(void){
    digitalWrite(DRIVER_STEP_PIN, LOW);
    time_now = micros();
 
    if(pos_error){
        driver_pulse_state = PULSE_LOW;
    }
    else{
        driver_pulse_state = PULSE_IDLE;
    }

}
