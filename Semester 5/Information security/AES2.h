#pragma once
#include<vcclr.h>
#include <stdio.h>
#include <stdlib.h>
namespace aes2 {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// The number of columns comprising a state in AES. This is a constant in AES. Value=4
#define Nb 4
	// xtime is a macro that finds the product of {02} and the argument to xtime modulo {1b}
#define xtime(x)   ((x<<1) ^ (((x>>7) & 1) * 0x1b))
	// Multiplty is a macro used to multiply numbers in the field GF(2^8)
#define Multiply(x,y) (((y & 1) * x) ^ ((y>>1 & 1) * xtime(x)) ^ ((y>>2 & 1) * xtime(xtime(x))) ^ ((y>>3 & 1) * xtime(xtime(xtime(x)))) ^ ((y>>4 & 1) * xtime(xtime(xtime(xtime(x))))))
	// The number of rounds in AES Cipher. It is simply initiated to zero. The actual value is recieved in the program.
	int Nr=0;
	// The number of 32 bit words in the key. It is simply initiated to zero. The actual value is recieved in the program.
	int Nk=0;
	// in – it is the array that holds the CipherText to be decrypted.
	// out – it is the array that holds the output of the for decryption.
	// state – the array that holds the intermediate results during decryption.
	unsigned char inE[16], inD[16], outE[16], outD[16], state[4][4];
	// The array that stores the round keys.
	unsigned char RoundKey[240];
	// The Key input to the AES Program
	unsigned char Key[32];
	// The round constant word array, Rcon[i], contains the values given by
	// x to th e power (i-1) being powers of x (x is denoted as {02}) in the field GF(2^8)
	// Note that i starts at 1, not 0).
	int Rcon[255] = {
		0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
		0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
		0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
		0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
		0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
		0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
		0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
		0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
		0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
		0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
		0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
		0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
		0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
		0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
		0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
		0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb
	};
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox2;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton6);
			this->groupBox2->Controls->Add(this->radioButton5);
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox2->ForeColor = System::Drawing::Color::Brown;
			this->groupBox2->Location = System::Drawing::Point(384, 22);
			this->groupBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox2->Size = System::Drawing::Size(351, 285);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Decryption";
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(191, 130);
			this->radioButton6->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(63, 34);
			this->radioButton6->TabIndex = 10;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"256";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(100, 130);
			this->radioButton5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(64, 34);
			this->radioButton5->TabIndex = 10;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"192";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Location = System::Drawing::Point(11, 130);
			this->radioButton4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(64, 34);
			this->radioButton4->TabIndex = 10;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"128";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(11, 174);
			this->button2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(329, 42);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Decrypt it";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Harrington", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(11, 40);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 22);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Text";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Harrington", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(11, 88);
			this->label5->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 22);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Key";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Harrington", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(11, 234);
			this->label6->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 22);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Dec";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox4->Location = System::Drawing::Point(87, 34);
			this->textBox4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(250, 37);
			this->textBox4->TabIndex = 2;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox5->Location = System::Drawing::Point(87, 82);
			this->textBox5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(250, 37);
			this->textBox5->TabIndex = 1;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox6->Location = System::Drawing::Point(87, 230);
			this->textBox6->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(250, 37);
			this->textBox6->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Papyrus", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::Brown;
			this->groupBox1->Location = System::Drawing::Point(22, 22);
			this->groupBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox1->Size = System::Drawing::Size(351, 285);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Encryption";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(197, 130);
			this->radioButton3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(63, 34);
			this->radioButton3->TabIndex = 9;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"256";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(106, 130);
			this->radioButton2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(64, 34);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"192";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(16, 130);
			this->radioButton1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(64, 34);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"128";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(16, 174);
			this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(323, 42);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Encrypt it";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Harrington", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(11, 234);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 22);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Enc";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Harrington", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(11, 88);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Key";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Harrington", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(11, 40);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Text";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox3->Location = System::Drawing::Point(87, 230);
			this->textBox3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(250, 37);
			this->textBox3->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox2->Location = System::Drawing::Point(87, 82);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(250, 37);
			this->textBox2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox1->Location = System::Drawing::Point(87, 34);
			this->textBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(250, 37);
			this->textBox1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(747, 316);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"Form1";
			this->Text = L"AES";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i;
				 // Receive the length of key here.
				 if(radioButton1->Checked){
					 Nr=128;
				 }else if(radioButton2->Checked){
					 Nr=192;
				 }else if(radioButton3->Checked){
					 Nr=256;
				 }
				 // Calculate Nk and Nr from the received value.
				 Nk = Nr / 32;
				 Nr = Nk + 6;
				 // The array temp stores the key.
				 // The array temp2 stores the plaintext.
				 unsigned char * temp = new unsigned char[textBox2->TextLength];
				 System::String^ userinput=textBox2->Text;
				 interior_ptr<const Char> ppchar = PtrToStringChars(userinput);  
				 for (int i=0; *ppchar != L'\0'; ++ppchar, i++){
					 temp[i]=*ppchar;
					 //Debug::WriteLine("1:");
					 //Debug::WriteLine(temp[i]);
				 }
				 unsigned char * temp2 = new unsigned char[textBox1->TextLength];
				 System::String^ userinput2=textBox1->Text;
				 interior_ptr<const Char> ppchar2 = PtrToStringChars(userinput2);
				 for (int i=0; *ppchar2 != L'\0'; ++ppchar2, i++){
					 temp2[i]=*ppchar2;
					 //Debug::WriteLine("2:");
					 //Debug::WriteLine(temp2[i]);
				 }
				 // Copy the Key and PlainText
				 for(i=0;i<textBox2->TextLength;i++){
					 Key[i]=temp[i];
					 Debug::WriteLine("KeyE:");
					 Debug::WriteLine(Key[i]);
				 }
				 for(i=0;i<textBox1->TextLength;i++){
					 inE[i]=temp2[i];
					 Debug::WriteLine("inE:");
					 Debug::WriteLine(inE[i]);
				 }
				 // The KeyExpansion routine must be called before encryption.
				 KeyExpansion();
				 // The next function call encrypts the PlainText with the Key using AES algorithm.
				 Cipher();
				 // Output the encrypted text.
				 //System::String ^ enc="";
				 //char buffer [1];
				 //for(i=0;i<Nk*4;i++){
				 //	itoa (out[i],buffer,1);
				 //	enc+=buffer;
				 //	//	printf("%02x ",out[i]);
				 //	Debug::WriteLine(buffer);
				 //}
				 //textBox3->Text=enc;
				 Debug::WriteLine("outE:");
				 Debug::WriteLine(outE[0]);
				 Debug::WriteLine(outE[1]);
				 Debug::WriteLine(outE[2]);
				 Debug::WriteLine(outE[3]);
				 Debug::WriteLine(outE[4]);
				 String^ clistr = gcnew String((const char*) outE);
				 textBox3->Text=clistr;
				 textBox4->Text=clistr;
				 delete temp;
				 delete temp2;
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i;
				 // Receive the length of key here.
				 if(radioButton4->Checked){
					 Nr=128;
				 }else if(radioButton5->Checked){
					 Nr=192;
				 }else if(radioButton6->Checked){
					 Nr=256;
				 }
				 // Calculate Nk and Nr from the received value.
				 Nk = Nr / 32;
				 Nr = Nk + 6;
				 // The array temp stores the key.
				 // The array temp2 stores the plaintext.
				 unsigned char * temp = new unsigned char[textBox5->TextLength];
				 System::String^ userinput=textBox5->Text;
				 interior_ptr<const Char> ppchar = PtrToStringChars(userinput);  
				 for (int i=0; *ppchar != L'\0'; ++ppchar, i++){
					 temp[i]=*ppchar;
					 //Debug::WriteLine(temp[i]);
				 }
				 unsigned char * temp2 = new unsigned char[textBox4->TextLength];
				 System::String^ userinput2=textBox4->Text;
				 interior_ptr<const Char> ppchar2 = PtrToStringChars(userinput2);
				 for (int i=0; *ppchar2 != L'\0'; ++ppchar2, i++){
					 temp2[i]=*ppchar2;
				 }
				 // Copy the Key and CipherText
				 for(i=0;i<textBox5->TextLength;i++){
					 Key[i]=temp[i];
					 Debug::WriteLine("KeyD:");
					 Debug::WriteLine(Key[i]);
				 }
				 /*
				 for(i=0;i<textBox4->TextLength;i++){
					 inD[i]=temp2[i];
					 Debug::WriteLine("inD:");
					 Debug::WriteLine(inD[i]);
				 }
				 */
				 for(i=0;i<16;i++){
					 inD[i]=outE[i];
					 Debug::WriteLine("inD:");
					 Debug::WriteLine(inD[i]);
				 }

				 //Recieve the Key from the user
				 //printf(“Enter the Key in hexadecimal: “);
				 //for(i=0;i<Nk*4;i++){
				 //	scanf(“%x”,&Key[i]);
				 //}
				 //printf(“Enter the CipherText in hexadecimal: “);
				 //for(i=0;i<Nb*4;i++){
				 //	scanf(“%x”,&in[i]);
				 //}
				 //The Key-Expansion routine must be called before the decryption routine.
				 KeyExpansion();
				 // The next function call decrypts the CipherText with the Key using AES algorithm.
				 InvCipher();
				 // Output the decrypted text.
				 /*printf(“\nText after decryption:\n”);
				 for(i=0;i<Nb*4;i++){
				 printf(“%02x “,out[i]);
				 }*/
				 /*System::String ^ dec="";
				 for(i=0;i<Nk*4;i++){
					 dec+=outD[i];
					 //	printf("%02x ",out[i]);
				 }*/
				 String^ clistr = gcnew String((const char*) outD);
				 textBox6->Text=clistr;
				 //textBox6->Text=dec;
				 delete temp;
				 delete temp2;
			 }

			 int getSBoxInvert(int num){
				 int rsbox[256] ={
					 0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
					 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
					 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
					 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
					 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
					 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
					 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
					 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
					 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
					 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
					 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
					 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
					 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
					 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
					 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
					 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
				 };
				 return rsbox[num];
			 }

			 int getSBoxValue(int num){
				 int sbox[256] = {
					 //0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
					 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
					 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
					 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
					 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
					 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
					 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
					 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
					 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
					 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
					 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
					 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
					 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
					 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
					 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
					 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
					 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
				 };
				 return sbox[num];
			 }
			 // This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.
			 void KeyExpansion(){
				 int i,j;
				 unsigned char temp[4],k;
				 // The first round key is the key itself.
				 for(i=0;i<Nk;i++){
					 RoundKey[i*4]=Key[i*4];
					 RoundKey[i*4+1]=Key[i*4+1];
					 RoundKey[i*4+2]=Key[i*4+2];
					 RoundKey[i*4+3]=Key[i*4+3];
				 }
				 // All other round keys are found from the previous round keys.
				 while (i < (Nb * (Nr+1))){
					 for(j=0;j<4;j++){
						 temp[j]=RoundKey[(i-1) * 4 + j];
					 }
					 if (i % Nk == 0){
						 // This function rotates the 4 bytes in a word to the left once.
						 // [a0,a1,a2,a3] becomes [a1,a2,a3,a0]
						 // Function RotWord()
						 {
							 k = temp[0];
							 temp[0] = temp[1];
							 temp[1] = temp[2];
							 temp[2] = temp[3];
							 temp[3] = k;
						 }
						 // SubWord() is a function that takes a four-byte input word and
						 // applies the S-box to each of the four bytes to produce an output word.
						 // Function Subword()
						 {
							 temp[0]=getSBoxValue(temp[0]);
							 temp[1]=getSBoxValue(temp[1]);
							 temp[2]=getSBoxValue(temp[2]);
							 temp[3]=getSBoxValue(temp[3]);
						 }
						 temp[0] =  temp[0] ^ Rcon[i/Nk];
					 }else if (Nk > 6 && i % Nk == 4){
						 // Function Subword()
						 {
							 temp[0]=getSBoxValue(temp[0]);
							 temp[1]=getSBoxValue(temp[1]);
							 temp[2]=getSBoxValue(temp[2]);
							 temp[3]=getSBoxValue(temp[3]);
						 }
					 }
					 RoundKey[i*4+0] = RoundKey[(i-Nk)*4+0] ^ temp[0];
					 RoundKey[i*4+1] = RoundKey[(i-Nk)*4+1] ^ temp[1];
					 RoundKey[i*4+2] = RoundKey[(i-Nk)*4+2] ^ temp[2];
					 RoundKey[i*4+3] = RoundKey[(i-Nk)*4+3] ^ temp[3];
					 i++;
				 }
			 }

			 // This function adds the round key to state.
			 // The round key is added to the state by an XOR function.
			 void AddRoundKey(int round){
				 int i,j;
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 state[j][i] ^= RoundKey[round * Nb * 4 + i * Nb + j];
					 }
				 }
			 }

			 // The SubBytes Function Substitutes the values in the
			 // state matrix with values in an S-box.
			 void InvSubBytes(){
				 int i,j;
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 state[i][j] = getSBoxInvert(state[i][j]);
					 }
				 }
			 }

			 // The ShiftRows() function shifts the rows in the state to the left.
			 // Each row is shifted with different offset.
			 // Offset = Row number. So the first row is not shifted.
			 void InvShiftRows(){
				 unsigned char temp;
				 // Rotate first row 1 columns to right
				 temp=state[1][3];
				 state[1][3]=state[1][2];
				 state[1][2]=state[1][1];
				 state[1][1]=state[1][0];
				 state[1][0]=temp;
				 // Rotate second row 2 columns to right
				 temp=state[2][0];
				 state[2][0]=state[2][2];
				 state[2][2]=temp;
				 temp=state[2][1];
				 state[2][1]=state[2][3];
				 state[2][3]=temp;
				 // Rotate third row 3 columns to right
				 temp=state[3][0];
				 state[3][0]=state[3][1];
				 state[3][1]=state[3][2];
				 state[3][2]=state[3][3];
				 state[3][3]=temp;
			 }

			 // MixColumns function mixes the columns of the state matrix.
			 // The method used to multiply may be difficult to understand for beginners.
			 // Please use the references to gain more information.
			 void InvMixColumns(){
				 int i;
				 unsigned char a,b,c,d;
				 for(i=0;i<4;i++){
					 a = state[0][i];
					 b = state[1][i];
					 c = state[2][i];
					 d = state[3][i];
					 state[0][i] = Multiply(a, 0x0e) ^ Multiply(b, 0x0b) ^ Multiply(c, 0x0d) ^ Multiply(d, 0x09);
					 state[1][i] = Multiply(a, 0x09) ^ Multiply(b, 0x0e) ^ Multiply(c, 0x0b) ^ Multiply(d, 0x0d);
					 state[2][i] = Multiply(a, 0x0d) ^ Multiply(b, 0x09) ^ Multiply(c, 0x0e) ^ Multiply(d, 0x0b);
					 state[3][i] = Multiply(a, 0x0b) ^ Multiply(b, 0x0d) ^ Multiply(c, 0x09) ^ Multiply(d, 0x0e);
				 }
			 }

			 // InvCipher is the main function that decrypts the CipherText.
			 void InvCipher(){
				 int i,j,round=0;
				 //Copy the input CipherText to state array.
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 state[j][i] = inD[i*4 + j];
					 }
				 }
				 // Add the First round key to the state before starting the rounds.
				 AddRoundKey(Nr);
				 // There will be Nr rounds.
				 // The first Nr-1 rounds are identical.
				 // These Nr-1 rounds are executed in the loop below.
				 for(round=Nr-1;round>0;round--){
					 InvShiftRows();
					 InvSubBytes();
					 AddRoundKey(round);
					 InvMixColumns();
				 }
				 // The last round is given below.
				 // The MixColumns function is not here in the last round.
				 InvShiftRows();
				 InvSubBytes();
				 AddRoundKey(0);
				 // The decryption process is over.
				 // Copy the state array to output array.
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 outD[i*4+j]=state[j][i];
					 }
				 }
			 }
			 // The SubBytes Function Substitutes the values in the
			 // state matrix with values in an S-box.
			 void SubBytes(){
				 int i,j;
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 state[i][j] = getSBoxValue(state[i][j]);
					 }
				 }
			 }

			 // The ShiftRows() function shifts the rows in the state to the left.
			 // Each row is shifted with different offset.
			 // Offset = Row number. So the first row is not shifted.
			 void ShiftRows(){
				 unsigned char temp;
				 // Rotate first row 1 columns to left
				 temp=state[1][0];
				 state[1][0]=state[1][1];
				 state[1][1]=state[1][2];
				 state[1][2]=state[1][3];
				 state[1][3]=temp;
				 // Rotate second row 2 columns to left
				 temp=state[2][0];
				 state[2][0]=state[2][2];
				 state[2][2]=temp;
				 temp=state[2][1];
				 state[2][1]=state[2][3];
				 state[2][3]=temp;
				 // Rotate third row 3 columns to left
				 temp=state[3][0];
				 state[3][0]=state[3][3];
				 state[3][3]=state[3][2];
				 state[3][2]=state[3][1];
				 state[3][1]=temp;
			 }

			 // MixColumns function mixes the columns of the state matrix
			 // The method used may look complicated, but it is easy if you know the underlying theory.
			 // Refer the documents specified above.
			 void MixColumns(){
				 int i;
				 unsigned char Tmp,Tm,t;
				 for(i=0;i<4;i++){
					 t=state[0][i];
					 Tmp = state[0][i] ^ state[1][i] ^ state[2][i] ^ state[3][i] ;
					 Tm = state[0][i] ^ state[1][i] ; Tm = xtime(Tm); state[0][i] ^= Tm ^ Tmp ;
					 Tm = state[1][i] ^ state[2][i] ; Tm = xtime(Tm); state[1][i] ^= Tm ^ Tmp ;
					 Tm = state[2][i] ^ state[3][i] ; Tm = xtime(Tm); state[2][i] ^= Tm ^ Tmp ;
					 Tm = state[3][i] ^ t ; Tm = xtime(Tm); state[3][i] ^= Tm ^ Tmp ;
				 }
			 }

			 // Cipher is the main function that encrypts the PlainText.
			 void Cipher(){
				 int i,j,round=0;
				 //Copy the input PlainText to state array.
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 state[j][i] = inE[i*4 + j];
					 }
				 }
				 // Add the First round key to the state before starting the rounds.
				 AddRoundKey(0);
				 // There will be Nr rounds.
				 // The first Nr-1 rounds are identical.
				 // These Nr-1 rounds are executed in the loop below.
				 for(round=1;round<Nr;round++){
					 SubBytes();
					 ShiftRows();
					 MixColumns();
					 AddRoundKey(round);
				 }
				 // The last round is given below.
				 // The MixColumns function is not here in the last round.
				 SubBytes();
				 ShiftRows();
				 AddRoundKey(Nr);
				 // The encryption process is over.
				 // Copy the state array to output array.
				 for(i=0;i<4;i++){
					 for(j=0;j<4;j++){
						 outE[i*4+j]=state[j][i];
					 }
				 }
			 }
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

