#pragma once
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <iostream>

namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BlackJack
	/// </summary>
	public ref class Poker : public System::Windows::Forms::Form
	{
	public:
		Poker(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Hand^ userHand;
		Hand^ dealerHand;
		Hand^ pokerTableHand;
		Deck^ deck;
		int checkForFirstCard(Hand^ hand);
		int checkForSecondCard(Hand^ hand);
		int checkForBothCard(Hand^ hand);
	private: System::Windows::Forms::Panel^ pnlGame;
	private: System::Windows::Forms::Button^ btnStart;


	private: System::Windows::Forms::Label^ lblResult;
	private: System::Windows::Forms::Button^ btnBet;



	public:
		int bet;
		void initializeGame();
		void resetGame();
		void dealHiddenCard(Hand^ hand);
		void dealCard(Hand^ hand);
		bool checkOnePair(Hand^ hand);
		bool checkTwoPair(Hand^ hand);
		bool checkHighCard(Hand^ hand);
		bool checkThreeOfKind(Hand^ hand);
		bool checkStraight(Hand^ hand);
		bool checkFlush(Hand^ hand);
		bool checkFullHouse(Hand^ hand);
		bool checkFourOfKind(Hand^ hand);
		bool checkStraightFlush(Hand^ hand);
		bool checkRoyalFlush(Hand^ hand);
		Hand^ sortForRank(Hand^ hand);
		System::Void btnBet_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e);
		void loadDealerCardImages();
		void loadUserCardImages();
		void loadTableCardImages();
		void endGame();
		Hand^ faceUpDealerHand(Hand^ hand);
		int checkForNone(Hand^ hand);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Poker()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->pnlGame = (gcnew System::Windows::Forms::Panel());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnBet = (gcnew System::Windows::Forms::Button());
			this->pnlGame->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlGame
			// 
			this->pnlGame->Controls->Add(this->lblResult);
			this->pnlGame->Location = System::Drawing::Point(12, 12);
			this->pnlGame->Name = L"pnlGame";
			this->pnlGame->Size = System::Drawing::Size(920, 530);
			this->pnlGame->TabIndex = 2;
			// 
			// lblResult
			// 
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblResult->Location = System::Drawing::Point(578, 162);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(342, 202);
			this->lblResult->TabIndex = 2;
			this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::Teal;
			this->btnStart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStart->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->btnStart->FlatAppearance->BorderSize = 0;
			this->btnStart->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnStart->Location = System::Drawing::Point(27, 548);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(110, 70);
			this->btnStart->TabIndex = 3;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &Poker::btnStart_Click);
			// 
			// btnBet
			// 
			this->btnBet->BackColor = System::Drawing::Color::Teal;
			this->btnBet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBet->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBet->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->btnBet->FlatAppearance->BorderSize = 0;
			this->btnBet->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnBet->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBet->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBet->Location = System::Drawing::Point(406, 548);
			this->btnBet->Name = L"btnBet";
			this->btnBet->Size = System::Drawing::Size(110, 70);
			this->btnBet->TabIndex = 4;
			this->btnBet->Text = L"Bet";
			this->btnBet->UseVisualStyleBackColor = false;
			this->btnBet->Click += gcnew System::EventHandler(this, &Poker::btnBet_Click);
			// 
			// Poker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->btnBet);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->pnlGame);
			this->Name = L"Poker";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BlackJack";
			this->Load += gcnew System::EventHandler(this, &Poker::Poker_Load);
			this->pnlGame->ResumeLayout(false);
			this->ResumeLayout(false);

		}






#pragma endregion
	private: System::Void Poker_Load(System::Object^ sender, System::EventArgs^ e) {


	}



	};

}
