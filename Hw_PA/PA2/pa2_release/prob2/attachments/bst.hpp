#ifndef CS10123F_PA2_BST
#define CS10123F_PA2_BST

#include <vector>
#include <iostream>

const double alpha = 0.75;
struct Node
{
    Node *lson, *rson;
    long long value;
    long long totalvalue;
    bool exist;
    long long size;
    long long valid_size;
    bool imBalance()
    {
        if (lson == nullptr && rson != nullptr)
        {
            return rson->size > size * alpha;
        }
        else if (rson == nullptr && lson != nullptr)
        {
            return lson->size > size * alpha;
        }
        else if (rson != nullptr && lson != nullptr)
        {
            return std::max(lson->size, rson->size) > size * alpha;
        }
        else if (rson == nullptr && lson == nullptr)
        {
            return false;
        }
    }
    void update()
    {
        if (lson != nullptr && rson != nullptr)
        {
            size = 1 + lson->size + rson->size;
        }
        else if (lson == nullptr && rson != nullptr)
        {
            size = 1 + rson->size;
        }
        else if (lson != nullptr && rson == nullptr)
        {
            size = 1 + lson->size;
        }
        else if (lson == nullptr && rson == nullptr)
        {
            size = 1;
        }

        if (lson != nullptr && rson != nullptr)
        {
            valid_size = exist + lson->valid_size + rson->valid_size;
        }
        else if (lson == nullptr && rson != nullptr)
        {
            valid_size = exist + rson->valid_size;
        }
        else if (lson != nullptr && rson == nullptr)
        {
            valid_size = exist + lson->valid_size;
        }
        else if (lson == nullptr && rson == nullptr)
        {
            valid_size = exist;
        }

        if (lson != nullptr && rson != nullptr)
        {
            totalvalue = value + lson->totalvalue + rson->totalvalue;
        }
        else if (lson == nullptr && rson != nullptr)
        {
            totalvalue = value + rson->totalvalue;
        }
        else if (lson != nullptr && rson == nullptr)
        {
            totalvalue = value + lson->totalvalue;
        }
        else if (lson == nullptr && rson == nullptr)
        {
            totalvalue = value;
        }
    }
};
Node *root;
// you can do data structure initialization in this function

void ldr(Node *&node, std::vector<Node *> &vec)
{
    if (node == nullptr)
    {
        return;
    }
    ldr(node->lson, vec);
    if (node->exist)
    {
        vec.push_back(node);
    }
    ldr(node->rson, vec);
    if (!node->exist)
    {
        delete node;
    }
}

Node *build(const std::vector<Node *> vec, long long l, long long r)
{
    if (l > r)
    {
        return nullptr;
    }
    long long mid = (l + r) >> 1;
    Node *temp_node = vec[mid];
    temp_node->lson = build(vec, l, mid - 1);
    temp_node->rson = build(vec, mid + 1, r);
    temp_node->update();
    return temp_node;
}

void rebuild(Node *&node)
{
    std::vector<Node *> vec;
    ldr(node, vec);
    node = build(vec, 0, vec.size() - 1);
}
// You can deconstruct your data structure in this function

void clearnode(Node *&node)
{
    if (node != nullptr)
    {
        clearnode(node->lson);
        clearnode(node->rson);
        delete node;
    }
}

void insert(Node *&node, long long x)
{
    if (node == nullptr)
    {
        node = new Node;
        node->size = node->valid_size = 1;
        node->lson = node->rson = nullptr;
        node->value = x;
        node->exist = true;
        node->totalvalue = x;
        return;
    }
    node->size++;
    node->valid_size++;
    if (x < node->value)
    {
        node->totalvalue += x;
        insert(node->lson, x);
    }
    else
    {
        node->totalvalue += x;
        insert(node->rson, x);
    }
    if (node->imBalance())
    {
        rebuild(node);
    }
}


void erase(Node *&node, long long x)
{
    if (node->exist && node->value == x)
    {
        node->exist = false;
        node->valid_size--;
        return;
    }
    node->valid_size--;
    if (x < node->value)
    {
        node->totalvalue -= x;
        erase(node->lson, x);
    }
    else
    {
        node->totalvalue -= x;
        erase(node->rson, x);
    }
}

bool find_x(Node *&node, long long x)
{
    while (node != nullptr)
    {
        if (node->exist && x == node->value)
        {
            return 1;
        }
        else if (!node->exist && x == node->value)
        {
            node = node->rson;
        }
        else if (x < node->value)
        {
            node = node->lson;
        }
        else if (x > node->value)
        {
            node = node->rson;
        }
    }
    return 0;
}

long long querykth(Node *&node, long long k)
{
    while (node != nullptr)
    {
        if (node->exist && node->lson->valid_size + 1 == k)
        {
            return node->value;
        }
        if (node->lson->valid_size >= k)
        {
            node = node->lson;
        }
        else
        {
            k = k - (node->lson->valid_size + node->exist);
            node = node->rson;
        }
    }
    return 0;
}

long long queryksum(Node *&node, long long k, long long tempvalue)
{
    if (node == nullptr)
    {
        return -1;
    }
    long long ans = 0;
    long long rightvalue = 0;
    long long leftvalue = node->totalvalue;
    if (node->rson != nullptr)
    {
        long long rightvalue = node->rson->totalvalue;
        leftvalue -= rightvalue;
    }
    ans = leftvalue * k - rightvalue - tempvalue;
    if (ans >= 0 && node->lson != nullptr)
    {
        tempvalue = node->totalvalue - node->lson->totalvalue + tempvalue;
        long long ans_left = queryksum(node->lson, k, tempvalue);
        if (ans_left < 0)
        {
            return ans;
        }
        else
        {
            return ans_left;
        }
    }
    else if (ans < 0 && node->rson != nullptr)
    {
        tempvalue = tempvalue - node->totalvalue + node->rson->totalvalue;
        long long ans_right = queryksum(node->rson, k, tempvalue);
        return ans_right;
    }
}

void init(long long n [[maybe_unused]]) {}

void clear()
{
    clearnode(root);
}
// opt==1 insert x
// opt==2 erase x
// opt==3 query x
// opt==4 query xth
// opt==5 query x*sum(s1...st) - sum(s_t+1...s_m)
long long SetOperation(long long opt, long long x)
{
    if (opt == 1)
    {
        insert(root, x);
    }
    else if (opt == 2)
    {
        erase(root, x);
    }
    else if (opt == 3)
    {
        return find_x(root, x);
    }
    else if (opt == 4)
    {
        return querykth(root, x);
    }
    else if (opt == 5)
    {
        return queryksum(root, x, 0);
    }
    return 0;
}

#endif // CS10123F_PA2_BST

