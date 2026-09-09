#include <EEPROM.h>

const int lines[] = {0, 1, 2, 3}; 

const int ledSequence[] = {
  0, 1,   1, 0,   0, 2,   2, 0,   0, 3,   3, 0,
  1, 2,   2, 1,   1, 3,   3, 1,   2, 3,   3, 2
};

const int grid[] = {
  0, 1, 2, 3,     
  4, 5, 6, 7,     
  8, 9, 10, 11    
};

const byte nameBanner[] = {
  0,0,0,0, 1,1,0,0, 1,0,1,0, 0,1,0,0, 1,0,0, 0,0,0,0, 0,0,0,0, 
  0,0,0,0, 1,1,0,0, 0,1,0,0, 1,1,1,0, 1,1,1, 0,0,0,0, 0,0,0,0, 
  0,0,0,0, 1,0,1,0, 0,1,0,0, 1,0,1,0, 1,0,1, 0,0,0,0, 0,0,0,0  
};

const int TEXT_WIDTH = 27; 
const int EEPROM_ADDRESS = 0; 
const int TOTAL_ANIMATIONS = 3; 
int currentAnimation = 0;

void allOff() {
  for (int i = 0; i < 4; i++) pinMode(lines[i], INPUT);
}

void lightPair(int a, int c) {
  allOff();
  pinMode(lines[a], OUTPUT); pinMode(lines[c], OUTPUT);
  digitalWrite(lines[a], HIGH); digitalWrite(lines[c], LOW);
}

void renderFrame(byte frame[], int frameDurationMs) {
  unsigned long start = millis();
  while (millis() - start < frameDurationMs) {
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 4; c++) {
        int frameIndex = (r * 4) + c;
        if (frame[frameIndex] == 1) {
          int ledIndex = grid[(r * 4) + c];
          lightPair(ledSequence[ledIndex * 2], ledSequence[(ledIndex * 2) + 1]);
          delayMicroseconds(300); 
        }
      }
    }
  }
  allOff(); 
}

void setup() {
  currentAnimation = EEPROM.read(EEPROM_ADDRESS);
  if (currentAnimation >= TOTAL_ANIMATIONS) currentAnimation = 0;
  
  int nextAnimation = (currentAnimation + 1) % TOTAL_ANIMATIONS;
  EEPROM.write(EEPROM_ADDRESS, nextAnimation);
}

void loop() {
  switch(currentAnimation) {
    case 0: animationChase(); break;
    case 1: animationBounce(); break;
    case 2: animationScrollName(); break; 
  }
}

// Animation 1
void animationChase() {
  for (int i = 0; i < 12; i++) {
    lightPair(ledSequence[i * 2], ledSequence[(i * 2) + 1]); 
    delay(255); 
  }
}

// Animation 2
void animationBounce() {
  unsigned long start = millis();
  while(millis() - start < 4000) { 
    for (int col = 0; col < 4; col++) runCol(col);
    for (int col = 2; col > 0; col--) runCol(col);
  }
}

void runCol(int c) {
  unsigned long s = millis();
  int colMap[] = {0,4,8, 1,5,9, 2,6,10, 3,7,11};
  while(millis() - s < 200) { 
    for(int i=0; i<3; i++) {
      int idx = colMap[(c * 3) + i];
      lightPair(ledSequence[idx * 2], ledSequence[(idx * 2) + 1]); 
      delayMicroseconds(400);
    }
  }
}

// Animation 3
void animationScrollName() {
  int scrollSpeed = 160; 
  byte workingWindow[12]; 

  for (int offset = 0; offset <= (TEXT_WIDTH - 4); offset++) {
    memset(workingWindow, 0, sizeof(workingWindow)); 
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 4; c++) {
        int bannerIndex = (r * TEXT_WIDTH) + (offset + c);
        workingWindow[(r * 4) + c] = nameBanner[bannerIndex];
      }
    }
    renderFrame(workingWindow, scrollSpeed);
  }
  allOff();
  delay(1200); 
}
