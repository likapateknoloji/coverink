/*
 *Likapa System Call Deneme Kodu
 * Hell Yeah	
 * 
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char command[50];

	strcpy(command, "gnome-terminal -x sh -c 'cc system.c;./a.out; bash'");
	system(command);
	sleep(3);
	strcpy(command, "sudo obexpushd -B -n");
	system(command);
	
	
	return 0;
}

