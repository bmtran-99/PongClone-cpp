#include "pong_pch.h"
#include "Ball.h"
#include "Window.h"

namespace Pong
{
	CollisionType Ball::m_BallState = CollisionType::None;

	Ball::Ball(glm::vec2 position) : m_Position(position), m_Velocity(glm::vec2(-1.f, 0.f)), m_InitalPosition(position)
	{
		m_InitialVelocity = m_Velocity;
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

	void Ball::CollideWithPaddle(const CollisionType& collision)
	{
		m_Velocity.x = -m_Velocity.x;

		if (collision == CollisionType::Top)
			m_Velocity.y = -OFFSET_ANGLE * SPEED;

		else if (collision == CollisionType::Bottom)
			m_Velocity.y = OFFSET_ANGLE * SPEED;
	}

	CollisionType Ball::CheckPaddleCollision(Paddle& paddle)
	{
		float paddleLeft = paddle.GetPaddlePosition().x;
		float paddleRight = paddle.GetPaddlePosition().x + paddle.GetPaddleWidth();
		float paddleTop = paddle.GetPaddlePosition().y;
		float paddleBottom = paddle.GetPaddlePosition().y + paddle.GetPaddleHeight();

		float paddleRangeUpper = paddleBottom - (2.0f * paddle.GetPaddleHeight() / 3.0f);
		float paddleRangeMiddle = paddleBottom - (paddle.GetPaddleHeight() / 3.0f);

		bool hit = m_Position.x < paddleRight && m_Position.x > paddleLeft && m_Position.y < paddleBottom && m_Position.y > paddleTop;

		if (hit)
		{
			if (m_Position.y < paddleRangeUpper)
				return CollisionType::Top;
				
			else if (m_Position.y > paddleRangeUpper && m_Position.y < paddleRangeMiddle)
				return CollisionType::Middle;

			else return CollisionType::Bottom;
		}

		return CollisionType::None;
	}

	void Ball::CollideWithWall(const CollisionType& collision)
	{
		switch (collision)
		{
		case CollisionType::Top:
			m_Velocity.y = -m_Velocity.y;
			break;

		case CollisionType::Bottom:
			m_Velocity.y = -m_Velocity.y;
			break;
		
		case CollisionType::Left:
			m_Position = m_InitalPosition;
			m_Velocity = m_InitialVelocity;
			break;

		case CollisionType::Right:
			m_Position = m_InitalPosition;
			m_Velocity = m_InitialVelocity;
			break;
		}
	}

	CollisionType Ball::CheckWallCollision()
	{
		if (m_Position.x < 0.f)
			return CollisionType::Left;

		else if (m_Position.x + m_Size > Window::GetWidth())
			return CollisionType::Right;

		else if (m_Position.y < 0.f)
			return CollisionType::Bottom;

		else if (m_Position.y + m_Size > Window::GetHeight())
			return CollisionType::Top;

		return CollisionType::None;
	}

	void Ball::OnUpdate(Paddle& paddle_one, Paddle& paddle_two)
	{
		m_Position.x += m_Velocity.x * SPEED;
		m_Position.y += m_Velocity.y * SPEED;

		CollisionType collision_left = CheckPaddleCollision(paddle_one);
		CollisionType collision_right = CheckPaddleCollision(paddle_two);
		CollisionType collision_wall = CheckWallCollision();

		m_BallState = collision_wall;

		if (collision_left != CollisionType::None)
			CollideWithPaddle(collision_left);

		else if (collision_right != CollisionType::None)
			CollideWithPaddle(collision_right);

		else if (collision_wall != CollisionType::None)
			CollideWithWall(collision_wall);
	}
}