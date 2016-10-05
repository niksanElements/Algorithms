#ifndef SORTEDTREE_H
#define SORTEDTREE_H

struct Node{
    int data;
    Node* r_next;
    Node* l_next;
};

class SortedTree
{
    public:
        SortedTree();
        void insert(int d);
        void print();
        virtual ~SortedTree();
    protected:
    private:
        Node* root;
        void insert(int d,Node *root);
        void print(Node* root);
        void destroy(Node* root);
};

#endif // SORTEDTREE_H
