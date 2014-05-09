//ACM Taller Arduino 8-Mayo-2014
//Ejemplo 2 mejorado

int tiempo = 200;
int leds[] = {4,5,6,7};
void setup()
{

  for(int i=0;i<4;i++) pinMode(leds[i],OUTPUT);
}

void loop()
{

  secuencia();
  
}


void secuencia()
{
 for (int i = 0; i < 4; i++)
 {
   digitalWrite(leds[i],HIGH);
   delay(tiempo);
   digitalWrite(leds[i],LOW);
   delay(tiempo);
 }
}
