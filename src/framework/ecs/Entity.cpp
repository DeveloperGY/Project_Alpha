#include "Entity.hpp"

ef::Entity::Entity()
{
	return;
}

int ef::Entity::init(unsigned int id)
{
	this->id = id;
	return 0;
}

unsigned int ef::Entity::getId()
{
	return this->id;	
}