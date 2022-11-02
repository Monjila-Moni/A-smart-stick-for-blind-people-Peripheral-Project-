
const int buzzer1 = 3;

const int trigPin1 = 5;
const int echoPin1 = 6;
long duration1;
int distance1;
int safetyDistance1;



void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT);  // Sets the echoPin as an Input
pinMode(buzzer1, OUTPUT);

Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
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


else if (safetyDistance1>55 && safetyDistance1<150){
 
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

// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
}
