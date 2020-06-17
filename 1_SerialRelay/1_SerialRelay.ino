
#define relayPin0   32
#define relayPin1   33
#define relayPin2   25
#define relayPin3   26

#define buttonPin0  16
#define buttonPin1  17
#define buttonPin2  21
#define buttonPin3  22

void setup(){
 Serial.begin(115200);
 pinMode(relayPin0, OUTPUT);
 pinMode(relayPin1, OUTPUT);
 pinMode(relayPin2, OUTPUT);
 pinMode(relayPin3, OUTPUT);
 
 pinMode(buttonPin0, INPUT);
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 pinMode(buttonPin3, INPUT);
   
}

void loop(){
  
  char rx_byte;
    
  if(Serial.available() > 0){       
     rx_byte = (char)Serial.read(); 

     if(rx_byte == '1'){  
        digitalWrite(relayPin0, HIGH);
        delay(50);     
     }else if(rx_byte == '2'){
        digitalWrite(relayPin0, LOW);
        delay(50);
     }

  }
 
}
