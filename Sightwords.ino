//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int wordCount = 100;
const int switchPin = 7;

String vocabulary[wordCount] = {
  "a", "about", "all", "am", "an", "and", "are", "as", "at", "be", "been", "but", "by", 
  "called", "can", "come", "could", "day", "did", "do", "down", "each", "find", "first", 
  "for", "from", "get", "go", "had", "has", "have", "he", "her", "him", "his", "how", 
  "I", "if", "in", "into", "is", "it", "its", "like", "long", "look", "made", "make", 
  "many", "may", "more", "my", "no", "not", "now", "number", "of", "on", "one", "or", 
  "other", "out", "part", "people", "said", "see", "she", "so", "some", "than", "that", 
  "the", "their", "them", "then", "there", "these", "they", "this", "time", "to", "two", 
  "up", "use", "was", "water", "way", "we", "were", "what", "when", "which", "who", 
  "will", "with", "words", "would", "write", "you", "your"
};

void setup()
{
  randomSeed(analogRead(0));
  pinMode(switchPin, INPUT_PULLUP);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Sightwords");
  lcd.setCursor(2,1);
  lcd.print("By Alex Clark");
}


void loop()
{
  if (digitalRead(switchPin) == LOW) {
  int randomIndex = random(0, wordCount);
  delay(750 );
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print(vocabulary[randomIndex]);
  }
}
