const int lines[4] = {0, 1, 2, 3};

void allOff() {
  for (int i = 0; i < 4; i++) pinMode(lines[i], INPUT);
}

void lightPair(int a, int c) {
  allOff();
  pinMode(lines[a], OUTPUT);
  pinMode(lines[c], OUTPUT);
  digitalWrite(lines[a], HIGH);
  digitalWrite(lines[c], LOW);
}

void scanAll(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    for (int a = 0; a < 4; a++) {
      for (int c = 0; c < 4; c++) {
        if (a == c) continue;
        lightPair(a, c);
        delayMicroseconds(500);
      }
    }
  }
  allOff();
}

void setup() {
}

void loop() {
  scanAll(1000);
  delay(1000);
}
