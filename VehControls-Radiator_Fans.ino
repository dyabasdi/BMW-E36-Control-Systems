  const Kp = 1;
  const Ki = 1;
  const Kd = 1;
  const target_temp = 190;
  float prev_error = 0;


void setup() {
  Serial.begin(9600);
  // initialize variables

}

// ------------------------------------------------------------------------------------------------------------
// Begin Loop
// ------------------------------------------------------------------------------------------------------------
void loop() {
  float coolant_temp = analogRead(A0) * (/*convert to ohms and then scale to temp*/) ;
  float error = target_temp - coolant_temp;
  float integral = 
  double duty_cycle = Kp*error + Ki*integral + Kd*(error - prev_error);
  
  float prev_error = error;

}