

#define TIMEOUT 1500

long distanciaTimeout(int trig, int echo){
  
  long duration, cm;
  
  //Emite un ultrasonido _-----_
  pinMode(distanceTrig, OUTPUT);
  digitalWrite(distanceTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(distanceTrig, HIGH);;
  delayMicroseconds(10);
  digitalWrite(distanceTrig, LOW);
 
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
