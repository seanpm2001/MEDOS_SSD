SECTIONS
{
    . = 0x00100000;

    .text :{
        code = .; _code = .; __code = .;
        *(.text)
        *(.rodata)
    }

    .rodata ALIGN (0x1000) : {
        *(.rodata)
    }

    .data ALIGN (0x1000) : {
        data = .; _data = .; __data = .;
        *(.data)
    }

    .bss : {
        sbss = .;
        bss = .; _bss = .; __bss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }
    end = .; _end = .; __end = .;
}

ARCH		=	i386
RTS_DIR		=	`pwd`/rts/boards/$(ARCH)
 
ifeq ($(ARCH),i386)
GNATMAKE	=	gnatmake
AS		=	as
ASFLAGS		=	--32 -march=i386
 
OBJS		=	obj/startup.o obj/multiboot.o obj/console.o
BOARD		=	pc
 
.PHONY: obj/multiboot.o obj/console.o
 
endif
 
all: bare_bones
 
bare_bones: $(OBJS) src/bare_bones.adb
	$(GNATMAKE) --RTS=$(RTS_DIR) -XBoard=$(BOARD) -Pbare_bones.gpr
 
obj/startup.o: src/$(BOARD)/startup.s
	$(AS) $(ASFLAGS) src/$(BOARD)/startup.s -o obj/startup.o
 
.PHONY: clean