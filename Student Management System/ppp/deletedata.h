#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
	/// Summary for deletedata
	/// </summary>
	public ref class deletedata : public System::Windows::Forms::Form
	{
	public:
		deletedata(void)
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
		~deletedata()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ rollNoTb;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
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
			this->rollNoTb = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(29, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Roll No(e.g 12L-3450)";
			// 
			// rollNoTb
			// 
			this->rollNoTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollNoTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rollNoTb->Location = System::Drawing::Point(29, 99);
			this->rollNoTb->Name = L"rollNoTb";
			this->rollNoTb->Size = System::Drawing::Size(204, 22);
			this->rollNoTb->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(75, 139);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Remove";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &deletedata::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(24, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(224, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Delete Student Data";
			// 
			// deletedata
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 192);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->rollNoTb);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(300, 231);
			this->MinimumSize = System::Drawing::Size(300, 231);
			this->Name = L"deletedata";
			this->Text = L"Remove Data";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		ifstream read("StudentInfo.txt");
		ofstream write("temp.txt");

		if (!read || !write) {
			MessageBox::Show("File Not Found", "File Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}

		string line;
		bool recordFound = false;
		String^ rollNumber = rollNoTb->Text;
		while (getline(read, line)) {
			size_t pos = line.find(msclr::interop::marshal_as<string>(rollNumber));
			if (pos == string::npos) {
				write << line << std::endl;
			}
			else {
				recordFound = true;
			}
		}

		read.close();
		write.close();

		if (recordFound) {
			remove("StudentInfo.txt");
			rename("temp.txt", "StudentInfo.txt");

			MessageBox::Show("Data Successfully Deleted", "Data Removed", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else {
			MessageBox::Show("Data not found", "Data Missing", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			remove("temp.txt"); 
		}
	}
	};
}
