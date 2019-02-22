int led = 13;
int boton = 20;
int counter = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);

  if(digitalRead(boton) == HIGH){
    counter++;
    Serial.println("Boton apretado "+(String)counter);
  }
}
