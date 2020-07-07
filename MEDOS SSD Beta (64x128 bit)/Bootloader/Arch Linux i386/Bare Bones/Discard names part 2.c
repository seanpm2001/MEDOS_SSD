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
	 