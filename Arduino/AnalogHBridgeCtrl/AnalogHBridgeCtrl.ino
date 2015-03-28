const uint8_t analogInPin  = A0;    // analog input pin
const uint8_t leftControl  = 11;    // left side of the H-bridge
const uint8_t rightControl = 12;    // right side of the H-bridge

int sensorValue = 0;            // value read from potentiometer
int outputValue = 0;            // value written to the analog output

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read in the analog value
  sensorValue = analogRead(analogInPin);
  // map it from the input range (0-1023) to the analog output range (-255-255)
  outputValue = map(sensorValue,0,1023,-255,255);
  // set the direction control pins
  if (outputValue > 0) {
    analogWrite(leftControl, abs(outputValue));
    digitalWrite(rightControl, LOW);
  } else if (outputValue < 0) {
    analogWrite(rightControl, abs(outputValue));
    digitalWrite(leftControl, LOW);
  } else {
    digitalWrite(leftControl, LOW);
    digitalWrite(rightControl, LOW);
  }
  // change the analog output and report values
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.println(outputValue);
  delay(10);
}
