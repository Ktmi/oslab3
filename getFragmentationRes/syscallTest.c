#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

#define SYS_get_slob_amt_claimed 436
#define SYS_get_slob_amt_free 437

int main()
{
	printf("Amount claimed: %d", syscall(SYS_get_slob_amt_claimed));
	printf("Amount free: %d", syscall(SYS_get_slob_amt_free));
	return 0;
}