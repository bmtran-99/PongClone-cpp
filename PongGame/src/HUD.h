#pragma once

namespace Pong
{
	class HUD
	{
	public:
		HUD();
		~HUD();

		void OnUpdate();
		void Draw(unsigned int width, unsigned int height, std::string& result);

		inline unsigned int GetPlayer1Score() { return m_ScoreP1; }
		inline unsigned int GetPlayer2Score() { return m_ScoreP2; }

		inline bool CheckWinner()
		{ 
			if (m_ScoreP1 == 10 || m_ScoreP2 == 10)
				return true;
			else return false;
		}

		std::string Dashboard();

	private:
		void SetPlayerScore();
		std::string DisplayScore(unsigned int score);

		unsigned int m_ScoreP1 = 0;
		unsigned int m_ScoreP2 = 0;
	};
}

