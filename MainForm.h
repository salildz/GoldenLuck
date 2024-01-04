#pragma once
#include "BlackJack.h"
#include "CoinFlip.h"
#include "Poker.h"
#include "RockPaperScissors.h"
#include "Slot.h"
#include "Bank.h"

namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBlackJack;
	private: System::Windows::Forms::Button^ btnPoker;
	private: System::Windows::Forms::Button^ btnSlot;
	private: System::Windows::Forms::Button^ btnCoinFlip;
	private: System::Windows::Forms::Button^ btnRockPaperScissors;
	private: System::Windows::Forms::Button^ btnBank;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnBlackJack = (gcnew System::Windows::Forms::Button());
			this->btnPoker = (gcnew System::Windows::Forms::Button());
			this->btnSlot = (gcnew System::Windows::Forms::Button());
			this->btnCoinFlip = (gcnew System::Windows::Forms::Button());
			this->btnRockPaperScissors = (gcnew System::Windows::Forms::Button());
			this->btnBank = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnBlackJack
			// 
			this->btnBlackJack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBlackJack.BackgroundImage")));
			this->btnBlackJack->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBlackJack->Location = System::Drawing::Point(42, 333);
			this->btnBlackJack->Name = L"btnBlackJack";
			this->btnBlackJack->Size = System::Drawing::Size(175, 125);
			this->btnBlackJack->TabIndex = 0;
			this->btnBlackJack->Text = L"BlackJack";
			this->btnBlackJack->UseVisualStyleBackColor = true;
			this->btnBlackJack->Click += gcnew System::EventHandler(this, &MainForm::btnBlackJack_Click);
			// 
			// btnPoker
			// 
			this->btnPoker->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPoker.BackgroundImage")));
			this->btnPoker->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnPoker->Location = System::Drawing::Point(392, 333);
			this->btnPoker->Name = L"btnPoker";
			this->btnPoker->Size = System::Drawing::Size(175, 125);
			this->btnPoker->TabIndex = 1;
			this->btnPoker->Text = L"Poker";
			this->btnPoker->UseVisualStyleBackColor = true;
			this->btnPoker->Click += gcnew System::EventHandler(this, &MainForm::btnPoker_Click);
			// 
			// btnSlot
			// 
			this->btnSlot->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnSlot->Location = System::Drawing::Point(742, 333);
			this->btnSlot->Name = L"btnSlot";
			this->btnSlot->Size = System::Drawing::Size(175, 125);
			this->btnSlot->TabIndex = 2;
			this->btnSlot->Text = L"Slot";
			this->btnSlot->UseVisualStyleBackColor = true;
			this->btnSlot->Click += gcnew System::EventHandler(this, &MainForm::btnSlot_Click);
			// 
			// btnCoinFlip
			// 
			this->btnCoinFlip->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnCoinFlip->Location = System::Drawing::Point(217, 482);
			this->btnCoinFlip->Name = L"btnCoinFlip";
			this->btnCoinFlip->Size = System::Drawing::Size(175, 125);
			this->btnCoinFlip->TabIndex = 3;
			this->btnCoinFlip->Text = L"CoinFlip";
			this->btnCoinFlip->UseVisualStyleBackColor = true;
			this->btnCoinFlip->Click += gcnew System::EventHandler(this, &MainForm::btnCoinFlip_Click);
			// 
			// btnRockPaperScissors
			// 
			this->btnRockPaperScissors->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRockPaperScissors->Location = System::Drawing::Point(567, 482);
			this->btnRockPaperScissors->Name = L"btnRockPaperScissors";
			this->btnRockPaperScissors->Size = System::Drawing::Size(175, 125);
			this->btnRockPaperScissors->TabIndex = 4;
			this->btnRockPaperScissors->Text = L"Rock Paper Scissors";
			this->btnRockPaperScissors->UseVisualStyleBackColor = true;
			this->btnRockPaperScissors->Click += gcnew System::EventHandler(this, &MainForm::btnRockPaperScissors_Click);
			// 
			// btnBank
			// 
			this->btnBank->Location = System::Drawing::Point(742, 28);
			this->btnBank->Name = L"btnBank";
			this->btnBank->Size = System::Drawing::Size(77, 55);
			this->btnBank->TabIndex = 5;
			this->btnBank->Text = L"Bank";
			this->btnBank->UseVisualStyleBackColor = true;
			this->btnBank->Click += gcnew System::EventHandler(this, &MainForm::btnBank_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->btnBank);
			this->Controls->Add(this->btnRockPaperScissors);
			this->Controls->Add(this->btnCoinFlip);
			this->Controls->Add(this->btnSlot);
			this->Controls->Add(this->btnPoker);
			this->Controls->Add(this->btnBlackJack);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Golden Luck";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void GameClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		//Shows MainForm again
		this->Show();
	}

		   //BlackJack------------------------------------------------------------
	private: System::Void btnBlackJack_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hides MainForm
		this->Hide();
		//Initializes BlackJack game
		BlackJack^ blackJack = gcnew BlackJack();
		blackJack->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::GameClosed);
		blackJack->Show();
	}
	


		   //Poker------------------------------------------------------------
	private: System::Void btnPoker_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hides MainForm
		this->Hide();
		//Initializes Poker game
		Poker^ poker = gcnew Poker();
		poker->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::GameClosed);
		poker->Show();
	}


		   //Slot------------------------------------------------------------
	private: System::Void btnSlot_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hides MainForm
		this->Hide();
		//Initializes Poker game
		Slot^ slot = gcnew Slot();
		slot->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::GameClosed);
		slot->Show();
	}


		   //CoinFlip------------------------------------------------------------
	private: System::Void btnCoinFlip_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hides MainForm
		this->Hide();
		//Initializes Poker game
		CoinFlip^ coinFlip = gcnew CoinFlip();
		coinFlip->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::GameClosed);
		coinFlip->Show();
	}


		   //RockPaperScissors------------------------------------------------------------
	private: System::Void btnRockPaperScissors_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hides MainForm
		this->Hide();
		//Initializes Poker game
		RockPaperScissors^ rockPaperScissors = gcnew RockPaperScissors();
		rockPaperScissors->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::GameClosed);
		rockPaperScissors->Show();
	}
	private: System::Void btnBank_Click(System::Object^ sender, System::EventArgs^ e) {
		Bank^ bank = gcnew Bank();
		bank->Show();
	}
};
}
