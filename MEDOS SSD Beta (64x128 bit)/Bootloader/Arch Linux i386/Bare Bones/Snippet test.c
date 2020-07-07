mkdir -p bare_bones/src/pc
cd bare_bones
mkdir -p rts/boards/i386/adalib
mkdir -p rts/boards/i386/adainclude
mkdir -p rts/src
mkdir -p obj

for f in "ada.ads" "a-unccon.ads" "a-uncdea.ads" "gnat.ads" "g-souinf.ads" \
"interfac.ads" "s-atacco.adb" "s-atacco.ads" "s-maccod.ads" "s-stoele.adb" \
"s-stoele.ads"
do
cp /usr/lib/gcc/x86_64-linux-gnu/4.6/adainclude/$f rts/src/
ln -s `pwd`/rts/src/$f `pwd`/rts/boards/i386/adainclude/$f
done

pragma Discard_Names;
pragma Restrictions (No_Enumeration_Maps);
pragma Normalize_Scalars;
pragma Restrictions (No_Exception_Propagation);
pragma Restrictions (No_Finalization);
pragma Restrictions (No_Tasking);
pragma Restrictions (No_Protected_Types);
pragma Restrictions (No_Delay);
pragma Restrictions (No_Recursion);
pragma Restrictions (No_Allocators);
pragma Restrictions (No_Dispatch);
pragma Restrictions (No_Implicit_Dynamic_Code);
pragma Restrictions (No_Secondary_Stack);

   package Binder is
      for Default_Switches ("Ada") use ("-r");
   end Binder;
   
type Fruit is (Orange, Banana, Apple);
--  Ada defines the following strings, "Orange", "Banana" and "Apple" in an array.
 
