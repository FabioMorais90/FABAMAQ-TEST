///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "cMain.h"

///////////////////////////////////////////////////////////////////////////

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10101, OnStartButton)
	EVT_BUTTON(10102, OnCreditsInButton)
	EVT_BUTTON(10103, OnCreditsOutButton)
	EVT_TIMER(10104, OnTimer)
wxEND_EVENT_TABLE()

cMain::cMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	//init the gameCtrl
	m_gameCTRL = new GameController();
	timer = new wxTimer(this, 10104);

	this->SetSizeHints(wxSize(804, 500), wxDefaultSize);
	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer(0, 0);
	gbSizer1->SetFlexibleDirection(wxBOTH);
	gbSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Target : "), wxDefaultPosition, wxSize(60, 20), 0);
	m_staticText1->Wrap(-1);
	m_staticText1->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticText1, wxGBPosition(0, 0), wxGBSpan(1, 6), wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

	m_buttonTarget = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(30, 25), 0);
	m_buttonTarget->SetBackgroundColour(GetWXColor(m_gameCTRL->GetTarget()));
	m_buttonTarget->Enable(false);
	gbSizer1->Add(m_buttonTarget, wxGBPosition(0, 6), wxGBSpan(1, 1), wxALL, 5);

	//Game State text
	m_staticTextState = new wxStaticText(this, wxID_ANY, m_gameCTRL->GetGameStateText(), wxDefaultPosition, wxSize(80, 20), wxALIGN_CENTRE);
	m_staticTextState->Wrap(-1);
	m_staticTextState->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextState, wxGBPosition(0, 21), wxGBSpan(1, 5), wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

	//Timer see How to do a timer
	wxString timeLeftText;
	timeLeftText << m_gameCTRL->GetTimeLeft();
	m_staticTextTimer = new wxStaticText(this, wxID_ANY, timeLeftText, wxDefaultPosition, wxSize(40, 20), wxALIGN_CENTRE);
	m_staticTextTimer->Wrap(-1);
	m_staticTextTimer->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextTimer, wxGBPosition(0, 26), wxGBSpan(1, 4), wxALL | wxEXPAND, 5);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Score :"), wxDefaultPosition, wxSize(60, 20), wxALIGN_RIGHT);
	m_staticText2->Wrap(-1);
	m_staticText2->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticText2, wxGBPosition(0, 56), wxGBSpan(1, 6), wxALL | wxEXPAND, 5);

	//Score counter text
	wxString scoretext;
	scoretext << m_gameCTRL->GetScore();
	m_staticTextScore = new wxStaticText(this, wxID_ANY, scoretext, wxDefaultPosition, wxSize(40, 20), wxALIGN_RIGHT);
	m_staticTextScore->Wrap(-1);
	m_staticTextScore->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextScore, wxGBPosition(0, 62), wxGBSpan(1, 4), wxALL | wxEXPAND, 5);

	//CREATE THE BOARD PANEL
	m_panelBoard = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(136, 20), wxTAB_TRAVERSAL);
	m_panelBoard->SetBackgroundColour(wxColour(255, 255, 255));

	btnSquares = new wxButton * [nWidth * nHeight];
	wxGridSizer* gSizerBoard;
	gSizerBoard = new wxGridSizer(nHeight, nWidth, 0, 0);
	for (int y = 0; y < nHeight; y++) //goes from 0 to 5 (lines)
	{
		for (int x = 0; x < nWidth; x++)//goes from 0 to 10 (collumns)
		{
			btnSquares[y * nWidth + x] = new wxButton(m_panelBoard, (10000 + (y * nWidth + x)), wxT(""), wxDefaultPosition, wxDefaultSize, 0);
			btnSquares[y * nWidth + x]->SetBackgroundColour(GetWXColor(m_gameCTRL->GetColor(x, y)));
			btnSquares[y * nWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
			gSizerBoard->Add(btnSquares[y * nWidth + x], 0, wxALL | wxEXPAND, 5);
		}
	}
	m_panelBoard->SetSizer(gSizerBoard);
	m_panelBoard->Layout();
	gSizerBoard->Fit(m_panelBoard);
	gbSizer1->Add(m_panelBoard, wxGBPosition(1, 0), wxGBSpan(15, 68), wxALL | wxEXPAND, 5);

	m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Number of Plays :"), wxDefaultPosition, wxSize(136, 20), wxALIGN_LEFT);
	m_staticText3->Wrap(-1);
	m_staticText3->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticText3, wxGBPosition(16, 0), wxGBSpan(1, 11), wxALL, 5);

	//Number of Plays Counter
	wxString playsText;
	playsText << m_gameCTRL->GetNumberPlays();
	m_staticTextPlays = new wxStaticText(this, wxID_ANY, playsText, wxDefaultPosition, wxSize(40, 20), wxALIGN_LEFT);
	m_staticTextPlays->Wrap(-1);
	m_staticTextPlays->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextPlays, wxGBPosition(16, 11), wxGBSpan(1, 5), wxALL, 5);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Coins Inserted :"), wxDefaultPosition, wxSize(136, 20), wxALIGN_LEFT);
	m_staticText4->Wrap(-1);
	m_staticText4->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticText4, wxGBPosition(17, 0), wxGBSpan(1, 11), wxALL, 5);

	//Number of Coin Inserted
	wxString coinsInText;
	coinsInText << m_gameCTRL->GetCredits().GetInserted();
	m_staticTextIn = new wxStaticText(this, wxID_ANY, wxT(" 0"), wxDefaultPosition, wxSize(40, 20), wxALIGN_LEFT);
	m_staticTextIn->Wrap(-1);
	m_staticTextIn->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextIn, wxGBPosition(17, 11), wxGBSpan(1, 5), wxALL, 5);

	m_staticText5 = new wxStaticText(this, wxID_ANY, wxT("Coins Retrieved :"), wxDefaultPosition, wxSize(136, 20), wxALIGN_LEFT);
	m_staticText5->Wrap(-1);
	m_staticText5->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticText5, wxGBPosition(18, 0), wxGBSpan(1, 11), wxALL, 5);

	//Number of Coins Retrieved
	wxString coinsRetrievedText;
	coinsRetrievedText << m_gameCTRL->GetCredits().GetRetrieved();
	m_staticTextOut = new wxStaticText(this, wxID_ANY, coinsRetrievedText, wxDefaultPosition, wxSize(40, 20), wxALIGN_LEFT);
	m_staticTextOut->Wrap(-1);
	m_staticTextOut->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextOut, wxGBPosition(18, 11), wxGBSpan(1, 5), wxALL, 5);

	m_staticText6 = new wxStaticText(this, wxID_ANY, wxT("Credits Stored :"), wxDefaultPosition, wxSize(136, 20), wxALIGN_LEFT);
	m_staticText6->Wrap(-1);
	m_staticText6->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticText6, wxGBPosition(19, 0), wxGBSpan(1, 11), wxALL, 5);

	//Number of Coins Stored
	wxString coinsStoredText;
	coinsStoredText << m_gameCTRL->GetCredits().GetStored();
	m_staticTextStored = new wxStaticText(this, wxID_ANY, coinsStoredText, wxDefaultPosition, wxSize(40, 20), wxALIGN_LEFT);
	m_staticTextStored->Wrap(-1);
	m_staticTextStored->SetFont(wxFont(12, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	gbSizer1->Add(m_staticTextStored, wxGBPosition(19, 11), wxGBSpan(1, 5), wxALL, 5);

	wxString rules;
	rules << "Hit as many targets as you can within 60 seconds. At every 5 seconds the colors will change. \n\n";
	rules << "30 - 50 = 1 coin | 50 + = coins equal to score.";
	m_staticTextRules = new wxStaticText(this, wxID_ANY, rules, wxDefaultPosition, wxSize(572, 70), wxALIGN_CENTRE);
	m_staticTextRules->Wrap(-1);
	m_staticTextRules->SetFont(wxFont(11, wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL, false, wxEmptyString));
	m_staticTextRules->SetBackgroundColour(wxColour(255, 255, 255));
	gbSizer1->Add(m_staticTextRules, wxGBPosition(16, 16), wxGBSpan(3, 479), wxALL, 5);

	//Start Button
	m_buttonStart = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonStart->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	m_buttonStart->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnStartButton, this);
	gbSizer1->Add(m_buttonStart, wxGBPosition(19, 20), wxGBSpan(1, 11), wxALL, 5);

	//Credit In Button
	m_buttonCreditsIn = new wxButton(this, wxID_ANY, wxT("Credits In"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonCreditsIn->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	m_buttonCreditsIn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnCreditsInButton, this);
	gbSizer1->Add(m_buttonCreditsIn, wxGBPosition(19, 33), wxGBSpan(1, 8), wxALL, 5);

	//Credit OUT Button
	m_buttonCreditsOut = new wxButton(this, wxID_ANY, wxT("Credits Out"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonCreditsOut->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFontFamily::wxFONTFAMILY_DEFAULT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_BOLD, false, wxEmptyString));
	m_buttonCreditsOut->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnCreditsOutButton, this);
	gbSizer1->Add(m_buttonCreditsOut, wxGBPosition(19, 43), wxGBSpan(1, 9), wxALL, 5);

	this->SetSizer(gbSizer1);
	this->Layout();
	this->Centre(wxBOTH);
}

