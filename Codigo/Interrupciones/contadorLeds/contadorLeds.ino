int counter = 0;
int led = 13;
int diodo = A8;

void setup() {
   // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  cli();
  DDRK &= ~(1 << DDK0);
  PORTK |= (1 << PORTK0);
  PCICR |= (1 << PCIE2);
  PCMSK2 |= (1 << PCINT16);
  sei();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(diodo));
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);
  Serial.println("Contador: "+(String)counter);
}

ISR(PCINT2_vect){
  counter++;
}

