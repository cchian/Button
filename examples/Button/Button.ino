#include "Button.h"

//declare button obj use pin 30
Button button(2);

void press(int sender) {
  Serial.println("Press pin "+String(sender));
}
void click(int sender) {
  Serial.println("Click pin "+String(sender));
}
void doubleClick(int sender) {
  Serial.println("Double Click pin "+String(sender));
}
void hold(int sender) {
  Serial.println("Hold pin "+String(sender));
}
void longHold(int sender) {
  Serial.println("Long Hold pin "+String(sender));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //set callback function for Button
  button.eventPress(press);
  button.eventClick(click);
  button.eventDoubleClick(doubleClick);
  button.eventHold(hold);
  button.eventLongHold(longHold);

  /*set time for event with milliseconds
  button.setDoubleClickTime(250);
  button.setHoldTime(2000);
  button.setLongHoldTime(5000);
 */
}
void loop() {
  /*handle button action*/
  button.handleButton();
  
  // put your main code here, to run repeatedly:
}



