const int LEFT = 7;
const int RIGHT = 6;
int pin_up_list[4] = {7,6,5,4};
int pin_down_list[4] = {12,13,2,8};
int pwm_pins[4] = {11, 10, 9, 3};
int pin_all[8] = {13, 12, 8, 7, 6, 5, 4, 2};

void activate() {
  bool going_down = false;
  float pwm = 255.0;
  int delay_amt = 0;
  for (int pin: pin_up_list) {
      digitalWrite(pin, HIGH);
    }
  while (!going_down) {
    pwm += 0.0;
    for (int pin: pwm_pins) {
      analogWrite(pin, pwm);
      Serial.println(pin);
    }
    Serial.println(pwm);
    delay_amt++;
    if (delay_amt >= 300) {
      going_down = true;
    }
    delay(100);  
  }
  pwm = 0;
  delay_amt = 0;
  for (int pin: pin_up_list) {
    digitalWrite(pin, LOW);
  }
  for (int pin: pin_down_list) {
    digitalWrite(pin, HIGH);
  }
  while (going_down) {
    pwm += 0.8;
    for (int pin: pwm_pins) {
      analogWrite(pin, pwm);
      Serial.println(pin);
    }
    Serial.println(pwm);
    delay_amt++;
    if (delay_amt >= 300) {
      break;
    }
    delay(100);
  }

}

void setup() {
  // rotation pins
  Serial.begin(9600);
  for (int pin: pin_all) {
    pinMode(pin, OUTPUT);
  }
  // other pins

  // PWM pins (to control voltage)
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);

  // for the button
  pinMode(A0, INPUT);
  // for the sensor
  pinMode(A1, INPUT);

  activate();
}

void loop() {
  if (digitalRead(3)) {
    activate();
  }
  
}
