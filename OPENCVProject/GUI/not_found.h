#ifndef NOT_FOUND_H_INCLUDED
#define NOT_FOUND_H_INCLUDED

#pragma once

#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#using <System.Data.dll> 
#using <System.Drawing.dll>


namespace myOpenCV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyNotFound : public System::Windows::Forms::Form{
	public:
		MyNotFound(void){
			InitializeComponent();
		
		}

	protected:

		~MyNotFound(){
			if (components){delete components;}
		}

	System::Windows::Forms::Label^  title;
	System::Windows::Forms::PictureBox^  picture;
	System::Windows::Forms::GroupBox^  patient;
	System::Windows::Forms::Label^  title2;
	System::Windows::Forms::GroupBox^  informations;
	System::Windows::Forms::Button^  Try;
	System::Windows::Forms::Label^  result;
	System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void){
			this->title = (gcnew System::Windows::Forms::Label());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->patient = (gcnew System::Windows::Forms::GroupBox());
			this->title2 = (gcnew System::Windows::Forms::Label());
			this->informations = (gcnew System::Windows::Forms::GroupBox());
			this->result = (gcnew System::Windows::Forms::Label());
			this->Try = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->BeginInit();
			this->patient->SuspendLayout();
			this->informations->SuspendLayout();
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::White;
			this->title->Location = System::Drawing::Point(12, 19);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(327, 52);
			this->title->TabIndex = 0;
			this->title->Text = L"Medical Record";
			// 
			// picture
			// 
			this->picture->Location = System::Drawing::Point(20, 37);
			this->picture->Name = L"picture";
			this->picture->ImageLocation = L"C:/Users/DSi_5/Desktop/Projet2/not_found.png";
			this->picture->Size = System::Drawing::Size(427, 489);
			this->picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture->TabIndex = 2;
			this->picture->TabStop = false;
			// 
			// patient
			// 
			this->patient->Controls->Add(this->picture);
			this->patient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->patient->ForeColor = System::Drawing::Color::White;
			this->patient->Location = System::Drawing::Point(21, 123);
			this->patient->Name = L"patient";
			this->patient->Size = System::Drawing::Size(462, 551);
			this->patient->TabIndex = 6;
			this->patient->TabStop = false;
			this->patient->Text = L"Patient";
			// 
			// title2
			// 
			this->title2->AutoSize = true;
			this->title2->ForeColor = System::Drawing::Color::Transparent;
			this->title2->Location = System::Drawing::Point(325, 9);
			this->title2->Name = L"title2";
			this->title2->Size = System::Drawing::Size(31, 20);
			this->title2->TabIndex = 7;
			this->title2->Text = L"TM";
			// 
			// informations
			// 
			this->informations->Controls->Add(this->result);
			this->informations->Controls->Add(this->Try);
			this->informations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->informations->ForeColor = System::Drawing::Color::White;
			this->informations->Location = System::Drawing::Point(584, 123);
			this->informations->Name = L"informations";
			this->informations->Size = System::Drawing::Size(784, 551);
			this->informations->TabIndex = 3;
			this->informations->TabStop = false;
			this->informations->Text = L"Informations";
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(51, 59);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(440, 91);
			this->result->TabIndex = 14;
			this->result->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->result->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(144)), 
				static_cast<System::Int32>(static_cast<System::Byte>(144)));
			this->result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->result->Text = L"Match Not Found";
			this->result->ForeColor = System::Drawing::Color::White;
			this->result->Padding = System::Windows::Forms::Padding(8, 0, 6, 0);
			// 
			// Try
			// 
			this->Try->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(54)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Try->FlatAppearance->BorderSize = 2;
			this->Try->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Try->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Try->Location = System::Drawing::Point(50, 411);
			this->Try->Name = L"Try";
			this->Try->Size = System::Drawing::Size(683, 115);
			this->Try->TabIndex = 13;
			this->Try->UseVisualStyleBackColor = true;
			this->Try->Click += gcnew System::EventHandler(this, &MyNotFound::Try_Click);
			this->Try->Text = L"Try with another picture";
			this->Try->Visible = true;
			// 
			// MyNotFound
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(89)), 
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(1411, 788);
			this->Controls->Add(this->informations);
			this->Controls->Add(this->title2);
			this->Controls->Add(this->patient);
			this->Controls->Add(this->title);
			this->Name = L"MyNotFound";
			this->Text = L"MyNotFound";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->EndInit();
			this->patient->ResumeLayout(false);
			this->informations->ResumeLayout(false);
			this->informations->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();	

		}
#pragma endregion
	Void Try_Click(System::Object^  sender, System::EventArgs^  e) {
			Close();
		 }

};
}


#endif //NOT_FOUND_H_INCLUDED