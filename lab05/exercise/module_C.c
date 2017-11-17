#include <linux/module.h>	/*Need by all modules*/

extern int symbol_var;

module_param(symbol_var, int , 0);
MODULE_PARM_DESC(symbol, "Variable");


int init_module(void)
{
	printk(KERN_INFO "Module_B inserts successfully\n");
	printk(KERN_INFO "symbol_var:%d\n",symbol_var);
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Module_B removes successfully\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");


