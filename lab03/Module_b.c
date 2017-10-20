#include <linux/module.h>

extern int symbol_function(int);

int symbol_variable = 56;

int init_module(void){
	printk(KERN_INFO "Module_a inserted successfully.\n");
	printk(KERN_INFO "symbol_function(symbol_variable) = %d\n", symbol_function(symbol_variable));
	return 0;
}
void cleanup_module(void){
	printk(KERN_INFO "Module_a removed successfully.\n");
}

EXPORT_SYMBOL(symbol_variable);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YoYo");
MODULE_DESCRIPTION("Module for OS lab");
