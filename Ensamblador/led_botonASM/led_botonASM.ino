void setup() {
  // put your setup code here, to run once:
  cli();
  DDRB |= 1 << DDB7;
  PORTB |= 1 << PORTB7;
  DDRD &= ~(1 << DDD1);
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC10) | (1 << ISC11);
  EIMSK |= (1 << INT1);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(INT1_vect){
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
