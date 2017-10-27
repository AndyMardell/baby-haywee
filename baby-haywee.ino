//---------------------------------------
// Declare Vars
//---------------------------------------

int pirPin = D1;
int pirState = LOW;
int pirStatus = 0;

int relayPin = D2;

int pauseTime = 5000;
int squirtTime = 1000;
int triggered = 0; // Times triggered

//---------------------------------------
// Setup
//---------------------------------------

void setup() {

  // Setup Serial
  Serial.begin(115200);

  // Declare PIR as input
  pinMode(pirPin, INPUT);

  // Declare Relay as Output
  pinMode(relayPin, OUTPUT);

}

//---------------------------------------
// Loop
//---------------------------------------
 
void loop(){

  // Check PIR status
  pirStatus = digitalRead(pirPin);

  // If PIR is sensing motion
  if (pirStatus == HIGH) {
    
    // Increment triggered
    triggered++;

    // If state is set to low
    if (pirState == LOW) {
      Serial.println("Motion detected");
      // Change state to high (sensing motion)
      pirState = HIGH;
    }

    // Squirty Wee-Wee
    squirt();

    // Don't trigger again for pauseTime
    delay(pauseTime);

  // If PIR is not sensing motion
  } else {

    // Do nothing

    // If state is set to high
    if (pirState == HIGH){
      Serial.println("Motion ended");
      // Change state to low
      pirState = LOW;
    }

  }

}

void squirt() {
  // Turn relay on
  digitalWrite(relayPin, HIGH);
  // Wait for a bit
  delay(squirtTime);
  // Turn relay off
  digitalWrite(relayPin, LOW);
}
