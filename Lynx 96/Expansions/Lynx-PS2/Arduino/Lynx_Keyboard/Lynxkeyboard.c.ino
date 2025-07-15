/*
  Lynxkeyboard - Camputers Lynx Keyboard Library
  Adapted by Ian Cudlip

  Based on C64keyboard - Commodore Keyboard library by Hartland PC LLC
  Copyright (c) 2022 Hartland PC LLC
  Written by Robert VanHazinga

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "Lynxkeyboard.h"

void resetMT88(void) {
  digitalWrite(ANALOG_SW_DATA , LOW);
  digitalWrite(ANALOG_SW_RESET, HIGH);
  digitalWrite( ANALOG_SW_STROBE, HIGH);
  digitalWrite(ANALOG_SW_RESET, LOW);
  digitalWrite( ANALOG_SW_STROBE, LOW);
  digitalWrite(ANALOG_SW_DATA , HIGH);
  keyboard.setLock (PS2_LOCK_SCROLL && 0);
  capslock = false;
  lshift = false;
  rshift = false;
  currkeymap = 1;
  }

void setswitch(uint16_t c){
  int bitr;
  bool state;
  
  // Fix logic table hole in MT8812/16 and things
  // AX3 line control. There must be a more logical way of working this out.
  if (!MT8808) {
    // any required modifiers here, hopefully none.
    if (c>63) {
      digitalWrite(ANALOG_SW_AX3, LOW);
    } else {
      digitalWrite(ANALOG_SW_AX3, HIGH);
    }
  }

  if (debug){
    Serial.println(c);
  }
  
  if (c < 160) {
    for ( int currentPin = ANALOG_SW_ARRAY_START; currentPin <= ANALOG_SW_ARRAY_END; ++currentPin) {
      bitr = (currentPin - ANALOG_SW_ARRAY_START);
      state =  bitRead(c, bitr);
      digitalWrite(currentPin, state);
    }
    digitalWrite( ANALOG_SW_STROBE, HIGH);
    digitalWrite( ANALOG_SW_STROBE, LOW);
  }
  if (!MT8808){digitalWrite(ANALOG_SW_AX3, LOW);}

}

void setfswitch(uint16_t c){
  int bitr;
  bool state;
  
   digitalWrite(ANALOG_SW_AX3, HIGH);

  if (c < 160) {
    for ( int currentPin = ANALOG_SW_ARRAY_START; currentPin <= ANALOG_SW_ARRAY_END; ++currentPin) {
      bitr = (currentPin - ANALOG_SW_ARRAY_START);
      state =  bitRead(c, bitr);
      digitalWrite(currentPin, state);
    }
    digitalWrite( ANALOG_SW_STROBE, HIGH);
    digitalWrite( ANALOG_SW_STROBE, LOW);
  }
  
  digitalWrite(ANALOG_SW_AX3, LOW);

}

void debugkey (uint16_t c,uint8_t flags,uint8_t kc){
    Serial.print ("Lynx Keycode: ");
    Serial.print (c);
    Serial.print ("  (ASCII Code: ");
    Serial.print (kc);
    Serial.print (" Hex: ");
    Serial.print (kc, HEX);
    Serial.print (")  Flags: ");
      for (int i = 7; i >= 0; i--)
    {
        bool b = bitRead(flags, i);
        Serial.print(b);
    }
    Serial.println();
  }
    
void Lynxkey(uint16_t k) {
   flags = k >> 8;
   uint8_t kc= k & 0xFF;
   uint16_t c = 0;

  if (currkeymap == 2) {
    if (bitRead(flags, 6)) {
      c = pgm_read_word(keymap->shift_2 + kc);
    }
    else {
      c = pgm_read_word(keymap->noshift_2 + kc);
    }
  }

   if (currkeymap == 1) {
    if (bitRead(flags, 6)) {
      c = pgm_read_word(keymap->shift_1 + kc);
    }
    else {
      c = pgm_read_word(keymap->noshift_1 + kc);
    }
  }
  
//  debug output
    if (debug){debugkey(c,flags,kc);}

// Ignore extended codes 
    if (kc == 250){
      if (debug){
        Serial.println("Ignore");
      }
      c=IGNORE_KEYCODE;
      }

// Lynx Break Key
    if (kc == LynxBREAK) {
      if (bitRead(flags, 7)) {
        Lynxbreak=false;
        digitalWrite(LynxBREAK_PIN, LOW);
        if (debug) {
          Serial.println("Break Off");
        } 
      } else {     
        Lynxbreak=true;
        digitalWrite(LynxBREAK_PIN, HIGH);
        if (debug) {
          Serial.println("Break On");
        } 
      }
      c=IGNORE_KEYCODE;
    }
    
// MT reset function    
    if (kc == MT_RESET) {
    resetMT88();  
    c=IGNORE_KEYCODE;
   }   
    
// Capslock function 

    if (kc == CAPSLOCK_KEY) {
      capslock = !capslock;
      if (debug) {
        if (capslock)  {
          Serial.println("Caps Lock On");
        } else {
          Serial.println("Caps Lock Off");
        }
      }
      
      digitalWrite (ANALOG_SW_DATA, HIGH);
      setswitch(6);
      delay(100);
      digitalWrite (ANALOG_SW_DATA, LOW);
      setswitch(6);
      c = IGNORE_KEYCODE; 
      }


// Keymap Handling
    if (kc == KEY_MAP_1 && !bitRead(flags,7)){
      currkeymap = 1;
      keyboard.setLock (PS2_LOCK_SCROLL && 0);
      }

    if (kc == KEY_MAP_2 && !bitRead(flags,7)){
      currkeymap = 2;
      keyboard.setLock (PS2_LOCK_SCROLL && 1);
      }
        
// Jump to end if key code is an ignored key
    if (c != IGNORE_KEYCODE) {
    //  Differential shift conversion during key press
   if (c >= 160 ) {
      c -= 160;
      if (rshift || lshift) {
        //digitalWrite (ANALOG_SW_DATA, LOW);
        //setswitch(LynxRSHFT);      (lets not set the right shift, as for some reasons enter gets pressed)
        digitalWrite (ANALOG_SW_DATA, LOW);
        setswitch(LynxLSHFT);   
      }
      
     else {
        digitalWrite (ANALOG_SW_DATA, HIGH);
        setswitch(LynxLSHFT);
      }
      // Set cross switch key
      digitalWrite(ANALOG_SW_DATA, HIGH);
      setswitch(c);
       if bitRead (flags,7){
      // Restore shift state to match keystate
      digitalWrite (ANALOG_SW_DATA, lshift);
      setswitch(LynxLSHFT);
//      digitalWrite (ANALOG_SW_DATA, rshift);
//      setswitch(LynxRSHFT);
      digitalWrite(ANALOG_SW_DATA, HIGH);
     }
   }
   
// Shift key handling
     if bitRead (flags,6){
      if (c == LynxRSHFT) {rshift = true;}
      if (c == LynxLSHFT) {lshift = true;}
      }
  
    if bitRead (flags,7){
      digitalWrite(ANALOG_SW_DATA , LOW);
        if (c==LynxRSHFT) {rshift = false;}
        if (c==LynxLSHFT) {lshift = false;}
        }

  // Process normal keypress
    if (c != IGNORE_KEYCODE){setswitch(c);}      
 }

// Reset switch state pin to default high state (Key press).
    digitalWrite(ANALOG_SW_DATA , HIGH);
}

void Testkey(uint8_t c) {
   
    digitalWrite (ANALOG_SW_DATA, HIGH);
    setfswitch(c);
    
// Reset switch state pin to default high state (Key press).
    digitalWrite(ANALOG_SW_DATA , HIGH);
}


void Lynxkeyboard::begin(const LynxKeymap_t &map) {

  keymap = &map;

  // initialize the pins

  for ( int currentPin = ANALOG_SW_ARRAY_START; currentPin <= ANALOG_SW_ARRAY_END; ++currentPin) {
    pinMode( currentPin, OUTPUT);
  }

  if (!MT8808){pinMode( ANALOG_SW_AX3, OUTPUT);}  // ANALOG_SW_AX3 (AX3) is separate as it is used only for conversion of X12/X13 into X6/X7
  pinMode( ANALOG_SW_STROBE, OUTPUT);  // MT88XX strobe
  pinMode( ANALOG_SW_DATA, OUTPUT);   // MT88XX data
  pinMode( ANALOG_SW_RESET, OUTPUT); // MT88XX reset
  pinMode(ANALOG_SW_DATA, OUTPUT);  //MT88XX data
  pinMode(LynxBREAK_PIN, OUTPUT); // C64 NMI (lol)

  digitalWrite(LynxBREAK_PIN, LOW);

  resetMT88();
}
Lynxkeyboard::Lynxkeyboard() {
  // nothing to do here, begin() does it all
}
