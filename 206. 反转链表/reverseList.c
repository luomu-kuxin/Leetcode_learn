#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next; 
};


struct ListNode *creatList()
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head -> next = NULL;
    return head;
}

struct ListNode *addAtTail(struct ListNode *head, int val)
{
    struct ListNode *list = (struct ListNode*)malloc(sizeof(struct ListNode));
    list->val = val;
    list->next = NULL;
    struct ListNode *node = head;
    while(node->next){
        node = node->next;
    }
    node -> next = list;
    return head;
    
}   

struct ListNode *reverseList(struct ListNode* head)
{
    struct ListNode * tmp = NULL;
    struct ListNode * node = head -> next;
    struct ListNode * list = NULL;
    
    while(node){
        tmp = node -> next;
        node -> next = list;
        list = node;
        node = tmp;
    }
    return list;

}

void printList(struct ListNode *head)
{
    struct ListNode *node  = head;
    while (node)
    {
        printf("%d -> ",node->val);
        node = node -> next;
    }

    
}

int main(void){

    struct ListNode *head = creatList();
    head = addAtTail(head, 1);
    head = addAtTail(head, 2);
    head = addAtTail(head, 3);
    head = addAtTail(head, 4);
    head = reverseList(head);
    printList(head);
    return 0;
}