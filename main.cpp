#include <iostream>
#include "FreeRTOS.h"
#include "FreeRTOS-KernelV10.6.2/include/task.h"
#include "TaskBlink.h"
#include "pico/stdio.h"


#define D1 22
#define D2 21
#define D3 20

#define SW0 7
#define SW1 8
#define SW2 9

#define DELAY1 100
#define DELAY2 300
#define DELAY3 500

void task_runner (void *param)
{
	TaskBlink *task = static_cast<TaskBlink *> (param);

	while (true)
	{
		task -> run();
	}
}

int main()
{
	stdio_init_all();

	static TaskBlink task_d1(D1, SW0, DELAY1);
	static TaskBlink task_d2(D2, SW1, DELAY2);
	static TaskBlink task_d3(D3, SW2, DELAY3);

	xTaskCreate(task_runner, "LED_1", 256, &task_d1, tskIDLE_PRIORITY +1, NULL);
	xTaskCreate(task_runner, "LED_2", 256, &task_d2, tskIDLE_PRIORITY +1, NULL);
	xTaskCreate(task_runner, "LED_3", 256, &task_d3, tskIDLE_PRIORITY +1, NULL);
	vTaskStartScheduler();

	while (true)
	{}
}