#@copyright : Michael
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I . 
LIBS=
SRC =$(wildcard *.c)
OBJ= $(SRC:.c=.o)
As =$(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=learn_in_depth_cortex_m3
all:$(Project_name).bin
	@echo ======Build is Done======

startup.o: startup.s
	 $(CC)as.exe $(CFLAGS) $< -o $@

%.o:%.c
		 $(CC)gcc.exe -c $(INCS)   $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $(Project_name).elf -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	 $(CC)objcopy.exe -O binary $< $@




