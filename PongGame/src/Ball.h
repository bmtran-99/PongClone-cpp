#pragma once

namespace Pong
{
	class Ball
	{
	public:
		Ball(glm::vec2 position);
		~Ball();

		void OnRender();
		void OnUpdate();

		static inline uint32_t GetBallSize() { return m_Size; }
	private:
		static const uint32_t m_Size = 8;
		glm::vec2 m_Position;
	};
}