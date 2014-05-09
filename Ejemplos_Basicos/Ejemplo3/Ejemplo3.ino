// ACM Taller Arduino 8-Mayo-2014
//Ejemplo3


int led = 9;
int ldr = 0;
int luz = 0;

void setup()
{
//  pinMode(led,OUTPUT);
  Serial.begin(9600); //Inicio de puerto serie a 9600bps
}

void loop()
{
  luz=analogRead(ldr);
  monitorizar();
  if (luz <= 30) analogWrite(led,255);
  if (luz >= 30) analogWrite (led,0);
}


void monitorizar()
{
  Serial.print("El valor de luz es:  ");
  Serial.println(luz);
  delay(1000);
}

