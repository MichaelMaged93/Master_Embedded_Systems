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
extern uint32_t _STACK_TOP;

/***************************************************************************************/

void Reset_Handler(void);
void Default_Handler(void)
{
    Reset_Handler();
}

/***************************************************************************************/

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

/****************************************************************************************/

uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t)&_STACK_TOP,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&H_Fault_Handler,
    (uint32_t)&MM_Fault_Handler,
    (uint32_t)&Bus_Fault,
    (uint32_t)&Usage_Fault_Handler
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
