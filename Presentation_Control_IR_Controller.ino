/***********************************************************
  Project 12: Ir Receiver and Controller
  Description: LCD1602 display's a Unique code when pressing each button on Remote
  Company: Texoham eLearning Platform
  Website: www.texoham.com/elearning
***********************************************************/

#include <Mouse.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include "IRremote.h"

#define UP 50174055
#define DOWN 50182215
const int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);
decode_results results;

int count = 0;
boolean startPpt = true ; 

void setup()
{
  irrecv.enableIRIn();
  Serial.begin(9600);
  Keyboard.begin();
  
}

void loop()
{
  if (irrecv.decode(&results))
  {
    irrecv.resume();                            // Receive the next value
    results.value;
    Serial.println(results.value);
    if ((results.value == 50174055) || (results.value == 33472575) ){
      Keyboard.write(KEY_DOWN_ARROW);
      Serial.println("Next Slide");
      count++;
      results.value = 0;
      Serial.print("Count:");
      Serial.println(count);
      delay(100);
    }
  }
  if ((results.value == 50182215) || ( results.value == 33439935 )) {
    Keyboard.write(KEY_UP_ARROW);
    Serial.println("Previous Slide");
    count--;
    Serial.print("Count:");
    Serial.println(count);
    results.value = 0 ;
    delay(100);
  }
  if (startPpt &&(( results.value == 50155695 )|| (results.value == 33456255 ))) {
    //This below lines works for Google Slides
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_F5);
    delay(50); 
    Keyboard.releaseAll();
        
    Serial.println("Start Presentation");
    startPpt = false;
    Serial.print("Count:");
    Serial.println(count);
    results.value = 0 ;
    delay(100);
  }
  else if((results.value == 50155695) || (results.value == 33456255 )){
    Keyboard.press(KEY_ESC);
    delay(50); 
    Keyboard.releaseAll();
    startPpt = true;
    Serial.println("Exit Presentation");
    results.value = 0 ;
    delay(100);
  }
}








/**

  // Modifiers
  #define KEY_LEFT_CTRL     0x80
  #define KEY_LEFT_SHIFT    0x81
  #define KEY_LEFT_ALT      0x82
  #define KEY_LEFT_GUI      0x83
  #define KEY_RIGHT_CTRL    0x84
  #define KEY_RIGHT_SHIFT   0x85
  #define KEY_RIGHT_ALT     0x86
  #define KEY_RIGHT_GUI     0x87

  // Misc keys
  #define KEY_UP_ARROW      0xDA
  #define KEY_DOWN_ARROW    0xD9
  #define KEY_LEFT_ARROW    0xD8
  #define KEY_RIGHT_ARROW   0xD7
  #define KEY_BACKSPACE     0xB2
  #define KEY_TAB           0xB3
  #define KEY_RETURN        0xB0
  #define KEY_MENU          0xED // "Keyboard Application" in USB standard
  #define KEY_ESC           0xB1
  #define KEY_INSERT        0xD1
  #define KEY_DELETE        0xD4
  #define KEY_PAGE_UP       0xD3
  #define KEY_PAGE_DOWN     0xD6
  #define KEY_HOME          0xD2
  #define KEY_END           0xD5
  #define KEY_CAPS_LOCK     0xC1
  #define KEY_PRINT_SCREEN  0xCE // Print Screen / SysRq
  #define KEY_SCROLL_LOCK   0xCF
  #define KEY_PAUSE         0xD0 // Pause / Break

  // Numeric keypad
  #define KEY_NUM_LOCK      0xDB
  #define KEY_KP_SLASH      0xDC
  #define KEY_KP_ASTERISK   0xDD
  #define KEY_KP_MINUS      0xDE
  #define KEY_KP_PLUS       0xDF
  #define KEY_KP_ENTER      0xE0
  #define KEY_KP_1          0xE1
  #define KEY_KP_2          0xE2
  #define KEY_KP_3          0xE3
  #define KEY_KP_4          0xE4
  #define KEY_KP_5          0xE5
  #define KEY_KP_6          0xE6
  #define KEY_KP_7          0xE7
  #define KEY_KP_8          0xE8
  #define KEY_KP_9          0xE9
  #define KEY_KP_0          0xEA
  #define KEY_KP_DOT        0xEB

  // Function keys
  #define KEY_F1            0xC2
  #define KEY_F2            0xC3
  #define KEY_F3            0xC4
  #define KEY_F4            0xC5
  #define KEY_F5            0xC6
  #define KEY_F6            0xC7
  #define KEY_F7            0xC8
  #define KEY_F8            0xC9
  #define KEY_F9            0xCA
  #define KEY_F10           0xCB
  #define KEY_F11           0xCC
  #define KEY_F12           0xCD
  #define KEY_F13           0xF0
  #define KEY_F14           0xF1
  #define KEY_F15           0xF2
  #define KEY_F16           0xF3
  #define KEY_F17           0xF4
  #define KEY_F18           0xF5
  #define KEY_F19           0xF6
  #define KEY_F20           0xF7
  #define KEY_F21           0xF8
  #define KEY_F22           0xF9
  #define KEY_F23           0xFA
  #define KEY_F24           0xFB



*/
