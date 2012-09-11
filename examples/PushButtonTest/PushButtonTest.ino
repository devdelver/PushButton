#include <PushButton.h>
#include <Metro.h>

int LED = 13;

int col=0;

/*
  Test PushButton
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
PushButton btn(2); // button at pin 2;
Metro intervalo(1000, true); 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  Serial.println("* Inicio *");
  
  pinMode(LED, OUTPUT);
//  pinMode(2, INPUT);
  
  digitalWrite(LED, HIGH);
  delay(10000); // aguarda 15s. (segurança)
  digitalWrite(LED, LOW);
  
  Serial.print("Button State:");
  Serial.println(digitalRead(2),HEX);
}

// the loop routine runs over and over again forever:
void loop() {
  btn.update(); // Atualizacao do estado do botão.

  int event = btn.getEvent();
  if (event==PushButton::EV_PRESSED) {
     Serial.println("Button pressed!");
     col=0;
  }
  if (event==PushButton::EV_LONG_PRESSED) {
     Serial.println("Button LONG pressed!");
     col=0;
  }
  
  if (intervalo.check()) {
     Serial.print('.');
     if (col++>=20) {
       Serial.println();
       col=0;
     }
  }
}



