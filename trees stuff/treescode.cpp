int maxDepth(Node *node, int depth)
{
    if (node == null)
    {
        return 0;
    }

    return max(maxDepth(node->left), maxDepth(node->right)) + 1;
}

// iterative approach using stack
int maxDepth(Node *root)
{
    stack << Node *, depth >> st;
    ans = 0;
    stack.push({root, 1});
    while (!stack.empty())
    {
        auto [node, depth] = st.top();
        ans = max(ans, depth);
        stack.pop();
        if (node->left != nullptr)
        {
            stack.push({node->left, depth + 1});
        }
        if (node->right != nullptr)
        {
            stack.push({node->left, depth + 1});
        }
    }
    cout << ans << endl;
}

int pathSum(Node *root, int sum, int x)
{
    if (node == null)
    {
        return false;
    }

    sum += root->value;
    if (node->left == nullptr && node->right == nullptr)
    {
        if (sum == x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool left = pathSum(node->left, sumGlobal + node->left->val, int x);
    bool right = pathSum(node->left, sumGlobal + node->right->val, int x);

    return left || right;
}

int pathSum(Node *root, int x)
{
    stack<Node *, int> st;
    st.push({root, root->val});

    while (!st.empty())
    {
        auto [node, sum] = st.top();
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum + node->val == x)
            {
                return true;
            }
        }
        st.pop();
        if (node->left != nullptr)
        {
            st.push({node->left, sum + node->val})
        }
        if (node->right != nullptr)
        {
            st.push({node->right, sum + node->val})
        }
    }
    return false;
}

int goodCount(Node *node, int greatestTillNow)
{
    if (node == null)
    {
        return 0;
    } // since when there is no node there is no path.

    // update the next node's greatest tillnow variable if the current node has a greater value
    int left = goodCount(node->left, max(node->val, greatestTillNow));
    int right = goodCount(node->right, max(node->val, greatestTillNow));
    int ans = left + right;
    if (node->val >= greatestTillNow)
    {
        ans++;
    }
}

// diameter of a tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int diameter = INT_MIN;
    int diameterOfBinaryTree(TreeNode *root)
    {
        // note if you want to return something after the entire tree has been traversed
        // create the dfs as a separate function and have it update a global variable.
        // then call it inside another function that is going to be executed and then return the
        // global variable last.
        longestPath(root);
        return diameter;
    }

private:
    int longestPath(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftLongestPath = longestPath(node->left);
        int rightLongestPath = longestPath(node->right);
        diameter = max(diameter, leftLongestPath + rightLongestPath);
        return max(leftLongestPath, rightLongestPath) + 1;
    }
};

// BFS

void printAllNodes(TreeNode *root)
{
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int nodesInCurrentLevel = queue.size();
        // do some logic here for the current level

        for (int i = 0; i < nodesInCurrentLevel; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();

            // do some logic here on the current node
            cout << node->val << endl;

            // put the next level onto the queue
            if (node->left)
            {
                queue.push(node->left);
            }

            if (node->right)
            {
                queue.push(node->right);
            }
        }
    }
}

void printRightValues(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int elInCurrentLvl = q.size();
        cout << q.back() << endl;
        for (int i = 0; i < elInCurrentLvl; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }
}

// BST:
// minimum possible difference between any two elements in a binary search tree:
int minDiff(TreeNode *root)
{
    vector<int> values;
    dfs(root, values);
    int ans = INT_MAX;
    for (int i = 1; i < values.size(); i++)
    {
        ans = min(ans, values[i] - values[i - 1]);
    }
    return ans;
}
void dfs(TreeNode *root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }
    // preorder traversal in a bst would give a sorted array.
    dfs(root->left, values);
    values.push_back(root->val);
    dfs(root->right, values);
}
// iterative solution by inorder traversal(just rem but not easy)
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> values = iterativeInorder(root);
        int ans = INT_MAX;
        for (int i = 1; i < values.size(); i++)
        {
            ans = min(ans, values[i] - values[i - 1]);
        }

        return ans;
    }

    vector<int> iterativeInorder(TreeNode *root)
    {
        stack<TreeNode *> stack;
        vector<int> values;
        TreeNode *curr = root;

        while (!stack.empty() || curr != nullptr)
        {
            if (curr != nullptr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                values.push_back(curr->val);
                curr = curr->right;
            }
        }

        return values;
    }
};

bool validate(TreeNode *root)
{
    return dfs(root, INT_MIN, INT_MAX); // root can be anything so no check of small and large
    // for the main root.
}

bool dfs(TreeNode *root, int small, int large)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->val < small || root->val > large)
    {
        return false;
    }
    left = dfs(root->left, small, root->val);
    right = dfs(root->right, root->val, large);
    return left && right;
}

// iterative version
bool isValid(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    stack < pair<TreeNode *, pair<int, int>> st;
    st.push(root);
    if (!st.empty())
    {
        auto [node, p] = st.top();
        int small = p.first;
        int large = p.second;
        st.pop();
        if (node->val < small || node->val > large)
        {
            return false;
        }
        if (node->left != nullptr)
        {
            st.push({node->left, {small, node->val}});
        }
        if (node->right != nullptr)
        {
            st.push({node->right, {node->val, large}});
        }
    }

    return true;
}

// insert node in bst;
// note: we can always insert a node into the end of the tree as a leaf node
// because we can always find lower and higher elements till the bottom.

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};

// closest value
int closestValue(TreeNode *root, double target)
{
    int ans = 0;
    double diff = INT_MAX;
    while (root != nullptr)
    {

        if (abs(root->val - target) < diff || (abs(root->val - target) == diff && root->val < ans))
        {
            diff = abs(root->val - target);
            ans = root->val;
        }

        if (root->val > target)
        {

            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}