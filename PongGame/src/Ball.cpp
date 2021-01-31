#include "pong_pch.h"
#include "Ball.h"

namespace Pong
{
	Ball::Ball(glm::vec2 position) : m_Position(position)
	{
	}

	Ball::~Ball()
	{
	}

	void Ball::OnRender()
	{
		glBegin(GL_QUADS);
		glVertex2i(m_Position.x, m_Position.y);
		glVertex2i(m_Position.x + m_Size, m_Position.y);
		glVertex2i(m_Position.x + m_Size, m_Position.y + m_Size);
		glVertex2i(m_Position.x, m_Position.y + m_Size);
		glEnd();
	}

	void Ball::OnUpdate()
	{

	}
}