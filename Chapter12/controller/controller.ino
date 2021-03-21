/*
 * Program for getting temp. data from an Arduino Uno (peripheral) and 
 * display it on an LCD, using an I2C bus.
 * This program runs on a Blue Pill microcontroller board (controller).
 * Written by Miguel Garcia-Ruiz
 * Feb. 3, 2021
 * Ver. 1
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <LiquidCrystal_I2C.h> //library for controlling the LCD using I2C protocol
LiquidCrystal_I2C lcd(0x27, 16, 2);// Sets LCD address to 0x27 for a 16 characters and 2 lines display
//The library can be downloaded from: https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

#include <Wire.h> //controls I2C protocol
#define SLAVEADDRESS 0x8  //Arduino Uno's peripheral (slave) address
void setup() {
  Wire.begin(SLAVEADDRESS); //starts I2C connection using peripheral (slave) address. 
  Serial.begin(9600); //temp. data is also shown on serial monitor from Arduino IDE
  lcd.begin();  //Initializes LCD
  lcd.backlight(); // Turns on the LCD backlight
}

void loop() {
   Wire.requestFrom(8, 4);//The master requests bytes from a peripheral (slave) device (the Arduino Uno).
                          //The bytes then are retrieved with the read() function. 
                          //syntax: Wire.requestFrom(address, quantity); 
   
   uint8_t index = 0;

//The following code snippet is based on: https://medium.com/@sandhan.sarma/sending-floats-over-the-i2c-bus-between-two-arduinos-part-2-486db6dc479f
//The following defines a custom data structure called floatToBytes, which is based on a union datatype.
//It also declares a floatToBytes variable named converter. 
//The floatToBytes data structure has 2 variables: one is a char array with size 4, and a float variable.
//both objtempReading and buffer are occupying the same memory location, the 4 elements of the buffer array now also points to the the same 4 bytes of our float variable objtempReading:
   union floatToBytes {
       char buffer[4];
       float objtempReading; 
   } converter;

   while (Wire.available()){ //Returns the # of bytes that available for reading with read()
      converter.buffer[index] = Wire.read(); //sends the buffer variable as an argument to Wire.write()
      index++;
   }

   Serial.println(converter.objtempReading); //shows temp. on serial monitor
   lcd.setCursor(0, 0); // LCD's curson on column 0, row 0 
   lcd.print("Body Temp.:"); 
   lcd.print(converter.objtempReading); //displays temperature on the LCD in degrees Celsius
   delay(500);
}
