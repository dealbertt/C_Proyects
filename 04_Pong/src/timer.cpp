#include <iostream>
#include "../header/timer.hpp"


bool checkTimer(TIMER *timer){
    if(timer->value == 0){
        timer->value = timer->resetValue;
        return true;
    }else{
       timer->value --; 
       return false;
    }
    return false;
}

