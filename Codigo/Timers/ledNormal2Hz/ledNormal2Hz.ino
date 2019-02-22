void setup(){
  
  cli();
  
  DDRB |= 1 << DDB7;
  PORTB |= 1 << PORTB7;
  
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCCR1B |= 1 << CS12;
  TCCR1B |= 1 << CS10;
  
  TCNT1H = 0xE0;
  TCNT1L = 0xC0;
  
  TIMSK1 = 0;
  TIMSK1 |=  1 << TOIE1;
  
  sei();
}

void loop(){
}

ISR(TIMER1_OVF_vect){
  //PORTB = 0x05
  asm volatile(
    "sbis 0x05, 7\n\t"
    "rjmp on\n\t"
    "cbi 0x05, 7\n\t"
    "rjmp end\n\t"
    "on: sbi 0x05, 7\n\t"
    "end:"
   );
   
  TCNT1H = 0xF0;
  TCNT1L = 0x60;
}
