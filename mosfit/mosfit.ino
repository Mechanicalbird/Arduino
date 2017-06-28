
int GatePin = 6;
int GateSignal = 3; 

void setup () {
pinMode (GatePin, OUTPUT); // Defines Arduino's pin 5 as an output
}

void loop () { 
analogWrite (GatePin, GateSignal); // But if it is in this range, the Arduino sends the signal to the "GatePin".
}


