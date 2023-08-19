#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
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