#ifndef DOOR_H
#define DOOR_H


class Door
{
public:
    Door();
    ~Door();
    void SetWinner(bool);
    bool IsWinner();
    void SetDoorClosed(bool);
    bool GetDoorClosed();

private:
    bool WinningDoor;
    bool DoorClosed;
};

#endif // DOOR_H
