/*
  Simple Arduino Pomodoro

  Timer based on "Blink without Delay": http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

const int led1Min  = 6;
const int led2Min  = 7;
const int led3Min  = 8;
const int led4Min  = 9;
const int led5Min  = 10;
const int led10Min = 11;
const int led15Min = 12;
const int led20Min = 13;

const unsigned long pomodoroTotalMillis = (unsigned long) 25 * 60 * 1000;

void setup() {
  // Set pins as outputs
  pinMode(led1Min,  OUTPUT);
  pinMode(led2Min,  OUTPUT);
  pinMode(led3Min,  OUTPUT);
  pinMode(led4Min,  OUTPUT);
  pinMode(led5Min,  OUTPUT);
  pinMode(led10Min, OUTPUT);
  pinMode(led15Min, OUTPUT);
  pinMode(led20Min, OUTPUT);

  startRoutine();
}

void startRoutine() {
  const int interval = 50;

  // Animate
  setAllLedsAscending(HIGH, interval);
  delay(interval);
  setAllLedsAscending(LOW, interval);
  delay(interval);
  setAllLedsAscending(HIGH, interval);

  // Blink
  setAllLeds(LOW);
  delay(interval);
  setAllLeds(HIGH);
  delay(interval);
  setAllLeds(LOW);
  delay(interval);
  setAllLeds(HIGH);
}

void endRoutine() {
  const int interval = 600;

  while (true) {
    // Blink
    setAllLeds(HIGH);
    delay(interval);
    setAllLeds(LOW);
    delay(interval);
  }
}

void setAllLeds(const int state) {
  digitalWrite(led1Min,  state);
  digitalWrite(led2Min,  state);
  digitalWrite(led3Min,  state);
  digitalWrite(led4Min,  state);
  digitalWrite(led5Min,  state);
  digitalWrite(led10Min, state);
  digitalWrite(led15Min, state);
  digitalWrite(led20Min, state);
}

void setAllLedsAscending(const int state, const int interval) {
  digitalWrite(led1Min,  state);
  delay(interval);
  digitalWrite(led2Min,  state);
  delay(interval);
  digitalWrite(led3Min,  state);
  delay(interval);
  digitalWrite(led4Min,  state);
  delay(interval);
  digitalWrite(led5Min,  state);
  delay(interval);
  digitalWrite(led10Min, state);
  delay(interval);
  digitalWrite(led15Min, state);
  delay(interval);
  digitalWrite(led20Min, state);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long pomodoroRemainingMillis = pomodoroTotalMillis - currentMillis;

  if (pomodoroRemainingMillis <= 0)
    endRoutine();

  // 1 minute LED
  if (pomodoroRemainingMillis >= (unsigned long) 1 * 60 * 1000)
    digitalWrite(led1Min, HIGH);
  else
    digitalWrite(led1Min, LOW);

  // 2 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 2 * 60 * 1000)
    digitalWrite(led2Min, HIGH);
  else
    digitalWrite(led2Min, LOW);

  // 3 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 3 * 60 * 1000)
    digitalWrite(led3Min, HIGH);
  else
    digitalWrite(led3Min, LOW);

  // 4 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 4 * 60 * 1000)
    digitalWrite(led4Min, HIGH);
  else
    digitalWrite(led4Min, LOW);

  // 5 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 5 * 60 * 1000)
    digitalWrite(led5Min, HIGH);
  else
    digitalWrite(led5Min, LOW);

  // 10 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 10 * 60 * 1000)
    digitalWrite(led10Min, HIGH);
  else
    digitalWrite(led10Min, LOW);

  // 15 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 15 * 60 * 1000)
    digitalWrite(led15Min, HIGH);
  else
    digitalWrite(led15Min, LOW);

  // 20 minutes LED
  if (pomodoroRemainingMillis >= (unsigned long) 20 * 60 * 1000)
    digitalWrite(led20Min, HIGH);
  else
    digitalWrite(led20Min, LOW);
}
