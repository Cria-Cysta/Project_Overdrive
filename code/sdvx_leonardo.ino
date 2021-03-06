/*
* Modify by Cria_Cysta 
* By Daniel Tam (daniel@danieltam.net)
============ NOTES ============
The code is for Project Overdrive's hardwares Ver 21B20.
You will need to download the encoder library and use it in your project for this to work (ww.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino)
===============================
*/

// buttons
#define BT_A 2
#define BT_B 3
#define BT_C 4
#define BT_D 5
#define FX_L 6
#define FX_R 7
#define BT_ST 8

// encoders
#include <Encoder.h>
Encoder enc1(10, 16);
Encoder enc2(15, 14);
float knob1 = 0;
float knob2 = 0;
float old_knob1 = 0;
float old_knob2 = 0;

void setup()
{ 
  // set pins to read, and output high
  // when the pins read low, we know that the buttons have went to ground (aka, pushed down)
  pinMode(BT_A, INPUT);
  pinMode(BT_B, INPUT);
  pinMode(BT_C, INPUT);
  pinMode(BT_D, INPUT);
  pinMode(FX_L, INPUT);
  pinMode(FX_R, INPUT);
  pinMode(BT_ST, INPUT);
  
  digitalWrite(BT_A, HIGH);
  digitalWrite(BT_B, HIGH);
  digitalWrite(BT_C, HIGH);
  digitalWrite(BT_D, HIGH);
  digitalWrite(FX_L, HIGH);
  digitalWrite(FX_R, HIGH);
  digitalWrite(BT_ST, HIGH);
  
  Mouse.begin();
  Keyboard.begin();
}

void loop()
{
  // read encoders
  knob1 =  (float)(enc1.read());
  knob2 = (float)enc2.read();
  
  if(knob1 != old_knob1)
  {
    // if there's a difference in encoder movement from last pass, move the mouse
    if(knob1 < old_knob1)
    {
      Mouse.move(0, -10);
    }
    else
    {
      Mouse.move(0, 10);
    }
    
	// we count the difference in the encoders, but we must not go over arduino's int limit
    if(knob1 < -255)
    {
      enc1.write(0);
      old_knob1 = 0;
    }
    else if (knob1 > 255)
    {
      enc1.write(0);
      old_knob1 = 0;
    }
    else
    {
      old_knob1 = knob1;
    }
  }
  
  if(knob2 != old_knob2)
  {
    if(knob2 > old_knob2)
    {
      Mouse.move(-10, 0);
    }
    else
    {
      Mouse.move(10, 0);
    }
    
    if(knob2 < -255)
    {
      enc2.write(0);
      old_knob2 = 0;
    }
    else if(knob2 > 255)
    {
      enc2.write(0);
      old_knob2 = 0;
    }
    else
    {
      old_knob2 = knob2;
    }
  }
  
  // read the buttons for low, if it's low, output a keyboard press  
  if(digitalRead(BT_A) == LOW)
  {
    Keyboard.press('a');
  }
  else
  {
    Keyboard.release('a');
  }
  
  if(digitalRead(BT_B) == LOW)
  {
    Keyboard.press('b');
  }
  else
  {
    Keyboard.release('b');
  }
  
  if(digitalRead(BT_C) == LOW)
  {
    Keyboard.press('c');
  }
  else
  {
    Keyboard.release('c');
  }
  
  if(digitalRead(BT_D) == LOW)
  {
    Keyboard.press('d');
  }
  else
  {
    Keyboard.release('d');
  }
  
  if(digitalRead(FX_L) == LOW)
  {
    Keyboard.press('z');
  }
  else
  {
    Keyboard.release('z');
  }
  
  if(digitalRead(FX_R) == LOW)
  {
    Keyboard.press('x');
  }
  else
  {
    Keyboard.release('x');
  }
  
  if(digitalRead(BT_ST) == LOW)
  {
    Keyboard.press('n');
  }
  else
  {
    Keyboard.release('n');
  }
}
