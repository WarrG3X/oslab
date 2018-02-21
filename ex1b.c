#include<stdio.h>
#include<dirent.h>

struct dirent *dptr; //Stores FileID, Name
int main(int argc,char *argv[]){

	DIR *dirp; //Directory Stream
	char dir_name[100];
	
	printf("Enter Dir Name - \n");
	scanf("%s",dir_name);

	if((dirp=opendir(dir_name))==NULL){
		printf("Directory Doesn't Exist\n");
	}
	else{
		while(dptr=readdir(dirp))
			printf("%s \n",dptr->d_name);
	}

	return 0;
	}
