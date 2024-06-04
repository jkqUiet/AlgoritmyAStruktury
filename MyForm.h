#pragma once

#include "Kriteria/UJPodmienene/Pobyv.h"
#include "Filtrovac.h"
#include "Manager.h"
#include <string>
#include <iostream>

#include "Filtre/FInterval.h"
#include "Filtre/FTyp.h"
#include "Filtre/FHodnota.h"
#include "Filtre/FPrislusnost.h"
#include "UniverzalnyFilter.h"

#include "Kriteria/UJPodmienene/Nazov.h"
#include "Kriteria/UJPodmienene/Pobyv.h"
#include "Kriteria/UJPodmienene/Typ.h"
#include "Kriteria/UJPodmienene/Zastavanost.h"
#include "Kriteria/UJPodmienene/Prislusnost.h"
#include "Triedenie.h"

namespace AUSsemestralka2 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Nazov* KritNazov = new Nazov();
		Pobyv* KritPObyv = new Pobyv();
		Zastavanost* KritZastav = new Zastavanost();
		Typ* KritTyp = new Typ();
		Prislusnost* KritPrislusnost = new Prislusnost();

	private: System::Windows::Forms::ToolStripMenuItem^ vyfiltrujToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ odoberFilterToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ vyberTriedenie;
	private: System::Windows::Forms::ComboBox^ vyberKriteriumTriedenia;
	private: System::Windows::Forms::Label^ label4;







		   Manager* manager;
	public:
		MyForm(Manager* man)
		{
			InitializeComponent();
			inicializujTabulky();
			manager = man;
			manager->manazuj();
			pridajJednotky(-1);
			zobFiltre->Columns->Add("Column", "Filter");

			vyberTriedenie->Items->Add("Zostupne");
			vyberTriedenie->Items->Add("Vzostupne");

			vyberKriteriumTriedenia->Items->Add("Nazov");
			vyberKriteriumTriedenia->Items->Add("PObyvatelov");
			vyberKriteriumTriedenia->Items->Add("Zastavanost");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			if (KritNazov != nullptr) {
				delete KritNazov;
				KritNazov = nullptr;
				delete KritPObyv;
				KritPObyv = nullptr;
				delete KritZastav;
				KritZastav = nullptr;
				delete KritTyp;
				KritTyp = nullptr;
				delete KritPrislusnost;
				KritPrislusnost = nullptr;
			}
		}

	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ pridajFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ názovToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ potNazov;
	private: System::Windows::Forms::ToolStripMenuItem^ početObyvateľovToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ obyvMax;
	private: System::Windows::Forms::ToolStripTextBox^ obyvMin;
	private: System::Windows::Forms::ToolStripMenuItem^ potPObyv;
	private: System::Windows::Forms::ToolStripMenuItem^ zastavanosťToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ zastMax;
	private: System::Windows::Forms::ToolStripTextBox^ zastMin;
	private: System::Windows::Forms::ToolStripMenuItem^ potZastavan;
	private: System::Windows::Forms::ToolStripMenuItem^ typToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^ vyberTyp;
	private: System::Windows::Forms::ToolStripMenuItem^ potTyp;
	private: System::Windows::Forms::ToolStripMenuItem^ prislušnosťToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ potPrislusnost;
	private: System::Windows::Forms::DataGridView^ zobFiltre;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^ vycistiFiltreToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent()
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->pridajFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->názovToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->potNazov = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->početObyvateľovToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->obyvMax = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->obyvMin = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->potPObyv = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zastavanosťToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zastMax = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->zastMin = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->potZastavan = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->typToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vyberTyp = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->potTyp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prislušnosťToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox2 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->potPrislusnost = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vyfiltrujToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->odoberFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vycistiFiltreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zobFiltre = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->vyberTriedenie = (gcnew System::Windows::Forms::ComboBox());
			this->vyberKriteriumTriedenia = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zobFiltre))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Gray;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Left;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->pridajFilterToolStripMenuItem,
					this->vyfiltrujToolStripMenuItem, this->odoberFilterToolStripMenuItem, this->vycistiFiltreToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->menuStrip1->Size = System::Drawing::Size(143, 530);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// pridajFilterToolStripMenuItem
			// 
			this->pridajFilterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->názovToolStripMenuItem,
					this->početObyvateľovToolStripMenuItem, this->zastavanosťToolStripMenuItem, this->typToolStripMenuItem, this->prislušnosťToolStripMenuItem
			});
			this->pridajFilterToolStripMenuItem->Name = L"pridajFilterToolStripMenuItem";
			this->pridajFilterToolStripMenuItem->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->pridajFilterToolStripMenuItem->Size = System::Drawing::Size(130, 32);
			this->pridajFilterToolStripMenuItem->Text = L"Pridaj Filter";
			// 
			// názovToolStripMenuItem
			// 
			this->názovToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->názovToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripTextBox1,
					this->potNazov
			});
			this->názovToolStripMenuItem->Name = L"názovToolStripMenuItem";
			this->názovToolStripMenuItem->Size = System::Drawing::Size(236, 32);
			this->názovToolStripMenuItem->Text = L"Názov";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->BackColor = System::Drawing::Color::Silver;
			this->toolStripTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 23);
			this->toolStripTextBox1->ToolTipText = L"Nazov UJ";
			// 
			// potNazov
			// 
			this->potNazov->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->potNazov->Name = L"potNazov";
			this->potNazov->Size = System::Drawing::Size(160, 32);
			this->potNazov->Text = L"Potvrdiť";
			this->potNazov->Click += gcnew System::EventHandler(this, &MyForm::potNazov_Click);
			// 
			// početObyvateľovToolStripMenuItem
			// 
			this->početObyvateľovToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->početObyvateľovToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->obyvMax,
					this->obyvMin, this->potPObyv
			});
			this->početObyvateľovToolStripMenuItem->Name = L"početObyvateľovToolStripMenuItem";
			this->početObyvateľovToolStripMenuItem->Size = System::Drawing::Size(236, 32);
			this->početObyvateľovToolStripMenuItem->Text = L"Počet obyvateľov";
			// 
			// obyvMax
			// 
			this->obyvMax->BackColor = System::Drawing::Color::Silver;
			this->obyvMax->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->obyvMax->Name = L"obyvMax";
			this->obyvMax->Size = System::Drawing::Size(100, 23);
			this->obyvMax->ToolTipText = L"Maximalny pocet";
			// 
			// obyvMin
			// 
			this->obyvMin->BackColor = System::Drawing::Color::Silver;
			this->obyvMin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->obyvMin->Name = L"obyvMin";
			this->obyvMin->Size = System::Drawing::Size(100, 23);
			this->obyvMin->ToolTipText = L"Minimalny pocet";
			// 
			// potPObyv
			// 
			this->potPObyv->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->potPObyv->Name = L"potPObyv";
			this->potPObyv->Size = System::Drawing::Size(160, 32);
			this->potPObyv->Text = L"Potvrdiť";
			this->potPObyv->Click += gcnew System::EventHandler(this, &MyForm::potPObyv_Click);
			// 
			// zastavanosťToolStripMenuItem
			// 
			this->zastavanosťToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->zastavanosťToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->zastMax,
					this->zastMin, this->potZastavan
			});
			this->zastavanosťToolStripMenuItem->Name = L"zastavanosťToolStripMenuItem";
			this->zastavanosťToolStripMenuItem->Size = System::Drawing::Size(236, 32);
			this->zastavanosťToolStripMenuItem->Text = L"Zastavanosť";
			// 
			// zastMax
			// 
			this->zastMax->BackColor = System::Drawing::Color::Silver;
			this->zastMax->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->zastMax->Name = L"zastMax";
			this->zastMax->Size = System::Drawing::Size(100, 23);
			this->zastMax->ToolTipText = L"Maximalna zastavanost";
			// 
			// zastMin
			// 
			this->zastMin->BackColor = System::Drawing::Color::Silver;
			this->zastMin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->zastMin->Name = L"zastMin";
			this->zastMin->Size = System::Drawing::Size(100, 23);
			this->zastMin->ToolTipText = L"Minimalna zastavanost";
			// 
			// potZastavan
			// 
			this->potZastavan->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->potZastavan->Name = L"potZastavan";
			this->potZastavan->Size = System::Drawing::Size(160, 32);
			this->potZastavan->Text = L"Potvrdiť";
			this->potZastavan->Click += gcnew System::EventHandler(this, &MyForm::potZastavan_Click);
			// 
			// typToolStripMenuItem
			// 
			this->typToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->typToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->vyberTyp,
					this->potTyp
			});
			this->typToolStripMenuItem->Name = L"typToolStripMenuItem";
			this->typToolStripMenuItem->Size = System::Drawing::Size(236, 32);
			this->typToolStripMenuItem->Text = L"Typ";
			// 
			// vyberTyp
			// 
			this->vyberTyp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->vyberTyp->Name = L"vyberTyp";
			this->vyberTyp->Size = System::Drawing::Size(121, 23);
			this->vyberTyp->ToolTipText = L"Vyber typu";
			this->vyberTyp->Click += gcnew System::EventHandler(this, &MyForm::vyberTyp_Click);
			// 
			// potTyp
			// 
			this->potTyp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->potTyp->Name = L"potTyp";
			this->potTyp->Size = System::Drawing::Size(181, 32);
			this->potTyp->Text = L"Potvrdiť";
			this->potTyp->Click += gcnew System::EventHandler(this, &MyForm::potTyp_Click);
			// 
			// prislušnosťToolStripMenuItem
			// 
			this->prislušnosťToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->prislušnosťToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripTextBox2,
					this->potPrislusnost
			});
			this->prislušnosťToolStripMenuItem->Name = L"prislušnosťToolStripMenuItem";
			this->prislušnosťToolStripMenuItem->Size = System::Drawing::Size(236, 32);
			this->prislušnosťToolStripMenuItem->Text = L"Prislušnosť";
			// 
			// toolStripTextBox2
			// 
			this->toolStripTextBox2->BackColor = System::Drawing::Color::Silver;
			this->toolStripTextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox2->Name = L"toolStripTextBox2";
			this->toolStripTextBox2->Size = System::Drawing::Size(100, 23);
			this->toolStripTextBox2->ToolTipText = L"Nazov UJ do ktorej ma patrit";
			// 
			// potPrislusnost
			// 
			this->potPrislusnost->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->potPrislusnost->Name = L"potPrislusnost";
			this->potPrislusnost->Size = System::Drawing::Size(160, 32);
			this->potPrislusnost->Text = L"Potvrdiť";
			this->potPrislusnost->Click += gcnew System::EventHandler(this, &MyForm::potPrislusnost_Click);
			// 
			// vyfiltrujToolStripMenuItem
			// 
			this->vyfiltrujToolStripMenuItem->Name = L"vyfiltrujToolStripMenuItem";
			this->vyfiltrujToolStripMenuItem->Size = System::Drawing::Size(130, 32);
			this->vyfiltrujToolStripMenuItem->Text = L"Vyfiltruj";
			this->vyfiltrujToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::vyfiltrujToolStripMenuItem_Click);
			// 
			// odoberFilterToolStripMenuItem
			// 
			this->odoberFilterToolStripMenuItem->Name = L"odoberFilterToolStripMenuItem";
			this->odoberFilterToolStripMenuItem->Size = System::Drawing::Size(130, 32);
			this->odoberFilterToolStripMenuItem->Text = L"Odober filter";
			this->odoberFilterToolStripMenuItem->ToolTipText = L"Odoberie posledne pridany filter";
			this->odoberFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::odoberFilterToolStripMenuItem_Click);
			// 
			// vycistiFiltreToolStripMenuItem
			// 
			this->vycistiFiltreToolStripMenuItem->Name = L"vycistiFiltreToolStripMenuItem";
			this->vycistiFiltreToolStripMenuItem->Size = System::Drawing::Size(130, 32);
			this->vycistiFiltreToolStripMenuItem->Text = L"Vycisti filtre";
			this->vycistiFiltreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::vycistiFiltreToolStripMenuItem_Click);
			// 
			// zobFiltre
			// 
			this->zobFiltre->AllowUserToAddRows = false;
			this->zobFiltre->AllowUserToDeleteRows = false;
			this->zobFiltre->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->zobFiltre->BackgroundColor = System::Drawing::Color::DimGray;
			this->zobFiltre->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->zobFiltre->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::LimeGreen;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::Desktop;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->zobFiltre->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->zobFiltre->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::WindowFrame;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::LimeGreen;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::Desktop;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->zobFiltre->DefaultCellStyle = dataGridViewCellStyle2;
			this->zobFiltre->GridColor = System::Drawing::Color::Black;
			this->zobFiltre->Location = System::Drawing::Point(0, 195);
			this->zobFiltre->Name = L"zobFiltre";
			this->zobFiltre->ReadOnly = true;
			this->zobFiltre->RightToLeft = System::Windows::Forms::RightToLeft::No;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->zobFiltre->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->zobFiltre->RowHeadersWidth = 10;
			this->zobFiltre->Size = System::Drawing::Size(239, 335);
			this->zobFiltre->TabIndex = 10;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::DimGray;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::LimeGreen;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::Desktop;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::LightGreen;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(245, 55);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::LimeGreen;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::Desktop;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView1->RowHeadersWidth = 15;
			this->dataGridView1->Size = System::Drawing::Size(796, 475);
			this->dataGridView1->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightGray;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(-1, 157);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 35);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Nastavene Filtre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkGray;
			this->label2->Location = System::Drawing::Point(238, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(311, 37);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Vyfiltrovane vysledky";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Silver;
			this->label3->Location = System::Drawing::Point(815, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 20);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Zoradenie ";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Honeydew;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(946, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 40);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Utrieďiť";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// vyberTriedenie
			// 
			this->vyberTriedenie->BackColor = System::Drawing::Color::LightGreen;
			this->vyberTriedenie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vyberTriedenie->FormattingEnabled = true;
			this->vyberTriedenie->Location = System::Drawing::Point(819, 24);
			this->vyberTriedenie->Name = L"vyberTriedenie";
			this->vyberTriedenie->Size = System::Drawing::Size(121, 29);
			this->vyberTriedenie->TabIndex = 17;
			// 
			// vyberKriteriumTriedenia
			// 
			this->vyberKriteriumTriedenia->BackColor = System::Drawing::Color::LightGreen;
			this->vyberKriteriumTriedenia->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vyberKriteriumTriedenia->FormattingEnabled = true;
			this->vyberKriteriumTriedenia->Location = System::Drawing::Point(692, 24);
			this->vyberKriteriumTriedenia->Name = L"vyberKriteriumTriedenia";
			this->vyberKriteriumTriedenia->Size = System::Drawing::Size(121, 29);
			this->vyberKriteriumTriedenia->TabIndex = 18;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Silver;
			this->label4->Location = System::Drawing::Point(689, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 18);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Kriterium triedenia";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1053, 530);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->vyberKriteriumTriedenia);
			this->Controls->Add(this->vyberTriedenie);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->zobFiltre);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"Aplikacia";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zobFiltre))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void potNazov_Click(System::Object^ sender, System::EventArgs^ e) {
		string text;
		MarshalString(toolStripTextBox1->Text, text);
		UniverzalnyFilter<JednotkaUzemna*>* filter = new FHodnota<string, JednotkaUzemna*, string>(KritNazov, text);
		manager->pridajFilter(filter);
		pridajFilter("Nazov : " + toolStripTextBox1->Text);

	}

	private: System::Void potPObyv_Click(System::Object^ sender, System::EventArgs^ e) {
		int pObyvMax = System::Convert::ToInt32(obyvMax->Text);
		int pObyvMin = System::Convert::ToInt32(obyvMin->Text);

		UniverzalnyFilter<JednotkaUzemna*>* filter = new FInterval<string, JednotkaUzemna*, int>(KritPObyv, pObyvMin, pObyvMax);
		manager->pridajFilter(filter);
		pridajFilter("PObyv : <" + obyvMin->Text + " , " + obyvMax->Text + ">");
	}

	private: System::Void potZastavan_Click(System::Object^ sender, System::EventArgs^ e) {

		int pZastavMax = System::Convert::ToInt32(zastMax->Text);
		int pZastavMin = System::Convert::ToInt32(zastMin->Text);

		UniverzalnyFilter<JednotkaUzemna*>* filter = new FInterval<string, JednotkaUzemna*, double>(KritZastav, pZastavMin, pZastavMax);
		manager->pridajFilter(filter);
		String^ text = "Zast : <" + zastMin->Text + " , " + zastMax->Text + ">";
		pridajFilter(text);
	}

	private: System::Void potTyp_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ var = vyberTyp->Text;
		String^ text = "Typ : " + var;
		if (var == "Obec") {
			UniverzalnyFilter<JednotkaUzemna*>* filter = new FTyp<string, JednotkaUzemna*, UJTyp>(KritTyp, UJTyp::Obec);
			manager->pridajFilter(filter);
			pridajFilter(text);
		}
		if (var == "Slovensko") {
			UniverzalnyFilter<JednotkaUzemna*>* filter = new FTyp<string, JednotkaUzemna*, UJTyp>(KritTyp, UJTyp::Slovensko);
			manager->pridajFilter(filter);
			pridajFilter(text);
		}
		if (var == "Okres") {
			UniverzalnyFilter<JednotkaUzemna*>* filter = new FTyp<string, JednotkaUzemna*, UJTyp>(KritTyp, UJTyp::Okres);
			manager->pridajFilter(filter);
			pridajFilter(text);
		}
		if (var == "Kraj") {
			UniverzalnyFilter<JednotkaUzemna*>* filter = new FTyp<string, JednotkaUzemna*, UJTyp>(KritTyp, UJTyp::Kraj);
			manager->pridajFilter(filter);
			pridajFilter(text);
		}
	}

	private: System::Void potPrislusnost_Click(System::Object^ sender, System::EventArgs^ e) {
		string text;
		MarshalString(toolStripTextBox2->Text, text);
		JednotkaUzemna* var = nullptr; var = manager->vyhladajJednotku(text);
		if (var != nullptr) {
			KritPrislusnost->setHore(var);
			UniverzalnyFilter<JednotkaUzemna*>* filter = new FPrislusnost<string, JednotkaUzemna*>(KritPrislusnost, true);
			manager->pridajFilter(filter);
			pridajFilter("Prislus : " + toolStripTextBox2->Text);
		}
	}

	private: System::Void vyberTyp_Click(System::Object^ sender, System::EventArgs^ e) {
		vyberTyp->Items->Clear();
		vyberTyp->Items->Add("Obec");
		vyberTyp->Items->Add("Okres");
		vyberTyp->Items->Add("Kraj");
		vyberTyp->Items->Add("Slovensko");
	}

	private: System::Void vycistiFiltreToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		zobFiltre->Rows->Clear();
		manager->clearniFiltrovane();
		manager->vycistiFiltre();
		manager->manazuj();
		pridajJednotky(-1);
	}

	private: void pridajFilter(String^ parameter) {
		zobFiltre->Rows->Add();
		zobFiltre->Rows[zobFiltre->RowCount - 1]->Cells[0]->Value = parameter;
	}

	private: void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: void MarshalString(String^ s, wstring& os) {
		using namespace Runtime::InteropServices;
		const wchar_t* chars =
			(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: void inicializujTabulky() {
		dataGridView1->Columns->Add("Column", "Nazov");
		dataGridView1->Columns->Add("Column", "Pris : Okres");
		dataGridView1->Columns->Add("Column", "Pris : Kraj");
		dataGridView1->Columns->Add("Column", "Pris : Stat");

		dataGridView1->Columns->Add("Column", "Pocet obyvatelov");
		dataGridView1->Columns->Add("Column", "Preproduktivni");
		dataGridView1->Columns->Add("Column", "Produktivni");
		dataGridView1->Columns->Add("Column", "Poproduktivni");
		dataGridView1->Columns->Add("Column", "Zastavanost");
		dataGridView1->Columns->Add("Column", "Cekova vymera");
		dataGridView1->Columns->Add("Column", "Zastavna plocha");

	}
	private: void pridajStlpec(int stlpec) {
		dataGridView1->Columns->Add("Columns", "Nazov");
		switch (stlpec) {
		case 1 : dataGridView1->Columns->Add("Columns", "Vysledok Krit : Nazov");
			break;
		case 2 : dataGridView1->Columns->Add("Columns", "Vysledok Krit : PObyv");
			break;
		case 3 : dataGridView1->Columns->Add("Columns", "Vysledok Krit : Zastavanost"); 
			break;
		}
	}
	private: void pridajJednotky(int triedSpec) {
		dataGridView1->Rows->Clear();
		structures::ArrayList<JednotkaUzemna*>* var = manager->getJednotkyFiltrovane();
		
		if (triedSpec != -1) {
			dataGridView1->Columns->Clear();
			dataGridView1->Refresh();
			pridajStlpec(triedSpec);

			for (auto a : *var) {
				dataGridView1->Rows->Add();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[0]->Value =
					gcnew String(a->getNazov().c_str());
				switch (triedSpec) {
				case 1: {														
					dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[1]->Value =
						gcnew String(a->getNazov().c_str());
					break;
				}
				case 2: {							
					dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[1]->Value = a->getPocetObyvatelov();
					break;
				}
				case 3: {								
					dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[1]->Value = a->getZastavanost();
					break;
				}
				}
			}
		}
		else {
			dataGridView1->Columns->Clear();
			dataGridView1->Refresh();
			inicializujTabulky();
			for (auto a : *var) {
				dataGridView1->Rows->Add();
				String^ nazov = gcnew String(a->getNazov().c_str());
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[0]->Value = nazov;
				JednotkaUzemna* varJed = nullptr;
				int index = 0;
				if (a->getTenNadomnou() != nullptr) {
					varJed = a->getTenNadomnou();
					index = getStartIndex(a);
				}
				while (varJed != nullptr) {
					dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[index]->Value = gcnew String(varJed->getNazov().c_str());
					varJed = varJed->getTenNadomnou();
					index++;
				}

				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[4]->Value = a->getPocetObyvatelov();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[5]->Value = a->getPreProd();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[6]->Value = a->getProd();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[7]->Value = a->getPoProd();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[8]->Value = a->getZastavanost();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[9]->Value = a->getVymera();
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[10]->Value = a->getZastavne();

			}
		}
	}

	private: int getStartIndex(JednotkaUzemna* jed) {
		switch (jed->getTyp()) {
		case UJTyp::Obec: return 1;
		case UJTyp::Okres: return 2;
		case UJTyp::Kraj: return 3;
		default: return -1;
		}
	}
	
	private: System::Void vyfiltrujToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		manager->clearniFiltrovane();
		manager->manazuj();
		pridajJednotky(-1);

	}
	private: System::Void odoberFilterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		manager->odoberFilter();
		if (zobFiltre->RowCount > 0) {
			zobFiltre->Rows->RemoveAt(zobFiltre->RowCount - 1);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		bool typTriedenia = false;
		
		if (vyberTriedenie->Text == "Zostupne") {
			typTriedenia = true;
		} 
		if (vyberTriedenie->Text == "Vzostupne") {
			typTriedenia = false;
		}	
		int identifikator = 0;
		if (vyberKriteriumTriedenia->Text == "Nazov") {
			Triedenie<JednotkaUzemna*, string>* triedenie = new Triedenie<JednotkaUzemna*, string>();
			triedenie->utried(manager->getJednotkyFiltrovane(), KritNazov, typTriedenia);
			delete triedenie;
			identifikator = 1;
		}
		if (vyberKriteriumTriedenia->Text == "PObyvatelov") {
			Triedenie<JednotkaUzemna*, int>* triedenie = new Triedenie<JednotkaUzemna*, int>();
			triedenie->utried(manager->getJednotkyFiltrovane(), KritPObyv, typTriedenia);
			delete triedenie;
			identifikator = 2;
		}
		if (vyberKriteriumTriedenia->Text == "Zastavanost") {
			Triedenie<JednotkaUzemna*, double>* triedenie = new Triedenie<JednotkaUzemna*, double>();
			triedenie->utried(manager->getJednotkyFiltrovane(), KritZastav, typTriedenia);
			delete triedenie;
			identifikator = 3;
		}
		pridajJednotky(identifikator);
	}
};
}

