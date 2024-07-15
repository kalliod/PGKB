void setup() {
  // open the serial port:
  //Serial.ignoreFlowControl();
  //Serial1.setPollingMode(true);
  Serial.begin(115200);
  while(!Serial) {;;}

  // initialize control over the keyboard:
  Serial.println("Setup complete");
}

void loop() {
  // keep watching the push buttons
  Serial.println("Loop");
  delay(1000);
}
