#ifndef PATIENT_FOUND_H_INCLUDED
#define NOT_PATIENT_H_INCLUDED

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

	public ref class MyPatientFound : public System::Windows::Forms::Form{
	public:
		MyPatientFound(void){
			//ICI RECUPERATION DES INFOS DE LA BASE
			System::String^ name = "Inès Frébault";
			System::String^ urlPicture = "img0";
			//ET ENVOI DES DONNES DANS LA FONCTION DE LA FORM
			InitializeComponent(name, urlPicture);
		}

	protected:
		~MyPatientFound(){
			if (components){delete components;}
		}
	System::Windows::Forms::Label^  Titre;
	System::Windows::Forms::PictureBox^  Picture;
	System::Windows::Forms::GroupBox^  Patient;
	System::Windows::Forms::Label^  Titre2;
	System::Windows::Forms::GroupBox^  Informations;
	System::Windows::Forms::Button^  Record;
	System::Windows::Forms::TextBox^  NamePatient;
	System::Windows::Forms::Label^  Result;
	System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code

		void InitializeComponent(System::String^ name, System::String^ urlPicture){
			this->Titre = (gcnew System::Windows::Forms::Label());
			this->Picture = (gcnew System::Windows::Forms::PictureBox());
			this->Patient = (gcnew System::Windows::Forms::GroupBox());
			this->Titre2 = (gcnew System::Windows::Forms::Label());
			this->Informations = (gcnew System::Windows::Forms::GroupBox());
			this->Result = (gcnew System::Windows::Forms::Label());
			this->NamePatient = (gcnew System::Windows::Forms::TextBox());
			this->Record = (gcnew System::Windows::Forms::Button());
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
			this->Picture->ImageLocation = "C:/Users/DSi_5/Desktop/ProjetBis/myOpenCV30/" + urlPicture + ".jpg";
			this->Picture->Location = System::Drawing::Point(20, 37);
			this->Picture->Name = L"Picture";
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
			this->Informations->Controls->Add(this->NamePatient);
			this->Informations->Controls->Add(this->Record);
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
			this->Result->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Result->Text = "Match Found";
			this->Result->ForeColor = System::Drawing::Color::White;
			this->Result->Padding = System::Windows::Forms::Padding(100, 0, 65, 0);
			// 
			// NamePatient
			//
			
			this->NamePatient->AppendText(name);
			this->NamePatient->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NamePatient->Cursor = System::Windows::Forms::Cursors::Default;
			this->NamePatient->Enabled = false;
			this->NamePatient->Location = System::Drawing::Point(50, 217);
			this->NamePatient->Name = L"NamePatient";
			this->NamePatient->ReadOnly = true;
			this->NamePatient->Size = System::Drawing::Size(683, 28);
			this->NamePatient->TabIndex = 12;
			this->NamePatient->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NamePatient->BackColor = System::Drawing::Color::White;
			this->NamePatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			// 
			// Record
			// 
			this->Record->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(54)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Record->FlatAppearance->BorderSize = 2;
			this->Record->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Record->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Record->Location = System::Drawing::Point(50, 411);
			this->Record->Name = L"Record";
			this->Record->Size = System::Drawing::Size(683, 115);
			this->Record->TabIndex = 9;
			this->Record->UseVisualStyleBackColor = true;
			this->Record->Click += gcnew System::EventHandler(this, &MyPatientFound::Record_Click);
			this->Record->Text = L"Show medical record";
			this->Record->Visible = true;
			// 
			// MyPatientFound
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
			this->Name = L"MyPatientFound";
			this->Text = L"MyPatientFound";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->EndInit();
			this->Patient->ResumeLayout(false);
			this->Informations->ResumeLayout(false);
			this->Informations->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();	

		}
#pragma endregion
	
private: System::Void Record_Click(System::Object^  sender, System::EventArgs^  e) {
			 //LANCE LA FICHE MEDICALE
		 }
};
}

#endif //PATIENT_FOUND_H_INCLUDED