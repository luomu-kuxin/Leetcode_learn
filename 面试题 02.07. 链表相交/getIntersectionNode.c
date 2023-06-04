// 给你两个单链表的头节点 headA 和 headB ，
// 请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
// 默认好像如果相交，则后面的一定都一样。 同时需要比较的是指针，不是数值。

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


struct ListNode* creatList()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head -> val = 0;
    head -> next = NULL;
    return head;
}

struct ListNode* addAtTail(struct ListNode* head, int val)
{
    struct ListNode* node = head;
    while(node -> next){
        node = node -> next;
    }
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp -> next = NULL;
    tmp -> val = val;
    node -> next = tmp;
 
    return head;
}

struct ListNode* addList(struct ListNode* head, struct ListNode *node)
{
    struct ListNode* list = head;
    while(list->next){
        list = list -> next;
    }
    if(node){
        list -> next = node;
    }
    return head;
}

void printList(struct ListNode* head)
{
    struct ListNode *list = head->next;
    while(list){
        printf("%d -> ",list->val);
        list = list -> next;
    }
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *list = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    list = NULL, cur =NULL;
    int la = 0,lb = 0;
    list = headA;
    while(list){
        list = list -> next;
        la++;
    }
    cur = headB;
    while(cur){
        cur = cur -> next;
        lb++;
    }
    int gap = 0;
    if(la >= lb){
        list = headA;
        cur = headB;
        gap = la - lb;
    }else{
        list = headB;
        cur = headA;
        gap = lb - la;
    }
    while(gap--){
        list = list -> next;
    }
    while(list){
        if(list == cur){
            return list;
        }else{
            list = list -> next;
            cur = cur -> next;
        }
    }
    return NULL;

}

int main(void)
{
    struct ListNode *head = creatList();
    head = addAtTail(head,1);
    head = addAtTail(head,2);

    struct ListNode *node = creatList();
    node = addAtTail(node,3);
    node = addAtTail(node,4);
    node = addAtTail(node,5);
    struct ListNode *list = creatList();
    list = addAtTail(list,10);
    list = addAtTail(list,6);
    list = addAtTail(list,9);
    list = addAtTail(list,12);

    head = addList(head,list);
    printList(head);
    node = addList(node, list);
    printf("\n");
    printList(node);
    printf("\n");
    struct ListNode *tmp = getIntersectionNode(head,node);
    printList(tmp);
    return 0;

}