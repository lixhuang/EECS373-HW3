#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* temp = head, *temp2 = temp;
	if (new_element->index < temp->index)
	{
		new_element->next = head;
		head = new_element;
		return head;
	}
	while (temp != NULL && new_element->index > temp->index)
	{
		temp2 = temp;
		temp = temp->next;
	}
	temp2->next = new_element;
	new_element->next = temp;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* temp, *temp2;
	if (head->next == NULL)
		return head;
	temp = reverse(head->next);
	for (temp2 = temp; temp2->next != NULL; temp2 = temp2->next){}
	temp2->next = head;
	head->next = NULL;
	head = temp;
	return head;
}
