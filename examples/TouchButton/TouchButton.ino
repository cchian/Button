#ifdef ESP32
#include <Button.h>

//declare button obj use T2 touch pin map to GPIO2 on ESP32
Button button(T2,TOUCH);

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
  button.eventPress((void*)press);
  button.eventClick((void*)click);
  button.eventDoubleClick((void*)doubleClick);
  button.eventHold((void*)hold);
  button.eventLongHold((void*)longHold);

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
#else
	#error support for ESP32 only.
#endif


