
const int buttonPin = 1;
const int potPin = A0;

int i = 2;
int buttonState = 0;
int potVal = 0;

int delayVal = 0;

void setup(){
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}


void loop(){
  potVal = analogRead(potPin);
  delayVal = potVal;
  
  digitalWrite(i,HIGH);
  delay(delayVal);
  digitalWrite(i,LOW);
  
  buttonState = digitalRead(buttonPin);
  
  Serial.print(delayVal);
  
  if (buttonState == HIGH){
    i = i - 1;
    if(i < 2){
    i = 11;
  	}
  }
  
  else{
    i = i + 1;
    if(i > 11){
    i = 2;
  	}
  }
}
