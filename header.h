#ifndef _HEADER_H_
#define _HEADER_H_

#include <string>

struct node_t
{
    std::string value_;
    node_t *left_{nullptr};
    node_t *right_{nullptr};
};

void initialize(node_t *&root, const char *input);
void printHelper(node_t *root, int place);
void print(node_t *root);
double evaluate(node_t *tree);
void clear(node_t * root);

#endif
