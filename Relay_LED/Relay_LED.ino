// Blinking Relay-LED

const int LED4 = 10; 

const int LED1 = 2;                     

void setup() {
  // put your setup code here, to run once:
pinMode(LED4, OUTPUT); // sets the digital pin as output
pinMode(LED1, OUTPUT); // sets the digital pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED4, HIGH); // turns the LED on
digitalWrite(LED1, HIGH); // turns the LED on
delay(1000);             // waits for a second

digitalWrite(LED4, LOW);  // turns the LED off          
digitalWrite(LED1, LOW);  // turns the LED off
delay(1000);             // waits for a second

}
