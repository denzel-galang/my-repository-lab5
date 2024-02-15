#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
	int counter = 0;
	struct node* temp = head;

	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	
	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function will return "abc"
char* toCString(node* head){
	char* result = (char*)malloc(sizeof(char) * (length(head)+ 1));
	if (result == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	int counter = 0;
	struct node* temp = head;

	while (temp != NULL) {
		result[counter] = temp->letter;
		counter++;
		temp = temp->next;
	}

	result[counter] = '\0';
	
	return result;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	struct node* newChar = (struct node*)malloc(sizeof(struct node));
	newChar->letter = c;
	newChar->next = NULL;

	if (*pHead == NULL) {
		*pHead = newChar;
		return;
	}

	struct node* temp = *pHead;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newChar;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	if (*pHead == NULL) {
		return;
	}

	struct node* temp = *pHead;
	struct node* nextNode;

	while (temp->next != NULL) {
		nextNode = temp->next;
		free(temp);
		temp = nextNode;
	}

	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}