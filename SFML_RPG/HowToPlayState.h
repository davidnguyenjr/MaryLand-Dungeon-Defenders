#ifndef HOWTOPLAYSTATE_H
#define HOWTOPLAYSTATE_H

#include "State.h"
#include "Gui.h"

class HowToPlayState :
	public State
{
private:
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font buttonFont;
	sf::Font howtoplayFont;

	sf::RectangleShape btnBackground;
	std::map<std::string, gui::Button*> buttons;

	std::vector<sf::VideoMode> modes;

	sf::Text howtoplayText;

	//Functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	HowToPlayState(StateData* state_data);
	virtual ~HowToPlayState();

	//Functions
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif
