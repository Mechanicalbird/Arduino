
const int LED1 = 2;    
const int LED2 = 7; 
const int LED3 = 6; 
float sensorPin = A0;
float sensorValue = 0;

const int BUTTON = 5;//the input pin where the 
const int BUTTON2 = 3;//the input pin where the 
const int BUTTON3 = 4;//the input pin where the

int val = 0;         //val will be used to store the state
                     //of the input pin
int old_val = 0;     //this variable stores the previous
                     //value of "val"
int state = 0;       //0 = LED off while 1 = LED on

int val2 = 0;         //val will be used to store the state
                     //of the input pin
int old_val2 = 0;     //this variable stores the previous
                     //value of "val"
int state2 = 0;       //0 = LED off while 1 = LED on

int val3 = 0;         //val will be used to store the state
                     //of the input pin
int old_val3 = 0;     //this variable stores the previous
                     //value of "val"
int state3 = 0;       //0 = LED off while 1 = LED on



void setup() {
  // put your setup code here, to run once:
pinMode(LED1, OUTPUT); // sets the digital pin as output
pinMode(LED2, OUTPUT); // sets the digital pin as output
pinMode(LED3, OUTPUT); // sets the digital pin as output
pinMode(BUTTON,INPUT);  //and the Button is an input
pinMode(BUTTON2,INPUT);  //and the Button is an input
pinMode(BUTTON3,INPUT);  //and the Button is an input

pinMode(sensorPin, INPUT);
digitalWrite(sensorPin, HIGH); //pull up

Serial.begin(9600);
}

void loop() {

// get the data
  
sensorValue = analogRead(sensorPin);
float voltage = sensorValue;//*(5.0/1023.0);

Serial.print("Pressure ");
Serial.println(voltage);
Serial.println(" ");
delay(500);

  // put your main code here, to run repeatedly:

val  = digitalRead(BUTTON);//read input value and store it
val2 = digitalRead(BUTTON2);//read input value and store it
val3 = digitalRead(BUTTON3);//read input value and store it

if ((val == HIGH)&&(old_val==LOW)){
  delay(10);
}
if ((val == HIGH)&&(old_val==LOW)){
  state = 1 - state;
  delay(10);
}

if ((val2 == HIGH)&&(old_val2==LOW)){
  delay(10);
}
if ((val2 == HIGH)&&(old_val2==LOW)){
  state2 = 1 - state2;
  delay(10);
}



old_val  = val;          //val is now old, let's store it
old_val2 = val2;          //val is now old, let's store it
old_val3 = val3;          //val is now old, let's store it

if (state == 1){
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
