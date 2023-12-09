#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace std;
//struct Student
//{
//	int id = 0;
//	string fname;
//	string lname;
//	string CGPA;
//	string degree;
//	string rollNo;
//};
namespace ppp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for display
	/// </summary>
	public ref class display : public System::Windows::Forms::Form
	{
	public:
		display(void)
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
		~display()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ closeBtn;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Green;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(13, 295);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"DISPLAY DATA";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &display::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(12, 57);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(410, 225);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &display::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(112, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"STUDENT RECORDS";
			// 
			// closeBtn
			// 
			this->closeBtn->BackColor = System::Drawing::Color::IndianRed;
			this->closeBtn->ForeColor = System::Drawing::Color::White;
			this->closeBtn->Location = System::Drawing::Point(323, 295);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(99, 33);
			this->closeBtn->TabIndex = 4;
			this->closeBtn->Text = L"CLOSE";
			this->closeBtn->UseVisualStyleBackColor = false;
			this->closeBtn->Click += gcnew System::EventHandler(this, &display::closeBtn_Click);
			// 
			// display
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(435, 335);
			this->Controls->Add(this->closeBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->MaximumSize = System::Drawing::Size(451, 374);
			this->MinimumSize = System::Drawing::Size(451, 374);
			this->Name = L"display";
			this->Text = L"Display Students Information";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ifstream read("StudentInfo.txt");
		/*Student std;*/
		string line;
		string info;
		String^ data;
		int i = 0, k = 1;
		while (getline(read, line)) {
			/*read >> std.rollNo;
			read >> std.fname;
			read >> std.lname;
			read >> std.degree;
			read >> std.CGPA;
			info = std.rollNo + " " + std.fname + " " + std.lname + " " + std.degree + " " + std.CGPA;*/
				data += msclr::interop::marshal_as<String^>(line) + "\n";
				
		}
		textBox1->Text = data;
		
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}
