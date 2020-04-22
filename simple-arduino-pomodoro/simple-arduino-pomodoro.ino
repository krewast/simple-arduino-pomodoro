/*
  Simple Arduino Pomodoro

  Timer based on "Blink without Delay": http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

const unsigned long pomodoroTotalMillis = (unsigned long) 25 * 60 * 1000; // 25 minutes

const unsigned long leds[][2] = {
  { 6, (unsigned long)  1 * 60 * 1000}, //  1 minute LED
  { 7, (unsigned long)  2 * 60 * 1000}, //  2 minute LED
  { 8, (unsigned long)  3 * 60 * 1000}, //  3 minute LED
  { 9, (unsigned long)  4 * 60 * 1000}, //  4 minute LED
  {10, (unsigned long)  5 * 60 * 1000}, //  5 minute LED
  {11, (unsigned long) 10 * 60 * 1000}, // 10 minute LED
  {12, (unsigned long) 15 * 60 * 1000}, // 15 minute LED
  {13, (unsigned long) 20 * 60 * 1000}  // 20 minute LED
};
// sizeof counts number of bytes, not elements. Divided by 2 at the end because the array has two dimensions
const unsigned int numOfLeds = sizeof(leds) / sizeof(unsigned long) / 2;

void setup() {
  // Set pins as outputs
  for (int x = 0; x < numOfLeds; x++) {
    pinMode(leds[x][0], OUTPUT);
  }

  startRoutine();
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long pomodoroRemainingMillis = pomodoroTotalMillis - currentMillis;

  if (pomodoroRemainingMillis <= 0)
    endRoutine();

  for (int x = 0; x < numOfLeds; x++) {
    if (pomodoroRemainingMillis >= leds[x][1])
      digitalWrite(leds[x][0], HIGH);
    else
      digitalWrite(leds[x][0], LOW);
  }
}

// ascendInterval == 0 changes the state immediately
void setAllLeds(const int state, const int ascendInterval) {
  for (int x = 0; x < numOfLeds; x++) {
    digitalWrite(leds[x][0], state);
    delay(ascendInterval);
  }
}

void startRoutine() {
  const int interval = 50;

  // Animate
  setAllLeds(HIGH, interval);
  setAllLeds(LOW,  interval);
  setAllLeds(HIGH, interval);

  // Blink
  setAllLeds(LOW, 0);
  delay(interval);
  setAllLeds(HIGH, 0);
  delay(interval);
  setAllLeds(LOW, 0);
  delay(interval);
  setAllLeds(HIGH, 0);
}

void endRoutine() {
  const int interval = 600;

  while (true) {
    // Blink
    setAllLeds(HIGH, 0);
    delay(interval);
    setAllLeds(LOW, 0);
    delay(interval);
  }
}
