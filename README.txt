===== CPU usage with inline assembly

By writing a constant value to the MSR and then reading the TSC before and after executing a piece of code, 
you can measure the elapsed time of the code by calculating the difference between the two TSC values.

This approach can be useful for measuring the elapsed time of different pieces of code and comparing performance.

By using a constant value for the MSR, you can ensure that the measurements are consistent and accurate.


===== Updates -> Added kernel module, but I have some problems with kernel header so I cannot compile and run this module.
===== HERE ARE STEPS TO COMPILE THE KERNEL MODULE

1 -> Compile the C++ code into a kernel module using the make command and a Makefile. 
  This will create a file with a .ko extension, which stands for kernel object.

2 -> Use the insmod command to insert the module into the kernel. For example:
  "sudo insmod module_name.ko"
  
3 -> Check the kernel log to see if the module was successfully loaded. You can use the dmesg command to view the log:
  "dmesg | tail" -> this requires root access, don't forget the magic word "sudo"

4 -> If you want to unload the module, you can use the rmmod command:
  "sudo rmmod module_name"

5 -> It's also possible to specify additional parameters when loading a kernel module, using the modprobe command. For example:
  "sudo modprobe module_name param1=value1 param2=value2"
  
===== TODO

[X] This program requires to run at ring(0)*
[X] Turn this into kernel module that could elavate the privilege to ring(0)


* Ring(0) is the most privileged level and is usually reserved for the operating system kernel and other critical system components
Code running at ring 0 has complete control over the system and can access all system resources, including memory, devices, and other hardware.
