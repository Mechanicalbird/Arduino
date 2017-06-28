// Blinking LED

const int LED4 = 10; // LED connected to
                    // digital pin 13

void setup() {
  // put your setup code here, to run once:
pinMode(LED4, OUTPUT); // sets the digital pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED4, HIGH); // turns the LED on
delay(1000);             // waits for a second
//digitalWrite(LED, LOW);  // turns the LED off
//delay(1000);             // waits for a second

}
