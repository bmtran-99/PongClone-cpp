#include "pong_pch.h"
#include "HUD.h"

namespace Pong
{
	HUD* HUD::m_Instance = nullptr;

	HUD::HUD()
	{
		m_Instance = this;
	}

	HUD::~HUD()
	{

	}

	void HUD::Draw(unsigned int width, unsigned int height, std::string& score)
	{
		glRasterPos2i(width, height);
		glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)score.c_str());
	}

	void HUD::OnUpdate()
	{

	}

	std::string HUD::Dashboard()
	{
		return DisplayScore(m_Instance->GetPlayer1Score()) + ":" + m_Instance->DisplayScore(m_Instance->GetPlayer2Score());
	}

	std::string HUD::DisplayScore(unsigned int score)
	{
		std::stringstream ss;
		ss << score;
		return ss.str();
	}
}
