#include "Login.h"
using namespace System;
using namespace System::Windows::Forms;



namespace GoldenLuck {
	[STAThreadAttribute]
		void main(array < String^>^ args)
	{

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(0);
		GoldenLuck::Login form;
		Application::Run(% form);
	}
}