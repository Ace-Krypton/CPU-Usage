======================================== CPU usage with inline assembly ========================================

By writing a constant value to the MSR and then reading the TSC before and after executing a piece of code, 
you can measure the elapsed time of the code by calculating the difference between the two TSC values.

This approach can be useful for measuring the elapsed time of different pieces of code and comparing performance.

By using a constant value for the MSR, you can ensure that the measurements are consistent and accurate.


================================================== TODO =======================================================
[ ] This program requires to run at ring(0)*
[ ] Turn this into kernel module that could elavate the privilege to ring(0)


* Ring(0) is the most privileged level and is usually reserved for the operating system kernel and other critical system components
Code running at ring 0 has complete control over the system and can access all system resources, including memory, devices, and other hardware.
