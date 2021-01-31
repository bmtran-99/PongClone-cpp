#pragma once

namespace Pong
{
	class HUD
	{
	public:
		HUD();
		~HUD();

		void OnUpdate();
		void Draw(unsigned int width, unsigned int height, std::string& score);

		inline static HUD& GetHUD() { return *m_Instance; }

		inline unsigned int GetPlayer1Score() { return m_ScoreP1; }
		inline unsigned int GetPlayer2Score() { return m_ScoreP2; }

		void SetPlayerScore();
		std::string Dashboard();

	private:
		static HUD* m_Instance;
		std::string DisplayScore(unsigned int score);

		unsigned int m_ScoreP1 = 0;
		unsigned int m_ScoreP2 = 0;
	};
}

