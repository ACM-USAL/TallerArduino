#define LONGITUD_COMANDOS 3

int comandoSonido(boolean signal){

  static boolean state = false; // Almacena el estado anterior de la señal
  static unsigned long times[LONGITUD_COMANDOS] = {0,0,0}; //Almacena los instantes de tiempo en que la señal pasa de 0 a 1 (palmadas)
  
  unsigned long thisTime; 
  int i; 
  unsigned long minGap;
  static int clapNumber = 0; // Indica qué palmada estamos esperando
  unsigned long gaps[LONGITUD_COMANDOS-1]; // Almacena los tiempos entre palmada y palmada
  int comando = 0; // Variable para el valor de retorno de la función 
  float temp; 
  static unsigned long ignoreUntil = 0; 
  
  //Despues de cada palmada la linea oscila un tiempo, usamos ignoreUntil para no detectar las oscilaciones como palmanas nuevas
  if(millis() < ignoreUntil) return -1;
  
  //Si la señal está a 0
  if(signal == false){
    
    // Comprobamos si ha habido cambio de estado (1 -> 0)
    if(state == false) return -1;
    else{
      state = false;
      return -1;
      
    }
  //Si la señal está a 1
  }else{
    // Si ya habíamos detectado la palmada no hacemos nada
    if(state == true) return -1;
    // Si la palmada es nueva
    else{
      state = true;
      thisTime = millis();
      //Ignorarémos el estado de la linea durante 0.2 segundos para evitar las oscilaciones
      ignoreUntil = thisTime+200;
     
      //Si la anterior palmada la detectamos hace más de 2 segundos, volvemos a empezar 
      if(clapNumber > 0 && thisTime-times[clapNumber-1] > 2000) clapNumber = 0;
      times[clapNumber] = thisTime;
      
      clapNumber++;
      /*Serial.print("Times: ");
      Serial.print(thisTime); Serial.print(" "); Serial.println(i);*/
      
      //Si hemos detectado palmadas suficientes como para analizarlas como comando...
      if(clapNumber == LONGITUD_COMANDOS){
        // ANALISIS DEL COMANDO COMPLETO
        
        // Calculamos los gaps (espacios entre palmas)
        for(i = 0; i<(LONGITUD_COMANDOS-1); i++)
          gaps[i] = times[i+1]-times[i];
        
        // Calculamos el menor de los gaps, se considera como nulo, palmas seguidas.
        minGap = gaps[0];
        for(i = 0; i<(LONGITUD_COMANDOS-1); i++)
          minGap = min(minGap, gaps[i]);
              
        // Si un gap dura más que el 150% del menor gap se considera como pausa
        for(i=0; i<(LONGITUD_COMANDOS-1); i++){
          
          if(gaps[i] / float(minGap) > 1.5){
            
            // El comando asociado a un patón de palmas se calcula como la expresión binaria de las pausas entre palmas:
            // EJ: X_XX_X -> 101 -> 5    X_X_XX -> 110 -> 6  
            // Nota: X_X_X_X se interpreta como XXXX -> 000 -> 0
            temp = LONGITUD_COMANDOS-2-i;
            comando = (int) (pow(2.0, temp)+0.1) + comando; // Sumamos 0.1 porque el cast de double a int trunca y no redondea.
            
          }
        }          
        
        clapNumber = 0;
        return comando;
        
        
      }else return -1;
    }
  }

};


