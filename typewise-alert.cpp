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
  switch(coolingType) {
    case PASSIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 40;
      break;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  if(alertTarget == TO_CONTROLLER){
      const unsigned short header = 0xfeed;
      cout<<"header = "<<header<<" "<<"breachType = "<<breachType<<endl;
  }
  else {
      const char* recepient = "a.b@c.com";
      if(breachType == TOO_LOW){
          cout<<"recepient = "<<recepient<<" "<<"Hi, the temperature is too low"<<endl;
      }
      else if(breachType == TOO_HIGH){
          cout<<"recepient = "<<recepient<<" "<<"Hi, the temperature is too high"<<endl;
      }
      else{
          cout<<"NORMAL"<<endl;
      }
  }
}
