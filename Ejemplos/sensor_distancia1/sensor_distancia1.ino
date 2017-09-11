#define SigfoxDeb
#define trigPin 3
#define echoPin 2
#define led 8
#include <SoftwareSerial.h>
#ifdef SigfoxDeb
SoftwareSerial mySerial(0, 1); // RX, TX
#endif
//const int boton=6;
char RespuestaSigfox[50];
char ID[51];
char PAC[51];

typedef union
{
    uint16_t number;
    uint8_t bytes[2];
} UINT16_t;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  #ifdef SigfoxDeb
  mySerial.begin(9600);
  #endif
  //pinMode(boton, INPUT);
  pinMode(7, OUTPUT);
  #ifdef SigfoxDeb
  mySerial.println("\n\n\n\n\n\n\n\n\rInicio");
  #endif
}

void leer_distancia()
{
  UINT16_t dist;
  String bufer="AT$SF=";
  char payload[20];
  long duracion, distancia ;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);       
  delayMicroseconds(10);            
  digitalWrite(trigPin, LOW);       
  duracion = pulseIn(echoPin, HIGH) ;
  distancia = duracion / 2 / 29.1  ;
  Serial.println(String(distancia) + " cm.") ;
  dist.number=(uint16_t)(distancia);
  if (distancia<10)
  {
    bufer+=0;
    bufer+=distancia;
  }
  else
  {
    bufer+=distancia;
  }
  bufer.toCharArray(payload,12);
  digitalWrite(7, HIGH);
  delay(1000);
  enviarcomandoATSigfox("AT");
  enviarcomandoATSigfox("AT$RC");
  enviarcomandoATSigfox(payload);
  digitalWrite(7, LOW);
}

void loop() 
{
   leer_distancia();
   delay(600000);
}

void enviarcomandoATSigfox(char* comandoAT)
{
  unsigned long x=0;
  #ifdef SigfoxDeb
  mySerial.print("\r\n\tSigfox-->");
  mySerial.println(comandoAT);
  #endif
  while( Serial.available() > 0) Serial.read();
    x = 0;
  memset(RespuestaSigfox, '\0',sizeof(RespuestaSigfox)); 
  Serial.print(comandoAT);
  Serial.print("\r\n");
  while(true)
  {
    if(Serial.available() != 0)
    {   
      RespuestaSigfox[x] = Serial.read();
      x++;
      if (strstr(RespuestaSigfox, "\n") != NULL)
      {
        #ifdef SigfoxDeb
        mySerial.print("Comando OK\n\r");
        mySerial.println(RespuestaSigfox);
        #endif
        break;
      }
    }
  }
}
