#pragma once
#include <iostream>
#include <string>
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

	/// <summary>
	/// Summary for chnageData
	/// </summary>
	public ref class chnageData : public System::Windows::Forms::Form
	{
	public:
		/*bool ISvalid(string fname, string lname, string cnic, string cgpa, string dp) {
			bool flag = true;
			double marks;
			for (int i = 0; cnic[i] != '\0' && flag; i++) {
				if ((cnic[i] >= '0' && cnic[i] <= '9') || cnic[i] == '-')
					flag = true;
				else
					flag = false;
			}


			if (!flag)
				return false;
			for (int i = 0; dp[i] != '\0' && flag; i++) {
				if (dp == "CS" || dp == "SE" || dp == "IT" || dp == "DS" || dp == "cs" || dp == "se" || dp == "it" || dp == "ds")
					flag = true;
				else
					flag = false;
			}
			if (!flag)
				return false;
			for (int i = 0; cgpa[i] != '\0' && flag; i++) {
				marks = stod(cgpa);
				if (marks >= 0.0 && marks <= 4.0)
					flag = true;
				else
					flag = false;
			}
			if (!flag)
				return false;
			return true;
		}*/
		bool isValid(string fname, string lname, string cgpa, string dp, string cnic) {
			double marks;
			int a = 1;
			for (int i = 0; fname[i] != '\0' && a != 2; i++) {
				if ((fname[i] >= 'a' && fname[i] <= 'z') || (fname[i] >= 'A' && fname[i] <= 'Z')) {
					a = 1;
				}
				else {
					a = 2;
				}

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
			for (int i = 0; lname[i] != '\0' && a != 2; i++) {
				if ((lname[i] >= 'a' && lname[i] <= 'z') || (lname[i] >= 'A' && lname[i] <= 'Z')) {
					a = 6;
				}
				else {
					a = 2;
				}
			}
			if (a == 2)
				return false;
			return true;
		}
		chnageData(void)
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
		~chnageData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ updateBtn;
	private: System::Windows::Forms::TextBox^ fnameTb;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ lnameTb;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ rollNoTb;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ cgpaTb;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ cnicTb;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ dpartmentTb;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ cancelbtn;
	private: System::Windows::Forms::Button^ addbtn;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->updateBtn = (gcnew System::Windows::Forms::Button());
			this->fnameTb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lnameTb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rollNoTb = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->cgpaTb = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cnicTb = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dpartmentTb = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->cancelbtn = (gcnew System::Windows::Forms::Button());
			this->addbtn = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(188, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(303, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Update Student Data";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(191, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter Roll Number";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(189, 99);
			this->textBox1->MaxLength = 8;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(173, 27);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &chnageData::textBox1_TextChanged);
			// 
			// updateBtn
			// 
			this->updateBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateBtn->Location = System::Drawing::Point(382, 99);
			this->updateBtn->Name = L"updateBtn";
			this->updateBtn->Size = System::Drawing::Size(115, 27);
			this->updateBtn->TabIndex = 3;
			this->updateBtn->Text = L"Update";
			this->updateBtn->UseVisualStyleBackColor = true;
			this->updateBtn->Click += gcnew System::EventHandler(this, &chnageData::button1_Click);
			// 
			// fnameTb
			// 
			this->fnameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fnameTb->Enabled = false;
			this->fnameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fnameTb->Location = System::Drawing::Point(15, 259);
			this->fnameTb->MaxLength = 30;
			this->fnameTb->Multiline = true;
			this->fnameTb->Name = L"fnameTb";
			this->fnameTb->Size = System::Drawing::Size(285, 26);
			this->fnameTb->TabIndex = 7;
			this->fnameTb->TextChanged += gcnew System::EventHandler(this, &chnageData::fnameTb_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 234);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 18);
			this->label3->TabIndex = 6;
			this->label3->Text = L"First Name";
			// 
			// lnameTb
			// 
			this->lnameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lnameTb->Enabled = false;
			this->lnameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lnameTb->Location = System::Drawing::Point(346, 259);
			this->lnameTb->MaxLength = 30;
			this->lnameTb->Multiline = true;
			this->lnameTb->Name = L"lnameTb";
			this->lnameTb->Size = System::Drawing::Size(293, 26);
			this->lnameTb->TabIndex = 9;
			this->lnameTb->TextChanged += gcnew System::EventHandler(this, &chnageData::lnameTb_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(346, 234);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Last Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(123, 318);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 26;
			this->label5->Text = L"(Format: 12L-3456)";
			// 
			// rollNoTb
			// 
			this->rollNoTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rollNoTb->Enabled = false;
			this->rollNoTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rollNoTb->Location = System::Drawing::Point(15, 340);
			this->rollNoTb->MaxLength = 8;
			this->rollNoTb->Multiline = true;
			this->rollNoTb->Name = L"rollNoTb";
			this->rollNoTb->Size = System::Drawing::Size(285, 26);
			this->rollNoTb->TabIndex = 25;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(15, 315);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 18);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Roll Number";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(408, 318);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(90, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"(Range: 0.0 - 4.0)";
			// 
			// cgpaTb
			// 
			this->cgpaTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cgpaTb->Enabled = false;
			this->cgpaTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cgpaTb->Location = System::Drawing::Point(346, 340);
			this->cgpaTb->MaxLength = 4;
			this->cgpaTb->Multiline = true;
			this->cgpaTb->Name = L"cgpaTb";
			this->cgpaTb->Size = System::Drawing::Size(293, 26);
			this->cgpaTb->TabIndex = 28;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(346, 315);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 18);
			this->label10->TabIndex = 27;
			this->label10->Text = L"CGPA";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(69, 394);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(135, 13);
			this->label6->TabIndex = 32;
			this->label6->Text = L"(Format: 12345 1234567 1)";
			// 
			// cnicTb
			// 
			this->cnicTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cnicTb->Enabled = false;
			this->cnicTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cnicTb->Location = System::Drawing::Point(15, 419);
			this->cnicTb->MaxLength = 15;
			this->cnicTb->Multiline = true;
			this->cnicTb->Name = L"cnicTb";
			this->cnicTb->Size = System::Drawing::Size(285, 26);
			this->cnicTb->TabIndex = 31;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(15, 391);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 18);
			this->label8->TabIndex = 30;
			this->label8->Text = L"CNIC";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(447, 394);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(150, 13);
			this->label9->TabIndex = 35;
			this->label9->Text = L"(Departments: CS, SE, IT, DS)";
			// 
			// dpartmentTb
			// 
			this->dpartmentTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dpartmentTb->Enabled = false;
			this->dpartmentTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dpartmentTb->Location = System::Drawing::Point(346, 419);
			this->dpartmentTb->MaxLength = 2;
			this->dpartmentTb->Multiline = true;
			this->dpartmentTb->Name = L"dpartmentTb";
			this->dpartmentTb->Size = System::Drawing::Size(293, 26);
			this->dpartmentTb->TabIndex = 34;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(346, 391);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(95, 18);
			this->label12->TabIndex = 33;
			this->label12->Text = L"Department";
			// 
			// cancelbtn
			// 
			this->cancelbtn->BackColor = System::Drawing::Color::IndianRed;
			this->cancelbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelbtn->ForeColor = System::Drawing::Color::White;
			this->cancelbtn->Location = System::Drawing::Point(341, 475);
			this->cancelbtn->Name = L"cancelbtn";
			this->cancelbtn->Size = System::Drawing::Size(282, 38);
			this->cancelbtn->TabIndex = 37;
			this->cancelbtn->Text = L"CANCEL";
			this->cancelbtn->UseVisualStyleBackColor = false;
			this->cancelbtn->Click += gcnew System::EventHandler(this, &chnageData::cancelbtn_Click);
			// 
			// addbtn
			// 
			this->addbtn->BackColor = System::Drawing::Color::Green;
			this->addbtn->Enabled = false;
			this->addbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addbtn->ForeColor = System::Drawing::Color::White;
			this->addbtn->Location = System::Drawing::Point(27, 475);
			this->addbtn->Name = L"addbtn";
			this->addbtn->Size = System::Drawing::Size(282, 38);
			this->addbtn->TabIndex = 36;
			this->addbtn->Text = L"ADD";
			this->addbtn->UseVisualStyleBackColor = false;
			this->addbtn->Click += gcnew System::EventHandler(this, &chnageData::addbtn_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(188, 133);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(96, 13);
			this->label13->TabIndex = 38;
			this->label13->Text = L"(Format: 12L-3456)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(221, 187);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(237, 24);
			this->label14->TabIndex = 39;
			this->label14->Text = L"Update Previous Record";
			// 
			// chnageData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 536);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->cancelbtn);
			this->Controls->Add(this->addbtn);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->dpartmentTb);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->cnicTb);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->cgpaTb);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->rollNoTb);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->lnameTb);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->fnameTb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->updateBtn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"chnageData";
			this->Text = L"Data Updation";
			this->Load += gcnew System::EventHandler(this, &chnageData::chnageData_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string str = msclr::interop::marshal_as<string>(textBox1->Text);
			ifstream read("StudentInfo.txt");

			string line;
			bool recordFound = false;
			string rollNumber = msclr::interop::marshal_as<string>(textBox1->Text); // Replace with your rollNumber input

			while (getline(read, line)) {
				size_t pos = line.find(rollNumber);
				if (pos != string::npos) {
					recordFound = true;
					textBox1->Enabled = false;
					updateBtn->Enabled = false;
					rollNoTb->Text = textBox1->Text;
					fnameTb->Enabled = true;
					lnameTb->Enabled = true;
					cgpaTb->Enabled = true;
					dpartmentTb->Enabled = true;
					cnicTb->Enabled = true;
					addbtn->Enabled = true;
					break;
				}

				else {
					fnameTb->Enabled = false;
					lnameTb->Enabled = false;
					cgpaTb->Enabled = false;
					dpartmentTb->Enabled = false;
					cnicTb->Enabled = false;
				}
			}

			read.close();

			if (!recordFound) {
				MessageBox::Show("Data not found", "Data Finding Error",MessageBoxButtons::OK ,MessageBoxIcon::Error);
			}
	}
