//
//  Linkedlist.cpp
//  Homework 5
//
//  Created by Darby Rush on 11/9/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Linkedlist.h"

using namespace std;

//default constructor for empty list
Linkedlist::Linkedlist(){
    head = new Node;
    head->next = NULL;
    tail = head;
    numNodes = 0;
    
}
//destructor to free nodes dynamically created to support the linklist
Linkedlist::~Linkedlist(){
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete(current);
        current = next;
    }
    head = NULL;
    tail = NULL;
}

bool Linkedlist::empty() const{
    if((head->next = NULL)){
        return true;
    }
    else{
        return false;
    }
}

void Linkedlist::clear(){
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete(current);
        current = next;
    }
    head = NULL;
    tail = NULL;
    
}
Linkedlist::reference Linkedlist::back(){
    return tail->elem;
}
Linkedlist::const_reference Linkedlist::back() const{
    return tail->elem;
}
Linkedlist::reference Linkedlist::front(){
    return head->elem;
}
Linkedlist::const_reference Linkedlist::front() const{
    return head->elem;
}
Linkedlist& Linkedlist::operator=(const Linkedlist& left){
    if(this != &left){
        clear();
        Node* temp = left.head;
        while(temp != NULL){
            push_back(temp->elem);
            temp = temp->next;
        }
    }
    return *this;
}
void Linkedlist::pop_back (){
    Node *temp = new Node;

    temp = tail->prev;
    temp->next = NULL;
    tail = temp;
    numNodes--;
}
void Linkedlist::pop_front(){
    Node *temp = new Node;

       temp = head->next;
       temp->prev = NULL;
       head = temp;
       numNodes--;
}
void Linkedlist::push_back(const element_type& x ){
    Node *temp = new Node;

        temp->elem = x;
        temp->prev = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
        numNodes++;
   
}
void Linkedlist::push_front(const element_type& x){
    
           Node* temp = new Node;
           temp->elem = x;
           temp->next = head;
           temp->prev = NULL;
           head->prev = temp;
           head = temp;
           numNodes++;
      
}

void Linkedlist::sort(){
    
    Node* right = new Node();
    Node* left = new Node();
    Node* temp = new Node();
    left = head;
    right = head->next;
    int i =0;
    int j = 0;
    
    if(head == NULL){
        return;
    }
    else{
        while(left != NULL){
            right = left->next;
            
            while(right != NULL){
                if(left->elem > right->elem){
                       temp = left->next;
                       left->next = right->next;
                       left->prev = right->prev;
                       right->next = temp->next;
                       right->prev=temp->prev;
                    
                    
            }
        }
      }
    }
}

// constructor that initializes the linked list with n nodes,
// with elem value from 0 to n-1
  Linkedlist::Linkedlist(unsigned int n){
      for(int i = 0; i<n;i++){
          if(i==0){
              head = new Node();
              tail = head;
              head->next = NULL;
              head->prev = NULL;
          }
          else{
              push_back(i);
          }
      }
}

// print the linked list in the forward direction,
// similar to the show function of lab7
void Linkedlist::check() const{
 Node* current = head;
     
     if (current == NULL)
         cout << "It is an empty list!" << endl;
     
     int i = 0;
     while (current != NULL)
     {
         cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
         current = current->next;
         i++;
     }
     
     cout << "----------------------------------------------------------------------" << endl;
 }


// print the linked list in the backward direction,
// similar to the reverse_show function of lab8
void  Linkedlist::rcheck() const{
 Node* current = tail;
   
   if (current == NULL)
       cout << "It is an empty list!" << endl;
   
   int i = 0;
   while (current != NULL)
   {
       cout << current->elem << " " << endl;
       current = current->prev;
       i++;
   }
   
   cout << "------------------------------------------------------------------------------------------" << endl;
}

// insert a node with value specified by x after the node
// specified by pos. The first node has position 0.
// if the number of nodes in the linked list is less than
// pos, the node is inserted at the end.
void Linkedlist::insert(unsigned int pos, const element_type& x){
    if(numNodes > pos){
        push_back(x);
        return;
    }
    Node* temp = new Node();
    temp = head;
    Node* insertNode = new Node();
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }
    insertNode ->elem = x;
    insertNode->prev = temp;
    insertNode -> next = temp->next;
    
    numNodes++;
}

// remove the node specified by pos.
// if the number of nodes in the linked list is less than
// pos, the node at the end if any is removed.
void Linkedlist::erase(unsigned int pos){
    if(numNodes < pos){
        pop_back();
    }
    Node* temp = head;
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }
    
    temp->next = temp ->next->next;
    temp->next->prev=temp;
    numNodes++;
}
