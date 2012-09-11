/*
 * Implementation of PushButton Library for Arduino.
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
#include "Arduino.h"
#include "PushButton.h"

PushButton::PushButton(int switch_PIN): updInterval(11,true) {
	pin=switch_PIN;
	
	pinMode(pin, INPUT_PULLUP); 
	event=EV_NONE;
	offState=digitalRead(pin);
	millis_of_state=0;
	millis_of_start=0;
	keyDown=false;
}

void PushButton::update() {
	if (!updInterval.check()) {
		return;
	}

  int state = digitalRead(pin);
  if (state!=offState) { // botao pressionado!
     // registra o tempo no qual ele está pressionado
	 millis_of_state = millis();
     if (!keyDown) { // inicio do modo?
    	 keyDown=true;
    	 millis_of_start=millis_of_state;
     }
  } else {
    // botao nao acionado.
    if (keyDown) {
       int tempoPressionado=millis_of_state-millis_of_start;
       int tempoLiberado=millis()-millis_of_state;
       
       if (tempoPressionado<30 && tempoLiberado>30) { // pressionado apenas por 30ms?
         // considera que foi só ruido, cancela evento
    	   keyDown=false; // sai do modo de estado acionao
       } else 
         if (tempoLiberado>50) { // já considera que o usuario liberou o botao
             keyDown=false; // sai do modo de estado acionao
             if (tempoPressionado<1000) { // se ficou pressionado por mais de 30ms e menos de 1s
               event = EV_PRESSED; // pressionado por menos de 1s.
             } else {
               event = EV_LONG_PRESSED; // pressionado por mais de 1s.
             }
         }
    } // estado ON
  } // botao acionado ou nao?
	
	updInterval.reset();
}
void PushButton::print() {
	Serial.print("NAO IMPLEMENTADO!");
}
		
int PushButton::getEvent() {
    
	int retEvent=event;
	event=EV_NONE; // RESETA O EVENTO
	
	return retEvent;
}