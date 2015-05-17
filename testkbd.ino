

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  
  pinMode(19,OUTPUT);
  pinMode(20,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  
  
  Keyboard.begin();
  digitalWrite(19,LOW);
  digitalWrite(20,LOW);
  digitalWrite(21,LOW);
  digitalWrite(22,LOW);
  digitalWrite(23,LOW);
}
int FUNCTION = 77;
int EMPTY=0;
int keyMap[5][20]={
  {KEY_ESC,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_0,KEY_MINUS,KEY_EQUAL,KEY_BACKSPACE,KEY_NUM_LOCK,KEYPAD_MINUS,KEYPAD_SLASH,KEYPAD_ASTERIX},
  {KEY_TAB,KEY_Q,KEY_W,KEY_E,KEY_R,KEY_T,KEY_Y,KEY_U,KEY_I,KEY_O,KEY_P,KEY_LEFT_BRACE,KEY_RIGHT_BRACE,KEY_ENTER,KEYPAD_7,KEYPAD_8,KEYPAD_9,KEYPAD_PLUS},
  {KEY_CAPS_LOCK,KEY_A,KEY_S,KEY_D,KEY_F,KEY_G,KEY_H,KEY_J,KEY_K,KEY_L,KEY_SEMICOLON,FUNCTION,KEY_QUOTE,EMPTY,KEYPAD_4,KEYPAD_5,KEYPAD_6,KEYPAD_PLUS},
  {KEY_LEFT_SHIFT,KEY_Z,KEY_X,KEY_C,KEY_V,KEY_B,KEY_N,KEY_M,KEY_COMMA,KEY_PERIOD,KEY_SLASH,EMPTY,EMPTY,KEY_RIGHT_SHIFT,KEYPAD_1,KEYPAD_2,KEYPAD_3,KEYPAD_ENTER},
  {KEY_LEFT_GUI,KEY_LEFT_ALT,FUNCTION,KEY_LEFT_CTRL,EMPTY,EMPTY,KEY_SPACE,EMPTY,KEY_BACKSLASH,KEY_LEFT,KEY_RIGHT,EMPTY,KEY_DOWN,KEY_UP,EMPTY,KEYPAD_0,KEYPAD_PERIOD}                         
};
//Needed in order to know if you are going to release the button or not, modifer keys gets pushed and released when turning of power on output.
int previous[5][20]={
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}                         
};

void loop() {
  //Delays are neccesarry for stability
  delay(15);
  writePort(23,4);
  delay(15);
  writePort(21,2);
  delay(15);
  writePort(19,0);
  delay(15);
  writePort(22,3);
  delay(15);
  writePort(20,1);
  
  
}
void writePort(int port, int y){
  digitalWrite(port,LOW);
  readInputPort(0,y,0,port);
  readInputPort(1,y,1,port);
  readInputPort(2,y,2,port);
  readInputPort(3,y,3,port);
  readInputPort(4,y,4,port);
  readInputPort(5,y,5,port);
  readInputPort(6,y,6,port);
  readInputPort(7,y,7,port);
  readInputPort(8,y,8,port);
  readInputPort(9,y,9,port);
  readInputPort(10,y,10,port);
  readInputPort(11,y,11,port);
  readInputPort(12,y,12,port);
  readInputPort(14,y,13,port);
  readInputPort(15,y,14,port);
  readInputPort(16,y,15,port);
  readInputPort(17,y,16,port);
  readInputPort(18,y,17,port);
  digitalWrite(port,HIGH);
}
//Simply checking what the value is now, and what it was before
void readInputPort(int port, int y,int x, int outputPort){
  if(digitalRead(port) == LOW){
    if( previous[y][x] == HIGH){
      Keyboard.press(keyMap[y][x]);
      previous[y][x] = LOW;
    }
  }else if(digitalRead(port) == HIGH && previous[y][x] == LOW){
      Keyboard.release(keyMap[y][x]);
      previous[y][x] = HIGH; 
    }
}
