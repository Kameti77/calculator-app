#include "Window.h"
#include <wx/tokenzr.h>
#include <cmath>

wxBEGIN_EVENT_TABLE(Window, wxFrame)
 EVT_COMMAND_RANGE(ID_BTN_FIRST, ID_BTN_LAST, wxEVT_BUTTON, Window::OnButtonClicked)
wxEND_EVENT_TABLE()

Window::Window() : wxFrame(nullptr, wxID_ANY, "CALCULATOR", wxPoint(200, 200), wxSize(440, 560)) {
	panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(440, 560));
	panel->SetBackgroundColour(wxColour(25, 25, 25));
	wxFont btnFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Roboto Mono");


	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	mainSizer->Add(panel, 0,  wxALL, 1);

	display = new wxTextCtrl(panel, wxID_ANY, "0", wxPoint(15, 10), wxSize(390, 80), wxTE_RIGHT | wxTE_READONLY | wxBORDER_NONE);
	display->SetBackgroundColour(wxColour(62, 77, 77));
	display->SetFont(wxFont(24, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	// trignometry and delete buttons
	for (int i = 0; i < 4; ++i) {
		wxButton* newBtn = new wxButton(panel, 10000 + i, firstRowBtns[i], wxPoint(15 + i * 100, 105), wxSize(90, 35), wxBORDER_NONE);
		buttonKeys.insert({ 10000 + i, firstRowBtns[i] });
		if (firstRowBtns[i] == "del") {
			newBtn->SetBackgroundColour(wxColour(99, 46, 46));
			newBtn->SetForegroundColour(wxColour(255, 255, 255));
			newBtn->SetFont(btnFont);
		}
		else {
			newBtn->SetBackgroundColour(wxColour(136, 167, 2));
			newBtn->SetFont(btnFont);
		}

	}
	int countId = 0;

	// other buttons
	for (int row = 0; row < 5; ++row) {
		for (int col = 0; col < 4; ++col) {
			if (btns[row][col] == "") {
				continue;
			}
			if (btns[row][col] == "AC") {
				wxButton* newBtn = new wxButton(panel, 10010, btns[row][col], wxPoint(pointX, pointY), wxSize(190, 55), wxBORDER_NONE);
				newBtn->SetBackgroundColour(wxColour(68, 51, 136));
				newBtn->SetForegroundColour(wxColour(255, 255, 255));
				newBtn->SetFont(btnFont);
				pointX += 100;
			}
			else {
				wxButton* newBtn = new wxButton(panel, 10010 + countId, btns[row][col], wxPoint(pointX, pointY), wxSize(90, 55), wxBORDER_NONE);
				if (btns[row][col] == "=") {
					newBtn->SetBackgroundColour(wxColour(213, 75, 0));				newBtn->SetFont(btnFont);
				}
				else {
					newBtn->SetBackgroundColour(wxColour(62, 62, 77));
				}
				newBtn->SetForegroundColour(wxColour(255, 255, 255));
				newBtn->SetFont(btnFont);

			}
			pointX += 100;
			countId++;
		}
		pointX = 15;
		pointY += 70;
	}
	SetSizer(mainSizer);

	int count = 0;
	for (int row = 0; row < 5; ++row) {
		for (int col = 0; col < 4; ++col) {
			if (btns[row][col] == "") {
				continue;
			}
			buttonKeys.insert({ 10010 + count, btns[row][col]});
			count++;
		}
	}
}

Window::~Window() {

}

void Window::OnButtonClicked(wxCommandEvent& evt) {
	int btnId = evt.GetId();
	


	if (buttonKeys[btnId] == "=") {
		HandleEqual();
	}
	else if (buttonKeys[btnId] == "AC") {
		currentInput = "";
	}
	else if(buttonKeys[btnId] == "del" ){
		if(!currentInput.IsEmpty()) currentInput.RemoveLast();
	}
	else {
		if (buttonKeys[btnId] == "+" || buttonKeys[btnId] == "-" || buttonKeys[btnId] == "*" || buttonKeys[btnId] == "/" || buttonKeys[btnId] == "%" ) {
			if(IsLastOperator) currentInput.Remove(currentInput.Length() - 3);
			currentInput += " " + buttonKeys[btnId] + " ";
			IsLastOperator = true;
		}
		else if (buttonKeys[btnId] == "sin" || buttonKeys[btnId] == "cos" || buttonKeys[btnId] == "tan") {
			if (IsLastOperator) currentInput.Remove(currentInput.Length() - 4);
			currentInput += buttonKeys[btnId] + " ";
			IsLastOperator = true;
		}
		else if (buttonKeys[btnId] == "+/-") {
			currentInput += "-";
			IsLastOperator = false;
		}
		else {
			if (buttonKeys[btnId] == ".") {
				if (IsLastOperator) currentInput.Remove(currentInput.Length() - 1);
				IsLastOperator = true;
			}
			else {
				IsLastOperator = false;
			}
			currentInput += buttonKeys[btnId];
		}
	}

	display->SetValue(currentInput);
}

void Window::HandleEqual() {

	wxString expression = display->GetValue();
	wxStringTokenizer tokenizer(expression, " ", wxTOKEN_DEFAULT); // 2 * 2

	double result = 0.0;
	wxString currentOperator = "+";
	wxString trigToken = "";
	double nextNumber = 0.0;
	bool exception= false;
	while (tokenizer.HasMoreTokens())
	{
		wxString token = tokenizer.GetNextToken().Trim();
		if (token.IsEmpty())
			continue;
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
			currentOperator = token;
		}
		else if (token == "sin" || token == "cos" || token == "tan") {
			currentOperator = token;
		}
		else {
			double number = wxAtof(token);
			if (currentOperator == "+")      result += number;
			else if (currentOperator == "-") result -= number;
			else if (currentOperator == "*") result *= number;
			else if (currentOperator == "/") {
				if (number == 0) { exception = true; break; } 
				result /= number; 
			}
			else if (currentOperator == "%") {
				if (number == 0) { exception = true; break; }
				result = fmod(result, number);
			}
			else if (currentOperator == "sin") result = sin(number);
			else if (currentOperator == "cos") result = cos(number);
			else if (currentOperator == "tan") result = tan(number);
		}
	}
	exception ? currentInput = "undefined" :currentInput = wxString::Format(wxT("%g"), result);
}