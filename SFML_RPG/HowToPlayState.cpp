#include "stdafx.h"
#include "HowToPlayState.h"

void HowToPlayState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
}

void HowToPlayState::initFonts()
{
	if (!this->buttonFont.loadFromFile("Fonts/LLPIXEL3.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
	else if (!this->howtoplayFont.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void HowToPlayState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void HowToPlayState::initGui()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/howtoplaybg.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);

	//Buttons
	this->buttons["BACK"] = new gui::Button(
		gui::p2pX(72.f, vm), gui::p2pY(81.5f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->buttonFont, "Back", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	/*this->buttons["APPLY"] = new gui::Button(
		gui::p2pX(60.f, vm), gui::p2pY(81.5f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Apply", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));*/
		//Text init
		//this->optionsText.setFont(this->font);
		//this->optionsText.setPosition(sf::Vector2f(gui::p2pX(5.2f, vm), gui::p2pY(41.7f, vm)));
		//this->optionsText.setCharacterSize(gui::calcCharSize(vm, 70));
		//this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));

		//this->optionsText.setString(
		//	"Resolution \n\n"
		//);

	this->howtoplayText.setFont(this->howtoplayFont);
	this->howtoplayText.setPosition(sf::Vector2f(gui::p2pX(1.2f, vm), gui::p2pY(35.7f, vm)));
	this->howtoplayText.setCharacterSize(gui::calcCharSize(vm, 40));
	this->howtoplayText.setFillColor(sf::Color(255, 255, 255, 200));

	this->howtoplayText.setString(
		"\t   WASD        ->     Move Up/Down/Left/Right\n"
		"\tLEFT-CLICK     ->     Attack\n"
		"\t     C            ->     Toggle Character Tab\n"
		"\t    ESC          ->     Pause/Quit\n"
	);
}

void HowToPlayState::resetGui()
{
	/*
	 * Clears the GUI elements and re-initialises the GUI.
	 *
	 * @return void
	 */

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	this->buttons.clear();
	this->initGui();
}

HowToPlayState::HowToPlayState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
}

HowToPlayState::~HowToPlayState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}
//Accessors

//Functions
void HowToPlayState::updateInput(const float& dt)
{

}

void HowToPlayState::updateGui(const float& dt)
{
	/*Updates all the gui elements in the state and handle their functionlaity.*/
	//Buttons
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosWindow);
	}

	//Button functionality
	//Quit the game
	if (this->buttons["BACK"]->isPressed())
	{
		this->endState();
	}
}
void HowToPlayState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateGui(dt);
}

void HowToPlayState::renderGui(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}

void HowToPlayState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderGui(*target);

	target->draw(this->howtoplayText);

	//REMOVE LATER!!!
	sf::Text mouseText2;
	mouseText2.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText2.setFont(this->buttonFont);
	mouseText2.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText2.setString(ss.str());
	target->draw(mouseText2);
}