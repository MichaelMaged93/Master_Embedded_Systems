/* linker script CortexM3
Eng.Michael
*/
MEMORY
{
flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128k
sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{	
	.text : {
		_S_text = . ;
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = . ;
	}> flash
	.data : {
		_S_data = . ;
		*(.data)
		_E_data = . ;	
		. = ALIGN(4) ;
	}> sram AT> flash
	.bss : {
		_S_bss = . ;
		*(.bss*)
		_E_bss = . ;
		. = ALIGN(4) ;
	 . = . + 0x1000 ;
	 _STACK_TOP = . ;
	}> sram
}