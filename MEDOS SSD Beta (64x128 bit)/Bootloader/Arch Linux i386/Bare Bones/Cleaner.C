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