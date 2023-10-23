class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        int i,ind;
        bool flag=true;
        queue<TreeNode*>q;
      //queue to store nodes of binary tree
        q.push(root);//push root
        while(!q.empty())
        {
            int s=q.size();
            vector<int>r(s);
          //create a vector with queue size to store nodes of a particular level
            for(i=0;i<s;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(flag)
                    ind=i;//left to right
                else
                    ind=s-i-1;//right to left
              //use flag to specify the direction (left to right/right to left)
                r[ind]=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
              //push child nodes of a node into queue
            }
            flag=!flag; //negate flag to change the direction
            v.push_back(r);//store node values of a level
        }
        return v;
    }
};
