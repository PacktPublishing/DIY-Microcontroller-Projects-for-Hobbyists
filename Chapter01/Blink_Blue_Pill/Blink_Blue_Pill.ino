/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc
  This example code is in the public domain.
  modified 8 May 2014
  by Scott Fitzgerald
  
  Modified by Roger Clark. www.rogerclark.net for Maple mini 25th April 2015 , where the LED is on PC13
  Modified by Miguel Garcia-Ruiz.
  
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
  
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PC13 as an output. Blue Pill's internal LED is also connected to it.
  pinMode(PC13, OUTPUT);  //PC13 I/O port is labeled as "C13" on the Blue Pill.
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
