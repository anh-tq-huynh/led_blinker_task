//
// Created by Anh Huynh on 24.8.2026.
//

#include "Button.h"
#include "FreeRTOS.h"
#include "FreeRTOS-KernelV10.6.2/include/task.h"


bool Button::btn_is_pressed()
{
	bool current_pin_state = btn.read();
	TickType_t current_time = xTaskGetTickCount();

	if (current_pin_state  && !last_pin_state)
	{
		if ((current_time - last_pressed_time) >= pdMS_TO_TICKS(50))
		{
			last_pressed_time = current_time;
			last_pin_state = true;
			return true;
		}

	}
	if (!current_pin_state)
	{
		if ((current_time - last_pressed_time) >= pdMS_TO_TICKS(50))
		{
			last_pin_state = false;
		}
	}
	return false;
}
