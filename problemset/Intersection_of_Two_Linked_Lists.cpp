/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0;
        int lenb = 0;
        ListNode* ptra = headA;
        ListNode* ptrb = headB;

        while (ptra) {
            lena++;
            ptra = ptra->next;
        }
        while (ptrb) {
            lenb++;
            ptrb = ptrb->next;
        }

        ptra = headA;
        ptrb = headB;

        if (lena > lenb) {
            for (int i = 0; i < lena - lenb; i++) {
                ptra = ptra->next;
            }
        } else if (lena < lenb) {
            for (int i = 0; i < lenb - lena; i++) {
                ptrb = ptrb->next;
            }
        }

        while (ptra) {
            if (ptra == ptrb) return ptra;
            ptra = ptra->next;
            ptrb = ptrb->next;
        }

        return NULL;
    }
};
