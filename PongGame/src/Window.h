#pragma once

namespace Pong
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Pong", unsigned int width = 1200, unsigned int height = 600)
			: Title(title), Width(width), Height(height) {}
	};

	static WindowProps m_Props;

	class Window
	{
	public:
		Window(const WindowProps& props = WindowProps());
		~Window();

		static inline unsigned int GetWidth() { return m_Props.Width; }
		static inline unsigned int GetHeight() { return m_Props.Height; }

		void OnUpdate();

	private:
		void Init(const WindowProps& props);
	};
}