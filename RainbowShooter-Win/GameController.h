#pragma once
#include <math.h>  
#include <cstdlib>
#include <ctime>

#include "Square.h"
#include "Score.h"
#include "Credits.h"

//Define the timer starting point (in seconds)
#define TIMER_START 60

//Define the range to get 1 credit as reward
#define	MIN_SCORE 30
#define	MAX_SCORE 50

//Define the Height(number of lines) and Width (number of columns)
#define BOARD_HEIGHT 5
#define BOARD_WIDTH 10

enum class GameState {
	Stopped = 0,
	Playing = 1,
	Paused = 2
};

//Class that holds all the data and logic of the game
class GameController
{
private:
	Credits credits;
	Score score;
	int nPlays;
	//This board is made of h columns with w lines
	Square* board;
	/*A collection of line patterns for each animation step
	 A height*N array, where height is the number of lines of the board and N the number of patterns desired
	*/
	Square animPattern[BOARD_HEIGHT][BOARD_HEIGHT];
	//Indicates what collum of the Patterns grid is the current pattern
	int animIndex = 0;
	//Indicates if the game is paused, stopped or playing
	GameState gameState = GameState::Stopped;
	//Indicates the shooting target
	Color target = Color::white;
	// Time Left to play indicator
	int timeLeft;

public:

	//default constructor
	GameController();

	//Copy Constructor
	GameController(const GameController& game);

	//destructor
	~GameController();

	// get credits to display
	Credits GetCredits();

	//Insert Credits;
	void CreditsIn();

	//Retrieve Credits
	unsigned int CreditsOut();

	//get Score to display
	int GetScore();

	//get number of plays
	int GetNumberPlays();

	//Calculate the score into credits
	// if within MIN_SCORE and MAX_SCORE you get 1 credit
	// if more, you get credits equal to the score / 10 (rounded up)
	unsigned int CalculateReward();

	//get color from square in (column ,line)
	Color GetColor(int collum, int line);

	//get state from square in column x and line y
	bool GetState(int collum, int line);

	//get the shooting target
	Color GetTarget();

	//get the time left
	int GetTimeLeft();

	//Decrement Time Left, returns true is the pattern changed
	bool DecrementTime();

	//Select Random Color for Target
	void SelectTarget();

	//get the game state
	GameState GetGameState();
	
	//get the game state in text
	const char* GetGameStateText();

	//Start Game (returns true if successful)
	bool StartGame();

	//Pause Game
	void PauseGame();

	//Unpause Game
	void UnPauseGame();

	//End the gameGame
	bool EndGame();

	//Resets the gameboard to initial state
	void Reset();
	
	//Change the pattern
	void NextPattern();

	//Hitting fuction that checks if the player hit the correct target in (x,y)
	bool HitTarget(int x, int y);

private:

	//aux function to color the board
	void ColorBoard();

	//aux function to create the color patterns
	void CreateColorPatterns();

};

