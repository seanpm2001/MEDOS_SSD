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