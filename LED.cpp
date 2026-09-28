//
// Created by Anh Huynh on 24.8.2026.
//

#include "LED.h"

void LED::toggle_led()
{
	last_state = !last_state;
	led.write(last_state);
}

void LED::led_off() const
{
	led.write(false);
}

bool LED::get_led_state() const
{
	return led.read();
}

