// تعريف متغيرات لتخزين آخر وقت تم فيه تغيير حالة كل مصباح LED
unsigned long previousMillisRed = 0;
unsigned long previousMillisGreen = 0;

// تعريف الفاصل الزمني لتغيير حالة كل مصباح LED (بالميلي ثانية)
const int intervalRed = 250;  // المصباح الأحمر يومض كل 250ms
const int intervalGreen = 500; // المصباح الأخضر يومض كل 500ms

// تعريف متغيرات لتخزين الحالة الحالية لكل مصباح (مضاءة أو مطفأة)
bool redState = HIGH;  // يبدأ المصباح الأحمر بحالة التشغيل (HIGH)
bool greenState = HIGH; // يبدأ المصباح الأخضر بحالة التشغيل (HIGH)

void setup() {
  pinMode(11, OUTPUT); // تعيين المنفذ 11 كمخرج للتحكم بالمصباح الأحمر
  pinMode(10, OUTPUT); // تعيين المنفذ 10 كمخرج للتحكم بالمصباح الأخضر
}

void loop() {
  // قراءة الوقت الحالي منذ تشغيل المتحكم
  unsigned long currentMillis = millis();

  // التحقق مما إذا كان الوقت المنقضي منذ آخر تغيير أكبر من أو يساوي الفاصل الزمني للمصباح الأحمر
  if (currentMillis - previousMillisRed >= intervalRed) {
    previousMillisRed = currentMillis; // تحديث آخر وقت تغيير للمصباح الأحمر
    redState = !redState;  // عكس حالة المصباح (HIGH يصبح LOW والعكس)
    digitalWrite(11, redState); // تطبيق الحالة الجديدة على المنفذ 11
  }

  // التحقق مما إذا كان الوقت المنقضي منذ آخر تغيير أكبر من أو يساوي الفاصل الزمني للمصباح الأخضر
  if (currentMillis - previousMillisGreen >= intervalGreen) {
    previousMillisGreen = currentMillis; // تحديث آخر وقت تغيير للمصباح الأخضر
    greenState = !greenState;  // عكس حالة المصباح (HIGH يصبح LOW والعكس)
    digitalWrite(10, greenState); // تطبيق الحالة الجديدة على المنفذ 10
  }
}