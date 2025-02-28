int sensorValue;
float temp2 = 0;
#define led1 13
#define motor 12

void setup() {
pinMode(led1, OUTPUT);
pinMode(motor, OUTPUT);
Serial.begin(9600);
Serial.println("### Temperature monitor ###");
}

void loop() {
sensorValue = analogRead(A0);
Serial.print("Sensor Value: ");
Serial.println(sensorValue);
delay(2000);

// Convertimos el valor del sensor en temperatura (en grados Celsius)
temp2 = (sensorValue * (500.0 / 1023.0)) - 50.0;
Serial.print("Temp value: ");
Serial.println(temp2);
delay(2000); // Espera de 2 segundos

// Validación 1: Si la temperatura es inferior a 5°C, el LED parpadea con retardo de 0.5 segundos
if (temp2 < 5) {
digitalWrite(motor, LOW);
while (true) {
digitalWrite(led1, HIGH);
delay(500);
digitalWrite(led1, LOW);
delay(500);
// Salir del bucle cuando la temperatura suba
sensorValue = analogRead(A0);
temp2 = (sensorValue * (500.0 / 1023.0)) - 50.0;
if (temp2 >= 5) break;
}
}

// Validación 2: Si la temperatura está entre 6°C y 25°C, apaga el LED (sin intermitencia)
else if (temp2 >= 6 && temp2 <= 25) {
digitalWrite(led1, LOW);
digitalWrite(motor, LOW);
}

// Validación 3: Si la temperatura es mayor a 25°C, enciende el LED y el motor
else if (temp2 > 25) {
digitalWrite(led1, HIGH);
digitalWrite(motor, HIGH);
Serial.println("Motor ON");
}

delay(2000);
}
