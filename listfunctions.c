#include "linkedlist.h"
Queuepointer init(){
	// initialise the queue pointers
	Queuepointer myqueue;
	myqueue = (Queuepointer) malloc (sizeof(struct queue));
	myqueue -> front = NULL;
	myqueue -> rear   = NULL;
	return myqueue;
}
void add(Queuepointer myqueue){
	printf("Please enter reg no. to add\n>");
	if(myqueue->front == NULL){ // q is empty
		Nodepointer newnode;
		newnode = (Nodepointer) malloc (sizeof(struct node));
		gets(newnode -> value);
		newnode -> next = NULL;
		myqueue -> front = newnode;
		myqueue -> rear  = newnode;
		printf("added to front\n");
	} else {	// add to back
		Nodepointer newnode;
		newnode = (Nodepointer) malloc (sizeof(struct node));
		gets(newnode -> value);
		newnode -> next = NULL;
		myqueue -> rear -> next = newnode;
		myqueue -> rear  = newnode;
		printf("added to rear\n");
	}
}
void depart(Queuepointer myqueue){
	if(myqueue->front != NULL){
		Nodepointer temp;
		printf("%s",myqueue->front->value);
		temp = myqueue->front;
		myqueue->front = myqueue->front->next;
		if (strcmp(temp->value, myqueue->rear->value) ==0){
			myqueue->rear = myqueue->rear->next;
		}
		// or
		/*if (temp->next == myqueue->rear){
			myqueue->rear = myqueue->rear->next;
		}*/
		free(temp);
	} else {
		printf("Empty Queue! No taxis in here!\n");
	}
}
void printFront(Queuepointer myqueue){
	if (myqueue->front != NULL){
		printf("%s is at the front \n",myqueue->front->value);
	} else {
		printf("Empty!\n");
	}
}
void printBack(Queuepointer myqueue){
	if (myqueue->rear != NULL){
		printf("%s is at the back\n",myqueue->rear->value);
	} else {
		printf("Empty!\n");
	}
}
int search(Queuepointer myqueue){
	int count = 1;
	char searchst[MAX_LEN];
	Nodepointer current;
	current = myqueue->front;
	puts("Enter a rego to search for:");
	gets(searchst);
	while (current/*->next*/ != NULL){
		if(strcmp(current->value, searchst) == 0){
			printf("Found %s at location %d (front to back)\n",current->value,count); 
			return 0;// don't waste clock cycles doing the rest if this is found here
		} 
		current = current->next;
		count++;
	}
	// bug fix for the LAST location, isn't covered by the above. will only reach if not found above.
	if (current->value != NULL){
		if(strcmp(current->value, searchst) == 0){
			printf("Found %s at the back location: %d (front to back)\n",current->value,count);
		} else {
			printf("%s not found",searchst); 
		}
	}
	return 1;
}
void isempty(Queuepointer myqueue){
	if (myqueue->front == NULL && myqueue->rear == NULL){
		puts("empty, sorry!");
	} else {
		puts("not empty!");
	}
}
void printqueue(Queuepointer myqueue){
	Nodepointer current;
	current = myqueue->front;
	while (current->next != NULL){
		puts(current->value);
		current = current->next;
	}
	puts(current->value);
}
void menu(){
	printf("1. \"arrive\"\n2. \"depart\"\n3. \"print front\"\n4. \"print back\"\n5. \"search\"\n6. \"print queue\"\n7. \"exit\"\n>");
}