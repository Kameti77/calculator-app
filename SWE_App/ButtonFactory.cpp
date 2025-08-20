#include "ButtonFactory.h"


//ButtonFactory::ButtonFactory(wxPanel* panel, wxWindow* window)
//	: m_panel(panel), m_parentWindow(window) {
//
//}
wxPanel* ButtonFactory::m_panel = nullptr;

void ButtonFactory::Init(wxPanel* panel) {
	m_panel = panel;
}

wxButton* ButtonFactory::CreateAddButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "+", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	return newBtn;
}
wxButton* ButtonFactory::CreateMinusButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "-", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	return newBtn;
}
wxButton* ButtonFactory::CreateMultiplyButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "*", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	return newBtn;
}
wxButton* ButtonFactory::CreateDivisionButton(const wxPoint& pos) {
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY, "/", pos, wxSize(90, 55), wxBORDER_NONE);
	newBtn->SetBackgroundColour(wxColour(62, 62, 77));
	newBtn->SetForegroundColour(wxColour(255, 255, 255));
	return newBtn;
}
