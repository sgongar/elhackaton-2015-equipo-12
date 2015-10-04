//#include <SoftwareSerial.h>



#define RX_PIN 0
#define TX_PIN 1

// SoftwareSerial BT(RX_PIN, TX_PIN);

int interruptor = 2;
int ledPin = 7;
int led;
char texto;
int flag;
int state;
int flag_loop = 1;
char flag_state;

void setup() 
{
  pinMode(interruptor, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() 
{
    int valor_interruptor = digitalRead(interruptor);
    if(Serial.available() > 0)
    {
      state = Serial.read();
      flag_state = state;
      flag = 0;
    }
    
    if (valor_interruptor == 1)
    {
      flag = 1;
      flag_state = 'r';
    }
    // if the state is 0 the led will turn off
    
    if (flag_state == 'p') 
    {
      if (flag == 0)
      {
        int i;
        digitalWrite(ledPin, HIGH);
        tone(12, 261, 1000);
        delay(1000);
        tone(12, 329, 1000);
        delay(1250);
        tone(12, 391, 1000);
        delay(1750);
        tone(12, 523, 1000);
      }

      if(flag == 0)
      {
        // Encender sonido y luces
        // Serial.println("");
        flag = 1;
      }
    }
      
    else if (flag_state == 'r') 
    {
      digitalWrite(ledPin, LOW);
      if(flag == 0)
      {
        Serial.println("LED: off");
        flag = 1;
      }
    } 
  }





