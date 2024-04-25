#include <ArduinoRS485.h>
#include <Adafruit_SleepyDog.h>

#define NPK_SENSOR_ADDRESS 0x01 // Address of the NPK sensor on the RS485 network

const int RE_DE_PIN = 4; // RE and DE pins of RS485 to TTL translator
float sensorValue;

const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
const byte mois[] = {0x01,0x03,0x00,0x12,0x00,0x01,0x24,0x0F};
const byte ph[] = {0x01,0x03,0x00,0x06,0x00,0x01,0x64,0x0b};
 
byte values[11];

void setup() {
  // Initialize Serial port for debugging
  Serial.begin(9600);
  
  // Initialize RS485 communication
  Serial1.begin(4800);
  pinMode(RE_DE_PIN, OUTPUT);
  digitalWrite(RE_DE_PIN, HIGH); // Enable transmitter mode
}

void loop() {

  byte val1,val2,val3,val4,val5;
  val1 = nitrogen();
  val2 = phosphorous();
  val3 = potassium();
  val4 = moisture();
  val5 = pH();
  delay(1000);
  
  
  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(val2);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");
  Serial.print("Moisture: ");
  Serial.print(val4);
  Serial.println("%");
  Serial.print("PH: ");
  Serial.println(val5);
  Serial.println();
  for(int i=0; i<1; i++){
    Watchdog.sleep();
  }
  delay(1000);
}
 
byte nitrogen(){
  digitalWrite(RE_DE_PIN,LOW);
  if(Serial1.write(nitro,sizeof(nitro))==8){
    digitalWrite(RE_DE_PIN,LOW);
    for(int i=0;i<sizeof(values);i++){
    values[i] = Serial1.read();
    }
  }
  return values[4];
}
 
byte phosphorous(){
  digitalWrite(RE_DE_PIN,HIGH);
  if(Serial1.write(phos,sizeof(phos))==8){
    digitalWrite(RE_DE_PIN,LOW);
    for(byte i=0;i<sizeof(values);i++){
    values[i] = Serial1.read();
    }
  }
  return values[4];
}
 
byte potassium(){
  digitalWrite(RE_DE_PIN,HIGH);
  if(Serial1.write(pota,sizeof(pota))==8){
    digitalWrite(RE_DE_PIN,LOW);
    for(byte i=0;i<sizeof(values);i++){
    values[i] = Serial1.read();
    }
  }  
  return values[4];
}

byte moisture(){
  digitalWrite(RE_DE_PIN,HIGH);
  if(Serial1.write(mois,sizeof(mois))==8){
    digitalWrite(RE_DE_PIN,LOW);
    for(byte i=0;i<7;i++){
    values[i] = Serial1.read();
    }
  }
  return values[4];
}

byte pH(){
  digitalWrite(RE_DE_PIN,HIGH);
  if(Serial1.write(ph,sizeof(ph))==8){
    digitalWrite(RE_DE_PIN,LOW);
    for(byte i=0;i<7;i++){
    values[i] = Serial1.read();
    }
  }
  return values[4];
}
