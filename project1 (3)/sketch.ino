const int yellowLedPin = 11;   // المنفذ المتصل بالـ LED الأصفر
const int blueLedPin = 10;    // المنفذ المتصل بالـ LED الأزرق

unsigned long previousMillisYellow = 0; // لحساب وقت تشغيل وإيقاف LED الأصفر
unsigned long previousMillisBlue = 0;   // لحساب وقت تشغيل وإيقاف LED الأزرق

const long intervalYellow = 1000; // وميض الـ LED الأصفر كل 1 ثانية
const long intervalBlue = 500;    // وميض الـ LED الأزرق كل 0.5 ثانية

bool yellowLedState = LOW; // الحالة الأولية لـ LED الأصفر
bool blueLedState = LOW;   // الحالة الأولية لـ LED الأزرق

void setup() {
  pinMode(yellowLedPin, OUTPUT); // ضبط الـ LED الأصفر كمخرج
  pinMode(blueLedPin, OUTPUT);   // ضبط الـ LED الأزرق كمخرج
}

void loop() {
  unsigned long currentMillis = millis(); // الحصول على الوقت الحالي

  // التحكم في LED الأصفر (يومض كل 1 ثانية)
  if (currentMillis - previousMillisYellow >= intervalYellow) {
    previousMillisYellow = currentMillis; // تحديث وقت آخر تغيير
    yellowLedState = !yellowLedState; // عكس حالة LED الأصفر
    digitalWrite(yellowLedPin, yellowLedState); // تشغيل أو إطفاء LED
  }

  // التحكم في LED الأزرق (يومض كل 0.5 ثانية)
  if (currentMillis - previousMillisBlue >= intervalBlue) {
    previousMillisBlue = currentMillis; // تحديث وقت آخر تغيير
    blueLedState = !blueLedState; // عكس حالة LED الأزرق
    digitalWrite(blueLedPin, blueLedState); // تشغيل أو إطفاء LED
  }
}
