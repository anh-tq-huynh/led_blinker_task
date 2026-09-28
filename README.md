## Summary
This is a simple project that uses FreeRTOS and C++ to blink LEDs.

## Requirements
Implement three tasks where each task controls blinking of one LED. Each task has a dedicated LED and a
button. Pressing the button increases LED toggle interval with 100ms increments up to 500ms. When
interval is 500ms pressing the button sets the interval to 0 which should set the LED off. When interval is
zero pressing the button increases the blinking interval again by 100ms and blinking start again.
Implement the task so that same function can be used for all three tasks. Tasks must start with blinking
intervals: 100ms, 300ms, and 500ms
