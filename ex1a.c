#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char *argv[])
	{
		int pid;
		pid = fork();
		if(pid==-1){
			printf("Error opening Process\n");
			exit(1);
		}
		else if(pid!=0){
			pid = getpid();
			printf("The parent process ID is %d \n",pid);
		}
		else{
			pid = getpid();
			printf("The child process ID is %d \n", pid);
		}
		return 0;

	}	
