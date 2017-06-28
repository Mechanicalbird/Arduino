const int SENSOR = 9;

const int LED = 9;

int val = 0;
int in = 0;

void setup() {
pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop() {

  
val = analogRead(0);

in = analogRead(SENSOR);

Serial.println(in/4);

analogWrite(LED,in/4);

delay(100);

}
