#include "Wire.h"
#include "I2CKeyPad.h"

const uint8_t KEYPAD_ADDRESS = 0x20;

I2CKeyPad keyPad(KEYPAD_ADDRESS);

//Heavy Duty Keypad
char keymap[19] = "D#0*C987B654A321NF";  //  N = NoKey, F = Fail

//Soft Keypad
//char keymap[19] = "DCBA#9630852*741NF";  //  N = NoKey, F = Fail

void setup()
{
  delay(2000);
  Serial.begin(9600);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("I2C_KEYPAD_LIB_VERSION: ");
  Serial.println(I2C_KEYPAD_LIB_VERSION);
  Serial.println();

  Wire.begin(SDA,SCL);
  Wire.setClock(400000);

  if (keyPad.begin() == false)
  {
    Serial.println("\nERROR: cannot communicate to keypad.\nPlease reboot.\n");
    while (1);
  }

  keyPad.loadKeyMap(keymap);
}


void loop()
{
  if (keyPad.isPressed())
  {
    char ch = keyPad.getChar();     //  note we want the translated char
    int key = keyPad.getLastKey();
    Serial.print(key);
    Serial.print(" \t");
    Serial.println(ch);
    delay(100);
  }
}