#include <linux/init.h>
#include <linux/module.h>
// macros  from above  header files
// this license is very importat 
MODULE_LICENSE("GPL");//*
// this authero is optional 
MODULE_AUTHOR("TILAK");//!
// this Description  is optional 
MODULE_DESCRIPTION("Our First Dynamically Loadable Kernel Module");//!
// c function constructor 
static int __init tilak_module_init(void){
    printk(KERN_INFO "hello, world (from Tilak)\n");
    return 0;
}
// c function distruction
static void __exit tilak_module_exit(void){
    printk(KERN_INFO "Goodbye, world (from Tilak)\n");
}
// cmacros! from above  header files
// this is to enter or inject 
module_init(tilak_module_init);
//this is exit and relasee
module_exit(tilak_module_exit);

