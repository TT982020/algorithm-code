#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
//�Ƴ�Ԫ��
struct ListNode* removeElements(struct ListNode* head, int val) {
    //����1ֱ��ɾ��
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
    //����2��ɾ���ļ����µ�������
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

//��ת����

struct ListNode* reverseList(struct ListNode* head) {
    //����1��ֱ��ɾ��
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
    //����2��ͷ�巨����
    struct ListNode* newhead = NULL, * cur = head, * next = NULL;
    while (cur) {
        //ͷ�岻�ÿ��ǳ�ʼnewheadΪ��
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