# Button
<pre>ไลบารีใช้ในการจัดการขา IO ของ Arduino ให้เป็น Switch Input<br>
This library allows you to use GPIO pins of Arduino, ESP32, 
and ESP8266 (including touch pins for ESP32) as buttons or switches. It is easy to use.<br>
<pre/>
<br>
Support the following Event-Driven
 -Press
 -Click
 -DoubleClick
 -Hold (long press)
 -LongHold (more than LongPress)<hr>
 picture from
 <p align="center">
  <img src="https://commandronestore.com/learning/learning_img/preview_img/arduino0000/arduino002_1.png
" width="350" title="hover text">
  <img src="https://commandronestore.com/learning/learning_img/preview_img/arduino0000/arduino002_1.png
" width="350" alt="accessibility text">
</p>
 
<font color="#434f54">&#47;&#47; &nbsp;Change Arduino editor font to &#34;Courier New&#34; for specify correct ESP32 image below.</font>
<font color="#434f54">&#47;&#47; &nbsp;1.Click the link at the line following File &gt; Preferences &gt; More preferences can be edited directly in the file.</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;This will open the .Arduino15 (or something like that) folder.</font>
<font color="#434f54">&#47;&#47; &nbsp;2.Exit the Arduino IDE</font>
<font color="#434f54">&#47;&#47; &nbsp;3.Open the file preferences.txt in a text editor.</font>
<font color="#434f54">&#47;&#47; &nbsp;4.Search for the line that starts with &#34;editor.font&#34;.</font>
<font color="#434f54">&#47;&#47; &nbsp;5.Change the first word following the equals sign on that line to the &#34;Courier New&#34;.</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;like this &#34;editor.font=Courier New,plain,11&#34;</font>
<font color="#434f54">&#47;&#47; &nbsp;6.Save the file.</font>
<font color="#434f54">&#47;&#47; &nbsp;7.Start the Arduino IDE. The editor should now be using the font you chose.</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;┌─────────────────────────────┐</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;┌───┐ &nbsp;&nbsp;┌───┐ &nbsp;&nbsp;┌───┬───┐ &nbsp;│</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;│</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;│ &nbsp;&nbsp;└───┘ &nbsp;&nbsp;└───┘ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;│</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;│</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│┌───────────────────────────┐│</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GND &nbsp;1-▓┤│ º &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│├▓-38 GND</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;VCC &nbsp;2-▓┤│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-37 GPIO23</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;! &nbsp;&nbsp;&nbsp;&nbsp;EN &nbsp;3-▓┤│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-36 GPIO22 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SCL</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC_H ADC1_0 SensVP GPI36 &nbsp;&nbsp;4-▓┤│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-35 GPIO1 &nbsp;TX0 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CLK03</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC_H ADC1_3 SensVN GPI39 &nbsp;&nbsp;5-▓┤│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-34 GPIO3 &nbsp;RX0 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CLK02</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC1_6 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GPI34 &nbsp;&nbsp;6-▓┤│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-33 GPIO21 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDA</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC1_7 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GPI35 &nbsp;&nbsp;7-▓┤│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ESP32 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-32 GPIO20</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;XTAL32 ADC1_4 &nbsp;&nbsp;&nbsp;&nbsp;T9 GPO32 &nbsp;&nbsp;8-▓┤░ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-31 GPIO19</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;XTAL32 ADC1_5 &nbsp;&nbsp;&nbsp;&nbsp;T8 GPO33 &nbsp;&nbsp;9-▓┤░ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-30 GPIO18</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC2_8 &nbsp;DAC_1 GPIO25 10-▓┤░ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-29 GPIO5</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC2_9 &nbsp;DAC_2 GPIO26 11-▓┤░ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-28 GPIO17 TX1</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC2_7 &nbsp;&nbsp;&nbsp;&nbsp;T7 GPIO27 12-▓┤░ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-27 GPIO16 RX1</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC2_6 &nbsp;&nbsp;&nbsp;&nbsp;T6 GPIO14 13-▓┤░ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░├▓-26 GPIO4 &nbsp;T0 &nbsp;ADC2_0</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC2_5 &nbsp;&nbsp;&nbsp;&nbsp;T5 GPIO12 14-▓┤░──────░░░░░░░░░░░░░░░░░────░├▓-25 GPIO0 &nbsp;T1 &nbsp;ADC2_1 CLK01</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└─────▓─▓─▓─▓─▓─▓─▓─▓─▓─▓─────┘</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GND 15────────┘ │ │ │ │ │ │ │ │ └────────24 GPIO2 &nbsp;T2 &nbsp;ADC2_2</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ADC2_4 &nbsp;&nbsp;&nbsp;&nbsp;T4 GPIO13 16──────────┘ │ │ │ │ │ │ └──────────23 GPIO15 T3 &nbsp;ADC2_3</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SD_D2 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GPIO9 17────────────┘ │ │ │ │ └────────────22 GPIO8 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SD_D1</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SD_D3 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GPIO10 18──────────────┘ │ │ └──────────────21 GPIO7 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SD_D0</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SD_CMD &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GPIO11 19────────────────┘ └────────────────20 GPIO6 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SD_CLK</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;░ &nbsp;&nbsp;&nbsp;PWM Pin</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1-38 Physical pin on package</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Absolute MAX per pin 12mA, recommended 6mA</font>
<font color="#434f54">&#47;&#47; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;VCC = 3.3V</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47;</font>
<font color="#434f54">&#47;&#47;</font>


