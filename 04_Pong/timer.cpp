#include <iostream>
#include "header/timer.hpp"



void Timer::resetTimer(){
        value = resetValue;
        return;
}

bool Timer::checkTimer(){
    if(value <= 0){
        activated = true;
        resetTimer();
        return activated;
    }else{
        value --;
        return false;
    }

}
