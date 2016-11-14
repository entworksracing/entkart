/*
  BFBLDC motor driver

  reads throttle position and outputs signal to energize coils in a brushless DC motor
 
  This code is licenced under the GNU-GPL v3.
  
 */
 
// coil pins:

int coil_one = 11;
int coil_two = 10;
int coil_three = 9;

// the setup routine runs once when you press reset:

void setup() { 
  
  // initialize the digital pins as outputs.
  
  pinMode(coil_one, OUTPUT);   
  pinMode(coil_two, OUTPUT);
  pinMode(coil_three, OUTPUT);  
  
  //startup_sequence
  
  digitalWrite(coil_two, HIGH);
  delay(1000);
  digitalWrite(coil_two, LOW);
  digitalWrite(coil_three, HIGH);
  delay(1000);
  digitalWrite(coil_three, LOW);
  
}

// the loop routine runs over and over again forever:

void loop() {
   
  int throttle_position1 = .25*analogRead(0);  //  read the throttle position
  
  digitalWrite(coil_one, HIGH);   // turn the signal to coil set 1 on
  delay(throttle_position1);               // wait for the period determined by the position of the throttle
  digitalWrite(coil_one, LOW);    // turn the signal to coil 1 off by making the voltage LOW
  delay(1);               // time until energizing the next set of coils
  
  int throttle_position2 = .25*analogRead(0);
  
  digitalWrite(coil_two, HIGH);
  delay(throttle_position2);
  digitalWrite(coil_two, LOW);
  delay(1);
  
  int throttle_position3 = .25*analogRead(0);
  
  digitalWrite(coil_three, HIGH);
  delay(throttle_position3);
  digitalWrite(coil_three, LOW);
  delay(1);
}
