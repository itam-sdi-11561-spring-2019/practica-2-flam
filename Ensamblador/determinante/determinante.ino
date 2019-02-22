int led = 13;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  int a = 10;
  int b = 20;
  int c = 30;
  int det = b*b-4*a*c;
  //Si el determinante es positivo, prende el led, si no lo apaga.
  if(det>0){
    digitalWrite(led, HIGH);
  }  
}
