#include <WiFi.h>
#include <HTTPClient.h>

// بيانات WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";  // شبكة Wokwi لا تحتاج إلى كلمة مرور

// بيانات ThingSpeak
String apiKey = "ESZKQFA3URME4FNN";  // استبدل بمفتاح API الخاص بك
const char* server = "http://api.thingspeak.com/update";

// تعريف مدخل LDR
#define LDR_PIN 34  // مستشعر الضوء متصل بـ GPIO34 (الخروج التماثلي AO)

void setup() {
  Serial.begin(115200);

  // الاتصال بشبكة WiFi
  WiFi.begin(ssid, password);
  Serial.print("🔄 جاري الاتصال بشبكة WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\n✅ متصل بنجاح!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    int lightIntensity = analogRead(LDR_PIN);  // قراءة شدة الإضاءة

    Serial.print("🌞 شدة الإضاءة: ");
    Serial.println(lightIntensity);

    sendDataToThingSpeak(lightIntensity);
  } else {
    Serial.println("❌ تم فقد الاتصال بشبكة WiFi!");
  }

  delay(15000);  // إرسال البيانات كل 15 ثانية
}

// دالة إرسال البيانات إلى ThingSpeak
void sendDataToThingSpeak(int light) {
  HTTPClient http;
  String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(light);

  http.begin(url);
  int httpCode = http.GET();
  
  if (httpCode > 0) {
    Serial.println("✅ تم إرسال البيانات بنجاح إلى ThingSpeak!");
  } else {
    Serial.println("❌ خطأ في الإرسال!");
  }
  
  http.end();
}
