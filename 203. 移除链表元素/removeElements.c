// 给你一个链表的头节点 head 和一个整数 val ，
// 请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *list = (struct ListNode  *)malloc(sizeof(struct ListNode));
    while(head && head -> val == val){
        struct ListNode *temp = (struct ListNode  *)malloc(sizeof(struct ListNode));
        temp = head;
        // 将新的头结点设置为head->next并删除原来的头结点
        head = head->next;
        free(temp);
    }
    list = head;
    
    while(list && (list->next)){
        if( list -> next -> val == val){
            struct ListNode *tmp = (struct ListNode  *)malloc(sizeof(struct ListNode));
            tmp = list->next;
            list->next = tmp->next;
            free(tmp);
        }else{
            list = list->next;
        }
    }
    return head;
}

struct ListNode* addElement(struct ListNode* head,int val)
{
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p -> val = val;
    p->next = NULL;
    struct ListNode* i = (struct ListNode*)malloc(sizeof(struct ListNode));
    i = head;
    while (i->next != NULL)
    {
        i = i -> next;
    }
    i -> next = p;
    return head;
}


struct ListNode* creatMyLinkList()
{
   struct ListNode *list = (struct ListNode*)malloc(sizeof(struct ListNode));
    list -> next = NULL;
    return list;
}

void printLinkList(struct ListNode* head)
{
    
    for(struct ListNode *p = head->next; p != NULL; p = p->next)
    {
        printf("[%d] -> ",p->val);
    }

}


int main(void){
    struct ListNode *head = creatMyLinkList();
    addElement(head,2);
    addElement(head,3);
    addElement(head,6);
    addElement(head,3);
    addElement(head,1);
    addElement(head,7);
    removeElements(head,3);
    printLinkList(head);
    return 0;
}
