/*
  Copyright (c) 10/04/2016

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

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif
#include "digitalLatch.h"

DigitalLatch::DigitalLatch(uint8_t enable, uint8_t data, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t clear){
							//set all arduino pin
	this->enable = enable;
	this->data = data;
	this->clear = clear;
	pin[0] = pin1;
	pin[1] = pin2;
	pin[2] = pin3;
	pin[3] = pin4;
}

void DigitalLatch::init(){ //initialize all outputs
	for (uint8_t i = 0; i < 4; i++) pinMode(pin[i], OUTPUT);
	pinMode(enable, OUTPUT);
	pinMode(data, OUTPUT);
	pinMode(clear, OUTPUT);
	digitalWrite(clear, HIGH);
	digitalWrite(enable, LOW);
	digitalWrite(data, LOW);
	reset();
}

bool DigitalLatch::reset(){  //reset :clear LOW
	digitalWrite(clear, LOW);
	digitalWrite(pin[3], !digitalRead(pin[3]));		//toggle chip select pin to reset all 74ls259 chip
	digitalWrite(clear, HIGH);
	latchReg = 0; 		//reset register
}

bool DigitalLatch::latchRead(uint8_t latchBit){		//read the state of the latch
	uint16_t reg = 1;
	reg = reg << latchBit;
	if ((latchReg & reg) != 0) return 1;
	else return 0;
}

void DigitalLatch::latchWrite(uint8_t latchBit, bool power){
	setLatch(latchBit);		//set the address latch
	digitalWrite(data, power);	//set the data pin HIGH-LOW
	punch();					//punch the enable bit and write to latchBit
	latchRegWrite(latchBit, power);	//store the new state of latch to register
}

void DigitalLatch::punch(){		//put the enable bit to LOW to write to latch
	digitalWrite(enable, HIGH);
	digitalWrite(enable, LOW);
}		 

void DigitalLatch::latchRegWrite(uint8_t latchBit, bool power){		//store the sate of each latch on register
	uint16_t reg = 1;
	reg = reg << latchBit;
	if (power == 0) latchReg &= ~reg;
	else latchReg |= reg;
}

void DigitalLatch::setLatch(uint8_t latch_in){		//set the state of each bit for latch address
	for(int i = 0; i<4; i++){
		bool bitState =  setBit(latch_in, i); //get bit value
		digitalWrite(pin[i], bitState);
	}
}

bool DigitalLatch::setBit(uint8_t latch_in, uint8_t pos){ //return the value of position bit on latch address
	uint8_t bit = 1;
	bit = bit<<pos;
	bit &= latch_in;
	if (bit !=0) return 1;
	else return 0;
}







DigitalLatch32::DigitalLatch32(uint8_t enable, uint8_t data, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t clear){
							//set all arduino pin
	this->enable = enable;
	this->data = data;
	this->clear = clear;
	pin[0] = pin1;
	pin[1] = pin2;
	pin[2] = pin3;
	pin[3] = pin4;
	pin[4] = pin5;
}

void DigitalLatch32::init(){ //initialize all outputs
	for (uint8_t i = 0; i < 5; i++) pinMode(pin[i], OUTPUT);
	pinMode(enable, OUTPUT);
	pinMode(data, OUTPUT);
	pinMode(clear, OUTPUT);
	digitalWrite(clear, HIGH);
	digitalWrite(enable, LOW);
	digitalWrite(data, LOW);
	reset();
}

bool DigitalLatch32::reset(){  //reset :clear LOW
	digitalWrite(clear, LOW);
	digitalWrite(pin[3], !digitalRead(pin[3]));		//toggle chip select pin to reset all 74ls259 chip
	digitalWrite(pin[4], !digitalRead(pin[4]));		//toggle chip select pin to reset all 74ls259 chip
	digitalWrite(pin[3], !digitalRead(pin[3]));		//toggle chip select pin to reset all 74ls259 chip
	digitalWrite(clear, HIGH);
	latchReg = 0; 		//reset register
}

bool DigitalLatch32::latchRead(uint8_t latchBit){		//read the state of the latch
	uint32_t reg = 1;
	reg = reg << latchBit;
	if ((latchReg & reg) != 0) return 1;
	else return 0;
}

void DigitalLatch32::latchWrite(uint8_t latchBit, bool power){
	setLatch(latchBit);		//set the address latch
	digitalWrite(data, power);	//set the data pin HIGH-LOW
	punch();					//punch the enable bit and write to latchBit
	latchRegWrite(latchBit, power);	//store the new state of latch to register
}

void DigitalLatch32::punch(){		//put the enable bit to LOW to write to latch
	digitalWrite(enable, HIGH);
	digitalWrite(enable, LOW);
}		 

void DigitalLatch32::latchRegWrite(uint8_t latchBit, bool power){		//store the sate of each latch on register
	uint32_t reg = 1;
	reg = reg << latchBit;
	if (power == 0) latchReg &= ~reg;
	else latchReg |= reg;
}

void DigitalLatch32::setLatch(uint8_t latch_in){		//set the state of each bit for latch address
	for(int i = 0; i<5; i++){
		bool bitState =  setBit(latch_in, i); //get bit value
		digitalWrite(pin[i], bitState);
	}
}

bool DigitalLatch32::setBit(uint8_t latch_in, uint8_t pos){ //return the value of position bit on latch address
	uint8_t bit = 1;
	bit = bit<<pos;
	bit &= latch_in;
	if (bit !=0) return 1;
	else return 0;
}
