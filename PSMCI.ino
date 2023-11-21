//Declaramos todos los terminos

#include <SoftwareSerial.h> //Para el SIM
#include <DHT.h> //Para el sensor de humedad
unsigned long timer, timerDelay = 10000UL, timerDelay2 = 5000UL;
int valorCO2, valorTMPS, buzzer=12, ADVERTENCIA, ALARMA;
float voltaje, TMP, valorFlama;
#define GSM_RX 2
#define GSM_TX 3
#define DHTPIN 8
#define DHTTYPE DHT11

SoftwareSerial sim(GSM_RX, GSM_TX);
DHT dht(DHTPIN, DHTTYPE);

SoftwareSerial MiBT(10,11);

String number = "+50498679416";

void setup(){
Serial.begin(9600);	
sim.begin(115200);
Serial.println("LISTO");
MiBT.begin(38400); 
dht.begin();
pinMode(buzzer, OUTPUT);
pinMode(13, OUTPUT);
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

  Serial.println("TEMPERATURA DE CONTACTO:");
  Serial.println(TMP);
}

void analogFlame(){
  valorFlama = analogRead(A4);
  Serial.println("valorFlama:");
  Serial.println(valorFlama); 
  if(valorFlama < 50){
    ADVERTENCIA=1;
    }else{ADVERTENCIA=0;}
}

void call(){    //Para llamar a los bomberos
  sim.print(F("ATD"));
  sim.print(number);
  sim.print(F(";\r\n"));
  }

void sms(){
  Serial.println("Enviando reporte via SMS");
  sim.println("AT+CMGF=1");
  delay(1000);
  Serial.println("Ingrese el numero");
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(1000);
  String SMS = "holi";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);
  delay(1000);
}

void humidity(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.println("HUMEDAD:");
    Serial.println(h);
    Serial.println("TEMPERATURA:");
    Serial.println(t);

    if(t>35 || h<50){
      ADVERTENCIA=1;
      }else{ADVERTENCIA=0;}
    
  }
  
void loop(){
  float t,h;
  unsigned long actualTimer = millis(); 
     
    if(actualTimer>timerDelay2){
      Serial.println("valorFlama:");
      valorFlama = analogRead(A4);
      Serial.println(valorFlama);
      h = dht.readHumidity();
      t = dht.readTemperature();
      Serial.println("HUMEDAD:");
      Serial.println(h);
      Serial.println("TEMPERATURA:");
      Serial.println(t);
      Serial.println(" ");

      timerDelay2+=5000UL;
      }

  
  if(actualTimer>timerDelay){ 
    humidity();
    SCO2();
    STEMP();
    timerDelay+=10000UL;
  }
    if(valorFlama==0){
    }
    else if(t>40 || h<20 || TMP<260 || valorFlama<120){
      Serial.println(h);
      Serial.println(t);
      Serial.println(TMP);
      Serial.println(valorFlama);
      digitalWrite(12, HIGH);
      Serial.println("ACTIVIDAD ANORMAL");
      valorCO2 = analogRead(A0);
      if(valorCO2>280){
        digitalWrite(13, HIGH);
        Serial.println("FUEGO");
       // call()
       delay(1000);
       digitalWrite(13,LOW);
      }else{
        digitalWrite(13, LOW);
      }
     // delay(5000);
      }else{
        digitalWrite(12,LOW);
      }
   
}
