#ifndef CONTROL_H
#define CONTROL_H

#include <windows.h>

#include "ftz.h"

class Control
{
private:
public:
    Control();
    void handleInput(FTZ* ftz);
};

#endif // CONTROL_H
