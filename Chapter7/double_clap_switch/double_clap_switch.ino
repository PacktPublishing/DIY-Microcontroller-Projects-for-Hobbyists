/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 7: Clap switch: using a simple microphone to detect two clapping sounds in a row.
  Exercice 2: A LED will blink after two claps are detected by the mic sensor.
  
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.

  Ver. 1
  August, 2020
*/

const int MicAnalogPin = 0;                   // analog input pin
const int LedDigitalPin = PC13;               // digital output pin
const int ClapThreshold = 300;                // value for your clap sound
int ClapNumber = 0;                           // clap counter
bool LedState = false;                        // state of the LED

void setup() {
  Serial.begin(9600);                         // start analog sensing
  pinMode(LedDigitalPin, OUTPUT);             // set the digital pin as output
  pinMode(MicAnalogPin, INPUT);               // set the analogo pin as input
}

void loop() {
  int SoundValue = analogRead(MicAnalogPin);  // read sensor data from analog pin
  if (SoundValue > ClapThreshold) {           // clap detected?
    ClapNumber++;                             // increase the clap counter
    delay(500);                               // a 500 miliseconds pause
  }
  if (ClapNumber == 2) {                      // two claps?
    if (LedState) {
      digitalWrite(LedDigitalPin, HIGH);        // turn led on
    } else {
      digitalWrite(LedDigitalPin, LOW);         // turn led off
    }
    ClapNumber = 0;
    LedState = !LedState;                     // flag the state for the LED
  }
}
