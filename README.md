# OS-Assingment2
Adding our own system call in linux kernel (v5.9)
# Problem Statement
Create your own system call in C, called sh_task_info(), which takes argument as PID. It would need to search out the task_struct() corresponding to the PID and print out all the fields corresponding to it and also save it in a file. The file name also needs to be supplied as an argument to the system call. Handle errors in user inputs, such as incorrect arguments, through appropriate errno and function return values.
# Solution
In order to write our own system call, we have to follow certain steps as explained, then we will use test.c to check our own system call.sh_task_info syscall entry is first added in arch/x86/entry/syscalls/syscall_64.tbl then the function is declared in kernel/sys.c which takes two arguments PID of the process and full file name (with path) where the output should be stored.first the file name is stored in buf using strncpy_from_user as the file name was in reference to userspace and should not directly be used in kernel space.Then using find_task_by_vpid function we get the task_struct corresponding to a given PID (if it exists).then the corresponding 6 field values are stored in data. Using flip_open a new or existing file is opened and kernel_write writes data into the file is closed using filp_close after manipulating.now that the syscall is ready we need to compile it and install modules so that we can use it in userspace. For this we used commands
sudo make -j 4 && sudo make modules_install install -j 4 && sudo reboot -f 
after this, our syscall is ready to be used In test.c we call sh_task_info with arguments using
syscall(548, PID,file_name);
After processing syscall is ready to be tested using test.c explained in the following sections
