# Button
ไลบารีใช้ในการจัดการขา IO ของ Arduino ให้เป็น Switch Input<br>
This Library allow to Use the Arduino Digital IO Pin and ESP-32 Touch pin as a Button Switch.<br>


<pre>
<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">Button</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font>

<font color="#5e6d03">#define</font> <font color="#000000">SW1</font> <font color="#000000">T6</font> <font color="#434f54">&#47;&#47;pin D14 on ESP-32</font>
<b><font color="#d35400">Button</font></b> <font color="#000000">button</font><font color="#000000">(</font><font color="#000000">SW1</font><font color="#434f54">,</font> <font color="#000000">TOUCH</font><font color="#000000">)</font><font color="#000000">;</font>

<font color="#00979c">void</font> <font color="#d35400">click</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#005c5f">&#34;Click pin &#34;</font> <font color="#434f54">+</font> <font color="#00979c">String</font><font color="#000000">(</font><font color="#000000">sender</font><font color="#000000">)</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>

<font color="#434f54">&#47;&#47; these event function not use in this sketch.</font>
<font color="#00979c">void</font> <font color="#d35400">press</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#434f54">&#47;&#47;Serial.println(&#34;Press pin &#34;+String(sender));</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">doubleClick</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#434f54">&#47;&#47;Serial.println(&#34;Double Click pin &#34;+String(sender));</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">hold</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#434f54">&#47;&#47;Serial.println(&#34;Hold pin &#34;+String(sender));</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">longHold</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">sender</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#434f54">&#47;&#47;Serial.println(&#34;Long Hold pin &#34;+String(sender));</font>
<font color="#000000">}</font>

<font color="#00979c">void</font> <font color="#5e6d03">setup</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">115200</font><font color="#000000">)</font><font color="#000000">;</font>

 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventPress</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#d35400">press</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventClick</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#d35400">click</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventDoubleClick</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#000000">doubleClick</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventHold</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#000000">hold</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">eventLongHold</font><font color="#000000">(</font><font color="#000000">(</font><font color="#00979c">void</font><font color="#434f54">*</font><font color="#000000">)</font><font color="#000000">longHold</font><font color="#000000">)</font><font color="#000000">;</font>

<font color="#000000">}</font>

<font color="#00979c">void</font> <font color="#5e6d03">loop</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#000000">button</font><font color="#434f54">.</font><font color="#000000">handleButton</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#434f54">&#47;&#47;delay(20);</font>
<font color="#000000">}</font>

</pre>
