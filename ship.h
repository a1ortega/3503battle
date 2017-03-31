#ifndef ship_h
#define ship_h

#include <string>
#include <stdio.h>

using namespace std;

class Ship
{

public:
    //Variable that is used later in determining whether or not the ship is alive
    int health[5];
    
    //A blank array that is initialized in order to allow the direction of the ship's placement to be chosen
    //the chunk array contains the positions of the coordinates that each ship is bound to at some point
    string chunk[5];
    
    //Variable to be used in the for-loops of the position creation based upon the orientation
    int length = 0;
    
  Ship(int shipNumber, string position, int l, string orientation)
  {
    //Sets the length and initial chunk variable (first position) equal to the respective parameters
    length = l;
    chunk[0] = position;

    //Condition of if the orientation of the ship is to be up
    if(orientation.compare("up") == 0)
    {
      //Increments the ship upwards
      char number = position.at(1);
      for(int i = 1; i < length; i++)
      {
        number--;
        chunk[i] = string(1,position.at(0)) + number;
      }
    }

    //Condition of if the orientation of the ship is to be down
    if(orientation.compare("down") == 0)
    {
      //Increments the ship downwards
      char number = position.at(1);
      for(int i = 1; i < length; i++)
      {
        number++;
        chunk[i] = string(1,position.at(0)) + number;
      }
    }

    //Condition of if the orientation of the ship is to be right
    if(orientation.compare("right") == 0)
    {
      //Increments the ship to the right
      char number = position.at(0);
      for(int i = 1; i < length; i++)
      {
        number++;
        chunk[i] = number + string(1,position.at(1));
      }
    }

    //Condition of if the orientation of the ship is to be left
    if(orientation.compare("left") == 0)
    {
      //Increments the ship to the left
      char number = position.at(0);
      for(int i = 1; i < length; i++)
      {
        number--;
        chunk[i] = number + string(1,position.at(1));
      }
    }

    //Fills the health array with values equal to the corresponding ship nuber
    for(int i = 0; i < length; i++)
    {
      health[i] = shipNumber;
    }
  }

  //Method that attempts to shoot a ship at a given coordinate
  bool shoot(string coord)
  {
    //Searches through the all of the ship coordinates of the class
    for(int i = 0; i < length; i++)
    {
      //Compares the coordinates that are being shot with those of where the ship is located
      if(coord.compare(chunk[i]) && health[i] != 0)
      {
        //Health of ship at that point is set to 0 (essentially a dead variable)
        health[i] = 0;
        return true;
      }
    }
    return false;
  }

  //Statement to see if the ship is still alive
  bool isAlive()
  {
    //Sets a count variable
    int count = 0;
    for(int i = 0; i < length; i++)
    {
      //Compounds the count variable based on the values of the health index at that point
      count += health[i];
    }

    //After all of the compounding, if the count variable is equal to 0, the ship is confirmed to not be alive
    if(count == 0)
      return false;

    //It's alive
    else
      return true;
  }
};

#endif
