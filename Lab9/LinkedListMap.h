


#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

#include <string>
#include "Car.h"
#include "LinkedList.h"
#include "Map.h"

class LinkedListMap : public Map {
private:
    LinkedNode *head;
    LinkedNode  *temp;
    LinkedNode  *end;

    int size;

    LinkedListMap(const LinkedListMap& LinkedListMapToCopy);
    LinkedListMap& operator=(const LinkedListMap& LinkedListMapToCopy);

public:
    /**
     * Constructor
     */
     LinkedListMap();

     //Destructor
     ~LinkedListMap();

     /**
    * @post if the key is new, the key-value pair is added to the map
    *       if the key was already present, the new value overwrites the old value
    *       (i.e., the new value will be returned by get instead of the old value)
    */
    void put(std::string key, const Car& value);

    /**
     * @return the value associated with the given key
     * @throws std::invalid_argument if the key is not present
     */
    Car get(std::string key);

    /**
     * @return true if the given key is associated with a value in the map, false otherwise
     */
    bool containsKey(std::string key);


};
#endif //LINKEDLISTMAP_H

