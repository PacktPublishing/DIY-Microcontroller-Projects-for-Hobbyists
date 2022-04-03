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
#define PinPushButton PB0

class PushButtonHelper {
  public: 
    PushButtonHelper(int PinPushBtn) {
      PIN_PUSH_BUTTON = PinPushBtn;
    }

    int read_status() {
      current_reading = digitalRead(PIN_PUSH_BUTTON);
      // check to see if you just pressed the button
      // (i.e. the input went from LOW to HIGH), and you've waited long enough
      // since the last press to ignore any noise:

      // If the switch changed, due to noise or pressing:
      // reset the debouncing timer
      reset_debouncing_timer();

      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:
      if (isTimeElapsedLessThanOurDefaultDelayTime() && pushButtonStateChanged()) {
        // if the button state has changed:
        button_state = current_reading;

        // only toggle the Value/LED if the new button state is HIGH
        if (isButtonActivelyPressed()) {
          status = !status;
        } 
      }

      // save the reading. Next time through the loop, it'll be the lastButtonState:
      last_button_state = current_reading;
      return status;
    }

  private: 
    int PIN_PUSH_BUTTON;                    // port to read from
    unsigned long last_debouncing_time = 0; // the last time the output pin was toggled
    unsigned long debouncing_delay = 50;    // the debounce time; increase if the output flickers
    int status = HIGH;                      // the current state of the output pin
    int button_state;                       // the current reading from the input pin
    int last_button_state = LOW;            // the previous reading from the input pin
    int current_reading;

    void reset_debouncing_timer() {
      if(current_reading != last_button_state) {
        last_debouncing_time = millis();
      }
    }

    int isTimeElapsedLessThanOurDefaultDelayTime() {
      return (millis() - last_debouncing_time) > debouncing_delay;
    }

    int pushButtonStateChanged() {
      return current_reading != button_state;
    }

    int isButtonActivelyPressed() {
      return button_state == HIGH;
    }
} button_handler(PinPushButton);

void setup() {
  pinMode(PinLED, OUTPUT);
  pinMode(PinPushButton, INPUT_PULLUP);
}

void loop() {
  int led_status = button_handler.read_status();
  
  // set the LED:
  digitalWrite(PinLED, led_status);
}
