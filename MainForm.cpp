#include "MainForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array < String^>^ args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(0);
	GoldenLuck::MainForm form;
	Application::Run(% form);
}