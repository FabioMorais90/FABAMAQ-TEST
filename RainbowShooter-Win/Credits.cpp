#include "Credits.h"

Credits::Credits()
{
	stored = 0;
	inserted = 0;
	retrieved = 0;
}

Credits::Credits(unsigned int newTotal, unsigned int nInserted, unsigned int nRetrieved)
{
	stored = newTotal;
	inserted = nInserted;
	retrieved = nRetrieved;
}

void Credits::CreditsIn()
{
	stored++;
	inserted++;
}

unsigned int Credits::CreditsOut()
{
	unsigned int result = stored;
	retrieved += stored;
	stored = 0;
	return result;
}

unsigned int Credits::GetStored()
{
	return stored;
}

unsigned int Credits::GetRetrieved()
{
	return retrieved;
}

unsigned int Credits::GetInserted()
{
	return inserted;
}

void Credits::Decrement()
{
	if (stored > 0)
		stored--;
}

void Credits::AddEarned(int n)
{
	stored += n;
}

Credits::Credits(const Credits& score) {
	stored = score.stored;
	inserted = score.inserted;
	retrieved = score.retrieved;
}

Credits::~Credits()
{
}
