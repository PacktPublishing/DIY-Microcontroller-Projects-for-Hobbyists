/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 7: Clap switch: using a simple microphone to detect two clapping sounds in a row.
  Exercice 1: A LED will blink after a clap is detected by the mic sensor.

  Ver. 1
  August, 2020
  
  
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
  
*/

const int MicAnalogPin = 0;                   // analog input pin
const int LedDigitalPin = PC13;               // digital output pin
const int ClapThreshold = 300;                // value for your clap sound

void setup() {
  Serial.begin(9600);                         // starts serial transmition, sets data rate to 9600 bps
  pinMode(LedDigitalPin, OUTPUT);             // set the digital pin as output
  pinMode(MicAnalogPin, INPUT);               // set the analogo pin as input
}

void loop() {
  int SoundValue = analogRead(MicAnalogPin);  // read sensor data from analog pin
  if (SoundValue > ClapThreshold) {           // clap detected?
    digitalWrite(LedDigitalPin, HIGH);        // turn led on
    delay(1000);                               // a second pause
  } else {
    digitalWrite(LedDigitalPin, LOW);         // turn led off
  }
}
