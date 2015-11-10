#pragma once
#include "MyForm2.h"

namespace Projet2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Titre;
	protected: 


	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape1;
	private: System::Windows::Forms::PictureBox^  Picture;



	private: System::Windows::Forms::Button^  Found;

	private: System::Windows::Forms::Button^  Not_Found;

	private: System::Windows::Forms::GroupBox^  Patient;

	private: System::Windows::Forms::Label^  Titre2;
	private: System::Windows::Forms::GroupBox^  Informations;
	private: System::Windows::Forms::Button^  Record;





	private: System::Windows::Forms::TextBox^  NamePatient;




	private: System::Windows::Forms::TextBox^  Result;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: System::Windows::Forms::Button^  Try;


	private: System::ComponentModel::IContainer^  components;
	protected: 
	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Titre = (gcnew System::Windows::Forms::Label());
			this->lineShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->Picture = (gcnew System::Windows::Forms::PictureBox());
			this->Found = (gcnew System::Windows::Forms::Button());
			this->Not_Found = (gcnew System::Windows::Forms::Button());
			this->Patient = (gcnew System::Windows::Forms::GroupBox());
			this->Titre2 = (gcnew System::Windows::Forms::Label());
			this->Informations = (gcnew System::Windows::Forms::GroupBox());
			this->NamePatient = (gcnew System::Windows::Forms::TextBox());
			this->Result = (gcnew System::Windows::Forms::TextBox());
			this->Record = (gcnew System::Windows::Forms::Button());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
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
			this->Titre->Location = System::Drawing::Point(12, 19);
			this->Titre->Name = L"Titre";
			this->Titre->Size = System::Drawing::Size(327, 52);
			this->Titre->TabIndex = 0;
			this->Titre->Text = L"Medical Record";
			this->Titre->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// lineShape1
			// 
			this->lineShape1->Name = L"lineShape1";
			this->lineShape1->X1 = -8;
			this->lineShape1->X2 = 1433;
			this->lineShape1->Y1 = 52;
			this->lineShape1->Y2 = 52;
			this->lineShape1->Click += gcnew System::EventHandler(this, &MyForm::lineShape1_Click);
			// 
			// Picture
			// 
			this->Picture->Location = System::Drawing::Point(20, 37);
			this->Picture->Name = L"Picture";
			this->Picture->Size = System::Drawing::Size(427, 489);
			this->Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Picture->TabIndex = 2;
			this->Picture->TabStop = false;
			this->Picture->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// Found
			// 
			this->Found->Location = System::Drawing::Point(1110, 741);
			this->Found->Name = L"Found";
			this->Found->Size = System::Drawing::Size(135, 35);
			this->Found->TabIndex = 4;
			this->Found->Text = L"Test found";
			this->Found->UseVisualStyleBackColor = true;
			this->Found->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Not_Found
			// 
			this->Not_Found->Location = System::Drawing::Point(1264, 741);
			this->Not_Found->Name = L"Not_Found";
			this->Not_Found->Size = System::Drawing::Size(135, 35);
			this->Not_Found->TabIndex = 5;
			this->Not_Found->Text = L"Test Not found";
			this->Not_Found->UseVisualStyleBackColor = true;
			this->Not_Found->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// Patient
			// 
			this->Patient->Controls->Add(this->Picture);
			this->Patient->Location = System::Drawing::Point(21, 123);
			this->Patient->Name = L"Patient";
			this->Patient->Size = System::Drawing::Size(462, 551);
			this->Patient->TabIndex = 6;
			this->Patient->TabStop = false;
			this->Patient->Text = L"Patient";
			this->Patient->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// Titre2
			// 
			this->Titre2->AutoSize = true;
			this->Titre2->Location = System::Drawing::Point(325, 9);
			this->Titre2->Name = L"Titre2";
			this->Titre2->Size = System::Drawing::Size(31, 20);
			this->Titre2->TabIndex = 7;
			this->Titre2->Text = L"TM";
			this->Titre2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// Informations
			// 
			this->Informations->Controls->Add(this->Try);
			this->Informations->Controls->Add(this->NamePatient);
			this->Informations->Controls->Add(this->Result);
			this->Informations->Controls->Add(this->Record);
			this->Informations->Location = System::Drawing::Point(584, 123);
			this->Informations->Name = L"Informations";
			this->Informations->Size = System::Drawing::Size(784, 551);
			this->Informations->TabIndex = 3;
			this->Informations->TabStop = false;
			this->Informations->Text = L"Informations";
			this->Informations->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// NamePatient
			// 
			this->NamePatient->BackColor = System::Drawing::SystemColors::Control;
			this->NamePatient->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NamePatient->Cursor = System::Windows::Forms::Cursors::Default;
			this->NamePatient->Enabled = false;
			this->NamePatient->Location = System::Drawing::Point(50, 217);
			this->NamePatient->Name = L"NamePatient";
			this->NamePatient->ReadOnly = true;
			this->NamePatient->Size = System::Drawing::Size(683, 19);
			this->NamePatient->TabIndex = 12;
			this->NamePatient->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Result
			// 
			this->Result->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Result->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Result->Enabled = false;
			this->Result->ForeColor = System::Drawing::Color::Black;
			this->Result->Location = System::Drawing::Point(50, 37);
			this->Result->Name = L"Result";
			this->Result->ReadOnly = true;
			this->Result->Size = System::Drawing::Size(683, 19);
			this->Result->TabIndex = 11;
			this->Result->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Record
			// 
			this->Record->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Record->Location = System::Drawing::Point(50, 411);
			this->Record->Name = L"Record";
			this->Record->Size = System::Drawing::Size(683, 115);
			this->Record->TabIndex = 9;
			this->Record->Text = L"Try with another picture";
			this->Record->UseVisualStyleBackColor = true;
			this->Record->Visible = false;
			this->Record->Click += gcnew System::EventHandler(this, &MyForm::Record_or_try_Click);
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(0, 0);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->lineShape1});
			this->shapeContainer1->Size = System::Drawing::Size(1411, 788);
			this->shapeContainer1->TabIndex = 1;
			this->shapeContainer1->TabStop = false;
			// 
			// Try
			// 
			this->Try->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Try->Location = System::Drawing::Point(50, 411);
			this->Try->Name = L"Try";
			this->Try->Size = System::Drawing::Size(683, 115);
			this->Try->TabIndex = 13;
			this->Try->UseVisualStyleBackColor = true;
			this->Try->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1411, 788);
			this->Controls->Add(this->Informations);
			this->Controls->Add(this->Titre2);
			this->Controls->Add(this->Patient);
			this->Controls->Add(this->Not_Found);
			this->Controls->Add(this->Found);
			this->Controls->Add(this->Titre);
			this->Controls->Add(this->shapeContainer1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->EndInit();
			this->Patient->ResumeLayout(false);
			this->Informations->ResumeLayout(false);
			this->Informations->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void lineShape1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Match_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Picture->ImageLocation = L"C:/Users/DSi_5/Desktop/Projet2/img0.jpg";
			this->Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Result->Text = L"Match Found";
			this->Result->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->NamePatient->Text = L"Inès Frebault";
			this->NamePatient->BackColor = System::Drawing::Color::White;
			this->NamePatient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Record->Text = L"Show medical record";
			this->Record->Visible = true;
			this->Try->Visible = false;
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Picture->ImageLocation = L"C:/Users/DSi_5/Desktop/Projet2/not_found.png";
			this->Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Result->Text = L"Match Not Found";
			this->NamePatient->Text = L"";
			this->Result->BackColor = System::Drawing::Color::LightCoral;
			this->NamePatient->BackColor = System::Drawing::SystemColors::Control;
			 this->Try->Text = L"Try with another picture";
			 this->Record->Visible = false;
			 this->Try->Visible = true;
			 
		 }
private: System::Void bindingNavigator1_RefreshItems(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Record_or_try_Click(System::Object^  sender, System::EventArgs^  e) {
			Projet2::MyForm2 form2;
			form2.ShowDialog();
		 }
};
}
