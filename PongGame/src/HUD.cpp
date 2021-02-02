#include "pong_pch.h"
#include "HUD.h"
#include "Ball.h"

namespace Pong
{
	HUD::HUD()
	{
	}

	HUD::~HUD()
	{
	}

	void HUD::Draw(unsigned int width, unsigned int height, std::string& result)
	{
		glRasterPos2i(width, height);
		glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)result.c_str());
	}

	void HUD::OnUpdate()
	{
		SetPlayerScore();
	}

	std::string HUD::Dashboard()
	{
		if (m_ScoreP1 == 10)
			return "Player 1 won the game";
		else if (m_ScoreP2 == 10)
			return "Player 2 won the game";

		return DisplayScore(m_ScoreP1) + ":" + DisplayScore(m_ScoreP2);
	}

	std::string HUD::DisplayScore(unsigned int score)
	{
		std::stringstream ss;
		ss << score;
		return ss.str();
	}

	void HUD::SetPlayerScore()
	{
		if (Ball::GetBallState() == CollisionType::Left)
		{
			m_ScoreP2++;
			Ball::ResetBallState();
		}
			
		else if (Ball::GetBallState() == CollisionType::Right)
		{
			m_ScoreP1++;
			Ball::ResetBallState();
		}
	}
}
