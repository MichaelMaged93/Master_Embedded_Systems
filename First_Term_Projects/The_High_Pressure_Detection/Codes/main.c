#include <stdint.h>
#include <stdio.h>

#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"
#include "Pressure_Sensor.h"
#include "Main_Function.h"
void setup()
{
	GPIO_INITIALIZATION();
	Pressure_Sensor_init();
	Pointer_main_state = STATE_(main_waiting);
	Pointer_Alarm_state = STATE_(stop_alarm);
	Alarm_Actuator_init();
}


int main (){
	setup();

	while (1)
	{
		Pointer_sensor();
		Pointer_main_state();
		Pointer_Alarm_state();
		state_alarm_actuator();
	}

}
