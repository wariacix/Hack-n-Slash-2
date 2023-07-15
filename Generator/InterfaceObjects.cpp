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
	title.setFont(font);
	window.draw(title);
}


void hns::Cursor::Draw(sf::RenderWindow& window)
{
	sprite.setPosition((sf::Vector2f)sf::Mouse::getPosition() - (sf::Vector2f)window.getPosition() - sf::Vector2f(0, 30));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) sprite.setTexture(textureClicked);
	else sprite.setTexture(texture);
	window.draw(sprite);
}

void hns::Scroll::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(cornerSprites[i]);
	}
	window.draw(topSprite);
	window.draw(bottomSprite);
	window.draw(scrollRect);
}

void hns::ScrollList::AddTextObject(std::string objectString, std::wstring textString)
{
	textObject.insert(textObject.begin(), std::move(hns::TextObject(x + 10, y + 80 + (distance + 50)*textObject.size(), 32, 10, objectString, 18, sf::Color::White, textString, 30, 10, sf::Color::Black, 2.0f)));
	textObject[textObject.size()-1].SetTitle(textString);
}

void hns::ScrollList::Draw(sf::RenderWindow& window)
{
	hns::Scroll::Draw(window);

	leftTitlePart.Draw(window);
	titleObject.Draw(window);
	rightTitlePart.Draw(window);

	if (textObject.size() > 0)
	{
		for (int i = 0; i < textObject.size(); i++)
		{
			textObject[i].Draw(window);
		}
	}
}
