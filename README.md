# Arduino-Laser-Cut-Sumo-Robot

This is a project I am currently developing to help me win a sumo robot competition. This robot should weigh when completed under 750 grams which is perfect for the competition I am participating in since the limit is exactly that. The robot has five sensors. Two ir sensor switches to detect the edge of the arena and the arena itself. Then three ultrasound sensors on three sides of the robot to see if anything is nearby. These sensors are located on the left, right, and front of the robot. This is the robot assembly. 

<img src="sumo 1.PNG"
     alt="Sumo Robot Assembled"
     style="float: left; margin-right: 10px;" />
     
<img src="sumo 2.PNG"
     alt="Sumo Robot Exploded"
     style="float: left; margin-right: 10px;" />
     
<a href="https://www.dropbox.com/home?preview=File+from+iOS+(33).MOV">Video</a>
     
# BOM
<a href="https://www.pololu.com/product/1119">2 Pololu Motors</a>

Arduino Nano GPIO Shield

Arduino Nano

L298n Motor Driver

2 Side Panels

1 Front panel

1 back panel

1 bottom panel

2 Motor Mounts

1 Top panel

Toggle Switch

M3 Nuts and Bolts


# Code

<pre>
<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">NewPing</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">left_forward</font> <font color="#434f54">=</font> <font color="#000000">A3</font><font color="#000000">;</font><font color="#434f54">&#47;&#47;while high moves left motor forward</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">left_backward</font> <font color="#434f54">=</font> <font color="#000000">A2</font><font color="#000000">;</font><font color="#434f54">&#47;&#47;while high moves left motor backward</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">right_forward</font> <font color="#434f54">=</font> <font color="#000000">A4</font><font color="#000000">;</font><font color="#434f54">&#47;&#47;while high moves right motor forward</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">right_backward</font> <font color="#434f54">=</font> <font color="#000000">A5</font><font color="#000000">;</font><font color="#434f54">&#47;&#47;while high moves right motor backward</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">left_side</font> <font color="#434f54">=</font> <font color="#000000">13</font><font color="#000000">;</font><font color="#434f54">&#47;&#47;left edge sensor</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">right_side</font> <font color="#434f54">=</font> <font color="#000000">12</font><font color="#000000">;</font><font color="#434f54">&#47;&#47;right edge sensor</font>
<b><font color="#d35400">NewPing</font></b> <font color="#000000">Sonar</font><font color="#000000">(</font><font color="#000000">8</font><font color="#434f54">,</font><font color="#000000">9</font><font color="#434f54">,</font> <font color="#000000">60</font><font color="#000000">)</font><font color="#000000">;</font>
<b><font color="#d35400">NewPing</font></b> <font color="#000000">Left_Sonar</font><font color="#000000">(</font><font color="#000000">11</font><font color="#434f54">,</font><font color="#000000">10</font><font color="#434f54">,</font> <font color="#000000">60</font><font color="#000000">)</font><font color="#000000">;</font>
<b><font color="#d35400">NewPing</font></b> <font color="#000000">Right_Sonar</font><font color="#000000">(</font><font color="#000000">6</font><font color="#434f54">,</font> <font color="#000000">5</font><font color="#434f54">,</font> <font color="#000000">60</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#00979c">void</font> <font color="#5e6d03">setup</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#434f54">&#47;&#47; put your setup code here, to run once:</font>
 &nbsp;<font color="#434f54">&#47;&#47;Pin setup is declared here.</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">left_forward</font><font color="#434f54">,</font> <font color="#00979c">OUTPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">left_backward</font><font color="#434f54">,</font> <font color="#00979c">OUTPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">right_forward</font><font color="#434f54">,</font> <font color="#00979c">OUTPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">right_backward</font><font color="#434f54">,</font> <font color="#00979c">OUTPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">left_side</font><font color="#434f54">,</font> <font color="#00979c">INPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">right_side</font><font color="#434f54">,</font> <font color="#00979c">INPUT</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">9600</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<font color="#000000">Stop</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font><font color="#434f54">&#47;&#47; Robot stops after starting as stated in the rules.</font>
 &nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">4000</font><font color="#000000">)</font><font color="#000000">;</font><font color="#434f54">&#47;&#47; Robot gives you time to clear the area. Only 5 seconds though. </font>
<font color="#000000">}</font>
<font color="#00979c">bool</font> <font color="#000000">invert</font> <font color="#434f54">=</font> <font color="#00979c">false</font><font color="#000000">;</font><font color="#434f54">&#47;&#47; Direction invert when not in obstacle mode.</font>
<font color="#00979c">bool</font> <font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">true</font><font color="#000000">;</font><font color="#434f54">&#47;&#47; Obstacle mode is declared true by default until an edge is reached where it is inverted from there.</font>
<font color="#00979c">int</font> <font color="#000000">duration</font> <font color="#434f54">=</font> <font color="#000000">300</font><font color="#000000">;</font><font color="#434f54">&#47;&#47; Duration of the robots scan for other nearby robots is decalred here.</font>
<font color="#00979c">void</font> <font color="#5e6d03">loop</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;<font color="#00979c">int</font> &nbsp;<font color="#000000">dist</font><font color="#000000">;</font><font color="#434f54">&#47;&#47; Sonar.ping_cm() is this variables near equivilent.</font>
 &nbsp;<font color="#434f54">&#47;&#47; put your main code here, to run repeatedly:</font>
 &nbsp;
 &nbsp;<font color="#434f54">&#47;&#47;If the robot is in the near center of the arena and obstacle mode is true the robot moves forward.</font>
 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">right_side</font><font color="#000000">)</font> <font color="#434f54">==</font> <font color="#00979c">HIGH</font> <font color="#434f54">&amp;&amp;</font> <font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">left_side</font><font color="#000000">)</font> <font color="#434f54">==</font> <font color="#00979c">HIGH</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">obstacle_mode</font> <font color="#434f54">==</font> <font color="#00979c">true</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">forward</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#434f54">&#47;&#47;If robot sees something on either of its sides scan towards it. </font>
 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">obstacle_mode</font> <font color="#434f54">==</font> <font color="#00979c">true</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">Left_Sonar</font><font color="#434f54">.</font><font color="#d35400">ping_cm</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#434f54">&lt;=</font> <font color="#000000">60</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">Left_Sonar</font><font color="#434f54">.</font><font color="#d35400">ping_cm</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#434f54">!=</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">invert</font> <font color="#434f54">=</font> <font color="#00979c">false</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">false</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">obstacle_mode</font> <font color="#434f54">==</font> <font color="#00979c">true</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">Right_Sonar</font><font color="#434f54">.</font><font color="#d35400">ping_cm</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#434f54">&lt;=</font> <font color="#000000">60</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">Right_Sonar</font><font color="#434f54">.</font><font color="#d35400">ping_cm</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#434f54">!=</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">invert</font> <font color="#434f54">=</font> <font color="#00979c">true</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">false</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#434f54">&#47;&#47;If the robot is on an edge of the arena obstacle mode is inverted, the robot moves backwards, and then turns left.</font>
 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">right_side</font><font color="#000000">)</font> <font color="#434f54">==</font> <font color="#00979c">LOW</font> <font color="#434f54">||</font> <font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">left_side</font><font color="#000000">)</font> <font color="#434f54">==</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">backward</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">obstacle_mode</font> <font color="#434f54">==</font> <font color="#00979c">false</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">true</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">else</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">false</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#434f54">&#47;&#47;if obstacle mode is false robot scans the arena for another bot. The duration of the scan is defined above the loop. </font>
 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">obstacle_mode</font> <font color="#434f54">==</font> <font color="#00979c">false</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">invert</font> <font color="#434f54">==</font> <font color="#00979c">false</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">Left</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">25</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">Stop</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">50</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">duration</font> <font color="#434f54">-=</font> <font color="#000000">1</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">dist</font><font color="#434f54">=</font> <font color="#000000">Sonar</font><font color="#434f54">.</font><font color="#d35400">ping_cm</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#000000">dist</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">dist</font> <font color="#434f54">&lt;=</font> <font color="#000000">30</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">dist</font> <font color="#434f54">!=</font> <font color="#000000">0</font> <font color="#434f54">||</font> <font color="#000000">duration</font> <font color="#434f54">&lt;=</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">{</font><font color="#434f54">&#47;&#47;if the scan turns up something obstacle mode becomes true and the robot will run over the other bot. </font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">duration</font> <font color="#434f54">=</font> <font color="#000000">300</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">true</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#434f54">&#47;&#47;if obstacle mode is false robot scans the arena for another bot. The duration of the scan is defined above the loop. </font>
 &nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">obstacle_mode</font> <font color="#434f54">==</font> <font color="#00979c">false</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">invert</font> <font color="#434f54">==</font> <font color="#00979c">true</font><font color="#000000">)</font><font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">Right</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">25</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">Stop</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">50</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">duration</font> <font color="#434f54">-=</font> <font color="#000000">1</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">dist</font><font color="#434f54">=</font> <font color="#000000">Sonar</font><font color="#434f54">.</font><font color="#d35400">ping_cm</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">println</font><font color="#000000">(</font><font color="#000000">dist</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font> <font color="#000000">(</font><font color="#000000">dist</font> <font color="#434f54">&lt;=</font> <font color="#000000">30</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">dist</font> <font color="#434f54">!=</font> <font color="#000000">0</font> <font color="#434f54">||</font> <font color="#000000">duration</font> <font color="#434f54">&lt;=</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">{</font><font color="#434f54">&#47;&#47;if the scan turns up something obstacle mode becomes true and the robot will run over the other bot. </font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">duration</font> <font color="#434f54">=</font> <font color="#000000">300</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#000000">obstacle_mode</font> <font color="#434f54">=</font> <font color="#00979c">true</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font>
 &nbsp;<font color="#000000">}</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">backward</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">{</font><font color="#434f54">&#47;&#47;backwards code is defined here.</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_backward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_forward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_forward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_backward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">forward</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">{</font><font color="#434f54">&#47;&#47;forward code is defined here.</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_backward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_forward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_forward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_backward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">Left</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">{</font><font color="#434f54">&#47;&#47;Left code is defined here.</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_backward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_forward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_forward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_backward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">Right</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">{</font><font color="#434f54">&#47;&#47;Right code is defined here.</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_backward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">left_forward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_forward</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">right_backward</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>
<font color="#00979c">void</font> <font color="#000000">Stop</font><font color="#000000">(</font><font color="#000000">)</font><font color="#434f54">&#47;&#47;robot stop code is defined here if need be</font>
<font color="#000000">{</font>
 &nbsp;<font color="#d35400">analogWrite</font><font color="#000000">(</font><font color="#000000">left_backward</font><font color="#434f54">,</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">analogWrite</font><font color="#000000">(</font><font color="#000000">left_forward</font><font color="#434f54">,</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">analogWrite</font><font color="#000000">(</font><font color="#000000">right_forward</font><font color="#434f54">,</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">analogWrite</font><font color="#000000">(</font><font color="#000000">right_backward</font><font color="#434f54">,</font> <font color="#000000">0</font><font color="#000000">)</font><font color="#000000">;</font>
<font color="#000000">}</font>

</pre>
