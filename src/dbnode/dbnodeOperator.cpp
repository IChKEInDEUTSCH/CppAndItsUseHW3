#include <dbnode/dbnodeOperator.h>

#include <iostream>
#include <string>
#define NULL 0

/* Function to reverse a Doubly Linked List */
void reverseAll(dbNode** head_ref, dbNode** rear_ref) {
    dbNode* temp = NULL;
    dbNode* current = *head_ref;
    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    /* Before changing the head, check for the cases like
       empty list and list with only one node */
    if (temp != NULL) {
        *rear_ref = *head_ref;
        *head_ref = temp;
    }
}

// Given a reference (pointer to pointer) to the head
// of a list and an int, inserts a new node
// on the front of the list.
void pushNew(dbNode** head_ref, dbNode** rear_ref, std::string new_name, int eng, int math) {
    // 1. allocate dbNode
    dbNode* new_node = new dbNode();

    // 2. put in the data
    new_node->name = new_name;

    // 3. put in the tag
    new_node->eng = eng;
    new_node->math = math;

    // 4. Make next of new node as head
    // and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // 5. change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    if ((*rear_ref) == NULL)
        (*rear_ref) = new_node;
    // 6. move the head to point to the new node
    (*head_ref) = new_node;
}

// Given a reference (pointer to pointer) to the head
// of a DLL and an int, appends a new node at the end
void appendNew(dbNode** head_ref, dbNode** rear_ref, std::string new_name, int eng, int math) {
    // 1. allocate node
    dbNode* new_node = new dbNode();

    // dbNode* last = *rear_ref; /* used in step 6*/

    // 2. put in the data
    new_node->name = new_name;

    // 3. put in the taf
    new_node->eng = eng;
    new_node->math = math;

    // 4. This new node is going to be the last node, so
    // make next of it as NULL
    new_node->prev = (*rear_ref);
    new_node->next = NULL;
    // 5. If the Linked List is empty, then make the new
    // node as head
    // if (*head_ref == NULL) {
    //     new_node->prev = NULL;
    //     *head_ref = new_node;
    //     return;
    // }
    if ((*rear_ref) != NULL)
        (*rear_ref)->next = new_node;
    if ((*head_ref) == NULL)
        (*head_ref) = new_node;
    // // 6. Else traverse till the last node
    // while (last->next != NULL)
    //     last = last->next;

    // 7. Change the next of last node
    //(*rear_ref)->prev = new_node;

    // 8. Make last node as previous of new node
    (*rear_ref) = new_node;

    return;
}

// Given a reference (pointer to pointer) to the head
// of a DLL and a tag, extarct the node with coresponded tag
dbNode* extract(dbNode** head_ref, dbNode** rear_ref, std::string name) {
    // 1. Use at the whole program
    dbNode* index = *head_ref;
    // 2. While index next node not null
    while (index != NULL) {
        // 3. If node with coresponded tag is found
        if (index->name == name) {
            if (index->next == NULL && index->prev != NULL) {
                (*rear_ref) = index->prev;
                (*rear_ref)->next = NULL;
            }
            if (index->next != NULL && index->prev == NULL) {
                (*head_ref) = index->next;
                (*head_ref)->prev = NULL;
            }
            if (index->next != NULL && index->prev != NULL) {
                index->next->prev = index->prev;
                index->prev->next = index->next;
            }
            index->next = NULL;
            index->prev = NULL;
            break;
        }
        // 4.Else go to next node
        index = index->next;
    }
    // 5. Return coresponded node
    return index;
}