#include <Servo.h>
#include <Adafruit_MotorShield.h>
//continious servo: servo.write () 90 is no movement, closer to 0 and 180 is fast in oppisite directions

#define trigPin 12 // define the pins of your sensor
#define echoPin 13 
#define SERVO1_PWM 10
#define SERVO2_PWM 9
Servo servo_1;
Servo servo_2;
int servoSpeed = 100;
int servoStop = 90;
void setup() {
   servo_1.attach(SERVO1_PWM);
  servo_2.attach(SERVO2_PWM);
  servo_1.write (servoSpeed);
  servo_2.write (servoSpeed);
  Serial.begin(9600); // begin serial communitication  
   pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)

}
 
void loop() {

   long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 20) { 
    ///Serial  
   Serial.println ("Close Obstacle detected!" );
Serial.print ("Distance From Robot is " );
Serial.print ( distance);
Serial.print ( " CM!");// print out the distance in centimeters.
Serial.println (" The obstacle is declared a threat due to close distance. ");
Serial.println (" Turning !");
//servo stop
   servo_1.write (servoStop);  
    servo_2.write (servoStop);
    delay (1000);
    //backup
    servo_2.write(servoSpeed);  
    servo_1.write (90-(servoSpeed-90));
    delay (1000);
     servo_1.write (servoStop);  
    servo_2.write (70);
    delay (1000);
}
  else {
   Serial.println ("No obstacle detected. going forward");
  servo_1.write(servoSpeed);  
    servo_2.write (90-(servoSpeed-90));  
    delay (15);
    //servo_1.write(servoSpeed);  
    //servo_2.write (90-(servoSpeed-90)); 
   //delay (15);
  
  }  
 
 
}
