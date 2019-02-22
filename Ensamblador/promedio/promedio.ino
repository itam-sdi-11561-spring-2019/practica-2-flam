int sum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int n = (Serial.readString()).toInt();
  
  for(int i = 1; i <= n; i++){
    Serial.println("Escribe el numero "+i);
    sum += (Serial.readString()).toInt();
  }
  double avg = sum/n;

  Serial.println("El promedio es: ");
  Serial.print((String)avg);
}
