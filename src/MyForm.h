#pragma once
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <fstream>
#include <cmath>
#pragma warning(disable : 4996)

namespace gamegenie {

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
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Super Mario Bros. NES", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(177, 240);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(246, 31);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button1->Font = (gcnew System::Drawing::Font(L"Super Mario Bros. NES", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(242, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Convert";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label1->Font = (gcnew System::Drawing::Font(L"Super Mario Bros. NES", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(257, 400);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 15);
			this->label1->TabIndex = 2;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Super Mario Bros. NES", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Info;
			this->label2->Location = System::Drawing::Point(163, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(283, 60);
			this->label2->TabIndex = 3;
			this->label2->Text = L"GAME GENIE\r\nINJECTOR";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"Your Unmoddified Rom";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"nes";
			this->saveFileDialog1->FileName = L"Patched Rom";
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game Genie Injector";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		void convertCode() {
			msclr::interop::marshal_context variableToCopyTheString;
			std::string input;
			std::string Bytes;
			char addressBin[17];
			char valueBin[9];
			char* char_array;
			char GgLetter[16]{ 'A', 'P', 'Z', 'L', 'G', 'I', 'T', 'Y', 'E', 'O', 'X', 'U', 'K', 'S', 'V', 'N' };
						
			const char* Bin[16]
				= { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
			
			int Ass[24] = { 16, 21, 22, 23, 8, 17, 18, 19, 0, 9, 10, 11,
						   12, 1, 2, 3, 4, 13, 14, 15, 20, 5, 6, 7 };
			char Dest[25];


			input = variableToCopyTheString.marshal_as<std::string>(textBox1->Text);
			char_array = new char[6];
			strcpy(char_array, input.c_str());
			for (int i = 0; i < 6; i++)
			{
				for (int y = 0; y < 16; y++)
				{
					if (char_array[i] == GgLetter[y])
					{
						Bytes.append(Bin[y]);
					}
				}
			}
			char_array = new char[25];
			strcpy(char_array, Bytes.c_str());
			for (int i = 0; i < 24; i++)
			{
				Dest[Ass[i]] = char_array[i];
			}
			for (int i = 0; i < 16; i++)
			{
				addressBin[i] = Dest[i];
			}
			for (int i = 0; i < 8; i++)
			{
				valueBin[i] = Dest[i + 16];
			}
			addressBin[0] = '1';
			delete[] char_array;
			std::stringstream addressSTR;
			std::stringstream valueSTR;
			addressSTR << std::stoll(std::string(addressBin), NULL, 2);
			valueSTR << std::stoll(std::string(valueBin), NULL, 2);

			int finalAddress;
			addressSTR >> finalAddress;
			finalAddress -= 32752;
			int finalValue;
			valueSTR >> finalValue;

			
			msclr::interop::marshal_context deez;
			std::string nuts = deez.marshal_as<std::string>(openFileDialog1->FileName);
			
			saveFileDialog1->ShowDialog();
			msclr::interop::marshal_context New;
			std::string newDir = New.marshal_as<std::string>(saveFileDialog1->FileName);

			System::IO::File::Copy(openFileDialog1->FileName, saveFileDialog1->FileName);

			std::fstream rom(newDir, std::ios::in | std::ios::out | std::ios::binary);
			rom.seekp(finalAddress);
			rom.put(finalValue);

			rom.close();
		}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		openFileDialog1->ShowDialog();
		convertCode();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}