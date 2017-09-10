const int boton=6;
const int led6=8;

void setup() {
  pinMode(boton, INPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  if (digitalRead(boton)==LOW)
  {
    digitalWrite(led6, HIGH);
    delay(2000);
    digitalWrite(led6, LOW);
  }
}
