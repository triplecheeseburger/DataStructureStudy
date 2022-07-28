#include "doublylist.h"
#include <stdlib.h>

int main()
{
	DoublyList* doublyList = createDoublyList();
	displayDoublyList(doublyList);

	//add one
	addDLElement(doublyList, 0, (DoublyListNode){1, NULL, NULL});
	displayDoublyList(doublyList);
	addDLElement(doublyList, 1, (DoublyListNode){2, NULL, NULL});
	displayDoublyList(doublyList);
	addDLElement(doublyList, 2, (DoublyListNode){3, NULL, NULL});
	displayDoublyList(doublyList);
	addDLElement(doublyList, 3, (DoublyListNode){4, NULL, NULL});
	displayDoublyList(doublyList);
	addDLElement(doublyList, 4, (DoublyListNode){5, NULL, NULL});
	displayDoublyList(doublyList);
	//remove one
	removeDLElement(doublyList, 2);
	displayDoublyList(doublyList);
	removeDLElement(doublyList, 0);
	displayDoublyList(doublyList);
	removeDLElement(doublyList, doublyList->currentElementCount - 1);
	displayDoublyList(doublyList);

	for (int i = 0; i < 10; i++) {
		addDLElement(doublyList, i, (DoublyListNode){i, NULL, NULL});
	}
	displayDoublyList(doublyList);
	for (int i = 0; i < 10; i++) {
		addDLElement(doublyList, 5, (DoublyListNode){i, NULL, NULL});
	}
	displayDoublyList(doublyList);
	deleteDoublyList(doublyList);
	doublyList = NULL;
	displayDoublyList(doublyList);
    system("leaks doublyLinkedCircular");
}
