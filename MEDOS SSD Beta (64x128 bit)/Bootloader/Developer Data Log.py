password1 = str
print ("Developer data and logs for MEDOS")
print ("This file is password protected")
print ("To get the password, search the web, or open this file with a program like notepad++, notepad, python 3.6, and other programs that can open Python 3.6 files")
print ("You can also read the info through the file itself without entering the password if needed")
password1 = str(input("Please enter the 16 digit password:"))
if password1 == ("DEVBOOT64256128X"):
	print ("Developer log")
	print ("Bootloader part 1 - August 21st 2018 code | B1021")
codeinp = str(input("Please fill in the code here to enter a log data board:"))
if codeinp == ("B1021"):
	print ("Bootloader part 1 | August 21st 2018")
	print ("The bootloader is one of the first projects we are going to work on. Since python is a 32 bit program, and doesn't offer much for advanced versions of our operating system, we are going to have to use a different language for the 64 bit SSD version, and the 64 bit HDD version. The max stats for the 32 bit HDD version are: 4 Gigabytes per second and 2 Terabytes storage space. Obviously, that isn't going to stand in the future for modern systems, but it will work fine for virtual machines! The 64 bit HDD version will max out at 256 gigabytes per second and a max of 16 terabytes of disk space, since that is the max an HDD can go to.")
	print ("For this program, we are making a special bootloader. 32 bit, 8 bit, 16 bit, and 4 bit versions will be command-line only, however the 64 bit versions will boot through command line, then have the option to stay command line or go to a graphical user interface, since they are allotted a lot more memory. For this bootloader, we will be using the ' language. The bootloader will have a 5 second timer for the time you can press any key to boot into the bios, then it will go to a settings page that has the following options:")
	print ("[0] Live DVD mode")
	print ("[1] Install/reinstall")
	print ("[2] Safe mode")
	print ("[3] Fail-safe mode")
	print ("[4] Check for errors")
	print ("[5] Mount/unmount")
	print ("[6] Define system")
	print ("[7] Restart")
	print ("[8] Shut down")
	print ("[9] Sleep")
	print ("Those options will stay up until an input is given. Then it will boot into one of the options, and have a command line/GUI choice, for options 0, 1, 2, 3, 4, and 6")
	print ("That is all the info I have for now - Sean Patrick Myrick")
testconfirm = int(input("Did the command info look right? type 1 to confirm, type anything else and/or press enter to quit "))
if testconfirm == 1:
    print ("Test successful!")
    print ("Shutting down, please wait")
else:
    print ("Shutting down")
   