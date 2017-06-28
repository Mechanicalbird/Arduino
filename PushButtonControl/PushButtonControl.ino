//Turn on LED while the button is pressed

const int LED = 13;  // the pin for the LED
const int BUTTON = 7;//the input pin where the 
                     //pushbutton is connected
int val = 0;         //val will be used to store the state
                     //of the input pin
int old_val = 0;     //this variable stores the previous
                     //value of "val"
int state = 0;       //0 = LED off while 1 = LED on
                     
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT); //tell Arduino LED is an output
pinMode(BUTTON,INPUT);  //and the Button is an input
}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(BUTTON);//read input value and store it

//check whether the input is HIGH (button pressed)
//and change the state and check transition
if ((val == HIGH)&&(old_val==LOW)){
  delay(10);
}
if ((val == HIGH)&&(old_val==LOW)){
  state = 1 - state;
  delay(10);
}
old_val = val;          //val is now old, let's store it
if (state == 1){
  digitalWrite(LED,HIGH);//turn LED ON
}else{
  digitalWrite(LED,LOW); //turn LED off
}
}
