void setup() {
  Serial.begin(9600);
}

void loop() {
  int8_t n = 5;//(Serial.readString()).toInt();
  int8_t arr[5] = {2,5,7,3,4} ;
  int8_t *ptr = arr;
  int8_t avg = 10, residuo = 0;

  /*
  for(int i = 0; i < n; i++){
    Serial.println("Escribe el numero "+i);
    arr[i] = (Serial.readString()).toInt();
  }
  */
  

  asm volatile(
    "ldi r16, 0x00 \n\t"
    "ldi r19, 0x00 \n\t" 
    "ldi r17, %2 \n\t"
    "suma: \n\t"
    "ld r18, %a3+ \n\t"
    "add r19, r18 \n\t"
    "inc r16 \n\t"
    "cpse r17, r16 \n\t"
    "jmp suma \n\t"
    "ldi r20, 0x00 \n\t"
    "div: \n\t"
    "cp r19, r17 \n\t"
    "brlt  fin\n\t"
    "sub r19, r17 \n\t"
    "inc r20 \n\t"
    "jmp div \n\t"
    "fin: \n\t"
    "mov %1, r19 \n\t"
    "mov %0, r20 \n\t"
    :"=&d" (avg), "=&d" (residuo)
    :"M" (n), "e" (ptr)
    );
    
    Serial.println("El promedio es "+ (String) avg + ", con residuo " + (String) residuo);
  
  delay(5000);

}
