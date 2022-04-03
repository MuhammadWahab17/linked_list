

//
//  main.cpp
//  link_list
//
//  Created by Ch Muhammad Wahab on 01/11/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include "date.h"
using namespace std;
template<class t>
struct node{
    t data;
    node* next;
};
template<class t>
class link_list{
    node<t> *head,*tail;
public:
    link_list(){
        head=nullptr;
        tail=nullptr;
    }
    ~link_list(){
        while(!empty()){
            pop();
        }
        tail=NULL;
    }
    bool empty() const{
        return head==NULL;
    }

    void push(const int value){
        node<t> *temp;
        temp=new node<t>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    void pop(){
        node<t> *temp;
        temp=head;
        head=head->next;
        delete temp;
    }
    void remove2nd(){
        node<t> *temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            node<t> *temp2=temp->next->next;
            delete temp->next;
            temp->next=temp2;
            temp=temp2;
        }
    }
    bool remove(){
        node<t> *temp=head;
        if(temp==NULL)
        {
            delete temp;
            return true;
        }
        while (temp->next->next!=NULL)
            temp=temp->next;

        delete temp->next;
        temp->next=NULL;
        return true;
    }
    void display() const{
        node<t> *temp;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    void erase(const t& val){
        node<t>*prev=NULL,*temp=head;
        if(temp==NULL)
            return;
        if(head->data==val){
            head=head->next;
            delete temp;
            return;
        }
        while(temp->data!=val){
            prev=temp;
            temp=temp->next;
            if (temp==NULL)
                return;
        }
        prev->next=temp->next;
        delete temp;
    }
    void reverse(){
        node<t>*p=NULL,*cur=NULL,*n=NULL;
        if(head!=NULL)
            cur=head;
        while(cur!=NULL){
            n=cur->next;
            cur->next=p;
            p=cur;
            cur=n;
        }
        head=p;
    }
    void reverve_k(const int &val){
        if(head!=NULL)
            head=reverse_kr(head,val);
    }
    node<t>* reverse_kr(node<t> *head, int k){
        node<t>* prev=NULL;
        node<t>* curr=head;
        node<t>* q;
        int counter=k;
        while(counter-- && curr!=NULL){
            q=curr->next;
            curr->next=prev;
            prev=curr;
            curr=q;
        }
        if(head!=NULL)
            head->next=reverse_kr(q,k);
        return prev;
    }
    int count(){
        int n=0;
        node<t>*ptr=head;
        while (ptr) {
            n++;
            if(ptr->next)
            {ptr=ptr->next->next;n++;}
            else
                ptr=ptr->next;
        }
        return n;
    }
    int deci(){
        int deci=0,bin=count()-1;
        node<t>*temp=head;
        while(temp){
            deci += (temp->data * pow(2,bin--));
            temp=temp->next;
            if(temp)
            {
                deci += (temp->data * pow(2,bin--));
                temp=temp->next;
            }
        }
        return deci;
    }
    t middle(){
        node<t>*p1=head,*p2=head;
        while(1){
            if(p1->next==NULL)
                break;
            p1=p1->next;
            p2=p2->next;
            if(p2==NULL)
                break;
            p2=p2->next;
            if(p2==NULL)
                break;
            p2=p2->next;
            if(p2==NULL)
                break;
        }
        return p1->data;
    }
    void sort(){
        sort_rec(head,head->next);
//        node<t>*cur=head;
//        if(head==NULL)
//            throw "NULL \n";
//        while(cur!=NULL){
//            node<t>*hold=cur;
//            while(cur->next!=NULL){
//                if(hold->data > cur->next->data){
//                    t s=hold->data;
//                    hold->data=cur->next->data;
//                    cur->next->data=s;
//                }
//                cur=cur->next;
//            }
//            cur=hold->next;
//        }
    }

    void sort_rec(node<t>*cur,node<t>*next){
        if(cur == NULL || cur->next == NULL)
            return;
        
        if(next != NULL){
            if(next->data < cur->data){
                t temp = cur->data;
                cur->data = next->data;
                next->data = temp;
            }sort_rec(cur, next->next);
        }
        cur = cur->next;
        sort_rec(cur, cur->next);
    }

};









//MuhammadWahab17


int main(int argc, const char * argv[]) {
    

}
