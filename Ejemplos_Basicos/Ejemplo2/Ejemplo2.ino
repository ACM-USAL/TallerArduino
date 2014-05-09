//ACM Taller Arduino 8-Mayo-2014 
//EJEMPLO 2


int tiempo = 200;
int pinUno = 4;
int pinDos = 5;
int pinTres = 6;
int pinCuatro = 7;

void setup()
{
  
  pinMode(pinUno, OUTPUT);
  pinMode(pinDos, OUTPUT);  
  pinMode(pinTres, OUTPUT);
  pinMode(pinCuatro, OUTPUT);   
  
}

void loop()
{

  digitalWrite(pinUno, HIGH);
  delay(tiempo);
  digitalWrite(pinUno, LOW);
  delay(tiempo);
  digitalWrite(pinDos, HIGH);
  delay(tiempo);
  digitalWrite(pinDos, LOW);
  delay(tiempo);
  digitalWrite(pinTres, HIGH);
  delay(tiempo);
  digitalWrite(pinTres, LOW);
  delay(tiempo);
  digitalWrite(pinCuatro, HIGH);
  delay(tiempo);
  digitalWrite(pinCuatro, LOW);
  delay(tiempo); 

  
}


