#include "control.h"

Control::Control()
{

}

/* Handle user input */
void Control::handleInput(FTZ *ftz)
{
    bool wait = true;
    while(wait)
    {
        char key = '0';

        if( GetAsyncKeyState( VK_UP ) & 0x8000 )
            key = 'u';
        else if( GetAsyncKeyState( VK_DOWN ) & 0x8000 )
            key = 'd';
        else if( GetAsyncKeyState( VK_LEFT ) & 0x8000 )
            key = 'l';
        else if( GetAsyncKeyState( VK_RIGHT ) & 0x8000 )
            key = 'r';
        else if( GetAsyncKeyState( VK_SPACE ) & 0x8000 )
            key = 'a';

        if(key != '0')
        {
            int* pos = ftz->getHuman( )->getPos();
            int xpos = pos[0];
            int ypos = pos[1];

            /* Loot action */
            if(key == 'a')
            {
                Item *item = ftz->getShip()->getItem(xpos, ypos);
                if(item->getName() == "Bandage")
                    ftz->getHuman()->heal(100);
                else
                    ftz->getHuman()->setWeapon((Weapon*)item);
            }
            else
            {
                if(key == 'u')
                    xpos-- ;
                else if(key == 'd')
                    xpos++;
                else if(key == 'r')
                    ypos++;
                else if(key == 'l')
                    ypos--;

                if(ftz->getShip()->checkPos(xpos, ypos))
                {
                    Alien* alien = ftz->getShip()->getAlien(xpos, ypos);
                    ftz->getHuman()->action(alien);
                    wait = false;
                }
                else if(ftz->getShip()->getMap()[xpos][ypos]->isEnterable())
                {
                    ftz->getHuman()->move(xpos, ypos);
                    wait = false;
                }

                /* Sleep to avoid multiple key presses */
                Sleep(300);
            }
        }
    }
}
