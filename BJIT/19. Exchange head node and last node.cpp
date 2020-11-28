#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* add_node(node* head_ref, int data){
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;


    if(head_ref==NULL){ // //means if *head_ref = head; (pointing address of head, intially none)
        head_ref = temp;
    }
    else{
        struct node *tail = head_ref;
        while(tail->next != NULL) tail = tail->next;
        tail->next = temp;
    }
    return head_ref;
}

node* exchangeHeadandTail(node *head){
    node *tailPast = head, *secondHead = NULL;
    if(head->next) secondHead = head->next;
    while(tailPast->next->next) tailPast = tailPast->next;

    node *tail = tailPast->next;
    tailPast->next = head;
    head->next = NULL;
    tail->next = secondHead;

    return tail;
}
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    struct node *head = NULL;
//    int data;
//    for(int i=0; i<5; i++) {
//       cin>>data;
//       head = add_node(head, data);
//    }
    head = add_node(head, 10);
    head = add_node(head, 20);
    head = add_node(head, 30);
    head = add_node(head, 40);
    printList(head);
    head = exchangeHeadandTail(head);
    printList(head);

    cout<<"Ok"<<endl;
}
