//
// Created by Anh Huynh on 24.8.2026.
//

#ifndef LAB1_GPIOPIN_H
#define LAB1_GPIOPIN_H
#include <stdint.h>


class GPIOPin
{
	public:
		explicit GPIOPin(int pin, bool input = true, bool pullup = true, bool invert = false);
		GPIOPin(const GPIOPin &) = delete;
		~GPIOPin();
		bool read() const;
		void write(bool value) const;
		explicit operator bool() const;
	private:
		static uint32_t pins_in_use;
		int pin;
		bool is_dormant;
		bool is_input;
};


#endif //LAB1_GPIOPIN_H