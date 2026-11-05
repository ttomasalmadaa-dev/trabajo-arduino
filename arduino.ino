/* 
  Proyecto: Luz automática con sensor de movimiento
  Equipo: TecnoSoluciones
  Integrantes: Joaquin, Benja, Tomi
*/

// Definición de los pines según tu conexión
const int pinPIR = 4;   // Pin digital donde está conectado el sensor PIR
const int pinLED = 13;  // Pin digital donde está conectado el LED

// Variable para almacenar el estado del sensor
int estadoSensor = 0;   

void setup() {
  // Configuramos el pin del sensor PIR como entrada
  pinMode(pinPIR, INPUT);
  
  // Configuramos el pin del LED como salida
  pinMode(pinLED, OUTPUT);
  
  // Inicializamos la comunicación serie para monitoreo (opcional)
  Serial.begin(9600);
}

void loop() {
  // Leemos el valor del sensor PIR (HIGH si detecta movimiento, LOW si no)
  estadoSensor = digitalRead(pinPIR);

  // Verificamos si se detectó movimiento
  if (estadoSensor == HIGH) {
    digitalWrite(pinLED, HIGH); // Encendemos la luz
    Serial.println("¡Movimiento detectado! Luz encendida.");
  } else {
    digitalWrite(pinLED, LOW);  // Apagamos la luz
    Serial.println("Sin movimiento. Luz apagada.");
  }

  // Pequeña pausa para estabilizar la lectura
  delay(200);
}