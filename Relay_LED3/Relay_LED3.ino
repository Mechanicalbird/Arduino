// Blinking Relay-LED

const int LED4 = 10; 
const int LED1 = 2;    
const int LED2 = 7;  

const int BUTTON = 5;//the input pin where the 

int val = 0;         //val will be used to store the state
                     //of the input pin
int old_val = 0;     //this variable stores the previous
                     //value of "val"
int state = 0;       //0 = LED off while 1 = LED on

void setup() {
  // put your setup code here, to run once:
pinMode(LED4, OUTPUT); // sets the digital pin as output
pinMode(LED1, OUTPUT); // sets the digital pin as output
pinMode(LED2, OUTPUT); // sets the digital pin as output
pinMode(BUTTON,INPUT);  //and the Button is an input
}

void loop() {
  // put your main code here, to run repeatedly:

val = digitalRead(BUTTON);//read input value and store it

if ((val == HIGH)&&(old_val==LOW)){
  delay(10);
}
if ((val == HIGH)&&(old_val==LOW)){
  state = 1 - state;
  delay(10);
}
old_val = val;          //val is now old, let's store it

if (state == 1){
digitalWrite(LED4, HIGH); // turns the LED on
digitalWrite(LED1, HIGH); // turns the LED on
digitalWrite(LED2, HIGH); // turns the LED on

}else{
digitalWrite(LED4, LOW);  // turns the LED off          
digitalWrite(LED1, LOW);  // turns the LED off
digitalWrite(LED2, LOW);  // turns the LED off
}
  
           // waits for a second

}
