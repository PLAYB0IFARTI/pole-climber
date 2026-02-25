const int LEFT = 7;
const int RIGHT = 6;
int pin_up_list[4] = {7,6,5,4};
int pin_down_list[4] = {11,10,9,8};
int pin_all[8] = {11, 10, 9, 8, 7, 6, 5, 4};
uint8_t analog_pins[4] = {A0, A1, A2, A3};

void activate() {
  bool going_down = false;
  int pwm = 128;
  int delay_amt = 0;
  for (int pin: pin_up_list) {
      digitalWrite(pin, HIGH);
    }
  while (!going_down) {
    pwm += 0;
    for (uint8_t pin: analog_pins) {
      analogWrite(pin, pwm);
      Serial.println("im spinning");

      Serial.println(pin);
    }
    delay_amt++;
    if (delay_amt / 10 <= 30) {
      going_down = true;
    }
    delay(100);  
  }
  pwm = 128;

}

void setup() {
  // rotation pins
  Serial.begin(9600);
  for (int pin: pin_all) {
    pinMode(pin, OUTPUT);
  }
  // other pins

  // analog pins (to control voltage)
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  // for the button
  pinMode(3, INPUT);
  // for the sensor
  pinMode(2, INPUT);

  activate();
}

void loop() {
  if (digitalRead(3)) {
    activate();
  }
  
}
