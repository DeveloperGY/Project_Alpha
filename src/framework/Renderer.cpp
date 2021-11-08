#include "Renderer.hpp"

ef::Renderer::Renderer()
{
	return;
}

int ef::Renderer::init(ef::Window* win, ef::ComponentManager* com, ef::AssetManager* as)
{
	this->window = win;
	this->componentManager = com;
	this->assetManager = as;
	return 0;
}

int ef::Renderer::render(unsigned int entityId, ef::Window* win)
{
	ef::Window* renderWin = (win == nullptr) ? this->window : win;

	ef::cp::Transform* t = this->componentManager->getTransform(entityId);
	ef::cp::Sprite* s = this->componentManager->getSprite(entityId);
	

	if(t == nullptr || s == nullptr)
	{
		return -1;
	}

	float x = t->x;
	float y = t->y;
	std::string key = s->textureKey;
	sf::Texture tex = this->assetManager->getTexture(key);
	
	s->sprite.setPosition(sf::Vector2f(x, y));
	s->sprite.setTexture(tex);
	renderWin->draw(s->sprite);

	return 0;
}