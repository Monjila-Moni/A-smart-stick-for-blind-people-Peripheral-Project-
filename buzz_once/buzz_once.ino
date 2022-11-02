int const buzzer=A0;
int alreadyBlinked=0;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buzzer, OUTPUT);

  //this way also buzz once
  //digitalWrite(ledPin, HIGH);   
//delay(1000);
//digitalWrite(ledPin, LOW);
 
}

// the loop function runs over and over again forever
void loop() {
            //digitalWrite(buzzer, HIGH);   // set the LED on
  //delay(1000);                  // wait for a second
 // digitalWrite(buzzer, LOW);    // set the LED off
 // while(1); 

   if(alreadyBlinked == 0)
      {
             digitalWrite(buzzer, HIGH);   // set the LED on
             delay(1000);                  // wait for a second
             digitalWrite(buzzer, LOW);    // set the LED off
             alreadyBlinked = 1;
       }


       
       
   else if(alreadyBlinked == 1)
      {
             digitalWrite(buzzer, HIGH);   // set the LED on
             delay(1000);                  // wait for a second
             digitalWrite(buzzer, LOW);
             delay(1000);
             digitalWrite(buzzer, HIGH);   // set the LED on
             delay(1000);                  // wait for a second
             digitalWrite(buzzer, LOW);// set the LED off
             alreadyBlinked = 0;
       }
       else{
        digitalWrite(buzzer,LOW);}

       
}//delay(1000);  
