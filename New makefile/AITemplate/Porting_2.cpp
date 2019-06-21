#include <BattleShipGame/Wrapper/Porting.h>
#include "AITemplate_2.h"

// Do not edit this!
void* getai()
{
    AIInterface *ptr = new AI();
    return ptr;
}
