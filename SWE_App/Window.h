#pragma once
#include "wx/wx.h"

class Window: public wxFrame
{
private:
	// arrays of button
	wxString firstRowBtns[4] = { "sin", "cos", "tan", "del" };
	wxString btns[5][4] = {
		{"AC", "%", "/", ""},
		{ "7", "9", "9", "*" } ,
		{"4", "5", "6", "+"},
		{"1", "2", "3", "-"},
		{"0", ".", " + / -", "="}
	};

	// button positions
	int pointY = 155;
	int pointX = 15;

	wxPanel* panel = nullptr;
	wxListBox* text = nullptr;

	// event handler
	
public:
	Window();
	~Window();

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

