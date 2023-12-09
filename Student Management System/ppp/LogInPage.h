#pragma once
#include "list.h";
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <string>
#include <fstream>
#include <sstream>
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
	/// Summary for LogInPage
	/// </summary>
	public ref class LogInPage : public System::Windows::Forms::Form
	{
	public:
		string strConversion(String^ str) {
			marshal_context context;
			return context.marshal_as<string>(str);
		}
		String^ STRconversion(string str) {
			marshal_context context;
			return context.marshal_as<String^>(str);
		}

		void getUsernamePwd(bool& flag) {
			fstream file("loginInfo.txt");
			string line;
			string user = strConversion(userNameTb->Text);
			string pwd = strConversion(pwdTb->Text);
			string info = user + " " + pwd;
			
			if (file.is_open()) {
				while (getline(file, line)) {
					for (int i = 0; info.length() == line.length() && i < line.length() && flag; i++) {
						if (info[i] == line[i])
							flag = true;
						else
							flag = false;
					}
				}
			}
			else {
				flag = false;
			}
		}
		LogInPage(void)
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
		~LogInPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ userNameTb;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ pwdTb;

	private: System::Windows::Forms::Button^ OkButton;
	private: System::Windows::Forms::Button^ CnclButton;
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
			this->userNameTb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pwdTb = (gcnew System::Windows::Forms::TextBox());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CnclButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(101, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign In";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email";
			// 
			// userNameTb
			// 
			this->userNameTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->userNameTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userNameTb->Location = System::Drawing::Point(13, 103);
			this->userNameTb->Multiline = true;
			this->userNameTb->Name = L"userNameTb";
			this->userNameTb->Size = System::Drawing::Size(260, 26);
			this->userNameTb->TabIndex = 2;
			this->userNameTb->TextChanged += gcnew System::EventHandler(this, &LogInPage::userNameTb_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Passowrd";
			// 
			// pwdTb
			// 
			this->pwdTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pwdTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pwdTb->Location = System::Drawing::Point(13, 183);
			this->pwdTb->Multiline = true;
			this->pwdTb->Name = L"pwdTb";
			this->pwdTb->PasswordChar = '*';
			this->pwdTb->Size = System::Drawing::Size(260, 26);
			this->pwdTb->TabIndex = 4;
			// 
			// OkButton
			// 
			this->OkButton->BackColor = System::Drawing::Color::Green;
			this->OkButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OkButton->ForeColor = System::Drawing::Color::White;
			this->OkButton->Location = System::Drawing::Point(16, 241);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(95, 32);
			this->OkButton->TabIndex = 5;
			this->OkButton->Text = L"Sign In";
			this->OkButton->UseVisualStyleBackColor = false;
			this->OkButton->Click += gcnew System::EventHandler(this, &LogInPage::OkButton_Click);
			// 
			// CnclButton
			// 
			this->CnclButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->CnclButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CnclButton->ForeColor = System::Drawing::Color::White;
			this->CnclButton->Location = System::Drawing::Point(154, 241);
			this->CnclButton->Name = L"CnclButton";
			this->CnclButton->Size = System::Drawing::Size(95, 32);
			this->CnclButton->TabIndex = 6;
			this->CnclButton->Text = L"Cancel";
			this->CnclButton->UseVisualStyleBackColor = false;
			this->CnclButton->Click += gcnew System::EventHandler(this, &LogInPage::CnclButton_Click);
			// 
			// LogInPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 288);
			this->Controls->Add(this->CnclButton);
			this->Controls->Add(this->OkButton);
			this->Controls->Add(this->pwdTb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->userNameTb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LogInPage";
			this->Text = L"SIGN IN";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OkButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (userNameTb->Text != "" && pwdTb->Text != "") {
			ifstream read("LoginInfo.txt");
			string username = msclr::interop::marshal_as<string>(userNameTb->Text);
			string password = msclr::interop::marshal_as<string>(pwdTb->Text);
			bool flag = false;

			if (read.is_open()) {
				string line;
				while (getline(read, line)) {
					string storedUsername = "";
					string storedPassword = "";
					bool foundSpace = false;

					for (size_t i = 0; i < line.length(); ++i) {
						char ch = line[i];

						if (ch == ' ') {
							foundSpace = true;
							continue;
						}

						if (!foundSpace) {
							storedUsername += ch;
						}
						else {
							storedPassword += ch;
						}
					}

					// Check if the entered username and password match the stored credentials
					if (username == storedUsername && password == storedPassword) {
						flag = true;
						break; // Exit the loop if credentials match
					}
				}
				read.close();
			}
			else {
				MessageBox::Show("Unable to access user information", "Data Not Found", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				Close(); // Close the current window or perform relevant actions
				return; // Exit the function
			}

			if (flag) {
				// If the credentials match, show the "list" window
				list lt;
				lt.ShowDialog();
			}
			else {
				// If the credentials don't match, display an error message
				MessageBox::Show("Invalid Username or Password", "Wrong Data" , MessageBoxButtons::OK, MessageBoxIcon::Warning);
				Close(); // Close the current window or perform relevant actions
			}
		}
		else {
			MessageBox::Show("Please Enter Username/Password", "Data Entry" ,  MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		
	}
	private: System::Void CnclButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void userNameTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void pwdTb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
