#include "header.h"
#include "iostream"

void initialize(node_t *&root, const char *input)
{
    static int shift = 1;
    if (*(input + shift))
    {

        if (!root)
            root = new node_t;
        if (*(input + shift) == '(')
        {
            ++shift;
            root->left_ = new node_t;
            initialize(root->left_, input);
        }

        if (*(input + shift) == '+' || *(input + shift) == '-' || *(input + shift) == '*' || *(input + shift) == '/')
        {
            root->value_ = *(input + shift);

            shift++;
            root->right_ = new node_t;
            initialize(root->right_, input);
        }
        else if (*(input + shift) == ')')
        {
            while (*(input + shift) == ')')
            {

                shift++;
            }
        }
        else
        {
            if (root->left_ == nullptr && root->value_.empty())
            {
                root->left_ = new node_t();
                root->left_->value_ = *(input + shift);
                shift++;
            }
        }
        if (*(input + shift) == '+' || *(input + shift) == '-' || *(input + shift) == '*' || *(input + shift) == '/')
        {
            root->value_ = *(input + shift);

            shift++;
            if (*(input + shift) == '(')
            {
                root->right_ = new node_t;
                shift++;
                initialize(root->right_, input);
            }
            else
            {
                root->right_ = new node_t;
                root->right_->value_ = *(input + shift);
                shift++;
            }
        }
    }
}

double evaluate(node_t *tree)
{
    double num1, num2;
    const char *str = tree->value_.c_str();
    if (!tree->left_)
        return std::stod(str);
    num1 = evaluate(tree->left_);
    num2 = evaluate(tree->right_);
    switch (tree->value_[0])
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    }
    return 121212;
}

void printHelper(node_t *root, int place)
{
    if (root == NULL)
        return;
 
    place += 10;
 
    printHelper(root->right_, place);
 
    std::cout<<std::endl;
    for (int i = 10; i < place; i++)
        std::cout<<" ";
    std::cout<<root->value_<<"\n";
 
    printHelper(root->left_, place);
}
 
void print(node_t *root)
{
    printHelper(root, 0);
}

void clear(node_t * root)
{
    if (root->left_ != nullptr)
    {
        clear(root->left_);
    }
    if (root->right_ != nullptr)
    {
        clear(root->right_);
    }
    delete root;
}