//
// Created by Anh Huynh on 24.8.2026.
//

#include "TaskBlink.h"

#include <iostream>

#include "FreeRTOS.h"

#include "FreeRTOS-KernelV10.6.2/include/task.h"

TaskBlink::TaskBlink(const int led_pin, const int btn_pin, const uint32_t delay)
: led(led_pin), btn(btn_pin), delay(delay)
{}


void TaskBlink::blink_task() //run every 10ms
{
	if (delay > 0)
	{
		if (delay_countdown <= 10)
		{
			led.toggle_led();
			delay_countdown = delay;
		}
		else
		{
			delay_countdown -= 10;
		}

	}
	else
	{
		led.led_off();
	}
}

void TaskBlink::change_delay()
{
	if (btn.btn_is_pressed())
	{
		if (delay < 500)
		{
			delay += 100;
		}
		else
		{
			delay = 0;
		}
		delay_countdown = delay;
	}
}

void TaskBlink::run()
{
	change_delay();
	blink_task();
	vTaskDelay(pdMS_TO_TICKS(10));
}