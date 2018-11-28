#pragma once
#include<vcclr.h>
#include <stdio.h>
#include <stdlib.h>
namespace des2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//straight pbox
	int per[32]={16 ,  7 , 20  ,21,
		29 , 12 , 28 , 17,
		1 , 15,  23,  26,
		5 , 18 , 31  ,10,
		2  , 8 , 24 , 14,
		32  ,27,   3 ,  9,
		19  ,13,  30,   6,
		22 , 11  , 4 , 25};

	//sbox configuration 6 bit to 4 bit
	int s[8][4][16]=
	{{
		14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
			0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
			4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
			15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
	},
	{
		15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
			3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
			0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
			13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
		},


		{
			10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
				13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
				13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
				1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
		},
		{
			7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
				13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
				10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
				3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
			},
			{
				2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
					14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
					4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
					11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
			},
			{
				12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
					10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
					9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
					4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
				},
				{
					4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
						13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
						1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
						6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
				},
				{
					13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
						1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
						7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
						2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
					}};
					//getting 56 bit key from 64 bit using the parity bits
					int keyp[56]={57  , 49   , 41   ,33 ,   25   , 17 ,   9,
						1 ,  58    ,50  , 42 ,   34  ,  26  , 18,
						10 ,   2   , 59 ,  51  ,  43  ,  35  , 27,
						19  , 11   ,  3  , 60  ,  52  ,  44  , 36,
						63  , 55  ,  47  , 39  ,  31   , 23  , 15,
						7  , 62   , 54  , 46  ,  38  ,  30  , 22,
						14  ,  6   , 61  , 53  ,  45   , 37  , 29,
						21  , 13  ,   5  , 28   , 20  ,  12  ,  4};
					//D box configuration each 28 to 24 bit
					int key2[48]={14,    17,   11,    24,     1,    5,
						3   , 28 ,  15    , 6  ,  21  , 10 ,
						23    ,19  , 12   ,  4 ,  26  ,  8,
						16     ,7  , 27  ,  20  ,  13  ,  2,
						41   , 52 ,  31  ,  37  ,  47  , 55,
						30   , 40  , 51  ,  45  ,  33 , 48,
						44    ,49 ,  39  ,  56  ,  34 ,  53,
						46    ,42 ,  50  ,  36 ,   29 ,  32};
					int key[16][48],keyl[28],keyr[28],nshift,temp1,temp2,pkey[56];
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
							l = gcnew System::String("");
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
							this->button2 = (gcnew System::Windows::Forms::Button());
							this->label4 = (gcnew System::Windows::Forms::Label());
							this->label5 = (gcnew System::Windows::Forms::Label());
							this->label6 = (gcnew System::Windows::Forms::Label());
							this->textBox4 = (gcnew System::Windows::Forms::TextBox());
							this->textBox5 = (gcnew System::Windows::Forms::TextBox());
							this->textBox6 = (gcnew System::Windows::Forms::TextBox());
							this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
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
							this->groupBox2->Controls->Add(this->button2);
							this->groupBox2->Controls->Add(this->label4);
							this->groupBox2->Controls->Add(this->label5);
							this->groupBox2->Controls->Add(this->label6);
							this->groupBox2->Controls->Add(this->textBox4);
							this->groupBox2->Controls->Add(this->textBox5);
							this->groupBox2->Controls->Add(this->textBox6);
							this->groupBox2->Font = (gcnew System::Drawing::Font(L"Papyrus", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->groupBox2->Location = System::Drawing::Point(408, 15);
							this->groupBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->groupBox2->Name = L"groupBox2";
							this->groupBox2->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->groupBox2->Size = System::Drawing::Size(382, 229);
							this->groupBox2->TabIndex = 11;
							this->groupBox2->TabStop = false;
							this->groupBox2->Text = L"Decryption";
							// 
							// button2
							// 
							this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
								static_cast<System::Int32>(static_cast<System::Byte>(128)));
							this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->button2->Location = System::Drawing::Point(12, 131);
							this->button2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->button2->Name = L"button2";
							this->button2->Size = System::Drawing::Size(358, 44);
							this->button2->TabIndex = 6;
							this->button2->Text = L"Decrypt it";
							this->button2->UseVisualStyleBackColor = false;
							this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
							// 
							// label4
							// 
							this->label4->AutoSize = true;
							this->label4->Font = (gcnew System::Drawing::Font(L"Harrington", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->label4->Location = System::Drawing::Point(12, 42);
							this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
							this->label4->Name = L"label4";
							this->label4->Size = System::Drawing::Size(48, 25);
							this->label4->TabIndex = 5;
							this->label4->Text = L"Text";
							// 
							// label5
							// 
							this->label5->AutoSize = true;
							this->label5->Font = (gcnew System::Drawing::Font(L"Harrington", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->label5->Location = System::Drawing::Point(12, 92);
							this->label5->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
							this->label5->Name = L"label5";
							this->label5->Size = System::Drawing::Size(46, 25);
							this->label5->TabIndex = 4;
							this->label5->Text = L"Key";
							// 
							// label6
							// 
							this->label6->AutoSize = true;
							this->label6->Font = (gcnew System::Drawing::Font(L"Harrington", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->label6->Location = System::Drawing::Point(12, 190);
							this->label6->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
							this->label6->Name = L"label6";
							this->label6->Size = System::Drawing::Size(47, 25);
							this->label6->TabIndex = 3;
							this->label6->Text = L"Dec";
							// 
							// textBox4
							// 
							this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->textBox4->Location = System::Drawing::Point(94, 37);
							this->textBox4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->textBox4->MaxLength = 16;
							this->textBox4->Name = L"textBox4";
							this->textBox4->Size = System::Drawing::Size(272, 41);
							this->textBox4->TabIndex = 2;
							// 
							// textBox5
							// 
							this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->textBox5->Location = System::Drawing::Point(94, 87);
							this->textBox5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->textBox5->MaxLength = 16;
							this->textBox5->Name = L"textBox5";
							this->textBox5->Size = System::Drawing::Size(272, 41);
							this->textBox5->TabIndex = 1;
							// 
							// textBox6
							// 
							this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->textBox6->Location = System::Drawing::Point(94, 188);
							this->textBox6->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->textBox6->Name = L"textBox6";
							this->textBox6->Size = System::Drawing::Size(272, 41);
							this->textBox6->TabIndex = 0;
							// 
							// groupBox1
							// 
							this->groupBox1->Controls->Add(this->button1);
							this->groupBox1->Controls->Add(this->label3);
							this->groupBox1->Controls->Add(this->label2);
							this->groupBox1->Controls->Add(this->label1);
							this->groupBox1->Controls->Add(this->textBox3);
							this->groupBox1->Controls->Add(this->textBox2);
							this->groupBox1->Controls->Add(this->textBox1);
							this->groupBox1->Font = (gcnew System::Drawing::Font(L"Papyrus", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->groupBox1->Location = System::Drawing::Point(14, 15);
							this->groupBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->groupBox1->Name = L"groupBox1";
							this->groupBox1->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->groupBox1->Size = System::Drawing::Size(382, 229);
							this->groupBox1->TabIndex = 10;
							this->groupBox1->TabStop = false;
							this->groupBox1->Text = L"Encryption";
							// 
							// button1
							// 
							this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
								static_cast<System::Int32>(static_cast<System::Byte>(128)));
							this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->button1->Location = System::Drawing::Point(16, 131);
							this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->button1->Name = L"button1";
							this->button1->Size = System::Drawing::Size(352, 44);
							this->button1->TabIndex = 6;
							this->button1->Text = L"Encrypt it";
							this->button1->UseVisualStyleBackColor = false;
							this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
							// 
							// label3
							// 
							this->label3->AutoSize = true;
							this->label3->Font = (gcnew System::Drawing::Font(L"Harrington", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->label3->Location = System::Drawing::Point(12, 190);
							this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
							this->label3->Name = L"label3";
							this->label3->Size = System::Drawing::Size(48, 25);
							this->label3->TabIndex = 5;
							this->label3->Text = L"Enc";
							// 
							// label2
							// 
							this->label2->AutoSize = true;
							this->label2->Font = (gcnew System::Drawing::Font(L"Harrington", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->label2->Location = System::Drawing::Point(12, 92);
							this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
							this->label2->Name = L"label2";
							this->label2->Size = System::Drawing::Size(46, 25);
							this->label2->TabIndex = 4;
							this->label2->Text = L"Key";
							// 
							// label1
							// 
							this->label1->AutoSize = true;
							this->label1->Font = (gcnew System::Drawing::Font(L"Harrington", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(0)));
							this->label1->Location = System::Drawing::Point(12, 42);
							this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
							this->label1->Name = L"label1";
							this->label1->Size = System::Drawing::Size(48, 25);
							this->label1->TabIndex = 3;
							this->label1->Text = L"Text";
							// 
							// textBox3
							// 
							this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->textBox3->Location = System::Drawing::Point(94, 187);
							this->textBox3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->textBox3->Name = L"textBox3";
							this->textBox3->Size = System::Drawing::Size(272, 41);
							this->textBox3->TabIndex = 2;
							// 
							// textBox2
							// 
							this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->textBox2->Location = System::Drawing::Point(94, 87);
							this->textBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->textBox2->MaxLength = 16;
							this->textBox2->Name = L"textBox2";
							this->textBox2->Size = System::Drawing::Size(272, 41);
							this->textBox2->TabIndex = 1;
							this->textBox2->Text = L"1212121212121212";
							// 
							// textBox1
							// 
							this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->textBox1->Location = System::Drawing::Point(94, 37);
							this->textBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
							this->textBox1->MaxLength = 16;
							this->textBox1->Name = L"textBox1";
							this->textBox1->Size = System::Drawing::Size(272, 41);
							this->textBox1->TabIndex = 0;
							this->textBox1->Text = L"1231231231231233";
							// 
							// Form1
							// 
							this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
							this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
							this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
								static_cast<System::Int32>(static_cast<System::Byte>(192)));
							this->ClientSize = System::Drawing::Size(804, 263);
							this->Controls->Add(this->groupBox2);
							this->Controls->Add(this->groupBox1);
							this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
								static_cast<System::Byte>(204)));
							this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
							this->Name = L"Form1";
							this->Text = L"DES";
							this->groupBox2->ResumeLayout(false);
							this->groupBox2->PerformLayout();
							this->groupBox1->ResumeLayout(false);
							this->groupBox1->PerformLayout();
							this->ResumeLayout(false);

						}
#pragma endregion
					System::String ^l, ^r;
					private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
								 System::String ^p, ^ap="", ^ke, ^kp, ^rtem;
								 int key1[64];
								 p=textBox1->Text;
								 kp=textBox2->Text;
								 p=hex2bin(p);
								 kp=hex2bin(kp);
								 for(int i=0;i<64;i++){
									 key1[i]=kp[i]-'0';
								 }
								 l=p->Substring(0,32);
								 r=p->Substring(32,32);
								 //key generation
								 int t=1,j,row,col,temp,round=16;
								 j=0;
								 for(int i=0;i<56;i++)
									 pkey[i]=key1[keyp[i]-1];
								 for(int i=0;i<28;i++)
									 keyl[i]=pkey[i];
								 for(int i=0;i<28;i++)
									 keyr[i]=pkey[i+28];
								 //round key generation
								 for(int i=0;i<16;i++)
								 {
									 if(i==0||i==1||i==8||i==15)
										 nshift=1;
									 else
										 nshift=2;
									 while(nshift--)
									 {
										 temp1=keyl[0];
										 temp2=keyr[0];
										 for(j=0;j<27;j++)
										 {
											 keyl[j]=keyl[j+1];
											 keyr[j]=keyr[j+1];
										 }
										 keyl[27]=temp1;
										 keyr[27]=temp2;
									 }
									 for(j=0;j<24;j++)
										 key[i][j]=keyl[key2[j]-1];
									 for(j=24;j<48;j++)
										 key[i][j]=keyr[key2[j]-1-28];
								 }
								 //DES Encryption
							     System::String^ cip;
								 while(round--)
								 {
									 rtem=r;
									 t=1;
									 System::String ^ep="", ^xorout="", ^sout="", ^soutt;
									 //the expansion P box
									 ep+=r[31];
									 for(int i=0;i<32;i++)
									 {
										 if((t+1)%6==0)
										 {
											 ep+=r[4*((t+1)/6)];
											 t++;
										 }
										 if(t%6==0&&i!=0)
										 {
											 ep+=r[4*(t/6)-1];
											 t++;
										 }
										 ep+=r[i];
										 t++;
									 }
									 ep+=r[0];
									 //Key xor with output of expansion p box
									 for(int i=0;i<48;i++)
										 xorout+=Char(((int(ep[i])-48)^key[16-round-1][i])+48);
									 //sbox compression 48bit to 32 bit
									 for(int i=0;i<48;i+=6)
									 {
										 row=(int(xorout[i+5])-48)+(int(xorout[i])-48)*2;
										 col= (int(xorout[i+1])-48)*8+(int(xorout[i+2])-48)*4+(int(xorout[i+3])-48)*2+(int(xorout[i+4])-48);
										 temp=s[i/6][row][col];
										 soutt="";
										 while(temp>0)
										 {
											 soutt+=Char(temp%2+48);
											 temp/=2;
										 }
										 while(soutt->Length!=4)
											 soutt+="0";
										 for(j=soutt->Length-1;j>=0;j--)
											 sout+=soutt[j];
									 }
									 //straight pbox that is permutation of the sbox output
									 char pc[32];
									 for(int i=0;i<32;i++)
										 pc[i]=sout[per[i]-1];
									 r="";
									 for(int i=0;i<32;i++){
										 r+=Char(((int(pc[i])-48)^(int(l[i])-48))+48);
									 }
									 l=rtem;
									 //cout<<"Output after Round"<<16-round<<endl;
									 cip="";
									 for(int i=0;i<32;i+=4)
									 {
										 int te;
										 te=(int(l[i])-48)*8+(int(l[i+1])-48)*4+(int(l[i+2])-48)*2+(int(l[i+3])-48);
										 if(te<10)
											 cip+=System::Char(te+48);
										 else
											 cip+=System::Char(te+55);
									 }
									 for(int i=0;i<32;i+=4)
									 {
										 int te;
										 te=(int(r[i])-48)*8+(int(r[i+1])-48)*4+(int(r[i+2])-48)*2+(int(r[i+3])-48);
										 if(te<10)
											 cip+=System::Char(te+48);
										 else
											 cip+=System::Char(te+55);
									 }
								 }
								 textBox3->Text=cip;
							 }
					private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
								 System::String ^ltem;
								 int i,t=1,j,row,col,temp,round=16;
								 System::String ^cip;
								 while(round--){
									 ltem=l;
									 t=1;
									 System::String ^ep="", ^xorout="", ^sout="", ^soutt;
									 //the expansion P box
									 ep+=l[31];
									 for(i=0;i<32;i++){
										 if((t+1)%6==0){
											 ep+=l[4*((t+1)/6)];
											 t++;
										 }
										 if(t%6==0&&i!=0){
											 ep+=l[4*(t/6)-1];
											 t++;
										 }
										 ep+=l[i];
										 t++;
									 }
									 ep+=l[0];
									 //Key xor with output of expansion p box
									 for(i=0;i<48;i++){
										 xorout+=Char(((int(ep[i])-48)^key[round][i])+48);
									 }
									 //sbox compression 48bit to 32 bit
									 for(i=0;i<48;i+=6){
										 row=(int(xorout[i+5])-48)+(int(xorout[i])-48)*2;
										 col= (int(xorout[i+1])-48)*8+(int(xorout[i+2])-48)*4+(int(xorout[i+3])-48)*2+(int(xorout[i+4])-48);
										 temp=s[i/6][row][col];
										 soutt="";
										 while(temp>0){
											 soutt+=Char(temp%2+48);
											 temp/=2;
										 }
										 while(soutt->Length!=4){
											 soutt+="0";
										 }
										 for(j=soutt->Length-1;j>=0;j--){
											 sout+=soutt[j];
										 }
									 }
									 //straight pbox that is permutation of the sbox output
									 char pc[32];
									 for(i=0;i<32;i++)
										 pc[i]=sout[per[i]-1];
									 l="";
									 for(i=0;i<32;i++)
										 l+=Char(((int(pc[i])-48)^(int(r[i])-48))+48);
									 r=ltem;
									 //cout<<"Decrypted Output after Round"<<16-round<<endl;
									 cip="";
									 for(i=0;i<32;i+=4){
										 int te;
										 te=(int(l[i])-48)*8+(int(l[i+1])-48)*4+(int(l[i+2])-48)*2+(int(l[i+3])-48);
										 if(te<10){
											 cip+=Char(te+48);
										 }else{
											 cip+=Char(te+55);
										 }
									 }
									 for(i=0;i<32;i+=4){
										 int te;
										 te=(int(r[i])-48)*8+(int(r[i+1])-48)*4+(int(r[i+2])-48)*2+(int(r[i+3])-48);
										 if(te<10){
											 cip+=Char(te+48);
										 }else{
											 cip+=Char(te+55);
										 }
									 }
								 }
								 textBox6->Text=cip;
							 }
							 //hexadecimal to binary
							 System::String^ hex2bin(System::String^ p){
								 System::String ^ap="";
								 int l=p->Length;
								 for(int i=0; i<l; i++){
									 System::String ^st="";
									 if(p[i]>='0'&&p[i]<='9'){
										 int te=int(p[i])-48;
										 while(te>0){
											 st+=Char(te%2+48);
											 te/=2;
										 }
										 while(st->Length!=4){
											 st+="0";
										 }
										 for(int j=3;j>=0;j--){
											 ap+=st[j];
										 }
									 }else{
										 int te=p[i]-'A'+10;
										 while(te>0){
											 st+=Char(te%2+48);
											 te/=2;
										 }
										 for(int j=3; j>=0; j--){
											 ap+=st[j];
										 }
									 }
								 }
								 return ap;
							 }
					};
}