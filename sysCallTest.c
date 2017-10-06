#include <linux/init.h>
#include <linux/module.h>
#include<linux/linkage.h>

MODULE_LICENSE("DUAL BSD/GPL");

// called when module is installed
int __init init_module()
{
	printk(KERN_ALERT "my_xtime: Oh you know its in there my friend!\n");

	return 0;
}

asmlinkage int sys_my_xtime(struct timespec *current_time)
{
	printk(KERN_ALERT "my_xtime:Oh great job calling the system call boooop!\n");
	return -EFAULT;
}



// called when module is removed
void __exit cleanup_module()
{
	printk(KERN_ALERT "my_xtime: im out bud!!\n");
}