--  These strings can be accessed using the 'Image attribute, as in
Put (Fruit'Image (Orange));
--  Prints "Orange" to the console.

  TE : exception;  --  A badly named exception.
  
   raise Console.TE;
exception
   when Console.TE =>
      Put ("TE caught", 1, 2);
	 
bare_bones.adb:17:04: construct not allowed in configurable run-time mode
bare_bones.adb:17:04: file a-except.ads not found
bare_bones.adb:17:04: entity "Ada.Exceptions.Raise_Exception" not available
gnatmake: "/home/laguest/src/mine/bare_bones/src/bare_bones.adb" compilation error
make: *** [disk/boot/bare_bones] Error 4

with System;
 
package Ada.Exceptions is
   pragma Preelaborate (Exceptions);
 
   type Exception_Id is private;
   pragma Preelaborable_Initialization (Exception_Id);
 
   Null_Id : constant Exception_Id;
 
   procedure Raise_Exception
     (E       : Exception_Id;
      Message : String := "");
   pragma No_Return (Raise_Exception);
private
   type Exception_Id is new Natural;
 
   Null_Id : constant Exception_Id := Exception_Id'First;
end Ada.Exceptions;
 
with GNAT.Source_Info;
with Last_Chance_Handler;
 
package body Ada.Exceptions is
   procedure Raise_Exception
     (E       : Exception_Id;
      Message : String := "") is
      pragma Unreferenced (E);
      pragma Unreferenced (Message);
      File             : String := GNAT.Source_Info.File;
      Line             : Positive := GNAT.Source_Info.Line;
      Source_Location  : String := GNAT.Source_Info.Source_Location;
      Enclosing_Entity : String := GNAT.Source_Info.Enclosing_Entity;
      pragma Unreferenced (File, Line, Source_Location, Enclosing_Entity);
   begin
      Last_Chance_Handler (System.Null_Address, 0);
 
      loop
         null;
      end loop;
   end Raise_Exception;
end Ada.Exceptions;

bare_bones.adb:23:17: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:23:17: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:30:07: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:30:07: warning: Last_Chance_Handler will be called on exception
bare_bones.adb:33:17: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:33:17: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:38:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:38:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:44:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:44:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:50:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:50:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:56:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:56:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:61:42: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:61:42: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:86:21: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:86:21: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:86:30: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:86:30: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:86:39: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:86:39: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:89:26: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:89:26: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:97:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:97:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:104:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:104:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:110:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:110:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:124:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:124:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:130:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:130:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:136:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:136:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:142:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:142:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:148:20: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:148:20: warning: "Constraint_Error" may call Last_Chance_Handler
bare_bones.adb:151:04: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:151:04: warning: Last_Chance_Handler will be called on exception
bare_bones.adb:160:04: warning: pragma Restrictions (No_Exception_Propagation) in effect
bare_bones.adb:160:04: warning: this handler can never be entered, and has been removed
bare_bones.adb:160:09: violation of restriction "No_Exception_Propagation" at ../gnat.adc:10
gnatmake: "/home/laguest/src/mine/bare_bones/src/bare_bones.adb" compilation error
make: *** [disk/boot/bare_bones] Error 4

private
 
   Run_Time_Name : constant String := "Bare Bones Run Time";
   
with System;
 
procedure Last_Chance_Handler
  (Source_Location : System.Address; Line : Integer);
pragma Export (C, Last_Chance_Handler, "__gnat_last_chance_handler");

procedure Last_Chance_Handler
  (Source_Location : System.Address; Line : Integer) is
   pragma Unreferenced (Source_Location, Line);
begin
   --  TODO: Add in code to dump the info to serial/screen which
   --  is obviously board specific.
   loop
      null;
   end loop;
end Last_Chance_Handler;

library project gnat is
   type Arch_Name is ("i386", "arm");
   type Board_Name is ("pc", "rpi");
 
   Arch  : Arch_Name  := "i386";
   Board : Board_Name := external ("Board");
 
   case Board is
      when "pc" =>
         Arch := "i386";
      when "rpi" =>
         Arch  := "arm";
   end case;
 
   for Source_Dirs use ("rts/boards/" & Arch & "/adainclude");
   for Object_Dir use "obj"; --"rts/boards/" & Arch & "/adalib";
 
   package Builder is
      Basic_Switches := ("-gnat2005", "-g", "-x", "-a", "-gnatg",
			 "-gnatec=../gnat.adc");
 
      case Board is
         when "pc" =>
            for Default_Switches ("Ada") use Basic_Switches &
               ("-m32", "-march=i386");
         when "rpi" =>
            for Default_Switches ("Ada") use Basic_Switches &
               ("-march=armv6zk", "-mfpu=vfp", "-mfloat-abi=hard", "-marm",
                "-mcpu=arm1176jzf-s", "-mtune=arm1176jzf-s");
      end case;
   end Builder;
 
   package Compiler is
      for Default_Switches ("Ada") use ("-O2", "-ffunction-sections", "-fdata-sections");
   end Compiler;
 
   for Library_Kind use "static";
   for Library_Name use "gnat-4.6";
   for Library_Dir use "rts/boards/" & Arch & "/adalib";
end gnat;

gnatmake -XBoard=pc -Pgnat.gpr

.global startup                         # Make the startup entry point symbol visible to the linker
 
# Set up the Multiboot header (see GRUB docs for details)
.set ALIGN,    1<<0                     # Align loaded modules on page boundaries
.set MEMINFO,  1<<1                     # Provide memory map
.set FLAGS,    ALIGN | MEMINFO          # This is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002               # 'magic number' lets your bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS)         # Checksum required
 
header:                                 # Must be in the first 8kb of the kernel file
.align 4, 0x90                          # Pad the location counter (in the current subsection) to a 4-byte
                                        # storage boundary. The way alignment is specified can vary with
                                        # host system architecture.
.long MAGIC
.long FLAGS
.long CHECKSUM
 
# Reserve initial kernel stack space
.set STACKSIZE, 0x4000                  # 0x4000 being 16k.
.lcomm stack, STACKSIZE                 # Reserve 16k stack on a32-bit boundary
.comm  mbd, 4                           # Declare common symbol mbd, allocate it 4-bytes of
                                        # uninitialized memory.
.comm  magic, 4                         # Declare common symbol magic, allocate it 4-bytes of
                                        # uninitialized memory.
 
startup:
    movl  $(stack + STACKSIZE), %esp    # Set up the stack
 
# The following saves the contents of the registers as they will likely be
# overwritten because main is not our actual entry point, Bare_Bones is. We
# will use these 2 symbols inside Bare_Bones.
 
    movl  %eax, magic                   # EAX indicates to the OS that it was loaded by a Multiboot-compliant boot
                                        # loader
    movl  %ebx, mbd                     # EBX must contain the physical address of the Multiboot information
                                        # structure
 
    call  main                          # Call main (created by gnatbind)
 
    cli                                 # Disable interrupts. then intentionally hang the system.
                                        # CLI only affects the interrupt flag for the processor on which it is
                                        # executed.
 
hang:
    hlt                                 # Because the HLT instruction halts until an interrupt occurs, the
                                        # combination of a CLI followed by a HLT is used to intentionally hang
                                        # the computer if the kernel returns.
                                        # HLT is in a loop just in case a single HLT instruction fails to execute
                                        # for some reason, (such as in the case of an NMI).
    jmp   hang
	
with System;
 
package Console is
   pragma Preelaborate (Console);
 
   type Background_Colour is
     (Black,
      Blue,
      Green,
      Cyan,
      Red,
      Magenta,
      Brown,
      Light_Grey);
 
   for Background_Colour use
     (Black      => 16#0#,
      Blue       => 16#1#,
      Green      => 16#2#,
      Cyan       => 16#3#,
      Red        => 16#4#,
      Magenta    => 16#5#,
      Brown      => 16#6#,
      Light_Grey => 16#7#);
 
   for Background_Colour'Size use 4;
 
   type Foreground_Colour is
     (Black,
      Blue,
      Green,
      Cyan,
      Red,
      Magenta,
      Brown,
      Light_Grey,
      Dark_Grey,
      Light_Blue,
      Light_Green,
      Light_Cyan,
      Light_Red,
      Light_Magenta,
      Yellow,
      White);
 
   for Foreground_Colour use
     (Black         => 16#0#,
      Blue          => 16#1#,
      Green         => 16#2#,
      Cyan          => 16#3#,
      Red           => 16#4#,
      Magenta       => 16#5#,
      Brown         => 16#6#,
      Light_Grey    => 16#7#,
      Dark_Grey     => 16#8#,
      Light_Blue    => 16#9#,
      Light_Green   => 16#A#,
      Light_Cyan    => 16#B#,
      Light_Red     => 16#C#,
      Light_Magenta => 16#D#,
      Yellow        => 16#E#,
      White         => 16#F#);
 
   for Foreground_Colour'Size use 4;
 
   type Cell_Colour is
      record
         Foreground : Foreground_Colour;
         Background : Background_Colour;
      end record;
 
   for Cell_Colour use
      record
         Foreground at 0 range 0 .. 3;
         Background at 0 range 4 .. 7;
      end record;
 
   for Cell_Colour'Size use 8;
 
   type Cell is
      record
         Char   : Character;
         Colour : Cell_Colour;
      end record;
 
   for Cell'Size use 16;
 
   Screen_Width  : constant Natural := 80;
   Screen_Height : constant Natural := 25;
 
   subtype Screen_Width_Range  is Natural range 1 .. Screen_Width;
   subtype Screen_Height_Range is Natural range 1 .. Screen_Height;
 
   type Row    is array (Screen_Width_Range)  of Cell;
   type Screen is array (Screen_Height_Range) of Row;
 
   Video_Memory : Screen;
 
   for Video_Memory'Address use System'To_Address (16#000B_8000#);
 
   pragma Import (Ada, Video_Memory);
 
   procedure Put
     (Char       : in Character;
      X          : in Screen_Width_Range;
      Y          : in Screen_Height_Range;
      Foreground : in Foreground_Colour := White;
      Background : in Background_Colour := Black);
 
   procedure Put
     (Str        : in String;
      X          : in Screen_Width_Range;
      Y          : in Screen_Height_Range;
      Foreground : in Foreground_Colour := White;
      Background : in Background_Colour := Black);
 
   procedure Clear (Background : in Background_Colour := Black);
end Console;

package body Console is
   procedure Put
     (Char       : in Character;
      X          : in Screen_Width_Range;
      Y          : in Screen_Height_Range;
      Foreground : in Foreground_Colour := White;
      Background : in Background_Colour := Black) is
   begin
      Video_Memory (Y)(X).Char              := Char;
      Video_Memory (Y)(X).Colour.Foreground := Foreground;
      Video_Memory (Y)(X).Colour.Background := Background;
   end Put;
 
   procedure Put
      (Str        : in String;
       X          : in Screen_Width_Range;
       Y          : in Screen_Height_Range;
       Foreground : in Foreground_Colour := White;
       Background : in Background_Colour := Black) is
   begin
      for Index in Str'First .. Str'Last loop
         Put (Str (Index),
              X + Screen_Width_Range (Index) - 1,
              Y,
              Foreground,
              Background);
      end loop;
   end Put;
 
   procedure Clear (Background : in Background_Colour := Black) is
   begin
      for X in Screen_Width_Range'First .. Screen_Width_Range'Last loop
         for Y in Screen_Height_Range'First .. Screen_Height_Range'Last loop
            Put (' ', X, Y, Background => Background);
         end loop;
      end loop;
   end Clear;
end Console;

with Console; use Console;
 
procedure Bare_Bones is
begin
   Clear;
 
   Put ("Hello, bare bones in Ada.",
        Screen_Width_Range'First,
        Screen_Height_Range'First);
end Bare_Bones;
pragma No_Return (Bare_Bones);

OUTPUT_FORMAT(elf32-i386)

/* Tell the linker which startup code to use, we do this as there is no way to do this (well not easily) from the GNAT tools. */
STARTUP(startup.o)

ENTRY (startup)

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
 
clean:
	-rm obj/* *~ bare_bones
bare_bones.gpr
Place this file in the root directory.

project Bare_Bones is
   type Arch_Name is ("i386", "arm");
   type Board_Name is ("pc", "rpi");
 
   Arch  : Arch_Name  := "i386";
   Board : Board_Name := external ("Board");
 
   -- TODO: Add in a case statement that adds an arch dir to source.
 
   case Board is
      when "pc" =>
         for Source_Dirs use ("src", "src/pc");
      when "rpi" =>
         for Source_Dirs use ("src", "src/rpi");
   end case;
 
   for Object_Dir use "obj";
   for Exec_Dir use ".";
   for Main use ("bare_bones.adb");
 
   package Builder is
      Basic_Switches := ("-gnat2005", "-g", "-x", "-a", "-gnatg",
                         "-gnatec=../gnat.adc", "-gnaty-I", "-gnaty+d");
 
      case Board is
         when "pc" =>
            for Default_Switches ("Ada") use Basic_Switches &
               ("-m32", "-march=i386");
         when "rpi" =>
            for Default_Switches ("Ada") use Basic_Switches &
               ("-march=armv6zk", "-mfpu=vfp", "-mfloat-abi=hard", "-marm",
                "-mcpu=arm1176jzf-s", "-mtune=arm1176jzf-s");
      end case;
   end Builder;
 
   package Compiler is
      case Board is
         when "pc" =>
            for Default_Switches ("Ada") use
               ("-O0", "-g", "-ggdb", "-ffunction-sections", "-fdata-sections");
         when "rpi" =>
            for Default_Switches ("Ada") use
               ("-O0", "-g", "-ggdb", "-ffunction-sections", "-fdata-sections");
 
      end case;
   end Compiler;
 
-- To reduce size of final binary.
   package Linker is
      for Default_Switches ("Ada") use
         ("-Wl,--gc-sections", "-static", "-nostartfiles", "-nodefaultlibs",
          "-T../src/" & Board & "/linker.ld", "-v");
   end Linker;
end Bare_Bones;


git clone git://github.com/gonzoua/u-boot-pi.git
 
cd u-boot-pi
make rpi_b_config

make qemu

