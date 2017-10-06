#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <linux/unistd.h>

#define __NR_sys_my_xtime 326

int main(void)
{
	int ret = syscall(__NR_sys_my_xtime);
	printf("ret=%d errno=%d \n",ret,errno);
	return 0;
}
