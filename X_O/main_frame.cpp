#include "main_frame.h"
#include <wx/wx.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <wx/statline.h>
#include <sstream>

char tx[] = { 'O', 'X' };
wxString colorletters[] = {"#ff9d33", "#3395ff"};
int letter = 0;
int posicheck[3][3];
int results[] = { 0, 0 };

main_frame::main_frame(const wxString& tittle) : wxFrame(nullptr, wxID_ANY, tittle)
{
	createcontrols();
	createallbindings();
	setnewgame();
}

void main_frame::createcontrols()
{
	srand(time(NULL));
	letter = rand() % 2;
	panel = new wxPanel(this);
	
	vert1 = new wxStaticLine(panel, wxID_ANY, wxPoint(200, 50), wxSize(3, 450));
	vert2 = new wxStaticLine(panel, wxID_ANY, wxPoint(350, 50), wxSize(3, 450));

	hori1 = new wxStaticLine(panel, wxID_ANY, wxPoint(50, 200), wxSize(450, 3));
	hori2 = new wxStaticLine(panel, wxID_ANY, wxPoint(50, 350), wxSize(450, 3));

	lab11 = new wxStaticText(panel, wxID_ANY, "", wxPoint(65, 55), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	lab12 = new wxStaticText(panel, wxID_ANY, "", wxPoint(215, 55), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	lab13 = new wxStaticText(panel, wxID_ANY, "", wxPoint(380, 55), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

	lab21 = new wxStaticText(panel, wxID_ANY, "", wxPoint(65, 215), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	lab22 = new wxStaticText(panel, wxID_ANY, "", wxPoint(215, 215), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	lab23 = new wxStaticText(panel, wxID_ANY, "", wxPoint(380, 215), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	
	lab31 = new wxStaticText(panel, wxID_ANY, "", wxPoint(65, 365), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	lab32 = new wxStaticText(panel, wxID_ANY, "", wxPoint(215, 365), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	lab33 = new wxStaticText(panel, wxID_ANY, "", wxPoint(380, 365), wxSize(120, 120), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
	
	div = new wxStaticLine(panel, wxID_ANY, wxPoint(550, 10), wxSize(2, 530));
	turnolet = new wxStaticText(panel, wxID_ANY, tx[letter], wxPoint(560, 100), wxSize(280, 150), wxALIGN_CENTER);
	instructions = new wxStaticText(panel, wxID_ANY, "Turno de:", wxPoint(560, 70), wxSize(260, 30), wxALIGN_CENTER);
	winx = new wxStaticText(panel, wxID_ANY, "# de veces X gano:", wxPoint(580, 350), wxSize(100, -1));
	wino = new wxStaticText(panel, wxID_ANY, "# de veces O gano:", wxPoint(580, 390), wxSize(100, -1));
	scorex = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(770, 350), wxSize(50, -1), wxTE_READONLY | wxALIGN_CENTER_HORIZONTAL);
	scoreo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(770, 390), wxSize(50, -1), wxTE_READONLY | wxALIGN_CENTER_HORIZONTAL);

	wxFont newfontpieces(wxFontInfo(wxSize(0, 120)));

	turnolet->SetFont(wxFontInfo(wxSize(0, 140)).Bold());
	instructions->SetFont(wxFontInfo(wxSize(0, 32)));
	winx->SetFont(wxFontInfo(wxSize(0,18)));
	wino->SetFont(wxFontInfo(wxSize(0, 18)));
	scorex->SetFont(wxFontInfo(wxSize(0, 18)));
	scoreo->SetFont(wxFontInfo(wxSize(0, 18)));
	turnolet->SetForegroundColour(wxColor("#ff3363"));

	lab11->SetFont(newfontpieces);
	lab12->SetFont(newfontpieces);
	lab13->SetFont(newfontpieces);

	lab21->SetFont(newfontpieces);
	lab22->SetFont(newfontpieces);
	lab23->SetFont(newfontpieces);

	lab31->SetFont(newfontpieces);
	lab32->SetFont(newfontpieces);
	lab33->SetFont(newfontpieces);
}

void main_frame::createallbindings()
{
	panel->Bind(wxEVT_LEFT_DOWN, &main_frame::writinglettersfromplayers, this);
}

void main_frame::writinglettersfromplayers(wxMouseEvent& evt)
{
	wxPoint clpos = evt.GetPosition();
	if (clpos.x > 50 && clpos.x < 200) {
		if (clpos.y > 50 && clpos.y < 200) {
			if (lab11->GetLabel() != "") {
				return;
			}
			posicheck[0][0] = letter % 2;
			lab11->Show();
			lab11->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab11->SetLabel(tx[letter % 2]);
		}else if (clpos.y > 200 && clpos.y < 350) {
			if (lab21->GetLabel() != "") {
				return;
			}
			posicheck[1][0] = letter % 2;
			lab21->Show();
			lab21->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab21->SetLabel(tx[letter % 2]);
		}else if (clpos.y > 350 && clpos.y < 450) {
			if (lab31->GetLabel() != "") {
				return;
			}
			posicheck[2][0] = letter % 2;
			lab31->Show();
			lab31->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab31->SetLabel(tx[letter % 2]);
		}
	} else if(clpos.x > 200 && clpos.x < 350) {
		if (clpos.y > 50 && clpos.y < 200) {
			if (lab12->GetLabel() != "") {
				return;
			}
			posicheck[0][1] = letter % 2;
			lab12->Show();
			lab12->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab12->SetLabel(tx[letter % 2]);
		}
		else if (clpos.y > 200 && clpos.y < 350) {
			if (lab22->GetLabel() != "") {
				return;
			}
			posicheck[1][1] = letter % 2;
			lab22->Show();
			lab22->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab22->SetLabel(tx[letter % 2]);
		}
		else if (clpos.y > 350 && clpos.y < 450) {
			if (lab32->GetLabel() != "") {
				return;
			}
			posicheck[2][1] = letter % 2;
			lab32->Show();
			lab32->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab32->SetLabel(tx[letter % 2]);
		}
	}else if (clpos.x > 350 && clpos.x < 500) {
		if (clpos.y > 50 && clpos.y < 200) {
			if (lab13->GetLabel() != "") {
				return;
			}
			posicheck[0][2] = letter % 2;
			lab13->Show();
			lab13->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab13->SetLabel(tx[letter % 2]);
		}
		else if (clpos.y > 200 && clpos.y < 350) {
			if (lab23->GetLabel() != "") {
				return;
			}
			posicheck[1][2] = letter % 2;
			lab23->Show();
			lab23->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab23->SetLabel(tx[letter % 2]);
		}
		else if (clpos.y > 350 && clpos.y < 450) {
			if (lab33->GetLabel() != "") {
				return;
			}
			posicheck[2][2] = letter % 2;
			lab33->Show();
			lab33->SetForegroundColour(wxColor(colorletters[letter % 2]));
			lab33->SetLabel(tx[letter % 2]);
		}
	} else {
		return;
	}
	letter++;
	int winner = checkforwinner();
	if (winner == 0){
		wxMessageBox("FELICIDADES 0! GANASTE!");
		results[winner]++;
		setnewgame();
	} else if (winner == 1) {
		wxMessageBox("FELICIDADES X! GANASTE!");
		results[winner]++;
		setnewgame();
	} else if (winner == 3) {
		wxMessageBox("TENEMOS UN EMPATE!");
		setnewgame();
	}
	turnolet->SetLabel(tx[letter % 2]);
}

void main_frame::setnewgame()
{
	lab11->Hide();
	lab12->Hide();
	lab13->Hide();
	lab21->Hide();
	lab22->Hide();
	lab23->Hide();
	lab31->Hide();
	lab32->Hide();
	lab33->Hide();

	lab11->SetLabel("");
	lab12->SetLabel("");
	lab13->SetLabel("");
	lab21->SetLabel("");
	lab22->SetLabel("");
	lab23->SetLabel("");
	lab31->SetLabel("");
	lab32->SetLabel("");
	lab33->SetLabel("");
	
	wxString score = wxString::Format("%d", results[0]);
	scoreo->SetValue(score);
	wxString score2 = wxString::Format("%d", results[1]);
	scorex->ChangeValue(score2);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			posicheck[i][j] = 2;
		}
	}
}


int main_frame::checkforwinner()
{
	int hp = 0;
	for (int i = 0; i < 3; i++) {
		if (posicheck[i][0] == posicheck[i][1] && posicheck[i][1] == posicheck[i][2]) {
			return posicheck[i][0];
		}
		if (posicheck[0][i] == posicheck[1][i] && posicheck[1][i] == posicheck[2][i]) {
			return posicheck[0][i];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (posicheck[i][j] != 2) {
				hp++;
			}
		}
	}
	if (posicheck[0][0] == posicheck[1][1] && posicheck[1][1] == posicheck[2][2]) {
		return posicheck[0][0];
	}
	if (posicheck[0][2] == posicheck[1][1] && posicheck[1][1] == posicheck[2][0]) {
		return posicheck[0][2];
	}
	if (hp < 9) {
		return 2;
	}
	return 3;
}

