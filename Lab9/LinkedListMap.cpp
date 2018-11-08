//
//Created by Sonya Gattus 11/6/18
//

#include "LinkedListMap.h"
#include <iostream>
#include <string>

/**
 * Constructor
 */

 LinkedListMap::LinkedListMap(){
     head= nullptr;
     temp= nullptr;
     end= nullptr;
     //help search through LinkedListMap
     size=0;
 }

 //Destructor
 LinkedListMap::~LinkedListMap() {
     while(head!= nullptr){

         temp=head;
         head = head->getNext();
         delete temp;

         size=size-1;




     }

    head= nullptr;
     temp= nullptr;
    end= nullptr;
     //can I recreate remove value at??? in Child class


 }

 /**
    * @post if the key is new, the key-value pair is added to the map
    *       if the key was already present, the new value overwrites the old value
    *       (i.e., the new value will be returned by get instead of the old value)
    */
 void LinkedListMap::put(std::string key, const Car& value){
     LinkedNode* newNode=new LinkedNode(key);
     //set Car???
     newNode->setCar(value);
     if(head== nullptr){
         head = newNode;
         end = newNode;
         size +=1;
     }
     else if(this->containsKey(key)==true){
         //can I make separate function
         temp=head;
         for(int i=0; i<size; i++){
             if(temp->getItem()==key) {
                 temp->setCar(value);
             }
             else{
                 temp=temp->getNext();
             }
         }
         temp= nullptr;


     }
     else{
         end->setNext(newNode);
         end=newNode;
         size +=1;



     }


 }

/**
* @return the value associated with the given key
* @throws std::invalid_argument if the key is not present
*/
Car LinkedListMap::get(std::string key){
     if (containsKey(key)==true) {

         temp = head;
         for (int i = 0; i < size; i++) {
             if (temp->getItem() == key) {
                 return temp->getCar();
             } else {
                 temp = temp->getNext();
             }
         }
         temp = nullptr;
     }
     else{
         throw std::invalid_argument("Key not present");
     }

 }

/**
 * @return true if the given key is associated with a value in the map, false otherwise
 */
bool LinkedListMap::containsKey(std::string key){
        temp=head;
        bool isKeyed;
         for(int i=0; i<size; i++){
             if(temp->getItem()==key) {
                  isKeyed=true;
                  i=size;
             }
             else{
                 temp=temp->getNext();
                 isKeyed=false;
             }
         }
         temp= nullptr;
         return isKeyed;




 }
