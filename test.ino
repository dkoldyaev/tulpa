void setup() {
  // Настройка скорости Serial соединения
  Serial.begin(9600);
  
  // Настройка встроенного светодиода на вывод
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Включаем светодиод
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED is ON");
  
  // Задержка на 1 секунду
  delay(1000);

  // Выключаем светодиод
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED is OFF");
  
  // Задержка на 1 секунду
  delay(1000);
}

