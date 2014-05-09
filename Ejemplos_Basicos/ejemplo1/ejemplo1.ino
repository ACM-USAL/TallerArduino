//TALLER ARDUINO ACM 8-MAYO-2014


int pinLed = 12;

void setup()
{
  pinMode(pinLed, OUTPUT); //Le decimos que el pin 12 actura como salida para dar los 5V
}

void loop ()
{
  digitalWrite(pinLed, HIGH); //Le decimo que ponga el pin 12 a HIGH, para dar voltaje
  delay(1000);
  digitalWrite(pinLed, LOW); //Le decimos que pare el voltaje
  delay(1000);
}
