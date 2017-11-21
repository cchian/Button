#include"Button.h"

Button button(2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  button.eventClick(clicked);
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
