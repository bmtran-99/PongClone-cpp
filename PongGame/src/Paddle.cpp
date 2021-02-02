#include "pong_pch.h"
#include "Paddle.h"

// keycodes
#define VK_W 0x57
#define VK_S 0x53

namespace Pong
{
	Paddle::Paddle(const PaddleProps& props, glm::vec2 position)
		: m_Width(props.Width), m_Height(props.Height), m_Position(position)
	{

	}

	Paddle::~Paddle()
	{
	}

	void Paddle::OnRender()
	{
		glBegin(GL_QUADS);
		glVertex2i(m_Position.x, m_Position.y);
		glVertex2i(m_Position.x + m_Width, m_Position.y);
		glVertex2i(m_Position.x + m_Width, m_Position.y + m_Height);
		glVertex2i(m_Position.x, m_Position.y + m_Height);
		glEnd();
	}

	void Paddle::OnUpdate()
	{
		if (m_Position.x == 10.f)
		{
			if (GetAsyncKeyState(VK_W)) m_Position.y += SPEED;
			if (GetAsyncKeyState(VK_S)) m_Position.y -= SPEED;
		}
		else
		{
			if (GetAsyncKeyState(VK_UP)) m_Position.y += SPEED;
			if (GetAsyncKeyState(VK_DOWN)) m_Position.y -= SPEED;
		}
	}
}