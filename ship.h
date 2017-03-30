#ifndef ship_h
#define ship_h

#include <string>
#include <stdio.h>

using namespace std;

class Ship
{
private:
  int health[5];
  string chunk[5];
  int length = 0;

public:
  Ship(int shipNumber, string position, int l, string orientation)
  {
    length = l;
    chunk[0] = position;

    if(orientation.compare("up") == 0)
    {
      int number = (int) position.at(1);
      for(int i = 1; i < length; i++)
      {
        number--;
        chunk[i] = position.at(0) + number;
      }
    }
    if(orientation.compare("down") == 0)
    {
      int number = (int) position.at(1);
      for(int i = 1; i < length; i++)
      {
        number++;
        chunk[i] = position.at(0) + number;
      }
    }
    if(orientation.compare("right") == 0)
    {
      int number = (int) position.at(1) - 0x40;
      for(int i = 1; i < length; i++)
      {
        number++;
        chunk[i] = position.at(0) + number;
      }
    }
    if(orientation.compare("left") == 0)
    {
      int number = (int) position.at(1) - 0x40;
      for(int i = 1; i < length; i++)
      {
        number--;
        chunk[i] = position.at(0) + number;
      }
    }

    for(int i = 0; i < length; i++)
    {
      health[i] = shipNumber;
    }
  }

  bool shoot(string coord)
  {
    for(int i = 0; i < length; i++)
    {
      if(coord.compare(chunk[i]) && health[i] != 0)
      {
        health[i] = 0;
        return true;
      }
    }
    return false;
  }

  bool isAlive()
  {
    int count = 0;
    for(int i = 0; i < length; i++)
    {
      count += health[i];
    }
    if(count == 0)
      return false;
    else
      return true;
  }
};

#endif
