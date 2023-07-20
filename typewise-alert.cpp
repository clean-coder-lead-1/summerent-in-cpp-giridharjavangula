#include "typewise-alert.h"
#include<iostream>
using namespace std;

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  if(coolingType == PASSIVE_COOLING){
      lowerLimit = 0;
      upperLimit = 35;
  }
  else if(coolingType == HI_ACTIVE_COOLING){
      lowerLimit = 0;
      upperLimit = 45;
  }
  else{
      lowerLimit = 0;
      upperLimit = 40;
  }
return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      cout<<"recepient = "<<recepient<<" "<<"Hi, the temperature is too low"<<endl;
      break;
    case TOO_HIGH:
      cout<<"recepient = "<<recepient<<" "<<"Hi, the temperature is too high"<<endl;
      break;
    case NORMAL:
      break;
  }
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  if(alertTarget == TO_CONTROLLER){
      const unsigned short header = 0xfeed;
      cout<<"header = "<<header<<" "<<"breachType = "<<breachType<<endl;
  }
  else {
      sendToEmail(breachType);
  }
}
