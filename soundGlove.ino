/*Sound Glove 
 * By Shannon Cherpak
 * This sketch uses a handmade sensor, buzzer, and LilyPad simplesnap
 * to create a wearable glove that controls sound through motion
 */

 //include pitches.h tab 
 #include "pitches.h"

 //setup variables 
 int buzzerPin = 9; 
 int bendSensorPin = A3;
 int bendSensorReading; 

 //arrays to hold notes 
int cMajorScale[] = {NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1};
int dMajorScale[] = {NOTE_D1, NOTE_E1, NOTE_FS1, NOTE_G1};
int eMajorScale[] = {NOTE_E1, NOTE_FS1, NOTE_GS1, NOTE_A1};

//timing variables
int toneDuration = 200;
int noteCount = 4; 
int pauseBetweenNotes = 100; 

void setup() {
//setting up buzzer pin 
pinMode(buzzerPin, OUTPUT);
//reducing noise
 pinMode(bendSensorPin, INPUT_PULLUP);
//start serial monitor
Serial.begin(9600);
}

void loop() {
//read in from sensor
bendSensorReading = analogRead(bendSensorPin);
//print the reading from sensor to the serial monitor
Serial.println("Bend Sensor Reading = " + bendSensorReading);

if(bendSensorReading < 350){
  playCMajorScale();
  Serial.println("Finger Bent");
}
else if (bendSensorReading > 350 && bendSensorReading < 550){
  playDMajorScale();
  Serial.println("Finger Extended");
}
else if(bendSensorReading > 550){
  playEMajorScale();
  Serial.println("Finger Flat");
}
else{
  return; 
}
}

//writing functions for music notes
void playCMajorScale(){
  for(int thisNote = 0; thisNote < noteCount; thisNote++){
    tone(buzzerPin, cMajorScale[thisNote], toneDuration);
    delay(pauseBetweenNotes);
  }
  noTone(buzzerPin);
}

void playDMajorScale(){
   for(int thisNote = 0; thisNote < noteCount; thisNote++){
    tone(buzzerPin, dMajorScale[thisNote], toneDuration);
    delay(pauseBetweenNotes);
  }
  noTone(buzzerPin);
}

void playEMajorScale(){
   for(int thisNote = 0; thisNote < noteCount; thisNote++){
    tone(buzzerPin, eMajorScale[thisNote], toneDuration);
    delay(pauseBetweenNotes);
  }
  noTone(buzzerPin);
}

