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
	public:

	public:

	public:
		int coinChoice;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultBox))->BeginInit();
			this->SuspendLayout();
			// 
			// headsBtn
			// 
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
			this->tailsBtn->Location = System::Drawing::Point(568, 464);
			this->tailsBtn->Name = L"tailsBtn";
			this->tailsBtn->Size = System::Drawing::Size(166, 98);
			this->tailsBtn->TabIndex = 1;
			this->tailsBtn->Text = L"TAILS";
			this->tailsBtn->UseVisualStyleBackColor = true;
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50));
			this->label1->Location = System::Drawing::Point(113, 21);
			this->label1->MaximumSize = System::Drawing::Size(1000, 1000);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(720, 130);
			this->label1->TabIndex = 3;
			this->label1->Click += gcnew System::EventHandler(this, &CoinFlip::label1_Click);
			// 
			// CoinFlip
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->tailsBtn);
			this->Controls->Add(this->headsBtn);
			this->Name = L"CoinFlip";
			this->Text = L"CoinFlip";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultBox))->EndInit();
			this->ResumeLayout(false);

		}
		void resetGame() {
			resultBox->Refresh();
		}
		void loadResult() {
			if (coinResult() == true) resultBox->Load("coin\\coins-heads.gif");
			else resultBox->Load("coin\\coins-tails.gif");

		}

#pragma endregion
	private: System::Void headsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		coinChoice = 0;
		if (coinResult()) label1->Text = "YOU WIN!";
		else label1->Text = "YOU LOSE!";
		loadResult();
	}
	private: System::Void tailsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		coinChoice = 1;
		if (coinResult()) label1->Text = "YOU WIN!";
		else label1->Text = "YOU LOSE!";
		loadResult();
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}