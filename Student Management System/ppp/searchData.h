#pragma once
#include<iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
using namespace std;

namespace ppp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for searchData
	/// </summary>
	public ref class searchData : public System::Windows::Forms::Form
	{
	public:
		searchData(void)
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
		~searchData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ SearchBtn;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label13;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SearchBtn = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(95, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Roll Number";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(37, 79);
			this->textBox1->MaxLength = 8;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 23);
			this->textBox1->TabIndex = 1;
			// 
			// SearchBtn
			// 
			this->SearchBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchBtn->Location = System::Drawing::Point(204, 75);
			this->SearchBtn->Name = L"SearchBtn";
			this->SearchBtn->Size = System::Drawing::Size(94, 29);
			this->SearchBtn->TabIndex = 2;
			this->SearchBtn->Text = L"Search";
			this->SearchBtn->UseVisualStyleBackColor = true;
			this->SearchBtn->Click += gcnew System::EventHandler(this, &searchData::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(12, 187);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(333, 26);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Required Information";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(34, 105);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(96, 13);
			this->label13->TabIndex = 39;
			this->label13->Text = L"(Format: 12L-3456)";
			// 
			// searchData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(357, 237);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->SearchBtn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(373, 276);
			this->MinimumSize = System::Drawing::Size(373, 276);
			this->Name = L"searchData";
			this->Text = L"Find Student Data";
			this->Load += gcnew System::EventHandler(this, &searchData::searchData_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		fstream read("StudentInfo.txt");
		string line;
		bool found = false;
		string rollNumber = msclr::interop::marshal_as<string>(textBox1->Text);

		while (getline(read, line)) {
			size_t pos = line.find(rollNumber);
			if (pos != string::npos) {
				textBox2->Text = msclr::interop::marshal_as<String^>(line);
				found = true;
				break;
			}
		}

		read.close();

		if (!found) {
			textBox2->Text = "";
			MessageBox::Show("Record not found", "Missing Data", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
	private: System::Void searchData_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
