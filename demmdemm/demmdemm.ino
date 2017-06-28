const int LED = 9; //the pin for the LED
int i =0;          //We'll use this to count up and down

void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT); // tell Arduino LED is an output
}

void loop() {
  // put your main code here, to run repeatedly:
for (i=0; i < 255; i++){//loop from 0 to 254 (fade in)
  analogWrite(LED,i);//set the LED brightness
  delay(10);         //Wait 10ms
}
for (i=255; i > 0; i--){//loop from 255 to 1 (fade out)
  analogWrite(LED,i);//set the LED brightness
  delay(10);         //Wait 10ms
}
}
