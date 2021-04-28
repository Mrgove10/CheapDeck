#include <Arduino.h>
//https://github.com/matthgyver/Arduino-Keyboard-FR
#include <Keyboard.h>
#include <modifiers.h>
#include <button.cpp>

bool key1 = LOW;
bool key2 = LOW;
bool key3 = LOW;
bool key4 = LOW;
bool key5 = LOW;
bool key6 = LOW;
bool key7 = LOW;
bool key8 = LOW;

button b1(8, 16);
button b2(7, 14);
button b3(4, 19);
button b4(2, 21);
button b5(9, 10);
button b6(6, 15);
button b7(5, 18);
button b8(3, 20);

int blickpresslenght = 75;
/*
String generateuuid()
{
  const char templatestr[] = "xxxxxxxx-xxxx-4xxx-bxxx-xxxxxxxxxxxx";
  const char options[] = "0123456789abcdef";
  char tempstr[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

  for (int i = 0; i < strlen(templatestr); i++)
  {
    char x = templatestr[i];

    if (x == 'x')
    {
      // replace with random
      tempstr[i] = options[random(0, strlen(options))];
    }
    else
    {
      //else keep the partern
      tempstr[i] = templatestr[i];
    }
  }
  return String(tempstr);
}*/

void startup()
{
  //init
  int g = 250;
  b1.blink(g);
  b2.blink(g);
  b3.blink(g);
  b4.blink(g);
  b5.blink(g);
  b6.blink(g);
  b7.blink(g);
  b8.blink(g);

  b1.ledOn();
  b2.ledOn();
  b3.ledOn();
  b4.ledOn();
  b5.ledOn();
  b6.ledOn();
  b7.ledOn();
  b8.ledOn();
  delay(500);

  b1.ledOff();
  b2.ledOff();
  b3.ledOff();
  b4.ledOff();
  b5.ledOff();
  b6.ledOff();
  b7.ledOff();
  b8.ledOff();
}

void setup()
{
  startup();
  Keyboard.begin();
  Serial.begin(9600);
}

void loop()
{
  b1.routine();
  b2.routine();
  b3.routine();
  b4.routine();
  b5.routine();
  b6.routine();
  b7.routine();
  b8.routine();

  byte prevkey1 = key1;
  key1 = b1.getClickStatus();
  byte prevkey2 = key2;
  key2 = b2.getClickStatus();
  byte prevkey3 = key3;
  key3 = b3.getClickStatus();
  byte prevkey4 = key4;
  key4 = b4.getClickStatus();
  byte prevkey5 = key5;
  key5 = b5.getClickStatus();
  byte prevkey6 = key6;
  key6 = b6.getClickStatus();
  byte prevkey7 = key7;
  key7 = b7.getClickStatus();
  byte prevkey8 = key8;
  key8 = b8.getClickStatus();

  if (prevkey1 == LOW && key1 == HIGH)
  {
    // Keybind 1
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F13);
    Keyboard.releaseAll();
    b1.changeStatus();
    Serial.write('1');
  }
  if (prevkey2 == LOW && key2 == HIGH)
  {
    // Keybind 2
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F14);
    Keyboard.releaseAll();
    b2.changeStatus();
    Serial.write('2');
  }
  if (prevkey3 == LOW && key3 == HIGH)
  {
    // Keybind 3
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F15);
    Keyboard.releaseAll();
    Serial.write('3');
    b3.blink(blickpresslenght);
  }
  if (prevkey4 == LOW && key4 == HIGH)
  {
    // Keybind 4
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F16);
    Keyboard.releaseAll();
    Serial.write('4');
    b4.blink(blickpresslenght);
  }
  if (prevkey5 == LOW && key5 == HIGH)
  {
    // Keybind 5
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F17);
    Keyboard.releaseAll();
    Serial.write('5');
    b5.blink(blickpresslenght);
  }
  if (prevkey6 == LOW && key6 == HIGH)
  {
    // Keybind 6
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F18);
    Keyboard.releaseAll();
    Serial.write('6');
    b6.blink(blickpresslenght);
  }
  if (prevkey7 == LOW && key7 == HIGH)
  {
    // Keybind 7
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F19);
    Keyboard.releaseAll();
    Serial.write('7');
    b7.blink(blickpresslenght);
  }
  if (prevkey8 == LOW && key8 == HIGH)
  {
    // Keybind 8
   Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F20);
    Keyboard.releaseAll();
    Serial.write('8');
    b8.blink(blickpresslenght);
  }
  delay(25);
}
