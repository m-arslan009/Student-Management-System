#pragma once
#include "AddInfo.h"
#include "display.h"
#include "deletedata.h"
#include "searchData.h"
#include "chnageData.h"
namespace ppp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for list
	/// </summary>
	public ref class list : public System::Windows::Forms::Form
	{
	public:
		list(void)
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
		~list()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ addBtn;

	private: System::Windows::Forms::Button^ displayBtn;
	private: System::Windows::Forms::Button^ searchBtn;

	private: System::Windows::Forms::Button^ changeBtn;
	private: System::Windows::Forms::Button^ delBtn;
	private: System::Windows::Forms::Button^ ExitBtn;
	private: System::Windows::Forms::Label^ label7;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->displayBtn = (gcnew System::Windows::Forms::Button());
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->changeBtn = (gcnew System::Windows::Forms::Button());
			this->delBtn = (gcnew System::Windows::Forms::Button());
			this->ExitBtn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(20, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add Record";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(20, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Display Record";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(20, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Search Record";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(20, 178);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Change Record";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(20, 213);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Delete Record";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(20, 248);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Close Database";
			// 
			// addBtn
			// 
			this->addBtn->Location = System::Drawing::Point(204, 61);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(75, 23);
			this->addBtn->TabIndex = 6;
			this->addBtn->Text = L"ADD";
			this->addBtn->UseVisualStyleBackColor = true;
			this->addBtn->Click += gcnew System::EventHandler(this, &list::addBtn_Click);
			// 
			// displayBtn
			// 
			this->displayBtn->Location = System::Drawing::Point(204, 101);
			this->displayBtn->Name = L"displayBtn";
			this->displayBtn->Size = System::Drawing::Size(75, 23);
			this->displayBtn->TabIndex = 7;
			this->displayBtn->Text = L"DISPLAY";
			this->displayBtn->UseVisualStyleBackColor = true;
			this->displayBtn->Click += gcnew System::EventHandler(this, &list::displayBtn_Click);
			// 
			// searchBtn
			// 
			this->searchBtn->Location = System::Drawing::Point(204, 136);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(75, 23);
			this->searchBtn->TabIndex = 8;
			this->searchBtn->Text = L"SEARCH";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &list::searchBtn_Click);
			// 
			// changeBtn
			// 
			this->changeBtn->Location = System::Drawing::Point(204, 171);
			this->changeBtn->Name = L"changeBtn";
			this->changeBtn->Size = System::Drawing::Size(75, 23);
			this->changeBtn->TabIndex = 9;
			this->changeBtn->Text = L"CHANGE";
			this->changeBtn->UseVisualStyleBackColor = true;
			this->changeBtn->Click += gcnew System::EventHandler(this, &list::changeBtn_Click);
			// 
			// delBtn
			// 
			this->delBtn->Location = System::Drawing::Point(204, 206);
			this->delBtn->Name = L"delBtn";
			this->delBtn->Size = System::Drawing::Size(75, 23);
			this->delBtn->TabIndex = 10;
			this->delBtn->Text = L"DELETE";
			this->delBtn->UseVisualStyleBackColor = true;
			this->delBtn->Click += gcnew System::EventHandler(this, &list::delBtn_Click);
			// 
			// ExitBtn
			// 
			this->ExitBtn->Location = System::Drawing::Point(204, 241);
			this->ExitBtn->Name = L"ExitBtn";
			this->ExitBtn->Size = System::Drawing::Size(75, 23);
			this->ExitBtn->TabIndex = 11;
			this->ExitBtn->Text = L"EXIT";
			this->ExitBtn->UseVisualStyleBackColor = true;
			this->ExitBtn->Click += gcnew System::EventHandler(this, &list::ExitBtn_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(20, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(259, 25);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Managing Student Data";
			// 
			// list
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(310, 284);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->ExitBtn);
			this->Controls->Add(this->delBtn);
			this->Controls->Add(this->changeBtn);
			this->Controls->Add(this->searchBtn);
			this->Controls->Add(this->displayBtn);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"list";
			this->Text = L"Action Page";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AddInfo info;
		info.ShowDialog();
	}
	private: System::Void displayBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		display d;
		d.ShowDialog();
	}
private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	deletedata d;
	d.ShowDialog();
}
private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	searchData sd;
	sd.ShowDialog();
}
private: System::Void changeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	chnageData cd;
	cd.ShowDialog();
}
private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}
