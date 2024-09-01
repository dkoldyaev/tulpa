import serial

# Укажите порт и скорость передачи данных
ser = serial.Serial('/dev/cu.usbmodem00001', 9600)

# Откройте файл для записи данных
with open('output.txt', 'w') as file:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)  # Печать в консоль
            file.write(line + '\n')  # Запись в файл

