//
//  main.cpp
//  Linked List Construction
//
//  Created by Federico Xu on 27/08/2020.
//  Copyright © 2020 Federico Xu. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *prev;
    Node *next;
    
    Node(int value);
};

class doubleLinkedList{
public:
    Node *head;
    Node *tail;
    
    doubleLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void setHead(Node *node){
        if(head == NULL){
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }
    
    void setTail(Node *node){
        if(tail == node){
            setHead(node);
            return;
        }
        insertAfter(tail, node);
    }
    
    void insertBefore(Node *node, Node *nodeToInsert){
        if(nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if(node->prev == NULL)
            head = nodeToInsert;
        else
            node->prev->next = nodeToInsert;
        
        node->prev = nodeToInsert;
    }
    
    void insertAfter(Node *node, Node *nodeToInsert){
        if(nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if(node->next == NULL)
            tail = nodeToInsert;
        else
            node->next->prev = nodeToInsert;
        
        node->next = nodeToInsert;
    }
    
    void remove(Node *node){
        if(node == head)
            head = head->next;
        if(node == tail)
            tail = tail->prev;
        removeNodeBindings(node);
    }
    
    void removeNodeBindings(Node *node){
        if(node->prev != NULL)
            node->prev->next = node->next;
        if(node->next != NULL)
            node->next->prev = node->prev;
        node->prev = NULL;
        node->next = NULL;
    }
    
    void removeNodesWithValue(int value){
        Node *node = head;
        while(node != NULL){
            Node *nodeToRemove = node;
            if(nodeToRemove->value == value)
                remove(nodeToRemove);
        }
    }
    
    bool contains(int value){
        Node *node;
        for(node = head; node != NULL && node->value != value; node = node->next);
        return node != NULL;
    }
    
    void insertAtPosition(int position, Node *nodeToInsert){
        if(position == 1){
            setHead(nodeToInsert);
            return;
        }
        Node *node = head;
        int currentPos = 1;
        while(node != NULL && currentPos++ != position)
            node = node->next;
        if(node != NULL)
            insertBefore(node, nodeToInsert);
        else
            setTail(nodeToInsert);
    }
};

