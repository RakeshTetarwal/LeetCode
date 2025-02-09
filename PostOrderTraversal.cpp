
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 
class IterativeSolution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pot;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});
        while (!s.empty()) {
            TreeNode* t = s.top().first;
            int time = s.top().second;
            s.pop();
            if(time == 0){
                time++;
                s.push({t, time});
            }else{
                if(t){
                    pot.push_back(t->val);
                }
                continue;
            }
            if (t && t->right != NULL) {
                s.push({t->right, 0});
            }
            if (t && t->left != NULL) {
                s.push({t->left, 0});
            }
        }
        return pot;
    }
};

class RecursiveSolution {
public:

    void rec_pot(TreeNode* root, vector<int>& pot){
        if(!root){
            return;
        }
        rec_pot(root->left, pot);
        rec_pot(root->right, pot);
        pot.push(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pot;
        rec_pot(root, pot);
        return pot;
    }
};

