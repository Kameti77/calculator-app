#include "ButtonFactory.h"


wxPanel* ButtonFactory::m_panel = nullptr;
wxTextCtrl* ButtonFactory::m_display = nullptr;
wxString ButtonFactory::currentInput = "";
bool ButtonFactory::IsLastOperator = false;
bool ButtonFactory::IsLastTrig = false;
bool ButtonFactory::IsLastDot = false;

wxFont ButtonFactory::m_btnFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Roboto Mono");

void ButtonFactory::Init(wxPanel* panel, wxFont font, wxTextCtrl* display) {
	m_panel = panel;
	m_btnFont = font;
	m_display = display;
}

wxButton* ButtonFactory::CreateAddButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "+", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}
wxButton* ButtonFactory::CreateMinusButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "-", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}
wxButton* ButtonFactory::CreateMultiplyButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "*", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}
wxButton* ButtonFactory::CreateDivisionButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "/", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}

wxButton* ButtonFactory::CreateClearButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "AC", pos, wxSize(190, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(68, 51, 136));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}
wxButton* ButtonFactory::CreateModButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "%", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}
void ButtonFactory::CreateOperationButton(const wxString label, const wxPoint& pos) {
	if (label == "+") {
		CreateAddButton(pos);
	}
	else if (label == "-") {
		CreateMinusButton(pos);
	}
	else if (label == "*") {
		CreateMultiplyButton(pos);
	}
	else if (label == "/") {
		CreateDivisionButton(pos);
	}
	else if (label == "%") {
		CreateModButton(pos);
	}
}

wxButton* ButtonFactory::CreateDelButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "del", pos, wxSize(90, 35), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(99, 46, 46));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}

wxButton* ButtonFactory::CreateNumberButton(const wxString label, const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, label, pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}

wxButton* ButtonFactory::CreateTrigButton(const wxString label, const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, label, pos, wxSize(90, 35), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(136, 167, 2));
	newBtn->SetForegroundColour(wxColour(0, 0, 0));
	newBtn->SetFont(m_btnFont);
	ApplyEvent(newBtn);
	return newBtn;
}

wxButton* ButtonFactory::CreateEqualButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "=", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(213, 75, 0));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	newBtn->SetFont(m_btnFont);
	// ApplyEvent(newBtn);
	return newBtn;
}


void ButtonFactory::CreateButton(const wxString label, const wxPoint& pos) {
	wxButton* newBtn;
	if (label == "sin" || label == "cos" || label == "tan" || label == "del")
	{
		if (label == "del") {
			CreateDelButton(pos);
		}else {
			CreateTrigButton(label, pos);
		}
	}
	 else{
		if (label == "AC") {
			CreateClearButton(pos);
		}
		else if (label == "=") {
			CreateEqualButton(pos);
		}
		else if (label == "+" || label == "-" || label == "*" || label == "/" || label == "%") {
			CreateOperationButton(label, pos);
		}
		else {
			CreateNumberButton(label, pos);
		}
		

	}
}

wxButton* ButtonFactory::CreateNewButton(wxWindow* parent, wxString label, const wxPoint& pos, wxSize size) {
	wxButton* newBtn = new wxButton(parent, wxID_ANY, label, pos, size);
	return newBtn;
}


void ButtonFactory::OnButtonClicked(wxCommandEvent& evt) {
	wxButton* clickedBtn = dynamic_cast<wxButton*>(evt.GetEventObject());
	if (!clickedBtn) return;

	wxString label = clickedBtn->GetLabel();

	if (label == "=") {
		
		HandleEqual();
	}
	else if (label == "AC") {
		currentInput = "";
	}
	else if (label == "del") {
		if (!currentInput.IsEmpty()) currentInput.RemoveLast();
	}
	else {
		if (label == "+" || label == "-" || label == "*" || label == "/" || label == "%") {
			if (IsLastOperator) currentInput.Remove(currentInput.Length() - 3);
			currentInput += " " + label + " ";
			IsLastOperator = true;
			IsLastTrig = IsLastDot = false;
		}
		else if (label == "sin" || label == "cos" || label == "tan") {
			// if (IsLastTrig) currentInput.Remove(currentInput.Length() - 4);
			currentInput += label + " ";
			IsLastTrig = true;
			IsLastOperator = IsLastDot = false;
		}
		else if (label == "+/-") {
			currentInput += "-";
			IsLastOperator = IsLastTrig = IsLastDot = false;
		}
		else {
			if (label == ".") {
				if (IsLastDot) currentInput.Remove(currentInput.Length() - 1);
				IsLastDot = true;
				IsLastOperator = IsLastTrig = false;
			}
			else {
				IsLastOperator = IsLastTrig = IsLastDot = false;
			}
			currentInput += label;
		}
	}

	m_display->SetValue(currentInput);
}

void ButtonFactory::HandleEqual() {
	wxString expression = m_display->GetValue();
	wxStringTokenizer tokenizer(expression, " ", wxTOKEN_DEFAULT);

	double result = 0.0;
	wxString currentOperator = "+";
	bool exception = false;
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
			else if (currentOperator == "sin")
			{
				result = sin(number * M_PI / 180.0);
				if (fabs(result) < 1e-10)
					result = 0;
			}
			else if (currentOperator == "cos")
			{
				result = cos(number * M_PI / 180.0);
				if (fabs(result) < 1e-10)
					result = 0;
			}
			else if (currentOperator == "tan") {
				result = tan(number * M_PI / 180.0);
				if (fabs(result) < 1e-10)
					result = 0;
			}
		}
	}
	exception ? currentInput = "undefined" : currentInput = wxString::Format(wxT("%g"), result);
}
void ButtonFactory::ApplyEvent(wxButton* button) {
	button->Bind(wxEVT_BUTTON, &ButtonFactory::OnButtonClicked);
}