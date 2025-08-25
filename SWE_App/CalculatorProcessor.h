#pragma once
#include "wx/wx.h"
#include <wx/tokenzr.h>

class CalculatorProcessor
{
protected:
	CalculatorProcessor() = default;
public:
	static CalculatorProcessor& GetInstance() {
		static CalculatorProcessor instance;
		return instance;
	}

	CalculatorProcessor(const CalculatorProcessor&) = delete;
	CalculatorProcessor(CalculatorProcessor&&) = delete;
	CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;
	CalculatorProcessor& operator=(CalculatorProcessor&&) = delete;


	static int precedence(const wxString& op);
	static bool isOperator(const wxString& op);
	static bool isTrig(const wxString& func);

	static bool exception;
	static bool isEmpty;

	static std::vector<wxString> ChangeToPostfix(wxString expression);

	static double Calculate(const wxString& expression);

	};

