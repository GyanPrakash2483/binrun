#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <resetstring.h>

int main(int argc, char** argv)
{
//get current working directory
	char cwd[128] = {0};
	getcwd(cwd, 128);

//check if an input file is provided
	if(!argv[1]){
	printf("binrun: \x1B[31merror: \x1B[0mno input file\n");
	exit(1);
	}

//check if the file exists
	char file[128] = {0};
	strcat(file, cwd);
	strcat(file, "/");
	strcat(file, argv[1]);
	if(!(access(file, F_OK) == 0)) {
		printf("binrun: \x1B[31merror: \x1B[0mfile: %s not found\n", file);
		exit(1);
	}

//64 is calculated to be enough to fit hardcoded perimeters
	int cmd_len = 64;

//set length of char array to accomodate arguments provided

	for(int i = 1; i < argc; i++) {
		cmd_len += strlen(argv[i]);
	}
	cmd_len += strlen(cwd);

	char command[cmd_len];

	system("mkdir -p /data/data/com.termux/files/home/.binrun/");	//create the directory if it does not already exist.

	resetstring(command, cmd_len);

	strcat(command, "cp ");
	strcat(command, cwd);
	strcat(command, "/");
	strcat(command, argv[1]);
	strcat(command, " /data/data/com.termux/files/home/.binrun/executable");

	system(command);	//copy the executable file to data directory so that it can have exec permission

	system("chmod +x /data/data/com.termux/files/home/.binrun/executable");	//make the file executable

	resetstring(command, cmd_len);
	strcat(command, "/data/data/com.termux/files/home/.binrun/executable");

//add arguments
	for(int i = 2; i < argc; i++){
		strcat(command, " ");
		strcat(command, argv[i]);
	}

	system(command);	//Run the executable

	system("rm /data/data/com.termux/files/home/.binrun/executable");	//delete the copy of file

	return 0;
}
