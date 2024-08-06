def main():
    #print("hello world")
    # we want to open prop file from here and write 
    driver_handle= open('/proc/tilak_driver')
    message_from_kernel_space=driver_handle.readline()
    print(f'here is the message from KERNEL', message_from_kernel_space)
    driver_handle.close()    

    return
main()