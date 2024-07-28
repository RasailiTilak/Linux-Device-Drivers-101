# Chapter 03
` mkdir ldd`<br>
`sudo apt install -y build-essential linux-headers-$(uname -r) kmod`<br>
`make`

after the make or comipled ldd.c generate the ldd.ko which is kernel module this is important to inject to the kernel and verify that kernel is accepted or not.-
- ```modinfo ldd.ko```

### utilites
- ``` sudo insmod ldd.ko``` *(inseert the module)*
- ``` echo $?```(print the previous execution) 
*print(kernel log buffer)to check the module loaded or not*
- ```sudo dmesg```(di message)*```sudo dmesg -c``` (display message and clean)*
*output([11580.802561] hello, world (from Tilak))*
## how to remove the module
- ```sudo rmmod ldd ```(rmmod= remove the module)
*([11747.142273] Goodbye, world (from Tilak))*
- ```modinfo ldd.ko```


## code explanation ldd.c
```sh

#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");//*
MODULE_AUTHOR("TILAK");//!
MODULE_DESCRIPTION("Our First Dynamically Loadable Kernel Module");//!

static int __init tilak_module_init(void){
    printk(KERN_INFO "hello, world (from Tilak)\n");
    return 0;
}

static void __exit tilak_module_exit(void){
    printk(KERN_INFO "Goodbye, world (from Tilak)\n");
}

module_init(tilak_module_init);
module_exit(tilak_module_exit);
```
---
---
```sh
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

```

- when the module inject module (init function)
- when the module exit or relese function(eixt function { clean the memory so on})

- #### init function 
    - int and return  anything with the fucntion name
- #### exit function 
    - void anything with the fucntion name
## Makefile code explanation
```sh
obj-m +=ldd.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```
- kernel comes with build system
    - Makefile
    *(creating the boject ldd.o)*
    ```obj-m +=ldd.o```
    *(two taget make all and make clean)*
    ```all:```
       ``` make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules```
        <br>
        * make(out make call anothher make )-C /lib/modules/$(shell uname -r)/build(changes the woring or execution direcroty to which belong to the kernal)M=$(PWD)(output on the original make dirctory )modules(you suppose to create the modules)*
        example:
        - make or (make all)
                *(make -C /lib/modules/6.8.0-39-generic/build M=/home/ubuntu/ldd modules)*
        make[1]: Entering directory '/usr/src/linux-headers-6.8.0-39-generic'
        warning: the compiler differs from the one used to build the kernel
        The kernel was built by: x86_64-linux-gnu-gcc-13 (Ubuntu 13.2.0-23ubuntu4) 13.2.0
        You are using:           gcc-13 (Ubuntu 13.2.0-23ubuntu4) 13.2.0
        CC [M]  /home/ubuntu/ldd/ldd.o
        MODPOST /home/ubuntu/ldd/Module.symvers
        CC [M]  /home/ubuntu/ldd/ldd.mod.o
        LD [M]  /home/ubuntu/ldd/ldd.ko
        BTF [M] /home/ubuntu/ldd/ldd.ko
        Skipping BTF generation for /home/ubuntu/ldd/ldd.ko due to unavailability of vmlinux
        make[1]: Leaving directory '/usr/src/linux-headers-6.8.0-39-generic'

    ```clean:```<br>
        ```make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean```
        * make(out make call anothher make )-C /lib/modules/$(shell uname -r)/build(changes the woring or execution direcroty to which belong to the kernal)M=$(PWD)(output on the original make dirctory )clean(execute the clean command)*
        example:
        - ```make clean``` 
        *(make -C /lib/modules/6.8.0-39-generic/build M=/home/ubuntu/ldd clean)*
            make[1]: Entering directory '/usr/src/linux-headers-6.8.0-39-generic'
            CLEAN   /home/ubuntu/ldd/Module.symvers
            make[1]: Leaving directory '/usr/src/linux-headers-6.8.0-39-generic'*



    # Chapter 04 (Deep Dive -make and Makefile)
    ## make 
    - make is utility utility 
        -  helps with automation, 
            - execution commands with shell nature  (shell command).
            - example 
                - *```gcc main.c -o main```*<br>
    to reduce multiple file execute , we can do with make is short 
    when we give make command it  will search for the Makefile( which is the buch of recepi ) or *```make -f filename.mk target```*
    ## Makefile or (.mk)  
    when we just *- make* go to the first target *when we speciy the target it will go the target directly(make clean)*  

    - target:____________dependencies(x.c)
    - tab | ---------recepie gcc x.c -o x.o(command 1)
    - tab | ---------recepie gcc x.c -o x.o(command 2)


    ## Using lsmod utitility to list loaded kernel Module
    *(lsmod  confirm the actually loaded or not in to the kernal)*
    - `sudo insmod ldd.ko`(*load the module*)
    - `sudo rmmod ldd` (*unload the module*)
    ###
    - `lsmod `
    - `man lsmod`
    ## insmod, module and the kernel
    `sudo insmod ldd.ko`
    1. call `init_module` to hint the kernel that a module insertion is attempted.
    2. trransfers control to the kernel.
    3. kernel execute `sys_init_module`
    4. verifies permissions
    5. `load_moduule` function is called 
        - checks the sanity of the `.ko`
        - creates memory.
        - copies from user space to kernel space 
        - resolves sysmbols <br>*(means the process by which the linker finds and matches symbol references (like function calls or variable uses) with their actual definitions)*
        - returns a fererence to the kernel
    6. add the referenc to a linked list that has all tthe loaded modules.
    7. `module_init` listed fuction
## rmmod module 
`sudo rmmod ldd`
- this is always perform from the user space 
- `rmmod` calls `delete_module()` which hints the kernel that a module is to be removed.
    - control is transfered to the kernel.
- kernel excecuted `sys_delete_module()`
    - checks the permission of the one requesting 
    - checks if any other loaded module needs the current module.
    - checks if fthe mosule is actually loaded!.
    - Executes the function provided in `module_exit`
    - `free_module()`
        - removes references and kernel object reference.
        - perform any other cleanup.
        - unload the module
        - changes the state in the list
        - removes it from the list and frees the memory

## `modinfo` and the `.mod.c `file
`modinfo`
`modinfo --help`
`modinfo ldd.ko`
