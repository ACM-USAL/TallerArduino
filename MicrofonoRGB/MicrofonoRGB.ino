

/* D0 2 
   RGB 10 y 11*/

int D0 = 2;
int state = 0;
long nextTime = 0;

void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT);
 
};
void loop(){
  
  
  
  if(digitalRead(2) == HIGH && millis() > nextTime){
    
    if(state == 0){
      state = 1;
      analogWrite(10,200);
      analogWrite(11,0);
      nextTime = millis() + 200;     
    
    }else{
      state = 0;
      analogWrite(10,0);
      analogWrite(11,200);
      nextTime = millis() + 200;
    }
  
  }  

};



