int i = 6;
int buttonState = 0;
const int buttonPin = 1;

int delay_val = 700;


void display0(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(7,LOW); 
  delay(delay_val);
}

void display1(){
  digitalWrite(13,LOW); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(8,LOW); 
  digitalWrite(7,LOW); 
  delay(delay_val);
}

void display2(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,LOW); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(8,LOW); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}

void display3(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(8,LOW); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}

void display4(){
  digitalWrite(13,LOW); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(8,HIGH); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}

void display5(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,LOW); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(8,HIGH); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}

void display6(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,LOW); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}

void display7(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(8,LOW); 
  digitalWrite(7,LOW); 
  delay(delay_val);
}

void display8(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}

void display9(){
  digitalWrite(13,HIGH); 
  digitalWrite(12,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(8,HIGH); 
  digitalWrite(7,HIGH); 
  delay(delay_val);
}


void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
}
	

void loop(){
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH){
    i = i - 1;
    
    if(i < 7){
    i = 16;
  	}
 	
    if(i == 16){
      display9();
    }
      
    else if(i == 15){
      display8();
    }
      
    else if(i == 14){
      display7();
    }
    
    else if(i == 13){
      display6();
    }
    
    else if(i == 12){
      display5();
    }
    
    else if(i == 11){
      display4();
    }
    
    else if(i == 10){
      display3();
    }
    
    else if(i == 9){
      display2();
    }
    
    else if(i == 8){
      display1();
    }
    
    else if(i == 7){
      display0();
      
    }
  }
  
  else{
    i = i + 1;
    
    if(i > 16){
    i = 7;
  	}
    
    if(i == 7){
      display0();
    }
    
    else if(i == 8){
      display1();
    }
    
    else if(i == 9){
      display2();
    }
    
    else if(i == 10){
      display3();
    }
    
    else if(i == 11){
      display4();
    }
    
    else if(i == 12){
      display5();
    }
    
    else if(i == 13){
      display6();
    }
    
    else if(i == 14){
      display7();
    }
    
    else if(i == 15){
      display8();
    }
    
    else if(i == 16){
      display9();
    }
  }
}
