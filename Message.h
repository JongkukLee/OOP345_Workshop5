#pragma once
#include <iostream>
#include <string>

namespace w5
{
  class Message
  {
    std::string user;
    std::string reply;
    std::string message;

  public:
    Message()
    {

    }
    // - constructor retrieves a record from the in file object, 
    // parses the record(as described above) and stores its components 
    // in the Message object.c is the character that delimits each record
    Message(std::ifstream& in, char c)
    {
      std::string row;
      std::getline(in, row, c);

      this->user = row.substr(0, row.find(' '));
      row = row.substr(row.find(' '));

      // check if existing reply
      std::size_t idx = row.find("@");
      // if not existing, the remained text is message. 
      if (idx == std::string::npos)
      {
        this->reply = "";
        this->message = row;
      }
      else
      {
        this->reply = row.substr(1, row.find(' '));
        this->message = row.substr(row.find(' '));
      }
    }
    // - returns true if the object is in a safe empty state
    bool empty() const
    {
      return this->message.size() == 0;
    }
    // - displays the Message objects within the container
    void display(std::ostream& os) const
    {
      os << "Message" << std::endl;
      os << "User : " << this->user << std::endl;
      if (this->reply.size() != 0)
        os << "Reply : " << this->reply << std::endl;
      os << "Tweet : " << this->message << std::endl;
    }
	// set member fields (user, reply, message)
	void set(std::string username, std::string replyname, std::string msg)
	{
		this->user = username;
		this->reply = replyname;
		this->message = msg;
	}
	// return user name
	const std::string getUser()
	{
		return this->user;
	}
	// return reply name
	const std::string getReply()
	{
		return this->reply;
	}
	// return message
	const std::string getMessage()
	{
		return this->reply;
	}
  };
}
