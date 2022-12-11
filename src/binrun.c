//binrun.c

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{

	int cmd_len = strlen(argv[1]) + 42;
	char command[cmd_len];

	//initialise variable char array to 0;
	for(int j = 0; j < cmd_len; j++) {
	command[j] = 0;
	}

	strcat(command, "cp ");
	strcat(command, argv[1]);
	strcat(command, " /data/data/com.termux/files/home/");

	system(command);

	
}
