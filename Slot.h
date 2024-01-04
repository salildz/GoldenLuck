#pragma once
#include <iostream>
#include "User.h"


namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Slot
	/// </summary>
	public ref class Slot : public System::Windows::Forms::Form
	{
	public:
		Slot(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void playSlot();
		System::Void Slot_Load(System::Object^ sender, System::EventArgs^ e);
		bool checkRoll(int Roll1, int Roll2, int Roll3);
		System::Void btnRoll_Click(System::Object^ sender, System::EventArgs^ e);
		void SlotRoll(int& Roll, PictureBox^ Slot);
		bool canBet();
		void SlotAnimation(int& a, PictureBox^ Slot);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Slot()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnRoll;
	private: System::Windows::Forms::PictureBox^ Slot1;
	private: System::Windows::Forms::PictureBox^ Slot2;
	private: System::Windows::Forms::PictureBox^ Slot3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;

	private: System::Windows::Forms::Label^ announcer;
	private: System::Windows::Forms::ComboBox^ comboBox;
	private: System::Windows::Forms::Label^ labelBalance;







	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Slot::typeid));
			   this->Slot1 = (gcnew System::Windows::Forms::PictureBox());
			   this->btnRoll = (gcnew System::Windows::Forms::Button());
			   this->Slot2 = (gcnew System::Windows::Forms::PictureBox());
			   this->Slot3 = (gcnew System::Windows::Forms::PictureBox());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->announcer = (gcnew System::Windows::Forms::Label());
			   this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			   this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->labelBalance = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot3))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // Slot1
			   // 
			   this->Slot1->BackColor = System::Drawing::Color::Transparent;
			   this->Slot1->Location = System::Drawing::Point(272, 305);
			   this->Slot1->Name = L"Slot1";
			   this->Slot1->Size = System::Drawing::Size(123, 183);
			   this->Slot1->TabIndex = 3;
			   this->Slot1->TabStop = false;
			   // 
			   // btnRoll
			   // 
			   this->btnRoll->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->btnRoll->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->btnRoll->Location = System::Drawing::Point(286, 543);
			   this->btnRoll->Name = L"btnRoll";
			   this->btnRoll->Size = System::Drawing::Size(417, 52);
			   this->btnRoll->TabIndex = 7;
			   this->btnRoll->Text = L"ROLL";
			   this->btnRoll->UseVisualStyleBackColor = false;
			   this->btnRoll->Click += gcnew System::EventHandler(this, &Slot::btnRoll_Click);
			   // 
			   // Slot2
			   // 
			   this->Slot2->BackColor = System::Drawing::Color::Transparent;
			   this->Slot2->Location = System::Drawing::Point(451, 305);
			   this->Slot2->Name = L"Slot2";
			   this->Slot2->Size = System::Drawing::Size(129, 183);
			   this->Slot2->TabIndex = 8;
			   this->Slot2->TabStop = false;
			   // 
			   // Slot3
			   // 
			   this->Slot3->BackColor = System::Drawing::Color::Transparent;
			   this->Slot3->Location = System::Drawing::Point(632, 305);
			   this->Slot3->Name = L"Slot3";
			   this->Slot3->Size = System::Drawing::Size(125, 183);
			   this->Slot3->TabIndex = 9;
			   this->Slot3->TabStop = false;
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->Controls->Add(this->labelBalance);
			   this->panel1->Controls->Add(this->comboBox);
			   this->panel1->Controls->Add(this->announcer);
			   this->panel1->Controls->Add(this->Slot2);
			   this->panel1->Controls->Add(this->Slot1);
			   this->panel1->Controls->Add(this->btnRoll);
			   this->panel1->Controls->Add(this->Slot3);
			   this->panel1->Location = System::Drawing::Point(0, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(992, 617);
			   this->panel1->TabIndex = 10;
			   // 
			   // announcer
			   // 
			   this->announcer->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->announcer->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->announcer->ForeColor = System::Drawing::Color::Black;
			   this->announcer->Location = System::Drawing::Point(22, 9);
			   this->announcer->Name = L"announcer";
			   this->announcer->Size = System::Drawing::Size(970, 42);
			   this->announcer->TabIndex = 12;
			   this->announcer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // contextMenuStrip1
			   // 
			   this->contextMenuStrip1->Name = L"contextMenuStrip1";
			   this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
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
			   this->comboBox->Location = System::Drawing::Point(30, 30);
			   this->comboBox->Name = L"comboBox";
			   this->comboBox->Size = System::Drawing::Size(110, 21);
			   this->comboBox->TabIndex = 1;
			   this->comboBox->Text = L"0";
			   // 
			   // labelBalance
			   // 
			   this->labelBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->labelBalance->Location = System::Drawing::Point(765, 9);
			   this->labelBalance->Name = L"labelBalance";
			   this->labelBalance->Size = System::Drawing::Size(180, 56);
			   this->labelBalance->TabIndex = 14;
			   this->labelBalance->Text = "Credit: " + User::credit.ToString();

			   // 
			   // Slot
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::White;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(991, 607);
			   this->Controls->Add(this->panel1);
			   this->Name = L"Slot";
			   this->Text = L"Slot";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot3))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }

		   void loadImages(int a, PictureBox^ pictureBox) {														//to load the images of Slot
			   pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
			   pictureBox->Load("SlotPhoto\\" + a + ".png");
			   pictureBox->Refresh();
		   }
		 
		   
	};



	};


}