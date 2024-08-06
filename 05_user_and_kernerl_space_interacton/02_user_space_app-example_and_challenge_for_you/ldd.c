#include <linux/init.h>
#include <linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TILAK");

MODULE_DESCRIPTION("Our First Dynamically Loadable Kernel Module");//!


static struct proc_dir_entry *custom_proc_node;

// implementing the read operation 
//ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);
// TO SEND THE DATA FROM KERNEL SPACE TO USER SPACE 
static ssize_t	tilak_read(struct file * file_pointer,//(input parameter are pupulated by the kernel)
                    char * user_space_buffer, // (user-space will read this bufffer)
                    size_t count,
                    loff_t * offset){// use of offset in the input/output , keep track TO STOP PRINTING FOREVER

// to implement the messag we need string 
    char msg[]= "Ack!\n";
    // give the lenght of the message  unsigned int 
    size_t len=strlen(msg);
    // for the return value
    int result;
     printk("tilak _read\n");

    // fitst chek the off set 
    if(*offset>=len)
        return 0;
    


    // now write in to the buffer we will use API (copt-to_user(destination, source, number_of_bytes))
    //copy_to_user(dst, src, no_of_bytes) 
    //capture the return values in the variable resutl
    result=copy_to_user(user_space_buffer, msg, len);


// UPDATE offset by the len
    *offset+=len;
    


   

    // here we have to return the number of the bytes insted of te 0
   //return 0;
   return len;
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