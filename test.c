/* Name: Udit Bhati
   Roll_Number: 2019281*/
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int pid;
	printf("Enter PID : ");
	scanf("%d",&pid);
	char str[500];
	printf("Enter file name : ");
	scanf("%s",str);

		pid_t t=(pid_t)pid;
		char *aa=str;
		long int b=syscall(548,t,aa);

			if(b==0){
				printf("\nSyscall exited normally with status 0 \nCheck dmesg for more info \n\n");
				printf("Printing file : %s \n\n",aa);
				FILE *file; char *line=NULL; size_t len=0; ssize_t read;
				file=fopen(aa,"r");
				if(file==NULL){
					printf("Error while reading file \n");
					return -1;
							}
				while((read=getline(&line,&len,file))!=-1){
					printf("%s",line);
					}
				
				fclose(file);
				}
		else{
			printf("An Error occurred Check dmesg for more info \n");
			perror("Error ");
			printf("Error no : %d \n",errno);
	 		return 0;
		}
	
	
}

