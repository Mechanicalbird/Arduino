
/*
------------------------------------------------------------------------------------------------
  Arduino Excel 1.2
    
    created        October 07th 2015 by Roberto Valgolio

    last modified  04/11/2015

    history
    1.2   30/11/2015
      * revisited input task
      * revisited ReadLine function
      * updated MapArgs function

    1.1   04/11/2015
      * inproved input management with references selection on received values
      * added a command example for Excel file saving

    this example code is in the public domain
    any feedback will be appreciated, please write to roberto.valgolio@gmail.com

    This sketch exchanges over serial csv messages with ArduinoExcel.xls app by the same author

------------------------------------------------------------------------------------------------
*/

const int serialBufferSize = 32;      // buffer size for input
char  serialBuffer[serialBufferSize]; // buffer for input
const int serialMaxArgs = 4;          // max CSV message args 
char* serialArgs[serialMaxArgs];      // args pointers
int   idx = 0;                        // index
int   outputTiming = 1000;            // packet sending timing in ms      important: this dermines the output timing
float input1;                         // received value
//float inputArray[6];                  // received values
float a0;                             // A0 pin reading
float a1;                             // A1 pin reading 
float rnd;                            // random number


void setup(){
  
  //Serial.begin(9600);
  Serial.begin(115200);
  Serial.println("hello from Arduino");
  delay(1000);
  
  // rx buffer clearing
  while (Serial.available() > 0) {
    byte c = Serial.read();
  }
  
  // if analog input pin 5 is unconnected, random analog noise will cause the call to randomSeed() to generate different seed numbers each time the sketch runs
  randomSeed(analogRead(5));

}


