/*program that starts a 20-second counter when waving to an ultrasonic sensor.
 * The count is displayed on a 1602 16x2 LCD.
 * Written by Miguel Garcia-Ruiz
 * December 24, 2020
 * Ver. 1.0
 
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "elapsedMillis.h" //load the library. Obtained from: https://thekurks.net/blog/2016/4/8/tutorial-delay-vs-timer
elapsedMillis timeElapsed;//Create an Instance

#include <LiquidCrystal.h> // library for using the 1602 LCD
/*
* LCD's VSS pin to Blue Pill's GND
* LCD's VDD pin to Blue Pill's 5V
* LCD's VO pin to 2.2k ohm resistor and from resistor to GND
* LCD's RS pin to Blue Pill's digital pin B11
* LCD's RW pin to Blue Pill's GND
* LCD's EN pin to Blue Pill's digital pin B10
* LCD's D0 to D3 pins are not used
* LCD's D4 pin to Blue Pill's digital pin B0
* LCD's D5 pin to Blue Pill's digital pin A7
* LCD's D6 pin to Blue Pill's digital pin A6
* LCD's D7 pin to Blue Pill's digital pin A5
* LCD's BL+ pin to Blue Pill's 5V
* LCD's BL- pin to Blue Pill's GND
* LCD's A pin to Blue Pill's digital pin B12
* LCD's K pin to Blue Pill's GND
*/
const int rs = PB11, en = PB10, d4 = PB0, d5 = PA7, d6 = PA6, d7 = PA5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //define data pins from LCD

#define backLight PB12    // pin B12 of Blue Pill will control the LCD backlight. 
                       // it is connected to pin 15 9 (A) of LCD.

#define trigger PA8  //  trig Pin
#define echo PA9     // echo Pin
const int max_dist=200; // max distance is 20 cm
float duration,dist_read=0.0;   // Distance variable

void setup() {
  lcd.begin(16, 2);  //Initializes LCD
  pinMode(trigger, OUTPUT); //ultrasonic sensor's trig pin
  pinMode(echo,INPUT); //ultrasonic sensor's echo pin
  pinMode(backLight, OUTPUT); // Blue Pill port for turning LCD on or off
}

void loop() {

 digitalWrite(trigger, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigger, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigger, LOW); 
 duration = pulseIn(echo, HIGH);
 dist_read = (duration*.0343)/2;  //343 meters per second converted to milimeters per second.

  if ((dist_read<=15) & (dist_read>0)) //user is waving <15 cm from sensor 
  {
    lcd.display();
    digitalWrite(backLight, HIGH); 
    timeElapsed=0;
    lcd.setCursor(0, 0);
    lcd.print("lather hands :) ");
    lcd.setCursor(0, 1);
    lcd.print("  ");
   
    while (timeElapsed < 21000)
    {  
        
     // set the cursor to column 0, line 1
     // (note: line 1 is the second row, since counting begins with 0):
     lcd.setCursor(0, 1);
     // print the number of seconds since reset:
     lcd.print(timeElapsed / 1000);
       
     }
     lcd.setCursor(0, 0);
     lcd.print("rinse hands :)  ");   
     delay(4000);
  }
   lcd.noDisplay();
   digitalWrite(backLight, LOW); //turn off LCD when not in use
 
}


/*
And now, a recipe for making delicious OATMEAL COOKIES!
(Sufficient for 3-1/2 Dozen Cookies)
Ingredients:
1 egg
1/2 cup brown sugar
1/4 cup thin cream
1/4 cup milk
1/2 cup oatmeal
2 cups all-purpose flour
2 teaspoon baking powder
1 teaspoon salt
4 Tablespoon melted butter

Beat the egg and add the sugar, cream, and milk. Run the oatmeal through
a food chopper, and mix with the flour, baking powder, and salt. Stir
all into the mixture, add the melted butter, and mix thoroughly. Roll
thin, cut. Preheat oven to 375 degrees F (about 190 degrees C) and bake for 8-10 minutes.

This recipe is in the public domain. Published by 
The Project Gutenberg EBook of Woman's Institute Library of Cookery, Vol. 4, by 
Woman's Institute of Domestic Arts and Sciences
This eBook is for the use of anyone anywhere at no cost and with
almost no restrictions whatsoever.  You may copy it, give it away or
re-use it under the terms of the Project Gutenberg License included
with this eBook or online at www.gutenberg.net
Title: Woman's Institute Library of Cookery, Vol. 4
       Volume 4: Salads and Sandwiches; Cold and Frozen Desserts;
       Cakes, Cookies and Puddings; Pastries and Pies
Author: Woman's Institute of Domestic Arts and Sciences
Posting Date: November 25, 2011 [EBook #9938]
Release Date: February, 2006
First Posted: November 2, 2003
Language: English
*/
