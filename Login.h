#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <vector>
#include "MainForm.h"
#include "User.h"
#include "Register.h"


namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		String^ finalUsername;
		String^ finalPassword;

		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void Login::Loginfunc();
		std::vector<std::string> parseCommaDelimitedString(std::string line);
		void PlayMusic(const char* filePath, bool loop);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnSignIn;
	private: System::Windows::Forms::Button^ btnRegister;


	private: System::Windows::Forms::TextBox^ txtUsername1;
	private: System::Windows::Forms::TextBox^ txtPassword1;
	private: System::Windows::Forms::Label^ lblError;





	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->btnSignIn = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->txtUsername1 = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword1 = (gcnew System::Windows::Forms::TextBox());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSignIn
			// 
			this->btnSignIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->btnSignIn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnSignIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignIn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->btnSignIn->FlatAppearance->BorderSize = 0;
			this->btnSignIn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignIn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignIn->ForeColor = System::Drawing::Color::Transparent;
			this->btnSignIn->Location = System::Drawing::Point(300, 568);
			this->btnSignIn->Name = L"btnSignIn";
			this->btnSignIn->Size = System::Drawing::Size(150, 57);
			this->btnSignIn->TabIndex = 1;
			this->btnSignIn->Text = L"Sign In";
			this->btnSignIn->UseVisualStyleBackColor = false;
			this->btnSignIn->Click += gcnew System::EventHandler(this, &Login::btnSignIn_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->btnRegister->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRegister->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->btnRegister->FlatAppearance->BorderSize = 0;
			this->btnRegister->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->ForeColor = System::Drawing::Color::Transparent;
			this->btnRegister->Location = System::Drawing::Point(510, 568);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(150, 57);
			this->btnRegister->TabIndex = 2;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &Login::btnRegister_Click);
			// 
			// txtUsername1
			// 
			this->txtUsername1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(132)), static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->txtUsername1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUsername1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F));
			this->txtUsername1->ForeColor = System::Drawing::Color::White;
			this->txtUsername1->Location = System::Drawing::Point(484, 269);
			this->txtUsername1->Name = L"txtUsername1";
			this->txtUsername1->Size = System::Drawing::Size(176, 50);
			this->txtUsername1->TabIndex = 3;
			// 
			// txtPassword1
			// 
			this->txtPassword1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->txtPassword1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F));
			this->txtPassword1->ForeColor = System::Drawing::Color::White;
			this->txtPassword1->Location = System::Drawing::Point(484, 341);
			this->txtPassword1->Name = L"txtPassword1";
			this->txtPassword1->Size = System::Drawing::Size(176, 50);
			this->txtPassword1->TabIndex = 4;
			this->txtPassword1->PasswordChar = '*';
			// 
			// lblError
			// 
			this->lblError->BackColor = System::Drawing::Color::Transparent;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblError->Location = System::Drawing::Point(12, 191);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(920, 47);
			this->lblError->TabIndex = 10;
			this->lblError->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->txtPassword1);
			this->Controls->Add(this->txtUsername1);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->btnSignIn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}








#pragma endregion
	private: System::Void GameClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Show();																											//Shows MainForm again
	}

	private: System::Void GameTerminated(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		std::ifstream inFile("User.txt");																						//Use ifstream for reading
		std::ofstream outFile("Temp_User.txt");																					//Use ofstream for writing to a temporary file

		if (inFile.is_open() && outFile.is_open()) {
			std::string line;

			while (getline(inFile, line)) {
				std::vector<std::string> parsedline = parseCommaDelimitedString(line);
				std::string username = parsedline.at(0);
				std::string password = parsedline.at(1);

				std::string editUname = msclr::interop::marshal_as<std::string>(finalUsername->ToString());
				std::string editPword = msclr::interop::marshal_as<std::string>(finalPassword->ToString());

				if (username == editUname && password == editPword) {
					outFile << editUname << "," << editPword << "," << User::credit << "\n";
				}
				else {
					outFile << line << "\n";
				}
			}

			inFile.close();
			outFile.close();

																																//Rename or replace the original file with the updated file
			std::remove("User.txt");
			std::rename("Temp_User.txt", "User.txt");
		}

		this->Close();																											//Close the form after updating the file
	}

	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
		PlayMusic("musics\\music.wav", true);
	}

	private: System::Void btnSignIn_Click(System::Object^ sender, System::EventArgs^ e) {
		Loginfunc();
	}
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hides Login
		this->Hide();
		Register^ register1 = gcnew Register();
		register1->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Login::GameClosed);
		register1->Show();
	}
	};
}