# esp32-rihanna-scroll
A visual project for the ESP32 TTGO T-Display which scrolls text relating to Rihanna's Super Bowl halftime performance.

<img src="./rihanna_scroll_img.png" width="550" height="400" />

## Set Up
For this project, you will need an ESP32 TTGO T-Display. I will be using the Arduino IDE in order to upload this project onto the ESP32. 

1. To set up the Arduino IDE environment, follow the instructions in the demo [here](https://www.youtube.com/watch?v=adLUgmCJKnM).
- Some issues that came up for me in setting up this environment included lack of dependencies (e.g. python) and the upload speed. For example, I found that I had to lower my upload speed to 115200. Keep these in mind and make changes accordingly if you come across any issues when following the demo -- the output should let you know.
2. Clone this project and open it up in the Arduino IDE.
3. Connect to your ESP32. Make sure that you select your board on the top left. 
4. Upload your code and voilà! You should now see the scrolling text on your ESP32. 

## Technical Concerns
Some technical issues arose due to my inexperience with the functions available to alter the interface. Research was needed in order to figure out things like how to loop the scroll text and make one appear right after the other as well as how to control other aesthetic choices.

I found the TFT_eSPI Sprite Scroll example to be incredibly useful in helping me figure out, not only how to scroll (both vertically and horizontally), but also how to write text to the interface, change colors, etc. On mac, you can access this example by going into the Arduino IDE and going to File > Examples > TFT_eSPI > Sprite > Sprite Scroll.

In terms of what functions are available to alter the interface, the following repo provides the list of available functions in addition to their implementations: [https://github.com/Bodmer/TFT_eSPI/blob/master/Extensions/Sprite.cpp](https://github.com/Bodmer/TFT_eSPI/blob/master/Extensions/Sprite.cpp). 

- If you use the Sprite Scroll example as a template, this link can also be found at the top of that file as well.

## Notes
For more details on this project, visit the blog post [here](https://pitch-koala-3bc.notion.site/Rihanna-Halftime-Memorial-Generative-Ar-23d2540f1279470699fa699854f9609d).
