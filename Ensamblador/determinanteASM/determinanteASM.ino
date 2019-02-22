int led = 13;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int det;
  
  asm volatile(
    "ldi r16, 0x14 \n\t"
    "muls r16, r16 \n\t"
    "mov r16, r0 \n\t"
    "mov r17, r1 \n\t"
    "ldi r18, 0x0A \n\t"
    "ldi r19, 0x1E \n\t"
    "muls r18, r19 \n\t"
    "mov r18, r0 \n\t"
    "mov r19, r1 \n\t"
    "lsl r18 \n\t"
    "rol r19 \n\t"
    "lsl r18 \n\t"
    "rol r19 \n\t"
    "sub r16, r18 \n\t"
    "sbc r17, r19 \n\t"
    "movw %0, r16 \n\t"
    :"=r" (det)
    :
  );
  
  //Si el determinante es positivo, prende el led, si no lo apaga.
  if(det>0){
    digitalWrite(led, HIGH);
  }
  
}
