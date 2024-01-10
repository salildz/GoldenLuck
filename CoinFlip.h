#pragma once

namespace GoldenLuck {

	using namespace System::Collections::Generic;


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CoinFlip
	/// </summary>
	public ref class CoinFlip : public System::Windows::Forms::Form
	{
	public:
		int coinFlip();
		bool coinResult();
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox;
	private: System::Windows::Forms::Button^ buttonBet;
	public:

	public:

	public:
		int coinChoice;
	private: System::Windows::Forms::Label^ label2;
	public:
		int pChoice;
		bool canBet();
		void loadResult();
		void resetGame();
		System::Void CoinFlip_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonBet_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void headsBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void tailsBtn_Click(System::Object^ sender, System::EventArgs^ e);
		CoinFlip(void)
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
		~CoinFlip()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ headsBtn;
	private: System::Windows::Forms::Button^ tailsBtn;
	private: System::Windows::Forms::PictureBox^ resultBox;

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
			this->headsBtn = (gcnew System::Windows::Forms::Button());
			this->tailsBtn = (gcnew System::Windows::Forms::Button());
			this->resultBox = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->buttonBet = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultBox))->BeginInit();
			this->SuspendLayout();
			// 
			// headsBtn
			// 
			this->headsBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F));
			this->headsBtn->Location = System::Drawing::Point(182, 464);
			this->headsBtn->Name = L"headsBtn";
			this->headsBtn->Size = System::Drawing::Size(166, 98);
			this->headsBtn->TabIndex = 0;
			this->headsBtn->Text = L"HEADS";
			this->headsBtn->UseVisualStyleBackColor = true;
			this->headsBtn->Click += gcnew System::EventHandler(this, &CoinFlip::headsBtn_Click);
			// 
			// tailsBtn
			// 
			this->tailsBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F));
			this->tailsBtn->Location = System::Drawing::Point(568, 464);
			this->tailsBtn->Name = L"tailsBtn";
			this->tailsBtn->Size = System::Drawing::Size(166, 98);
			this->tailsBtn->TabIndex = 1;
			this->tailsBtn->Text = L"TAILS";
			this->tailsBtn->UseVisualStyleBackColor = true;
			this->tailsBtn->Click += gcnew System::EventHandler(this, &CoinFlip::tailsBtn_Click);
			// 
			// resultBox
			// 
			this->resultBox->Location = System::Drawing::Point(360, 185);
			this->resultBox->Name = L"resultBox";
			this->resultBox->Size = System::Drawing::Size(211, 201);
			this->resultBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->resultBox->TabIndex = 2;
			this->resultBox->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.5F));
			this->label1->Location = System::Drawing::Point(113, 21);
			this->label1->MaximumSize = System::Drawing::Size(1000, 1000);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(720, 130);
			this->label1->TabIndex = 3;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox
			// 
			this->comboBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"100", L"500", L"1000", L"2000", L"3000", L"4000",
					L"5000"
			});
			this->comboBox->Location = System::Drawing::Point(394, 464);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(121, 21);
			this->comboBox->TabIndex = 1;
			this->comboBox->Text = L"0";
			// 
			// buttonBet
			// 
			this->buttonBet->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F));
			this->buttonBet->Location = System::Drawing::Point(394, 503);
			this->buttonBet->Name = L"buttonBet";
			this->buttonBet->Size = System::Drawing::Size(121, 59);
			this->buttonBet->TabIndex = 5;
			this->buttonBet->Text = L"BET";
			this->buttonBet->UseVisualStyleBackColor = true;
			this->buttonBet->Click += gcnew System::EventHandler(this, &CoinFlip::buttonBet_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.5F));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(628, 593);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(304, 55);
			this->label2->TabIndex = 6;
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// CoinFlip
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonBet);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->tailsBtn);
			this->Controls->Add(this->headsBtn);
			this->Name = L"CoinFlip";
			this->Text = L"CoinFlip";
			this->Load += gcnew System::EventHandler(this, &CoinFlip::CoinFlip_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultBox))->EndInit();
			this->ResumeLayout(false);

		}



#pragma endregion



	};
}