cMain::~cMain()
{
	delete m_gameCTRL;
	delete btnSquares;
	delete timer;
}

//Interaction for all the colored buttons
void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % nWidth;
	int y = (evt.GetId() - 10000) / nWidth;
	
	GameState state = m_gameCTRL->GetGameState();
	if (state == GameState::Playing) {
		if (m_gameCTRL->HitTarget(x, y)) {
			btnSquares[y * BOARD_WIDTH + x]->SetBackgroundColour(GetWXColor(Color::black));
		}
	}
	UpdateUI();
	Refresh();
	evt.Skip();
}

//the interaction for the start button
void cMain::OnStartButton(wxCommandEvent& evt)
{
	GameState state = m_gameCTRL->GetGameState();
	if (state == GameState::Stopped) { //Start the GAME!
		if (m_gameCTRL->StartGame()) {
			UpdateBoard();
			m_staticTextState->SetLabel("Playing");
			timer->Start(1000); // set interval of 1 second
			UpdateTime();
		}		
	}
	else if (state == GameState::Playing) { //Pause
		m_staticTextState->SetLabel("Paused");
		m_gameCTRL->PauseGame();
		timer->Stop();
	}
	else { //Unpause
		m_staticTextState->SetLabel("Playing");
		m_gameCTRL->UnPauseGame();
		timer->Start();
	}
	
	UpdateUI();
	Refresh();
	evt.Skip();
}

