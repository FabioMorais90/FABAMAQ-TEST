///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/event.h>

///////////////////////////////////////////////////////////////////////////

#include "GameController.h"

///////////////////////////////////////////////////////////////////////////////
/// Class cMain
///////////////////////////////////////////////////////////////////////////////
class cMain : public wxFrame 
{
	private:
		int nHeight = BOARD_HEIGHT;
		int nWidth = BOARD_WIDTH;
		GameController* m_gameCTRL;//Implementar o board de forma a funcionar (Reve o GameCTLR)
		//Ver como implementar time
		wxTimer* timer;
		
	protected:
		wxStaticText* m_staticText1;
		wxButton* m_buttonTarget;
		wxStaticText* m_staticTextState;
		wxStaticText* m_staticTextTimer;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticTextScore;
		wxPanel* m_panelBoard;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticTextPlays;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticTextIn;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticTextOut;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticTextStored;
		wxButton* m_buttonCreditsIn;
		wxButton* m_buttonStart;
		wxButton* m_buttonCreditsOut;
		wxStaticText* m_staticTextRules;

		
		//wxButton* m_btn1;
		wxButton** btnSquares;
	
	public:
		
		cMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Rainbow Shooter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 804, 500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~cMain();

		void OnButtonClicked(wxCommandEvent& evt); 
		void OnStartButton(wxCommandEvent& evt);
		void OnCreditsInButton(wxCommandEvent& evt);
		void OnCreditsOutButton(wxCommandEvent& evt);
		void OnTimer(wxTimerEvent& event);

		wxDECLARE_EVENT_TABLE();

	private:
		//auxiliar function to convert Color into wxColour
		wxColour GetWXColor(Color c);
		//auxiliar function to get the time. IMPLEMENTARS
		int GetTime();
		//Auxiliar function to decrement the time left counter
		void UpdateTime();
		//Update the colors of the Board
		void UpdateBoard();
		//Updates the entire UI
		void UpdateUI();


};
