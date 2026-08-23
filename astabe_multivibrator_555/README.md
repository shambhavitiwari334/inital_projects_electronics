# Astable Multivibrator using 555 Timer IC

## What it does
A transistor-based astable multivibrator circuit that generates a continuous 
square wave output, causing an LED to blink (turn ON and OFF rapidly). Fully analog — 
no microcontroller or programming involved. Built during first-year coursework.

## Components
- NE555 Timer IC (DIP-8) along with base
- 3 x Resistors (R1= 2.3kohm, R2= 3.8kohm, R for led= 330ohm)
- 2 x Capacitors (C1= 0.01 microfarad electrolytic, C2= 10nF ceramic)
- LED (Red)
- 9V Battery

## Build
![PCB photo](./pcb_photo.jpeg)
![breadboard photo](./breadboard_photo.jpeg)
![See output signal on DSO](./oscilloscope_photo.jpeg)
[Tinkercad simulation link](https://www.tinkercad.com/things/9UWTqhIc7bS-astable-multivibrator?sharecode=24KyLWJFIdCRHLIxljLEY-yAc45WQWKRsC8CW3FnLB0)

## What I learned
- Time constant and how it affects frequency in an RC circuit
- Soldering and hardware debugging on a zero PCB
- Foundational analog concepts that underlie timing behaviour even in 
  digital/embedded systems
