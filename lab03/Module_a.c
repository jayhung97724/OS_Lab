#include <linux/module.h>

int symbol_function(int x){
	if(x > 100){
		return 1;
	}else if(x == 100){
		return 0;	
	}else {
		return -1;	
	}
}

int init_module(void){
	printk(KERN_INFO "Module_a inserted successfully.\n");
	return 0;
}
void cleanup_module(void){
	printk(KERN_INFO "Module_a removed successfully.\n");
}

EXPORT_SYMBOL(symbol_function);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YoYo");
MODULE_DESCRIPTION("Module for OS lab");