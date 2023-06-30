#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int value;
	int index;
	int family;
	struct stack *next;
} t_stack;

void assignFamilyNumbers(t_stack *head, int *sortedArray, int arraySize) {
	int familyNumber = 0;
	int *familyMapping = (int *)malloc(sizeof(int) * arraySize);

	for (int i = 0; i < arraySize; i++) {
		if (i > 0 && sortedArray[i] - sortedArray[i - 1] > 1) {
			familyNumber++;
		}
		familyMapping[sortedArray[i]] = familyNumber;
	}

	t_stack *current = head;
	while (current != NULL) {
		current->family = familyMapping[current->value];
		current = current->next;
	}

	free(familyMapping);
}

int main() {
	// Assuming the linked list is already created and populated with values.
	// Also assuming the sorted array is available.

	t_stack *head = NULL;  // Initialize head of the linked list

	// Code to populate the linked list goes here...

	int sortedArray[] = { 1, 2, 4, 5, 7, 8, 9, 10, 12 };
	int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);

	assignFamilyNumbers(head, sortedArray, arraySize);

	// Now each node in the linked list should have its corresponding family number assigned.
	printf("fam: %d\n", head->family);
	while (head) {
		head = head->next;
	}
	return 0;
}
