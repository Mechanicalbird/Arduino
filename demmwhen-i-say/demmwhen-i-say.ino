const int LED    = 9;  // the pin for the LED
const int BUTTON = 7;  // input pin of the puahbutton

int val = 0;           // stores the state of the input pin

int old_val = 0;       // stores the previous value of "val"
int state   = 0;       // 0=LED off while 1 = LED on
int brightness = 128;  // stores the brightness value
unsigned long startTime =0; //when did we begin pressing?

void setup() {
pinMode(LED,OUTPUT);  //tell Arduino LED is an output
pinMode(BUTTON,INPUT);  //tell Arduino LED is an output
}

void loop() {
val = digitalRead(BUTTON);// read input value and store it

if ((val == HIGH)&&(old_val == LOW)){

  state = 1 - state ;

  startTime = millis();

  delay(10);
}

if ((val == HIGH)&&(old_val == HIGH)){
  if (state == 1 && (millis() - startTime) > 500){
    brightness++;
    delay(10);

    if (brightness > 255){
      brightness = 0;
    }
  }
}


old_val = val;

  if (state == 1){
  analogWrite(LED,brightness);
  }else{
  analogWrite(LED,0);
  }

}
