#include <iostream>
#include <set>

using namespace std;

struct Node
{
    Node(int data,Node* next):data(data),next(next){}
    int data;
    Node* next;
};

struct treeNode
{
    treeNode(Node* data,treeNode* left,treeNode* right)
        :data(data),left(left),right(right){}
    Node* data;
    treeNode* left;
    treeNode *right;
};

class Tree
{
public:
    treeNode* headNode;

    Tree()
    {
        this->headNode = NULL;
    }
    Tree(Node *data)
    {
        this->headNode = new treeNode(data,NULL,NULL);
    }


    void insert(Node *data)
    {
        this->headNode = insert(data,this->headNode);
    }

    treeNode* insert(Node* data,treeNode* head)
    {
        if(head == NULL)
        {
            head = new treeNode(data,NULL,NULL);
        }
        else
        {
            if(data > head->data)
            {
                return insert(data,head->right);
            }
            else if(data < head->data)
            {
                return insert(data,head->left);
            }
        }
        return head;
    }

    bool find(Node* data)
    {
        return find(data,this->headNode);
    }

    bool find(Node* data,treeNode *head)
    {
        if(head != NULL)
        {
            if(data > head->data)
                find(data,head->right);
            if(data < head->data)
                find(data,head->left);
            else
                return true;
        }
        return false;

    }
};

bool  has_cycle(Node* head)
{
    Tree nodeAddresses;
    while(head != NULL)
    {
        if(nodeAddresses.find(head))
        {
            return true;
        }
        nodeAddresses.insert(head);
        head = head->next;
    }
    return false;
};

bool has_cycle2(Node* head) {
    if (head == NULL){
        return 0;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            return true;
        }
    }

    return false;
}

int main()
{
    Node *head = new Node(3,new Node(4,new Node(5,NULL)));
    head->next->next->next = head->next->next;
    Node* adrress = head;

    cout << (has_cycle(head) == has_cycle2(head)) << endl;
    return 0;
}
