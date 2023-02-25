#include "pitches.h"

int RedLed = A1;
int GreenLed = A2;
int pir = 9;
int buzzer = 8;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  int alarm = digitalRead(pir);
  if(alarm == HIGH)
  {
    Serial.println("Alarm!");
    Music();
    digitalWrite(RedLed, HIGH);
    digitalWrite(GreenLed, LOW);
  }
  else
  {
    digitalWrite(RedLed, LOW);
    digitalWrite(GreenLed, HIGH);
    
  }
  
  delay(100);
}


void Music()
{
for (int thisNote = 0; thisNote < 8; thisNote++) 
  {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
