#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_LEN 21
typedef struct node *Nodepointer; // Nodepointer is a new type
typedef struct queue *Queuepointer; // Queuepointer is a new type
struct node { //  defined globally
	char value[MAX_LEN];
	struct node *next;
};
typedef struct node *Nodepointer;  //  new type
struct queue { //  defined globally
	Nodepointer front;
	Nodepointer rear;
};
typedef struct queue *Queuepointer; // new type
Queuepointer myqueue; //  myqueue is local variable

// prototypes
Queuepointer init();
void add(Queuepointer myqueue);
void isempty(Queuepointer myqueue);
void depart(Queuepointer myqueue);
void menu();
void printFront(Queuepointer myqueue);
void printBack(Queuepointer myqueue);
void printqueue(Queuepointer myqueue);
int search(Queuepointer myqueue);