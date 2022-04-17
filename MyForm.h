#pragma once
#include "QuakeVec.h"

namespace QuakeUI {

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


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Button^ button1;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(141, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(686, 62);
			this->label1->TabIndex = 2;
			this->label1->Text = L"WELCOME TO QUAKETRACK";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(243, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(491, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"PLEASE ENTER YOUR LATITUDE AND LONGITUDE";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(268, 218);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 26);
			this->textBox1->TabIndex = 4;
			
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(539, 218);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(174, 26);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(313, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Latitude";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(581, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Longitude";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(75, 290);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(857, 29);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Input \"1\" to sort by Relevance, \"2\" to sort by Magnitude, or \"3\" to sort by Dista"
				L"nce";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(409, 337);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(179, 26);
			this->textBox3->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(388, 453);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(214, 37);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Your Quakes:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(148, 516);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(138, 20);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Distance (miles)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(313, 516);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(93, 20);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Magnitude";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(475, 516);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 20);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Depth";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(643, 516);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 20);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Date";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(798, 516);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(93, 20);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Relevance";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(148, 559);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 20);
			this->label12->TabIndex = 16;
			this->label12->Text = L"label12";
			
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(313, 559);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(60, 20);
			this->label13->TabIndex = 17;
			this->label13->Text = L"label13";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(475, 559);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(60, 20);
			this->label14->TabIndex = 18;
			this->label14->Text = L"label14";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(643, 559);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(60, 20);
			this->label15->TabIndex = 19;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(798, 559);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(60, 20);
			this->label16->TabIndex = 20;
			this->label16->Text = L"label16";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(148, 600);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(60, 20);
			this->label17->TabIndex = 21;
			this->label17->Text = L"label17";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(313, 600);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(60, 20);
			this->label18->TabIndex = 22;
			this->label18->Text = L"label18";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(475, 600);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(60, 20);
			this->label19->TabIndex = 23;
			this->label19->Text = L"label19";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(643, 600);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(60, 20);
			this->label20->TabIndex = 24;
			this->label20->Text = L"label20";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(798, 600);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(60, 20);
			this->label21->TabIndex = 25;
			this->label21->Text = L"label21";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(148, 638);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(60, 20);
			this->label22->TabIndex = 26;
			this->label22->Text = L"label22";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(313, 638);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(60, 20);
			this->label23->TabIndex = 27;
			this->label23->Text = L"label23";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(475, 638);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(60, 20);
			this->label24->TabIndex = 28;
			this->label24->Text = L"label24";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(643, 638);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(60, 20);
			this->label25->TabIndex = 29;
			this->label25->Text = L"label25";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(798, 638);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(60, 20);
			this->label26->TabIndex = 30;
			this->label26->Text = L"label26";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(148, 678);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(60, 20);
			this->label27->TabIndex = 31;
			this->label27->Text = L"label27";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(313, 678);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(60, 20);
			this->label28->TabIndex = 32;
			this->label28->Text = L"label28";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(475, 678);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(60, 20);
			this->label29->TabIndex = 33;
			this->label29->Text = L"label29";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(643, 678);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(60, 20);
			this->label30->TabIndex = 34;
			this->label30->Text = L"label30";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(798, 678);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(60, 20);
			this->label31->TabIndex = 35;
			this->label31->Text = L"label31";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(148, 715);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(60, 20);
			this->label32->TabIndex = 36;
			this->label32->Text = L"label32";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(313, 715);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(60, 20);
			this->label33->TabIndex = 37;
			this->label33->Text = L"label33";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(475, 715);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(60, 20);
			this->label34->TabIndex = 38;
			this->label34->Text = L"label34";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(643, 715);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(60, 20);
			this->label35->TabIndex = 39;
			this->label35->Text = L"label35";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(798, 715);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(60, 20);
			this->label36->TabIndex = 40;
			this->label36->Text = L"label36";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(453, 384);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 54);
			this->button1->TabIndex = 41;
			this->button1->Text = L"GO";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1011, 991);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double userLatD = System::Convert::ToDouble(textBox1->Text);
		float userLat = float(userLatD);
		double userLongD = System::Convert::ToDouble(textBox2->Text);
		float userLong = float(userLongD);
		int sortParam = System::Convert::ToInt16(textBox3->Text); //1 for relevance, 2 for magnitude, 3 for distance
		QuakeVec gamer(userLat, userLong);
		std::vector<Quake> sol = gamer.ReturnTop5();
		float dist1 = sol[0].GetDistance();
		float mag1 = sol[0].GetMag();
		float depth1 = sol[0].GetDepth();
		String^ date1 = gcnew String(sol[0].GetDate().c_str());
		float relevance1 = sol[0].GetRelevance();
		label12->Text = System::Convert::ToString(dist1);
		label13->Text = System::Convert::ToString(mag1);
		label14->Text = System::Convert::ToString(depth1);
		label15->Text = date1;
		label16->Text = System::Convert::ToString(relevance1);
	}
};
}

