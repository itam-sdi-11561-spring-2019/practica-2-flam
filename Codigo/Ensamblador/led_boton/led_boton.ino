int led = 13;
int boton = 31;
int flag = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  if( digitalRead(boton) == HIGH){
    if(flag == 0){
      digitalWrite(led, HIGH);
      flag = 1;
    }else{
      digitalWrite(led, LOW);
      flag = 0;
    }
  }
  
  delay(250);
}
