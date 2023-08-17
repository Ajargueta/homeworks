#include "app.h"
#include "main_frame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(app);

bool app::OnInit() {
	main_frame* mainFrame = new main_frame("Juego X-O");
	mainFrame->SetClientSize(850, 550);
	mainFrame->Center();
	mainFrame->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER);
	mainFrame->Show();
	return true;
}
