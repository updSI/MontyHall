#include "Door.h"

Door::Door()
{
    WinningDoor = false;
    DoorClosed = false;
}

Door::~Door()
{

}

void Door::SetWinner(bool win)
{
    WinningDoor = win;
}

bool Door::IsWinner()
{
    return WinningDoor;
}

void Door::SetDoorClosed(bool c)
{
    DoorClosed = c;
}

bool Door::GetDoorClosed()
{
    return DoorClosed;
}

