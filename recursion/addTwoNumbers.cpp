#include <iostream>
using namespace std;
// 最高位在链表尾版本
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
    public:
        
        ListNode * addTwoNumbers(ListNode* L1, ListNode* L2){
            if(L1 == nullptr ) return L2;
            if(L2 == nullptr ) return L1;

            ListNode* result = new ListNode();
            add(L1, L2, result, result, 0);

            return result;
        }

       

        void add(ListNode*L1, ListNode*L2, ListNode* pre, ListNode* cur, int carry){
            //边界条件：两个链表都走到末位时
            //除非最后一位有进位，否则删除最后一个tmp节点。
            if(L1 == nullptr && L2 == nullptr) {
                if(carry != 0 ) cur->val = carry;
                else{
                    pre->next = nullptr;
                    delete cur;
                }
                return;
            }
           
            int sum;
            ListNode* tmp = new ListNode();
            
            //L1走到末尾，L2没走到末尾
            if(L1 == nullptr){
                sum = L2->val + carry;
                carry = sum / 10;

                cur->val = sum % 10;
                cur->next = tmp;

                add(L1, L2->next, cur, tmp, carry);
            }
            //L2走到末尾，L1没走到末尾
            else if(L2 == nullptr){
                sum = L1->val + carry;
                carry = sum / 10;

                cur->val = sum % 10;
                cur->next = tmp;
                add(L1->next, L2, cur, tmp, carry);
            }
            //都没到末尾
            else {
                sum = L1->val + L2->val + carry;
                carry = sum / 10;

                cur->val = sum % 10;
                cur->next = tmp;
                cout << carry;
                add(L1->next, L2->next, cur, tmp, carry);
            } 
        }
};
