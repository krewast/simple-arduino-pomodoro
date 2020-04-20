/*
  Simple Arduino Pomodoro

  Timer based on Blink without Delay: http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

const int led1Min  = 6;
const int led2Min  = 7;
const int led3Min  = 8;
const int led4Min  = 9;
const int led5Min  = 10;
const int led10Min = 11;
const int led15Min = 12;
const int led20Min = 13;

const unsigned long pomodoroMillis = (unsigned long) 25 * 60 * 1000;

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
  allLedsHighAscending(interval);
  delay(interval);
  allLedsLowAscending(interval);
  delay(interval);
  allLedsHighAscending(interval);

  // Blink
  allLedsLow();
  delay(interval);
  allLedsHigh();
  delay(interval);
  allLedsLow();
  delay(interval);
  allLedsHigh();
}

void endRoutine() {
  const int interval = 600;

  while (true) {
    // Blink
    allLedsHigh();
    delay(interval);
    allLedsLow();
    delay(interval);
  }
}

void allLedsHighAscending(const int interval) {
  digitalWrite(led1Min,  HIGH);
  delay(interval);
  digitalWrite(led2Min,  HIGH);
  delay(interval);
  digitalWrite(led3Min,  HIGH);
  delay(interval);
  digitalWrite(led4Min,  HIGH);
  delay(interval);
  digitalWrite(led5Min,  HIGH);
  delay(interval);
  digitalWrite(led10Min, HIGH);
  delay(interval);
  digitalWrite(led15Min, HIGH);
  delay(interval);
  digitalWrite(led20Min, HIGH);
}

void allLedsLowAscending(const int interval) {
  digitalWrite(led1Min,  LOW);
  delay(interval);
  digitalWrite(led2Min,  LOW);
  delay(interval);
  digitalWrite(led3Min,  LOW);
  delay(interval);
  digitalWrite(led4Min,  LOW);
  delay(interval);
  digitalWrite(led5Min,  LOW);
  delay(interval);
  digitalWrite(led10Min, LOW);
  delay(interval);
  digitalWrite(led15Min, LOW);
  delay(interval);
  digitalWrite(led20Min, LOW);
}

void allLedsHigh() {
  digitalWrite(led1Min,  HIGH);
  digitalWrite(led2Min,  HIGH);
  digitalWrite(led3Min,  HIGH);
  digitalWrite(led4Min,  HIGH);
  digitalWrite(led5Min,  HIGH);
  digitalWrite(led10Min, HIGH);
  digitalWrite(led15Min, HIGH);
  digitalWrite(led20Min, HIGH);
}

void allLedsLow() {
  digitalWrite(led1Min,  LOW);
  digitalWrite(led2Min,  LOW);
  digitalWrite(led3Min,  LOW);
  digitalWrite(led4Min,  LOW);
  digitalWrite(led5Min,  LOW);
  digitalWrite(led10Min, LOW);
  digitalWrite(led15Min, LOW);
  digitalWrite(led20Min, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long pomodoroLeftMillis = pomodoroMillis - currentMillis;

  if (pomodoroLeftMillis <= 0)
    endRoutine();

  // 1 minute LED
  if (pomodoroLeftMillis >= (unsigned long) 1 * 60 * 1000)
    digitalWrite(led1Min, HIGH);
  else
    digitalWrite(led1Min, LOW);

  // 2 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 2 * 60 * 1000)
    digitalWrite(led2Min, HIGH);
  else
    digitalWrite(led2Min, LOW);

  // 3 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 3 * 60 * 1000)
    digitalWrite(led3Min, HIGH);
  else
    digitalWrite(led3Min, LOW);

  // 4 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 4 * 60 * 1000)
    digitalWrite(led4Min, HIGH);
  else
    digitalWrite(led4Min, LOW);

  // 5 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 5 * 60 * 1000)
    digitalWrite(led5Min, HIGH);
  else
    digitalWrite(led5Min, LOW);

  // 10 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 10 * 60 * 1000)
    digitalWrite(led10Min, HIGH);
  else
    digitalWrite(led10Min, LOW);

  // 15 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 15 * 60 * 1000)
    digitalWrite(led15Min, HIGH);
  else
    digitalWrite(led15Min, LOW);

  // 20 minutes LED
  if (pomodoroLeftMillis >= (unsigned long) 20 * 60 * 1000)
    digitalWrite(led20Min, HIGH);
  else
    digitalWrite(led20Min, LOW);
}
