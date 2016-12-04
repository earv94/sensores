/*void setup() {
  Serial.begin(9600);//obligatorio iniciar el serial.
  
  
 pinMode(A0, INPUT); // declarar input para recibir datos de sensores 
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 pinMode(A3, INPUT);
 pinMode(A4, INPUT);
 pinMode(A5, INPUT);
}

void loop() {
  Serial.print("sensor:\t");
  Serial.print(analogRead(A0));// imprime en el monitor serial el sensor 1.
  Serial.print("\t"); //tabula
  Serial.print(analogRead(A1));// imprime en el monitor serial el sensor 1.
  Serial.print("\t"); //tabula
  Serial.print(analogRead(A2));// imprime en el monitor serial el sensor 1.
  Serial.print("\t"); //tabula
  Serial.print(analogRead(A3));// imprime en el monitor serial el sensor 1.
  Serial.print("\t"); //tabula
  Serial.print(analogRead(A4));// imprime en el monitor serial el sensor 1.
  Serial.print("\t"); //tabula
  Serial.println(analogRead(A5));// imprime en el monitor serial el sensor 1.  //acá imprimir cada uno de los sensores, si no estoy mal se hace analogicamente, para que lo tenga en cuenta.
}


*/
// Motor A
int enA = 7; // Pin Habilita motor A - PWM
int in1 = 6;  // Pin Controla el sentido de giro
int in2 = 5; // // Pin Controla el sentido de giro

// Motor B
int enB = 2;
int in3 = 4;
int in4 = 3;

void setup()
{
  // Configura todos los pines como salidas
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void PruebaOne()
{
  // Esta prueba gira ambos motores en ambas direcciones a una velocidad fija
  // Gira el motor A en sentido horario
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Setea la velocidad a 200 en el rango posible de 0~255
  analogWrite(enA,200);
  // Gira el motor B en sentido horario
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Setea la velocidad a 200 en el rango posible de 0~255
  analogWrite(enB, 200);
  delay(3000); // Giramos los motores por 3 segundos

  // Ahora cambiamos el sentido de giro de los motores
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(3000); // Giramos los motores por 3 segundos

  // Ahora apagamos los motores
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void PruebaTwo()
{
  // En esta prueba giramos los motores en un rango posible de velocidad
  // Usamos PWM para enviar analogWrite() y controlar la maxima velocidad posible

  // Giramos los motores en un sentido
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Aceleramos desde Cero a la velocidad maxima
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  // Desaceleramos desde la velocidad maxima a Cero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  // Apagamos los motores
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void loop()
{
  PruebaOne();
  delay(2000);
  PruebaTwo();
  delay(2000);
}

