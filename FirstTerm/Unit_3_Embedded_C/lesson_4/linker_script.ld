/* linker script CortexM4
Eng.Michael
*/
MEMORY
{
flash(RX) : ORIGIN = 0x00000000 , LENGTH = 512M
sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 512M
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
	}> sram
}