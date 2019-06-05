<<<<<<< HEAD
/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    unique_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    unique_ptr<ListNode> addTwoNumbers(unique_ptr<ListNode> l1, unique_ptr<ListNode> l2) {
        ListNode* result=nullptr;
        int carry= 0;
        int count = 0;
        ListNode* p1 = l1.get();
        ListNode* p2 = l2.get();
        ListNode* pr = nullptr;
        while(p1 != nullptr && p2 != nullptr) {
            cout << "val1:" << p1->val << ",val2:" << p2->val << endl; 
            int sum = carry + p1->val + p2->val;
            carry = sum / 10;
            sum = sum % 10;
            cout << "sum:" << sum << ",carry:" << carry << endl;
            if(! result) {
                result = new ListNode(sum);
                count += 1;
                pr = result;
            } else {
                pr->next = unique_ptr<ListNode> (new ListNode(sum));
                count += 1;
                pr = (pr->next).get();
            }
            p1 = p1->next.get();
            p2 = p2->next.get();
        }
        ListNode* p = p1?p1:p2;
        if(p == nullptr && carry > 0) {//both pointers are null here
            pr->next = unique_ptr<ListNode> (new ListNode(carry));
            count += 1;
            carry = 0;
            pr = pr->next.get();
        }else{
            while(p != nullptr) {
                cout << "val:" << p->val << ",carry:" << carry << endl; 
                int sum = carry + p->val;
                carry = sum / 10;
                sum = sum % 10;
                cout << "sum:" << sum << ",carry:" << carry << endl;
                pr->next = unique_ptr<ListNode> (new ListNode(sum));
                pr = pr->next.get();
                count += 1;
                p = p->next.get();
            }
            if(carry > 0) {
                cout << "carry:" << carry << endl; 
                pr->next = unique_ptr<ListNode>(new ListNode(carry));
                pr = pr->next.get();
                count += 1;
                carry = 0;
                pr = pr->next.get();
            }
        }
        cout << "number of nodes created:" << count << endl;
        ListNode* iter = result;
        while(iter != nullptr) {
            cout << "->" << iter->val;
            iter = iter->next.get();
        }
        cout << endl;
        return unique_ptr<ListNode>(result);
    }
};

int main() {
    Solution sol = Solution();
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9);
    l2->next = unique_ptr<ListNode>(new ListNode(9));
    unique_ptr<ListNode> result = sol.addTwoNumbers(
        unique_ptr<ListNode> (l1), 
        unique_ptr<ListNode> (l2)
        );
    if(result == nullptr) {
        cout<<"Result is a nullptr"<<endl;
    } else {
        ListNode* p = result.get();
        while(p!=nullptr) {
            cout<<p->val<<endl;
            p = p->next.get();
        }
    }
=======
/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    unique_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    unique_ptr<ListNode> addTwoNumbers(unique_ptr<ListNode> l1, unique_ptr<ListNode> l2) {
        ListNode* result=nullptr;
        int carry= 0;
        int count = 0;
        ListNode* p1 = l1.get();
        ListNode* p2 = l2.get();
        ListNode* pr = nullptr;
        while(p1 != nullptr && p2 != nullptr) {
            cout << "val1:" << p1->val << ",val2:" << p2->val << endl; 
            int sum = carry + p1->val + p2->val;
            carry = sum / 10;
            sum = sum % 10;
            cout << "sum:" << sum << ",carry:" << carry << endl;
            if(! result) {
                result = new ListNode(sum);
                count += 1;
                pr = result;
            } else {
                pr->next = unique_ptr<ListNode> (new ListNode(sum));
                count += 1;
                pr = (pr->next).get();
            }
            p1 = p1->next.get();
            p2 = p2->next.get();
        }
        ListNode* p = p1?p1:p2;
        if(p == nullptr && carry > 0) {//both pointers are null here
            pr->next = unique_ptr<ListNode> (new ListNode(carry));
            count += 1;
            carry = 0;
            pr = pr->next.get();
        }else{
            while(p != nullptr) {
                cout << "val:" << p->val << ",carry:" << carry << endl; 
                int sum = carry + p->val;
                carry = sum / 10;
                sum = sum % 10;
                cout << "sum:" << sum << ",carry:" << carry << endl;
                pr->next = unique_ptr<ListNode> (new ListNode(sum));
                pr = pr->next.get();
                count += 1;
                p = p->next.get();
            }
            if(carry > 0) {
                cout << "carry:" << carry << endl; 
                pr->next = unique_ptr<ListNode>(new ListNode(carry));
                pr = pr->next.get();
                count += 1;
                carry = 0;
                pr = pr->next.get();
            }
        }
        cout << "number of nodes created:" << count << endl;
        ListNode* iter = result;
        while(iter != nullptr) {
            cout << "->" << iter->val;
            iter = iter->next.get();
        }
        cout << endl;
        return unique_ptr<ListNode>(result);
    }
};

int main() {
    Solution sol = Solution();
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9);
    l2->next = unique_ptr<ListNode>(new ListNode(9));
    unique_ptr<ListNode> result = sol.addTwoNumbers(
        unique_ptr<ListNode> (l1), 
        unique_ptr<ListNode> (l2)
        );
    if(result == nullptr) {
        cout<<"Result is a nullptr"<<endl;
    } else {
        ListNode* p = result.get();
        while(p!=nullptr) {
            cout<<p->val<<endl;
            p = p->next.get();
        }
    }
>>>>>>> 74ed0147be89ddfd4f3bd2123fb35e5a776d6085
}