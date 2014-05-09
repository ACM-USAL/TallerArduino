//Comandos
#define PARAR 0
#define GIRAR 1
#define UMBRAL 650 // con el tablero va con 400

//sensores IR
int irLed0 = A0;
int irLed1 = A1;
int irLed2 = A2;

// Motor derecho
int motorASpeed = 10; //velocidad
int motorAIn1 = 9; 
int motorAIn2 = 8;

//Motor izquierdo
int motorBSpeed = 5; //velocidad
int motorBIn3 = 6;
int motorBIn4 = 7;

//Micro
int microDigital = 12;

//Distance
int distanceTrig = 4;
int distanceEcho = 3;

//Leds
int ledVerde = 2;
int ledAzul = 11;

void setup(){

  //Iniciar la comunicación serie
  //con el ordenador (depuración)
  Serial.begin(9600);

  //Modo de los pines del motor
  pinMode(motorAIn1, OUTPUT);
  pinMode(motorAIn2, OUTPUT);
  pinMode(motorBIn3, OUTPUT);
  pinMode(motorBIn4, OUTPUT);  
  //no necesario V
  pinMode(motorASpeed, OUTPUT);
  pinMode(motorBSpeed, OUTPUT);

  pinMode(microDigital, INPUT);  
  
  pinMode(distanceTrig, OUTPUT);
  pinMode(distanceEcho, INPUT);  
  
  pinMode(ledAzul, OUTPUT);  
  pinMode(ledVerde, OUTPUT);  
  parar();
  
}

void loop(){
  

  digitalWrite(ledAzul,HIGH);
  digitalWrite(ledVerde,LOW);  
      
  int cm = distanciaTimeout(distanceTrig, distanceEcho);

<<<<<<< HEAD
Serial.println();
=======
>>>>>>> ea6565875a53b9ef75e746bbea7088a005c750d3
  if(cm>0 && cm < 10)
  { 
    delay(1000);
  }
  if(cm<20 && cm > 0)
  {
    girarDerecha(700); 
  } 
  //Lectura de sensores IR
  int irRead0, irRead1, irRead2;   
  irRead0 = analogRead(irLed0);
  irRead1 = analogRead(irLed1);
  irRead2 = analogRead(irLed2);
  if(analogRead(irLed0) >  UMBRAL)
  {
    rectificarD();

  }
  else if(analogRead(irLed2) >  UMBRAL){

    rectificarI();

  }
  else if(analogRead(irLed1) > UMBRAL)
  {
    irRecto();
  }

}
void irRecto(){

  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn3, HIGH);
  digitalWrite(motorBIn4, LOW); 

  analogWrite(motorASpeed,220);
  analogWrite(motorBSpeed,220);
}

void rectificarD(){

  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn3, HIGH);
  digitalWrite(motorBIn4, LOW); 

  analogWrite(motorASpeed,0);
  analogWrite(motorBSpeed,170);
}

void rectificarI(){

  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn3, HIGH);
  digitalWrite(motorBIn4, LOW); 

  analogWrite(motorASpeed,170);
  analogWrite(motorBSpeed,0);
}



void parar(){

  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledAzul,LOW);
  
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn3, HIGH);
  digitalWrite(motorBIn4, LOW);  

  analogWrite(motorASpeed, 0);
  analogWrite(motorBSpeed, 0);

  while(1)
  {

    int comando=comandoSonido( digitalRead(microDigital));   

    if(-1 !=comando)
    {
     // Serial.println(comando);
      //delay(1000);
      if(comando == PARAR)
      {
      
        digitalWrite(motorAIn1, HIGH);
        digitalWrite(motorAIn2, LOW);
        digitalWrite(motorBIn3, HIGH);
        digitalWrite(motorBIn4, LOW);  
      
        analogWrite(motorASpeed, 170);
        analogWrite(motorBSpeed, 0);        
        break;
      } 
      else if (comando == GIRAR)
      {
        girarDerecha(2000);

        analogWrite(motorASpeed, 0);
        analogWrite(motorBSpeed, 0);           
      }
    }
  }  
}

void girarDerecha(int time){

  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, HIGH);
  digitalWrite(motorBIn3, HIGH);
  digitalWrite(motorBIn4, LOW);  

  analogWrite(motorASpeed, 175);
  analogWrite(motorBSpeed, 175);
  delay(time);
}
