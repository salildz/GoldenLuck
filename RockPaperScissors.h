#pragma once
#include "User.h"
namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RockPaperScissors
	/// </summary>
	public ref class RockPaperScissors : public System::Windows::Forms::Form
	{
	private:
		int round, scoreP, scoreD;

		char Pchoice, Dchoice;
	private: System::Windows::Forms::PictureBox^ Dbox;
	private: System::Windows::Forms::ComboBox^ comboBox;
	private: System::Windows::Forms::Label^ labelBalance;

	private: System::Windows::Forms::PictureBox^ Pbox;


	public:
		bool canBet();
		RockPaperScissors(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


		void RockPaperScissors::Dchoicegenerator();

		void RockPaperScissors::playRPSround();

		void RockPaperScissors::calculatescore();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RockPaperScissors()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblP;
	private: System::Windows::Forms::Label^ lblD;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ start;
	private: System::Windows::Forms::Button^ Paper;
	private: System::Windows::Forms::Button^ Rock;
	private: System::Windows::Forms::Button^ Scissor;
	private: System::Windows::Forms::Label^ lblRound;
	private: System::Windows::Forms::Label^ lblResult;

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
			this->Paper = (gcnew System::Windows::Forms::Button());
			this->Rock = (gcnew System::Windows::Forms::Button());
			this->Scissor = (gcnew System::Windows::Forms::Button());
			this->lblRound = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Dbox = (gcnew System::Windows::Forms::PictureBox());
			this->Pbox = (gcnew System::Windows::Forms::PictureBox());
			this->lblD = (gcnew System::Windows::Forms::Label());
			this->lblP = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->labelBalance = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dbox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Pbox))->BeginInit();
			this->SuspendLayout();
			// 
			// Paper
			// 
			this->Paper->BackColor = System::Drawing::Color::Firebrick;
			this->Paper->Location = System::Drawing::Point(252, 321);
			this->Paper->Name = L"Paper";
			this->Paper->Size = System::Drawing::Size(118, 72);
			this->Paper->TabIndex = 1;
			this->Paper->Text = L"PAPER";
			this->Paper->UseVisualStyleBackColor = false;
			this->Paper->Click += gcnew System::EventHandler(this, &RockPaperScissors::Paper_Click);
			// 
			// Rock
			// 
			this->Rock->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Rock->Location = System::Drawing::Point(80, 321);
			this->Rock->Name = L"Rock";
			this->Rock->Size = System::Drawing::Size(117, 72);
			this->Rock->TabIndex = 2;
			this->Rock->Text = L"ROCK";
			this->Rock->UseVisualStyleBackColor = false;
			this->Rock->Click += gcnew System::EventHandler(this, &RockPaperScissors::Rock_Click);
			// 
			// Scissor
			// 
			this->Scissor->BackColor = System::Drawing::Color::YellowGreen;
			this->Scissor->Location = System::Drawing::Point(432, 321);
			this->Scissor->Name = L"Scissor";
			this->Scissor->Size = System::Drawing::Size(120, 72);
			this->Scissor->TabIndex = 3;
			this->Scissor->Text = L"SCISSOR";
			this->Scissor->UseVisualStyleBackColor = false;
			this->Scissor->Click += gcnew System::EventHandler(this, &RockPaperScissors::Scissor_Click);
			// 
			// lblRound
			// 
			this->lblRound->AutoEllipsis = true;
			this->lblRound->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblRound->Location = System::Drawing::Point(172, 13);
			this->lblRound->Name = L"lblRound";
			this->lblRound->Size = System::Drawing::Size(118, 31);
			this->lblRound->TabIndex = 4;
			this->lblRound->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblResult
			// 
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblResult->Location = System::Drawing::Point(177, 239);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(113, 34);
			this->lblResult->TabIndex = 5;
			this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(252, 414);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(118, 69);
			this->start->TabIndex = 6;
			this->start->Text = L"START";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &RockPaperScissors::start_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->Dbox);
			this->panel1->Controls->Add(this->Pbox);
			this->panel1->Controls->Add(this->lblD);
			this->panel1->Controls->Add(this->lblP);
			this->panel1->Controls->Add(this->lblRound);
			this->panel1->Controls->Add(this->lblResult);
			this->panel1->Location = System::Drawing::Point(80, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(472, 286);
			this->panel1->TabIndex = 7;
			// 
			// Dbox
			// 
			this->Dbox->BackColor = System::Drawing::Color::Transparent;
			this->Dbox->Location = System::Drawing::Point(319, 82);
			this->Dbox->Name = L"Dbox";
			this->Dbox->Size = System::Drawing::Size(100, 108);
			this->Dbox->TabIndex = 11;
			this->Dbox->TabStop = false;
			// 
			// Pbox
			// 
			this->Pbox->BackColor = System::Drawing::Color::Transparent;
			this->Pbox->Location = System::Drawing::Point(52, 82);
			this->Pbox->Name = L"Pbox";
			this->Pbox->Size = System::Drawing::Size(100, 108);
			this->Pbox->TabIndex = 10;
			this->Pbox->TabStop = false;
			// 
			// lblD
			// 
			this->lblD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblD->Location = System::Drawing::Point(355, 217);
			this->lblD->Name = L"lblD";
			this->lblD->Size = System::Drawing::Size(35, 47);
			this->lblD->TabIndex = 9;
			// 
			// lblP
			// 
			this->lblP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblP->Location = System::Drawing::Point(82, 217);
			this->lblP->Name = L"lblP";
			this->lblP->Size = System::Drawing::Size(35, 47);
			this->lblP->TabIndex = 8;
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
			this->comboBox->Location = System::Drawing::Point(80, 414);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(110, 21);
			this->comboBox->TabIndex = 1;
			this->comboBox->Text = L"0";
			// 
			// labelBalance
			// 
			this->labelBalance->Location = System::Drawing::Point(432, 414);
			this->labelBalance->Name = L"labelBalance";
			this->labelBalance->Size = System::Drawing::Size(120, 23);
			this->labelBalance->TabIndex = 9;
			// 
			// RockPaperScissors
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(638, 498);
			this->Controls->Add(this->labelBalance);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->start);
			this->Controls->Add(this->Scissor);
			this->Controls->Add(this->Rock);
			this->Controls->Add(this->Paper);
			this->Name = L"RockPaperScissors";
			this->Text = L"RockPaperScissors";
			this->Load += gcnew System::EventHandler(this, &RockPaperScissors::RockPaperScissors_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dbox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Pbox))->EndInit();
			this->ResumeLayout(false);

		}

		void resetGame() {																				//restarts the game for a fresh start
			round = 1;
			scoreP = 0;
			scoreD = 0;
			Rock->Visible = true;
			Scissor->Visible = true;
			Paper->Visible = true;
			Rock->Enabled = true;
			Paper->Enabled = true;
			Scissor->Enabled = true;
			start->Enabled = false;
			lblRound->Visible = true;
			lblResult->Visible = true;
			lblResult->Text = " ";
			lblD->Text = "0";
			lblP->Text = "0";
			lblRound->Text = "Round 1";

		}

		void endGame() {                                                                                   //This is where the winner gets identified
			Rock->Enabled = false;																		   //also locks the Paper Rock and Scissor buttons
			Paper->Enabled = false;
			Scissor->Enabled = false;
			start->Enabled = true;


			if (scoreP == scoreD) {
				lblRound->Text = " ";
				lblResult->Text = "Tie";

				User::credit += Convert::ToInt32(comboBox->SelectedItem);

				labelBalance->Text = "Credit: " + User::credit.ToString();
			}
			else if (scoreP > scoreD) {
				lblRound->Text = " ";
				lblResult->Text = "You Win!";

				User::credit += Convert::ToInt32(comboBox->SelectedItem) * 2;

				labelBalance->Text = "Credit: " + User::credit.ToString();
			}
			else if (scoreP < scoreD) {
				lblRound->Text = " ";
				lblResult->Text = "You Lose!";
				labelBalance->Text = "Credit: " + User::credit.ToString();
			}

		}

		void loadImages() {                                                                                 //to load the images of Rock Paper Scissor
			switch (Dchoice) {
			case 'R':
				Dbox->Load("RPS\\Rock.png");
				break;
			case 'P':
				Dbox->Load("RPS\\Paper.png");
				break;
			case 'S':
				Dbox->Load("RPS\\Scissor.png");
				break;
			}

			switch (Pchoice) {
			case 'R':
				Pbox->Load("RPS\\Rock.png");
				break;
			case 'P':
				Pbox->Load("RPS\\Paper.png");
				break;
			case 'S':
				Pbox->Load("RPS\\Scissor.png");
				break;
			}

			Pbox->Refresh();																				 //refresh so we can see the new picture
			Dbox->Refresh();
		}

#pragma endregion
	private: System::Void RockPaperScissors_Load(System::Object^ sender, System::EventArgs^ e) {             //makes sure user cant interact with the game before clicking start.
		Rock->Visible = false;
		Scissor->Visible = false;
		Paper->Visible = false;
		lblRound->Visible = false;
		lblResult->Visible = false;
		start->Visible = true;
		labelBalance->Text = "Credit: " + User::credit.ToString();
		labelBalance->Visible = true;
		comboBox->Visible = true;

	}

	private: System::Void Rock_Click(System::Object^ sender, System::EventArgs^ e) {						//buttons...
		Pchoice = 'R';
		playRPSround();
	}
	private: System::Void Paper_Click(System::Object^ sender, System::EventArgs^ e) {
		Pchoice = 'P';
		playRPSround();
	}
	private: System::Void Scissor_Click(System::Object^ sender, System::EventArgs^ e) {
		Pchoice = 'S';
		playRPSround();
	}

	private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e) {
		if (canBet()) {

			User::credit -= Convert::ToInt32(comboBox->SelectedItem);
			labelBalance->Text = "Credit: " + User::credit;
			resetGame();
		}



	}
	};
}