#include "Entity.hpp"

unsigned int ef::Entity::CURRENT_ID = 1;

ef::Entity::Entity()
{
	return;
}

int ef::Entity::init()
{
	this->id = ef::Entity::CURRENT_ID;
	ef::Entity::CURRENT_ID++;
	return 0;
}

unsigned int ef::Entity::getId()
{
	return this->id;	
}

void ef::Entity::behaviour()
{
	return;
}