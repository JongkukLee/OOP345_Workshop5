#pragma once
#include <iostream>
#include <vector>

class Message;

namespace w5
{
  class Notifications
  {
    std::vector<Message*> containers;

  public:
    // - default constructor - empty
    Notifications()
    {

    }
    // - copy constructor
    Notifications(const Notifications& no)
    {
      for (int i = 0; i < no.containers.size(); i++)
      {
        this->containers.push_back(new Message());
        this->containers.at(i)->

        this->containers.push_back(new Message());


        this->containers.push_back(no.containers.at(i));
      }
    }
    // -copy assignment operator
    Notifications& operator=(const Notifications& no)
    {
      if (this != &no)
      {
        for (int i = 0; i < no.containers.size(); i++)
          this->containers.push_back(no.containers.at(i));
      }
    }
    // - move constructor
    Notifications(Notifications&& no)
    {
      for (int i = 0; i < no.containers.size(); i++)
        this->containers.push_back(no.containers.at(i));
    }
    // -move assignment operator
    Notifications&& operator=(Notifications&& no)
    {
      if (this != &no)
      {
        for (int i = 0; i < no.containers.size(); i++)
          this->containers.push_back(no.containers.at(i));
      }
    }
    // - destructor
    ~Notifications()
    {

    }
    // - adds msg to the set
    void operator+=(const Message& msg)
    {

    }
    // - inserts the Message objects to the os output stream
    void display(std::ostream& os) const
    {

    }
  };
}