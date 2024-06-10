volatile float manifold_pressure = analogRead(A0) *(/*Linear relationship for pressure sensor*/);
const int activation_pressure = 5;//activates second fuel pump at this pressure
const int output_pin = 2;//pin on arduino


void setup() {
  Serial.begin(9600);
  // initialize variables
}

// ------------------------------------------------------------------------------------------------------------
// Begin Loop
// ------------------------------------------------------------------------------------------------------------
void loop() {
    while (manifold_pressure > activation_pressure){
        digitalWrite(output_pin, HIGH);
    }
}