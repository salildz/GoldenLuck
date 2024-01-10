#include "Register.h"


using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {

	void Register::Registerfunc() {																																//this function opens the text file 
		//in a way that we can edit the file
		std::fstream myFile;
		myFile.open("User.txt", std::ios::out | std::ios::app);

		if (txtPassword2->Text != txtPassword3->Text) {																									//checks if the password confirmation 
			lblError->Text = "Passwords are not the same";																								//is the same as the password
		}
		else if (myFile.is_open() && chckOver18->Checked && !String::IsNullOrEmpty(txtUsername2->Text) && !String::IsNullOrEmpty(txtPassword2->Text)) { //checks if the user is above 18
			//and if the textboxes are null or not
			std::string Uname = msclr::interop::marshal_as<std::string>(txtUsername2->Text);
			std::string Pword = msclr::interop::marshal_as<std::string>(txtPassword2->Text);
			myFile << Uname << "," << Pword << "," << "0" << "\n";																						//edits the text file like this vv
			myFile.close();																																//		Username,Password,Credit
			this->Close();
		}
	}

	std::vector<std::string> Register::parseCommaDelimitedString(std::string line) {											//reads from the user text file
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

}