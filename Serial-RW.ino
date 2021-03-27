/*
  Serial-WR

  Output hello to Serial
  Read input from Serial. If there is a 'E' detected, flip the LED

  yluo
  
*/  

float high_thresh = 6;
float low_thresh = -6;
// LED status
//int led_status = HIGH;
int incomingByte = 0;

int x_val;
int y_val;

#define buzzerPin 51
#define x_axis A0
#define y_axis A1

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //led_status = HIGH;

  pinMode(buzzerPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  x_val = analogRead(x_axis);
  y_val = analogRead(y_axis);

  if(x_val < 400 && y_val > 500 && y_val < 550) {

    Serial.print("L");
    delay(300);   
  }
  
  if(x_val > 700 && y_val > 500 && y_val < 550) {

    Serial.print("R");
    delay(300);
  }
 
  if(y_val < 400 && x_val > 475 && x_val < 525) {

    Serial.print("U");
    delay(300);  
  }
  
  if(y_val > 700 && x_val > 475 && x_val < 525) {

    Serial.print("D");
    delay(300);
  }

  
  // read from the Serial port:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.print(incomingByte);
    
    if(incomingByte == 'E') {
      // flip LED
      //led_status = (led_status == HIGH)? LOW : HIGH;
      digitalWrite(buzzerPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
    }
  }

}
