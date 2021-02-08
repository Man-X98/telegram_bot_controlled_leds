# telegram_bot_controlled_leds
<h1>Control your LEDs with a simple telegram bot </h1>
  <p>This simple NodeMCU sketch lets you control an addressable LED strip with up to two telegram bots with simple commands. 
    I did not find a good system yet to choose induvidual colors. All colors have to be programmed into the sketch. </p>
  
  <h4>Parts</h4>
  <ul>
    <li>NodeMCU</li>
    <li>WS2812B LED strip</li>
    <li>5V power supply</li>
    <li>Cables to put everything together</li>
  </ul>
  <h4> Integrated commands</h4>
  <ul>
  <li>"help" --> returns a list of available commands</li>
  <li>"red" --> turns leds red</li>
  <li>"green" --> turns leds green</li>
  <li>"blue" --> turns leds blue</li>
  <li>"purple" --> turns leds purple</li>
  <li>"turquoise" --> turns leds turquoise</li>
  <li>"down" --> lowers brightness</li>
  <li>"up" --> raises brightness</li>
  <li>"full" --> sets leds to maximum brightness </li>
  </ul>
  
  <p> There is also a special "love" command. I used this code together with the following print: https://www.prusaprinters.org/prints/41691-heart-shaped-lamp
  The love command turns the lights off, then pulses red and resumes to the previous color. With this command and support for two telegram bots you can show your partner you are thinking of him/her while no being with them. Just delete that part if it's not what you are looking for ;)</p>
  
