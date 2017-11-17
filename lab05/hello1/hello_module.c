#include <linux/module.h> /*Needed by all modules*/

int init_module(void){
	printk(KERN_INFO "Hello module inserts successfully\n");	//KERN_INFO = information

	/*
	 * A non 0 return means init_module failed; module can;t be loaded.
	 */
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Hello module removes successfully.\n");
}

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

