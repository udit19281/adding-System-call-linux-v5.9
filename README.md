# Adding System call in linux kernel v5.9

# Problem Statement
Create your own system call in C, called sh_task_info(), which takes argument as PID. It would need to search out the task_struct() corresponding to the PID and print out all the fields corresponding to it and also save it in a file. The file name also needs to be supplied as an argument to the system call. Handle errors in user inputs, such as incorrect arguments, through appropriate errno and function return values.

