#include "Square.h"

Square::Square() {
	state = false;
	color = Color::white;
}

Square::Square( Color newColor, bool newState) {
	state = newState;
	color = newColor;
}

Square::Square(const Square& square) {
	state = square.state;
	color = square.color;
}

Square::~Square() {}

Color Square::GetColor() { return color; }

void Square::SetColor(Color newColor) { color = newColor; }

bool Square::GetState() { return state; }

void Square::SetState(bool newState) { state = newState; }
