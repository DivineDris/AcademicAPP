#pragma once

#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 

namespace AcademicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LoginLabel;
	private: System::Windows::Forms::TextBox^ EmailTextBox;
	protected:

	private: System::Windows::Forms::Label^ EmailLabel;
	private: System::Windows::Forms::Label^ PasswordLabel;
	private: System::Windows::Forms::TextBox^ PasswordTextBox;

	private: System::Windows::Forms::Button^ CancelButton;
	private: System::Windows::Forms::Button^ LogInButton;

	private:
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;
		sql::Statement* stmt;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LoginLabel = (gcnew System::Windows::Forms::Label());
			this->EmailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EmailLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->LogInButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LoginLabel
			// 
			this->LoginLabel->AutoSize = true;
			this->LoginLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoginLabel->Location = System::Drawing::Point(200, 55);
			this->LoginLabel->Name = L"LoginLabel";
			this->LoginLabel->Size = System::Drawing::Size(96, 37);
			this->LoginLabel->TabIndex = 0;
			this->LoginLabel->Text = L"Login";
			// 
			// EmailTextBox
			// 
			this->EmailTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EmailTextBox->Location = System::Drawing::Point(96, 114);
			this->EmailTextBox->Name = L"EmailTextBox";
			this->EmailTextBox->Size = System::Drawing::Size(376, 26);
			this->EmailTextBox->TabIndex = 1;
			// 
			// EmailLabel
			// 
			this->EmailLabel->AutoSize = true;
			this->EmailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EmailLabel->Location = System::Drawing::Point(12, 120);
			this->EmailLabel->Name = L"EmailLabel";
			this->EmailLabel->Size = System::Drawing::Size(48, 20);
			this->EmailLabel->TabIndex = 2;
			this->EmailLabel->Text = L"Email";
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PasswordLabel->Location = System::Drawing::Point(12, 160);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(78, 20);
			this->PasswordLabel->TabIndex = 4;
			this->PasswordLabel->Text = L"Password";
			// 
			// PasswordTextBox
			// 
			this->PasswordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PasswordTextBox->Location = System::Drawing::Point(96, 154);
			this->PasswordTextBox->Name = L"PasswordTextBox";
			this->PasswordTextBox->Size = System::Drawing::Size(376, 26);
			this->PasswordTextBox->TabIndex = 3;
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(397, 226);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 5;
			this->CancelButton->Text = L"cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &MainForm::CancelButton_Click);
			// 
			// LogInButton
			// 
			this->LogInButton->Location = System::Drawing::Point(316, 226);
			this->LogInButton->Name = L"LogInButton";
			this->LogInButton->Size = System::Drawing::Size(75, 23);
			this->LogInButton->TabIndex = 6;
			this->LogInButton->Text = L"log in";
			this->LogInButton->UseVisualStyleBackColor = true;
			this->LogInButton->Click += gcnew System::EventHandler(this, &MainForm::LogInButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->LogInButton);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->PasswordLabel);
			this->Controls->Add(this->PasswordTextBox);
			this->Controls->Add(this->EmailLabel);
			this->Controls->Add(this->EmailTextBox);
			this->Controls->Add(this->LoginLabel);
			this->Name = L"MainForm";
			this->Text = L"AcademicApp";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void LogInButton_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ email = this->EmailTextBox->Text;
	String^ password = this->PasswordTextBox->Text;

	if (email->Length == 0 || password->Length == 0) {
		MessageBox::Show("Please enter email and password");
		return;
	}
	try
	{
		stmt = con->createStatement();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
	
}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306",
			"root", "123456root");
		con->setSchema("academicapp");
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}


}
};
}
