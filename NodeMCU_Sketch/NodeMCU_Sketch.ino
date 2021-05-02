//Small sketch to controll a LED strip with a Telegram Bot

//Declare LED Object
#include <FastLED.h>
 #define LEDPIN     7 
 #define NUMOFLEDS    11 
 CRGB leds[NUMOFLEDS];
int colors[]={0, 0, 0};
float dimmer=1;
  
//Declare Bot
#include "CTBot.h"
CTBot myBot;
CTBot secondBot;
String ssid  = "<WIFI SSID"; 
String pass  = "WIFI PASSWORD"; 
String token = "TOKEN BOT ONE"; 
String second_token = "TOKEN BOT TWO";

void setup() {
  //initialize LEDs
  FastLED.addLeds<WS2812, LEDPIN, GRB>(leds, NUMOFLEDS); 
  //clear LEDs;
//  for(int i=0;i<NUMOFLEDS;i++){
//     leds[i]= CRGB (  0, 0, 0);
//      FastLED.show();
//    }
    
  // initialize the Serial
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);
  secondBot.setTelegramToken(second_token);
  
  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOT OK");
}


void loop() {
     
  // a variable to store telegram message data
  TBMessage msg;
  TBMessage msg2;

  // if there is an incoming message...
  if (myBot.getNewMessage(msg)) {
    Serial.println(msg.text);

    //Sned message with possible commands to user 
    if(msg.text.equalsIgnoreCase("help")){
      myBot.sendMessage(msg.sender.id, "Hi, this is comes from the bottom of yout lamp\n\nThe following colors are available:\nred\ngreen\nblue\npurple\nturquoise\n\n To manage brightness type:\n'down' to lower brightness\n'up' to raise brightness\n'full' to return to full brightness\n\nHave fun <3");
    }

    //LEDs are changed according to command:
    else {
      myBot.sendMessage(msg.sender.id, setLEDs(msg.text));
    }
  }

  //Code for second bot:
  //Comment the rest of the loop out if you only use one bot
  
  if (secondBot.getNewMessage(msg2)) {
    Serial.println(msg2.text);

    //Sned message with possible commands to user 
    if(msg2.text.equalsIgnoreCase("help")){
      secondBot.sendMessage(msg2.sender.id, "Hi, this is comes from the bottom of yout lamp\n\nThe following colors are available:\nred\ngreen\nblue\npurple\nturquoise\n\n To manage brightness type:\n'down' to lower brightness\n'up' to raise brightness\n'full' to return to full brightness\n\nHave fun <3");
    }

    //LEDs are changed according to command:
    else {
      secondBot.sendMessage(msg2.sender.id, setLEDs(msg2.text));
    }
  }
  
  delay(500); // wait 500 milliseconds
}


//function used to change LEDs and return a message the is send back to the user
String setLEDs(String message){
  if(message.equalsIgnoreCase("red")){
    colors[0]=255;
    colors[1]=0;
    colors[2]=0;
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (255*dimmer, 0, 0);
      FastLED.show();
    }
    return "Color changed to red.";
  }
  else if(message.equalsIgnoreCase("green")){
    colors[0]=0;
    colors[1]=255;
    colors[2]=0;
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (  0,255*dimmer, 0);
      FastLED.show();
    }
    return "Color changed to green.";
  }
  else if(message.equalsIgnoreCase("blue")){
    colors[0]=0;
    colors[1]=0;
    colors[2]=255;
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (  0, 0, 255*dimmer);
      FastLED.show();
    }
    return "Color changed to blue.";
  }

  else if(message.equalsIgnoreCase("purple")){
    colors[0]=255;
    colors[1]=0;
    colors[2]=255;
     for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (colors[0]*dimmer,colors[1]*dimmer,colors[2]*dimmer);
      FastLED.show();
    }
    return "Color changed to purple.";
  }

  else if(message.equalsIgnoreCase("turquoise")){
    colors[0]=0;
    colors[1]=255;
    colors[2]=255;
     for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (colors[0]*dimmer,colors[1]*dimmer,colors[2]*dimmer);
      FastLED.show();
    }
    return "Color changed to turquoise.";
  }

  else if(message.equalsIgnoreCase("off")){
    colors[0]=0;
    colors[1]=0;
    colors[2]=0;
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (  0, 0, 0);
      FastLED.show();
    }
    return "Lamp was turned off";
  }

  
  else if(message.equalsIgnoreCase("down")){
    dimmer=dimmer*0.5;
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (colors[0]*dimmer,colors[1]*dimmer,colors[2]*dimmer);
      FastLED.show();
    }
    return "Brightness lowered";
  }

  else if(message.equalsIgnoreCase("up")){
    dimmer =dimmer*2;
    if(dimmer>1){
      dimmer=1;
    }
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (colors[0]*dimmer,colors[1]*dimmer,colors[2]*dimmer);
      FastLED.show();
    }
    return "Brightness raised";
  }

  else if(message.equalsIgnoreCase("full")){
    dimmer=1;
    for(int i=0;i<NUMOFLEDS;i++){
      leds[i]= CRGB (colors[0],colors[1],colors[2]);
      FastLED.show();
    }
    return "maximum Brightness";
  }

  else{

    return "Invalid command. Nothing was changed.";
  } 
}
