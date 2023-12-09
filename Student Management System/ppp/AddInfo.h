#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <msclr/marshal_cppstd.h>
using namespace std;
struct Student
{
	int id = 0;
	string fname;
	string lname;
	string CGPA;
	string degree;
	string rollNo;
	string cnic;
};
namespace ppp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for AddInfo
	/// </summary>
	public ref class AddInfo : public System::Windows::Forms::Form
	{
	public:
		bool isRollNumberPresent(string str) {
			std::ifstream file("StudentInfo.txt");
			std::string line;

			while (std::getline(file, line)) {
				std::istringstream iss(line);
				std::string token;
				while (iss >> token) {
					if (token == str) {
						return false;
					}
				}
			}

			return true;
		}
		bool isValid(string roll, string cgpa, string dp, string cnic) {
			double marks;
			int a = 1;
			for (int i = 0; roll[i] != '\0' && a != 2; i++) {
				if (((roll[i] >= '0' && roll[i] <= '9') || roll[i] == 'L' || roll[3] == '-' )&& roll[i] != 'l')
					a = 1;
				else
					a = 2;
			}
			if (a == 2)
				return false;
			for (int i = 0; cgpa[i] != '\0' && a != 2; i++) {
				marks = stod(cgpa);
				if (marks >= 0.0 && marks <= 4.0)
					a = 3;
				else
					a = 2;
			}
			if (a == 2)
				return false;
			for (int i = 0; dp[i] != '\0' && a != 2; i++) {
				if (dp == "CS" || dp == "SE" || dp == "IT" || dp == "DS" || dp == "cs" || dp == "se" || dp == "it" || dp == "ds")
					a = 4;
				else
					a = 2;
			}
			if (a == 2)
				return false;
			for (int i = 0; cnic[i] != '\0' && a != 2; i++) {
				if ((cnic[i] >= '0' && cnic[i] <= '9') || cnic[5] == '-' || cnic[13] == '-')
					a = 5;
				else
					a = 2;
			}
			if (a == 2)
				return false;
			return true;
		}
		bool isEmpty(String^ str) {
			if (str->Length == 0)
				return false;
			else
				return true;
		}
		AddInfo(void)
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
		~AddInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ lnameTb;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ fnameTb;








	private: System::Windows::Forms::TextBox^ rollNoTb;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ addbtn;

	private: System::Windows::Forms::TextBox^ dpartmentTb;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ cancelbtn;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ cgpaTb;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ cnicTb;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label11;







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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lnameTb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->fnameTb = (gcnew System::Windows::Forms::TextBox());
			this->rollNoTb = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->addbtn = (gcnew System::Windows::Forms::Button());
			this->dpartmentTb = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cancelbtn = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cgpaTb = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->cnicTb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(191, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(239, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student Information";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(15, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"First Name";
			// 
			// lnameTb
			// 
			this->lnameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lnameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lnameTb->Location = System::Drawing::Point(353, 85);
			this->lnameTb->MaxLength = 30;
			this->lnameTb->Multiline = true;
			this->lnameTb->Name = L"lnameTb";
			this->lnameTb->Size = System::Drawing::Size(285, 26);
			this->lnameTb->TabIndex = 4;
			this->lnameTb->TextChanged += gcnew System::EventHandler(this, &AddInfo::lnameTb_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(353, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Last Name";
			// 
			// fnameTb
			// 
			this->fnameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fnameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fnameTb->Location = System::Drawing::Point(18, 85);
			this->fnameTb->MaxLength = 30;
			this->fnameTb->Multiline = true;
			this->fnameTb->Name = L"fnameTb";
			this->fnameTb->Size = System::Drawing::Size(285, 26);
			this->fnameTb->TabIndex = 5;
			this->fnameTb->TextChanged += gcnew System::EventHandler(this, &AddInfo::fnameTb_TextChanged);
			// 
			// rollNoTb
			// 
			this->rollNoTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollNoTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rollNoTb->Location = System::Drawing::Point(18, 162);
			this->rollNoTb->MaxLength = 8;
			this->rollNoTb->Multiline = true;
			this->rollNoTb->Name = L"rollNoTb";
			this->rollNoTb->Size = System::Drawing::Size(285, 26);
			this->rollNoTb->TabIndex = 13;
			this->rollNoTb->TextChanged += gcnew System::EventHandler(this, &AddInfo::rollNoTb_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(18, 137);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 18);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Roll Number";
			// 
			// addbtn
			// 
			this->addbtn->BackColor = System::Drawing::Color::Green;
			this->addbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addbtn->ForeColor = System::Drawing::Color::White;
			this->addbtn->Location = System::Drawing::Point(22, 285);
			this->addbtn->Name = L"addbtn";
			this->addbtn->Size = System::Drawing::Size(282, 39);
			this->addbtn->TabIndex = 14;
			this->addbtn->Text = L"ADD";
			this->addbtn->UseVisualStyleBackColor = false;
			this->addbtn->Click += gcnew System::EventHandler(this, &AddInfo::addbtn_Click);
			// 
			// dpartmentTb
			// 
			this->dpartmentTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dpartmentTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dpartmentTb->Location = System::Drawing::Point(359, 236);
			this->dpartmentTb->MaxLength = 2;
			this->dpartmentTb->Multiline = true;
			this->dpartmentTb->Name = L"dpartmentTb";
			this->dpartmentTb->Size = System::Drawing::Size(279, 26);
			this->dpartmentTb->TabIndex = 16;
			this->dpartmentTb->TextChanged += gcnew System::EventHandler(this, &AddInfo::dpartmentTb_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(356, 208);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(95, 18);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Department";
			// 
			// cancelbtn
			// 
			this->cancelbtn->BackColor = System::Drawing::Color::IndianRed;
			this->cancelbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelbtn->ForeColor = System::Drawing::Color::White;
			this->cancelbtn->Location = System::Drawing::Point(336, 285);
			this->cancelbtn->Name = L"cancelbtn";
			this->cancelbtn->Size = System::Drawing::Size(282, 39);
			this->cancelbtn->TabIndex = 17;
			this->cancelbtn->Text = L"CANCEL";
			this->cancelbtn->UseVisualStyleBackColor = false;
			this->cancelbtn->Click += gcnew System::EventHandler(this, &AddInfo::cancelbtn_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(454, 211);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(150, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"(Departments: CS, SE, IT, DS)";
			// 
			// cgpaTb
			// 
			this->cgpaTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cgpaTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cgpaTb->Location = System::Drawing::Point(356, 162);
			this->cgpaTb->MaxLength = 4;
			this->cgpaTb->Multiline = true;
			this->cgpaTb->Name = L"cgpaTb";
			this->cgpaTb->Size = System::Drawing::Size(282, 26);
			this->cgpaTb->TabIndex = 20;
			this->cgpaTb->TextChanged += gcnew System::EventHandler(this, &AddInfo::cgpaTb_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(356, 137);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 18);
			this->label10->TabIndex = 19;
			this->label10->Text = L"CGPA";
			// 
			// cnicTb
			// 
			this->cnicTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cnicTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cnicTb->Location = System::Drawing::Point(21, 236);
			this->cnicTb->MaxLength = 15;
			this->cnicTb->Multiline = true;
			this->cnicTb->Name = L"cnicTb";
			this->cnicTb->Size = System::Drawing::Size(285, 26);
			this->cnicTb->TabIndex = 22;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(21, 208);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 18);
			this->label4->TabIndex = 21;
			this->label4->Text = L"CNIC";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(126, 141);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"(Format: 12L-3456)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(75, 211);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(135, 13);
			this->label6->TabIndex = 24;
			this->label6->Text = L"(Format: 12345-1234567-1)";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(425, 142);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(90, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"(Range: 0.0 - 4.0)";
			// 
			// AddInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 346);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->cnicTb);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cgpaTb);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->cancelbtn);
			this->Controls->Add(this->dpartmentTb);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->addbtn);
			this->Controls->Add(this->rollNoTb);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->fnameTb);
			this->Controls->Add(this->lnameTb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(667, 385);
			this->MinimumSize = System::Drawing::Size(667, 385);
			this->Name = L"AddInfo";
			this->Text = L"Student Information";
			this->Load += gcnew System::EventHandler(this, &AddInfo::AddInfo_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void department_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void AddInfo_Load(System::Object^ sender, System::EventArgs^ e) {
	
	if (isEmpty(fnameTb->Text) || isEmpty(lnameTb->Text) || isEmpty(rollNoTb->Text) || isEmpty(dpartmentTb->Text) || isEmpty(cnicTb->Text))
		addbtn->Enabled = false;
	else
		addbtn->Enabled = true;
}
private: System::Void dpartmentTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void fnameTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	string name = msclr::interop::marshal_as<string>(fnameTb->Text);
	for (int i = 0; name[i] != '\0'; i++) {
		if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')) {
			fnameTb->BackColor = System::Drawing::SystemColors::Window;
			addbtn->Enabled = true;
		}
		else {
			fnameTb->BackColor = System::Drawing::Color::LightCoral;
			addbtn->Enabled = false;
		}
			
	}
}
private: System::Void addbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (fnameTb->Text != "" && lnameTb->Text != "" && rollNoTb->Text != "" && cgpaTb->Text != "" && dpartmentTb->Text != "" && cnicTb->Text != "") {
		fstream write("StudentInfo.txt", ios::app);
		Student std;
		std.rollNo = msclr::interop::marshal_as<string>(rollNoTb->Text);
		if (isRollNumberPresent(std.rollNo)) {
			std.fname = msclr::interop::marshal_as<string>(fnameTb->Text);
			std.lname = msclr::interop::marshal_as<string>(lnameTb->Text);
			std.degree = msclr::interop::marshal_as<string>(dpartmentTb->Text);
			std.CGPA = msclr::interop::marshal_as<string>(cgpaTb->Text);

			std.cnic = msclr::interop::marshal_as<string>(cnicTb->Text);
			if (isValid(std.rollNo, std.CGPA, std.degree, std.cnic)) {
				write << "( ";
				write << std.rollNo << " ";
				write << std.fname << " ";
				write << std.lname << " ";
				write << std.degree << " ";
				write << std.CGPA << " ";
				write << std.cnic << " ) " << endl;
				write.close();
				fstream write1("Student ID.txt");
				write1 << std.id;
				write1.close();
			}
			else {
				MessageBox::Show(" Enter Information in Correct Format / Given Range", "Incorrect Data", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				fnameTb->Clear();
				lnameTb->Clear();
				cgpaTb->Clear();
				cnicTb->Clear();
				rollNoTb->Clear();
				dpartmentTb->Clear();
			}
		}
		else {
			MessageBox::Show("Roll Number Already Exist", "Duplicate Roll No.", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			rollNoTb->Clear();
		}
	}
	else {
		MessageBox::Show("Please Enter Complete Record", "Incomplete Data", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}
private: System::Void lnameTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	string name = msclr::interop::marshal_as<string>(lnameTb->Text);
	for (int i = 0; name[i] != '\0'; i++) {
		if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')) {
			lnameTb->BackColor = System::Drawing::SystemColors::Window;
			addbtn->Enabled = true;
		}
		else {
			lnameTb->BackColor = System::Drawing::Color::LightCoral;
			addbtn->Enabled = false;
		}
	}
}
private: System::Void cancelbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void rollNoTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void cgpaTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}
