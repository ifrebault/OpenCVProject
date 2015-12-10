#ifndef FIRST_H_INCLUDED
#define FIRST_H_INCLUDED

#pragma once
#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#using <System.Data.dll> 
#using <System.Drawing.dll>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "patient_found.h"
#include "not_found.h"

namespace myOpenCV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;

	public ref class MyIndex : public System::Windows::Forms::Form	{
	public:
		MyIndex(void){
			capture = 0;   
			cameraFrame = 0;

			InitializeComponent();
		}

		~MyIndex(){
			if (components){delete components; }
			if(capture){ delete capture; }
			if(cameraFrame){ delete cameraFrame; }
		}
	System::Windows::Forms::Label^  titre;
	System::Windows::Forms::Label^  titre2;
	System::Windows::Forms::Label^  taken;
	System::Windows::Forms::Button^  picture;
	System::Windows::Forms::Button^  camera;
	System::Windows::Forms::Button^  load;

		VideoCapture* capture;   				
		Mat* cameraFrame;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->load = (gcnew System::Windows::Forms::Button());
			this->titre = (gcnew System::Windows::Forms::Label());
			this->titre2 = (gcnew System::Windows::Forms::Label());
			this->taken = (gcnew System::Windows::Forms::Label());
			this->picture = (gcnew System::Windows::Forms::Button());
			this->camera = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Titre
			// 
			this->titre->AutoSize = true;
			this->titre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->titre->ForeColor = System::Drawing::Color::White;
			this->titre->Location = System::Drawing::Point(12, 20);
			this->titre->Name = L"Titre";
			this->titre->Size = System::Drawing::Size(327, 52);
			this->titre->TabIndex = 1;
			this->titre->Text = L"Medical Record";
			// 
			// Titre2
			// 
			this->titre2->AutoSize = true;
			this->titre2->ForeColor = System::Drawing::Color::Transparent;
			this->titre2->Location = System::Drawing::Point(326, 9);
			this->titre2->Name = L"Titre2";
			this->titre2->Size = System::Drawing::Size(31, 20);
			this->titre2->TabIndex = 8;
			this->titre2->Text = L"TM";
			// 
			// Taken
			// 
			this->taken->AutoSize = true;
			this->taken->BackColor = System::Drawing::Color::Transparent;
			this->taken->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->taken->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->taken->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->taken->Location = System::Drawing::Point(21, 228);
			this->taken->Name = L"Taken";
			this->taken->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->taken->Size = System::Drawing::Size(245, 49);
			this->taken->TabIndex = 24;
			this->taken->Text = L"Taken a picture";
			// 
			// picture
			// 
			this->picture->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->picture->Location = System::Drawing::Point(21, 280);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(239, 59);
			this->picture->TabIndex = 26;
			this->picture->Text = L"Picture";
			this->picture->UseVisualStyleBackColor = true;
			this->picture->Click += gcnew System::EventHandler(this, &MyIndex::picture_Click);
			// 
			// camera
			// 
			this->camera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->camera->Location = System::Drawing::Point(21, 138);
			this->camera->Name = L"camera";
			this->camera->Size = System::Drawing::Size(239, 59);
			this->camera->TabIndex = 27;
			this->camera->Text = L"Camera";
			this->camera->UseVisualStyleBackColor = true;
			this->camera->Click += gcnew System::EventHandler(this, &MyIndex::camera_Click);


			this->load->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->load->Location = System::Drawing::Point(511, 280);
			this->load->Name = L"button1";
			this->load->Size = System::Drawing::Size(239, 59);
			this->load->TabIndex = 29;
			this->load->Text = L"Load";
			this->load->UseVisualStyleBackColor = true;
			this->load->Visible = false;
			this->load->Click += gcnew System::EventHandler(this, &MyIndex::button1_Click);
			// 
			// MyIndex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(89)), 
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(799, 401);
			this->Controls->Add(this->camera);
			this->Controls->Add(this->picture);
			this->Controls->Add(this->taken);
			this->Controls->Add(this->titre2);
			this->Controls->Add(this->titre);
			this->Controls->Add(this->load);
			this->Name = L"MyIndex";
			this->Text = L"MyIndex";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Void camera_Click(System::Object^  sender, System::EventArgs^  e) {
			if(capture == 0) {
				capture = new VideoCapture(0);
				cameraFrame = new Mat();
			}
			
			while (true) {
				capture->read(*cameraFrame);
				imshow("CameraFrame", *cameraFrame);
				waitKey(30);
			}
		 }

	Void picture_Click(System::Object^  sender, System::EventArgs^  e) {
			if(capture == 0) {
				capture = new VideoCapture(0);
				cameraFrame = new Mat();
			}
			string str = "../imgTemp/imgTemp.jpg";
			capture->read(*cameraFrame); 
			imwrite(str, *cameraFrame);
			this->load->Visible = true;
		 }
 
	Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			//ICI LE TRAITEMENT

			///////////////////////////

			int i = 1;
			if(i == 1){
				myOpenCV30::MyPatientFound form;
				form.ShowDialog();
			}

			if(i == 2){
				myOpenCV30::MyNotFound form;
				form.ShowDialog();
			}
		 }
};
}


#endif // FIRST_H_INCLUDED
