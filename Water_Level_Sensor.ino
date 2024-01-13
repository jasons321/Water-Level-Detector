const int numReadings = 17;

float readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float total = 0;                  // the running total
float average = 0;      

int trig = 3; 
int echo = 2;

int LED1 = 13; 
int LED2 = 12; 
int LED3 = 11; 
int LED4 = 10;
int LED5 = 9; 
int LED6 = 8; 
int LED7 = 7; 
int LED8 = 6; 
int LED9 = 5;
int LED10 = 4; 

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED9,OUTPUT);
  pinMode(LED10,OUTPUT);
  turneverythingoff();
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  
}

void loop() {
   total = total - readings[readIndex];
  
   float duration, cm;
   pinMode(trig, OUTPUT);
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   pinMode(echo, INPUT);
   duration = pulseIn(echo, HIGH);
   readings[readIndex] = microsecondsToCentimeters(duration)-8.8;
    total = total + readings[readIndex];
    readIndex = readIndex + 1;

    if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  average = total / numReadings;
 
Serial.println(average);

turneverythingoff();

 if(average>2.5&&average<5){
    digitalWrite(LED1,HIGH); 
  }
  else if(average>5&&average<7.5){
    digitalWrite(LED2,HIGH); 
  }
  else if(average>7.5&&average<10){
    digitalWrite(LED3,HIGH); 
  }
  else if(average>10&&average<12.5){
    digitalWrite(LED4,HIGH); 
  }
  else if(average>12.5&&average<15){
    digitalWrite(LED5,HIGH); 
  }
  else if(average>15&&average<17.5){
    digitalWrite(LED6,HIGH); 
  }
  else if(average>17.5&&average<20){
    digitalWrite(LED7,HIGH); 
  }
  else if(average>20&&average<22.5){
    digitalWrite(LED8,HIGH); 
  }
  else if(average>22.5&&average<25){
    digitalWrite(LED9,HIGH); 
  }
  else if (average>25){
    digitalWrite(LED10,HIGH); 
  }
  delay(100);
}   
float microsecondsToCentimeters(float microseconds) {
   return (microseconds /2) *0.0343;
}
void turneverythingoff(){
  digitalWrite(LED1,LOW); 
  digitalWrite(LED2,LOW); 
  digitalWrite(LED3,LOW); 
  digitalWrite(LED4,LOW); 
  digitalWrite(LED5,LOW); 
  digitalWrite(LED6,LOW); 
  digitalWrite(LED7,LOW); 
  digitalWrite(LED8,LOW); 
  digitalWrite(LED9,LOW); 
  digitalWrite(LED10,LOW); 
}
