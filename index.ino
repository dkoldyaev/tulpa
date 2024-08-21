void setup() {
  Serial.begin(9600);

  // Инициализация пинов
  pinMode(A6, INPUT); // Датчик уровня жидкости
  pinMode(A5, INPUT); // Датчик света
  pinMode(A7, INPUT); // Датчик температуры
  pinMode(D2, INPUT); // Датчик шока
}

void loop() {
  // Считывание значений с датчиков
  int liquidLevel = analogRead(A6); // Уровень жидкости
  int lightLevel = analogRead(A5); // Уровень освещенности
  int temperature = analogRead(A7); // Температура
  int shockStatus = digitalRead(D2); // Состояние шока (0 или 1)

  // Вывод значений в консоль
  Serial.print("Уровень жидкости: ");
  Serial.println(liquidLevel);

  Serial.print("Уровень освещенности: ");
  Serial.println(lightLevel);

  Serial.print("Температура: ");
  Serial.println(temperature);

  Serial.print("Состояние шока: ");
  Serial.println(shockStatus);

  // Задержка перед следующим чтением
  delay(1000);
}
