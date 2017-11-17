#include <linux/module.h>	/*Need by all modules*/


extern int symbol_var;
extern int symbol_fun(int);

int init_module(void)
{
	printk(KERN_INFO "Module_B inserts successfully\n");
	printk(KERN_INFO "symbol_var:%d\n",symbol_var);

	printk(KERN_INFO "symbol_function(100) = %d\n",symbol_fun(100));
	printk(KERN_INFO "symbol_function(0) = %d\n",symbol_fun(0));
	printk(KERN_INFO "symbol_function(-100) = %d\n",symbol_fun(-100));
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Module_B removes successfully\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");


