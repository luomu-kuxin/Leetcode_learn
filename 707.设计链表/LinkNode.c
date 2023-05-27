// 你可以选择使用单链表或者双链表，设计并实现自己的链表。

// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：

// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
#include<stdio.h>
#include<stdlib.h>

typedef struct MyLinkList
{
    int val;
    struct MyLinkList *next;
} MyLinkList;

MyLinkList * creatMyLinkList()
{
    MyLinkList *list = (MyLinkList *)malloc(sizeof(MyLinkList));
    list -> next = NULL;
    return list;
}

void addAthead(MyLinkList *head, int val)
{   
    MyLinkList * p = (MyLinkList *)malloc(sizeof(MyLinkList));
    p->val = val;
    p -> next = head ->next;
    head -> next = p;
}

void addAtTail(MyLinkList *head, int val)
{
    MyLinkList * p = (MyLinkList *)malloc(sizeof(MyLinkList));
    p -> val = val;
    p->next = NULL;
    MyLinkList * i = (MyLinkList *)malloc(sizeof(MyLinkList));
    i = head;
    while (i->next != NULL)
    {
        i = i -> next;
    }
    i -> next = p;
        
}

int getindex(MyLinkList *head ,int index)
{
    MyLinkList *i = (MyLinkList *)malloc(sizeof(MyLinkList));
    i = head->next;
    for( int n = 0 ; i!= NULL ; n++){
        if(n == index){
            n = i->val;
            return n;
        }else{
            i = i -> next;
        }
    }
    return -1;
}

void addAtIndex(MyLinkList *head, int index, int val)
{
    if(index == 0)addAthead(head,val);

    MyLinkList *i = (MyLinkList *)malloc(sizeof(MyLinkList));
   
    i = head->next;
    for(int n = 0; i != NULL; n++){
        if(n == index - 1){
            MyLinkList *p = (MyLinkList *)malloc(sizeof(MyLinkList));
            p -> val = val;
            p -> next = NULL; 
            p -> next = i -> next;
            i -> next = p;
        }
        i = i-> next;
    }
}

void deletAtIndex(MyLinkList *head, int index)
{
    if(index < 0 || head -> next == NULL) return;
    if(index == 0){
        MyLinkList *tmp = head -> next;
        head -> next = tmp ->next;
        tmp->next =NULL;
        free(tmp);
    }
    MyLinkList *i = (MyLinkList *)malloc(sizeof(MyLinkList));
    i = head->next;
    for(int n = 0; i != NULL; n++){
        if( n  == index - 1 ){
            MyLinkList *p = (MyLinkList *)malloc(sizeof(MyLinkList));
            if(p != NULL){
                i -> next = p -> next;
            }
            free(p);
        }
        i = i->next;
    }
}


void myLinkedListFree(MyLinkList* head) {
    while(head){
        MyLinkList* tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}


void printLinkList(MyLinkList * head)
{
    
    for(MyLinkList *p = head->next; p != NULL; p = p->next)
    {
        printf("[%d] -> ",p->val);
    }

}



int main(void)
{

    MyLinkList *list = creatMyLinkList();
    addAthead(list,1);
    addAtTail(list,3);
    addAtIndex(list,1,2);
    int a = getindex(list,1);
    deletAtIndex(list,0);
    int b = getindex(list,0);
    printf(" %d\n",a);

    printf(" %d\n",b);
    // addAthead(list,1);
    // addAtTail(list,3);
    // addAtIndex(list,0,2);
    // int a = getindex(list,1);
    // printLinkList(list);
    // printf("\n");
    // deletAtIndex(list,1);
    // printLinkList(list);
    // printf("\n");
    // printf("第1个为: %d",a);
    return 0;
}