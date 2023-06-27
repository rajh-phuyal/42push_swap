#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack
{
	int value;
	int index;
	int family;
	struct stack *next;
} t_stack;

void assignSiblings(t_stack *head)
{
	// Step 1: Find min and max odd/even values
	int minOdd = INT_MAX;
	int maxOdd = INT_MIN;
	int minEven = INT_MAX;
	int maxEven = INT_MIN;

	t_stack *current = head;
	while (current != NULL)
	{
		int value = current->value;
		if (value % 2 == 0) // even
		{
			if (value < minEven)
				minEven = value;
			if (value > maxEven)
				maxEven = value;
		}
		else // odd
		{
			if (value < minOdd)
				minOdd = value;
			if (value > maxOdd)
				maxOdd = value;
		}

		current = current->next;
	}

	// Step 2: Determine the number of families for odd and even numbers
	int numOddFamilies = (maxOdd - minOdd + 1) / 2;
	int numEvenFamilies = (maxEven - minEven + 1) / 2;

	// Step 3: Assign siblings based on the values
	current = head;
	while (current != NULL)
	{
		int value = current->value;

		if (value % 2 == 0) // even
		{
			int family = (value - minEven) / 2;
			current->family = numOddFamilies + family;
		}
		else // odd
		{
			int family = (value - minOdd) / 2;
			current->family = family;
		}

		current = current->next;
	}
}

// Example usage
int main()
{
	t_stack node1 = {-1, 1, -1, NULL};
	t_stack node2 = {-35, 2, -1, NULL};
	t_stack node3 = {4, 3, -1, NULL};
	t_stack node4 = {3, 4, -1, NULL};
	t_stack node5 = {0, 5, -1, NULL};
	t_stack node6 = {1, 6, -1, NULL};
	t_stack node7 = {6, 7, -1, NULL};
	t_stack node8 = {7, 8, -1, NULL};
	t_stack node9 = {10, 9, -1, NULL};
	t_stack node10 = {11, 10, -1, NULL};
	t_stack node11 = {9, 11, -1, NULL};
	t_stack node12 = {8, 12, -1, NULL};
	t_stack node13 = {12, 13, -1, NULL};
	t_stack node14 = {2, 14, -1, NULL};
	t_stack node15 = {43, 15, -1, NULL};
	t_stack node16 = {22, 16, -1, NULL};

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;
	node7.next = &node8;
	node8.next = &node9;
	node9.next = &node10;
	node10.next = &node11;
	node11.next = &node12;
	node12.next = &node13;
	node13.next = &node14;
	node14.next = &node15;
	node15.next = &node16;

	assignSiblings(&node1);

	t_stack *current = &node1;
	while (current != NULL)
	{
		printf("Value: %d, Sibling: %d\n", current->value, current->family);
		current = current->next;
	}

	return 0;
}
