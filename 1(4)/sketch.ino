#define LED_PIN 8        // تحديد المنفذ المتصل بالـ LED
#define BUTTON_PIN 7     // تحديد المنفذ المتصل بالزر (Button)

byte lastButtonState = LOW;  // تخزين آخر حالة للزر (بدايةً يكون غير مضغوط)
byte ledState = LOW;         // تخزين حالة الـ LED (بدايةً يكون مطفأ)

unsigned long debounceDuration = 50; // تحديد مدة التخلص من الاهتزازات (50 مللي ثانية)
unsigned long lastTimeButtonStateChanged = 0; // تخزين آخر وقت تغيرت فيه حالة الزر

void setup() {
  pinMode(LED_PIN, OUTPUT);  // ضبط منفذ الـ LED كمخرج
  pinMode(BUTTON_PIN, INPUT); // ضبط منفذ الزر كمدخل
}

void loop() {
  // التحقق مما إذا كان الوقت المنقضي منذ آخر تغيير للحالة أكبر من وقت التخلص من الاهتزازات
  if (millis() - lastTimeButtonStateChanged > debounceDuration) { 
    byte buttonState = digitalRead(BUTTON_PIN); // قراءة حالة الزر (HIGH أو LOW)

    // التحقق مما إذا تغيرت حالة الزر مقارنةً بالحالة السابقة
    if (buttonState != lastButtonState) { 
      lastTimeButtonStateChanged = millis(); // تحديث وقت آخر تغيير للحالة
      lastButtonState = buttonState; // تحديث آخر حالة للزر

      // إذا كان الزر مضغوطًا (LOW)، قم بعكس حالة الـ LED
      if (buttonState == LOW) { 
        ledState = (ledState == HIGH) ? LOW : HIGH; // إذا كان مضيئًا، أطفئه، والعكس
        digitalWrite(LED_PIN, ledState); // تحديث حالة الـ LED (تشغيل أو إطفاء)
      }
    }
  }
}
