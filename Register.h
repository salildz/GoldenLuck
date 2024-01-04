#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <vector>
#include "User.h"



namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtUsername2;
	private: System::Windows::Forms::TextBox^ txtPassword2;
	private: System::Windows::Forms::TextBox^ txtPassword3;
	private: System::Windows::Forms::CheckBox^ chckOver18;
	private: System::Windows::Forms::Button^ btnSignUp;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register::typeid));
			this->txtUsername2 = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword2 = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword3 = (gcnew System::Windows::Forms::TextBox());
			this->chckOver18 = (gcnew System::Windows::Forms::CheckBox());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtUsername2
			// 
			this->txtUsername2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(175)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->txtUsername2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUsername2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F));
			this->txtUsername2->ForeColor = System::Drawing::Color::White;
			this->txtUsername2->Location = System::Drawing::Point(484, 268);
			this->txtUsername2->Name = L"txtUsername2";
			this->txtUsername2->Size = System::Drawing::Size(176, 50);
			this->txtUsername2->TabIndex = 4;
			// 
			// txtPassword2
			// 
			this->txtPassword2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)), static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtPassword2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F));
			this->txtPassword2->ForeColor = System::Drawing::Color::White;
			this->txtPassword2->Location = System::Drawing::Point(484, 341);
			this->txtPassword2->Name = L"txtPassword2";
			this->txtPassword2->Size = System::Drawing::Size(176, 50);
			this->txtPassword2->TabIndex = 5;
			// 
			// txtPassword3
			// 
			this->txtPassword3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)), static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtPassword3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 26.25F));
			this->txtPassword3->ForeColor = System::Drawing::Color::White;
			this->txtPassword3->Location = System::Drawing::Point(484, 415);
			this->txtPassword3->Name = L"txtPassword3";
			this->txtPassword3->Size = System::Drawing::Size(176, 50);
			this->txtPassword3->TabIndex = 6;
			// 
			// chckOver18
			// 
			this->chckOver18->AutoSize = true;
			this->chckOver18->BackColor = System::Drawing::Color::Transparent;
			this->chckOver18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->chckOver18->Location = System::Drawing::Point(539, 502);
			this->chckOver18->Name = L"chckOver18";
			this->chckOver18->Size = System::Drawing::Size(15, 14);
			this->chckOver18->TabIndex = 7;
			this->chckOver18->UseVisualStyleBackColor = true;
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(175)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->btnSignUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnSignUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignUp->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->btnSignUp->FlatAppearance->BorderSize = 0;
			this->btnSignUp->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignUp->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignUp->ForeColor = System::Drawing::Color::DimGray;
			this->btnSignUp->Location = System::Drawing::Point(510, 568);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(150, 57);
			this->btnSignUp->TabIndex = 8;
			this->btnSignUp->Text = L"Sign Up";
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &Register::btnSignUp_Click);
			// 
			// lblError
			// 
			this->lblError->BackColor = System::Drawing::Color::Transparent;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblError->Location = System::Drawing::Point(12, 191);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(920, 47);
			this->lblError->TabIndex = 9;
			this->lblError->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->chckOver18);
			this->Controls->Add(this->txtPassword3);
			this->Controls->Add(this->txtPassword2);
			this->Controls->Add(this->txtUsername2);
			this->Name = L"Register";
			this->Text = L"Register";
			this->Load += gcnew System::EventHandler(this, &Register::Register_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void Registerfunc() {

			std::fstream myFile;
			myFile.open("User.txt", std::ios::out);

			if (txtPassword2->Text != txtPassword3->Text) {
				lblError->Text = "Passwords are not the same";
			}
			else if (myFile.is_open() && chckOver18->Checked && !String::IsNullOrEmpty(txtUsername2->Text) && !String::IsNullOrEmpty(txtPassword2->Text)) {

				std::string Uname = msclr::interop::marshal_as<std::string>(txtUsername2->Text);
				std::string Pword = msclr::interop::marshal_as<std::string>(txtPassword2->Text);
				myFile << Uname << "," << Pword << "," << "0" << "\n";
				myFile.close();
				this->Close();
			}
		}

		std::vector<std::string> parseCommaDelimitedString(std::string line) {
			std::vector<std::string> result;
			std::stringstream s_stream(line);

			while (s_stream.good()) {
				std::string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}
			return result;
		}



#pragma endregion
	private: System::Void Register_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void txtPassword2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void txtPassword3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
		Registerfunc();
	}
	};
}
