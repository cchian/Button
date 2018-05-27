# Button
ไลบารีใช้ในการจัดการขา IO ของ Arduino ให้เป็น Switch Input<br>
This Library allow to Use the Arduino Digital IO Pin and ESP-32 Touch pin as a Button Switch.<br>


#include <Button.h><br>
<br>
#define SW1 T6 //pin D14 on ESP-32<br>
Button button(SW1, TOUCH);<br>
<br>
void click(int sender) {<br>
  Serial.println("Click pin " + String(sender));<br>
}<br>
<br>
// these event function not use in this sketch.<br>
void press(int sender) {<br>
  //Serial.println("Press pin "+String(sender));<br>
}<br>
void doubleClick(int sender) {<br>
  //Serial.println("Double Click pin "+String(sender));<br>
}<br>
void hold(int sender) {<br>
  //Serial.println("Hold pin "+String(sender));<br>
}<br>
void longHold(int sender) {<br>
  //Serial.println("Long Hold pin "+String(sender));<br>
}<br>
<br>
void setup() {<br>
  Serial.begin(115200);<br>
 <br>
  button.eventPress((void*)press);<br>
  button.eventClick((void*)click);<br>
  button.eventDoubleClick((void*)doubleClick);<br>
  button.eventHold((void*)hold);<br>
  button.eventLongHold((void*)longHold);<br>
<br>
}<br>
<br>
void loop() {<br>
  button.handleButton();<br>
  //delay(20);<br>
}<br>
