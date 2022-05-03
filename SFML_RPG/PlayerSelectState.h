#ifndef PLAYERSELECTSTATE_H
#define PLAYERSELECTSTATE_H

#include "State.h"
#include "Gui.h"
#include "MaryState.h"
#include "CookieState.h"
#include "KnittensState.h"

class PlayerSelectState :
	public State
{
private:
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;
	sf::Sprite mary;
	sf::Sprite cookie;
	sf::Sprite knittens;
	sf::Texture maryTexture;
	sf::Texture cookieTexture;
	sf::Texture knittensTexture;

	sf::RectangleShape btnBackground;
	std::map<std::string, gui::Button*> buttons;

	std::vector<sf::VideoMode> modes;

	//Functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	PlayerSelectState(StateData* state_data);
	virtual ~PlayerSelectState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons(const float& dt);
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif
