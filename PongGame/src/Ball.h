#pragma once

#include "Paddle.h"

namespace Pong
{
	enum class CollisionType
	{
		None,
		Top,
		Middle,
		Bottom,
		Left,
		Right
	};


	class Ball
	{
	public:
		Ball(glm::vec2 position);
		~Ball();

		void OnRender();
		void OnUpdate(Paddle& paddle_one, Paddle& paddle_two);

		static inline uint32_t GetBallSize() { return m_Size; }
		static inline CollisionType GetBallState() { return m_BallState; }

		static inline void ResetBallState() { m_BallState = CollisionType::None; }
	private:
		void CollideWithPaddle(const CollisionType& collision);
		void CollideWithWall(const CollisionType& collision);

		CollisionType CheckWallCollision();
		CollisionType CheckPaddleCollision(Paddle& paddle);

		static const uint32_t m_Size = 8;

		static CollisionType m_BallState;

		const uint32_t SPEED = 8;

		const float OFFSET_ANGLE = 0.25;

		glm::vec2 m_Position, m_Velocity, m_InitalPosition, m_InitialVelocity;
	};
}