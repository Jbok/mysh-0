#include <stdio.h>
#include <string.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int length = strlen(command);
	
	char buffer[8096]; //char array temporary save word
	strcpy(buffer,command); //save string
	
	buffer[length-1]='\0'; //remove '\n' end of line


	int wordcount=0;
	char *wordArray[8096]={};//string array temporary save words

	char *ptr=strtok(buffer," ");//pointer of word divided by " "
	
	while(ptr!=NULL){
		wordArray[wordcount++]=ptr;
		ptr=strtok(NULL," ");
	}

	*argv=wordArray;
	*argc=wordcount;
}
