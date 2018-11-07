//
// Created by Toby Dragon on 10/17/17.
//
#include "LinkedNode.h"


LinkedNode::LinkedNode(std::string item){
    this->item = item;
    next = nullptr;
    this->car= nullptr;

}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
    car= nullptr;
}

std::string LinkedNode::getItem(){
    return item;
}

LinkedNode* LinkedNode::getNext(){
    return next;
}

Car LinkedNode::getCar() {
    return *car;
}

void LinkedNode::setItem(std::string newItem){
    item = newItem;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}

void LinkedNode::setCar(Car newCar){
    this->car=new Car(newCar);
}
