#include <fstream>

#pragma once
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

		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Log_in;
	private: System::Windows::Forms::CheckBox^ AgeTick;
	protected:


	private: System::Windows::Forms::Label^ Username;


	private: System::Windows::Forms::Label^ Password;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ UsernameLog;
	private: System::Windows::Forms::TextBox^ PasswordLog;



	private: System::Windows::Forms::Button^ Register;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ PasswordReg2;

	private: System::Windows::Forms::TextBox^ PasswordReg;

	private: System::Windows::Forms::TextBox^ UsernameReg;







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
			System::Windows::Forms::Label^ label4;
			this->Log_in = (gcnew System::Windows::Forms::Button());
			this->AgeTick = (gcnew System::Windows::Forms::CheckBox());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->Password = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->UsernameLog = (gcnew System::Windows::Forms::TextBox());
			this->PasswordLog = (gcnew System::Windows::Forms::TextBox());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->UsernameReg = (gcnew System::Windows::Forms::TextBox());
			this->PasswordReg = (gcnew System::Windows::Forms::TextBox());
			this->PasswordReg2 = (gcnew System::Windows::Forms::TextBox());
			label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label4
			// 
			label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			label4->Location = System::Drawing::Point(100, 58);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(98, 23);
			label4->TabIndex = 5;
			label4->Text = L"Username :";
			// 
			// Log_in
			// 
			this->Log_in->Location = System::Drawing::Point(101, 267);
			this->Log_in->Name = L"Log_in";
			this->Log_in->Size = System::Drawing::Size(112, 48);
			this->Log_in->TabIndex = 0;
			this->Log_in->Text = L"Login";
			this->Log_in->UseVisualStyleBackColor = true;
			this->Log_in->Click += gcnew System::EventHandler(this, &Login::Log_in_Click);
			// 
			// AgeTick
			// 
			this->AgeTick->Location = System::Drawing::Point(178, 200);
			this->AgeTick->Name = L"AgeTick";
			this->AgeTick->Size = System::Drawing::Size(100, 17);
			this->AgeTick->TabIndex = 1;
			this->AgeTick->Text = L"I am above 18";
			this->AgeTick->UseVisualStyleBackColor = true;
			this->AgeTick->CheckedChanged += gcnew System::EventHandler(this, &Login::AgeTick_CheckedChanged);
			// 
			// Username
			// 
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->Username->Location = System::Drawing::Point(100, 80);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(98, 23);
			this->Username->TabIndex = 2;
			this->Username->Text = L"Username :";
			this->Username->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Password
			// 
			this->Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->Password->Location = System::Drawing::Point(100, 155);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(98, 23);
			this->Password->TabIndex = 3;
			this->Password->Text = L"Password :";
			this->Password->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Password->UseWaitCursor = true;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(100, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 23);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Password :";
			// 
			// UsernameLog
			// 
			this->UsernameLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->UsernameLog->Location = System::Drawing::Point(226, 77);
			this->UsernameLog->Name = L"UsernameLog";
			this->UsernameLog->Size = System::Drawing::Size(130, 26);
			this->UsernameLog->TabIndex = 6;
			this->UsernameLog->TextChanged += gcnew System::EventHandler(this, &Login::UsernameLog_TextChanged);
			// 
			// PasswordLog
			// 
			this->PasswordLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->PasswordLog->Location = System::Drawing::Point(226, 152);
			this->PasswordLog->Name = L"PasswordLog";
			this->PasswordLog->Size = System::Drawing::Size(130, 26);
			this->PasswordLog->TabIndex = 7;
			this->PasswordLog->TextChanged += gcnew System::EventHandler(this, &Login::PasswordLog_TextChanged);
			// 
			// Register
			// 
			this->Register->Location = System::Drawing::Point(241, 267);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(112, 48);
			this->Register->TabIndex = 8;
			this->Register->Text = L"Register";
			this->Register->UseVisualStyleBackColor = true;
			this->Register->Click += gcnew System::EventHandler(this, &Login::Register_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->Username);
			this->panel1->Controls->Add(this->UsernameLog);
			this->panel1->Controls->Add(this->Password);
			this->panel1->Controls->Add(this->PasswordLog);
			this->panel1->Location = System::Drawing::Point(0, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(484, 272);
			this->panel1->TabIndex = 9;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(label4);
			this->panel2->Controls->Add(this->AgeTick);
			this->panel2->Controls->Add(this->UsernameReg);
			this->panel2->Controls->Add(this->PasswordReg);
			this->panel2->Controls->Add(this->PasswordReg2);
			this->panel2->Location = System::Drawing::Point(-6, -14);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(470, 267);
			this->panel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(100, 149);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Password :";
			// 
			// UsernameReg
			// 
			this->UsernameReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->UsernameReg->Location = System::Drawing::Point(226, 55);
			this->UsernameReg->Name = L"UsernameReg";
			this->UsernameReg->Size = System::Drawing::Size(130, 26);
			this->UsernameReg->TabIndex = 11;
			this->UsernameReg->TextChanged += gcnew System::EventHandler(this, &Login::UsernameReg_TextChanged);
			// 
			// PasswordReg
			// 
			this->PasswordReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->PasswordReg->Location = System::Drawing::Point(226, 103);
			this->PasswordReg->Name = L"PasswordReg";
			this->PasswordReg->Size = System::Drawing::Size(130, 26);
			this->PasswordReg->TabIndex = 12;
			this->PasswordReg->TextChanged += gcnew System::EventHandler(this, &Login::PasswordReg_TextChanged);
			// 
			// PasswordReg2
			// 
			this->PasswordReg2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->PasswordReg2->Location = System::Drawing::Point(226, 149);
			this->PasswordReg2->Name = L"PasswordReg2";
			this->PasswordReg2->Size = System::Drawing::Size(130, 26);
			this->PasswordReg2->TabIndex = 13;
			this->PasswordReg2->TextChanged += gcnew System::EventHandler(this, &Login::PasswordReg2_TextChanged);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(454, 331);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Log_in);
			this->Controls->Add(this->Register);
			this->Name = L"Login";
			this->Text = L"Login";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}

		void Loginfunc() {
			if ()
		}

		void Registerfunc() {

		}

#pragma endregion
private: System::Void Log_in_Click(System::Object^ sender, System::EventArgs^ e) {
	panel2->Enabled = false;
	panel2->Visible = false;
	Loginfunc();
}
private: System::Void UsernameLog_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void PasswordLog_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void UsernameReg_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void PasswordReg_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void PasswordReg2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AgeTick_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e) {
	panel1->Enabled = false;
	panel1->Visible = false;
	Registerfunc();
}
};
}
