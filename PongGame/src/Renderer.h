#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "HUD.h"

namespace Pong
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Init();
		void Draw();
		void Update();
	private:
		std::unique_ptr<HUD> m_HUD;
		std::shared_ptr<Paddle> player_left;
		std::shared_ptr<Paddle> player_right;
		std::unique_ptr<Ball> ball;
	};
}