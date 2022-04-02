#ifndef BUTTON
#define BUTTON

#define TOUCH 0
#define DIO 1

class Button {
  private:
	/*
	*  main variable (can change value for your default)
	*/
    int pinType = 1; //default pin type is digitalIO get input by digitalRead function
    int buttonPin = 19; // analog input pin to use as a digital input
    // Button timing variables
    int debounce = 20; // ms debounce period to prevent flickering when pressing or releasing the button
    int DCgap = 100; // max ms between clicks for a double click event
    int holdTime = 2000; // ms hold period: how long to wait for press+hold event
    int longHoldTime = 5000; // ms long hold period: how long to wait for press+hold event
    int threadHold = 40; //threadhold for touch pin (for esp32 only)
	/*active LOW by default (need external_pullup for some pins)
	* can change it to HIGH (recomended for some pins not working with INPUT_PULLUP)
	*/
	int activeState = LOW; 
    /*
	*  Other button variables (don't change any.)
	*/
    boolean buttonVal = HIGH; // value read from button
    boolean buttonLast = HIGH; // buffered value of the button's previous state
    boolean DCwaiting = false; // whether we're waiting for a double click (down)
    boolean DConUp = false; // whether to register a double click on next release, or whether to wait and click
    boolean singleOK = true; // whether it's OK to do a single click
    long downTime = -1; // time the button was pressed down
    long upTime = -1; // time the button was released
    boolean ignoreUp = false; // whether to ignore the button release because the click+hold was triggered
    boolean waitForUp = false; // when held, whether to wait for the up event
    boolean holdEventPast = false; // whether or not the hold event happened already
    boolean longHoldEventPast = false;// whether or not the long hold event happened already
    boolean enablePress = false;
    boolean enableRelease = false;
    boolean enableClick = false;
    boolean enableDoubleClick = false;
    boolean enableHold = false;
    boolean enableLongHold = false;

	/*
	*   event source function
	*/
    void (*funcEventPress)(int pinSource);
    void (*funcEventRelease)(int pinSource);
    void (*funcEventClick)(int pinSource);
    void (*funcEventDoubleClick)(int pinSource);
    void (*funcEventHold)(int pinSource);
    void (*funcEventLongHold)(int pinSource);
    int checkButton();
	


  public:
    Button(int pin, int pinType,int ast);
    String Text = "";
    int Checked = 0;
    void init(int pin, int pinType,int ast);
	boolean isPress();
	void setActiveState(int state);
    void setPressDebounce(int debounce);
    void setHoldTime(int millis);
    void setLongHoldTime(int millis);
    void setDoubleClickTime(int millis);
    void setTouchThreadHold(int th);
    void eventPress(void (*pressFunc));
    void eventRelease(void (*releaseFunc));
    void eventClick(void (*clickFunc));
    void eventDoubleClick(void (*doublClickFunc));
    void eventHold(void (*holdFunc));
    void eventLongHold(void (*longlHoldFunc));
	void handleButton();
    
};

boolean Button::isPress(){
	if(buttonVal == LOW)
		return true;
	return false;
}
void Button::setTouchThreadHold(int th = 40) {
  this->threadHold = th;
}

