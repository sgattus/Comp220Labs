//
// Created by Toby Dragon on 10/10/18.
//

#include "Car.h"

Car::Car(int yearIn, std::string makeIn, std::string modelIn, float askingPriceIn, float origCostIn){
    this->year = yearIn;
    this->make = makeIn;
    this->model = modelIn;
    this->askingPrice = askingPriceIn;
    this->origCost = origCostIn;
    this->repairCapacity = 100;
    this->repairCosts = new float[this->repairCapacity];
    this->repairCount = 0;
}

Car::~Car(){
    delete[] this->repairCosts;
    this->repairCosts = nullptr;
}

Car::Car(const Car& carToCopy){
    this->year = carToCopy.year;
    this->make = carToCopy.make;
    this->model = carToCopy.model;
    this->askingPrice = carToCopy.askingPrice;
    this->origCost = carToCopy.origCost;
    this->repairCapacity = carToCopy.repairCapacity;
    this->repairCosts = new float[carToCopy.repairCapacity];
    for (int i=0; i<carToCopy.repairCount; i++){
        this->repairCosts[i] = carToCopy.repairCosts[i];
    }
    this->repairCount = carToCopy.repairCount;
}

Car& Car::operator=(const Car& carToCopy){
    if (this != &carToCopy) {
        delete[] this->repairCosts;
        this->repairCosts = nullptr;

        this->year = carToCopy.year;
        this->make = carToCopy.make;
        this->model = carToCopy.model;
        this->askingPrice = carToCopy.askingPrice;
        this->origCost = carToCopy.origCost;
        this->repairCapacity = carToCopy.repairCapacity;
        this->repairCosts = new float[carToCopy.repairCapacity];
        for (int i = 0; i < carToCopy.repairCount; i++) {
            this->repairCosts[i] = carToCopy.repairCosts[i];
        }
        this->repairCount = carToCopy.repairCount;
    }
    return *this;
}

float Car::getAskingPrice(){
    return this->askingPrice;
}
void Car::setAskingPrice(float newAskingPrice){
    this->askingPrice = newAskingPrice;
}
float Car::calcPotentialProfit(){
    float totalRepairs = 0;
    for (int i=0; i<this->repairCount; i++){
        totalRepairs += this->repairCosts[i];
    }
    return this->askingPrice - this->origCost - totalRepairs;
}

std::string Car::toString(){
    return std::to_string(this->year) + " " + this->make + " " + this->model + ": " + std::to_string(this->askingPrice);
}

void Car::addRepairCost(float newRepairCost){
   this->repairCosts[this->repairCount] = newRepairCost;
   this->repairCount++;
}
