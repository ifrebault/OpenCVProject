#ifndef PATIENT_DATA_H_INCLUDED
#define PATIENT_DATA_H_INCLUDED

#pragma once

#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#using <System.Data.dll> 
#using <System.Drawing.dll>

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
			InitializeComponent();

		}

	protected:
		~MyPatientData()
		{
			if (components){delete components;}
		}

	System::Windows::Forms::Label^  title;
	System::Windows::Forms::Label^  title2;
	System::Windows::Forms::PictureBox^  picture;
	System::Windows::Forms::Label^  placeBirthdayLabel;
	System::Windows::Forms::Label^  socialNumberPatient;
	System::Windows::Forms::Label^  addressLabel;
	System::Windows::Forms::Label^  addressPatient;
	System::Windows::Forms::Label^  birthdayPatient;
	System::Windows::Forms::Label^  genderPatient;
	System::Windows::Forms::Label^  namePatient;
	System::Windows::Forms::Label^  nameLabel;
	System::Windows::Forms::Label^  placeBirthdayPatient;
	System::Windows::Forms::Label^  emailLabel;
	System::Windows::Forms::Label^  emailPatient;
	System::Windows::Forms::Label^  phoneLabel;
	System::Windows::Forms::Label^  numberPatient;
	System::Windows::Forms::Label^  genderLabel;
	System::Windows::Forms::Label^  socialNumberLabel;
	System::Windows::Forms::Label^  birthdayLabel;
	System::Windows::Forms::ListBox^  diseaseLabel;
	System::Windows::Forms::Label^  ongoingTreatmentLabel;
	System::Windows::Forms::Label^  patientLabel;
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->title = (gcnew System::Windows::Forms::Label());
			this->title2 = (gcnew System::Windows::Forms::Label());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->placeBirthdayLabel = (gcnew System::Windows::Forms::Label());
			this->socialNumberPatient = (gcnew System::Windows::Forms::Label());
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->addressPatient = (gcnew System::Windows::Forms::Label());
			this->birthdayPatient = (gcnew System::Windows::Forms::Label());
			this->genderPatient = (gcnew System::Windows::Forms::Label());
			this->namePatient = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->placeBirthdayPatient = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->emailPatient = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->numberPatient = (gcnew System::Windows::Forms::Label());
			this->genderLabel = (gcnew System::Windows::Forms::Label());
			this->socialNumberLabel = (gcnew System::Windows::Forms::Label());
			this->birthdayLabel = (gcnew System::Windows::Forms::Label());
			this->diseaseLabel = (gcnew System::Windows::Forms::ListBox());
			this->ongoingTreatmentLabel = (gcnew System::Windows::Forms::Label());
			this->patientLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture))->BeginInit();
			this->SuspendLayout();
			//
			//
			//Data du patient, c'est ici qu'on met les données de la bdd
			//
			this->picture->ImageLocation = "C:/Users/DSi_5/Desktop/Projet2/img0.jpg";
			this->socialNumberPatient->Text = "X XX XX XX XXX XXX XX";
			this->addressPatient->Text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
			this->birthdayPatient->Text = "XX/XX/XXXX";
			this->genderPatient->Text = "Female";
			this->namePatient->Text = "Inès Frebault";
			this->placeBirthdayPatient->Text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
			this->emailPatient->Text = "Lorem@Lorem.Lorem";
			this->numberPatient->Text = "XX XX XX XX XX";
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
			this->numberPatient->AutoSize = true;
			this->numberPatient->BackColor = System::Drawing::Color::Transparent;
			this->numberPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->numberPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numberPatient->ForeColor = System::Drawing::Color::White;
			this->numberPatient->Location = System::Drawing::Point(343, 572);
			this->numberPatient->Name = L"numberPatient";
			this->numberPatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->numberPatient->Size = System::Drawing::Size(320, 49);
			this->numberPatient->TabIndex = 30;
			// 
			// emailPatient
			// 
			this->emailPatient->AutoSize = true;
			this->emailPatient->BackColor = System::Drawing::Color::Transparent;
			this->emailPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->emailPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->emailPatient->ForeColor = System::Drawing::Color::White;
			this->emailPatient->Location = System::Drawing::Point(984, 572);
			this->emailPatient->Name = L"emailPatient";
			this->emailPatient->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->emailPatient->Size = System::Drawing::Size(386, 49);
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
			// placeBirthdayPatient
			// 
			this->placeBirthdayPatient->AutoSize = true;
			this->placeBirthdayPatient->BackColor = System::Drawing::Color::Transparent;
			this->placeBirthdayPatient->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->placeBirthdayPatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->placeBirthdayPatient->ForeColor = System::Drawing::Color::White;
			this->placeBirthdayPatient->Location = System::Drawing::Point(368, 498);
			this->placeBirthdayPatient->Name = L"placeBirthdayPatient";
			this->placeBirthdayPatient->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->placeBirthdayPatient->Size = System::Drawing::Size(805, 49);
			this->placeBirthdayPatient->TabIndex = 26;
			// 
			// emailLabel
			// 
			this->emailLabel->AutoSize = true;
			this->emailLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(143)), 
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->emailLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->emailLabel->Location = System::Drawing::Point(803, 572);
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
			this->phoneLabel->Location = System::Drawing::Point(21, 572);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->phoneLabel->Size = System::Drawing::Size(302, 49);
			this->phoneLabel->TabIndex = 29;
			this->phoneLabel->Text = L"Phone Number";
			// 
			// placeBirthdayLabel
			// 
			this->placeBirthdayLabel->AutoSize = true;
			this->placeBirthdayLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), 
				static_cast<System::Int32>(static_cast<System::Byte>(143)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->placeBirthdayLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->placeBirthdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->placeBirthdayLabel->Location = System::Drawing::Point(21, 498);
			this->placeBirthdayLabel->Name = L"placeBirthdayLabel";
			this->placeBirthdayLabel->Padding = System::Windows::Forms::Padding(5, 5, 50, 5);
			this->placeBirthdayLabel->Size = System::Drawing::Size(329, 49);
			this->placeBirthdayLabel->TabIndex = 16;
			this->placeBirthdayLabel->Text = L"Place of birthday";
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
			// diseaseLabel
			// 
			this->diseaseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->diseaseLabel->FormattingEnabled = true;
			this->diseaseLabel->ItemHeight = 32;
			this->diseaseLabel->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Disease", L"Disease", L"Disease", L"Disease"});
			this->diseaseLabel->Location = System::Drawing::Point(21, 714);
			this->diseaseLabel->Name = L"diseaseLabel";
			this->diseaseLabel->Size = System::Drawing::Size(199, 164);
			this->diseaseLabel->TabIndex = 34;
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
			this->ongoingTreatmentLabel->Location = System::Drawing::Point(21, 640);
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
			// MyPatientData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(89)), 
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(1411, 949);
			this->Controls->Add(this->patientLabel);
			this->Controls->Add(this->ongoingTreatmentLabel);
			this->Controls->Add(this->diseaseLabel);
			this->Controls->Add(this->birthdayLabel);
			this->Controls->Add(this->socialNumberLabel);
			this->Controls->Add(this->genderLabel);
			this->Controls->Add(this->numberPatient);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->emailPatient);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->placeBirthdayPatient);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->namePatient);
			this->Controls->Add(this->genderPatient);
			this->Controls->Add(this->birthdayPatient);
			this->Controls->Add(this->addressPatient);
			this->Controls->Add(this->addressLabel);
			this->Controls->Add(this->socialNumberPatient);
			this->Controls->Add(this->placeBirthdayLabel);
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