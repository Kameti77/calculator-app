#pragma once
#include "wx/wx.h"
#include <wx/tokenzr.h>

class ButtonFactory
{
private:
	wxButton* newBtn = new wxButton(m_panel, wxID_ANY);
	wxPanel* panel;

	static wxPanel* m_panel;
	static wxWindow* m_parent;
	static wxFont m_btnFont;
	static wxTextCtrl* m_display;
	static wxString currentInput;

	static bool IsLastOperator;
	static bool IsLastTrig;
	static bool IsLastDot;
public:
	static void Init(wxPanel* m_panel, wxFont font, wxTextCtrl* display);
	static wxButton* CreateAddButton(const wxPoint& pos);
	static wxButton*  CreateMinusButton(const wxPoint& pos);
	static wxButton*  CreateMultiplyButton(const wxPoint& pos);
	static wxButton* CreateDivisionButton(const wxPoint& pos);
	static wxButton* CreateEqualButton(const wxPoint& pos);
	static wxButton* CreateClearButton(const wxPoint& pos);
	static wxButton* CreateModButton(const wxPoint& pos);
	static void CreateOperationButton(wxString label, const wxPoint& pos);
	static wxButton* CreateDelButton(const wxPoint& pos);

	static wxButton* CreateNumberButton(wxString label, const wxPoint& pos);
	static wxButton* CreateTrigButton(wxString label, const wxPoint& pos);

	static void CreateButton(wxString label, const wxPoint& pos);
	static wxButton* CreateNewButton(wxWindow* parent, wxString label, const wxPoint& pos, wxSize size);

	static void OnButtonClicked(wxCommandEvent& evt);
	static void HandleEqual();

	static void ApplyEvent(wxButton* button);
};

