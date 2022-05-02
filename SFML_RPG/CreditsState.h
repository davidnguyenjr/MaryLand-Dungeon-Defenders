#ifndef CREDITSSTATE_H
#define CREDITSSTATE_H

#include "State.h"
#include "Gui.h"

class CreditsState :
	public State
{
private:
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font buttonFont;
	sf::Font creditsFont;

	sf::RectangleShape btnBackground;
	std::map<std::string, gui::Button*> buttons;

	std::vector<sf::VideoMode> modes;

	sf::Text creditsText;

	//Functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	CreditsState(StateData* state_data);
	virtual ~CreditsState();

	//Functions
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif
