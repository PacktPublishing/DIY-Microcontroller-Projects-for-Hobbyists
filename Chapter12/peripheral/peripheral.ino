/*program that reads body temperature using an MLX90614 IR sensor connected
 * to an Arduino Uno's I2C.
 * This is the program for the Arduino Uno (also called peripheral or slave).
 * Temp. data will be sent through I2C bus to a Blue Pill microcontroller board.
 * Written by Miguel Garcia-Ruiz
 * Feb. 3, 2021
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
#include <Wire.h> //library that controls I2C bus
#include <Adafruit_MLX90614.h> //library for IR sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614(); //initializes sensor
#define SLAVEADDRESS 0x8  //  Arduino's slave address

float AmbientobjC=0.0; //it will store temp. in Celsius degrees

void setup() {  
  Wire.begin(SLAVEADDRESS); //starts I2C
  Wire.onRequest(requestEvent); //Interrupt that handles incoming requests from controller (master)
}

void loop() {
  AmbientobjC=mlx.readObjectTempC();// reads temp. values from sensor continuously
  delay(100);
}

void requestEvent() { //function that runs every time the controller (master) requests data from peripheral (slave)
 //The following code snippet is based on: https://medium.com/@sandhan.sarma/sending-floats-over-the-i2c-bus-between-two-arduinos-part-2-486db6dc479f
 //The following defines a custom data structure called floatToBytes, which is based on a union datatype.
 //It also declares a floatToBytes variable named converter. 
 //The floatToBytes data structure has 2 variables: one is a char array with size 4, and a float variable.
 //both objtempReading and buffer are occupying the same memory location, the 4 elements of the buffer array now also points to the the same 4 bytes of our float variable objtempReading:
  union floatToBytes {
    char buffer[4];
    float objtempReading;
  } converter;
 //temp. is added +3 for compensating ambient temp:
  converter.objtempReading = AmbientobjC+3;
  Wire.write(converter.buffer, 4); //sends temp. through I2C bus as bytes
}



