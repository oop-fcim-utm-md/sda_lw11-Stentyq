#include "header.h"

#include <assert.h>

int main(int argc, char const *argv[])
{
    node_t *root = nullptr;

    initialize(root, "((1+((2+3)*(4+(5/6))))+((2*3)*(4-6)))");

    print(root);

    assert("+" == root->value_);
    assert("1" == root->left_->left_->value_);
    assert(nullptr == root->left_->left_->left_);
    assert(nullptr == root->left_->left_->right_);
    assert("*" == root->right_->value_);
    assert("6" == root->right_->right_->right_->value_);
    assert(nullptr == root->right_->right_->right_->left_);
    assert(nullptr == root->right_->right_->right_->right_);
    assert(13 == int(evaluate(root)));

    clear(root);
}
