#include <linux/init.h>
#include <linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TILAK");

MODULE_DESCRIPTION("Our First Dynamically Loadable Kernel Module");//!


static struct proc_dir_entry *custom_proc_node;
struct proc_ops driver_proc_ops ={};

static int __init tilak_module_init(void){
    printk("tilak_module_init: entry\n");
    custom_proc_node = proc_create("tilak_driver", 
                                    0, 
                                    NULL, 
                                    &driver_proc_ops);
    printk("tilak_module_init: exit\n");
    
    return 0;
}
// c function distruction
static void __exit tilak_module_exit(void){
   // extern void proc_remove(struct proc_dir_entry *);
   printk("tilak_module_exit: entry\n");
   proc_remove(custom_proc_node);
   printk("tilak_module_exit: exit\n");
    
}


// struct proc_dir_entry *proc_create(const char *name, 
//                                     umode_t mode, 
//                                     struct proc_dir_entry *parent, 
//                                     const struct proc_ops *proc_ops);

// custom_proc_node *proc_create("tilak_driver", 
//                                     0, 
//                                     NULL, 
//                                     NULL);
module_init(tilak_module_init);
module_exit(tilak_module_exit);