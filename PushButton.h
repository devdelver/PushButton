/*
 * Header of PushButton Library for Arduino.
 *  
 * version 1.0
 *  
 * created by Sergio M C Figueiredo - September 2012
 * 
 * site: http://blog.devdelver.com/category/arduino
 * 
 * e-mail: sfigueiredo@devdelver.com
 * 
 */
#ifndef PushButton_h
#define PushButton_h

#include "../Metro/Metro.h"

/*
  PushButton Module interface.
*/
class PushButton {
	private:
		int pin;
		int event;
		
		int offState;
		unsigned long millis_of_state;
		unsigned long millis_of_start;
		int keyDown;
				
		Metro updInterval;
  
	protected:
  
  
    public:
		static const int EV_NONE=0;
		static const int EV_PRESSED=1;
		static const int EV_LONG_PRESSED=2;
		
		PushButton(int switch_PIN);
		void update();
		void print();
		
		int getEvent();		
};

#endif