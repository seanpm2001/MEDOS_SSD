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