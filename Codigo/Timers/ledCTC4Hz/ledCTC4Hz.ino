void setup(){
  cli();
  
  DDRB |= 1 << DDB7;
  PORTB |= 1 << PORTB7;
  
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCCR1B |= 1 << CS12;
  TCCR1B |= 1 << CS10;
  TCCR1B |= 1 << WGM12;
  
  OCR1AH = 0x0F;
  OCR1AL = 0xA0;
  
  TIMSK1 = 0;
  TIMSK1 |=  1 << OCIE1A;
  
  sei();
}

void loop(){
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
