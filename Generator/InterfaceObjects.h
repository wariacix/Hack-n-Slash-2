#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"

class hns::TextObject : public GameObject
{
protected:
	sf::Font font;
	sf::Text title;
	int textSize;
public:
	TextObject(int x, int y, int sizeX, int sizeY, std::string texName, int textSize, sf::Color color, std::wstring titleName, int xOffset = 84, int yOffset = 13, sf::Color outlineColor = sf::Color::Black, float outlineSize = 0.0f) : hns::GameObject(x, y, sizeX, sizeY, texName)
	{
		hns::GameObject::GameObject(x, y, sizeX, sizeY, texName);
		this->x = x;
		this->y = y;
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		this->textSize = textSize;

		texture.loadFromFile("Textures\\" + texName + ".png");
		sprite.setScale(5.f, 5.f);
		sprite.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));
		sprite.setPosition(x, y);
		sprite.setTexture(texture);

		font = sf::Font();
		font.loadFromFile("dpcomic.ttf");

		title = sf::Text();

		title.setFont(font);
		title.setString(titleName);
		title.setCharacterSize(textSize);
		title.setPosition(x + xOffset, y + yOffset);
		title.setFillColor(color);
		title.setOutlineColor(outlineColor);
		title.setOutlineThickness(outlineSize);
	}

	void Draw(sf::RenderWindow& window);
	void SetTitle(std::wstring input);
};

class hns::Scroll
{
protected:
	int x, y, sizeX, sizeY;

	sf::Texture cornerTextures[4];
	sf::Sprite cornerSprites[4];
	sf::Texture topTexture, bottomTexture;
	sf::Sprite topSprite, bottomSprite;

	sf::RectangleShape scrollRect;
public:
	Scroll(int x = 50, int y = 50, int sizeX = 128, int sizeY = 64)
	{
		this->x = x;
		this->y = y;
		this->sizeX = sizeX;
		this->sizeY = sizeY;

		cornerTextures[0].loadFromFile("Textures\\UI\\Scrolls\\upperLeftScroll.png");
		cornerTextures[1].loadFromFile("Textures\\UI\\Scrolls\\upperRightScroll.png");
		cornerTextures[2].loadFromFile("Textures\\UI\\Scrolls\\lowerLeftScroll.png");
		cornerTextures[3].loadFromFile("Textures\\UI\\Scrolls\\lowerRightScroll.png");

		topTexture.loadFromFile("Textures\\UI\\Scrolls\\upperScrollTileable.png");
		bottomTexture.loadFromFile("Textures\\UI\\Scrolls\\bottomScrollTileable.png");

		cornerSprites[0].setTexture(cornerTextures[0]);
		cornerSprites[1].setTexture(cornerTextures[1]);
		cornerSprites[2].setTexture(cornerTextures[2]);
		cornerSprites[3].setTexture(cornerTextures[3]);

		topSprite.setTexture(topTexture);
		topSprite.setTextureRect(sf::IntRect(0, 0, sizeX, 6));
		bottomSprite.setTexture(bottomTexture);
		bottomSprite.setTextureRect(sf::IntRect(0, 0, sizeX, 8));

		cornerSprites[0].setPosition(x - 50, y);
		cornerSprites[1].setPosition(x + sizeX * 5, y);
		cornerSprites[2].setPosition(x - 50, y + sizeY * 5 - 10);
		cornerSprites[3].setPosition(x + sizeX * 5, y + sizeY * 5);

		topSprite.setPosition(x, y);
		bottomSprite.setPosition(x, y + sizeY*5);

		cornerSprites[0].setScale(5,5);
		cornerSprites[1].setScale(5, 5);
		cornerSprites[2].setScale(5, 5);
		cornerSprites[3].setScale(5, 5);

		topSprite.setScale(5, 5);
		bottomSprite.setScale(5, 5);

		scrollRect.setPosition(x + 5, y + 30);
		scrollRect.setSize(sf::Vector2f(sizeX*5 + 10, sizeY*5 - 20));
		scrollRect.setFillColor(sf::Color(198, 165, 109, 255));
	}

	void Draw(sf::RenderWindow& window);
};

class hns::ScrollList : hns::Scroll
{
public:
	hns::GameObject leftTitlePart;
	hns::GameObject rightTitlePart;
	hns::TextObject titleObject = TextObject(x + sizeX * 2 / 3, y + 10, 50, 10, "UI\\Scrolls\\titleMid", 27, sf::Color::White, L"testTitle");

	std::vector<hns::TextObject> textObject;
	std::vector<bool> hasSprite;
	int distance = 10; // in pixels
	ScrollList(int x, int y, int sizeX, int sizeY, int titleSizeX, std::wstring titleString) : hns::Scroll(x, y, sizeX, sizeY)
	{
		Scroll::Scroll(x, y, sizeX, sizeY);
		titleObject = hns::TextObject(x + 55 + sizeX * 1 / 3, y - 30, titleSizeX, 10, "UI\\Scrolls\\titleMid", 27, sf::Color::White, titleString, 15, 5, sf::Color::Black, 2.0f);
		titleObject.SetTitle(titleString);
		leftTitlePart = hns::GameObject(x + 55 + sizeX * 1 / 3 - 75, y - 30, 16, 12, "UI\\Scrolls\\titleLeft");
		rightTitlePart = hns::GameObject(x + 55 + sizeX * 1 / 3 + titleSizeX * 5, y - 25, 16, 12, "UI\\Scrolls\\titleRight");

		textObject = std::vector<hns::TextObject>();
	}

	void AddTextObject(std::string objectString, std::wstring textString);
	void Draw(sf::RenderWindow& window);
};

class hns::Cursor
{
public:
	static sf::Texture texture, textureClicked;
	static sf::Sprite sprite;
	
	hns::Cursor()
	{
		texture = sf::Texture();
		textureClicked = sf::Texture();
		sprite = sf::Sprite();
		texture.loadFromFile("Textures\\cursor.png");
		textureClicked.loadFromFile("Textures\\cursorClicked.png");
		sprite.setTexture(texture);
		sprite.setScale(4.0f, 4.0f);
	}

	static void Draw(sf::RenderWindow& window);
};