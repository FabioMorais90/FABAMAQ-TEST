#include "Score.h"

Score::Score()
{
	points = 0;
}

Score::Score(int newPoints)
{
	points = newPoints;
}

void Score::Increase()
{
	points++;
}

void Score::Decrease()
{
	points--;
}

void Score::SetPoints(int newPoints)
{
	points = newPoints;
}

int Score::GetPoints()
{
	return points;
}

Score::Score(const Score& score)
{
	points = score.points;
}

Score::~Score()
{
}


