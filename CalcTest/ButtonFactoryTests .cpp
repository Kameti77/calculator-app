#include "CppUnitTest.h"
#include "../SWE_App/ButtonFactory.cpp"
#include "wx/wx.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
wxPanel* panel = new wxPanel(parent);
wxTextCtrl* display = new wxTextCtrl(panel, wxID_ANY);
wxFont btnFont;

wxInitializer init;

namespace CalcTest
{
	TEST_CLASS(ButtonTest)
	{
	public:
		TEST_METHOD(ButtonFactory_CreateAddButton_Created)
		{
			Assert::IsTrue(init.IsOk());

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* addBtn = ButtonFactory::CreateAddButton(wxPoint(50, 50));
			Assert::IsNotNull(addBtn);
		}


		TEST_METHOD(ButtonFactory_CreateEqualButton_Clickable)
		{
			Assert::IsTrue(init.IsOk(), L"Failed to initialize wxWidgets");

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* equalButton = ButtonFactory::CreateEqualButton(wxPoint(50, 50));
			Assert::IsNotNull(equalButton);

			Assert::IsTrue(equalButton->IsEnabled());
		}

		TEST_METHOD(ButtonFactory_EqualButton_HasCorrectLabel)
		{
			Assert::IsTrue(init.IsOk());

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* equalButton = ButtonFactory::CreateEqualButton(wxPoint(50, 50));

			Assert::IsNotNull(equalButton);

			wxString actual = equalButton->GetLabel();
			const wxString expected = "=";

			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(ButtonFactory_Multiplication_HasCorrectLabel)
		{
			Assert::IsTrue(init.IsOk());

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* multiButton = ButtonFactory::CreateMultiplyButton(wxPoint(50, 50));

			Assert::IsNotNull(multiButton);

			wxString actual = multiButton->GetLabel();
			const wxString expected = "*";

			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(ButtonFactory_NumberOne_HasCorrectLabel)
		{
			Assert::IsTrue(init.IsOk());

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* button = ButtonFactory::CreateNumberButton("1",wxPoint(50, 50));

			Assert::IsNotNull(button);

			wxString actual = button->GetLabel().Trim(true).Trim(false);
			const wxString expected = "1";

			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(ButtonFactory_TanButton_HasCorrectLabel)
		{
			Assert::IsTrue(init.IsOk());

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* button = ButtonFactory::CreateTrigButton("tan", wxPoint(50, 50));

			Assert::IsNotNull(button);

			wxString actual = button->GetLabel().Trim(true).Trim(false);
			const wxString expected = "tan";

			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(ButtonFactory_DelButton_HasCorrectLabel)
		{
			Assert::IsTrue(init.IsOk());

			ButtonFactory::Init(panel, btnFont, display);

			wxButton* button = ButtonFactory::CreateDelButton(wxPoint(50, 50));

			Assert::IsNotNull(button);

			wxString actual = button->GetLabel().Trim(true).Trim(false);
			const wxString expected = "del";

			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(ButtonFactory_CreateEqualButton_HasParent)
		{
			wxButton* button = ButtonFactory::CreateEqualButton(wxPoint(50, 50));
			Assert::IsTrue(button->GetParent() == panel);
		}

		TEST_METHOD(ButtonFactory_CreateClearButton_ClickEvent)
		{
			wxButton* button = ButtonFactory::CreateClearButton(wxPoint(50, 50));
			bool clicked = false;
			button->Bind(wxEVT_BUTTON, [&clicked](wxCommandEvent&) { clicked = true; });
			button->GetEventHandler()->ProcessEvent(wxCommandEvent(wxEVT_BUTTON, button->GetId()));
			Assert::IsTrue(clicked);
		}

		TEST_METHOD(ButtonFactory_CreateState_DisplayOutput)
		{
			ButtonFactory::currentInput = "";
			ButtonFactory::CreateState("+");
			Assert::IsTrue(ButtonFactory::currentInput == " + ");
		}

		TEST_METHOD(ButtonFactory_CreateState_DeleteLastEntry)
		{
			ButtonFactory::currentInput = "2 + 2";
			ButtonFactory::CreateState("del");
			Assert::IsTrue(ButtonFactory::currentInput == "2 + ");
		}

		TEST_METHOD(ButtonFactory_CreateState_ClearDisplay)
		{
			ButtonFactory::currentInput = "2 + 2 * sin 30";
			ButtonFactory::CreateState("AC");
			Assert::IsTrue(ButtonFactory::currentInput == "");
		}
	};

}