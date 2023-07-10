/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/Documents/CTD_2023/Labs/lab142/src/lab142.ino"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 3 "/Users/admin/Documents/CTD_2023/Labs/lab142/src/lab142.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

#define watchDogPin D5

void setup() {
  display.setup();
	display.clearDisplay();
	display.display();

  Watchdog.init(WatchdogConfiguration().timeout(5000));
  Watchdog.start();

  pinMode(watchDogPin, INPUT_PULLUP);
}
void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
	
  if(digitalRead(watchDogPin)) {
    Watchdog.refresh();
  }
  if(System.resetReason() == RESET_REASON_WATCHDOG) {
    display.println("Reason Due To Watchdog Timeout");
  } else {
    display.println("Reason Due To Manual Reset");
  }

  display.display();
}