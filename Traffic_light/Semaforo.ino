// the setup function runs once when you press reset or power the board
void setup() {
  //naming the colors
  #define green 22 // Pin 22 defined as the green LED
  #define yellow 24 // Pin 24 defined as the yellow LED
  #define red 26 // Pin 26 defined as the red LED

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT); // Pin 13 is also defined as the internal LED of the board by arduino
  pinMode(green, OUTPUT); // Pin 22 configured as output for GREEN LED on protoboard for the semaforo
  pinMode(yellow, OUTPUT); // Yellow LED, configured as output
  pinMode(red, OUTPUT); // Red LED, configures as output

  // Start with all outputs in off
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  // Set up serial console:
  Serial.begin(9600); // begin serial comms, baud rate set to 9600
}

void blink_3_times(int color) {
  digitalWrite(color, LOW);   // turn the LED off by making the voltage LOW
  delay(200);                      // wait for a 1/2 second
  digitalWrite(color, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a 1/2 second
  digitalWrite(color, LOW);   // turn the LED off by making the voltage LOW
  delay(200);                      // wait for a 1/2 second
  digitalWrite(color, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a 1/2 second
  digitalWrite(color, LOW);   // turn the LED off by making the voltage LOW
  delay(200);
  digitalWrite(color, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a 1/2 second
  digitalWrite(color, LOW);   // turn the LED off by making the voltage LOW
  //delay(200);
}

// the loop function runs over and over again forever
void loop() {
  // SEMAFORO functionality:
  digitalWrite(green, HIGH); // Turn on green
  Serial.write("Green light is on! Please go ahead");
  Serial.write('\n');
  delay(2000); // Verde por 2 segs
  digitalWrite(green, LOW); // Turn off green
  blink_3_times(green); // blink green for transition

  digitalWrite(yellow, HIGH); // Turn on yellow for a sec
  Serial.write("Yellow light is on! Please prepare to stop");
  Serial.write('\n');
  delay(1000);
  digitalWrite(yellow, LOW); // Turn off yellow

  digitalWrite(red, HIGH); // Turn on red for 2 secs
  Serial.write("Red light is on! Please stop and wait.");
  Serial.write('\n');
  delay(2000);
  digitalWrite(red, LOW); // Turn off red and start again!

  Serial.write("waiting to restart...");
  Serial.write('\n');
  Serial.write('\n');
  delay(2000); //2 secs wait for restart
}
