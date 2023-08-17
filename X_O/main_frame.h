#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
class main_frame : public wxFrame
{
public:
	main_frame(const wxString& tittle);
	void createcontrols();
	void createallbindings();
	void writinglettersfromplayers(wxMouseEvent& evt);
	void setnewgame();
	int checkforwinner();
private:
	wxStaticText* turnolet;
	wxPanel* panel;

	wxStaticLine* vert1;
	wxStaticLine* vert2;
	wxStaticLine* hori1;
	wxStaticLine* hori2;

	wxStaticText* lab11;
	wxStaticText* lab12;
	wxStaticText* lab13;
	wxStaticText* lab21;
	wxStaticText* lab22;
	wxStaticText* lab23;
	wxStaticText* lab31;
	wxStaticText* lab32;
	wxStaticText* lab33;

	wxStaticLine* div;
	wxStaticText* instructions;
	wxStaticText* winx;
	wxStaticText* wino;
	wxTextCtrl* scorex;
	wxTextCtrl* scoreo;
};

