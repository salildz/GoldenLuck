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

	void Login::Loginfunc() {																								//this function opens text file and then checks
		std::ifstream myFile;																						//if the information of the user inside the file is equal
		myFile.open("User.txt", std::ios::in);																		//to the information inside the textboxes

		if (myFile.is_open()) {
			std::string line;

			while (getline(myFile, line)) {

				std::vector<std::string> parsedline = parseCommaDelimitedString(line);
				const char* username = parsedline.at(0).c_str();

				std::string editUname = msclr::interop::marshal_as<std::string>(txtUsername1->Text);				//gets the info from the textboxes
				const char* usernameString = editUname.c_str();														//converts a C++ std::string to a C-style string												

				if (std::strcmp(username, usernameString) == 0) {													//compares usernames

					const char* password = parsedline.at(1).c_str();

					std::string editPword = msclr::interop::marshal_as<std::string>(txtPassword1->Text);			//gets the info from the textboxes
					const char* passwordString = editPword.c_str();													//converts a C++ std::string to a C-style string

					if (std::strcmp(password, passwordString) == 0) {												//compares passwords

						const char* credit3 = parsedline.at(2).c_str();												//gets the credit from the text file
						int credit4 = std::stoi(credit3);															//turns std::string into an int	and
						User^ user = gcnew User(credit4);															//sends that int value to user							
						this->Hide();
						MainForm^ mainForm = gcnew MainForm();														//Initializes Main menu

						finalUsername = gcnew String(usernameString);												//Use this to give value to the finalUsername
						finalPassword = gcnew String(passwordString);												//and finalPassword

						mainForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Login::GameTerminated);
						mainForm->Show();
					}
					else {
						lblError->Text = "Wrong Password!";
					}
				}
			}
		}
	}

	std::vector<std::string> Login::parseCommaDelimitedString(std::string line) {											//reads from the user text file
		std::vector<std::string> result;																			//reads till reaches a comma and then stores the substring
		std::stringstream s_stream(line);																			//inside the result then checks if there are more to read inside
		//the file if there is, it continues the loop
		while (s_stream.good()) {
			std::string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}
		return result;
	}

	void Login::PlayMusic(const char* filePath, bool loop) {
		// Use SND_ASYNC for asynchronous playback
		// Use SND_LOOP for looping playback
		UINT flags = SND_ASYNC | (loop ? SND_LOOP : 0);

		PlaySoundA(filePath, NULL, flags);
	}
}