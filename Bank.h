#pragma once

namespace GoldenLuck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Bank
	/// </summary>
	public ref class Bank : public System::Windows::Forms::Form
	{
	public:
		int credit = 0;
		Bank(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->lblBalance->Text = "Credit: " + credit;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Bank()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblBalance;
	private: System::Windows::Forms::ComboBox^ cmbbxBalance;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Label^ lblError;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Bank::typeid));
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->cmbbxBalance = (gcnew System::Windows::Forms::ComboBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblBalance
			// 
			this->lblBalance->AutoSize = true;
			this->lblBalance->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblBalance->ForeColor = System::Drawing::Color::Black;
			this->lblBalance->Location = System::Drawing::Point(199, 9);
			this->lblBalance->MaximumSize = System::Drawing::Size(133, 25);
			this->lblBalance->Name = L"lblBalance";
			this->lblBalance->Size = System::Drawing::Size(80, 25);
			this->lblBalance->TabIndex = 0;
			this->lblBalance->Text = L"Credit: ";
			// 
			// cmbbxBalance
			// 
			this->cmbbxBalance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->cmbbxBalance->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->cmbbxBalance->FormattingEnabled = true;
			this->cmbbxBalance->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"100", L"500", L"1000", L"2000", L"3000", L"4000",
					L"5000"
			});
			this->cmbbxBalance->Location = System::Drawing::Point(12, 108);
			this->cmbbxBalance->Name = L"cmbbxBalance";
			this->cmbbxBalance->Size = System::Drawing::Size(145, 21);
			this->cmbbxBalance->TabIndex = 1;
			this->cmbbxBalance->Text = L"0";
			// 
			// btnAdd
			// 
			this->btnAdd->AutoSize = true;
			this->btnAdd->BackColor = System::Drawing::Color::Transparent;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnAdd->ForeColor = System::Drawing::Color::Black;
			this->btnAdd->Location = System::Drawing::Point(191, 108);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 35);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Bank::btnAdd_Click);
			// 
			// lblError
			// 
			this->lblError->AutoSize = true;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblError->ForeColor = System::Drawing::Color::Black;
			this->lblError->Location = System::Drawing::Point(22, 197);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(300, 25);
			this->lblError->TabIndex = 3;
			this->lblError->Text = L"CREDIT CANNOT EXCEED 10000";

			// 
			// Bank
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(344, 231);

			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->cmbbxBalance);
			this->Controls->Add(this->lblBalance);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::Red;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Bank";
			this->Text = L"Bank";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (credit > 10000) {
			this->Controls->Add(this->lblError);
			btnAdd->Enabled = false;
		}
		else {
			String^ selectedValue = cmbbxBalance->SelectedItem->ToString();
			int selectedAmount = Int32::Parse(selectedValue);
			if ((credit + selectedAmount) > 10000) {
				this->Controls->Add(this->lblError);
				btnAdd->Enabled = false;
			}
			else {
				credit += selectedAmount;
				lblBalance->Text = "Credit: " + credit.ToString();
			}

		}

	}
	};
}
