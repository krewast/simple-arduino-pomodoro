# Simple Arduino Pomodoro

**Already working, but still under development.**

The goal of this project is to build a fully functioning Pomodoro timer with a microcontroller and only a few additional components (LEDs, resistors, etc.).
It's aimed at beginners who are interested in electronics and programming with Arduinos.
There are two independent steps:

- Step 1 (Easy): Build the entire circuit on a solderless breadboard to see how it works.
- Step 2 (Intermediate): Transfer the circuit to a prototype PCB. This is is a bit more complicated as it requires soldering and a few more components.


## What is the Pomodoro Technique?

The Pomodoro Technique is time management method.
It can help to avoid procrastination by breaking down work into intervals of intense focus, separated by short breaks.

There are six steps in the original technique:

1. Decide on the task to be done.
2. Set the pomodoro timer (traditionally to 25 minutes).
3. Work on the task.
4. End work when the timer rings and put a checkmark on a piece of paper.
5. If you have fewer than four checkmarks, take a short break (3–5 minutes), then go to step 2.
6. After four pomodoros, take a longer break (15–30 minutes), reset your checkmark count to zero, then go to step 1.

Explanation mostly copied from the <a href="https://en.wikipedia.org/wiki/Pomodoro_Technique" title="Pomodoro Technique" target="_blank">Wikipedia article</a>.


## How this timer works

I wanted to keep it as simple as possible.
That's why I chose to use just a handful of LEDs to show the current state of the Pomodoro cycle (work, pause) and how much time is left for focused work.

There are ten LEDs.
Nine of them (the red and green ones) are used as countdown for the 25 minute long "work" state, while the blue indicates a 5 minute pause.
The difference between red and green LEDs is the period of time each of them covers:

- Red: 5 minute steps for the first 20 minutes
- Green: 1 minute steps for the last 5 minutes.

Here the entire overview:

| Nr.   | Color |        Stands for... |
|:------|:------|---------------------:|
| LED 9 | red   | 20 - 25 minutes left |
| LED 8 | red   | 15 - 20 minutes left |
| LED 7 | red   | 10 - 15 minutes left |
| LED 6 | red   |  5 - 10 minutes left |
| LED 5 | green |  4 -  5 minutes left |
| LED 4 | green |  3 -  4 minutes left |
| LED 3 | green |  2 -  3 minutes left |
| LED 2 | green |  1 -  2 minutes left |
| LED 1 | green |  0 -  1 minute  left |
| LED 0 | blue  |                Pause |

If anyone's wondering: I didn't use the binary format (<a href="https://en.wikipedia.org/wiki/Binary_clock" title="Pomodoro Technique" target="_blank">Binary clock</a>) to show how much work time is left on purpose, as it constantly requires some mental math.
That would have been too distracting, and like I wrote before, I wanted to keep it as simple as possible.


## Why does this project exists?

Well, mainly because I wanted to do a little electronics project again for a long time now.
Even though I work as a web developer today (after studying) I initially started out as an electrician technician.
So this is basically a "back to the roots" project for me :)

A Pomodoro timer is also something I consider to be useful for me (I tend to be easily distracted sometimes) and others - Win, win!

Oh, and yes: There are a lot of apps and websites out there that more or less do the same thing as this timer.
The issue I have with them is that they are often a gateway to unwanted procrastination.
Picking up your phone to see how much time is left?
"Let me just check my messages real quick."
Switching to the browser to see what the timer is saying?
"Okay, but how about some cat videos?"
Also: It's simply fun to build something instead of just downloading!


## Step 1 (Easy): Arduino Uno + Breadboard

This section shows how an Arduino Uno Board has to be connected to a few LEDs (and resistors) on a breadboard to work with this projects code.


### Parts list

- 1 Arduino Uno (+ USB cable)
- 1 Breadboard
- 11 Breadboard wires (Best: Male to Male jumpers)
- 10 LEDs (4x red, 5x green, 1x blue - But it doesn't really matter)
- 10 150Ω resistors (180Ω oder 220Ω are also fine)


### Calculating the right resistor value (for the interested)

The operating voltage of an Arduino board is 5V (Volt).
Even though the input voltage can be higher (7 - 12V according to the data sheet), the board itself runs on 5V.
This is also the voltage on each output pin (if its state is set to HIGH) - a problem for most LEDs.
Why?
Because they usually require a forward voltage of only about 2 - 2.5V.
Using 5V directly would destroy most LEDs really fast if not immediately.
So, the voltage needs to be "brought down".

To do so, resistors can be used.
They are available in different shapes and sizes but the most relevant attribute in this case is the right value.
It can be calculated using <a href="https://en.wikipedia.org/wiki/Ohm%27s_law" title="Pomodoro Technique" target="_blank">Ohm's law</a>:

```
I = V / R
```

After rearranging the equation:

```
R = V / I
```

To get the right value for the resistor (`R`), the correct voltage (`V`) and current (`I`) are required.

As mentioned before, LEDs require a forward voltage of about 2 - 2.5V.
The save choice is to assume 2V.
This value has to be subtracted from the source voltage of 5V.
That means: `V = 5V - 2V`

The current that's necessary to make a standard LED shine is 20mA (milliamps).
That's the value for `I`.

```
R = (5V - 2V) / 20mA
R = 150Ω
```

To illustrate this calculation, a simplified version of each LED circuit:

<img src="Resistor-Value-Calculation/Resistor-Value-Calculation-Circuit-Diagram.svg" style="height: 300px;">

5V source voltage "at the top", the LED that requires a forward voltage of 2V and a current of 20mA and the 150Ω resistor connected to ground "at the bottom".

Higher values than 150Ω are also okay but will dim the LEDs in comparison.


### Breadboard wiring

<img src="Arduino-Uno-Breadboard/Arduino-Uno-Breadboard.svg" style="width: 100%;">


### Breadboard circuit diagram

<img src="Arduino-Uno-Breadboard/Arduino-Uno-Breadboard-Circuit-Diagram.svg" style="width: 100%;">

## Step 2 (Intermediate): ATtiny2313 on a prototype PCB (+ Arduino Uno as programmer)

Coming soon.
