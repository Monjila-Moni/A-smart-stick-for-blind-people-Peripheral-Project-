
const int trigPin2 = 7;
const int echoPin2 = 9;
const int buzzer2 =2;
long duration2;
int distance2;
int holeDetection;

void setup() {
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin2, LOW);
  delay(200);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
  holeDetection = distance2;
  
  if (holeDetection>50 && holeDetection<1200){
  
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
  Serial.print("hole distance : ");
  Serial.println(holeDetection);

}
