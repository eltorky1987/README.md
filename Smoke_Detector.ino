/*
 * Project: Smart Smoke Detector
 * Author: Mahamed Eltorky
 * Platform: Arduino
 * Description: Detects smoke levels using MQ-2 sensor and triggers an alarm.
 */

// تعريف الأطراف (Pins)
const int sensorPin = A0;   // طرف مستشعر الدخان MQ-2
const int buzzerPin = 9;    // طرف الإنذار (Buzzer)
const int ledPin = 13;      // طرف الليد للتنبيه البصري

// حد التنبيه (Threshold)
int threshold = 400; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // لفتح شاشة المراقبة ومتابعة القراءات
  
  Serial.println("System Initializing...");
  delay(2000); // وقت تسخين المستشعر
}

void loop() {
  int sensorValue = analogRead(sensorPin); // قراءة القيمة التناظرية
  
  Serial.print("Smoke Level: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    // حالة الخطر: تشغيل الإنذار والليد
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println("⚠️ WARNING: Smoke Detected!");
  } else {
    // حالة الأمان: إيقاف الإنذار
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(500); // تأخير بسيط لاستقرار القراءات
}

