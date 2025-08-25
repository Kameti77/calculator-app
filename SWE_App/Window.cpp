#include "Window.h"
#include <wx/tokenzr.h>
#include <cmath>
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "CALCULATOR", wxPoint(200, 200), wxSize(440, 560)) {
	panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(440, 560));
	panel->SetBackgroundColour(wxColour(25, 25, 25));
	wxFont btnFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Roboto Mono");

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	mainSizer->Add(panel, 0, wxALL, 1);

	display = new wxTextCtrl(panel, wxID_ANY, "0", wxPoint(15, 10), wxSize(390, 80), wxTE_RIGHT | wxTE_READONLY | wxBORDER_NONE);
	display->SetBackgroundColour(wxColour(62, 77, 77));
	display->SetFont(wxFont(24, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	ButtonFactory::Init(panel, btnFont, display);

	SetSizer(mainSizer);

	for (int row = 0; row < 6; ++row) {
		for (int col = 0; col < 4; ++col) {
			if (btns[row][col] == "") {
				continue;
			}
			if (btns[row][col] == "=") {
				equalButton = ButtonFactory::CreateEqualButton(wxPoint(pointX, pointY));
			}
			else {
				ButtonFactory::CreateButton(btns[row][col], wxPoint(pointX, pointY));
			}
			if (btns[row][col] == "AC") {
				pointX += 100;
			}
			pointX += 100;
		}
		pointX = 15;
		if (row == 0) pointY += 50;
		else pointY += 70;
	}

	equalButton->Bind(wxEVT_BUTTON, &Window::OnEqualButtonClicked, this);
}

void Window::OnEqualButtonClicked(wxCommandEvent& evt) {
	wxString input = display->GetValue();
	double value = CalculatorProcessor::GetInstance().Calculate(input);
	wxString output;
	if (CalculatorProcessor::GetInstance().exception) { output = "undefined"; }
	else if (CalculatorProcessor::GetInstance().isEmpty) { output = ""; }
	else output = wxString::Format(wxT("%.12g"), value);
	display->SetValue(output);
}
