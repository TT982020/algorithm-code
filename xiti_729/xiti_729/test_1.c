#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
//移除元素
struct ListNode* removeElements(struct ListNode* head, int val) {
    //方法1直接删除
   //  struct ListNode* cur = head, *prev = NULL;
   //  while(cur){
   //      if(cur->val == val){
   //          if(cur == head){
   //              head = cur->next;
   //              free(cur);
   //              cur = head;
   //          }else{
   //              struct ListNode* del = cur;
   //              prev->next = cur->next;
   //              cur = cur->next;
   //              free(del);
   //          }
   //      }else{
   //          prev = cur;
   //          cur = cur->next;
   //      }
   //  }
   //  return head;
    //方法2不删除的加入新的链表中
    struct ListNode* newhead = NULL, * cur = head, * tail = NULL;
    while (cur) {
        if (cur->val != val) {
            if (newhead == NULL) {
                newhead = tail = cur;
                cur = cur->next;
                tail->next = NULL;
            }
            else {
                tail->next = cur;
                cur = cur->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        else {
            struct ListNode* del = cur;
            cur = cur->next;
            free(del);
        }
    }
    return newhead;
}

//反转链表

struct ListNode* reverseList(struct ListNode* head) {
    //方法1，直接删除
    // struct ListNode* cur = head, *prev = NULL,*next = NULL;

    // if(cur)
    //     next = cur->next;

    // while(cur){
    //     cur->next = prev;
    //     prev = cur;
    //     cur = next;
    //     if(next){
    //         next = next->next;
    //     }
    // }
    // return prev;
    //方法2：头插法进行
    struct ListNode* newhead = NULL, * cur = head, * next = NULL;
    while (cur) {
        //头插不用考虑初始newhead为空
        /*next = cur->next;
        if (newhead == NULL) {
            newhead = cur;
            cur = cur->next;
            newhead->next = NULL;
        }
        else {
            cur->next = newhead;
            newhead = cur;
            cur = next;

        }*/
        next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
        return newhead;
    }
}