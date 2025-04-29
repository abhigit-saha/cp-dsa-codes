#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *parent;
    vector<Node *> children;
    int degree;
    bool marked;
    Node(int val)
    {
        value = val;
        parent = nullptr;
        degree = 0;
        marked = false;
    }
};

class BinomialHeap
{
public:
    vector<Node *> trees;
    Node *min_node;
    int count;
    BinomialHeap()
    {
        min_node = nullptr;
        count = 0;
        trees.clear();
    }
    bool is_empty()
    {
        return count == 0;
    }
    void insert(int value)
    {
        Node *node = new Node(value);
        BinomialHeap temp;
        temp.trees.push_back(node);
        temp.count = 1;
        unionWith(temp);
    }
    int get_min()
    {
        if (min_node == nullptr)
            throw runtime_error("Heap is empty");
        return min_node->value;
    }
    int extract_min()
    {
        if (min_node == nullptr)
            throw runtime_error("Heap is empty");
        Node *minTree = nullptr;
        int index = -1;
        for (int i = 0; i < trees.size(); i++)
        {
            if (trees[i] == min_node)
            {
                minTree = trees[i];
                index = i;
                break;
            }
        }
        if (index != -1)
            trees.erase(trees.begin() + index);
        BinomialHeap temp;
        reverse(minTree->children.begin(), minTree->children.end());
        temp.trees = minTree->children;
        for (Node *child : temp.trees)
            child->parent = nullptr;
        count -= 1;
        unionWith(temp);
        _find_min();
        return minTree->value;
    }
    void decrease_key(Node *node, int new_value)
    {
        if (new_value > node->value)
            throw invalid_argument("New value is greater than the current value");
        node->value = new_value;
        _bubble_up(node);
    }
    void delete_node(Node *node)
    {
        decrease_key(node, INT_MIN);
        extract_min();
    }
    void _bubble_up(Node *node)
    {
        Node *parent = node->parent;
        while (parent != nullptr && node->value < parent->value)
        {
            swap(node->value, parent->value);
            node = parent;
            parent = node->parent;
        }
    }
    void _link(Node *tree1, Node *tree2)
    {
        if (tree1->value > tree2->value)
            swap(tree1, tree2);
        tree2->parent = tree1;
        tree1->children.push_back(tree2);
        tree1->degree++;
    }
    void _consolidate()
    {
        int max_degree = (count > 0) ? floor(log2(count)) + 1 : 1;
        vector<Node *> degree_table(max_degree + 1, nullptr);
        for (Node *tree : trees)
        {
            Node *current = tree;
            int d = current->degree;
            while (d < degree_table.size() && degree_table[d] != nullptr)
            {
                Node *other = degree_table[d];
                degree_table[d] = nullptr;
                if (current->value < other->value)
                {
                    _link(current, other);
                }
                else
                {
                    _link(other, current);
                    current = other;
                }
                d = current->degree;
            }
            if (d >= degree_table.size())
                degree_table.resize(d + 1, nullptr);
            degree_table[d] = current;
        }
        trees.clear();
        min_node = nullptr;
        for (Node *tree : degree_table)
        {
            if (tree != nullptr)
            {
                trees.push_back(tree);
                if (min_node == nullptr || tree->value < min_node->value)
                    min_node = tree;
            }
        }
    }
    void unionWith(BinomialHeap &other_heap)
    {
        trees.insert(trees.end(), other_heap.trees.begin(), other_heap.trees.end());
        count += other_heap.count;
        _consolidate();
        other_heap.trees.clear();
        other_heap.min_node = nullptr;
        other_heap.count = 0;
    }
    void _find_min()
    {
        min_node = nullptr;
        for (Node *tree : trees)
        {
            if (min_node == nullptr || tree->value < min_node->value)
                min_node = tree;
        }
    }
    int size()
    {
        return count;
    }
};

int main()
{
    BinomialHeap heap1;
    heap1.insert(10);
    heap1.insert(3);
    heap1.insert(15);

    BinomialHeap heap2;
    heap2.insert(6);
    heap2.insert(8);
    heap2.insert(1);

    cout << "Heap1 minimum: " << heap1.get_min() << endl;
    cout << "Heap2 minimum: " << heap2.get_min() << endl;

    heap1.unionWith(heap2);
    cout << "After union, Heap1 minimum: " << heap1.get_min() << endl;

    cout << "Extracted min: " << heap1.extract_min() << endl;
    cout << "New min after extraction: " << heap1.get_min() << endl;

    return 0;
}
