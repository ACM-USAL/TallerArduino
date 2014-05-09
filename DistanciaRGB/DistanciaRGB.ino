#define TIMEOUT 3000

/* TRIGGER 2 ECHO 3
   RGB 10 y 11*/

int trigPin = 4;
int echoPin = 3;

void setup(){
  Serial.begin(9600);
  analogWrite(10,200); 
};
void loop(){
  
  int intensidad =  10*distanciaTimeout(trigPin, echoPin);
  analogWrite(11,intensidad);
  Serial.println(intensidad); 
  delay(100);

};


long distanciaTimeout(int trig, int echo){
  
  long duration, cm;
  
  //Emite un ultrasonido _-----_
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);;
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  //Espera el resultado un maximo de ITIMEOUTms
  duration = pulseIn(echo, HIGH, TIMEOUT);
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  return cm;
}



long microsecondsToCentimeters(long microseconds)
{
  //La velocidad del sonido es de 340 m/s = 29 ms/cm
  //Lo dividimos entre 2 (ida y vuelta)
  return microseconds / 29 / 2;
}

