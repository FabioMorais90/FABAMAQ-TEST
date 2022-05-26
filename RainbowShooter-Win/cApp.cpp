#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp()
{
}

cApp::~cApp()
{
    delete m_frame;
}

bool cApp::OnInit()
{
    m_frame = new cMain(nullptr);
    m_frame->Show();

    return true;
}
