/* program that reads the amount of light using a photoresistor. We will analyze with a
photoresistor if a plant receives enough light. We connect a green,
yellow and red LEDs to the Blue Pill's ports to indicate
whether the amount of light that a plant receives is ok by turning the
green LED on, if the light is poor by turning the yellow LED on, or if the plant
is in darkness by turning the red LED on.
The light values analyzed in the program are experimental. You may need to change them accoring to your needs (e.g. a plant may need more light).
Ver. 1
Nov. 4, 2020

 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.


*/

int photoresistorPin = PB1;  // the photoresistor is connected to port PB1.
int photoresistorReading;    // the analog reading from port PB1
 
void setup(void) {  
  pinMode(PB12, OUTPUT); // green LED connected to input port PB12 (light is ok)
  pinMode(PB14, OUTPUT); // yellow LED connected to input port PB14 (light is dim)
  pinMode(PB15, OUTPUT); // red LED connected to input port PB15 (dark environment)
}
 
void loop(void) {
  photoresistorReading = analogRead(photoresistorPin); 
  digitalWrite(PB12, LOW);
  digitalWrite(PB14, LOW);
  digitalWrite(PB15, LOW);
  //we define three thresholds for the data obtained from the photoresistor: 
  if (photoresistorReading < 600) { // darkness
    digitalWrite(PB15, HIGH);
  } else if (photoresistorReading < 1000) {  // light is dim
    digitalWrite(PB14, HIGH);
  } else {
    digitalWrite(PB12, HIGH);  // light is ok
  }
  delay(500); //give some time for the photoresistor to acquire light 
}