int Button::checkButton() {
  int event = 0;
  // Read the state of the button

  if (this->pinType != TOUCH) {
    buttonVal = digitalRead(buttonPin);
  }
 #ifdef ESP32 
  else {
//Serial.println(touchRead(buttonPin));
    if (touchRead(buttonPin) <= this->threadHold) {
      buttonVal = LOW;
    } else {
      buttonVal = HIGH;
    }
	
  }
#endif
  // Button pressed down
  if(activeState==HIGH)
	  buttonVal=!buttonVal;
  if (buttonVal == LOW && buttonLast == HIGH && (millis() - upTime) > debounce) {
    //fixed for button press, click and double click
    if (enablePress == true) {
      this->funcEventPress(buttonPin);
    }
    delay(1);
    downTime = millis();
    ignoreUp = false;
    //      waitForUp = false;
    singleOK = true;
    holdEventPast = false;
    longHoldEventPast = false;
    if ((millis() - upTime) < DCgap && DConUp == false && DCwaiting == true) DConUp = true;
    else DConUp = false;
    DCwaiting = false;
  }
  // Button released
  else if (buttonVal == HIGH && buttonLast == LOW && (millis() - downTime) > debounce) {
    if (not ignoreUp) {
      upTime = millis();
      if (DConUp == false) DCwaiting = true;
      else {
        event = 2;
        DConUp = false;
        DCwaiting = false;
        singleOK = false;
      }
    }
    if (enableRelease == true) {
      funcEventRelease(buttonPin);
    }
  }
  // Test for normal click event: DCgap expired
  if ( buttonVal == HIGH && (millis() - upTime) >= DCgap && DCwaiting == true && DConUp == false && singleOK == true) {
    event = 1;
    DCwaiting = false;
  }
  // Test for hold
  if (buttonVal == LOW && (millis() - downTime) >= holdTime) {
    // Trigger "normal" hold
    if (not holdEventPast) {
      event = 3;
      waitForUp = true;
      ignoreUp = true;
      DConUp = false;
      DCwaiting = false;
      downTime = millis();
      holdEventPast = true;
    }
    // Trigger "long" hold
    if ((millis() - downTime) >= longHoldTime) {
      if (not longHoldEventPast) {
        event = 4;
        longHoldEventPast = true;
      }
    }
  }
  buttonLast = buttonVal;
  return event;
}

Button::Button(int pin, int pinType = 1,int ast=LOW) {
  this->init(pin, pinType, ast);
};

void Button::setActiveState(int state=LOW){
	activeState=state;
}

void Button::setPressDebounce(int debounce = 20) {
  this->debounce = debounce;
}

void Button::setHoldTime(int millis = 2000) {
  this->holdTime = millis;
}
void Button::setLongHoldTime(int millis = 5000) {
  this->longHoldTime = millis;
}
void Button::setDoubleClickTime(int millis = 100) {
  this->DCgap = millis;
}

void Button::eventPress(void *pressFunc) {
  this->enablePress = true;
  this->funcEventPress = (void (*)(int))pressFunc;
}
void Button::eventRelease(void *releaseFunc) {
  this->enableRelease = true;
  this->funcEventRelease = (void (*)(int))releaseFunc;
}
void Button::eventClick(void (*clickFunc)) {
  this->enableClick = true;
  this->funcEventClick = (void (*)(int))clickFunc;
}
void Button::eventDoubleClick(void (*doublClickFunc)) {
  this->enableDoubleClick = true;
  this->funcEventDoubleClick = (void (*)(int))doublClickFunc;
}
void Button::eventHold(void (*holdFunc)) {
  this->enableHold = true;
  this->funcEventHold = (void (*)(int))holdFunc;
}
void Button::eventLongHold(void (*longlHoldFunc)) {
  this->enableLongHold = true;
  this->funcEventLongHold = (void (*)(int))longlHoldFunc;
}

void Button::init(int pin, int pinType = 0,int ast=LOW) {
  this->activeState=ast;
  this->pinType = pinType;
  this->buttonPin = pin;
  if (this->pinType != TOUCH) {
	//the following work with INPUT_PULLUP: 14, 16, 17, 18, 19, 21, 22, 23 
	//this library will check button state with LOW
	if(activeState==LOW){
		pinMode(buttonPin, INPUT_PULLUP);
	}else{
		pinMode(buttonPin, INPUT);
	}
	//Serial.println("pullup");
  }
}
void Button::handleButton() {
  int b = checkButton();
  if (b == 1) {
    if (enableClick == true) {
      funcEventClick(buttonPin);
    }
  }
  if (b == 2) {
    if (enableDoubleClick == true) {
      funcEventDoubleClick(buttonPin);
    }
  }
  if (b == 3) {
    if (enableHold == true) {
      funcEventHold(buttonPin);
    }
  }
  if (b == 4) {
    if (enableLongHold == true) {
      funcEventLongHold(buttonPin);
    }
  }
}

#endif
