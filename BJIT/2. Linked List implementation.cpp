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
node* insertAtPosition(node* head_ref, int pos, int data){
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if(pos==0){
        new_node->next = head_ref;
        head_ref = new_node;
    }
    else{
        int idx = 0;
        node *temp = head_ref;
        while(idx<pos-2){ //for 0 base indexing pos - 1 hobe
            idx++;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head_ref;
}
//void deleteAtposition(node** head_ref, int data, int pos){
//    node *temp = *head_ref;
//    if(pos==0){
//        *head_ref = *head_ref->next;
//        delete(temp);
//    }
//    else{
//        int idx = 0;
//        while(idx<pos-2){
//            idx++;
//            temp = temp->next;
//        }
//        node *t = temp->next;
//        temp->next = temp->next->next;
//        delete(t);
//    }
//}
node* deleteAtposition(node* head_ref, int pos){
    node *temp = head_ref;
    if(pos==0){
        head_ref = head_ref->next;
        delete(temp);
    }
    else{
        int idx = 0;
        while(idx<pos-2){
            idx++;
            temp = temp->next;
        }
        node *t = temp->next;
        temp->next = temp->next->next;
        delete(t);
    }
    return head_ref;
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
    head = insertAtPosition(head, 2, 93);
    printList(head);
    head = deleteAtposition(head, 2);
    printList(head);

    cout<<"Ok"<<endl;
}
