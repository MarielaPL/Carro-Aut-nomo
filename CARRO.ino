//variables de puente h
const int controlPin1 = 2;
const int controlPin2 = 3;
const int controlPin3 = 4;
const int controlPin4 = 5;
const int enablePin = 9;
const int enablePin2 = 10;
const int adelanteSwitch = 4;
const int atrasSwitch = 5;
const int sensorPinOut1 = 11;
const int sensorPinIn1 = 8;
const int sensorPinOut2 = 6;
const int sensorPinIn2 = 7;


//variables de motor
int motorEnabled = 0;
int motorSpeed = 150;
int motorDirection = 1;

//variables de sensor ultrasonico enfrente
long distancia;
long tiempo;

//variables sensor ultrasonico atras
long distancia2;
long tiempo2;

//variable de vuelta
char resp;

void setup(){
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
  pinMode(sensorPinOut1,OUTPUT);  //salida de ultrasonico enfrente
  pinMode(sensorPinIn1,INPUT);    //entrada ultrasonico enfrente
  pinMode(sensorPinOut2,OUTPUT);  //salida de ultrasonico atras
  pinMode(sensorPinIn2,INPUT);    //entrada ultrasonico atras
}

void loop(){
 //estabilizar ultrasonico
 dist1();
 
 while(distancia <= 50){
  detener();
  derecha();
  dist2();                 //opcional
  while(distancia2 > 50){  //opcional
  reversa();
  dist2();                  //opcional
  }                        //opcional
//  delay(2000);
  detener();
  izquierda();
  dist1();
 }
     avanzar();
 }
 
 void dist1(){
    digitalWrite(sensorPinOut1,LOW);    
    delayMicroseconds(5);
    digitalWrite(sensorPinOut1,HIGH);
    delayMicroseconds(10);
   tiempo=pulseIn(sensorPinIn1,HIGH); //pulso ultrasonico
   distancia=int(0.017 * tiempo);
    Serial.print("Distancia enfrente: ");
 Serial.print(distancia);
 Serial.print(" cm");
 Serial.println();
 }
 
 void dist2(){
   digitalWrite(sensorPinOut2,LOW);
       delayMicroseconds(5);
 digitalWrite(sensorPinOut2,HIGH); 
     delayMicroseconds(10);
 tiempo2=pulseIn(sensorPinIn2,HIGH); //pulso ultrasonico
 distancia2=int(0.017 * tiempo2);

 Serial.print("Distancia atras: ");
 Serial.print(distancia2);
 Serial.print(" cm");
 Serial.println();
 
 }
 
 void avanzar(){
    //Adelante 
   analogWrite(enablePin, motorSpeed);
   digitalWrite(controlPin1, LOW);
   digitalWrite(controlPin2, HIGH);
 }
 
 void detener(){
   analogWrite(enablePin, 0);
 }
 
 void reversa(){
   analogWrite(enablePin, motorSpeed);
   digitalWrite(controlPin1, HIGH);
   digitalWrite(controlPin2, LOW);
 }

 
 void izquierda(){
    analogWrite(enablePin2,motorSpeed);
    digitalWrite(controlPin3,HIGH);
    digitalWrite(controlPin4, LOW);
 }
 
 void derecha(){
  analogWrite(enablePin2,motorSpeed);
  digitalWrite(controlPin3,LOW);
  digitalWrite(controlPin4,HIGH);
 }