<font color="#434f54">&#47;&#47;this library tested and Its work! for Arduino, ESP32, ESP8266</font>
<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">Button</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font>
<font color="#434f54">&#47;&#47;declare button obj use pin 2, DIO as default pinType and HIGH Active state</font>
<font color="#434f54">&#47;&#47;the following ESP32 pins work with INPUT_PULLUP: 14, 16, 17, 18, 19, 21, 22, 23</font>
<b><font color="#d35400">Button</font></b> <font color="#000000">button</font><font color="#000000">(</font><font color="#000000">2</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#434f54">&#47;&#47;same as below</font>
<font color="#434f54">&#47;&#47;Button button(2,DIO,LOW);</font>

<font color="#00979c">void</font> <font color="#d35400">press</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Press pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#d35400">release</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Release pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#d35400">click</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Click pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">doubleClick</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Double Click pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">hold</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Hold pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">longHold</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Long Hold pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>

<font color="#00979c">void</font> <font color="#5e6d03">setup</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#434f54">&#47;&#47; put your setup code here, to run once:</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">115200</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#434f54">&#47;&#47;set callback function for Button</font>
<font color="#5e6d03">#if</font> <font color="#000000">defined</font><font color="#000000">(</font><b><font color="#d35400">ESP32</font></b><font color="#000000">)</font> <font color="#434f54">||</font> <font color="#000000">defined</font><font color="#000000">(</font><font color="#000000">ESP8266</font><font color="#000000">)</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventPress</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#d35400">press</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventRelease</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#d35400">release</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventClick</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#d35400">click</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventDoubleClick</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#000000">doubleClick</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventHold</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#000000">hold</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventLongHold</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#000000">longHold</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#5e6d03">#else</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventPress</font><font color="#000000">(</font><font color="#d35400">press</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventRelease</font><font color="#000000">(</font><font color="#d35400">release</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventClick</font><font color="#000000">(</font><font color="#d35400">click</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventDoubleClick</font><font color="#000000">(</font><font color="#000000">doubleClick</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventHold</font><font color="#000000">(</font><font color="#000000">hold</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventLongHold</font><font color="#000000">(</font><font color="#000000">longHold</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#5e6d03">#endif</font>
 &nbsp;<font color="#95a5a6">&#47;*set time for event with milliseconds</font>
<font color="#95a5a6"> &nbsp;&nbsp;&nbsp;button.setDoubleClickTime(250);</font>
<font color="#95a5a6"> &nbsp;&nbsp;&nbsp;button.setHoldTime(2000);</font>
<font color="#95a5a6"> &nbsp;&nbsp;&nbsp;button.setLongHoldTime(5000);</font>
<font color="#95a5a6"> &nbsp;*&#47;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#5e6d03">loop</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#95a5a6">&#47;*handle button action*&#47;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">handleButton</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>

 &nbsp;<font color="#434f54">&#47;&#47; put your main code here, to run repeatedly:</font>
<font color="#000000">}</font>
</pre>

