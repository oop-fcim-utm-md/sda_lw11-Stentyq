#ifndef _HEADER_H_
#define _HEADER_H_

#include <string>

struct node_t
{
    std::string value_;
    node_t *left_{nullptr};
    node_t *right_{nullptr};
};

void initialize(node_t *&, const std::string);
void print(node_t *);
double evaluate(node_t *);
void clear(node_t *);

#endif
