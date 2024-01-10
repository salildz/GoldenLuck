#pragma once
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <iostream>
#include "User.h"
namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BlackJack : public System::Windows::Forms::Form
	{
	public:
		BlackJack(void)
		{
			InitializeComponent();
			this->lblBalance->Text = "Credit: " + User::credit;
		}
		Hand^ userHand;
		Hand^ dealerHand;
		Deck^ deck;
	private: System::Windows::Forms::Button^ btnHit;
	private: System::Windows::Forms::Button^ btnStay;
	private: System::Windows::Forms::Panel^ pnlGame;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Label^ lblDealer;
	private: System::Windows::Forms::Label^ lblResult;
	private: System::Windows::Forms::Label^ lblBalance;
	private: System::Windows::Forms::ComboBox^ comboBox;



	public:

		int bet;
		void initializeGame();
		void resetGame();
		void dealHiddenCard(Hand^ hand);
		void dealCard(Hand^ hand);
		int reduceDealerAce();
		int reduceUserAce();
		bool isBlackJack(Hand^ hand);
		void printCredit();
		void loadDealerCardImages();
		void loadUserCardImages();
		void endGame();
		void faceUpDealerHand();
		bool canBet();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BlackJack()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BlackJack::typeid));
			this->btnHit = (gcnew System::Windows::Forms::Button());
			this->btnStay = (gcnew System::Windows::Forms::Button());
			this->pnlGame = (gcnew System::Windows::Forms::Panel());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->lblDealer = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->pnlGame->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnHit
			// 
			this->btnHit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(117)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->btnHit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnHit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHit->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->btnHit->FlatAppearance->BorderSize = 0;
			this->btnHit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnHit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHit->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnHit->Location = System::Drawing::Point(278, 548);
			this->btnHit->Name = L"btnHit";
			this->btnHit->Size = System::Drawing::Size(110, 70);
			this->btnHit->TabIndex = 0;
			this->btnHit->Text = L"Hit";
			this->btnHit->UseVisualStyleBackColor = false;
			this->btnHit->Click += gcnew System::EventHandler(this, &BlackJack::btnHit_Click);
			// 
			// btnStay
			// 
			this->btnStay->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(117)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->btnStay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnStay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStay->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->btnStay->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnStay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStay->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnStay->Location = System::Drawing::Point(546, 548);
			this->btnStay->Name = L"btnStay";
			this->btnStay->Size = System::Drawing::Size(110, 70);
			this->btnStay->TabIndex = 1;
			this->btnStay->Text = L"Stay";
			this->btnStay->UseVisualStyleBackColor = false;
			this->btnStay->Click += gcnew System::EventHandler(this, &BlackJack::btnStay_Click);
			// 
			// pnlGame
			// 
			this->pnlGame->BackColor = System::Drawing::Color::Transparent;
			this->pnlGame->Controls->Add(this->lblResult);
			this->pnlGame->Controls->Add(this->lblUser);
			this->pnlGame->Controls->Add(this->lblDealer);
			this->pnlGame->Location = System::Drawing::Point(12, 12);
			this->pnlGame->Name = L"pnlGame";
			this->pnlGame->Size = System::Drawing::Size(920, 530);
			this->pnlGame->TabIndex = 2;
			// 
			// lblResult
			// 
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblResult->Location = System::Drawing::Point(0, 164);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(920, 202);
			this->lblResult->TabIndex = 2;
			this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblUser
			// 
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblUser->Location = System::Drawing::Point(820, 505);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(100, 25);
			this->lblUser->TabIndex = 1;
			this->lblUser->Text = L"User: ";
			// 
			// lblDealer
			// 
			this->lblDealer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblDealer->Location = System::Drawing::Point(802, 0);
			this->lblDealer->Name = L"lblDealer";
			this->lblDealer->Size = System::Drawing::Size(118, 25);
			this->lblDealer->TabIndex = 0;
			this->lblDealer->Text = L"Dealer: ";
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
			this->btnStart->Click += gcnew System::EventHandler(this, &BlackJack::btnStart_Click);
			// 
			// lblBalance
			// 
			this->lblBalance->BackColor = System::Drawing::Color::Transparent;
			this->lblBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblBalance->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblBalance->Location = System::Drawing::Point(728, 563);
			this->lblBalance->Name = L"lblBalance";
			this->lblBalance->Size = System::Drawing::Size(164, 55);
			this->lblBalance->TabIndex = 4;
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
			this->comboBox->Location = System::Drawing::Point(27, 624);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(110, 21);
			this->comboBox->TabIndex = 1;
			this->comboBox->Text = L"0";
			// 
			// BlackJack
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->lblBalance);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->pnlGame);
			this->Controls->Add(this->btnStay);
			this->Controls->Add(this->btnHit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"BlackJack";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"BlackJack";
			this->Load += gcnew System::EventHandler(this, &BlackJack::BlackJack_Load);
			this->pnlGame->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		
#pragma endregion
	private: System::Void BlackJack_Load(System::Object^ sender, System::EventArgs^ e) {
		btnHit->Visible = false;
		btnStay->Visible = false;
		lblDealer->Visible = false;
		lblUser->Visible = false;
		lblBalance->Visible = true;

	}

	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) { //Resets the game window. Checks for the parameters such as credit. If everything is good. Starts the game by calling initializegame function.
		resetGame();
		if (canBet()) {
			pnlGame->Controls->Clear();
			btnStart->Enabled = false;
			comboBox->Visible = false;

			btnHit->Visible = true;
			btnStay->Visible = true;
			lblDealer->Visible = true;
			lblUser->Visible = true;
			btnHit->Enabled = true;
			btnStay->Enabled = true;
			User::credit -= Convert::ToInt32(comboBox->SelectedItem);
			printCredit();
			initializeGame();
			loadDealerCardImages();
			loadUserCardImages();
			if (reduceUserAce() == 21) {
				endGame();
			}

		}
		else {
			lblResult->Text = "Not Enough!";
			lblResult->Show();
		}
	}
	private: System::Void btnHit_Click(System::Object^ sender, System::EventArgs^ e) { //Deals a card for the user. Then checks if user's hand is blackjack.
		if (reduceUserAce() < 21) {
			dealCard(userHand);
			loadUserCardImages();
		}
		if (reduceUserAce() == 21) {
			User::credit += Convert::ToInt32(comboBox->SelectedItem) * 2.5;
			printCredit();
			endGame();
		}
		else if (reduceUserAce() > 21) {

			endGame();
		}
	}
	private: System::Void btnStay_Click(System::Object^ sender, System::EventArgs^ e) { //If user decides to stay, dealer hidden card faces up. Then, deals card for the dealer until dealers hand sum >=16.
		btnHit->Enabled = false;
		btnStay->Enabled = false;
		faceUpDealerHand();

		while (reduceDealerAce() < 17) {
			dealCard(dealerHand);
			loadDealerCardImages();
			pnlGame->Refresh();
		}

		endGame();

	}



	};
}