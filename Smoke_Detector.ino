// نظام أجينا الذكي لكشف الدخان v2.0
// تطوير: محمد التركي (أجينا)

const int smokePin = A0;   // مستشعر الدخان
const int buzzerPin = 9;  // الجرس
const int ledPin = 13;    // لمبة البيان (اختياري)
int threshold = 400;      // مستوى الحساسية

void setup() {
  pinMode(smokePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println(">>> نظام أجينا للأمان مستعد الآن <<<");
}

void loop() {
  int smokeLevel = analogRead(smokePin);
  Serial.print("مستوى الدخان: ");
  Serial.println(smokeLevel);

  if (smokeLevel > threshold) {
    // حالة الخطر
    Serial.println("⚠️ تحذير شديد! تم كشف دخان!");
    digitalWrite(ledPin, HIGH); 
    
    // إنذار متقطع (مزعج أكتر للتنبيه)
    for(int i=0; i<5; i++) {
      digitalWrite(buzzerPin, HIGH);
      delay(80);
      digitalWrite(buzzerPin, LOW);
      delay(80);
    }
  } else {
    // حالة الأمان
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  
  delay(500); // تحديث كل نصف ثانية
}
