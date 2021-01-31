#include "pong_pch.h"
#include "Renderer.h"
#include "Window.h"

namespace Pong
{
	Renderer::Renderer()
	{
		Init();
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Init()
	{
		m_HUD = std::make_unique<HUD>();

		player_left = std::make_shared<Paddle>(PaddleProps(), glm::vec2(10.f, 250.f));
		player_right = std::make_shared<Paddle>(PaddleProps(), glm::vec2(Window::GetWidth() -
			player_left->GetPaddleWidth() - 10.f, 250.f));

		ball = std::make_unique<Ball>(glm::vec2((Window::GetWidth() - Ball::GetBallSize()) / 2,
			(Window::GetHeight() - Ball::GetBallSize()) / 2));
	}

	void Renderer::Draw()
	{
		m_HUD->Draw(Window::GetWidth() / 2 - 10, 
			Window::GetHeight() - 15, m_HUD->Dashboard());

		player_left->OnRender();
		player_right->OnRender();
		ball->OnRender();
	}

	void Renderer::Update()
	{
		m_HUD->OnUpdate();
		player_left->OnUpdate();
		player_right->OnUpdate();
		ball->OnUpdate();
	}
}