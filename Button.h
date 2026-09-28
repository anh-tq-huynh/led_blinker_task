//
// Created by Anh Huynh on 24.8.2026.
//

#ifndef LAB1_BUTTON_H
#define LAB1_BUTTON_H
#include "GPIOPin.h"


class Button
{
	public:
		explicit Button (const int pin) : btn (pin, true, true, true) {};
		bool btn_is_pressed();
	private:
		GPIOPin btn;
		int last_pressed_time = 0;
		bool last_pin_state = false;



};


#endif //LAB1_BUTTON_H