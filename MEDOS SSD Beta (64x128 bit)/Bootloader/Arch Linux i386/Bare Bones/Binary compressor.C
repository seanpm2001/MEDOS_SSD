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

