#pragma once

namespace Pong
{
	struct PaddleProps
	{
		unsigned int Width;
		unsigned int Height;

		PaddleProps(unsigned int width = 10, unsigned int height = 80) : Width(width), Height(height) {}
	};

	class Paddle
	{
	public:
		Paddle(const PaddleProps& props, glm::vec2 position);
		~Paddle();

		void OnRender();
		void OnUpdate();

		inline unsigned int GetPaddleWidth() { return m_Width; }
		inline unsigned int GetPaddleHeight() { return m_Height; }

		inline glm::vec2 GetPaddlePosition() { return m_Position; }

	private:
		unsigned int m_Width, m_Height;

		const uint32_t SPEED = 3;

		glm::vec2 m_Position;
	};
}