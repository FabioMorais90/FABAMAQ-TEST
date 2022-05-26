#pragma once
//Class resposible for socre keeping and converting score into prizes
class Score
{
private:
	int points = 0;

public:
	//default constructor
	Score();

	//parameterized constructor (default state is false)
	Score(int newPoints);

	//Copy Constructor
	Score(const Score& score);

	//destructor
	~Score();

	//increments by 1
	void Increase();
	
	//decrements by 1
	void Decrease();

	//Set new value of points
	void SetPoints(int newPoints);

	//Get value of points
	int GetPoints();
};

