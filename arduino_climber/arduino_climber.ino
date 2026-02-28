const int LEFT = 7;
const int RIGHT = 6;
const int trigPin = A1;
const int echoPin = A2;
int pin_down_list[4] = {2, 4, 9, 12};
int pin_up_list[4] = {3, 5, 10, 11};
uint16_t pwm_pins[4] = {A6, A5, A4, A3};
int pin_all[8] = {2, 4, 10, 12, 3, 5, 9, 11};
bool machine_on = false;

void activate() {
  bool going_down = false;
  float pwm = 255.0;
  int delay_amt = 0;
  for (int pin: pin_up_list) {
      digitalWrite(pin, HIGH);
    }
  while (!going_down) {
    pwm += 0.0;
    Serial.println("im on");
    for (int pin: pwm_pins) {
      analogWrite(pin, pwm);
    }
    // Serial.println(pwm);
    delay_amt++;

    if (analogRead(A1) >= 1) {
      // Serial.print("gkofdg");
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
    Serial.print("im doing it");
    pwm += 0.8;
    for (int pin: pwm_pins) {
      analogWrite(pin, pwm);
    }
    delay_amt++;
    if (delay_amt >= 300) {
      break;
    }
    delay(100);
  }
  machine_on = false;

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
  pinMode(6, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(A1, INPUT);

}

void loop() {
  Serial.println(analogRead(A1));
  if (analogRead(A1) >= 1 && !machine_on) {
    Serial.print("im on");
    activate();
    machine_on = true;
  }
  else {
    // Serial.println("notup");
  }
  
}
