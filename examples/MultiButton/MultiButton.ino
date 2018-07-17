#include <Button.h>

Button button1(2);
Button button2(3);
Button button3(4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
#if defined(ESP32) || defined(ESP8266)
  button1.eventClick((void*)clicked);
  button2.eventClick((void*)clicked);
  button3.eventClick((void*)clicked);
#else
  button1.eventClick(clicked);
  button2.eventClick(clicked);
  button3.eventClick(clicked);
#endif
}
void clicked(int sender) {
  Serial.println("Button Pin:" + String(sender) + " Clicked");
}
void loop() {
  handleButton();
  // put your main code here, to run repeatedly:

}
void handleButton() {
  button1.handleButton();
  button2.handleButton();
  button3.handleButton();
}

