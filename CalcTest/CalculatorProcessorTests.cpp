#include "CppUnitTest.h"
#include "../SWE_App/CalculatorProcessor.cpp"
#include "wx/wx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcTest
{
	TEST_CLASS(CalcTest)
	{
	public:
		TEST_METHOD(CalculatorProcessor_checking_addition)
		{
			// input for class
			wxString input = "1 + 1";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);
			
			// expected output
			double expected = 2;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(CalculatorProcessor_checking_subtraction)
		{
			// input for class
			wxString input = "2 - 1";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 1;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(CalculatorProcessor_checking_multiplition)
		{
			// input for class
			wxString input = "2 * 2";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 4;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(CalculatorProcessor_checking_division)
		{
			// input for class
			wxString input = "2 / 2";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 1;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(exception_handling_zero_division)
		{
			// input for class
			wxString input = "1 / 0";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);
			bool isException = CalculatorProcessor::GetInstance().exception;

			// expected output
			bool expected = true;

			//verify ouput is as expected
			Assert::AreEqual(expected, isException);
		}

		TEST_METHOD(invalid_input_turned_to_empty_ouput)
		{
			// input for class
			wxString input = "+ - * .";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);
			bool isEmpty = CalculatorProcessor::GetInstance().isEmpty;

			// expected output
			bool expected = true;

			//verify ouput is as expected
			Assert::IsTrue(isEmpty);
		}
		TEST_METHOD(CalculatorProcessor_trignometric_sin)
		{
			// input for class
			wxString input = "sin 90";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 1;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(CalculatorProcessor_trignometric_cos)
		{
			// input for class
			wxString input = "cos 180";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = -1;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(CalculatorProcessor_trignometric_tan)
		{
			// input for class
			wxString input = "tan 0";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 0;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(ShantingYardAlgorithim_check_tripleTrigFunction)
		{
			// input for class
			wxString input = "sin cos cos 60";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 0.017451741970597286;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(ShantingYardAlgorithim_check_complexExpression)
		{
			// input for class
			wxString input = "sin 0 + 2 * 3 - 4 / 2 - 3 % 2";

			// instance class
			double output = CalculatorProcessor::GetInstance().Calculate(input);

			// expected output
			double expected = 3;

			//verify ouput is as expected
			Assert::AreEqual(expected, output);
		}

	};
}