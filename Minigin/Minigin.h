#pragma once
#include "GameObject.h"

struct SDL_Window;

namespace dae
{
	//Global ScreenWidth and Height
	static const int g_ScreenWidth = 640;
	static const int g_ScreenHeight = 480;

	class Minigin
	{
		const int msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* window{};
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();
		float GetFPS() const;

	private:
		void CalculateFPS();

		float m_FPS;
		float m_FrameTime;
		std::shared_ptr<GameObject> m_FpsCounter = std::make_shared<GameObject>();
	};
}