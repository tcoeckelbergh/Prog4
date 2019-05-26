#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "Scene.h"
#include "TextComponent.h"
#include "TextureComponent.h"
#include "GridLevel.h"

//******************************
// TEST CHANGE COMMIT FOR GIT
//******************************

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		g_ScreenWidth,
		g_ScreenHeight,
		SDL_WINDOW_OPENGL
	);
	if (window == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	auto background = std::make_shared<GameObject>();
	background->AddComponent(new TextureComponent("background.jpg"));
	scene.Add(background);

	auto logo = std::make_shared<GameObject>();
	logo->AddComponent(new TextureComponent("logo.png"));
	logo->SetPosition(216, 180);
	scene.Add(logo);

	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto titel = std::make_shared<GameObject>();
	titel->AddComponent(new TextComponent("Programming 4 assignment", font));
	titel->GetComponent<TextComponent>()->SetPosition(80, 20);
	scene.Add(titel);

	auto fpsFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	m_FpsCounter->AddComponent(new TextComponent("FPS", fpsFont));
	m_FpsCounter->GetComponent<TextComponent>()->SetPosition(10, 10);
	scene.Add(m_FpsCounter);

	// INPUT (MOVE TO GAMECODE)
	auto& inputM = InputManager::GetInstance();
	inputM.AssignButton(dae::ControllerButton::ButtonY, new JumpCommand());
	inputM.AssignButton(dae::ControllerButton::ButtonX, new FireCommand());
	inputM.AssignButton(dae::ControllerButton::ButtonB, new FartCommand());
	inputM.AssignButton(dae::ControllerButton::ButtonA, new DuckCommand());
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto t = std::chrono::high_resolution_clock::now();
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		//	Since this engine will be created to make old 2D single-player / local co-op arcady games
		// we will use the "Fixed time step with synchronization" game loop design pattern since
		// these games are so easy to run with the current hardware and noone should have any issues
		// getting to 60 FPS there is no need for a more complex loop to account for this issue.
		//	This gameloop just provides us with a cap on the framerate at 60FPS so that the game
		// doesn't run faster depending on the power of your machine
		while (true)
		{
			auto start = std::chrono::high_resolution_clock::now();

			input.ProcessInput();
			if (InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonX))
				break;

			sceneManager.Update();

			// I chose not to make a component for the FPS specifically since I feel you'll only
			// ever need one of it and a simple TextComponent does the same thing.
			m_FpsCounter->GetComponent<TextComponent>()->SetText(std::to_string((int)m_FPS) + " FPS");

			renderer.Render();

			t += std::chrono::milliseconds(msPerFrame);

			CalculateFPS();

			std::this_thread::sleep_until(t);
		}
	}

	Cleanup();
}

float dae::Minigin::GetFPS() const
{
	return m_FPS;
}

void dae::Minigin::CalculateFPS()
{
	// https://www.youtube.com/watch?v=4cwpXJIHaMo
	// I used this video for this function
	// Global variables only accessible inside this function
	// Initialised once and then retain their state
	static const int nrSamples = 10;
	static float frameTimes[nrSamples];
	static int currentFrame = 0;

	static float prevTicks = (float)SDL_GetTicks();

	float currentTicks;
	currentTicks = (float)SDL_GetTicks();

	m_FrameTime = currentTicks - prevTicks;

	// % creates the circular buffer effect
	frameTimes[currentFrame % nrSamples] = m_FrameTime;

	prevTicks = currentTicks;

	int count;

	if (currentFrame < nrSamples)
		count = currentFrame;
	else count = nrSamples;

	float frameTimeAvg = 0;
	for (int i = 0; i < count; ++i)
	{
		frameTimeAvg += frameTimes[i];
	}
	frameTimeAvg /= count;

	if (frameTimeAvg > 0)
		m_FPS = 1000.0f / frameTimeAvg;
	else m_FPS = 70;

	++currentFrame;
}
