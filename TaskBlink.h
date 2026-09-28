//
// Created by Anh Huynh on 24.8.2026.
//

#ifndef LAB1_TASKBLINK_H
#define LAB1_TASKBLINK_H
#include "Button.h"
#include "LED.h"


class TaskBlink
{
	public:
		TaskBlink( int led_pin,  int btn_pin, const uint32_t delay) ;
		void blink_task();
		void change_delay();

		void run();

	private:
		LED led;
		Button btn;
		uint32_t delay;
		uint32_t delay_countdown = delay;
};


#endif //LAB1_TASKBLINK_H