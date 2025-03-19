const int buttonPin = 2;  // زر التبديل
const int ledPin = 13;     // الليد

bool ledState = LOW;  // حالة الليد الأولية
bool lastButtonState = HIGH; // حالة الزر السابقة
bool currentButtonState;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // تفعيل المقاومة الداخلية للزر
  pinMode(ledPin, OUTPUT);          // ضبط الليد كمخرج
}

void loop() {
  currentButtonState = digitalRead(buttonPin); // قراءة حالة الزر

  // التحقق من الضغط (انتقال من HIGH إلى LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledState = !ledState;             // تبديل حالة الليد
    digitalWrite(ledPin, ledState);   // تشغيل أو إطفاء الليد
  }

  lastButtonState = currentButtonState; // حفظ الحالة الأخيرة للزر
}