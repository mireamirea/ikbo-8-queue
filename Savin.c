#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



#define MAX 20


struct queue {
	
	int data[MAX];
	int top;
	
};


void init (struct queue *que);
void push (struct queue *que, int a);
int pop (struct queue *que);
int peek (struct queue *que);
int isEmpty (struct queue *que);
void quePrint (struct queue *que);



int main () {
	
	struct queue que;
	
	init(&que);
	
	
	/* Test */
	
	push(&que,10);
	push(&que,-4);
	push(&que,22);
	pop(&que);
	push(&que,0);
	quePrint(&que);
 	
	
	return 0;
}



/* Initialization queue */

void init(struct queue *que) {

  que->top = 0;

}


/* Push element on top queue */

void push(struct queue *que, int a) {
	
	if (que->top < MAX) {
		
		que->data[que->top] = a;
		que->top++;
		
		printf("Element %d pushed. \n\n", a);
	}
	
	else {
		printf("Queue is full, amount of elements: %d \n\n", que->top);
	}
 
}



/* Delete element from top queue */

int pop(struct queue *que) {
	
	int i;
	
    if (que->top > 0) {
        
        que->top--;
        printf("Element %d deleted. \n\n", que->data[0]);
        
        for (i = 0; i < que->top; i++) {
        	
        	que->data[i] = que->data[i + 1];
        	
		}
        
        return que->data[que->top];
	}
    
    else {
    	
    	printf("Queue is empty! \n\n");
    	return 0;
	}
	
}



/* Returns the current element */

int peek(struct queue *que) {
	
	if (que->top > 0) {
		
		return que->data[0];
	}
	
	else {
		
		printf("Queue is empty! \n\n");
		return 0;
	}
	
}



/* Checking stack on emptiness */

int isEmpty(struct queue *que) {
	
	if (que->top == 0) {
		return 1;
	}
	
	else {
		return 0;
	}
	
}



/* Printing */

void quePrint(struct queue *que){
	
	int i, j = 0;
	
	i = que->top;
	if (isEmpty(que) == 1) {
		
		printf("Queue is empty! \n");
		return;
	}
	
	do {
		
		if (j == 0) {
			printf("Outputting elements queue: \n");
			j++;	
		}
		
		i--;
		printf("Element %d: ", i + 1);
		printf("%d\n", que->data[i]);
		
	} while (i>0);
	
}



