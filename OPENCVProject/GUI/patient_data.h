#ifndef PATIENT_DATA_H_INCLUDED
#define PATIENT_DATA_H_INCLUDED

#pragma once

#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#using <System.Data.dll> 
#using <System.Drawing.dll>

#include "my_global.h"
#include "mysql.h"
#define SERVER "127.0.0.1"
#define USER "root"
#define PASSWORD ""
#define DATABASE "classrecognition"

namespace myOpenCV30  {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyPatientData : public System::Windows::Forms::Form{
	public:
		MyPatientData(void){

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

			//Data Patient
			string selectData = "SELECT * FROM patient where id= " + id;
			mysql_query(connect, selectData.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string nameId = row[1];
			string firstnameId = row[2];
			string genderId = row[3];
			string birthDateId = row[4];
			string SSNId = row[5];
			string addressId = row[6];
			string telephoneNumberId = row[7];
			string emailId = row[8];

		    System::String^ name = gcnew System::String(nameId.c_str());
			System::String^ firstname = gcnew System::String(firstnameId.c_str());
			System::String^ gender = gcnew System::String(genderId.c_str());
			System::String^ birthDate = gcnew System::String(birthDateId.c_str());
			System::String^ SSN = gcnew System::String(SSNId.c_str());
			System::String^ address = gcnew System::String(addressId.c_str());
			System::String^ phoneNumber = gcnew System::String(telephoneNumberId.c_str());
			System::String^ email = gcnew System::String(emailId.c_str());

			//Picture Patient
			string selectPicture = "SELECT * FROM picture where idPatient= " + id;
			mysql_query(connect, selectPicture.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string pictureId = row[2];
			System::String^ picture = gcnew System::String(pictureId.c_str());

			//Disease Patient
			string selectDisease = "SELECT * FROM disease where idPatient= " + id;
			mysql_query(connect, selectDisease.c_str());
			result = mysql_store_result(connect);
			row = mysql_fetch_row(result);
			string diseaseId = row[2];
			string treatmentId = row[3];

			System::String^ disease = gcnew System::String(diseaseId.c_str());
			System::String^ treatment = gcnew System::String(treatmentId.c_str());

			InitializeComponent(name, firstname, gender, birthDate, SSN, address, phoneNumber, email, picture, disease, treatment);
		}

	protected:
		~MyPatientData(){
			if (components){delete components;}
		}

	System::Windows::Forms::Label^  title;
	System::Windows::Forms::Label^  title2;
	System::Windows::Forms::PictureBox^  picture;
	System::Windows::Forms::Label^  socialNumberPatient;
	System::Windows::Forms::Label^  addressLabel;
	System::Windows::Forms::Label^  addressPatient;
	System::Windows::Forms::Label^  birthdayPatient;
	System::Windows::Forms::Label^  genderPatient;
	System::Windows::Forms::Label^  namePatient;
	System::Windows::Forms::Label^  nameLabel;
	System::Windows::Forms::Label^  emailLabel;
	System::Windows::Forms::Label^  emailPatient;
	System::Windows::Forms::Label^  phoneLabel;
	System::Windows::Forms::Label^  phonePatient;
	System::Windows::Forms::Label^  genderLabel;
	System::Windows::Forms::Label^  socialNumberLabel;
	System::Windows::Forms::Label^  birthdayLabel;
	System::Windows::Forms::Label^  ongoingTreatmentLabel;
	System::Windows::Forms::Label^  patientLabel;
	System::Windows::Forms::Label^  diseaseLabel;
	System::Windows::Forms::Label^  treatmentLabel;
	System::Windows::Forms::Label^  diseasePatient;
	System::Windows::Forms::Label^  treatmentPatient;
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(System::String^ name,System::String^ firstname,System::String^ gender,System::String^ birthDate,System::String^ SSN,System::String^ address,System::String^ phoneNumber, System::String^ email, System::String^ picture, System::String^ disease, System::String^ treatment){
			this->title = (gcnew System::Windows::Forms::Label());
			this->title2 = (gcnew System::Windows::Forms::Label());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->socialNumberPatient = (gcnew System::Windows::Forms::Label());
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->addressPatient = (gcnew System::Windows::Forms::Label());
			this->birthdayPatient = (gcnew System::Windows::Forms::Label());
			this->genderPatient = (gcnew System::Windows::Forms::Label());
			this->namePatient = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->emailPatient = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->phonePatient = (gcnew System::Windows::Forms::Label());
			this->genderLabel = (gcnew System::Windows::Forms::Label());
			this->socialNumberLabel = (gcnew System::Windows::Forms::Label());
			this->birthdayLabel = (gcnew System::Windows::Forms::Label());
			this->ongoingTreatmentLabel = (gcnew System::Windows::Forms::Label());
			this->patientLabel = (gcnew System::Windows::Forms::Label());
			this->diseaseLabel = (gcnew System::Windows::Forms::Label());
			this->treatmentLabel = (gcnew System::Windows::Forms::Label());
			this->diseasePatient = (gcnew System::Windows::Forms::Label());
			this->treatmentPatient = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->BeginInit();
			this->SuspendLayout();
			//
			//
			//Data du patient, c'est ici qu'on met les données de la bdd
			//
			this->picture->ImageLocation = "../BDDjpg/" + picture + ".jpg";
			this->namePatient->Text = name + " " + firstname;
			this->genderPatient->Text = gender;
			this->birthdayPatient->Text = birthDate;
			this->socialNumberPatient->Text = SSN;
			this->addressPatient->Text = address;		
			this->emailPatient->Text = email;
			this->phonePatient->Text = phoneNumber;
			this->diseasePatient->Text = disease;
			this->treatmentPatient->Text = treatment;
			
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::White;
			this->title->Location = System::Drawing::Point(12, 20);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(327, 52);
			this->title->TabIndex = 1;
			this->title->Text = L"Medical Record";
			// 
			// title2
			// 
			this->title2->AutoSize = true;
			this->title2->ForeColor = System::Drawing::Color::Transparent;
			this->title2->Location = System::Drawing::Point(326, 9);
			this->title2->Name = L"title2";
			this->title2->Size = System::Drawing::Size(31, 20);
			this->title2->TabIndex = 8;
			this->title2->Text = L"TM";
			// 
			// picture
			// 
			this->picture->Location = System::Drawing::Point(21, 137);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(263, 254);
			this->picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture->TabIndex = 15;
			this->picture->TabStop = false;
			// 
			// socialNumberPatient
			// 
			this->socialNumberPatient->AutoSize = true;
			this->socialNumberPatient->BackColor = System::Drawing::Color::Transparent;
			this->socialNumberPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->socialNumberPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->socialNumberPatient->ForeColor = System::Drawing::Color::White;
			this->socialNumberPatient->Location = System::Drawing::Point(897, 193);
			this->socialNumberPatient->Name = L"socialNumberPatient";
			this->socialNumberPatient->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->socialNumberPatient->Size = System::Drawing::Size(393, 49);
			this->socialNumberPatient->TabIndex = 19;
			// 
			// numberPatient
			// 
			this->phonePatient->AutoSize = true;
			this->phonePatient->BackColor = System::Drawing::Color::Transparent;
			this->phonePatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->phonePatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->phonePatient->ForeColor = System::Drawing::Color::White;
			this->phonePatient->Location = System::Drawing::Point(343, 497);
			this->phonePatient->Name = L"numberPatient";
			this->phonePatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->phonePatient->Size = System::Drawing::Size(320, 49);
			this->phonePatient->TabIndex = 30;
			// 
			// emailPatient
			// 
			this->emailPatient->AutoSize = true;
			this->emailPatient->BackColor = System::Drawing::Color::Transparent;
			this->emailPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->emailPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->emailPatient->ForeColor = System::Drawing::Color::White;
			this->emailPatient->Location = System::Drawing::Point(804, 497);
			this->emailPatient->Name = L"emailPatient";
			this->emailPatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->emailPatient->Size = System::Drawing::Size(159, 49);
			this->emailPatient->TabIndex = 28;
			// addressPatient
			// 
			this->addressPatient->AutoSize = true;
			this->addressPatient->BackColor = System::Drawing::Color::Transparent;
			this->addressPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->addressPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->addressPatient->ForeColor = System::Drawing::Color::White;
			this->addressPatient->Location = System::Drawing::Point(247, 425);
			this->addressPatient->Name = L"addressPatient";
			this->addressPatient->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->addressPatient->Size = System::Drawing::Size(805, 49);
			this->addressPatient->TabIndex = 21;
			// 
			// birthdayPatient
			// 
			this->birthdayPatient->AutoSize = true;
			this->birthdayPatient->BackColor = System::Drawing::Color::Transparent;
			this->birthdayPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->birthdayPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->birthdayPatient->ForeColor = System::Drawing::Color::White;
			this->birthdayPatient->Location = System::Drawing::Point(897, 342);
			this->birthdayPatient->Name = L"birthdayPatient";
			this->birthdayPatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->birthdayPatient->Size = System::Drawing::Size(260, 49);
			this->birthdayPatient->TabIndex = 22;
			// 
			// genderPatient
			// 
			this->genderPatient->AutoSize = true;
			this->genderPatient->BackColor = System::Drawing::Color::Transparent;
			this->genderPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->genderPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->genderPatient->ForeColor = System::Drawing::Color::White;
			this->genderPatient->Location = System::Drawing::Point(303, 342);
			this->genderPatient->Name = L"genderPatient";
			this->genderPatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->genderPatient->Size = System::Drawing::Size(180, 49);
			this->genderPatient->TabIndex = 23;
			// 
			// namePatient
			// 
			this->namePatient->AutoSize = true;
			this->namePatient->BackColor = System::Drawing::Color::Transparent;
			this->namePatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->namePatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->namePatient->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->namePatient->Location = System::Drawing::Point(303, 193);
			this->namePatient->Name = L"namePatient";
			this->namePatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->namePatient->Size = System::Drawing::Size(260, 49);
			this->namePatient->TabIndex = 24;
			// 
			// DiseasePatient
			// 
			this->diseasePatient->AutoSize = true;
			this->diseasePatient->BackColor = System::Drawing::Color::Transparent;
			this->diseasePatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diseasePatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->diseasePatient->ForeColor = System::Drawing::Color::White;
			this->diseasePatient->Location = System::Drawing::Point(21, 695);
			this->diseasePatient->Name = L"DiseasePatient";
			this->diseasePatient->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->diseasePatient->Size = System::Drawing::Size(412, 49);
			this->diseasePatient->TabIndex = 39;
			// 
			// TreatmentPatient
			// 
			this->treatmentPatient->AutoSize = true;
			this->treatmentPatient->BackColor = System::Drawing::Color::Transparent;
			this->treatmentPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->treatmentPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->treatmentPatient->ForeColor = System::Drawing::Color::White;
			this->treatmentPatient->Location = System::Drawing::Point(541, 695);
			this->treatmentPatient->Name = L"TreatmentPatient";
			this->treatmentPatient->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->treatmentPatient->Size = System::Drawing::Size(805, 49);
			this->treatmentPatient->TabIndex = 41;
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)), 
				static_cast<System::Int32>(static_cast<System::Byte>(222)));
			this->nameLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(303, 137);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->nameLabel->Size = System::Drawing::Size(164, 49);
			this->nameLabel->TabIndex = 25;
			this->nameLabel->Text = L"Name";
			// 
			// emailLabel
			// 
			this->emailLabel->AutoSize = true;
			this->emailLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(143)), 
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->emailLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->emailLabel->Location = System::Drawing::Point(804, 497);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->emailLabel->Size = System::Drawing::Size(159, 49);
			this->emailLabel->TabIndex = 27;
			this->emailLabel->Text = L"Email";
			// 
			// phoneLabel
			// 
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(143)), 
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->phoneLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->phoneLabel->Location = System::Drawing::Point(21, 497);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->phoneLabel->Size = System::Drawing::Size(302, 49);
			this->phoneLabel->TabIndex = 29;
			this->phoneLabel->Text = L"Phone Number";
			// 
			// addressLabel
			// 
			this->addressLabel->AutoSize = true;
			this->addressLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(143)), 
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->addressLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->addressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->addressLabel->Location = System::Drawing::Point(21, 425);
			this->addressLabel->Name = L"addressLabel";
			this->addressLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->addressLabel->Size = System::Drawing::Size(199, 49);
			this->addressLabel->TabIndex = 20;
			this->addressLabel->Text = L"Address";
			// 
			// 
			// genderLabel
			// 
			this->genderLabel->AutoSize = true;
			this->genderLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)), 
				static_cast<System::Int32>(static_cast<System::Byte>(222)));
			this->genderLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->genderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->genderLabel->Location = System::Drawing::Point(303, 284);
			this->genderLabel->Name = L"genderLabel";
			this->genderLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->genderLabel->Size = System::Drawing::Size(186, 49);
			this->genderLabel->TabIndex = 31;
			this->genderLabel->Text = L"Gender";
			// 
			// socialNumberLabel
			// 
			this->socialNumberLabel->AutoSize = true;
			this->socialNumberLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)), 
				static_cast<System::Int32>(static_cast<System::Byte>(222)));
			this->socialNumberLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->socialNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->socialNumberLabel->Location = System::Drawing::Point(897, 137);
			this->socialNumberLabel->Name = L"socialNumberLabel";
			this->socialNumberLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->socialNumberLabel->Size = System::Drawing::Size(430, 49);
			this->socialNumberLabel->TabIndex = 32;
			this->socialNumberLabel->Text = L"social Security Number";
			// 
			// birthdayLabel
			// 
			this->birthdayLabel->AutoSize = true;
			this->birthdayLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)), 
				static_cast<System::Int32>(static_cast<System::Byte>(222)));
			this->birthdayLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->birthdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->birthdayLabel->Location = System::Drawing::Point(897, 284);
			this->birthdayLabel->Name = L"birthdayLabel";
			this->birthdayLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->birthdayLabel->Size = System::Drawing::Size(199, 49);
			this->birthdayLabel->TabIndex = 33;
			this->birthdayLabel->Text = L"Birthday";
			// 
			// ongoingTreatmentLabel
			// 
			this->ongoingTreatmentLabel->AutoSize = true;
			this->ongoingTreatmentLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
				static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ongoingTreatmentLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ongoingTreatmentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ongoingTreatmentLabel->ForeColor = System::Drawing::Color::White;
			this->ongoingTreatmentLabel->Location = System::Drawing::Point(21, 558);
			this->ongoingTreatmentLabel->Name = L"ongoingTreatmentLabel";
			this->ongoingTreatmentLabel->Padding = System::Windows::Forms::Padding(540, 5, 510, 5);
			this->ongoingTreatmentLabel->Size = System::Drawing::Size(1363, 49);
			this->ongoingTreatmentLabel->TabIndex = 35;
			this->ongoingTreatmentLabel->Text = L"Ongoing Treatment";
			// 
			// patientLabel
			// 
			this->patientLabel->AutoSize = true;
			this->patientLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(54)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->patientLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->patientLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->patientLabel->ForeColor = System::Drawing::Color::White;
			this->patientLabel->Location = System::Drawing::Point(19, 72);
			this->patientLabel->Name = L"patientLabel";
			this->patientLabel->Padding = System::Windows::Forms::Padding(620, 5, 610, 5);
			this->patientLabel->Size = System::Drawing::Size(1365, 49);
			this->patientLabel->TabIndex = 36;
			this->patientLabel->Text = L"Patient ";
			// 
			// DiseaseLabel
			// 
			this->diseaseLabel->AutoSize = true;
			this->diseaseLabel->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->diseaseLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diseaseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->diseaseLabel->Location = System::Drawing::Point(21, 623);
			this->diseaseLabel->Name = L"DiseaseLabel";
			this->diseaseLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->diseaseLabel->Size = System::Drawing::Size(195, 49);
			this->diseaseLabel->TabIndex = 37;
			this->diseaseLabel->Text = L"Disease";
			// 
			// TreatmentLabel
			// 
			this->treatmentLabel->AutoSize = true;
			this->treatmentLabel->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->treatmentLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->treatmentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->treatmentLabel->Location = System::Drawing::Point(541, 623);
			this->treatmentLabel->Name = L"TreatmentLabel";
			this->treatmentLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->treatmentLabel->Size = System::Drawing::Size(229, 49);
			this->treatmentLabel->TabIndex = 38;
			this->treatmentLabel->Text = L"Treatment";
			// 
			// MyPatientData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(89)), 
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(1411, 949);
			this->Controls->Add(this->treatmentPatient);
			this->Controls->Add(this->diseasePatient);
			this->Controls->Add(this->treatmentLabel);
			this->Controls->Add(this->diseaseLabel);
			this->Controls->Add(this->patientLabel);
			this->Controls->Add(this->ongoingTreatmentLabel);
			this->Controls->Add(this->diseaseLabel);
			this->Controls->Add(this->birthdayLabel);
			this->Controls->Add(this->socialNumberLabel);
			this->Controls->Add(this->genderLabel);
			this->Controls->Add(this->phonePatient);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->emailPatient);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->namePatient);
			this->Controls->Add(this->genderPatient);
			this->Controls->Add(this->birthdayPatient);
			this->Controls->Add(this->addressPatient);
			this->Controls->Add(this->addressLabel);
			this->Controls->Add(this->socialNumberPatient);
			this->Controls->Add(this->picture);
			this->Controls->Add(this->title2);
			this->Controls->Add(this->title);
			this->Name = L"MyPatientData";
			this->Text = L"MyPatientData";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}


#endif //PATIENT_DATA_H_INCLUDED