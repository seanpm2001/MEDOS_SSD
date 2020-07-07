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