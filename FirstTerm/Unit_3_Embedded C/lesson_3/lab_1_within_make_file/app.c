#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:<michael>";
unsigned char string_buffer3[100] = "learn-in-depth:<michael>";

void main(void)
{
	Uart_Send_String(string_buffer);
}