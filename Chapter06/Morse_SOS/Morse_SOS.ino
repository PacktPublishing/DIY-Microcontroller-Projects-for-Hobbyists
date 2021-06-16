/* Program that demonstrates how to show an S.O.S. Morse code message using a super bright LED connected to a Blue Pill's output port
 * Written by Miguel Garcia-Ruiz
 * December 10, 2020
 * Ver. 1.0
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 
 */

int led=PB12; // the Blue Pill's output port B12
int dot_duration=150; //dot duration in milliseconds
int dash_duration=dot_duration*3; //dash duration in milliseconds. A dash is three times the dot duration.
int shortspace_duration=dot_duration; // space between letters
int space_duration=dot_duration*7;//words are separated by a space equivalent to seven dots

void setup() {
      pinMode (led,OUTPUT);
} 

void S() { // making letter S
          dot();
          dot();
          dot();
          shortspace();
}
         
void O() { // making letter O
          dash();
          dash();
          dash();
          shortspace();
}
         
void shortspace() {
          delay(shortspace_duration);
} // a short space between letters

void space() {
          delay (space_duration);
} //a space between words

void dot() { //making a dot with a signal unit, which is short
          digitalWrite(led,HIGH); 
          delay (dot_duration); 
          digitalWrite(led,LOW); 
          delay(dot_duration); 
}
           
void dash() { //making a dash with three signal units
          digitalWrite(led,HIGH); 
          delay(dash_duration); 
          digitalWrite(led,LOW); 
          delay(dash_duration); 
}

void loop() {
          S(); O(); S(); //SOS message ("Save Our Souls") 
          space();  // a space in between each SOS word made with seven signal units
}
