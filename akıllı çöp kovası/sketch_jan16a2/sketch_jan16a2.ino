int Buzzer = D2;
int gaz_analog = A0;
int gaz_digital = D1;
int gazEşik = 500;

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  pinMode(gaz_digital, INPUT);
}

void loop() {
  int gazsensorAnalog = analogRead(gaz_analog);

  Serial.print("Gaz Sensor: ");
  Serial.print(gazsensorAnalog);
  Serial.print("\t");

  if (gazsensorAnalog > gazEşik) {
    Serial.println("Gaz Algılandı");
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer, LOW);
  } else {
    Serial.println("Gaz Yok");
  }
  delay(100);
}