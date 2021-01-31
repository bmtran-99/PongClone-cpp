#include "pong_pch.h"
#include "Paddle.h"

#define SPEED = 3;

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

	}
}