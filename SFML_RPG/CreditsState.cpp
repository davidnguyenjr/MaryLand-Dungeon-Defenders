#include "stdafx.h"
#include "CreditsState.h"

void CreditsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
}

void CreditsState::initFonts()
{
	if (!this->buttonFont.loadFromFile("Fonts/LLPIXEL3.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
	else if (!this->creditsFont.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void CreditsState::initKeybinds()
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

void CreditsState::initGui()
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

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/creditsbg.png"))
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

	this->creditsText.setFont(this->creditsFont);
	this->creditsText.setPosition(sf::Vector2f(gui::p2pX(1.2f, vm), gui::p2pY(35.7f, vm)));
	this->creditsText.setCharacterSize(gui::calcCharSize(vm, 200));
	this->creditsText.setFillColor(sf::Color(255, 255, 255, 200));

	this->creditsText.setString(
		"Player Credits: \n"
		"Authors: Stephen Challener(Redshrike), Johannes Sjölund(wulax), Matthew Krohn(makrohn),\n"
		"Thane Brimhall(pennomi), ElizaWy, bluecarrot16, Nila122, David Conway Jr. (JaidynReiman), Joe White\n"

		"-body / female / human / white.png: by Stephen Challener(Redshrike), Johannes Sjölund(wulax), Matthew Krohn(makrohn).License(s) : CC - BY - SA 3.0, GPL 3.0.\n" 
		
		"\t-https://opengameart.org/content/lpc-medieval-fantasy-character-sprites\n" 
		"\t-https://opengameart.org/content/lpc-ladies\n"

		"-head / nose / button / female / light.png : by Thane Brimhall(pennomi), Matthew Krohn(makrohn).License(s) : GPL 3.0, CC - BY - SA 3.0.\n" 
		"\t-https://opengameart.org/content/lpc-base-character-expressions\n" 

		"-eyes / female / blue.png : by Matthew Krohn(makrohn), Stephen Challener(Redshrike).License(s) : CC - BY - SA 3.0, GPL 3.0.\n" 
		"\t-https://opengameart.org/content/liberated-pixel-cup-lpc-base-assets-sprites-map-tiles\n" 

		"-hair / high_ponytail / female / black.png : by ElizaWy, bluecarrot16.License(s) : OGA - BY 3.0.\n" 
		"\t-https://opengameart.org/content/lpc-hair\n" 

		"-facial / earring / female / gold.png : by bluecarrot16.License(s) : CC - BY - SA 3.0.\n" 
		"\t-https://opengameart.org/content/lpc-pirates\n" 

		"-torso / clothes / corset / female / black.png : by ElizaWy, Nila122.License(s) : CC - BY - SA 3.0, GPL 3.0.\n" 
		"\t-https://opengameart.org/content/lpc-clothes-and-hair\n" 
		"\t-https://opengameart.org/content/lpc-7-womens-shirts\n" 

		"-torso / clothes / longsleeve / female / blue.png : by ElizaWy.License(s) : CC - BY - SA 3.0, GPL 3.0.\n" 
		"\t-https://opengameart.org/content/lpc-7-womens-shirts\n" 

		"-torso / waist / belt_loose / female / white.png : by bluecarrot16, Johannes Sjölund(wulax), Matthew Krohn(makrohn).License(s) : CC - BY - SA 3.0, GPL 3.0.\n" 
		"\t-https://opengameart.org/content/lpc-combat-armor-for-women\n" 
		"\t-https://opengameart.org/content/lpc-pirates\n" 

		"-legs / pants / female / black.png : by bluecarrot16, David Conway Jr. (JaidynReiman), Joe White, Matthew Krohn(makrohn), Johannes Sjölund(wulax).License(s) : CC - BY - SA 3.0, GPL 3.0.\n" 
		"\t-https://opengameart.org/content/liberated-pixel-cup-lpc-base-assets-sprites-map-tiles\n" 
		"\t-https://opengameart.org/content/lpc-medieval-fantasy-character-sprites\n" 

		"-feet / boots / female / blue.png : by Nila122, Johannes Sjölund(wulax), Stephen Challener(Redshrike).License(s) : CC - BY - SA 3.0, GPL 2.0, GPL 3.0.\n" 
		 "\thttps://opengameart.org/content/lpc-clothes-and-hair\n" 
	);
}

void CreditsState::resetGui()
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

CreditsState::CreditsState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
}

CreditsState::~CreditsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}
//Accessors

//Functions
void CreditsState::updateInput(const float& dt)
{

}

void CreditsState::updateGui(const float& dt)
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
void CreditsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateGui(dt);
}

void CreditsState::renderGui(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}

void CreditsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderGui(*target);

	target->draw(this->creditsText);

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