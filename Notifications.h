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
				this->containers.at(i)->set(no.containers.at(i)->getUser(), 
				no.containers.at(i)->getReply(), 
				no.containers.at(i)->getMessage());
      }
    }
    // -copy assignment operator
    Notifications& operator=(const Notifications& no)
    {
      if (this != &no)
      {
				// dealocate memory
				for (int i = 0; i < this->containers.size(); i++)
					delete this->containers.at(i);

				// deep copy
        for (int i = 0; i < no.containers.size(); i++)
          this->containers.push_back(no.containers.at(i));
      }
    }
    // - move constructor
    Notifications(Notifications&& no)
    {
			for (int i = 0; i < no.containers.size(); i++)
			{
				this->containers.push_back(no.containers.at(i));
				no.containers.at(i) = nullptr;
			}
		}
    // -move assignment operator
    Notifications&& operator=(Notifications&& no)
    {
      if (this != &no)
      {
				for (int i = 0; i < no.containers.size(); i++)
				{
					this->containers.push_back(no.containers.at(i));
					no.containers.at(i) = nullptr;
				}
      }
    }
    // - destructor
    ~Notifications()
    {

    }
    // - adds msg to the set
    void operator+=(const Message& msg)
    {
			//this->containers.push_back(&msg);
			this->containers.push_back(new Message());
    }
    // - inserts the Message objects to the os output stream
    void display(std::ostream& os) const
    {
			for (int i = 0; i < this->containers.size(); i++)
			{
				this->containers.at(i)->display(os);
			}
    }
  };
}