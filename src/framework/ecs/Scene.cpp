#include "Scene.hpp"

ef::Scene::Scene()
{
	this->id = 0;
	return;
}

int ef::Scene::init(unsigned int id)
{
	this->id = id;
	return 0;
}

unsigned int ef::Scene::getId()
{
	return this->id;
}