#pragma once
//Class that is responsible for the insert and retrieve of the credits 
class Credits
{
private:
	// Number of Credits Inserted
	unsigned int inserted = 0; 
	// Number of Credits Retrieved
	unsigned int retrieved = 0;
	// Number of Credits Available
	unsigned int stored = 0;

public:
	//default constructor
	Credits();

	//parameterized constructor (default state is false)
	Credits(unsigned int newTotal, unsigned int nInserted = 0, unsigned int nRetrieved = 0);

	//Copy Constructor
	Credits(const Credits& score);

	//destructor
	~Credits();

	//Insert Credits
	void CreditsIn();

	//Retrieve Credits
	unsigned int CreditsOut();

	//Get value of stored
	unsigned int GetStored();

	//Get value of Retrieved
	unsigned int GetRetrieved();

	//Get value of Inserted
	unsigned int GetInserted();

	//Decrement credits
	void Decrement();

	//Add credits earned
	void AddEarned(int n);

};

