# **IoT-Based Sensor Data Logging System**

This project implements an IoT-based sensor data logging system that monitors environmental parameters like temperature, humidity, fire, and gas levels. The system utilizes various sensors, displays the collected data on an LCD, and sends alerts over a serial connection when critical thresholds are exceeded.

## **Hardware Components**
- Arduino Uno or compatible microcontroller
- DHT11/DHT22 sensor (Temperature and Humidity)
- Fire sensor
- Gas sensor (e.g., MQ-2)
- Buzzer
- 16x2 LCD Display
- Wi-Fi Module (e.g., ESP8266)
- Jumper wires
- Breadboard

## **Libraries**
- **LiquidCrystal**: For controlling the LCD display.
- **Wire**: For I2C communication.
- **DHT**: For reading data from the DHT11/DHT22 sensor.

## **Circuit Diagram**
1. **LCD Display**: Connect as per the pin numbers mentioned in the code (13, 12, 11, 10, 9, 8).
2. **DHT Sensor**: Data pin connected to analog pin A2.
3. **Fire Sensor**: Connected to digital pin 2.
4. **Gas Sensor**: Connected to digital pin 3.
5. **Buzzer**: Connected to digital pin 7.
6. **Wi-Fi Module**: Set up for communication and alert transmission.

## **System Workflow**
1. **Setup**:
   - Initialize the sensors, LCD, and Wi-Fi module.
   - Display the initial status on the LCD.
   - Establish a Wi-Fi connection for transmitting alerts.

2. **Loop**:
   - Continuously read temperature and humidity from the DHT sensor.
   - Check for fire and gas detection.
   - Display sensor data on the LCD.
   - Trigger the buzzer and send alerts if critical thresholds are exceeded (e.g., high temperature, high humidity, fire, gas detection).

3. **Serial Communication**:
   - Alerts are sent via serial communication to a remote server or another device using AT commands.

## **Code Overview**

### **Functions**
- `setup()`: Initializes the sensors, LCD, Wi-Fi module, and sets up the serial connection.
- `loop()`: Continuously reads sensor data, updates the LCD, and triggers alerts.
- `okcheck()`: Waits for the 'OK' response from the Wi-Fi module after sending AT commands.
- `beep()`: Activates the buzzer for alert signaling.
- `converts()`, `convertl()`, `convertk()`: Helper functions to convert sensor values to the appropriate format for display or transmission.

### **Alerts**
- **High Temperature**: If the temperature exceeds 40°C.
- **High Humidity**: If the humidity exceeds 90%.
- **Fire Detected**: If the fire sensor is triggered.
- **Gas Detected**: If the gas sensor is triggered.

## **Usage**
1. Connect the components according to the circuit diagram.
2. Upload the code to the Arduino.
3. Monitor the LCD for real-time sensor data.
4. Observe alerts through the buzzer and serial communication.

## **Future Enhancements**
- Integrate a cloud-based logging system to store historical data.
- Implement remote monitoring via a web interface.
- Add more sensors for additional environmental parameters.

## **Contributing**
Feel free to fork this repository, submit issues, or suggest improvements!
