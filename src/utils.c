#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int length = strlen(command);
	
	char buffer[8096]; //char array temporary save word
	strcpy(buffer,command); //save string
	
	if(buffer[length-1]=='\n'){
		buffer[length-1]='\0'; //remove '\n' end of line
	}

	int wordcount=0;
	char *wordArray[8096]={""};//string array temporary save words

	char *ptr=strtok(buffer," ");//pointer of word divided by " "
	
	while(ptr!=NULL){
		if(strcmp(ptr,"\n")!=0 && strcmp(ptr,"\t")!=0){
			wordArray[wordcount++]=ptr;
		}
		ptr=strtok(NULL," ");
	}

	//if there is no word add "\0" and wordcount=1
	if(wordcount==0){
		wordcount=1;
	}
	
	//2D dynamic allocate
	*argv=(char**)malloc(sizeof(char*)*wordcount);
	for(int i=0;i<wordcount;i++){
		*((*argv)+i)=(char*)malloc(sizeof(char)*length);
		strcpy(*((*argv)+i),wordArray[i]);
	}

	*argc=wordcount;
}
