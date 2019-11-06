# Step 3
Instrumented the code.
 - Added 2 arrays to slob.c
   - slob_amt_free
   - slob_amt_claimed
 - Whenever the if(!b) is executed
   - and the slob_list is free_slob_small
     - add the free amount of bytes we couldn't use to a temp variable
	 - results are recorded to array at end of slob_alloc
 - Results are accessible
   - sys_get_slob_amt_free assigned to syscall(437)
   - sys_get_slob_amt_claimed assigned to syscall(436)
   
Instrumented slob_alloc, to record fragmentation for small
allocations. At the if (!b) after b = slob_page_alloc
has been called, the system will add the amount of
free bytes in the called page to a temporary variable,
temp_amt_free.
After the routine is done, we check if we were using
the free_slob_small list, and if so, we stored
our gathered statistics in global arrays.
The value from temp_amt_free is stored in the
amt_free array, and the value from size is stored
in amt_claimed.
   
# Step 4
Modifed slob_page_alloc to use best fit
 - Put off setting aside space until we determine the best fit
 - Iterate through the whole page until we reach the end
 - Possible best fits are stored as pointers to the locations

Modified slob_page_alloc() to use best fit algorithm.
Rather than immediately allocating when a fit is found,
the system now stores the location of the first available
fit, then compares that with the next available fit.
If the next available fit is a better fit, then
that is stored instead. The system continues to do this
until the list of possible fits has been exhausted.
Once all possible fits are exhausted, and a best
available fit has been found, the system runs the allocation
algorithm on the best possible fit.
 
# Step 5
Could never actually get a kernel I compiled to run on a VM,
not on the provided Centos image, nor the provided ubuntu image,
nor on my own ubuntu VM, nor on my amazon VM.

However, if I ever did get the kernel to compile successfully,
the attached source should be able to report the level
of fragmentation.

# Additional Notes
The version of linux this is written for is 5.4-rc6