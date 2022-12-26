CPU USAGE CALCULATOR WITH INLINE ASSEMBLY

By writing a constant value to the MSR and then reading the TSC before and after executing a piece of code, 
you can measure the elapsed time of the code by calculating the difference between the two TSC values.
This approach can be useful for measuring the elapsed time of different pieces of code and comparing performance.
By using a constant value for the MSR, you can ensure that the measurements are consistent and accurate.


HERE ARE STEPS TO COMPILE THE KERNEL MODULE

Compile the C++ code into a kernel module using the make command and a Makefile. 
  This will create a file with a .ko extension, which stands for kernel object.

Use the insmod command to insert the module into the kernel. For example:
  "sudo insmod module_name.ko"
  
Check the kernel log to see if the module was successfully loaded. You can use the dmesg command to view the log:
  "sudo dmesg | tail"

If you want to unload the module, you can use the rmmod command:
  "sudo rmmod module_name"

It's also possible to specify additional parameters when loading a kernel module, using the modprobe command. For example:
  "sudo modprobe module_name param1=value1 param2=value2"
  
  
TODO

[X] This program requires to run at ring(0)*
[X] Turn this into kernel module that could elavate the privilege to ring(0)


* Ring(0) is the most privileged level and is usually reserved for the operating system kernel and other critical system components
Code running at ring 0 has complete control over the system and can access all system resources, including memory, devices, and other hardware.


[DISCLAIMER]

Loading your own kernel module can be dangerous for a number of reasons.

Instability: A kernel module that is not properly written or tested can cause the system to become unstable or even crash.

Security vulnerabilities: A kernel module that contains security vulnerabilities can compromise the security of the system.

Compatibility issues: A kernel module that is not compatible with the version of the kernel that is running on the system can cause issues or even prevent the system from booting.

System resources: A kernel module that consumes a large amount of system resources, such as memory or CPU time, can negatively impact the performance of the system.

~In general, it is best to avoid loading your own kernel modules unless you are an experienced user who is familiar with the risks and knows how to properly write and test kernel modules.