void loop(){

  static unsigned long  setupTime = millis();
  static unsigned long  loopTime = 0;
  static unsigned long  inputCount = 0;
  static unsigned long  outputCount = 0;

  loopTime = millis() - setupTime;

  // Output Task
  // instructions performed each outputTiming ms
  if (loopTime >= (outputCount * (unsigned long)outputTiming)) {

    // set your custom values
    a0 = (float)analogRead(0) / 1023.0 * 5.0;      // reading converted to volt, as alternative you can send the row int value and make the conversion at ThingsGateway level
    a1 = (float)analogRead(1) / 1024.0 * 5.0;      // reading converted to volt, as alternative you can send the row int value and make the conversion at ThingsGateway level
    rnd = (float)random(0, 1000) / 1024.0 * 5.0;

    // look the following examples and modify the code as you need

    // The Excel format to ThingsGateway and Excel is:
    //   XLS,Command,Sheet,Range,Value
    // where:
    //  'XLS'         is a constant keyword for messages to Excel
    //  'Command'     specifies the action (clear, write, get, save, ...)
    //  'Sheet'       specifies the sheet where the action is applied
    //  'Range'       specifies a range of cells where the action is applied
    //  'Value'       is the written value that can be:
    //      integer
    //      float
    //      string
    //      '%date%'  keyword that will be substituted with current date
    //      '%time%'  keyword that will be substituted with current time
    // messages are \n terminated

    // example1
    // write the value from A0 pin to sheet 'Example' range 'B5'
    Serial.print("XLS,write,Example,B5,");
    Serial.print(a0,2);
    Serial.print("\n");
    // write a random value in sheet 'Example' range 'B6'
    Serial.print("XLS,write,Example,B6,");
    Serial.print(rnd,2); // only for example, put here your variable
    Serial.print("\n");

    // example2
    // write %date% that will be converted in current date and located at sheet 'Example' column 'A' row 'idx + 11'
    Serial.print("XLS,write,Example,A");
    Serial.print(idx + 11);
    Serial.print(",");
    Serial.print("%date%");
    Serial.print("\n");
    // write %time% that will be converted in current time and located at sheet 'Example' column 'B' row 'idx + 11'
    Serial.print("XLS,write,Example,B");
    Serial.print(idx + 11);
    Serial.print(",");
    Serial.print("%time%");
    Serial.print("\n");
    // write idx 'i' in sheet 'Example' column 'C' row 'idx + 11'
    Serial.print("XLS,write,Example,C");
    Serial.print(idx + 11);
    Serial.print(",");
    Serial.print(idx);
    Serial.print("\n");
    // write the value from A0 pin to sheet 'Example' column 'D' row 'idx + 11'
    Serial.print("XLS,write,Example,D");
    Serial.print(idx + 11);
    Serial.print(",");
    Serial.print(a0,2);
    Serial.print("\n");
    // write a random value in sheet 'Example' column 'E' row 'idx + 11'
    Serial.print("XLS,write,Example,E");
    Serial.print(idx + 11);
    Serial.print(",");
    Serial.print(rnd,2); // only for example, put here your variable
    Serial.print("\n");

    // get a value from sheet 'Test' column 'B' row 'idx + 5'
    // the return value will be captured by the Input Task (see below)
    //Serial.print("XLS,get,Test,B");
    //Serial.print(idx + 5);
    //Serial.print("\n");

    idx++;
  
    if (idx > 59) {
      // clear cells in A11:F75 area of 'Example' sheet
      Serial.print("XLS,clear,Example,A11:F70");
      Serial.print("\n");
      // save the Excel file (useful for activites over a long time)
      //Serial.print("XLS,save");
      //Serial.print("\n");
      idx = 0;
    }

    outputCount++;
  }

  // Input Task
  // waits a message with 50ms timeout
  int len;
  while ((len = readLine((byte*)serialBuffer, 50)) > 0) {

    // map CSV arguements
    if (mapArgs(serialBuffer, len, serialArgs, serialMaxArgs) > 0) {
      
      if (strcmp(serialArgs[0],"\0") == 0) {
      }
      else if (strcmp(serialArgs[0],"VAL") == 0)  {
        float x;
        x = atof(serialArgs[3]);                        // x contains the current received value and it depends on FIFO request sequence
       
        // first solution based on references selection
        if ((strcmp(serialArgs[1],"Test") == 0) && (strcmp(serialArgs[2],"B6") == 0))  {
          input1 = x;                                   // input1 contains the value from worksheet Test cell B6
        }
        else  {
          // not managed input
        }
/*
        // second solution based on references selection
        int i;
        if ((strcmp(serialArgs[1],"Test") == 0) && (*serialArgs[2] == 'B'))  {
          serialArgs[2]++;
          i = atoi(serialArgs[2]);                      // extracts the numerical part following 'B' from serialArgs[2]
          //inputArray1[i] = x;                           // inputArray1[i th] contains the value from worksheet Test column B row i th
        }
        else  {
          // not managed input
        }
*/
      }
    }
    inputCount++;
    clearBuffer((byte*)serialBuffer,serialBufferSize);
  }

  // if needed put here your custom task

} // end loop


int readLine(byte* startAddr, int timeout) {

  int wait = 0;
  byte *p = startAddr;
  int receivedCount = 0;

  while (wait < timeout) {

    // buffer compiling cycle
    while (Serial.available() > 0) {

      *p = Serial.read();

      // break if line terminator is found
      if (*p == '\n') {
        *p = '\0';
        return receivedCount;
      }
      receivedCount++;
      p++;
    }
    // wait 1ms
    delay(1);
    wait++;
  }
  // timeout exit
  *p = '\0';
  return -1;
}


// CSV arguements mapping
int mapArgs(char* startAddr, int nBytes, char** argPointer, int maxArgs) {

int  i;
char *p;

  *argPointer = startAddr;
  i = 1;

  for (p = startAddr; p < (startAddr + nBytes); p++) {
    if (*p == ',') {            // comma separate arguements

      *p = '\0';                // comma is substituted with \0 so the buffer contains arguements readable as string

      if (i < maxArgs) {
        i++,
        argPointer++;
        *argPointer = p + 1;    // store arg address
      }
      else {
        //Serial.println("args overflow");
        return -1;
      }
    }
  }
  return i;
}


// buffer clearing
  void clearBuffer(byte* startAddr, int nBytes) {

  byte   *p;
  
  for (p = startAddr; p < (startAddr + nBytes); p++) {
    *p = '\0';
  }
}


