#include "linkedlist.h"
int main(){
	char switchy[100];
	Queuepointer myqueue = init();
	puts("Welcome to the taxi rank, taxi registrations can be 20 chars long");
	menu();
	gets(switchy);
	do{
		menu();
		if(strcmp(switchy,"arrive") == 0){
			add(myqueue);
		} else if (strcmp(switchy,"depart") == 0){
			depart(myqueue);
		} else if (strcmp(switchy,"print front") == 0){
			printFront(myqueue);
		} else if (strcmp(switchy,"print back") == 0){
			printBack(myqueue);
		} else if (strcmp(switchy,"search") == 0){
			search(myqueue);
		} else if (strcmp(switchy,"check empty") == 0){
			isempty(myqueue);
		} else if (strcmp(switchy,"print queue") == 0){
			printqueue(myqueue);
		} else if (strcmp(switchy,"exit") == 0){
			printf("Hit enter to exit, Goodbye!");
			getchar(); // wait before exit
			exit(0);
		} else {
			printf("Error, try again and be explicit.\n");
		}
		gets(switchy);
	} while (switchy[0] != 0);
	return 0;
}
