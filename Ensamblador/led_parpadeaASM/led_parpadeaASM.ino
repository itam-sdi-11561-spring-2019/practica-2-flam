void setup() {
  // put your setup code here, to run once:
  cli();
  DDRB |= 1 << DDB7;
  PORTB |= 1 << PORTB7;
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
  OCR1AH = 0x20; 
  OCR1AL = 0x00;
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_COMPA_vect){
  //PORTB = 0x05
  asm volatile(
    "sbis 0x05, 7\n\t"
    "rjmp on\n\t"
    "cbi 0x05, 7\n\t"
    "rjmp end\n\t"
    "on: sbi 0x05, 7\n\t"
    "end: \n\t"
   );
}
