## to load
`struct proc_dir_entry *proc_create(const char *name, umode_t mode, struct proc_dir_entry *parent, const struct proc_ops *proc_ops);`



## to unload 
- `extern void proc_remove(struct proc_dir_entry *);` *(line -125)*


### code 

```
#include <linux/init.h>
#include <linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TILAK");

MODULE_DESCRIPTION("Our First Dynamically Loadable Kernel Module");//!


static struct proc_dir_entry *custom_proc_node;


static int __init tilak_module_init(void){
    printk("tilak_module_init: entry\n");
    custom_proc_node = proc_create("tilak_driver", 
                                    0, 
                                    NULL, 
                                    NULL);
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
```


## In terminal (multipass)
- you must be inside the **ldd** dir
- `ls /procc/` *(no tilak_driver)*
- `make`
- `sudo insmod ldd.ko`
- `lsmod`
if usded by =1
- `sudo dmesg` 




### to remove 
- `sudo rmmod ldd`
- `ls /proc/`
## if now showing anything, now restart the system
- `multipass stop primary` 
- `multipass start primary`


## in the multipass terminal 
- `lsmod`
- `sudo dmesg -c`
- `sudo dmesg`
- `make clean`
- `make`
- `ls /proc/`
- if not showing anything 
    - `sudo insmod ldd.ko`
    - `sudo dmesg`
- lsmod
- ls /proc/
### read this our new driver
- cat /proc/tilak_driver
- echo 1 > /proc/tilak_driver
- sudo echo 1 > /proc/tilak_driver
## to remove 
- sudo rmmod ldd
- ls /proc/
- sudo dmesg
- ls /proc/