#define BASIC_LED_PIN 35 // 35-43
#define BUTTON_PIN A3 // A3
#define CYCLE_DELAY 1000 // ms 


int led_pins[9];

void setup(){
    for (int i = 0; i < 9; i++){
      led_pins[i] = BASIC_LED_PIN;
      led_pins[i] += i;
      pinMode(led_pins[i], OUTPUT);
    }
    Serial.begin(9600);
    Serial.println("HELLO IN DA PROGRAM");
}

void algorithm(){
  // HIGH 
  // LOW
  lights_on();
  for (int i = 0; i < 9; i+=2){
    digitalWrite(led_pins[i], HIGH);
    delay(CYCLE_DELAY); // in ms
    digitalWrite(led_pins[i], LOW);
    Serial.println(led_pins[i]);
  }
  for (int i = 1; i < 9; i+=2){
    digitalWrite(led_pins[i], HIGH);
    delay(CYCLE_DELAY); // in ms
    digitalWrite(led_pins[i], LOW);
    Serial.println(i);
  }
}

void lights_on(){
  for (int i = 0; i < 9; i++){
    digitalWrite(led_pins[i], HIGH);
  }
  delay(650);
  for (int i = 0; i < 9; i++){
    digitalWrite(led_pins[i], LOW);
  }
}

void loop(){
  if (analogRead(BUTTON_PIN)){
    algorithm();
  }
  else {
    lights_on();
    delay(500);
  }
}
