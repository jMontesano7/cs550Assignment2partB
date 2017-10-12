#include <linux/init.h>
#include <linux/module.h>
#include <linux/linkage.h>
#include <linux/time.h>
#include <linux/uaccess.h>

//MODULE_LICENSE("DUAL BSD/GPL");

asmlinkage int sys_my_xtime(struct timespec *current_time)
{
	struct timespec buff;
	//printk(KERN_ALERT "my_xtime: my_xtime was called!\n");

	if(copy_from_user(&buff, current_time, sizeof(buff)))
	{
		printk(KERN_ALERT "my_xtime: COPY FROM USER FAILURE!\n");
		return -EFAULT;
	}
	buff = current_kernel_time();
	if(copy_to_user(current_time, &buff, sizeof(buff)))
	{
		printk(KERN_ALERT "my_xtime: COPY TO USER FAILURE!\n");
		return -EFAULT;
	}
	printk(KERN_ALERT "my_xtime: %ld \n", buff.tv_nsec);
	return 0;
}

//EXPORT_SYMBOL(sys_my_xtime);

