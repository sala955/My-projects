#include <Servo.h>
#include <DHT.h>

#define Heater 2        // السخان (LED أحمر)
#define RelayPIN 4      // الريليه (المضخة)
#define ServoPIN 9      // محرك السيرفو
#define DHTPIN 13       // حساس الحرارة والرطوبة DHT22
#define DHTTYPE DHT22   // نوع الحساس
#define PotiPIN A0      // حساس رطوبة التربة (بوتينشوميتر)
#define WaterPumpLED 7  // LED الأزرق للمضخة

Servo Myservo;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  pinMode(Heater, OUTPUT);
  pinMode(RelayPIN, OUTPUT);
  pinMode(ServoPIN, OUTPUT);
  pinMode(DHTPIN, INPUT);
  pinMode(PotiPIN, INPUT);
  pinMode(WaterPumpLED, OUTPUT);

  dht.begin();
  Myservo.attach(ServoPIN);
  Myservo.write(0);
}

void loop() {
  float Temperature = dht.readTemperature();  // قراءة درجة الحرارة
  float humidity = dht.readHumidity(); // قراءة نسبة الرطوبة
  int soilMoisture = analogRead(PotiPIN);     // قراءة مستوى رطوبة التربة

  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.println(" *C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);

  if (Temperature >= 30)
    Myservo.write(90);
  else if (Temperature < 20)
    digitalWrite(Heater, HIGH);
  else {
    Myservo.write(0);
    digitalWrite(Heater, LOW);
  }
  
  if(humidity >= 50)
    Serial.println("Dear, the humidity is low");
  
  if (soilMoisture < 30) { // إذا كانت التربة جافة
    digitalWrite(RelayPIN, HIGH); // تشغيل المضخة
    digitalWrite(WaterPumpLED, HIGH); // تشغيل LED الأزرق
    delay(10000);  // تشغيل المضخة لمدة 10 ثوانٍ
    digitalWrite(RelayPIN, LOW);  // إيقاف المضخة
    digitalWrite(WaterPumpLED, LOW); // إيقاف LED الأزرق
  }

  delay(2000); // تأخير لقراءة البيانات كل 2 ثانية
}
