//
// Created by Toby Dragon on 10/10/18.
//

#ifndef INC_220_OOP_CAR_H
#define INC_220_OOP_CAR_H
#include<string>

class Car {
private:
    int year;
    std::string make;
    std::string model;
    float askingPrice;
    float origCost;
    float* repairCosts;
    int repairCount;
    int repairCapacity;

public:
    Car(int yearIn, std::string makeIn, std::string modelIn, float askingPriceIn, float origCostIn);
    ~Car();
    Car(const Car& carToCopy);
    Car& operator=(const Car& carToCopy);

    float getAskingPrice();
    void setAskingPrice(float newAskingPrice);
    float calcPotentialProfit();
    std::string toString();

    void addRepairCost(float newRepairCost);

};


#endif //INC_220_OOP_CAR_H
