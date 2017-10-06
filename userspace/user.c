#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <time.h>

#define __NR_sys_my_xtime 326

int main(void)
{
	//int ret = syscall(__NR_sys_my_xtime);
	//printf("ret=%d errno=%d \n",ret,errno);
	struct timespec  t;
	t.tv_sec = -1;
	t.tv_nsec = -1;
	printf("BEFORE SYSCALL: Current Time =  %ld seconds and %ld nanoseconds \n", t.tv_sec, t.tv_nsec); 
	int ret = syscall(__NR_sys_my_xtime, &t);
	printf("AFTER SYSCALL: Current Time =  %ld seconds and %ld nanoseconds \n", t.tv_sec, t.tv_nsec); 
	printf("ret=%d errno=%d \n",ret,errno);

//	USED TO FIGURE OUT SIZE OF FILLED TIMESPEC

//	t.tv_sec = 10000;
//	t.tv_nsec = 888;
//	printf("Size of timespec: %ld ", sizeof(*t)); 

	return 0;
}
