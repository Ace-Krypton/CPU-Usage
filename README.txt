======================================== CPU usage with inline assembly ========================================

By writing a constant value to the MSR and then reading the TSC before and after executing a piece of code, 
you can measure the elapsed time of the code by calculating the difference between the two TSC values.

This approach can be useful for measuring the elapsed time of different pieces of code and comparing their performance. 
By using a constant value for the MSR, you can ensure that the measurements are consistent and accurate.
