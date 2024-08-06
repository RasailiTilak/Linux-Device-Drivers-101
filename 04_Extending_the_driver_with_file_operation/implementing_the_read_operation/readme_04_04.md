# implement the read operation 
`ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);`

##  first create the driver 
- make clean
- make 
- lsmod
- sudo dmesg
- ls /proc/
##  now read 
- cat /proc/tilak_driver
- sudo dmesg
