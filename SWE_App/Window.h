#pragma once
#include "wx/wx.h"
#include "map"

class Window: public wxFrame
{
private:
	// arrays of button
	wxString firstRowBtns[4] = { "sin", "cos", "tan", "del" };
	wxString btns[5][4] = {
		{"AC", "%", "/", ""},
		{ "7", "8", "9", "*" } ,
		{"4", "5", "6", "+"},
		{"1", "2", "3", "-"},
		{"0", ".", " +/-", "="}
	};
	std::map<int, wxString> buttonKeys;

	// button positions
	int pointY = 155;
	int pointX = 15;

	wxPanel* panel = nullptr;
	wxTextCtrl* display = nullptr;

	wxString currentInput = "";

	// event handler
	
public:
	Window();
	~Window();

	void OnButtonClicked(wxCommandEvent& evt);

	void HandleEqual();

	wxDECLARE_EVENT_TABLE();
};

enum { ID_BTN_FIRST = 10000, ID_BTN_LAST = 10100 };