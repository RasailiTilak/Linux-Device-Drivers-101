#include <linux/init.h>
#include <linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TILAK");

MODULE_DESCRIPTION("Our First Dynamically Loadable Kernel Module");//!


static struct proc_dir_entry *custom_proc_node;

// implementing the read operation 
//ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);
static ssize_t	tilak_read(struct file * file_pointer,
                    char * user_space_buffer, 
                    size_t count,
                    loff_t * offset){
    printk("tilak _read\n");
    return 0;
};

struct proc_ops driver_proc_ops ={
    //for the implementation 
    .proc_read=tilak_read
};

static int __init tilak_module_init(void){
    printk("tilak_module_init: entry\n");
    custom_proc_node = proc_create("tilak_driver", 
                                    0, 
                                    NULL, 
                                    &driver_proc_ops);

    if (custom_proc_node==NULL){
        printk("tilak_module_init: Error\n");
        return -1;
    }
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