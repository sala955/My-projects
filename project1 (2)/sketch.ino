const int IED = 12; // رقم المنفذ الذي يتصل به الـ LED

void setup() {
  pinMode(IED, OUTPUT); // ضبط المنفذ كمخرج
}

void loop() {
  digitalWrite(IED, HIGH); // تشغيل الـ LED
  delay(2000);                 // الانتظار لمدة 250 مللي ثانية
  digitalWrite(IED, LOW);  // إطفاء الـ LED
  delay(250);                 // الانتظار لمدة 250 مللي ثانية
}