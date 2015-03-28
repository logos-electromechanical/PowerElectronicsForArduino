const uint8_t analogInPin  = A0;    // analog input pin
const uint8_t analogOutPin = 11;    // analog output pin
const uint8_t dirPin1      = 13;
const uint8_t dirPin2      = 12;


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
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
  } else if (outputValue < 0) {
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  } else {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, LOW);
  }
  // change the analog output and report values
  analogWrite(analogOutPin, abs(outputValue));
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.println(outputValue);
  delay(10);
}
