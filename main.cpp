#include <wiringPi.h>
#include <unistd.h>
#include <iostream>

struct MotorSide
{
	MotorSide(int in_1, int in_2, int enable): in_1(in_1), in_2(in_2), enable(enable){}
	
	void setPinMode(int mode)
	{
		switch(mode)
		{
			case 1:
				pinMode(in_1, OUTPUT);
				pinMode(in_2, OUTPUT);
				pinMode(enable, OUTPUT);
				break;
			case 0:

				pinMode(in_1, INPUT);
				pinMode(in_2, INPUT);
				pinMode(enable, INPUT);
				break;
		}
	}
	
	void goForward()
	{
		digitalWrite(in_1, HIGH);
		digitalWrite(enable, HIGH);
	}

	void stop()
	{
		digitalWrite(in_1, LOW);
		digitalWrite(enable, LOW);
	}	
	
	void test()
	{
	std::cout << in_1 << " " << in_2 << std::endl;
	}	
	
	private:
		const int in_1;
		const int in_2;
		const int enable;
};


int main(int argc, char **argv)
{
//	const int gpio_left_first = 0;
//	const int gpio_left_second = 2;
//	const int gpio_left_enable = 3;
//
//	const int gpio_right_first = 1;
//	const int gpio_right_second = 5;
//	const int gpio_right_enable = 4;
//
	wiringPiSetup();
	
	MotorSide left_side(0, 2, 3);
	MotorSide right_side(1, 5, 4);
	
	left_side.setPinMode(1);
	right_side.setPinMode(1);
	
	left_side.goForward();
	right_side.goForward();
	delay(5000);
	left_side.stop();
	right_side.stop();
	
	left_side.test();
	//pinMode(gpio_left_first, OUTPUT);
	//pinMode(gpio_left_enable, OUTPUT);
	return 0;
}




