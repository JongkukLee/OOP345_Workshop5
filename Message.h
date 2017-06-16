// OOP345 Workshop 5: Containers 
// File Message.h
// Version 1.0
// Date 2017-06-16
// Author Jongkuk Lee ( jlee465@myseneca.ca, 127730158 )
// Description
//      declaration and implementation of variables and 
//            funtion prototype for Message Class  
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const bool VERBOSE = false;

namespace w5
{
	class Message
{
	std::string user;
	std::string reply;
	std::string tweet;

public:
	Message()
	{

	}
	// - constructor retrieves a record from the in file object, 
	// parses the record(as described above) and stores its components 
	// in the Message object.c is the character that delimits each record
	Message(std::ifstream& in, char c)
	{
		std::string line;
		std::getline(in, line, c);

		auto cr = line.find('\r');
		if (cr != std::string::npos)
			line.erase(cr);
		if(VERBOSE) std::cout << "line ->" << line << "<-\n";

		this->user = line.substr(0, line.find(' '));
		if (VERBOSE) std::cout << "user ->" << user << "<-\n";

		// if user length and remained text size is same,
		// do not set reply and tweet
		if (user.size() != line.size())
		{
			line = line.substr(line.find(' ') + 1);

			// check if existing reply
			std::size_t idx = line.find("@");

			// if reply is not existing, the remained text is tweet 
			if (idx == std::string::npos)
			{
				this->reply = "";
				this->tweet = line;
			}
			else
			{
				this->reply = line.substr(1, line.find(' '));
				this->tweet = line.substr(line.find(' ') + 1);
			}
		}
		else
		{
			this->reply = "";
			this->tweet = "";
		}

		if (VERBOSE) std::cout << "reply ->" << reply << "<-\n";
		if (VERBOSE) std::cout << "tweet ->" << tweet << "<-\n";

	}
	// - returns true if the object is in a safe empty state
	bool empty() const
	{
		return this->tweet.empty();
	}
	// - displays the Message objects within the container
	void display(std::ostream& os) const
	{
		os << "Message" << std::endl;
		os << " User  : " << this->user << std::endl;
		if (this->reply.size() != 0)
			os << " Reply : " << this->reply << std::endl;
		os << " Tweet : " << this->tweet << std::endl << std::endl;
	}
	// set member fields (user, reply, message)
	void set(std::string useruser, std::string replyuser, std::string msg)
	{

	}
	// return user user
	const std::string getUser()
	{
		return this->user;
	}
	// return reply user
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
#endif
