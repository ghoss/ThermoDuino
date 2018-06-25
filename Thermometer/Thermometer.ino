/*  PROTOTYPE - WORK IN PROGRESS
 *  Target: Arduino Pro Mini (ATMEGA382P, 3.3V/8MHz)
 */


#include <PCD8544.h>


// A custom glyph (a smiley)...
static const byte sym_deg[] = { B00000000, B00000000, B00000010, B00000101, B00000010 };
static const byte sym_arrowup[] = { B00000100, B00000110, B00111111, B00000110, B00000100 };
static const byte sym_arrowdwn[] = { B00010000, B00110000, B01111110, B00110000, B00010000 };


// Pin parameters: SCLK, SDIN, DC, RST, SCE
static PCD8544 lcd = {9, 8, 7, 5, 6};


void setup() {
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, sym_deg);
  lcd.createChar(1, sym_arrowup);
  lcd.createChar(2, sym_arrowdwn);
}


void loop() {
  // Just to show the program is alive...
  static int counter = 0;

  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);
  lcd.print("TEMP ");
  lcd.write(0); lcd.write('C');

  // Write the counter on the second line...
  lcd.setCursor(0, 1);
  lcd.write('+');
  lcd.print(counter, DEC);
  lcd.print(".5");

  lcd.setCursor(48, 1);
  lcd.write(1);
  lcd.print("-12.5");
  
  lcd.setCursor(48, 2);
  lcd.write(2);
  lcd.print("+32.5");

  lcd.setCursor(0,3);
  lcd.print("HUMID %");
  lcd.setCursor(0,4);
  lcd.print("34.5");

  lcd.setCursor(48, 4);
  lcd.write(1);
  lcd.print(" 21.5");
  
  lcd.setCursor(48, 5);
  lcd.write(2);
  lcd.print(" 82.5");

  delay(200);
  counter++;
}
