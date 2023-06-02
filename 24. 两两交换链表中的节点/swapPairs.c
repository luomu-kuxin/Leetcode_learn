// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */

// struct ListNode* swapPairs(struct ListNode* head){
//     if(!head)return head;
//     struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
//     tmp -> val = 0;
//     tmp -> next = head;
//     struct ListNode* temp = tmp;
//     struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//     cur = head;
//     while(cur && cur -> next){
//         tmp -> next = cur -> next;
//         tmp = tmp -> next;
//         cur ->next = tmp -> next;
//         tmp -> next = cur;
//         tmp = tmp -> next;
//         cur = cur -> next;
//     }

//     return temp -> next;
// }

// 我这里创建时候用了虚拟头节点，但Leetcode上貌似没有，需要创建一个虚拟头节点。可通过代码如上面注释中所示。
struct ListNode* swapPairs(struct ListNode* head){
    if(!head)return head;
    struct ListNode* tmp = head;
    struct ListNode* cur = tmp -> next;
    while(cur && cur->next){
        tmp -> next = cur -> next;
        tmp = tmp -> next;
        cur ->next = tmp -> next;
        tmp -> next = cur;
        tmp = tmp -> next;
        cur = cur -> next;
    }

    return head;
}

struct ListNode* creatList()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head -> next = NULL;
    head -> val = 0;
    return head;
}

struct ListNode* addAtHead(struct ListNode* head , int val)
{
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp -> next = NULL;
    tmp -> val = val;
    if(!head->next){
        head->next = tmp;
        return head;
    }

    struct ListNode* cur  = head -> next;
    head -> next = tmp;
    tmp -> next =cur;
    return head;
}

void printList(struct ListNode* head)
{
    struct ListNode *list = head-> next;
    while(list){
        printf("%d -> ",list->val);
        list = list -> next;
    }
}

int main(void){
    struct ListNode *node = creatList();
    // node = addAtHead(node,5);
    node = addAtHead(node,4);
    node = addAtHead(node,3);
    node = addAtHead(node,2);
    node = addAtHead(node,1);
    printList(node);
    printf("\n");
    node = swapPairs(node);
    printList(node);
    return 0;
}