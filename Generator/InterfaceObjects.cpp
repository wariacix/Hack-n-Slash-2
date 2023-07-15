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
	cornerSprites[0].setTexture(cornerTextures[0]);
	cornerSprites[1].setTexture(cornerTextures[1]);
	cornerSprites[2].setTexture(cornerTextures[2]);
	cornerSprites[3].setTexture(cornerTextures[3]);
	for (int i = 0; i < 4; i++)
	{
		window.draw(cornerSprites[i]);
	}
	topSprite.setTexture(topTexture);
	bottomSprite.setTexture(bottomTexture);
	window.draw(topSprite);
	window.draw(bottomSprite);
	window.draw(scrollRect);
}

void hns::ScrollList::AddTextObject(std::string objectString, std::wstring textString)
{
	textObject.insert(textObject.begin(), std::move(hns::TextObject(x + 10, y + 80 + (distance + 50)*textObject.size(), 32, 10, objectString, 22, sf::Color::White, textString, 20, 5, sf::Color::Black, 2.0f)));
	textObject[textObject.size()-1].SetTitle(textString);
}

void hns::ScrollList::Draw(sf::RenderWindow& window)
{
	hns::Scroll::Draw(window);

	leftTitlePart.sprite.setTexture(leftTitlePart.texture);
	leftTitlePart.Draw(window);
	titleObject.sprite.setTexture(titleObject.texture);
	titleObject.Draw(window);
	rightTitlePart.sprite.setTexture(rightTitlePart.texture);
	rightTitlePart.Draw(window);

	if (textObject.size() > 0)
	{
		for (int i = 0; i < textObject.size(); i++)
		{
			textObject[i].sprite.setTexture(textObject[i].texture);
			textObject[i].Draw(window);
		}
	}
}
