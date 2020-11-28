#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int n){data = n; next = NULL; }
};
class linked_list{
    node *head;

public:
    linked_list(){ head=NULL; }
    void add_node(int data);
    node* getHead(){return head; }
    void insertAtPosition(int data, int pos);
    void deleteAtPosition(int pos);
    void removeSortedDuplicates();
    void removeUnsortedDuplicates();
    void printList();
};
void linked_list::add_node(int data){
    node *tmp = new node(data);
    if(head==NULL){ head=tmp;}
    else{
        node *tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = tmp;
    }
//    else { tail->next = tmp; tail = tail->next; }
}
void linked_list::insertAtPosition(int data, int pos){
    node *temp = head;
    node *new_node = new node(data);
    if(pos==0){
        new_node->next = temp;
        head = new_node;
    }
    else{
        int idx = 0;
        while(idx!=pos-1){
            idx++;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void linked_list::deleteAtPosition(int pos){
    node *temp = head;
    if(pos==0){
        head = head->next;
        delete(temp);
    }
    else{
        int idx = 0;
        while(idx!=pos-1){
            idx++;
            temp = temp->next;
        }
        node *t = temp->next;
        temp->next = temp->next->next;
        delete(t);
    }

}
void linked_list::removeSortedDuplicates(){
    node *temp = head;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            node* t = temp->next;
            temp->next = t->next;
            delete(t);
        }
        else temp = temp->next;
    }
}
void linked_list::removeUnsortedDuplicates(){
    node *temp = head;

    while(temp!=NULL && temp->next!=NULL){
        node *temp2 = temp;
        while(temp2->next != NULL){
            if(temp->data == temp2->next->data){
                node *dup = temp2->next;
                temp2->next = dup->next;
                delete(dup);
            }
            else temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
void linked_list::printList(){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<endl;;
}


//Palindrome Checking Code

node* findMiddle(node* head){
    if(head==NULL || head->next==NULL) return head;
    node *slow = head; node *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast!=NULL) slow = slow->next;
    return slow;
}
node* reverseList(node* head){ //returns headNode of reversed List;
    if(head==NULL || head->next==NULL) return head;
    node* prev = NULL;
    while(head!=NULL){
        node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
bool isPalindrome(node* head){
    if(head==NULL || head->next==NULL) return true;
    node* mid = findMiddle(head);
    node* reverse2ndHalf = reverseList(mid);

    while(reverse2ndHalf!=NULL && head!=NULL){
        if(reverse2ndHalf->data != head->data) return false;
        reverse2ndHalf = reverse2ndHalf->next;
        head = head->next;
    }
    return true;
}
int main(){
    linked_list a;
    a.add_node(10);
    a.add_node(20);
    a.add_node(30);
    cout<<"Current Linked List: "<<endl;
    a.printList();

    cout<<"Insert 25 at position 2"<<endl;
    a.insertAtPosition(25, 2);
    a.printList();

    cout<<"Delete node at position 2"<<endl;
    a.deleteAtPosition(2);
    a.printList();

    cout<<"Current updated List: "<<endl;
    a.insertAtPosition(20, 2);
    a.insertAtPosition(20, 2);
    a.add_node(30);
    a.printList();
    cout<<"Remove Sorted Duplicates: "<<endl;
    a.removeSortedDuplicates();
    a.printList();

    cout<<"Current updated List: "<<endl;
    a.add_node(20);
    a.add_node(20);
    a.add_node(10);
    a.add_node(10);
    a.printList();
    cout<<"Remove Unsorted Duplicates: "<<endl;
    a.removeUnsortedDuplicates();
    a.printList();


    a.add_node(20);
    a.add_node(10);
    a.printList();
    a.printList();
    cout<<"Palindrome? "<<isPalindrome(a.getHead())<<endl;

    a.printList();
    a.printList();
    cout<<"Palindrome? "<<isPalindrome(a.getHead())<<endl;
}
