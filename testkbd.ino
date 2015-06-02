void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);

  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);


  Keyboard.begin();
  digitalWrite(19, HIGH);
  digitalWrite(20, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  
}
int ENDMATRIX = 99;
int FUNCTION = 77;
int EMPTY = 0;
int keyMap[5][20] = {
  {KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_MINUS, KEY_EQUAL, KEY_BACKSPACE, KEY_NUM_LOCK, KEYPAD_MINUS, KEYPAD_SLASH, KEYPAD_ASTERIX},
  {KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_ENTER, KEYPAD_7, KEYPAD_8, KEYPAD_9, KEYPAD_PLUS},
  {KEY_CAPS_LOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, FUNCTION, KEY_QUOTE, EMPTY, KEYPAD_4, KEYPAD_5, KEYPAD_6, KEYPAD_PLUS},
  {KEY_LEFT_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, EMPTY, EMPTY, KEY_RIGHT_SHIFT, KEYPAD_1, KEYPAD_2, KEYPAD_3, KEYPAD_ENTER},
  {KEY_LEFT_GUI, KEY_LEFT_ALT, KEY_TILDE, KEY_LEFT_CTRL, EMPTY, EMPTY, KEY_SPACE, EMPTY, KEY_BACKSLASH, KEY_LEFT, KEY_RIGHT, EMPTY, KEY_DOWN, KEY_UP, EMPTY, KEYPAD_0, KEYPAD_PERIOD}
};
int functionLayer[5][20] = {
  {KEY_TILDE, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_BACKSPACE, KEY_INSERT, KEY_HOME, KEY_PAGE_UP, KEYPAD_ASTERIX},
  {KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_ENTER, KEY_DELETE, KEY_END, KEY_PAGE_DOWN, KEYPAD_PLUS},
  {KEY_CAPS_LOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, EMPTY, KEY_QUOTE, EMPTY, KEYPAD_4, KEY_UP, KEYPAD_6, KEYPAD_PLUS},
  {KEY_LEFT_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, EMPTY, EMPTY, KEY_RIGHT_SHIFT, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEYPAD_ENTER},
  {KEY_LEFT_GUI, KEY_LEFT_ALT, EMPTY, KEY_LEFT_CTRL, EMPTY, EMPTY, KEY_SPACE, EMPTY, KEY_BACKSLASH, KEY_LEFT, KEY_RIGHT, EMPTY, KEY_DOWN, KEY_UP, EMPTY, KEYPAD_0, KEYPAD_PERIOD}
};
//Needed in order to know if you are going to release the button or not, modifer keys gets pushed and released when turning of power on output.
int lastDebounceTime[5][20] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int lastButtonState[5][20] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}
};
int buttonState[5][20] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}
};
int debounceDelay = 0; //mix with this if you get bad readings.
void loop() {
  //Delays are neccesarry for stability
  for (int i = 19; i < 24; i++) {
    digitalWriteFast(i, LOW);
    delay(1);
    for (int ii = 0; ii < 19; ii++) {
      if (ii == 13) { //Keeping pin 13 for LED
        continue;
      }
      int reading = digitalReadFast(ii);
      if (reading != lastButtonState[getRow(i)][getCol(ii)]) {
        lastDebounceTime[getRow(i)][getCol(ii)] = millis();
        lastButtonState[getRow(i)][getCol(ii)] = reading;
      }
      if ((millis() - lastDebounceTime[getRow(i)][getCol(ii)]) > debounceDelay) {
        if (reading != buttonState[getRow(i)][getCol(ii)]) {
          buttonState[getRow(i)][getCol(ii)] = reading;
          if (reading == LOW) {
            Serial.println("pushed");
            Serial.println(getRow(i)); //Debugging purposes
            Serial.println(getCol(ii));
            pressKey(getRow(i), getCol(ii));
            digitalWriteFast(i, HIGH);
            goto ENDMATRIX;
          }
          else {
            Serial.println("released");
            Serial.println(getRow(i)); //Debugging purposes
            Serial.println(getCol(ii));
            releaseKey(getRow(i), getCol(ii));
            digitalWriteFast(i, HIGH);
            goto ENDMATRIX;
          }
        }
      }
    }
    digitalWriteFast(i, HIGH);
  }
ENDMATRIX:;
}
int getRow(int port) {
  switch (port) {
    case 19:
      return 0;
    case 20:
      return 1;
    case 21:
      return 2;
    case 22:
      return 3;
    case 23:
      return 4;
  }
  return 100;
}

int getCol(int port) {
  switch (port) {
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 3;
    case 4:
      return 4;
    case 5:
      return 5;
    case 6:
      return 6;
    case 7:
      return 7;
    case 8:
      return 8;
    case 9:
      return 9;
    case 10:
      return 10;
    case 11:
      return 11;
    case 12:
      return 12;
    case 14:
      return 13;
    case 15:
      return 14;
    case 16:
      return 15;
    case 17:
      return 16;
    case 18:
      return 17;
  }
  return 100;
}
bool functionLayerActive = false;
void pressKey(int row, int col) {

  if (keyMap[row][col] == FUNCTION && !functionLayerActive) {
    functionLayerActive = true;
    //Serial.println("function layer actived");
  } else {
    if (functionLayerActive) {
      Keyboard.press(functionLayer[row][col]);
    } else {
      Keyboard.press(keyMap[row][col]);
    }
  }
}
void releaseKey(int row, int col) {

  if (keyMap[row][col] == FUNCTION && functionLayerActive) {
    functionLayerActive = false;
    //Serial.println("function layer deactived");
  } else {
    if (functionLayerActive) {
      Keyboard.release(functionLayer[row][col]);
    } else {
      Keyboard.release(keyMap[row][col]);
    }
  }
}
