// OOP345 Workshop 5: Containers 
// File Notifications.h
// Version 1.0
// Date 2017-06-16
// Author Jongkuk Lee ( jlee465@myseneca.ca, 127730158 )
// Description
//      declaration and implementation of variables and 
//            funtion prototype for Notifications Class  
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include <iostream>
#include <vector>
#include "Message.h"
//class Message;

namespace w5
{
  class Notifications
  {
    //std::vector<Message*> containers;

		Message* messgaeTable;
		        size_t count;
		static int maxSize;

  public:

		void dump(std::string label)
		{
			std::cout << label;
			std::cout << ",count=" << count;
			std::cout << ",messgaeTable=" << messgaeTable << std::endl;
		}

    // - default constructor - empty
    Notifications()
			: messgaeTable(new Message[maxSize]), count(0)
    {

    }
    // - copy constructor 
    Notifications(const Notifications& no)
			: messgaeTable(nullptr), count(0)
    {
			count = no.count;
			for (size_t i = 0; i < count; i++)
			{
				messgaeTable[i] = no.messgaeTable[i];
			}
    }
    // -copy assignment operator
    Notifications& operator=(const Notifications& no)
    {
      if (this != &no)
      {
				delete[] messgaeTable;
				messgaeTable = new Message[maxSize];
				count = no.count;
				for (size_t i = 0; i < count; i++)
				{
					messgaeTable[i] = no.messgaeTable[i];
				}
      }
			return *this;
    }
    // - move constructor
    Notifications(Notifications&& no)
			: messgaeTable(no.messgaeTable), count(no.count)
    {
			no.messgaeTable = nullptr; // make no a 'zombie'
			no.count = 0;
		}
    // -move assignment operator
    Notifications&& operator=(Notifications&& no)
    {
			if (this != &no)
			{
				delete[] messgaeTable;
				messgaeTable = nullptr; // make no a 'zombie'
				count = no.count;

				messgaeTable = messgaeTable;
				count = no.count;

				no.messgaeTable = nullptr; // make no a 'zombie'
				no.count = 0;
			}
			
			return std::move(*this);
    }
    // - destructor
    ~Notifications()
    {

    }
    // - adds msg to the set
    void operator+=(const Message& msg)
    {
		this->messgaeTable[count] = msg;
		count++;
    }
    // - inserts the Message objects to the os output stream
    void display(std::ostream& os) const
    {
			for (int i = 0; i < count; i++)
			{
				messgaeTable[i].display(os);
			}
    }
  };
	int Notifications::maxSize = 10;
}
#endif
