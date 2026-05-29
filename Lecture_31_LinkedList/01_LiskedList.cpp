#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void Print(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    int n;
    cout << "Enter size ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // create head node
    Node *head = new Node;
    head->data = arr[0];
    head->next = NULL;

    Node *temp = head;

    // create remaining nodes
    for(int i = 1; i < n; i++){

        temp->next = new Node;
        temp = temp->next;

        temp->data = arr[i];
        temp->next = NULL;
    }

    Print(head);

    return 0;
}