#pragma once
//enum that indicates a color. Black is a hitted square, white is a disabled square
enum class Color {
	black = -1,
	white = 0,
	red = 1,
	orange = 2,
	yellow = 3,
	green = 4,
	blue = 5,
};

//Class that holds the color and the state of a square
class Square
{
private: 
	bool state = false; //indicates if was hit or not
	Color color = Color::white;

public:
	//default constructor
	Square();

	//parameterized constructor (default state is false)
	Square(Color newColor, bool newState = false );

	//Copy Constructor
	Square(const Square& square);

	//destructor
	~Square();

	//Get color in square
	Color GetColor();

	//Set new Color
	void SetColor(Color newColor);

	//Get the state of this square
	bool GetState();

	//Set the new state of this square
	void SetState(bool newState);
};

