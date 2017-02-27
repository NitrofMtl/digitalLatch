/*
  Copyright (c) 28/03/2016

    By Nitrof

  Permission is hereby granted, free of charge, to any person obtaining a copy of
  this software and associated documentation files (the "Software"), to deal in
  the Software without restriction, including without limitation the rights to
  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  the Software, and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <digitalLatch.h>
    //Start an instance on digital latch
    //DigitalLatch(enable, data, pin1, pin2, pin3, pin4, clear)
DigitalLatch relay(0, 8, 2 ,3 ,4 ,5 ,6); //set all pins


void setup() {
  Serial.begin(9600);
  relay.init();
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
void loop() {
  
for(int i=0; i < 16; i++){
  relay.latchWrite(i, HIGH); //write latch #i, HIGH
  delay(500);
}

for(int i=0; i<16; i++){
  relay.latchWrite(i, LOW); //write latch #i, LOW
  delay(55);
}

for(int i=0; i < 16; i=i+3){
  relay.latchWrite(i, HIGH); 
  delay(500);
}

if (relay.latchRead(6)){ // if the latch #6 is HIGH, return true
  Serial.println("relay is HIGH");
}
else {
  Serial.println("relay is LOW");
}

relay.reset(); //reset all latch to 0

delay(1000);
}
