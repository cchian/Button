#include <Button.h>

//declare button obj use pin 2, DIO as default pinType
Button button(2);
//same as below
//Button button(2,DIO);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
#if defined(ESP32) || defined(ESP8266)
  button.eventClick((void*)clicked);
#else
  button.eventClick(clicked);
#endif
  pinMode(3, OUTPUT);
}
void clicked() {
  if (button.Checked) {
    Serial.println("Button Checked");
    digitalWrite(3, HIGH);
    button.Checked = false;

  } else {
    Serial.println("Button UnChecked");
    digitalWrite(3, LOW);
    button.Checked = true;
  }
}
void loop() {
  button.handleButton();
  // put your main code here, to run repeatedly:

}
