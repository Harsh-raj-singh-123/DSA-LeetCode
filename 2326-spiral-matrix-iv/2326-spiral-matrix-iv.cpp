/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head){
        vector<vector<int>> v(m, vector<int>(n, -1));
        int left  = 0;
        int right = n-1;
        int top = 0;
        int bottom  = m-1;
        ListNode* temp = head;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                if(temp != nullptr){
                    int x  = temp->val;
                    v[top][i]  = x;
                    temp = temp->next;
                }
            }
            top++;

            for(int i = top; i <= bottom; i++){
                if(temp != nullptr){
                    int x  =  temp->val;
                    v[i][right] = x;
                    temp  = temp->next;
                }
            }
            right--;

            if(top <= bottom){
                for(int i  = right; i >= left; i--){
                    if(temp != nullptr){
                        int x = temp->val;
                        v[bottom][i]  = x;
                        temp = temp->next;
                    }
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    if(temp != nullptr){
                        int x  = temp->val;
                        v[i][left] = x;
                        temp = temp->next;
                    }
                }
                left++;
            }
        }
        return v;
    }
};