#pragma once
#include "LogInPage.h"
#include "SignUpPage.h"

namespace ppp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SignUpButton;
	protected:

	private: System::Windows::Forms::Button^ LogInButton;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SignUpButton = (gcnew System::Windows::Forms::Button());
			this->LogInButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SignUpButton
			// 
			this->SignUpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SignUpButton->Location = System::Drawing::Point(80, 68);
			this->SignUpButton->Name = L"SignUpButton";
			this->SignUpButton->Size = System::Drawing::Size(162, 34);
			this->SignUpButton->TabIndex = 0;
			this->SignUpButton->Text = L"Sign Up";
			this->SignUpButton->UseVisualStyleBackColor = true;
			this->SignUpButton->Click += gcnew System::EventHandler(this, &MyForm::SignUpButton_Click_1);
			// 
			// LogInButton
			// 
			this->LogInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogInButton->Location = System::Drawing::Point(80, 125);
			this->LogInButton->Name = L"LogInButton";
			this->LogInButton->Size = System::Drawing::Size(162, 35);
			this->LogInButton->TabIndex = 1;
			this->LogInButton->Text = L"Log In";
			this->LogInButton->UseVisualStyleBackColor = true;
			this->LogInButton->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(21, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Student Management System";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 197);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LogInButton);
			this->Controls->Add(this->SignUpButton);
			this->MaximumSize = System::Drawing::Size(339, 236);
			this->MinimumSize = System::Drawing::Size(339, 236);
			this->Name = L"MyForm";
			this->Text = L"Welcome ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::SignUpButton_Click);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		LogInPage lg;
		lg.ShowDialog();
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SignUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void SignUpButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
	SignUpPage sgp;
	sgp.ShowDialog();
}
};
}
