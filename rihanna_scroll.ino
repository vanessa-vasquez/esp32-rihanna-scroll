/*
  Sketch to show scrolling of the graphics in sprites.
  Scrolling in this way moves the pixels in a defined rectangle
  within the Sprite. By default the whole sprite is scrolled.
  The gap left by scrolling is filled with a defined colour.

  Example for library:
  https://github.com/Bodmer/TFT_eSPI

  A Sprite is notionally an invisible graphics screen that is
  kept in the processors RAM. Graphics can be drawn into the
  Sprite just as it can be drawn directly to the screen. Once
  the Sprite is completed it can be plotted onto the screen in
  any position. If there is sufficient RAM then the Sprite can
  be the same size as the screen and used as a frame buffer.

  A 16 bit Sprite occupies (2 * width * height) bytes in RAM.

  An 8 bit Sprite occupies (width * height) bytes in RAM.

*/

#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite scrollText = TFT_eSprite(&tft); // Sprite object scrollText

int tcount = 0;

//==========================================================================================
void setup() {
  tft.init();
  tft.fillScreen(TFT_RED);

  // Create a sprite for Hello World
  scrollText.setColorDepth(8);
  scrollText.createSprite(135, 240);
  scrollText.setScrollRect(0, 0, 135, 240, TFT_RED);
  scrollText.fillSprite(TFT_RED);
  scrollText.setTextColor(TFT_WHITE); // White text, no background
}

//==========================================================================================
void loop() {
  // Push the sprites onto the TFT at specified coordinates
  scrollText.pushSprite(0, 0);

  delay(50); // wait so things do not scroll too fast

  // Now scroll the sprites scroll(dt, dy) where:
  // dx is pixels to scroll, left = negative value, right = positive value
  // dy is pixels to scroll, up = negative value, down = positive value
  // graph1.scroll(-1, 0); // scroll graph 1 pixel left, 0 up/down
  scrollText.scroll(0, 3);     // scroll stext 1 pixel right, up/down default is 0

  if (tcount == 0){
    scrollText.drawString("Things that happened", 0, 0, 2); // draw at 0,0 in sprite, font 2
    scrollText.drawString("at the Rihanna", 0, 25, 2);
    scrollText.drawString("concert ft. the", 0, 50, 2);
    scrollText.drawString("Superbowl", 0, 75, 2);
  } else if (tcount == 80){
    scrollText.drawString("1. She had a bomb", 0, 0, 2);
    scrollText.drawString("setlist.", 0, 25, 2);
  } else if (tcount == 160){
    scrollText.drawString("2. Fenty Beauty made", 0, 0, 2);
    scrollText.drawString("a cameo. Slay!", 0, 25, 2);
  } else if(tcount == 240){
    scrollText.drawString("3. She announced she", 0, 0, 2);
    scrollText.drawString("was pregnant!", 0, 25, 2);
  }

  if (tcount == 320){
    tcount = 0; // Loop back
  } else {
    tcount++;
  }

} // Loop back and do it all again
//==========================================================================================
