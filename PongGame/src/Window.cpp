#include "pong_pch.h"
#include "Window.h"
#include "Renderer.h"

const int INTERVAL = 1000 / 60;

namespace Pong
{
	std::unique_ptr<Renderer> m_Renderer = std::make_unique<Renderer>();

	void Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		m_Renderer->Draw();

		glutSwapBuffers();
	}

	void Update(int value)
	{
		m_Renderer->Update();

		glutTimerFunc(INTERVAL, Update, 0);
		glutPostRedisplay();
	}

	Window::Window(const WindowProps& props)
	{
		Init(props);
	}

	Window::~Window()
	{
	}

	void Window::Init(const WindowProps& props)
	{
		glutInitWindowSize(props.Width, props.Height);
		glutCreateWindow(props.Title.c_str());

		glutDisplayFunc(Draw);
		glutTimerFunc(INTERVAL, Update, 0);

		glViewport(0, 0, props.Width, props.Height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, props.Width, 0.0f, props.Height, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void Window::OnUpdate()
	{
		glutMainLoop();
	}
}