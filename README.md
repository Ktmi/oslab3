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
   
# Step 4
Modifed slob_page_alloc to use best fit
 - Put off setting aside space until we determine the best fit
 - Iterate through the whole page until we reach the end
 - Possible best fits are stored as pointers to the locations
 
# Step 5
Could never actually get a kernel I compiled to run on a VM,
not on the provided Centos image, nor the provided ubuntu image,
nor on my own ubuntu VM, nor on my amazon VM.

However, if I ever did get the kernel to compile successfully,
the attached source should be able to report the level
of fragmentation.

# Additional Notes
The version of linux this is written for is 5.4-rc6