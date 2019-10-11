#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
};
 

void print(ListNode* l){
    ListNode* ptr = l;
    while (ptr != NULL)
    {
        cout << ptr->val << " " ;
        ptr = ptr->next;
    }
    cout << endl;
}

void expand(int len, int* _l, ListNode* l){
    for(int i=0; i<len; ++i){
        ListNode* temp = new ListNode;
        temp->val = _l[i];
        temp->next = NULL;
        l->next = temp;
        l = l->next;
        //cout << "Node: " << l->val << " " << l->next << endl;
    }
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start_node=NULL, *current_node=NULL;
        bool check_l1=true, check_l2=true;        

        // Handle corner cases: Return other list if one is empty
        if(l1 == NULL){
            return l2;
        }

        if(l2 == NULL){
            return l1;
        }

        // Handle start; Do it once
        if(l1->val <= l2->val){
            start_node = l1;
            current_node = l1;
            l1 = l1->next;
        } else{
            start_node = l2;
            current_node = l2;
            l2 = l2->next;
        }

        while(true){
            if(l1 == NULL){
                current_node->next = l2;
                return start_node;
            }

            if(l2 == NULL){
                current_node->next = l1;
                return start_node;
            }

            if(l1->val <= l2->val){
                current_node->next = l1;
                l1 = l1->next;
            } else{
                current_node->next = l2;
                l2 = l2->next;
            }
            current_node = current_node->next;
        }

    }

};

int main(int argc, char const *argv[])
{
    int _l1[2] = { 2, 4 };
    int _l2[2] = { 3, 4 }; 

    ListNode* l1 = new ListNode;
    l1->val = 1;
    l1->next = NULL;
    ListNode* l2 = new ListNode;
    l2->val = 1;
    l2->next = NULL;

    expand(2, _l1, l1);
    expand(2, _l2, l2);

    Solution s;
    print(s.mergeTwoLists(NULL, l2));

    return 0;
}
