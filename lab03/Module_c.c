#include <linux/module.h>

extern int symbol_variable;

module_param(symbol_variable, int, 0);
MODULE_PARM_DESC(symbol_variable, "The symbol exported by Module_b.c.");

int init_module(void){
	printk(KERN_INFO "Module_a inserted successfully.\n");
	printk(KERN_INFO "symbol = %d\n", symbol_variable);
	return 0;
}
void cleanup_module(void){
	printk(KERN_INFO "Module_a removed successfully.\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YoYo");
MODULE_DESCRIPTION("Module for OS lab");
