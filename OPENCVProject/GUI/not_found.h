#ifndef NOT_FOUND_H_INCLUDED
#define NOT_FOUND_H_INCLUDED

#pragma once

#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#using <System.Data.dll> 
#using <System.Drawing.dll>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace myOpenCV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
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

	System::Windows::Forms::Label^  Titre;
	System::Windows::Forms::PictureBox^  Picture;
	System::Windows::Forms::GroupBox^  Patient;
	System::Windows::Forms::Label^  Titre2;
	System::Windows::Forms::GroupBox^  Informations;
	System::Windows::Forms::Button^  Try;
	System::Windows::Forms::Label^  Result;
	System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void){
			this->Titre = (gcnew System::Windows::Forms::Label());
			this->Picture = (gcnew System::Windows::Forms::PictureBox());
			this->Patient = (gcnew System::Windows::Forms::GroupBox());
			this->Titre2 = (gcnew System::Windows::Forms::Label());
			this->Informations = (gcnew System::Windows::Forms::GroupBox());
			this->Result = (gcnew System::Windows::Forms::Label());
			this->Try = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->BeginInit();
			this->Patient->SuspendLayout();
			this->Informations->SuspendLayout();
			this->SuspendLayout();
			// 
			// Titre
			// 
			this->Titre->AutoSize = true;
			this->Titre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Titre->ForeColor = System::Drawing::Color::White;
			this->Titre->Location = System::Drawing::Point(12, 19);
			this->Titre->Name = L"Titre";
			this->Titre->Size = System::Drawing::Size(327, 52);
			this->Titre->TabIndex = 0;
			this->Titre->Text = L"Medical Record";
			// 
			// Picture
			// 
			this->Picture->Location = System::Drawing::Point(20, 37);
			this->Picture->Name = L"Picture";
			this->Picture->ImageLocation = L"C:/Users/DSi_5/Desktop/Projet2/not_found.png";
			this->Picture->Size = System::Drawing::Size(427, 489);
			this->Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Picture->TabIndex = 2;
			this->Picture->TabStop = false;
			// 
			// Patient
			// 
			this->Patient->Controls->Add(this->Picture);
			this->Patient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Patient->ForeColor = System::Drawing::Color::White;
			this->Patient->Location = System::Drawing::Point(21, 123);
			this->Patient->Name = L"Patient";
			this->Patient->Size = System::Drawing::Size(462, 551);
			this->Patient->TabIndex = 6;
			this->Patient->TabStop = false;
			this->Patient->Text = L"Patient";
			// 
			// Titre2
			// 
			this->Titre2->AutoSize = true;
			this->Titre2->ForeColor = System::Drawing::Color::Transparent;
			this->Titre2->Location = System::Drawing::Point(325, 9);
			this->Titre2->Name = L"Titre2";
			this->Titre2->Size = System::Drawing::Size(31, 20);
			this->Titre2->TabIndex = 7;
			this->Titre2->Text = L"TM";
			// 
			// Informations
			// 
			this->Informations->Controls->Add(this->Result);
			this->Informations->Controls->Add(this->Try);
			this->Informations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Informations->ForeColor = System::Drawing::Color::White;
			this->Informations->Location = System::Drawing::Point(584, 123);
			this->Informations->Name = L"Informations";
			this->Informations->Size = System::Drawing::Size(784, 551);
			this->Informations->TabIndex = 3;
			this->Informations->TabStop = false;
			this->Informations->Text = L"Informations";
			// 
			// Result
			// 
			this->Result->AutoSize = true;
			this->Result->Location = System::Drawing::Point(51, 59);
			this->Result->Name = L"Result";
			this->Result->Size = System::Drawing::Size(440, 91);
			this->Result->TabIndex = 14;
			this->Result->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Result->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(144)), 
				static_cast<System::Int32>(static_cast<System::Byte>(144)));
			this->Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Result->Text = L"Match Not Found";
			this->Result->ForeColor = System::Drawing::Color::White;
			this->Result->Padding = System::Windows::Forms::Padding(8, 0, 6, 0);
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
			this->Try->Click += gcnew System::EventHandler(this, &MyNotFound::try_Click);
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
			this->Controls->Add(this->Informations);
			this->Controls->Add(this->Titre2);
			this->Controls->Add(this->Patient);
			this->Controls->Add(this->Titre);
			this->Name = L"MyNotFound";
			this->Text = L"MyNotFound";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->EndInit();
			this->Patient->ResumeLayout(false);
			this->Informations->ResumeLayout(false);
			this->Informations->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();	

		}
#pragma endregion
	Void try_Click(System::Object^  sender, System::EventArgs^  e) {
			Close();
		 }

};
}


#endif //NOT_FOUND_H_INCLUDED