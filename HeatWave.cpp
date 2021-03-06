#include "stdafx.h"
#include "HeatWave.h"

#include "Wire.h"

HeatWave::HeatWave()
{
}


HeatWave::~HeatWave()
{
}

// initializes things and runs the game loop
void HeatWave::start() {

	// do initialization
	initializeSFML();
	
	// initialize IMGUI
	initializeIMGUI();

	// run the game loop
	while (window.isOpen())
		gameLoop();
}

void HeatWave::initializeSFML() {

	new (&window) sf::RenderWindow(sf::VideoMode(1024, 768), "Heat Wave");
}

// setup imgui, called before the game loop
void HeatWave::initializeIMGUI() {

	ImGui::SFML::SetWindow(window);
	ImGui::SFML::SetRenderTarget(window);
	ImGui::SFML::InitImGuiRendering();
	ImGui::SFML::InitImGuiEvents();
}

// runs the game etc
void HeatWave::gameLoop() {

	static hwgame::Wire testWire = hwgame::Wire(frameUpdateDispatcher);

	pollWindowEvents(frameUpdateEvent.sfEvents);

	for (unsigned i = 0; i < frameUpdateEvent.sfEvents.size(); i++) {

		// send every event to IMGUI
		ImGui::SFML::ProcessEvent(frameUpdateEvent.sfEvents[i]);

		if (frameUpdateEvent.sfEvents[i].type == sf::Event::Closed)
			window.close();
	}

	// frame update
	frameUpdateDispatcher.fire(frameUpdateEvent);

	// update IMGUI
	ImGui::SFML::UpdateImGui();
	ImGui::SFML::UpdateImGuiRendering();

	ImGuiIO& io = ImGui::GetIO();

	ImGui::ShowTestWindow();

	window.clear(sf::Color(255, 255, 255, 255));

	ImGui::Render();
	window.display();
}

// polls all the window events for a frame and puts them in a vector
// returns the number of events polled
int HeatWave::pollWindowEvents(std::vector<sf::Event>& events) {

	unsigned int nEvent = 0;
	events.resize(1);

	while (window.pollEvent(events[nEvent])) {

		// resize if appropriate
		if (nEvent == events.size() - 1)
			events.resize(events.size() + 1);

		nEvent++;
	}

	if (nEvent == 0)
		events.resize(0);
	else
		events.resize(events.size() - 1);

	return events.size();
}