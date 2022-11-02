
const int buzzer1 = 3;

const int trigPin1 = 5;
const int echoPin1 = 6;
long duration1;
int distance1;
int safetyDistance1;



const int trigPin2 = 7;
const int echoPin2 = 9;
const int buzzer2 =2;
long duration2;
int distance2;
int holeDetection;

const int waterSens = A0;
const int buzzer3 =8;
int waterVal;

void setup() {

  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);  // Sets the echoPin as an Input
  pinMode(buzzer1, OUTPUT);


  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer2, OUTPUT);
  

  pinMode(waterSens, INPUT);
  pinMode(buzzer3,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin1, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);

// Calculating the distance
distance1= duration1*0.034/2;
safetyDistance1 = distance1;
if(safetyDistance1<=50){

   tone(buzzer1, 4050);
   delay(200);}


else if (safetyDistance1>55 && safetyDistance1<70){
 
    tone(buzzer1,4050);
    delay(200);
    noTone(buzzer1);
    delay(200);
    
    tone(buzzer1,4050);
    delay(200);
    noTone(buzzer1);
    delay(800);
    }
    

  //no occurance
else{
  noTone(buzzer1);
}


  digitalWrite(trigPin2, LOW);
  delay(200);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
  holeDetection = distance2;
  
  
 if (holeDetection>30 && holeDetection<1200){
  
    tone(buzzer2,3050);
    delay(200);
    noTone(buzzer2);
    delay(200);
    
    tone(buzzer2,3050);
    delay(200);
    noTone(buzzer2);
    delay(200);
    
    tone(buzzer2,3050);
    delay(200);
    noTone(buzzer2);
    delay(800);
   }
   
 waterVal = analogRead(waterSens);//read the water sensor
 if(waterVal>500){
    tone(buzzer3,1650);
    delay(200);
    noTone(buzzer3);
    delay(200);
    
    tone(buzzer3,1650);
    delay(200);
    noTone(buzzer3);
    delay(200);
    
    tone(buzzer3,1650);
    delay(200);
    noTone(buzzer3);
    delay(200);
    
    tone(buzzer3,1650);
    delay(200);
    noTone(buzzer3);
    delay(300);
    
 }

  Serial.print("Distance1: ");
  Serial.println(distance1);
  Serial.print("hole distance : ");
  Serial.println(holeDetection);

  Serial.print("Water Level: ");
  Serial.println(waterVal);
 

}
