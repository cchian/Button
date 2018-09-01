#include <Button.h>

//declare button obj use pin 2, DIO as default pinType
Button button(2);
//same as below
//Button button(2,DIO);

void press(int sender) {
  Serial.println("Press pin " + String(sender));
}
void release(int sender) {
  Serial.println("Release pin " + String(sender));
}
void click(int sender) {
  Serial.println("Click pin " + String(sender));
}
void doubleClick(int sender) {
  Serial.println("Double Click pin " + String(sender));
}
void hold(int sender) {
  Serial.println("Hold pin " + String(sender));
}
void longHold(int sender) {
  Serial.println("Long Hold pin " + String(sender));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //set callback function for Button
#if defined(ESP32) || defined(ESP8266)
  button.eventPress((void*)press);
  button.eventRelease((void*)release);
  button.eventClick((void*)click);
  button.eventDoubleClick((void*)doubleClick);
  button.eventHold((void*)hold);
  button.eventLongHold((void*)longHold);
#else
  button.eventPress(press);
  button.eventRelease(release);
  button.eventClick(click);
  button.eventDoubleClick(doubleClick);
  button.eventHold(hold);
  button.eventLongHold(longHold);
#endif
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


