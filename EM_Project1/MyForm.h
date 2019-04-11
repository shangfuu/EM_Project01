#pragma once
#include "DataManager.h"
#include "Vector.h"
#include"DotNetUitilities.h"
#include <sstream>
#include <iomanip>
#include <string>

namespace EM_Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm ���K�n
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			lastInputLength = -1;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;



	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  OutputLabel;
	private: System::Windows::Forms::TextBox^  Output;

	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;

	private: System::Windows::Forms::Label^  VectorLabel;
	private: System::Windows::Forms::ListBox^  VectorList;

	protected:

	protected:

	private:
		/// <summary>
		DataManager * dataManager;
		String^ userInput;
		int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadMatrixToolStripMenuItem;

			 /// </summary>
			 System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
			 /// �o�Ӥ�k�����e�C
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
				 this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->loadMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
				 this->InputLabel = (gcnew System::Windows::Forms::Label());
				 this->Input = (gcnew System::Windows::Forms::TextBox());
				 this->VectorLabel = (gcnew System::Windows::Forms::Label());
				 this->VectorList = (gcnew System::Windows::Forms::ListBox());
				 this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
				 this->OutputLabel = (gcnew System::Windows::Forms::Label());
				 this->Output = (gcnew System::Windows::Forms::TextBox());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->menuStrip2->SuspendLayout();
				 this->tableLayoutPanel1->SuspendLayout();
				 this->flowLayoutPanel1->SuspendLayout();
				 this->flowLayoutPanel2->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // menuStrip2
				 // 
				 this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
				 this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
				 this->menuStrip2->Location = System::Drawing::Point(0, 0);
				 this->menuStrip2->Name = L"menuStrip2";
				 this->menuStrip2->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
				 this->menuStrip2->Size = System::Drawing::Size(512, 28);
				 this->menuStrip2->TabIndex = 1;
				 this->menuStrip2->Text = L"menuStrip2";
				 // 
				 // FileToolStripMenuItem
				 // 
				 this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->LoadVectorToolStripMenuItem,
						 this->loadMatrixToolStripMenuItem
				 });
				 this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
				 this->FileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
				 this->FileToolStripMenuItem->Text = L"File";
				 // 
				 // LoadVectorToolStripMenuItem
				 // 
				 this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
				 this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(216, 26);
				 this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
				 this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::LoadVectorToolStripMenuItem_Click);
				 // 
				 // loadMatrixToolStripMenuItem
				 // 
				 this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
				 this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(216, 26);
				 this->loadMatrixToolStripMenuItem->Text = L"Load Matrix";
				 this->loadMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::LoadMatrixToolStripMenuItem_Click);
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->ColumnCount = 2;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
				 this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
				 this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel1->Location = System::Drawing::Point(0, 28);
				 this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 1;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(512, 424);
				 this->tableLayoutPanel1->TabIndex = 2;
				 // 
				 // flowLayoutPanel1
				 // 
				 this->flowLayoutPanel1->Controls->Add(this->InputLabel);
				 this->flowLayoutPanel1->Controls->Add(this->Input);
				 this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
				 this->flowLayoutPanel1->Controls->Add(this->VectorList);
				 this->flowLayoutPanel1->Location = System::Drawing::Point(260, 4);
				 this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
				 this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
				 this->flowLayoutPanel1->Size = System::Drawing::Size(248, 415);
				 this->flowLayoutPanel1->TabIndex = 0;
				 // 
				 // InputLabel
				 // 
				 this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->InputLabel->AutoSize = true;
				 this->InputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->InputLabel->Location = System::Drawing::Point(4, 0);
				 this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->InputLabel->Name = L"InputLabel";
				 this->InputLabel->Size = System::Drawing::Size(48, 19);
				 this->InputLabel->TabIndex = 0;
				 this->InputLabel->Text = L"Input";
				 // 
				 // Input
				 // 
				 this->Input->Location = System::Drawing::Point(4, 23);
				 this->Input->Margin = System::Windows::Forms::Padding(4);
				 this->Input->Multiline = true;
				 this->Input->Name = L"Input";
				 this->Input->Size = System::Drawing::Size(239, 196);
				 this->Input->TabIndex = 1;
				 this->Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Input_TextChanged);
				 // 
				 // VectorLabel
				 // 
				 this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->VectorLabel->AutoSize = true;
				 this->VectorLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->VectorLabel->Location = System::Drawing::Point(4, 223);
				 this->VectorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->VectorLabel->Name = L"VectorLabel";
				 this->VectorLabel->Size = System::Drawing::Size(58, 19);
				 this->VectorLabel->TabIndex = 2;
				 this->VectorLabel->Text = L"Vector";
				 // 
				 // VectorList
				 // 
				 this->VectorList->FormattingEnabled = true;
				 this->VectorList->ItemHeight = 15;
				 this->VectorList->Location = System::Drawing::Point(4, 246);
				 this->VectorList->Margin = System::Windows::Forms::Padding(4);
				 this->VectorList->Name = L"VectorList";
				 this->VectorList->Size = System::Drawing::Size(239, 154);
				 this->VectorList->TabIndex = 3;
				 // 
				 // flowLayoutPanel2
				 // 
				 this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
				 this->flowLayoutPanel2->Controls->Add(this->Output);
				 this->flowLayoutPanel2->Location = System::Drawing::Point(4, 4);
				 this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
				 this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
				 this->flowLayoutPanel2->Size = System::Drawing::Size(248, 415);
				 this->flowLayoutPanel2->TabIndex = 1;
				 // 
				 // OutputLabel
				 // 
				 this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->OutputLabel->AutoSize = true;
				 this->OutputLabel->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->OutputLabel->Location = System::Drawing::Point(4, 0);
				 this->OutputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->OutputLabel->Name = L"OutputLabel";
				 this->OutputLabel->Size = System::Drawing::Size(61, 19);
				 this->OutputLabel->TabIndex = 0;
				 this->OutputLabel->Text = L"Output";
				 // 
				 // Output
				 // 
				 this->Output->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(136)));
				 this->Output->Location = System::Drawing::Point(4, 23);
				 this->Output->Margin = System::Windows::Forms::Padding(4);
				 this->Output->Multiline = true;
				 this->Output->Name = L"Output";
				 this->Output->ReadOnly = true;
				 this->Output->Size = System::Drawing::Size(243, 390);
				 this->Output->TabIndex = 1;
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(512, 452);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->Controls->Add(this->menuStrip2);
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->Name = L"MyForm";
				 this->Text = L"VectorExample";
				 this->Load += gcnew System::EventHandler(this, &MyForm::WindowsForm_Load);
				 this->menuStrip2->ResumeLayout(false);
				 this->menuStrip2->PerformLayout();
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->flowLayoutPanel1->ResumeLayout(false);
				 this->flowLayoutPanel1->PerformLayout();
				 this->flowLayoutPanel2->ResumeLayout(false);
				 this->flowLayoutPanel2->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->VectorLabel->Text = L"Vector";
		//�}��Dialog
		openFileDialog1->ShowDialog();
	}
	private: System::Void LoadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->VectorLabel->Text = L"Matrix";
		//�}��Dialog
		openFileDialog1->ShowDialog();
	}
	private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		//��Input textbox������J���ܮɡA�K�|�i�J���禡
		//���o�V�q���
		std::vector<Vector> vectors = dataManager->GetVectors();
		std::vector<Matrix> matrices = dataManager->GetMatrices();

		//�P�_��J�ۤ���'\n'�A�è������r��-1��m
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//�N�ϥΪ̿�J�r��(�buserInput��)�A�̪ťէ@����
			array<String^> ^userCommand = userInput->Split(' ');
			/* �P�_���~���O */
			VECTOR_ERROR Error = Correct;
			MATRIX_ERROR M_Error = M_Correct;
			
			// �p�G�� Load Vector
			if (dataManager->HasVector() && this->VectorLabel->Text == L"Vector") {

				//�r�����A�Y���O��"print"�����p
				if (userCommand[0] == "print")
				{
					//�w�N��X�Ȧs
					String^ outputTemp = "";
					//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[1] == gcnew String(vectors[i].Name.c_str()))
						{
							//�N��X�榡�s�J�Ȧs
							outputTemp += "[";
							//�N��X��Ʀs�J�Ȧs
							for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
							{
								outputTemp += vectors[i].Data[j].ToString();
								if (j != vectors[i].Data.size() - 1)
									outputTemp += ",";
							}
							//�N��X�榡�s�J�Ȧs�A�åB����
							outputTemp += "]" + Environment::NewLine;
							//��X�Ȧs��T
							Output->Text += gcnew String(vectors[i].Name.c_str()) + " = " + outputTemp;
							break;
						}
					}
				}
				else if (userCommand[0] == "MVS") {

					Vector result = MVS(userCommand, vectors, Error);

					if (Error == Correct) {
						Output->Text += "-->" + Environment::NewLine;
						for (int i = 0; i < result.getDim(); i++) {
							Output->Text += result.Data[i].ToString() + "  ";
						}
						Output->Text += Environment::NewLine;
					}
				}
				else if (userCommand[0] == "Dot") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						/* ���׬ۦP�~�i Dot*/
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = vec1 * vec2;

							/* ��X�B�z */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = DOT_Error;
					}
				}
				else if (userCommand[0] == "Add") {

					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						/* ���׬ۦP�~�i Add*/
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = vec1 + vec2;

							/* ��X�B�z */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = ADD_Error;
					}

				}
				else if (userCommand[0] == "Scalar") {

					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					// �P�_�s�V�q
					if (Norm(vec1)) vec1.Data.resize(1);
					if (Norm(vec2))	vec2.Data.resize(1);

					if (Error == Correct) {
						// ���צܤ֭n�@�Ӥ@��
						if (vec1.getDim() > 1 && vec2.getDim() > 1) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Scalar(vec1, vec2);

							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = SCA_Error;
					}
				}
				else if (userCommand[0] == "Norm") {
					Vector vec;
					// ���O�榡
					Format_One(userCommand, vectors, Error, vec);

					if (Error == Correct) {
						double tmp = Norm(vec);

						Output->Text += "-->" + Environment::NewLine + tmp.ToString() + "  " + Environment::NewLine;
					}
					else if (Error == E_Error) {
						Error = NORM_Error;
					}
				}
				else if (userCommand[0] == "Normal") {
					/* Normal �u�B�z��@�V�q */
					Vector vec;
					// ���O�榡
					Format_One(userCommand, vectors, Error, vec);

					if (Error == Correct) {
						Vector tmp = Normal(vec);

						Output->Text += "-->" + Environment::NewLine;
						for (int i = 0; i < tmp.getDim(); i++) {
							Output->Text += tmp.Data[i].ToString() + "  ";
						}
						Output->Text += Environment::NewLine;
					}
					else if (Error == E_Error) {
						Error = NML_Error;
					}
				}
				else if (userCommand[0] == "Cross") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						// �u�B�z�T��
						if (vec1.getDim() != 3 && vec2.getDim() != 3) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Cross(vec1, vec2);

							/* �B�z��X */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = CRS_Error;
					}
				}
				else if (userCommand[0] == "Com") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Comp(vec1, vec2);

							/* �B�z��X */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = COM_Error;
					}
				}
				else if (userCommand[0] == "Proj") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Proj(vec1, vec2);
							/* ��X�B�z */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = PRJ_Error;
					}
				}
				else if (userCommand[0] == "Area") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							double trigArea = TrigArea(vec1, vec2);

							/* �B�z��X */
							Output->Text += "-->" + Environment::NewLine + trigArea.ToString() + Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = AREA_Error;
					}
				}
				else if (userCommand[0] == "IsPrl") {

					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);


					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							bool isPrl = IsParal(vec1, vec2);

							std::string Ans = "";
							if (isPrl) Ans = "Yes";
							else Ans = "No";
							Output->Text += "-->" + Environment::NewLine + gcnew String(Ans.c_str()) + Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = IsPRL_Error;
					}
				}
				else if (userCommand[0] == "IsOrtg") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							bool isOrg = IsOrthog(vec1, vec2);

							std::string Ans = "";
							if (isOrg) Ans = "Yes";
							else Ans = "No";
							Output->Text += "-->" + Environment::NewLine + gcnew String(Ans.c_str()) + Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = IsORTG_Error;
					}
				}
				else if (userCommand[0] == "Angle") {
					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							double theta = Angle(vec1, vec2);

							std::string Ans = "";
							Output->Text += "-->" + Environment::NewLine + "theta = " + theta.ToString() + Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = ANG_Error;
					}
				}
				else if (userCommand[0] == "pN") {
					// ����Ū��"pn" �M "Cross"�@�� ��Xproduct() ���O��~�n

					Vector vec1, vec2;
					// ���O�榡
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						// �u�B�z�T��
						if (vec1.getDim() != 3 && vec2.getDim() != 3) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Cross(vec1, vec2);

							/* �B�z��X */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString() + "  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
					else if (Error == E_Error) {
						Error = PN_Error;
					}
				}
				else if (userCommand[0] == "IsLI") {
					// �䴩�h���q��J
					Output->Text += "- Function NOT Finish Yet -" + Environment::NewLine;
				}
				else if (userCommand[0] == "Ob") {
					// �䴩�h���q��J
					std::vector<Vector>vecs;
					Format_Muti(userCommand, vectors, Error, vecs);

					if (Error == Correct) {
						for (int i = 0; i < vecs.size() - 1; i++) {
							if (vecs[i].getDim() != vecs[i + 1].getDim()) {
								Error = Dim_Error;
								break;
							}
						}
						if (Error == Correct) {
							std::vector<Vector> tmp = Ob(vecs);
							/* ��X�B�z */
							Output->Text += "-->" + Environment::NewLine + gcnew String("normal") + "  " + tmp.size().ToString() + Environment::NewLine;
							for (unsigned int i = 0; i < tmp.size(); i++) {
								for (unsigned int j = 0; j < tmp[i].getDim(); j++) {
									Output->Text += tmp[i].Data[j].ToString() + "  ";
								}
								Output->Text += Environment::NewLine + Environment::NewLine;
							}

						}
					}
					else if (Error == E_Error) {
						Error = OB_Error;
					}

				}
				//�Ϥ��h�P�_�䤣����O
				else
				{
					Output->Text += "- Command not found -" + Environment::NewLine;
				}
				// ���O���~
				if (Error == MVS_Error) {
					Output->Text += "- Command MVS format ERROR -" + Environment::NewLine;
				}
				else if (Error == Dim_Error) {
					Output->Text += "- Vector Dimesion Not the Same -" + Environment::NewLine;
				}
				else if (Error == SCA_Error) {
					Output->Text += "- Command Scalar format ERROR -" + Environment::NewLine;
				}
				else if (Error == DOT_Error) {
					Output->Text += "- Command Dot format ERROR -" + Environment::NewLine;
				}
				else if (Error == ADD_Error) {
					Output->Text += "- Command Add format ERROR -" + Environment::NewLine;
				}
				else if (Error == NORM_Error) {
					Output->Text += "- Command Norm format ERROR -" + Environment::NewLine;
				}
				else if (Error == NML_Error) {
					Output->Text += "- Command Normal format ERROR -" + Environment::NewLine;
				}
				else if (Error == CRS_Error) {
					Output->Text += "- Command Cross format ERROR -" + Environment::NewLine;
				}
				else if (Error == COM_Error) {
					Output->Text += "- Command Com format ERROR -" + Environment::NewLine;
				}
				else if (Error == PRJ_Error) {
					Output->Text += "- Command Proj format ERROR -" + Environment::NewLine;
				}
				else if (Error == AREA_Error) {
					Output->Text += "- Command Area format ERROR -" + Environment::NewLine;
				}
				else if (Error == IsPRL_Error) {
					Output->Text += "- Command IsPrl format ERROR -" + Environment::NewLine;
				}
				else if (Error == IsORTG_Error) {
					Output->Text += "- Command IsOrtg format ERROR -" + Environment::NewLine;
				}
				else if (Error == ANG_Error) {
					Output->Text += "- Command Angle format ERROR -" + Environment::NewLine;
				}
				else if (Error == PN_Error) {
					Output->Text += "- Command pN format ERROR -" + Environment::NewLine;
				}
				else if (Error == IsLI_Error) {
					Output->Text += "- Command IsLI format ERROR -" + Environment::NewLine;
				}
				else if (Error == OB_Error) {
					Output->Text += "- Command Ob format ERROR -" + Environment::NewLine;
				}
				userInput = "";
			}
			// �p�G�� Load Matrix
			if (dataManager->HasMatrix() && this->VectorLabel->Text == L"Matrix") {
				if (userCommand[0] == "print") {
					//�w�N��X�Ȧs
					String^ outputTemp = "";
					bool isIn = false;
					//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand->Length > 1 && userCommand[1] == gcnew String(matrices[i].Name.c_str()))
						{
							////�N��X�榡�s�J�Ȧs
							//outputTemp += "[";
							////�N��X��Ʀs�J�Ȧs
							//for (unsigned int r = 0; r < matrices[i].Data.size(); r++)
							//{
							//	for (unsigned int c = 0; c < matrices[i].Data[r].getDim(); c++) {
							//		outputTemp += matrices[i].Data[r].Data[c].ToString();
							//		if (c != matrices[i].Data[r].getDim() - 1)
							//			outputTemp += ",";
							//	}
							//	if(r != matrices[i].Data.size() -1)
							//	outputTemp += Environment::NewLine;
							//}
							////�N��X�榡�s�J�Ȧs�A�åB����
							//outputTemp += "]" + Environment::NewLine;
							////��X�Ȧs��T
							//Output->Text += gcnew String(matrices[i].Name.c_str()) + " = " + Environment::NewLine + outputTemp;
							isIn = true;
							Matrix mat = matrices[i];
							mat.print(Output);
							break;
						}
					}
					if (!isIn)	Output->Text +=  "- Variable Name Not Found" + Environment::NewLine;
				}
				else if (userCommand[0] == "MMO") {
					Matrix mat = Multi_Matrix_Op(userCommand,matrices,M_Error);
					if(!M_Error)
						mat.print(Output);
				}
				else if (userCommand[0] == "Add") {
					Matrix mat1, mat2;
					Format_Two(userCommand, matrices, M_Error, mat1, mat2);
					if (!M_Error) {
						if (mat1.getRow() != mat2.getRow() || mat1.getCol() != mat2.getCol()) {
							M_Error = RC_Error;
						}
						else {
							Matrix tmp = mat1 + mat2;
							tmp.Name = mat1.Name + " + " + mat2.Name;
							tmp.print(Output);
						}
					}
				}
				else if (userCommand[0] == "Sub") {

				}
				else {
					Output->Text += "- Command not found -" + Environment::NewLine;
				}

			}

		}
		else
		{
			//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
			array<String^> ^userCommand = Input->Text->Split('\n');
			//�ñN�̫�@��A�@���ثe�ϥΪ̿�J���O
			userInput = userCommand[userCommand->Length - 1];
		}

	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//�bDialog���UOK�K�|�i�J���禡
		//�r�����string^ to string
		std::string tempFileName;
		MarshalString(openFileDialog1->FileName, tempFileName);
		//�N�ɮ׸��|�W�ٶǤJdataManager
		dataManager->SetFileName(tempFileName);

		if (this->VectorLabel->Text == L"Vector") {
			openVectorDialog1_FileOk();
		}
		else if (this->VectorLabel->Text == L"Matrix"){
			openMatrixDialog1_FileOk();
		}
		else {
			Output->Text += "- File Name Error -" + Environment::NewLine;
		}

	}
	private: System::Void openVectorDialog1_FileOk() {

		//�qŪ��Ū���V�q���
		if (dataManager->LoadVectorData())
		{
			//�NVectorList�����إ����M��
			VectorList->Items->Clear();
			//���o�Ҧ��V�q���
			std::vector<Vector> vectors = dataManager->GetVectors();

			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//�N�ɮצW�٦s�J�Ȧs
				std::string tempString = vectors[i].Name;
				//�N��X�榡�s�J�Ȧs
				tempString += " [";
				//�N��X��Ʀs�J�Ȧs
				for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//�N��X�榡�s�J�Ȧs
				tempString += "]";
				//�N���إ[�JVectorList��
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
		}
	}
	private: System::Void openMatrixDialog1_FileOk() {
		//�qŪ��Ū���V�q���
		if (dataManager->LoadMatrixData())
		{
			//�NVectorList�����إ����M��
			VectorList->Items->Clear();
			//���o�Ҧ��V�q���
			std::vector<Matrix> matrices = dataManager->GetMatrices();

			for (unsigned int i = 0; i < matrices.size(); i++)
			{
				//�N�ɮצW�٦s�J�Ȧs
				std::string tempString = matrices[i].Name;
				//�N��X�榡�s�J�Ȧs
				tempString += " [";
				//�N��X��Ʀs�J�Ȧs
				for (unsigned int r = 0; r < matrices[i].Data.size(); r++)
				{
					for (unsigned int c = 0; c < matrices[i].Data[r].getDim(); c++) {
						std::string scalarString = std::to_string(matrices[i].Data[r].Data[c]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (r != matrices[i].Data.size() -1 || c != matrices[i].Data[r].getDim() - 1)
						tempString += ",";  
					}
				}
				//�N��X�榡�s�J�Ȧst
				tempString += "]";
				//�N���إ[�JVectorList��
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			std::vector <Vector> mat = Power_Method(matrices[2]);
			for (int i = 0; i < mat.size(); i++) {
				for (int j = 0; j < mat[i].Data.size(); j++) {
					std::cout << mat[i].Data[j] << " ";
				}
				std::cout << std::endl;
			}
			//std::cout << Determinant(matrices[1]);
			Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
		}
	}
};
}
