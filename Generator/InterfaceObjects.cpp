#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"
#include "InterfaceObjects.h"


void TextObject::SetTitle(std::wstring input)
{
	title.setString(input);
}

void TextObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(title);
}


void hns::Cursor::Draw(sf::RenderWindow& window)
{
	sprite.setPosition((sf::Vector2f)sf::Mouse::getPosition() - (sf::Vector2f)window.getPosition() - sf::Vector2f(0, 30));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) sprite.setTexture(textureClicked);
	else sprite.setTexture(texture);
	window.draw(sprite);
}
