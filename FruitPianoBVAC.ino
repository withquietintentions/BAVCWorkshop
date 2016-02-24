
#include <LiquidCrystal.h>
#include <Wire.h>
#include "Adafruit_MPR121.h"
Adafruit_MPR121 cap = Adafruit_MPR121();

//https://www.arduino.cc/en/Tutorial/ToneMelody?action=sourceblock&num=2

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int delayint = 500;
int piezoPin = 9;
//int Apple = 4;
const int blueLight = 8;
//const int Doggie = 5;
//const int Green = 3;
//int numTones= 3;
///int tones []= {440,294,692 };//A, D, G //B  494 Hz
uint16_t lasttouched = 0;
uint16_t currtouched = 0;
#define C  262 //0
#define CS 277 //1
#define D  294 //2
#define DS 311 //3
#define E  330 //4
#define F  349 //5
#define FS 370 //6
#define G  392 //7
#define GS 415 //8
#define A  440 //9
#define AS 466 //10
#define B  494 //11

void setup() {
 lcd.noAutoscroll(); 
  //LED 
pinMode (blueLight,OUTPUT);//blue light
digitalWrite(blueLight, LOW);
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  //debugging
   while (!Serial);        // needed to keep leonardo/micro from starting too fast!
  Serial.begin(9600);
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
   if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

}
void loop() {
     //ZERO WHITE
  if (cap.touched() & (1<<0)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("C is for");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Cat?");///CHANGE THE WORDS HERE
tone(piezoPin, C);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }
     //ONE GREEN
  if (cap.touched() & (1<<1)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("C Sharp");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Snappy");///CHANGE THE WORDS HERE
tone(piezoPin, CS);//CHANGE TONES HERE
    delay(500);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }
     //TWO BLACK
  if (cap.touched() & (1<<2)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("D is for");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Dunno");///CHANGE THE WORDS HERE
tone(piezoPin, D);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }
   //THREE BLUE
  if (cap.touched() & (1<<3)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("D SHARP");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("STILL DUNNO");///CHANGE THE WORDS HERE
tone(piezoPin,DS);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }
  //FOUR RED
   if (cap.touched() & (1<<4)) {
    digitalWrite(blueLight, HIGH);//
    tone(piezoPin, 440);//CHANGE TONES HERE
    delay(20);
     lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("E is for");//CHANGE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Eh");//CHANGE WORKDS HERE
   tone(piezoPin,E);//CHANGE TONES HERE 
   delay(delayint);
    noTone(piezoPin);
lcd.clear();
 digitalWrite(blueLight, LOW);
    }
    //FIVE YELLOW
 if (cap.touched() & (1<<5)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("F is for");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Flowers");///CHANGE THE WORDS HERE
tone(piezoPin, F);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }
     //SIX WHITE
 if (cap.touched() & (1<<6)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("F Sharp ");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Fluffy Stuff");///CHANGE THE WORDS HERE
tone(piezoPin, F);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }    //SEVEN GREEN
 if (cap.touched() & (1<<7)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("G is for");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("GREEN thing");///CHANGE THE WORDS HERE
tone(piezoPin, G);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }    //EIGHT BLACK
 if (cap.touched() & (1<<8)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("G Sharp");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Green STUFF");///CHANGE THE WORDS HERE
tone(piezoPin, GS);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }    //NINE YEllow
 if (cap.touched() & (1<<9)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("A is for");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("APPLE");///CHANGE THE WORDS HERE
tone(piezoPin, A);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }   
  //TEN UNKOWN
 if (cap.touched() & (1<<10)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("A Sharp");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("Applish");///CHANGE THE WORDS HERE
tone(piezoPin, AS);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }   
     //ELEVEN WHITE
 if (cap.touched() & (1<<11)) {
  digitalWrite(blueLight, HIGH);//CHANGE THE LIGHT OFF or On HERE  
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("B is for");///CHANGE THE WORDS HERE
   lcd.setCursor(0,1);
   lcd.print("BALLIN");///CHANGE THE WORDS HERE
tone(piezoPin, B);//CHANGE TONES HERE
    delay(delayint);
    noTone(piezoPin);
    digitalWrite(blueLight, LOW);
    lcd.clear();
 }

     currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
    
}
 
  
  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;
  
  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap.baselineData(i)); Serial.print("\t");
  }
  Serial.println();
  // put a delay so it isn't overwhelming
  delay(50);
}
