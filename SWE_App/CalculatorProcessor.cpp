#include "CalculatorProcessor.h"
#include <stack>
#include <string>
#include <vector>
#include <cmath>

bool CalculatorProcessor::exception = false;
bool CalculatorProcessor::isEmpty = false;



// check if token is operator
bool CalculatorProcessor::isOperator(const wxString& op) {
	return op == "+" || op == "-" || op == "*" || op == "/" || op == "%";
}

// check if token is trig function
bool CalculatorProcessor::isTrig(const wxString& func) {
	return func == "sin" || func == "cos" || func == "tan";
}

// Operator precedence
int CalculatorProcessor::precedence(const wxString& op) {
	if (op == "+" || op == "-") return 1;
	if (op == "*" || op == "/" || op == "%") return 2;
	return 0;
}

std::vector<wxString> CalculatorProcessor::ChangeToPostfix(wxString expression) {
	std::stack<wxString> ops;
	std::vector<wxString> output;

	std::vector<wxString> tokens;



	wxStringTokenizer tokenizer(expression, " ", wxTOKEN_DEFAULT);


	while (tokenizer.HasMoreTokens()) {
		wxString token = tokenizer.GetNextToken().Trim();
		tokens.push_back(token);
	}

	if(!tokens.empty()){
		if ( isOperator(tokens[0]) ) {
			tokens.erase(tokens.begin() + 0);
		}

		int i = 1;
		wxString lastToken = tokens[tokens.size() - i];

		while (lastToken == "." || isTrig(lastToken) || isOperator(lastToken) || !isdigit(lastToken[0])) {
			if (tokens.empty())  break;
			tokens.pop_back();
			if (!tokens.empty()) lastToken = tokens[tokens.size() - i];
		}
	}

	double result = 0.0;
	wxString currentOperator = "+";
		
	for (auto& token : tokens) {

		if (token.IsEmpty())
			continue;

		if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
			output.push_back(token);
		}

		else if (isTrig(token)) {
			ops.push(token);
		}
		else if (isOperator(token)) {
			while (!ops.empty() &&
				((isOperator(ops.top()) && precedence(ops.top()) >= precedence(token))
					|| isTrig(ops.top()))) {
				output.push_back(ops.top());
				ops.pop();
			}
			ops.push(token);
		}
	}
	while (!ops.empty()) {
		output.push_back(ops.top());
		ops.pop();
	}

	return output;
}



double CalculatorProcessor::Calculate(const wxString& expression) {
	std::stack<double> values;

	std::vector<wxString> postfix = ChangeToPostfix(expression);

	for (const auto& token : postfix) {
		isEmpty = false;
		if (token.IsEmpty())
			continue;
		if (isOperator(token)) {
			double b = values.top(); values.pop();
			double a = values.top(); values.pop();
			if (token == "+") values.push(a + b);
			else if (token == "-") values.push(a - b);
			else if (token == "*") values.push(a * b);
			else if (token == "/") {
				if (b == 0) { exception = true; values.push(-0.0000); break; }
				values.push(a / b);

			}
			else if (token == "%") {
				if (b == 0) { exception = true; values.push(-0.0000); break; }
				int int_a = static_cast<int>(a);
				int int_b = static_cast<int>(b);

				values.push(int_a % int_b);
			}
			exception = false;
		}
		else if (isTrig(token)) {
			double a = values.top(); values.pop();
			const double PI = 3.141592653589793;

			if (token == "sin") values.push(sin(a * PI / 180.0));
			else if (token == "cos") values.push(cos(a * PI / 180.0));
			else if (token == "tan") {
				if (fmod(a, 180.0) == 90.0) {
					exception = true;
					break;
				}
				else { values.push(tan(a * PI / 180.0)); }
			}
			exception = false;
		}
		else {
			values.push(wxAtof(token));
			exception = false;
		}
	}

	if (values.empty()) isEmpty = true;

	return !isEmpty ? values.top() : 0;

}
