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
	char die[50];
	
	
	
	strcpy(die, "sudo pkill -9 bluetoothd");
	system(die);
	strcpy(command, "ps auwx | grep blue");
	system(command);
	
	
	strcpy(die, "sudo pkill -9 obex-da");
	system(die);
	
	strcpy(command, "ps auwx | grep obex-da");
	system(command);
	strcpy(command, "sudo bluetoothd --compat");
	system(command);
	//system("gnome-terminal --hold -e ls .");
	//strcpy(command, "sudo obexpushd -B -n");
	//system(command);
	
	
	return 0;
}

