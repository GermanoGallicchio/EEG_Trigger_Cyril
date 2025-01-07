#define numberOfDigits 10                 // 000 to 255 expected for input value.
long int int1 = 0;                       
long int int2 = 0;
long int int3 = 0;                       
long int int4 = 0;
char     char1[10];
char     char2[10];
char     char3[10];
char     char4[10];
char theNumberString[numberOfDigits+1];
String theNumberString1;
int commaIndex;
int i = 0;

void setup() {

pinMode(1, OUTPUT);  // output d0
pinMode(5, OUTPUT);  // output d1
pinMode(6, OUTPUT);  // output d2
pinMode(9, OUTPUT);  // output d3
pinMode(10, OUTPUT); // output d4
pinMode(11, OUTPUT); // output d5
pinMode(12, OUTPUT); // output d6
pinMode(13, OUTPUT); // output d7
  
Serial.begin(2000000); // Set baud rate
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

if (Serial.available())   // Check to see if serial port is open
{
serial();
parallel();       // Run parallel data output routine
}
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void parallel(){    // Sets bit pattern according to decimal input value received from serial port. 

if  (int1 < 128){
  digitalWrite ( 13, LOW);    // Check decimal input value for establishing MSB output state
}
if  (int1 > 127){
  digitalWrite ( 13, HIGH);
  int1 = int1 - 64;
}

if  (int1 < 64){
  digitalWrite ( 12, LOW);
}  
if  (int1 > 63){
  digitalWrite ( 12, HIGH);
  int1 = int1 - 64;
}

if  (int1 < 32){
  digitalWrite ( 11, LOW);
}  
if  (int1 > 31){
  digitalWrite ( 11, HIGH);
  int1 = int1 - 32;
}

if  (int1 < 16){
  digitalWrite ( 10, LOW);
 }  
if  (int1 > 15){
  digitalWrite ( 10, HIGH);
  int1 = int1 - 16;
}

if  (int1 < 8){
  digitalWrite ( 9, LOW);
}  
if  (int1 > 7){
  digitalWrite ( 9, HIGH);
  int1 = int1 - 8;
}

if  (int1 < 4){
  digitalWrite ( 6, LOW);
}  
if  (int1 > 3){
  digitalWrite ( 6, HIGH);
  int1 = int1 - 4;
}

if  (int1 < 2){
  digitalWrite ( 5, LOW);
}  
if  (int1 > 1){
  digitalWrite ( 5, HIGH);
  int1 = int1 - 2;
}

if  (int1 <= 0){
  digitalWrite ( 1, LOW);
}  
if  (int1 > 0){
  digitalWrite ( 1, HIGH);        // Check decimal input value for establishing LSB output state

}

delay(1);
digitalWrite ( 1, LOW);           // Set binary output bits
digitalWrite ( 5, LOW);
digitalWrite ( 6, LOW);
digitalWrite ( 9, LOW);
digitalWrite ( 10, LOW);
digitalWrite ( 11, LOW);
digitalWrite ( 12, LOW);
digitalWrite ( 13, LOW);
}



///////////////////////////////////////////////////////////////////////////////////////////////
//                                      SERIAL COMMS
////////////////////////////////////////////////////////////////////////////////////////////////

void serial(){
  //delay (1);
 for (int j = 0; j < numberOfDigits; theNumberString[j++] = Serial.read());

 theNumberString1 = theNumberString;
    
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    i = 0;
    commaIndex = theNumberString1.indexOf(',');

    
while (isAlpha(theNumberString1[i])) {
      i++;
    }
    if (isAlpha(theNumberString1[0])){
    theNumberString1.substring(0,commaIndex).toCharArray(char1,i+1);
    }
    if (isDigit(theNumberString1[0])) {
    int1 = (theNumberString1.substring(0,commaIndex)).toInt();
    theNumberString1.substring(0,commaIndex).toCharArray(char1,i+1);
    //Serial.println(int1);
    }

    if (isAlpha(char1[0])) {
   //Serial.println(char1);
    }
    
    theNumberString1.remove(0,(commaIndex+1));
    
    
    if (commaIndex <= 0){
      return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
     i = 0;
    commaIndex = theNumberString1.indexOf(',');
while (isAlpha(theNumberString1[i])) {
      i++;
    }
    if (isAlpha(theNumberString1[0])){
    theNumberString1.substring(0,commaIndex).toCharArray(char2,i+1);
    }
    if (isDigit(theNumberString1[0])) {
    int2 = (theNumberString1.substring(0,commaIndex)).toInt();
    theNumberString1.substring(0,commaIndex).toCharArray(char2,i+1);
    Serial.println(int2);
    }

    if (isAlpha(char2[0])) {
   Serial.println(char2);
    }
    
    theNumberString1.remove(0,(commaIndex+1));
    
    
    if (commaIndex <= 0){
      return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   i = 0;
    commaIndex = theNumberString1.indexOf(',');
while (isAlpha(theNumberString1[i])) {
      i++;
    }
    if (isAlpha(theNumberString1[0])){
    theNumberString1.substring(0,commaIndex).toCharArray(char3,i+1);
    }
    if (isDigit(theNumberString1[0])) {
    int3 = (theNumberString1.substring(0,commaIndex)).toInt();
    theNumberString1.substring(0,commaIndex).toCharArray(char3,i+1);
    Serial.println(int3);
    }

    if (isAlpha(char3[0])) {
   Serial.println(char3);
    }
    
    theNumberString1.remove(0,(commaIndex+1));
    
    
    if (commaIndex <= 0){
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    i = 0;
    commaIndex = theNumberString1.indexOf(',');
while (isAlpha(theNumberString1[i])) {
      i++;
    }
    if (isAlpha(theNumberString1[0])){
    theNumberString1.substring(0,commaIndex).toCharArray(char4,i+1);
    }
    if (isDigit(theNumberString1[0])) {
    int4 = (theNumberString1.substring(0,commaIndex)).toInt();
    theNumberString1.substring(0,commaIndex).toCharArray(char4,i+1);
    Serial.println(int4);
    }

    if (isAlpha(char4[0])) {
   Serial.println(char4);
    }
    
    theNumberString1.remove(0,(commaIndex+1));
    
    
    if (commaIndex <= 0){
      return;
    }
}
