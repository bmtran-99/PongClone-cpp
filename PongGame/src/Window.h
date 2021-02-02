#pragma once

#include "Renderer.h"

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

	static WindowProps props;

	class Window
	{
	public:
		Window(const WindowProps& props = WindowProps());
		~Window();

		static inline unsigned int GetWidth() { return props.Width; }
		static inline unsigned int GetHeight() { return props.Height; }

		static inline Renderer& GetRenderer() { return *m_Renderer; }

		void OnUpdate();

	private:
		void Init(const WindowProps& props);

		static std::unique_ptr<Renderer> m_Renderer;
	};
}