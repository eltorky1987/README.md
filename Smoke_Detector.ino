// Agina Smart Smoke Detector v2.0
// Developed by: Mahamed Torky (Agina)

const int smokePin = A0;   
const int buzzerPin = 9;  
const int ledPin = 13;    
int threshold = 400;      

void setup() {
  pinMode(smokePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println(">>> Agina Security System Ready <<<");
}

void loop() {
  int smokeLevel = analogRead(smokePin);
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  if (smokeLevel > threshold) {
    digitalWrite(ledPin, HIGH); 
    for(int i=0; i<5; i++) {
      digitalWrite(buzzerPin, HIGH);
      delay(80);
      digitalWrite(buzzerPin, LOW);
      delay(80);
    }
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  delay(500); 
}
