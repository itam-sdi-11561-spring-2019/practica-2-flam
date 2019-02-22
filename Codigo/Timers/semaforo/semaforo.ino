void setup(){
  
  cli();
  
  DDRB |= 1 << DDB7;
  PORTB |= 1 << PORTB7;
  DDRB |= 1 << DDB6;
  DDRB |= 1 << DDB5;
  
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCCR1B |= 1 << CS12;
  TCCR1B |= 1 << CS10;
  
  TCCR1B |= 1<< WGM12;
  
  OCR1AH = 0x3E;
  OCR1AL = 0x80;
  
  sei();
}

void loop(){
  
  asm volatile(
  "cbi 0x05, 0x05 \n\t"
  "cbi 0x05, 0x06 \n\t"
  "sbi 0x05, 0x07 \n\t"
  "ldi r16, 0x0A \n\t"
  "rouge: sbis 0x16, 0x01 \n\t"
  "rjmp rouge \n\t"
  "sbi 0x16, 1 \n\t"
  "dec r16 \n\t"
  "brne rouge \n\t"
  "cbi 0x05, 0x07 \n\t"
  "sbi 0x05, 0x05 \n\t"
  "ldi r16, 0x0C \n\t"
  "vert: sbis 0x16, 0x01 \n\t"
  "rjmp vert \n\t"
  "sbi 0x16, 1 \n\t"
  "dec r16 \n\t"
  "brne vert \n\t"
  "sbi 0x05, 0x06 \n\t"
  "ldi r16, 0x03 \n\t"
  "jaune: sbis 0x16, 0x01 \n\t"
  "rjmp jaune \n\t"
  "sbi 0x16, 1 \n\t"
  "dec r16 \n\t"
  "brne jaune \n\t"
  
  );


}
