/*
  Project name: Simple Arduino Pomodoro
  Author: Bastian Kres - krewast.de
  Created: 2020-04-20
  Description: A simple Pomodoro timer that shows its current state with few LEDs. Based on Arduino.
  Project URL: https://github.com/krewast/simple-arduino-pomodoro

  Project based on code from:
  - "Blink without Delay": http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
  - "Fade": http://www.arduino.cc/en/Tutorial/Fade

  Copyright (c) 2020 Bastian Kres
  Licensed under the MIT License
*/

#define WORK_TIME_IN_MINUTES  25 // Default: 25 (minutes)
#define PAUSE_TIME_IN_MINUTES  5 // Default:  5 (minutes)

const unsigned long pomodoroWorkMillis  = (unsigned long) WORK_TIME_IN_MINUTES  * 60 * 1000;
const unsigned long pomodoroPauseMillis = (unsigned long) PAUSE_TIME_IN_MINUTES * 60 * 1000;
const unsigned long pomodoroTotalMillis = pomodoroWorkMillis + pomodoroPauseMillis;

// Work LEDs (red & green)
const unsigned long workLeds[][2] = {
  { 4, (unsigned long)              0}, //  0 -  1 minute  left LED (green)
  { 5, (unsigned long)  1 * 60 * 1000}, //  1 -  2 minutes left LED (green)
  { 6, (unsigned long)  2 * 60 * 1000}, //  2 -  3 minutes left LED (green)
  { 7, (unsigned long)  3 * 60 * 1000}, //  3 -  4 minutes left LED (green)
  { 8, (unsigned long)  4 * 60 * 1000}, //  4 -  5 minutes left LED (green)
  { 9, (unsigned long)  5 * 60 * 1000}, //  5 - 10 minutes left LED (red)
  {10, (unsigned long) 10 * 60 * 1000}, // 10 - 15 minutes left LED (red)
  {11, (unsigned long) 15 * 60 * 1000}, // 15 - 20 minutes left LED (red)
  {12, (unsigned long) 20 * 60 * 1000}  // 20 - 25 minutes left LED (red)
};
// sizeof() counts the number of bytes, not elements.
// Divide sizeof(workLeds) by sizeof(unsigned long) to get the number of bytes the array "occupies".
// Divide by 2 (because the array has two dimensions) to get the number of elements.
const int numOfWorkLeds = sizeof(workLeds) / sizeof(unsigned long) / 2;

// Pause LED (blue)
const int pauseLed = 3;
int pauseLedBrightness = 0;
int pauseLedFadeAmount = 1;
unsigned long pauseLedLastBrightnessChangeMillis = 0;

void setup() {
  // Set pins as outputs
  for (int x = 0; x < numOfWorkLeds; x++) {
    pinMode(workLeds[x][0], OUTPUT);
  }
  pinMode(pauseLed, OUTPUT);

  startRoutine();
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long pomodoroRemainingMillis = pomodoroTotalMillis - currentMillis;

  if (pomodoroRemainingMillis == 0)
    endRoutine();

  if (pomodoroRemainingMillis >= pomodoroPauseMillis) {
    for (int x = 0; x < numOfWorkLeds; x++) {
      if (pomodoroRemainingMillis - pomodoroPauseMillis > workLeds[x][1])
        digitalWrite(workLeds[x][0], HIGH);
      else
        digitalWrite(workLeds[x][0], LOW);
    }
  } else if (currentMillis - pauseLedLastBrightnessChangeMillis >= 8) {
    pauseLedLastBrightnessChangeMillis = currentMillis;

    analogWrite(pauseLed, pauseLedBrightness);

    pauseLedBrightness += pauseLedFadeAmount;
    if (pauseLedBrightness <= 0 || pauseLedBrightness >= 255)
      pauseLedFadeAmount = -pauseLedFadeAmount;
  }
}

// ascendInterval == 0 changes the state immediately
void setAllWorkLeds(const int state, const int ascendInterval) {
  for (int x = 0; x < numOfWorkLeds; x++) {
    digitalWrite(workLeds[x][0], state);
    delay(ascendInterval);
  }
}

void startRoutine() {
  const int interval = 50;

  // Animate
  setAllWorkLeds(HIGH, interval);
  setAllWorkLeds(LOW,  interval);
  setAllWorkLeds(HIGH, interval);

  // Blink
  setAllWorkLeds(LOW, 0);
  delay(interval);
  setAllWorkLeds(HIGH, 0);
  delay(interval);
  setAllWorkLeds(LOW, 0);
  delay(interval);
  setAllWorkLeds(HIGH, 0);
}

void endRoutine() {
  const int interval = 600;

  digitalWrite(pauseLed, LOW);

  while (true) {
    // Blink
    setAllWorkLeds(HIGH, 0);
    delay(interval);
    setAllWorkLeds(LOW, 0);
    delay(interval);
  }
}
