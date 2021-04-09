#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return head;
            ListNode *result = head, *tmp;
            head->next = tmp->next;
            tmp->next = head;
            backtrack(tmp, head);
            return result;
        }
        void backtrack(ListNode* pre, ListNode* pair){
            if(pair == nullptr || pair->next == nullptr ) return;
            ListNode *tmp = pair->next;
            pair->next = tmp->next;
            tmp->next = pair;
            pre->next = tmp;
            backtrack(pair,pair->next);
        }
};