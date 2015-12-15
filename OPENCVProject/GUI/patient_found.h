#ifndef PATIENT_FOUND_H_INCLUDED
#define PATIENT_FOUND_H_INCLUDED

#pragma once

#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#using <System.Data.dll> 
#using <System.Drawing.dll>

#include "patient_data.h"


#include "my_global.h"
#include "mysql.h"
#define SERVER "127.0.0.1"
#define USER "root"
#define PASSWORD ""
#define DATABASE "classrecognition"

namespace myOpenCV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyPatientFound : public System::Windows::Forms::Form{
	public:
		MyPatientFound(void){

			MYSQL *connect; 
			connect=mysql_init(NULL); 
			if(!connect){
				fprintf(stderr,"MySQL Initialization Failed");
			}
 
			connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);

			if(!connect){
				printf("Connection Failed!\n");
			}
	
			MYSQL_ROW row;  
			MYSQL_RES *result = NULL;

			//Id Patient
			string selectIdImg = "SELECT * FROM insertData ";
			mysql_query(connect, selectIdImg.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string idImg = row[0];
			
			string selectId2 = "SELECT * FROM picture where fileName=" + idImg;
			mysql_query(connect, selectId2.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string id = row[1];

			//Name Patient
			string selectName = "SELECT * FROM patient where id= " + id;
			mysql_query(connect, selectName.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string nameId = row[1];
			string firstnameId = row[2];

		    System::String^ name = gcnew System::String(nameId.c_str());
			System::String^ firstname = gcnew System::String(firstnameId.c_str());
			System::String^ patientName = name + " " + firstname;

			//Picture Patient
			string selectPicture = "SELECT * FROM picture where idPatient= " + id;
			mysql_query(connect, selectPicture.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string pictureId = row[2];
			System::String^ picture = gcnew System::String(pictureId.c_str());

			InitializeComponent(patientName, picture);

			mysql_free_result(result);
			mysql_close(connect);
		}

	protected:
		~MyPatientFound(){
			if (components){delete components;}
		}
	System::Windows::Forms::Label^  title;
	System::Windows::Forms::PictureBox^  picture;
	System::Windows::Forms::GroupBox^  patient;
	System::Windows::Forms::Label^  title2;
	System::Windows::Forms::GroupBox^  informations;
	System::Windows::Forms::Button^  record;
	System::Windows::Forms::TextBox^  namePatient;
	System::Windows::Forms::Label^  result;
	System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code

		void InitializeComponent(System::String^ name, System::String^ picture){
			this->title = (gcnew System::Windows::Forms::Label());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->patient = (gcnew System::Windows::Forms::GroupBox());
			this->title2 = (gcnew System::Windows::Forms::Label());
			this->informations = (gcnew System::Windows::Forms::GroupBox());
			this->result = (gcnew System::Windows::Forms::Label());
			this->namePatient = (gcnew System::Windows::Forms::TextBox());
			this->record = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->BeginInit();
			this->patient->SuspendLayout();
			this->informations->SuspendLayout();
			this->SuspendLayout();
			//
			//
			// Data 
			//
			this->picture->ImageLocation = "../BDDjpg/" + picture + ".jpg";
			this->namePatient->AppendText(name);
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
			this->informations->Controls->Add(this->namePatient);
			this->informations->Controls->Add(this->record);
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
			this->result->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->result->Text = "Match Found";
			this->result->ForeColor = System::Drawing::Color::White;
			this->result->Padding = System::Windows::Forms::Padding(100, 0, 65, 0);
			// 
			// namePatient
			//
			this->namePatient->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->namePatient->Cursor = System::Windows::Forms::Cursors::Default;
			this->namePatient->Enabled = false;
			this->namePatient->Location = System::Drawing::Point(50, 217);
			this->namePatient->Name = L"namePatient";
			this->namePatient->ReadOnly = true;
			this->namePatient->Size = System::Drawing::Size(683, 28);
			this->namePatient->TabIndex = 12;
			this->namePatient->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->namePatient->BackColor = System::Drawing::Color::White;
			this->namePatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			// 
			// record
			// 
			this->record->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(54)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->record->FlatAppearance->BorderSize = 2;
			this->record->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->record->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->record->Location = System::Drawing::Point(50, 411);
			this->record->Name = L"record";
			this->record->Size = System::Drawing::Size(683, 115);
			this->record->TabIndex = 9;
			this->record->UseVisualStyleBackColor = true;
			this->record->Click += gcnew System::EventHandler(this, &MyPatientFound::record_Click);
			this->record->Text = L"Show medical record";
			this->record->Visible = true;
			// 
			// MyPatientFound
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
			this->Name = L"MyPatientFound";
			this->Text = L"MyPatientFound";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->EndInit();
			this->patient->ResumeLayout(false);
			this->informations->ResumeLayout(false);
			this->informations->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();	

		}
#pragma endregion
	
private: System::Void record_Click(System::Object^  sender, System::EventArgs^  e) {
			 //LANCE LA FICHE MEDICALE
			 myOpenCV30::MyPatientData form;
			form.ShowDialog();
		 }
};
}

#endif //PATIENT_FOUND_H_INCLUDED