#include "interacting_object.h"

Interacting_object::Interacting_object() : tags_({})
{
}

Interacting_object::Interacting_object(std::set<std::string> tags) : tags_(tags)
{
}

bool Interacting_object::hasTag(std::string tag)
{
	return( tags_.find(tag) != tags_.end());
}

void Interacting_object::removeTag(std::string tag)
{
	tags_.erase(tag);
}

void Interacting_object::addTag(std::string tag)
{
	tags_.insert(tag);
}


