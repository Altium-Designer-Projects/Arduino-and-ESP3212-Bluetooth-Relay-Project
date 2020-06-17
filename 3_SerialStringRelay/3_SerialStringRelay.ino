
#define relayPin0   6 // esp3212  
#define relayPin1   7
#define relayPin2   8
#define relayPin3   9

#define buttonPin0  A0
#define buttonPin1  A1
#define buttonPin2  A2
#define buttonPin3  A3

String serialBuffer = "";      // a String to hold incoming data
bool bufferComplete = false;   // whether the string is complete
bool currentLineIsBlank = true;

String relayString  = "0";

byte firstChar  = 0;
byte secondChar = 0;

// R1ON      request?R1510&\r\n   1510
// R2OFF     request?R1680&\r\n   1680 

// R2ON      request?R1820&\r\n   1820
// R2OFF     request?R1940&\r\n   1940 

// R3ON      request?R2780&\r\n   2780
// R3OFF     request?R2860&\r\n   2860 

// R4ON      request?R3480&\r\n   3480
// R4OFF     request?R3640&\r\n   3640

void setup() {
 Serial.begin(9600);       
 serialBuffer.reserve(64); 
 pinMode(relayPin0, OUTPUT);
 pinMode(relayPin1, OUTPUT);
 pinMode(relayPin2, OUTPUT);
 pinMode(relayPin3, OUTPUT);
 
 pinMode(buttonPin0, INPUT);
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 pinMode(buttonPin3, INPUT);
}

void loop() {

 if(Serial.available() > 0){
    char inChar = (char)Serial.read();  // get the new byte:
    //Serial.println(inChar);
    serialBuffer += inChar;    // add it to the serialBuffer:

    if(inChar == '\n'){  // every line of text received from the client ends with \r\n
       currentLineIsBlank = true;
    }else if (inChar != '\r') {
       currentLineIsBlank = false;
    }
     
    if(inChar == '\n' && currentLineIsBlank){
       bufferComplete = true;
    }
 }

 if(bufferComplete == true){ 
    Serial.println(serialBuffer);
    if(serialBuffer.indexOf("request?") > -1){     //  request?R1510&\r\n   request
    
       firstChar  = serialBuffer.indexOf("R");
       secondChar = serialBuffer.indexOf('&');
    
       relayString = serialBuffer.substring(firstChar + 1, secondChar);
 
       Serial.println(relayString);
     
     }
       serialBuffer = "";   // clear the string: // string veriyi en son temizle
       bufferComplete = false;
 }

 if(relayString == "1510"){
   digitalWrite(relayPin0, HIGH);
   Serial.println("relay 0 high");
   // response göndermek lazım
   relayString = "";              // temizlemek lazım
 }else if(relayString == "1680"){
   digitalWrite(relayPin0, LOW);
   relayString = "";
 }

 if(relayString == "1820"){
   digitalWrite(relayPin1, HIGH);
   Serial.println("relay 1 high");
   relayString = "";   
 }else if(relayString == "1940"){
   digitalWrite(relayPin1, LOW);
   relayString = "";   
 }

 if(relayString == "2780"){
   digitalWrite(relayPin2, HIGH);
   relayString = "";   
 }else if(relayString == "2860"){
   digitalWrite(relayPin2, LOW);
   relayString = "";   
 }

 if(relayString == "3480"){
   digitalWrite(relayPin3, HIGH);
   relayString = "";   
 }else if(relayString == "3640"){
   digitalWrite(relayPin3, LOW);
   relayString = "";   
 } 
 

}
