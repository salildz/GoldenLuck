#pragma once
#include "Deck.h"
#include <vector>

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
	public ref class BlackJack : public System::Windows::Forms::Form
	{
	public:
		BlackJack(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void startGame(); // Function to start the game
		void dealInitialCards(); // Function to deal initial cards to player and dealer
		void playerTurn(); // Function to control the player's turn
		void dealerTurn(); // Function to control the dealer's turn
		void displayHands(bool showAll); // Function to display player and dealer hands
		void determineWinner(); // Function to determine the winner of the game
	
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
		Deck^ deck;
		System::Collections::Generic::List<Card^>^ playerHand;
		System::Collections::Generic::List<Card^>^ dealerHand;
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
			this->SuspendLayout();
			// 
			// BlackJack
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->ClientSize = System::Drawing::Size(944, 681);
			this->Name = L"BlackJack";
			this->Text = L"BlackJack";
			this->Load += gcnew System::EventHandler(this, &BlackJack::BlackJack_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BlackJack_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
