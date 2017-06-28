
const int LED1 = 2;    
const int LED2 = 7;  

const int BUTTON1 = 5;//the input pin where the 
const int BUTTON2 = 3;//the input pin where the 

int val1 = 0;         //val will be used to store the state
                     //of the input pin
int old_val1 = 0;     //this variable stores the previous
                     //value of "val"
int state1 = 0;       //0 = LED off while 1 = LED on

int val2 = 0;         //val will be used to store the state
                     //of the input pin
int old_val2 = 0;     //this variable stores the previous
                     //value of "val"
int state2 = 0;       //0 = LED off while 1 = LED on

void setup() {
  // put your setup code here, to run once:
pinMode(LED1, OUTPUT); // sets the digital pin as output
pinMode(LED2, OUTPUT); // sets the digital pin as output
pinMode(BUTTON1,INPUT);  //and the Button is an input
pinMode(BUTTON2,INPUT);  //and the Button is an input
}

void loop() {
  // put your main code here, to run repeatedly:

val1 = digitalRead(BUTTON1);//read input value and store it
val2 = digitalRead(BUTTON2);//read input value and store it

if ((val1 == HIGH)&&(old_val1==LOW)){
  delay(10);
}
if ((val1 == HIGH)&&(old_val1==LOW)){
  state1 = 1 - state1;
  delay(10);
}

if ((val2 == HIGH)&&(old_val2==LOW)){
  delay(10);
}
if ((val2 == HIGH)&&(old_val2==LOW)){
  state2 = 1 - state2;
  delay(10);
}

old_val1 = val1;          //val is now old, let's store it
old_val2 = val2;          //val is now old, let's store it

if (state1 == 1){
digitalWrite(LED1, HIGH); // turns the LED on

}else{          
digitalWrite(LED1, LOW);  // turns the LED off
}

if (state2 == 1){
digitalWrite(LED2, HIGH); // turns the LED on

}else{          
digitalWrite(LED2, LOW);  // turns the LED off
}

}
