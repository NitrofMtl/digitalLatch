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

#ifndef digitalLatch_H
#define digitalLatch_H

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class DigitalLatch {
	private:
			//register bit 0-3 for latch, bit 7 reset
		uint16_t latchReg = 0;
		uint8_t clear;
		uint8_t pin[4];
		uint8_t data;
		uint8_t enable;

		void setLatch(uint8_t latch_in);		//set the sate of latch_in
		void latchRegWrite(uint8_t latchBit, bool power);		//store the sate of each latch on register
		void punch();		//put the enable bit to high for 1 ms 
		bool setBit(uint8_t latch_in, uint8_t pos); 	//return the value of each bit on latch address

	public:
		DigitalLatch(uint8_t enable, uint8_t data, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t clear); //set all pin
		void init(); 		//initialize pins and set all pinMode
		bool reset();		//reset to low all latch
		bool latchRead(uint8_t latchBit); 		// return the sate of the latch
		void latchWrite(uint8_t latchBit, bool power); 		//write latch HIGH/LOW
};





class DigitalLatch32 {
  private:
      //register bit 0-3 for latch, bit 7 reset
    uint32_t latchReg = 0;
    uint8_t clear;
    uint8_t pin[5];
    uint8_t data;
    uint8_t enable;

    void setLatch(uint8_t latch_in);    //set the sate of latch_in
    void latchRegWrite(uint8_t latchBit, bool power);   //store the sate of each latch on register
    void punch();   //put the enable bit to high for 1 ms 
    bool setBit(uint8_t latch_in, uint8_t pos);   //return the value of each bit on latch address

  public:
    DigitalLatch32(uint8_t enable, uint8_t data, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t clear); //set all pin
    void init();    //initialize pins and set all pinMode
    bool reset();   //reset to low all latch
    bool latchRead(uint8_t latchBit);     // return the sate of the latch
    void latchWrite(uint8_t latchBit, bool power);    //write latch HIGH/LOW
};

#endif