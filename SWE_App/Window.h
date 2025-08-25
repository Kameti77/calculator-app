#pragma once
#include "wx/wx.h"
#include "map"


class Window: public wxFrame
{
private:
	// arrays of button
	wxString btns[6][4] = {
		{"sin", "cos", "tan", "del"},
		{"AC", "%", "/", ""},
		{ "7", "8", "9", "*" } ,
		{"4", "5", "6", "+"},
		{"1", "2", "3", "-"},
		{"0", ".", "+/-", "="}
	};

	// button positions
	int pointX = 15;
	int pointY = 105;
	
	wxPanel* panel;
	wxTextCtrl* display = nullptr;
	wxButton* equalButton = nullptr;

	wxString currentInput = "";
	bool IsLastOperator = false;
	bool IsLastNumber = false;
public:
	Window();

	void OnEqualButtonClicked(wxCommandEvent& evt);
};
