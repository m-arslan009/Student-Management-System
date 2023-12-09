#pragma once
#include "LogInPage.h"
#include <regex>
#include <fstream>
#include <msclr/marshal.h>

namespace ppp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for SignUpPage
	/// </summary>
	public ref class SignUpPage : public System::Windows::Forms::Form
	{
		bool userTyping = false;
	public:
		SignUpPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void isEmpty(string str) {
			if (str.length() == 0) {
				CAccountBtn->Enabled = false;
			}
			else {
				CAccountBtn->Enabled = true;
			}
		}

		System::Void ValidateEmail(string mail) {
			CAccountBtn->Enabled = false;
			for (int i = 0; i < mail.length(); i++) {
				if (((mail[i] >= 'a' && mail[i] <= 'z') || 
					(mail[i] >= 'A' && mail[i] <= 'Z') || 
					(mail[i] >= '0' && mail[i] <= '9') || 
					mail[i] == '@' || mail[i] == '.')) {
					emailTb->BackColor = System::Drawing::SystemColors::Window;
				}
				else {
					emailTb->BackColor = System::Drawing::Color::LightCoral;
					break;
				}
			}
			isEmpty(mail);
		}

		Void ValidateNameFields(int num) {
			string name;
			if(num == 1)
				name = strConvert(fNameTb->Text);
			else
				name = strConvert(lNameTb->Text);
			for (int i = 0; i < name.length(); i++) {
				if (((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')) && name.length() >= 3) {
					if(num == 1)
						fNameTb->BackColor = System::Drawing::SystemColors::Window;
					else
						lNameTb->BackColor = System::Drawing::SystemColors::Window;
				}
				else {
					if (num == 1)
						fNameTb->BackColor = System::Drawing::Color::LightCoral;
					else
						lNameTb->BackColor = System::Drawing::Color::LightCoral;
					break;
				}
			}
		}

		String^ STRconvert(string str) {
			marshal_context context;
			return context.marshal_as<String^>(str);
		}

		string strConvert(String^ str) {
			marshal_context context;
			return context.marshal_as<string>(str);
		}

		bool isEmailRegistered(string mail, int& runFlag) {
			bool isExist = false;
			fstream file("LoginInfo.txt");
			string line;
			if (file.is_open()) {
				while (getline(file, line)) {
					for (int i = 0; i < mail.length(); i++) {
						if (line[i] != mail[i]) {
							isExist = false;
							break;
						}
						else
							isExist = true;
					}
					if (isExist){
						file.close();
						return isExist;
					}
				}
				file.close();
				return false;
			}

			else {
				runFlag = 0;
				return false;
			}
		}

		bool RegisterNewUser(string value, int& runFlag) {
			ofstream file("LoginInfo.txt", ios::app);
			if (file.is_open()) {
				file << value << endl;
				file.close();
				return true;
			}

			else {
				runFlag = 0;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		System::Void ValidatePasswords() {
			if (userTyping && pwdTb->Text != "" && pwdTb->Text->Length >= 4 && pwdTb->Text->Length <= 16 &&
				pwdTb->Text == cpwdTb->Text) {
				// Enable the submitButton if user has started typing and passwords match with non-empty fields
				cpwdTb->BackColor = System::Drawing::SystemColors::Window;
				CAccountBtn->Enabled = true;
			}
			else {
				if (cpwdTb->Text != " ")
					cpwdTb->BackColor = System::Drawing::Color::LightCoral;
				CAccountBtn->Enabled = false;
			}	
		}
		~SignUpPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ fNameTb;
	private: System::Windows::Forms::TextBox^ lNameTb;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ emailTb;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ pwdTb;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::TextBox^ cpwdTb;

	private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Button^ CAccountBtn;








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
			this->fNameTb = (gcnew System::Windows::Forms::TextBox());
			this->lNameTb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->emailTb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pwdTb = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->cpwdTb = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->CAccountBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(55, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Create New Account";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"First Name";
			// 
			// fNameTb
			// 
			this->fNameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fNameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fNameTb->Location = System::Drawing::Point(13, 101);
			this->fNameTb->Multiline = true;
			this->fNameTb->Name = L"fNameTb";
			this->fNameTb->Size = System::Drawing::Size(314, 26);
			this->fNameTb->TabIndex = 2;
			this->fNameTb->TextChanged += gcnew System::EventHandler(this, &SignUpPage::fNameTb_TextChanged);
			// 
			// lNameTb
			// 
			this->lNameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lNameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNameTb->Location = System::Drawing::Point(13, 177);
			this->lNameTb->Multiline = true;
			this->lNameTb->Name = L"lNameTb";
			this->lNameTb->Size = System::Drawing::Size(314, 26);
			this->lNameTb->TabIndex = 4;
			this->lNameTb->TextChanged += gcnew System::EventHandler(this, &SignUpPage::lNameTb_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Last Name";
			// 
			// emailTb
			// 
			this->emailTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->emailTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailTb->Location = System::Drawing::Point(13, 253);
			this->emailTb->Multiline = true;
			this->emailTb->Name = L"emailTb";
			this->emailTb->Size = System::Drawing::Size(314, 26);
			this->emailTb->TabIndex = 6;
			this->emailTb->TextChanged += gcnew System::EventHandler(this, &SignUpPage::emailTb_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 219);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 18);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Email";
			// 
			// pwdTb
			// 
			this->pwdTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pwdTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pwdTb->Location = System::Drawing::Point(13, 329);
			this->pwdTb->Multiline = true;
			this->pwdTb->Name = L"pwdTb";
			this->pwdTb->PasswordChar = '*';
			this->pwdTb->Size = System::Drawing::Size(314, 26);
			this->pwdTb->TabIndex = 8;
			this->pwdTb->TextChanged += gcnew System::EventHandler(this, &SignUpPage::pwdTb_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(13, 295);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 18);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(42, 444);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(166, 16);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Already Have an Account\?";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->LinkColor = System::Drawing::Color::DarkCyan;
			this->linkLabel1->Location = System::Drawing::Point(214, 443);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(54, 18);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Log In";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignUpPage::linkLabel1_LinkClicked);
			// 
			// cpwdTb
			// 
			this->cpwdTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cpwdTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cpwdTb->Location = System::Drawing::Point(12, 405);
			this->cpwdTb->Multiline = true;
			this->cpwdTb->Name = L"cpwdTb";
			this->cpwdTb->PasswordChar = '*';
			this->cpwdTb->Size = System::Drawing::Size(314, 26);
			this->cpwdTb->TabIndex = 12;
			this->cpwdTb->TextChanged += gcnew System::EventHandler(this, &SignUpPage::cpwdTb_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(12, 371);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(148, 18);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Confirm Password";
			// 
			// CAccountBtn
			// 
			this->CAccountBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CAccountBtn->Location = System::Drawing::Point(60, 500);
			this->CAccountBtn->Name = L"CAccountBtn";
			this->CAccountBtn->Size = System::Drawing::Size(218, 37);
			this->CAccountBtn->TabIndex = 13;
			this->CAccountBtn->Text = L"Sign Up";
			this->CAccountBtn->UseVisualStyleBackColor = true;
			this->CAccountBtn->Click += gcnew System::EventHandler(this, &SignUpPage::button1_Click);
			// 
			// SignUpPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 561);
			this->Controls->Add(this->CAccountBtn);
			this->Controls->Add(this->cpwdTb);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pwdTb);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->emailTb);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lNameTb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->fNameTb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(354, 600);
			this->MinimumSize = System::Drawing::Size(354, 600);
			this->Name = L"SignUpPage";
			this->Text = L"Create Account";
			this->Load += gcnew System::EventHandler(this, &SignUpPage::SignUpPage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		LogInPage lg;
		SignUpPage signPage;
		signPage.Hide();
		lg.ShowDialog();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int runFlag = 1;
	LogInPage lg;
	string info;
	if (isEmailRegistered(strConvert(emailTb->Text), runFlag)) {
		MessageBox::Show("This Email Already Registered", "Registration", MessageBoxButtons::OK, MessageBoxIcon::Warning);

	}

	else if (runFlag == 0) {
		MessageBox::Show("File Not Open/Exist", "File Error");
	}

	else if (fNameTb->Text == "" || lNameTb->Text == "" || emailTb->Text == "" || pwdTb->Text == "" || cpwdTb->Text == "")
		MessageBox::Show("Please fill all the Records", "Missing Fields");

	else {
		info = strConvert(emailTb->Text) + " " + strConvert(pwdTb->Text);
		if (RegisterNewUser(info, runFlag))
			MessageBox::Show("Account Successfuly Created", "Registration", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else
			MessageBox::Show("Account Not Created", "Account Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}
private: System::Void SignUpPage_Load(System::Object^ sender, System::EventArgs^ e) {
	isEmpty(strConvert(cpwdTb->Text));
	isEmpty(strConvert(pwdTb->Text));
	isEmpty(strConvert(emailTb->Text));
	isEmpty(strConvert(fNameTb->Text));
	isEmpty(strConvert(lNameTb->Text));
}
private: System::Void cpwdTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	userTyping = true;
	
	ValidatePasswords();
}
private: System::Void pwdTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	userTyping = true;
	
	ValidatePasswords();
}
private: System::Void emailTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	ValidateEmail(strConvert(emailTb->Text));
}
private: System::Void fNameTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	ValidateNameFields(1);
}
private: System::Void lNameTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	ValidateNameFields(2);
}
};
}
