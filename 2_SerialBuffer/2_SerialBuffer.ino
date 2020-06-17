
String serialBuffer = "";       // a String to hold incoming data
bool bufferComplete = false;    // whether the string is complete
bool currentLineIsBlank = true;

void setup() {
  Serial.begin(115200);       
  serialBuffer.reserve(64); 

}

void loop(){

 if(Serial.available() > 0){            //   vedat\r\n
    char inChar = (char)Serial.read();  //   get the new byte:
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

     Serial.print(serialBuffer);
     serialBuffer = "";        // clear the string: // string veriyi en son temizle
     
	 bufferComplete = false;
  }

}
