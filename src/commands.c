#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
	if (!validate_cd_argv(argc, argv))
		return -1;
 	
	chdir(argv[1]);
	return 0;
}

int do_pwd(int argc, char** argv) {
	if (!validate_pwd_argv(argc, argv))
		return -1;

	char currentDir[8096];
	getcwd(currentDir,8096);
	printf("%s\n",currentDir);
	return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if(argc==2 && !strcmp(*argv,"cd"))
		return 1;
	else
		return 0;
}

int validate_pwd_argv(int argc, char** argv) {
	if(argc==1 && !strcmp(*argv,"pwd"))
		return 1;
	else
		return 0;
}
