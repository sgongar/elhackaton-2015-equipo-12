//#include <SoftwareSerial.h>

#define RX_PIN 0
#define TX_PIN 1

// SoftwareSerial BT(RX_PIN, TX_PIN);

int interruptor = 2;
int ledPin = 3;
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
      delay(50);
      flag = 0;
      flag_state = 'p';
    }
    // if the state is 0 the led will turn off
    /*
     * Envia un ping al receptor
     */
    if (flag_state == 'p') 
    {
      if (flag == 0)
      {
        Serial.println("hola receptor");
        digitalWrite(ledPin, HIGH);
        flag_state = 0;
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

