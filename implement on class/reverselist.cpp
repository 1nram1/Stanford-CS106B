#include<iostream>
using namespace std;
class ListNode {
public:
int val;
ListNode *next;
ListNode(int a = 0,ListNode *p = nullptr) : val(a),next(p) {}
};

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

     ListNode* reverseList(ListNode* head,ListNode* prev = nullptr) {
        if(!head) {
            return prev;
        }
        ListNode* next = head->next;
        head->next =prev;
        return reverseList(next,head);