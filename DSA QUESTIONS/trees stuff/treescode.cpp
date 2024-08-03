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
        ans = max(ans, depth)
                  stack.pop() if (node->left != nullptr)
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