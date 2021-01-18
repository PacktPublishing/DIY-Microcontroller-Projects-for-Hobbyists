/* 
 * Program that turns an LED on when its user presses a push button.
 * It debouonces the push button via software.
 * Miguel Garcia-Ruiz. 
 * The code is based on this web page: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
 * Version: 1.0
 * Date: October 19, 2020
 
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 
 
*/
#define PinLED PB12
#define Pinpushbutton PB0

void setup() {
  pinMode(PinLED, OUTPUT);
  pinMode(Pinpushbutton, INPUT_PULLUP);
}

 int reading_pushbutton;
 int ledState = HIGH;         // the current state of the output pin
  int buttonState;             // the current reading from the input pin
  int lastButtonState = LOW;   // the previous reading from the input pin
  unsigned long lastDebouncingTime = 0;  // the last time the output pin was toggled
  unsigned long debouncingDelay = 50;    // the debounce time; increase if the output flickers
  
void loop() {

  reading_pushbutton=digitalRead(Pinpushbutton);
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading_pushbutton!= lastButtonState) {
    // reset the debouncing timer
    lastDebouncingTime = millis();
  }

  if ((millis() - lastDebouncingTime) > debouncingDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading_pushbutton!=buttonState) {
      buttonState = reading_pushbutton;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(PinLED, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading_pushbutton;
    
  
}
