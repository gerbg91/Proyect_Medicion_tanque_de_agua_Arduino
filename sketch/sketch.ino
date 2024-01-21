
const int motor = 10;
const int emisor = 6;
const int receptor = 7;
const int pin_rojo = 5;
const int pin_verde = 4;
const int pin_amarillo = 3;
const double distancia_sonido = 0.01723;

void setup()
{
  Serial.begin(9600);
  pinMode(motor,INPUT);
  pinMode(receptor,OUTPUT);
  pinMode(emisor,INPUT);
  pinMode(pin_rojo,INPUT);
  pinMode(pin_verde,INPUT);
  pinMode(pin_amarillo,INPUT);
}

void loop()
{
  long distancia = distancia_sonido * leerUltrasonidoDistancia(receptor, emisor);
  if (distancia >= 10 and distancia <= 50) {
    digitalWrite(pin_rojo,HIGH);
    digitalWrite(pin_verde,LOW);
    digitalWrite(pin_amarillo,LOW);
    analogWrite(motor,1023);
  }else if (distancia >= 180 and distancia <= 200) {
    digitalWrite(pin_rojo,LOW);
    digitalWrite(pin_verde,HIGH);
    digitalWrite(pin_amarillo,LOW);
    analogWrite(motor,0);
  }else if (distancia > 50 and distancia < 200){
    digitalWrite(pin_rojo,LOW);
    digitalWrite(pin_verde,LOW);
    digitalWrite(pin_amarillo,HIGH);
    analogWrite(motor,1023);
  }else {
    digitalWrite(pin_rojo,LOW);
    digitalWrite(pin_verde,LOW);
    digitalWrite(pin_amarillo,LOW);
    analogWrite(motor,0);
  }
  delay(10);
}

long leerUltrasonidoDistancia(int triggerPin, int echoPin)
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH);
}