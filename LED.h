//
// Created by Anh Huynh on 24.8.2026.
//

#ifndef LAB1_LED_H
#define LAB1_LED_H
#include "GPIOPin.h"


class LED
{
	public:
		explicit LED (const int pin) : led (pin, false, false, false){}

		void toggle_led();
		void led_off() const;
		bool get_led_state() const;
	private:
		GPIOPin led;
		bool last_state = false;


};


#endif //LAB1_LED_H