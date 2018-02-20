#ifndef _ACTIONINPUT_180218_PRACTICE_W3_
#define _ACTIONINPUT_180218_PRACTICE_W3_

#include "../Action.h"

#include <vector>

#include "../../Collection/Collection.h"
#include "../../Flowerbed/Flowerbed.h"

class ActionInput : public Action{
public:
    void execute();

    ActionInput(){};
};

#endif