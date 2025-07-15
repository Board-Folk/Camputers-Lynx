/*
  Lynxkeyboard - Camputers Lynx Keyboard Library
  Adapted by Ian Cudlip
  v0 08/11/2023
  
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

#include <PS2KeyAdvanced.h>
#include "Lynxkeyboard.h"

PS2KeyAdvanced keyboard;
Lynxkeyboard ckey;
static volatile uint8_t  currkeymap = 1, flags ;
static const LynxKeymap_t *keymap = NULL;
static volatile bool lshift=false, rshift=false, capslock=false, Lynxbreak=false;

void setup() {
  // Configure the keyboard library
  keyboard.begin( DATA_PIN, IRQ_PIN );
  keyboard.setNoRepeat (1);
  keyboard.setNoBreak (0);
  ckey.begin();
 if (debug) {Serial.begin( 9600 );
 Serial.println("Startup..");
 }
}

void loop() {
 if ( keyboard.available() )
 {
   Lynxkey(keyboard.read());  
 }
}
