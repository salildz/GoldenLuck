#pragma once
#include <iostream>

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
		void Slot::playSlot();

		bool Slot::checkRoll(int Roll1, int Roll2, int Roll3);

		void Slot::SlotRoll(int Roll, PictureBox^ Slot);

		void Slot::SlotAnimation(int a, PictureBox^ Slot);

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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Slot1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnRoll = (gcnew System::Windows::Forms::Button());
			this->Slot2 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot3))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Slot1
			// 
			this->Slot1->BackColor = System::Drawing::Color::Black;
			this->Slot1->Location = System::Drawing::Point(30, 52);
			this->Slot1->Name = L"Slot1";
			this->Slot1->Size = System::Drawing::Size(126, 159);
			this->Slot1->TabIndex = 3;
			this->Slot1->TabStop = false;
			// 
			// btnRoll
			// 
			this->btnRoll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRoll->Location = System::Drawing::Point(30, 251);
			this->btnRoll->Name = L"btnRoll";
			this->btnRoll->Size = System::Drawing::Size(408, 52);
			this->btnRoll->TabIndex = 7;
			this->btnRoll->Text = L"ROLL";
			this->btnRoll->UseVisualStyleBackColor = true;
			this->btnRoll->Click += gcnew System::EventHandler(this, &Slot::btnRoll_Click);
			// 
			// Slot2
			// 
			this->Slot2->BackColor = System::Drawing::Color::Black;
			this->Slot2->Location = System::Drawing::Point(171, 52);
			this->Slot2->Name = L"Slot2";
			this->Slot2->Size = System::Drawing::Size(126, 159);
			this->Slot2->TabIndex = 8;
			this->Slot2->TabStop = false;
			// 
			// Slot3
			// 
			this->Slot3->BackColor = System::Drawing::Color::Black;
			this->Slot3->Location = System::Drawing::Point(312, 52);
			this->Slot3->Name = L"Slot3";
			this->Slot3->Size = System::Drawing::Size(126, 159);
			this->Slot3->TabIndex = 9;
			this->Slot3->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnRoll);
			this->panel1->Controls->Add(this->Slot1);
			this->panel1->Controls->Add(this->Slot3);
			this->panel1->Controls->Add(this->Slot2);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(466, 306);
			this->panel1->TabIndex = 10;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, -33);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(487, 460);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// Slot
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(156)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->ClientSize = System::Drawing::Size(485, 427);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Slot";
			this->Text = L"Slot";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot3))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}

		void loadImages(int a, PictureBox^ pictureBox) {
			switch (a) {
			case 1:
				pictureBox->Load("1.png");
				break;
			case 2:
				pictureBox->Load("2.png");
				break;
			case 3:
				pictureBox->Load("3.png");
				break;
			case 4:
				pictureBox->Load("4.png");
				break;
			case 5:
				pictureBox->Load("5.png");
				break;
			default:
				break;
			}

		}

#pragma endregion

	private: System::Void Slot_Load(System::Object^ sender, System::EventArgs^ e) {
		btnRoll->Visible = true;
	}
	private: System::Void btnRoll_Click(System::Object^ sender, System::EventArgs^ e) {
		playSlot();
	}
	};
}