private: System::Void addbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	ifstream read("StudentInfo.txt");
	ofstream write("temp.txt");
	string line;
	bool recordFound;
	String^ rollNumber = rollNoTb->Text;
	string fname = msclr::interop::marshal_as<string>(fnameTb->Text);
	string lname = msclr::interop::marshal_as<string>(lnameTb->Text);
	string dp = msclr::interop::marshal_as<string>(dpartmentTb->Text);
	string cgpa = msclr::interop::marshal_as<string>(cgpaTb->Text);
	string cnic = msclr::interop::marshal_as<string>(cnicTb->Text);
	if (fnameTb->Text != "" || lnameTb->Text != "" || cnicTb->Text != "" || cgpaTb->Text != "" || dpartmentTb->Text != "") {
		if (isValid(fname, lname, cgpa, dp, cnic)) {
			while (getline(read, line)) {
				size_t pos = line.find(msclr::interop::marshal_as<string>(rollNumber));
				if (pos != string::npos) {
					recordFound = true;
					write << "( " << msclr::interop::marshal_as<string>(rollNumber) << " ";
					write << fname << " ";
					write << lname << " ";
					write << dp << " ";
					write << cgpa << " ";
					write << cnic << " )\n";
				}

				else {
					write << line << endl;
				}
			}
			read.close();
			write.close();
			remove("StudentInfo.txt");
			rename("temp.txt", "StudentInfo.txt");
			MessageBox::Show("Data Successfully Updated", "Updated Data", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			Close();
		}
		else {
			MessageBox::Show(" Please Enter Data in Correct Format / Given Range", "Incorrect Data Entry", MessageBoxButtons::OK, MessageBoxIcon::Error);
			fnameTb->Clear();
			lnameTb->Clear();
			cgpaTb->Clear();
			cnicTb->Clear();
			dpartmentTb->Clear();
		}
	}
	else {
		MessageBox::Show("Please Enter Complete Record", "Incomplete Data", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void cancelbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void chnageData_Load(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	string rollNumber = msclr::interop::marshal_as<string>(textBox1->Text); 
	for (int i = 0; rollNumber[i] != '\0'; i++) {
		if (((rollNumber[i] >= '0' && rollNumber[i] <= '9') || rollNumber[i] == 'L' || rollNumber[3] == '-') && rollNumber[i] != 'l') {
			textBox1->BackColor = System::Drawing::SystemColors::Window;
			updateBtn->Enabled = true;
		}
		else {
			textBox1->BackColor = System::Drawing::Color::LightCoral;
			updateBtn->Enabled = false;
		}
	}
}
};
}
