// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

// 不允许修改 链表。

// 这题还是看中数学理解的，懂原理的话代码很好写
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

struct ListNode* circleList(struct ListNode* head, int val)
{
    struct ListNode *tmp = head;
    struct ListNode *cur = head;
    while(tmp -> next){
        tmp = tmp -> next;
    }
    while(val--){
        cur = cur -> next;
    }
    tmp -> next = cur;

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

void printCircle(struct ListNode* head, int val)
{
    struct ListNode *node = head;
    while(val--){
        node = node -> next;
        printf("%d -> ",node->val);
    }
    struct ListNode *list = node;
    // printf("%d -> ",list->val);
    node = node -> next;
    for(;list != node; node = node -> next){
        printf("%d -> ",node->val);
    }
    printf(" %d -> ",node->val);
    printf(" -------- val = 3\n");
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head; 
    struct ListNode *fast = head; 
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            struct ListNode *index = head;
            while(fast != index){
                fast = fast->next;
                index = index -> next;
            }
            return fast;
        }
    }
    return NULL;
    
}

int main(void)
{
    struct ListNode *head = creatList();
    head = addAtTail(head,1);
    head = addAtTail(head,2);
    head = addAtTail(head,3);
    head = addAtTail(head,4);
    head = addAtTail(head,5);
    printList(head);
    printf("\n");
    head = circleList(head, 3);
    printCircle(head,3);
    printf("\n");
    struct ListNode *node = detectCycle(head);
    printf("%d",node -> val);
    return 0;

}
