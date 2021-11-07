#pragma once
#include <set>
#include <string>

class Interacting_object
{
public:
	//Constructors
	Interacting_object();
	Interacting_object(std::set<std::string> tags);
	virtual void interact(Interacting_object& obj) = 0;

	//Accessor
	bool hasTag(std::string tag);

	//Mutator
	void removeTag(std::string tag);
	void addTag(std::string tag);

private:
	std::set<std::string> tags_;
};

