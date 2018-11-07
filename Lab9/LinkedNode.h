//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <string>
#include "Car.h"

class LinkedNode {

private:
    std::string item;
    Car* car;
    LinkedNode* next;

public:
    LinkedNode(std::string item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    std::string getItem();
    Car getCar();
    LinkedNode* getNext();
    void setCar(Car newCar);
    void setItem(std::string newItem);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
