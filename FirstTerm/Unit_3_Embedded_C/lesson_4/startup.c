// Startup.c
// Eng.Michael

#include <stdint.h>

extern int main(void);
//
extern uint32_t _S_text;
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
//booking 1024 B located by .bss through un intialized array of int 256 Element (256*4=1024)

 static uint32_t STACK_TOP[256];

/***************************************************************************************/

void Reset_Handler(void);
void Default_Handler(void)
{
    Reset_Handler();
}

/***************************************************************************************/

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
/****************************************************************************************/
   void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) =
   { 
    (void (*)())((unsigned long)STACK_TOP+ sizeof(STACK_TOP)),
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler
   };
/****************************************************************************************/

void Reset_Handler(void)
{
    // Copy data section from ROM to RAM
    uint32_t DATA_size = (uint8_t*)&_E_data - (uint8_t*)&_S_data;
    uint8_t* P_src = (uint8_t*)&_E_text;
    uint8_t* P_dst = (uint8_t*)&_S_data;

    for (uint32_t i = 0; i < DATA_size; i++)
    {
        *((uint8_t*)P_dst++) = *((uint8_t*)P_src++) ;
    }

/******************************************************************************************/

    // Initialize .bss section in SRAM to 0
    uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
    P_dst = (uint8_t*)&_S_bss;

    for (uint32_t i = 0; i < bss_size; i++)
    {
        *((uint8_t*)P_dst++) = (uint8_t)0 ; 
    }

    /************************************************************************************/

    // Jump to main()
    main();
}
