
#include "gdb.h"

// constants won't change. Used here to set a pin number :
const int ledPin =  13;      // the number of the LED pin

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long INTERVAL = 1000;           // interval at which to blink (milliseconds)

void RAMFUNC setup() {
	#ifdef DEBUG
		uart_div_modify(0, UART_CLK_FREQ / 115200);
		Serial.begin(115200);
		gdbstub_init();
	#endif
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}


void RAMFUNC loop() {
	static uint8_t ledState = LOW;
	ledState = calcLedState(millis(), ledState);
	digitalWrite(LED_BUILTIN, ledState);
}

uint8_t RAMFUNC calcLedState(uint32_t currentMillis, uint8_t ledState) {
	static uint32_t previousMillis = 0;
	if (currentMillis - previousMillis >= INTERVAL) {
		previousMillis = currentMillis;

		if (ledState == LOW)
			return HIGH;
		else
			return LOW;
	}
	return ledState;
}

