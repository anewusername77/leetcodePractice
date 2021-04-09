#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if(l1 == nullptr) return l2;
            if(l2 == nullptr) return l1;
            ListNode *l;
            ListNode *tmp;
            if(l1->val <= l2->val){
                tmp = l1->next;
                l1->next = l2;
                l = l1;
                l1 = tmp;
            }
            else {
                l = l2;
                l2 = l->next;
            }

            merge(l1, l2, l);
            return l;
    }
        void merge(ListNode *l1, ListNode *l2, ListNode* pre){
            if(l1 == nullptr) return;  //l1为空时。因为一直将l1插入l2所以如果没有了就结束。
            if(l2 == nullptr){
                pre->next = l1;  //l2为空l1不为空时，即l1的当前元素比l2最末尾元素还要大
                return;
            }
           
            ListNode *tmp;
            if(l1->val <= l2->val){
                tmp = l1->next;
                l1->next = l2;
                pre->next = l1;
                
                merge(tmp, l2, l1);
            }
            else{
                merge(l1, l2->next, pre->next);
            }
        }
};
