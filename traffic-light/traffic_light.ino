int red = 13;
int yellow = 12;
int green = 11;

volatile int seconds = 0;

int state = 0;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  // Start with GREEN
  digitalWrite(green, HIGH);

  // Configure Timer 1
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 0;

  // 1 second
  OCR1A = 15624;

  // CTC mode
  TCCR1B |= (1 << WGM12);

  // Prescaler = 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // Enable Timer 1 Compare Match A interrupt
  TIMSK1 |= (1 << OCIE1A);

  // Enable global interrupts
  sei();
}

void loop()
{
  if (state == 0 && seconds >= 5)
  {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);

    state = 1;
    seconds = 0;
  }

  else if (state == 1 && seconds >= 2)
  {
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);

    state = 2;
    seconds = 0;
  }

  else if (state == 2 && seconds >= 5)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);

    state = 0;
    seconds = 0;
  }
}

ISR(TIMER1_COMPA_vect)
{
  seconds++;
}
