#include <memory>

struct node
{
    node* left;
    node* right;
};

node* copy_node(node* original)
{
    if (!original)
    {
        return nullptr;
    }
    node* result = new node();
    result->left = copy_node(original->left);
    result->right = copy_node(original->right);
    return result;
}

int main()
{
    node* n = new node();
    auto c = copy_node(n);
    delete c;
    delete n;
    return 0;
}