#include "GameController.h"

GameController::GameController()
{
	credits = Credits(0);
	score = Score(0);
	nPlays = 0;
	timeLeft = 0;
	//Init the board
	board = new Square[BOARD_HEIGHT * BOARD_WIDTH]();
	gameState = GameState::Stopped;
	Color target = Color::white;
	//Create Patterns
	CreateColorPatterns();
}

GameController::GameController(const GameController& game) {
	credits = game.credits;
	score = game.score;
	nPlays = game.nPlays;
	timeLeft = game.timeLeft;
	//copy the board
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			board[y * BOARD_WIDTH + x] = game.board[y * BOARD_WIDTH + x];
		}
	}
	gameState = game.gameState;
	target = game.target;
	CreateColorPatterns();
	animIndex = game.animIndex;
}

GameController::~GameController()
{
	delete[] animPattern;
	delete board;
}

Credits GameController::GetCredits()
{
	return credits;
}

void GameController::CreditsIn() {
	credits.CreditsIn();
}

unsigned int GameController::CreditsOut() {
	return credits.CreditsOut();
}

int GameController::GetScore()
{
	return score.GetPoints();
}

int GameController::GetNumberPlays()
{
	return nPlays;
}

unsigned int GameController::CalculateReward()
{
	unsigned int coins = 0;
	if (score.GetPoints() >= MIN_SCORE) {
		if (score.GetPoints() < MAX_SCORE) {
			coins = 1;
		}
		else {
			double n = ceil(score.GetPoints() / 10.0);
			coins = (unsigned int)n;
		}
	}
	credits.AddEarned(coins);
	return coins;
}

Color GameController::GetColor(int x, int y)
{
	return board[y * BOARD_WIDTH + x].GetColor();
}

bool GameController::GetState(int x, int y)
{
	return board[y * BOARD_WIDTH + x].GetState();
}

Color GameController::GetTarget()
{
	return target;
}

int GameController::GetTimeLeft()
{
	return timeLeft;
}

bool GameController::DecrementTime()
{
	if (gameState == GameState::Stopped || gameState == GameState::Paused) {
		return false;
	}
	else {
		timeLeft--;
		if (timeLeft == 0){
			EndGame();
			return false;
		}
		if (timeLeft % 5 == 0) {
			NextPattern();
			return true;
		}
	}
	return false;
}

void GameController::SelectTarget()
{
	srand((unsigned)time(0));
	//generate a random number between 1 and 5
	int output = 1 + (std::rand() % 5);
	target = Color(output);
}
	
GameState GameController::GetGameState()
{
	return gameState;
}

const char* GameController::GetGameStateText()
{
	switch (gameState)
	{
	case GameState::Stopped:
		return "Stopped";
		break;
	case GameState::Playing:
		return "Playing";
		break;
	case GameState::Paused:
		return "Paused";
		break;
	default:
		return "";
		break;
	}
}

bool GameController::StartGame()
{
	bool success = false;
	//start game if have credits
	if (credits.GetStored() > 0) {
		credits.Decrement();
		nPlays++;
		animIndex = 0;
		timeLeft = TIMER_START;
		ColorBoard();
		SelectTarget();
		gameState = GameState::Playing;
		success = true;
	}
	else {
		success = false;
	}
	return success;
}

void GameController::PauseGame()
{
	gameState = GameState::Paused;
}

void GameController::UnPauseGame()
{
	gameState = GameState::Playing;
}

bool GameController::EndGame()
{
	CalculateReward();
	Reset();
	return true;
}

void GameController::Reset()
{
	score = Score(0);
	//Init the board
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			board[y * BOARD_WIDTH + x] = Color::white;
		}
	}
	gameState = GameState::Stopped;
	Color target = Color::white;
	animIndex = 0;
}

void GameController::NextPattern()
{
	//next pattern index (if over limit, reset to zero)
	if (animIndex < BOARD_HEIGHT-1)
		animIndex++; 
	else
		animIndex = 0;
	//Recolor The board
	ColorBoard();	
}

bool GameController::HitTarget(int x, int y)
{
	bool success = false;
	if (gameState == GameState::Paused || gameState == GameState::Stopped) {
		success = false; //if the game is paused doesn't count
	}
	else {
		Square sq = board[y * BOARD_WIDTH + x]; //check the board
		if (sq.GetColor() == Color::black || sq.GetColor() == Color::white) {
			success = false; //invalid target
		}
		else if (sq.GetColor() != target) {
			success = false; //it was a Miss
		}
		else { // it was a Hit!
			board[y * BOARD_WIDTH + x].SetState(true);
			board[y * BOARD_WIDTH + x].SetColor(Color::black);
			score.Increase();
			success = true;
		}
	}
	return success;
}

void GameController::ColorBoard()
{
	//go by collum
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		//go by line
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			board[y * BOARD_WIDTH + x] = animPattern[animIndex][y];
		}
	}
}

void GameController::CreateColorPatterns()
{
	/* animPattern [collum][line]
	(Color::red,		Color::blue,	Color::green,	Color::yellow,	Color::orange);
	(Color::orange,		Color::red,		Color::blue,	Color::green,	Color::yellow);
	(Color::yellow,		Color::orange,	Color::red,		Color::blue,	Color::green);
	(Color::green,		Color::yellow,	Color::orange,	Color::red,		Color::blue);
	(Color::blue,		Color::green,	Color::yellow,	Color::orange,	Color::red); */
	animPattern[0][0] = animPattern[1][1] = animPattern[2][2] = animPattern[3][3] = animPattern[4][4] = Square(Color::red);
	animPattern[0][1] = animPattern[1][2] = animPattern[2][3] = animPattern[3][4] = animPattern[4][0] = Square(Color::orange);
	animPattern[0][2] = animPattern[1][3] = animPattern[2][4] = animPattern[3][0] = animPattern[4][1] = Square(Color::yellow);
	animPattern[0][3] = animPattern[1][4] = animPattern[2][0] = animPattern[3][1] = animPattern[4][2] = Square(Color::green);
	animPattern[0][4] = animPattern[1][0] = animPattern[2][1] = animPattern[3][2] = animPattern[4][3] = Square(Color::blue);
}