void cMain::OnCreditsInButton(wxCommandEvent& evt)
{
	GameState state = m_gameCTRL->GetGameState();
	if (state == GameState::Stopped) {
		m_gameCTRL->CreditsIn();
		UpdateUI();
		Refresh();
	}
	evt.Skip();
}

void cMain::OnCreditsOutButton(wxCommandEvent& evt)
{
	GameState state = m_gameCTRL->GetGameState();
	if (state == GameState::Stopped) {
		m_gameCTRL->CreditsOut();
		UpdateUI();
		Refresh();
	}
	evt.Skip();
}

// On each interval of the timer this function is called
void cMain::OnTimer(wxTimerEvent& event)
{
	//check is patterned changed
	bool changedPatern = m_gameCTRL->DecrementTime();
	if (changedPatern) {
		UpdateBoard();
	}
	UpdateTime();
	int time = m_gameCTRL->GetTimeLeft();
	if (time == 0) { //game needs to stop
		m_staticTextState->SetLabel(m_gameCTRL->GetGameStateText()); //change text to stopped
		m_buttonTarget->SetBackgroundColour(GetWXColor(m_gameCTRL->GetTarget())); //reset the target square
		UpdateUI();
		UpdateBoard();
	}
	event.Skip();
}

//update Board display
void cMain::UpdateBoard()
{
	//Update the Buttons
	for (int y = 0; y < nHeight; y++) { //goes from 0 to 5 (lines) 
		for (int x = 0; x < nWidth; x++)//goes from 0 to 10 (collumns)
			btnSquares[y * nWidth + x]->SetBackgroundColour(GetWXColor(m_gameCTRL->GetColor(x, y)));
	}
}

//update Time Display
void cMain::UpdateTime()
{
	wxString timeLeftText;
	timeLeftText << m_gameCTRL->GetTimeLeft();
	m_staticTextTimer->SetLabel(timeLeftText);
}

wxColour cMain::GetWXColor(Color c)
{
	wxColour out;
	switch (c)
	{
	case Color::black:
		out = wxColour(0, 0, 0);
		break;
	case Color::red:
		out = wxColour(255, 0, 0);
		break;
	case Color::orange:
		out = wxColour(255, 128, 0);
		break;
	case Color::yellow:
		out = wxColour(255, 255, 0);
		break;
	case Color::green:
		out = wxColour(0, 255, 0);
		break;
	case Color::blue:
		out = wxColour(0, 0, 255);
		break;
	default:
		out = wxColour(255, 255, 255);
		break;
	}
	return out;
}

//update all the Displays
void cMain::UpdateUI()
{
	m_buttonTarget->SetBackgroundColour(GetWXColor(m_gameCTRL->GetTarget()));
	m_buttonTarget->Enable(false);

	wxString string;
	string << m_gameCTRL->GetScore();
	m_staticTextScore->SetLabel(string);
	string.Clear();
	
	string << m_gameCTRL->GetCredits().GetStored();
	m_staticTextStored->SetLabel(string);
	string.Clear();

	string << m_gameCTRL->GetCredits().GetInserted();
	m_staticTextIn->SetLabel(string);
	string.Clear();

	string << m_gameCTRL->GetCredits().GetRetrieved();
	m_staticTextOut->SetLabel(string);
	string.Clear();

}




