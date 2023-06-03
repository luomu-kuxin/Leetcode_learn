// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
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


void printList(struct ListNode* head)
{
    struct ListNode *list = head->next;
    while(list){
        printf("%d -> ",list->val);
        list = list -> next;
    }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //创建 虚拟头节点  
//    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tmp -> val = 0;
//    tmp -> next = head; 
//    struct ListNode *slow = tmp;
    struct ListNode *slow = head;
   struct ListNode *fast = head -> next;
  for(int i = 0; i < n; i++){
      fast = fast -> next;
  }
  while(fast){
      slow = slow -> next;
      fast = fast -> next;
  }
    slow -> next = slow -> next -> next;
    // head = tmp -> next;
    // free(tmp);
    return head;
}

int main(void){
    struct ListNode *head = creatList();
    head = addAtTail(head,1);
    head = addAtTail(head,2);
    // head = addAtTail(head,3);
    // head = addAtTail(head,4);
    // head = addAtTail(head,5);
    // head = addAtTail(head,6);
    
    printList(head);
    printf("\n");
    head = removeNthFromEnd(head,2);
    printList(head);
    return 0;
}
