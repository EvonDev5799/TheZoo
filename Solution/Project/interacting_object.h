#pragma once
#include <set>
#include <string>

class Interacting_object
{
public:
	//Constructors
	Interacting_object();

	virtual Interacting_object* interact(Interacting_object* obj) = 0;

	//Accessor
	bool hasTag(std::string tag);

	//Mutator
	void removeTag(std::string tag);
	void addTag(std::string tag);

private:
	std::set<std::string> tags_;
};

