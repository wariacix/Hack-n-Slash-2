#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "Map.h"
#include "Player.h"
#include "equipment.h"
#include "Interface.h"

void drawInterface(sf::RenderWindow& window);
void CityEnter(sf::RenderWindow& window, Map& mainMap, Player& mainPlayer, hns::Equipment &mainEquipment, hns::Interface& mainInterface);
class hns::Dialogue
{
protected:
	sf::Font font;
	sf::Texture viewTexture, interfaceTexture;
	sf::Sprite viewSprite, interfaceSprite;
	sf::SoundBuffer buffer;
	sf::Sound enterSound;
	sf::Text text;
	bool hasSoundBeenPlayed;

	void getDialogueAnswerTick(bool& clickFlag, hns::GameObject& button, int& numberOfButtons, int& choice, std::wstring choiceString[6], sf::RenderWindow& window, Player player, hns::Interface ui);
public:
	Dialogue();

	Dialogue(std::string viewTextureName, std::string enterSoundName, std::string interfaceStr, std::string fontName);

	Dialogue(const hns::Dialogue& copiedDialogue);

	virtual int getDialogueAnswer(sf::RenderWindow& window, Player player, hns::Interface ui, std::wstring choiceString[6], bool playSound = false);

	void playViewSound();

	void drawView(sf::RenderWindow& window);


	static void textWriting(std::wstring input, sf::Text textEnt, sf::RenderWindow& window, Map mainMap, Player mainPlayer);
};
