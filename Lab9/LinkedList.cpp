//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <string>

/**
* Constructor
*/
//Big O(1)
LinkedList::LinkedList(){
    head = nullptr; //head first element
    temp= nullptr;
    end=nullptr;
    //size essentially
    size=0;


}

//Destructor
//Big 0(N)
LinkedList::~LinkedList(){
    if(this->isEmpty()!=true){
        clearList();
    }
    delete temp;
    head= nullptr;
    end= nullptr;
    temp= nullptr;

}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
 //Big O(1)
void LinkedList::insertAtEnd(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    LinkedNode* newEnd= new LinkedNode(itemToAdd);
    newNode->setNext(nullptr);
    if (head == nullptr){
        head = newNode;
        end = newNode;

    }
    else {
        end->setNext(newNode);
        end = newNode;

    }
//    newEnd->setNext(top);
//    top = newEnd;
    size+=1;


}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //Big O(N)
int LinkedList::getValueAt(int index){

    if(head== nullptr) {
        throw std::out_of_range("Bad index given to getValueAt: 0");
    }
    //place is index num of last item in list
    else if(index>=size){
        throw std::out_of_range("Bad index given to getValueAt: 100");
    }
    else if(index<0){
        throw std::out_of_range("Bad index given to getValueAt: -1");
    }
    else{
            temp=head;
            for(int i=0;i<size;i++){
                if(index==i){
                    return temp->getItem();
                }
                else{
                    temp=temp->getNext();
                }
            }



    }


    //return item;

}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
 //Big O(N)
std::string LinkedList::toString(){
    std::stringstream ss("");
    std::string aString;

    if(head== nullptr){
        aString="{}";
        return aString;
    }
    else {

        //int size = size;
        temp = head;

        for (int i = 0; i <= size; i++) {
            if (i < size - 1) {
                ss << temp->getItem() << ", ";
                temp = temp->getNext();
            } else if (i == size - 1) {
                ss << temp->getItem();
            }


        }
        aString = "{" + ss.str() + "}";


        return aString;
    }

}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
 //Big O(1)
bool LinkedList::isEmpty(){
    if(head== nullptr) {
        return true;
    }
    else{
        return false;
    }

}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
 //Big O(1)
int LinkedList::itemCount(){
    return size;

}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
 //Big O(N)
void LinkedList::clearList(){
    while(head!= nullptr){
        removeValueAtFront();
    }
    end= nullptr;

    size=0;





}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
 //Big O(N)
int LinkedList::find(int numToFind){
    temp=head;

    for (int i = 0; i < size; i++) {
        if (temp->getItem() == numToFind) {
            return i;
        }
        temp=temp->getNext();
    }
    //std::cout << "not in array" << std::endl;
    return -1;

}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
 //Big O(N)
int LinkedList::findLast(int numToFind){
    temp=head;

    int indexN=-1;
    for(int i=0;i<size;i++){
        if(temp->getItem()==numToFind){
            indexN=i;

        }
        temp=temp->getNext();
    }
    if((size)<1){
        indexN=-1;
    }

    return indexN;

}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if there is no item to remove
 */
 //Big O(N)
int LinkedList::findMaxIndex(){

    if (size<1){

        throw std::out_of_range("In findMaxIndex, List must have items");
    }
    else {
        int maxIndex = 0;
        int maxValue = head->getItem();
        temp = head;

        for (int i = 0; i < size; i++) {

            if (temp->getItem() > maxValue) {
                maxIndex = i;
                maxValue = temp->getItem();
            }
            temp = temp->getNext();
        }
        return maxIndex;
    }
}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
 //Big O(1)
void LinkedList::insertAtFront(int itemToAdd){


    LinkedNode* newNode = new LinkedNode(itemToAdd);

    //if front is nullptr, end should be nullptr too
    if (head == nullptr){
        head = newNode;
        end = newNode;
        size +=1;
    }
    else {
        temp=head;
        head=newNode;
        head->setNext(temp);
        size+=1;


    }

}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
 //Big O(N)
void LinkedList::insertAt(int itemToAdd, int index) {
    LinkedNode *start = head;
    LinkedNode *newNode = new LinkedNode(itemToAdd);
    if(index>size){
        throw std::out_of_range("Bad index given to insertAt: 6");
    }
    else if(index<0){
        throw std::out_of_range("Bad index given to insertAt: -1");
    }
    else if (index == 0) {
        //head=newNode;
        head = newNode;
        head->setNext(start);

    } else {
        int i = 0;
        while (start != nullptr && i+1 < index) {
            start = start->getNext();
            i+=1;
        }
        newNode->setNext(start->getNext());
        start->setNext(newNode);





    }
    size += 1;
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
 //Big O(N)
int LinkedList::removeValueAtEnd() {


    if (this->isEmpty() == true) {
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }


    else {
        temp = head;
        for (int i = 0; i < size-1; i++) {
            temp = temp->getNext();

        }
        int data = temp->getItem();
        delete temp;
        temp = nullptr;
        size -= 1;
        if(size==0){
            head= nullptr;
            end= nullptr;
        }
        return data;

    }
}












    //std::cout << "not in array" << std::endl;





/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
 //Big O(1)
int LinkedList::removeValueAtFront(){
    LinkedNode *node=head;
    //TODO
    if(this->isEmpty()==true){

        throw std::out_of_range("Can't dequeue from an empty queue");
    }
    else {

        temp=head;
        int data = temp->getItem();
        head = head->getNext();
        delete temp;
        temp= nullptr;
        size=size-1;

        return data;
    }




}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //Big O(N)
int LinkedList::removeValueAt(int index){
    int data;
    temp=head;
    if (index == 0) {

        head=head->getNext();
        size-=1;
        return temp->getItem();


    }
    else {


        int i = 0;
        while (temp != nullptr && i + 1 < index) {
            data = temp->getNext()->getNext()->getItem();


            temp = temp->getNext();
            i += 1;
        }

        size -= 1;
        temp->setNext(temp->getNext()->getNext());



        std::cout << data << std::endl;
        return data;
    }


}