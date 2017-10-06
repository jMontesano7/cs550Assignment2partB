#include <linux/init.h>
#include <linux/module.h>
#include<linux/linkage.h>

//MODULE_LICENSE("DUAL BSD/GPL");

asmlinkage int sys_my_xtime(struct timespec *current_time)
{
	printk(KERN_ALERT "my_xtime: my_xtime was called!\n");
	return -EFAULT;
}

//EXPORT_SYMBOL(sys_my_xtime);

