//Declaramos todas los terminos

unsigned long timer, timerDelay = 2000UL;
int valorCO2, valorTMPS;
float voltaje, TMP, valorFlama;

void setup(){
Serial.begin(9600);	
}

//Declaramos las funciones

void SCO2(){
  valorCO2 = analogRead(A0);
  
  Serial.println("CO2:");
  Serial.println(valorCO2);
}

void STEMP(){
  valorTMPS = analogRead(A1);
  
  voltaje = valorTMPS * 4.68;
  voltaje/= 1024;
  TMP = (voltaje - 0.5)*100;

  Serial.println("TEMP:");
  Serial.println(TMP);
}

void analogFlame(){
  valorFlama = analogRead(A3);
  Serial.println("valorFlama:");
  Serial.println(valorFlama);
}

void loop(){
  unsigned long actualTimer = millis();
  
  analogFlame();

  if(actualTimer>timerDelay || valorFlama<700){
    SCO2();
    STEMP();
    timerDelay+=2000UL;
  }
  else{}
   
}