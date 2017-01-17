#include <iostream>

using namespace std;

struct Node
{
    Node(int data,Node *next):data(data),next(next){}
    int data;
    Node* next;
};

Node* RemoveDuplicate(Node *head)
{
    if(head != NULL)
    {
        Node* next = head->next;
        Node** current = &head;
        while(next != NULL)
        {
            if(next->data == (*current)->data){
                *current = next;
                next = next->next;
            }
            else
            {
                current = &(*current)->next;
                next = next->next;
            }
        }
    }
    return head;
}

void Print(Node *head)
{
    if(head != NULL)
    {
        cout << head->data << " ";
        Print(head->next);
    }
}


int main()
{
    Node *head = new Node(1,new Node(1,new Node(1,new Node(2,new Node(2,new Node(3,new Node(4,NULL)))))));
    Print(head);
    cout << endl;
    head = RemoveDuplicate(head);
    Print(head);
    cout << endl;
    return 0;
}
