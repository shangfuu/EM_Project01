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
	/// MyForm 的摘要
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
		/// 清除任何使用中的資源。
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
			 /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
			 /// 這個方法的內容。
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
				 this->menuStrip2->Size = System::Drawing::Size(927, 24);
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
				 this->FileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
				 this->FileToolStripMenuItem->Text = L"File";
				 // 
				 // LoadVectorToolStripMenuItem
				 // 
				 this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
				 this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
				 this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::LoadVectorToolStripMenuItem_Click);
				 // 
				 // loadMatrixToolStripMenuItem
				 // 
				 this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
				 this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(143, 22);
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
				 this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 1;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 505)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(927, 648);
				 this->tableLayoutPanel1->TabIndex = 2;
				 // 
				 // flowLayoutPanel1
				 // 
				 this->flowLayoutPanel1->Controls->Add(this->InputLabel);
				 this->flowLayoutPanel1->Controls->Add(this->Input);
				 this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
				 this->flowLayoutPanel1->Controls->Add(this->VectorList);
				 this->flowLayoutPanel1->Location = System::Drawing::Point(466, 3);
				 this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
				 this->flowLayoutPanel1->Size = System::Drawing::Size(458, 642);
				 this->flowLayoutPanel1->TabIndex = 0;
				 // 
				 // InputLabel
				 // 
				 this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->InputLabel->AutoSize = true;
				 this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->InputLabel->Location = System::Drawing::Point(3, 0);
				 this->InputLabel->Name = L"InputLabel";
				 this->InputLabel->Size = System::Drawing::Size(41, 16);
				 this->InputLabel->TabIndex = 0;
				 this->InputLabel->Text = L"Input";
				 // 
				 // Input
				 // 
				 this->Input->Location = System::Drawing::Point(3, 19);
				 this->Input->Multiline = true;
				 this->Input->Name = L"Input";
				 this->Input->Size = System::Drawing::Size(446, 247);
				 this->Input->TabIndex = 1;
				 this->Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Input_TextChanged);
				 // 
				 // VectorLabel
				 // 
				 this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->VectorLabel->AutoSize = true;
				 this->VectorLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->VectorLabel->Location = System::Drawing::Point(3, 269);
				 this->VectorLabel->Name = L"VectorLabel";
				 this->VectorLabel->Size = System::Drawing::Size(47, 16);
				 this->VectorLabel->TabIndex = 2;
				 this->VectorLabel->Text = L"Vector";
				 // 
				 // VectorList
				 // 
				 this->VectorList->FormattingEnabled = true;
				 this->VectorList->HorizontalScrollbar = true;
				 this->VectorList->ItemHeight = 12;
				 this->VectorList->Location = System::Drawing::Point(3, 288);
				 this->VectorList->Name = L"VectorList";
				 this->VectorList->Size = System::Drawing::Size(446, 340);
				 this->VectorList->TabIndex = 3;
				 // 
				 // flowLayoutPanel2
				 // 
				 this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
				 this->flowLayoutPanel2->Controls->Add(this->Output);
				 this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
				 this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
				 this->flowLayoutPanel2->Size = System::Drawing::Size(457, 642);
				 this->flowLayoutPanel2->TabIndex = 1;
				 // 
				 // OutputLabel
				 // 
				 this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->OutputLabel->AutoSize = true;
				 this->OutputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->OutputLabel->Location = System::Drawing::Point(3, 0);
				 this->OutputLabel->Name = L"OutputLabel";
				 this->OutputLabel->Size = System::Drawing::Size(52, 16);
				 this->OutputLabel->TabIndex = 0;
				 this->OutputLabel->Text = L"Output";
				 // 
				 // Output
				 // 
				 this->Output->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(136)));
				 this->Output->Location = System::Drawing::Point(3, 19);
				 this->Output->Multiline = true;
				 this->Output->Name = L"Output";
				 this->Output->ReadOnly = true;
				 this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Both;
				 this->Output->Size = System::Drawing::Size(440, 614);
				 this->Output->TabIndex = 1;
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(927, 672);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->Controls->Add(this->menuStrip2);
				 this->Name = L"MyForm";
				 this->Text = L"Project 1";
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
		//開啟Dialog
		openFileDialog1->ShowDialog();
	}
	private: System::Void LoadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->VectorLabel->Text = L"Matrix";
		//開啟Dialog
		openFileDialog1->ShowDialog();
	}
	private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		//當Input textbox中的輸入改變時，便會進入此函式
		//取得向量資料
		std::vector<Vector> vectors = dataManager->GetVectors();
		std::vector<Matrix> matrices = dataManager->GetMatrices();

		//判斷輸入自元為'\n'，並防止取到字串-1位置
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//將使用者輸入字串(在userInput中)，依空白作切割
			array<String^> ^userCommand = userInput->Split(' ');
			/* 判斷錯誤指令 */
			VECTOR_ERROR Error = Correct;
			MATRIX_ERROR M_Error = M_Correct;

			//清除output
			if (userCommand[0] == "/c" && userCommand[1] == "o") {
				Output->Text = "";
			}
			//查看指令
			else if (userCommand[0] == "/help" && userCommand->Length == 1) {
				Output->Text += Environment::NewLine + "==> \" /help \" -m to See Matrix Command Format" + Environment::NewLine +
					"==> \" /help \" -v to See Vector Command Format" + Environment::NewLine +
					"==> \" /c o \" to Clear Output List" + Environment::NewLine +
					"==> \" /c i \" to Clear Input List" + Environment::NewLine +
					"==> * Must have Space between each Operator or variable" + Environment::NewLine + Environment::NewLine;
			}
			//清除input
			else if (userCommand[0] == "/c" && userCommand[1] == "i") {
				Input->Text = "";
			}
			// 如果有 Load Vector
			else if (dataManager->HasVector() && this->VectorLabel->Text == L"Vector") {

				if (userCommand[0] == "/help" && userCommand[1] == "-v") {
					Output->Text += Environment::NewLine + "Vector Operation Command Format:" + Environment::NewLine +
						"* v can be Mutiple Matrix Operation *" + Environment::NewLine + "-- e.g v = v0 + v1 - v2" + Environment::NewLine +
						"- Print :  print v" + Environment::NewLine + "- Multiple Vector Support : MVS v" + Environment::NewLine +
						"- Dot :  Dot ( v , v )" + Environment::NewLine + "- Add : Add ( v , v )" + Environment::NewLine +
						"- Scalar :  Scalar ( v , v )" + Environment::NewLine + "- Norm : Norm ( v )" + Environment::NewLine +
						"- Normal :  Normal ( v )" + Environment::NewLine + "- Cross Product : Cross ( v , v )" + Environment::NewLine +
						"- Component :  Com ( v , v )" + Environment::NewLine + "- Projection : Proj ( v , v )" + Environment::NewLine +
						"- Triangle Area :  Area ( v , v )" + Environment::NewLine + "- IsParallel : IsPrl ( v , v )" + Environment::NewLine +
						"- IsOrthogonal :  IsOrg ( v , v )" + Environment::NewLine + "- Angle : Angle ( v , v )" + Environment::NewLine +
						"- PN :  pN ( v , v )" + Environment::NewLine + "- Is Linear Independent : IsLI ( v , v , .... )" + Environment::NewLine +
						"- Ob :  Ob ( v , v , .... )" + Environment::NewLine +
						Environment::NewLine;
				}
				else if (userCommand[0] == "print")
				{
					////定意輸出暫存
					//String^ outputTemp = "";
					////透過for迴圈，從向量資料中找出對應變數
					//for (unsigned int i = 0; i < vectors.size(); i++)
					//{
					//	//若變數名稱與指令變數名稱符合
					//	if (userCommand[1] == gcnew String(vectors[i].Name.c_str()))
					//	{
					//		//將輸出格式存入暫存
					//		outputTemp += "[";
					//		//將輸出資料存入暫存
					//		for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
					//		{
					//			outputTemp += vectors[i].Data[j].ToString();
					//			if (j != vectors[i].Data.size() - 1)
					//				outputTemp += ",";
					//		}
					//		//將輸出格式存入暫存，並且換行
					//		outputTemp += "]" + Environment::NewLine;
					//		//輸出暫存資訊
					//		Output->Text += gcnew String(vectors[i].Name.c_str()) + " = " + outputTemp;
					//		break;
					//	}
					//}
					Vector result = MVS(userCommand, vectors, Error);

					if (Error == Correct) {
						Output->Text += "-->" + Environment::NewLine;
						for (int i = 0; i < result.getDim(); i++) {
							Output->Text += result.Data[i].ToString();
							if (i != result.getDim() - 1)	Output->Text += ",  ";
						}
						Output->Text += Environment::NewLine;
					}
				}
				else if (userCommand[0] == "MVS") {

					Vector result = MVS(userCommand, vectors, Error);

					if (Error == Correct) {
						Output->Text += "-->" + Environment::NewLine;
						for (int i = 0; i < result.getDim(); i++) {
							Output->Text += result.Data[i].ToString();
							if (i != result.getDim() - 1)	Output->Text += ",  ";
						}
						Output->Text += Environment::NewLine;
					}
				}
				else if (userCommand[0] == "Dot") {
					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						/* 維度相同才可 Dot*/
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = vec1 * vec2;

							/* 輸出處理 */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Add") {

					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						/* 維度相同才可 Add*/
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = vec1 + vec2;

							/* 輸出處理 */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Scalar") {

					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						// 維度至少要一個一維
						if (vec1.getDim() > 1 && vec2.getDim() > 1) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Scalar(vec1, vec2);

							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Norm") {
					Vector vec;
					// 指令格式
					Format_One(userCommand, vectors, Error, vec);

					if (Error == Correct) {
						double tmp = Norm(vec);

						Output->Text += "-->" + Environment::NewLine + tmp.ToString() + "  " + Environment::NewLine;
					}
				}
				else if (userCommand[0] == "Normal") {
					/* Normal 只處理單一向量 */
					Vector vec;
					// 指令格式
					Format_One(userCommand, vectors, Error, vec);

					if (Error == Correct) {
						Vector tmp = Normal(vec);

						Output->Text += "-->" + Environment::NewLine;
						for (int i = 0; i < tmp.getDim(); i++) {
							Output->Text += tmp.Data[i].ToString() + "  ";
						}
						Output->Text += Environment::NewLine;
					}
				}
				else if (userCommand[0] == "Cross") {
					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						// 只處理三維
						if (vec1.getDim() != 3 && vec2.getDim() != 3) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Cross(vec1, vec2);

							/* 處理輸出 */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Com") {
					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Comp(vec1, vec2);

							/* 處理輸出 */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Proj") {
					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Proj(vec1, vec2);
							/* 輸出處理 */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Area") {
					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						if (vec1.getDim() != vec2.getDim()) {
							Error = Dim_Error;
						}
						else {
							double trigArea = TrigArea(vec1, vec2);

							/* 處理輸出 */
							Output->Text += "-->" + Environment::NewLine + trigArea.ToString() + Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "IsPrl") {

					Vector vec1, vec2;
					// 指令格式
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
				}
				else if (userCommand[0] == "IsOrg") {
					Vector vec1, vec2;
					// 指令格式
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
				}
				else if (userCommand[0] == "Angle") {
					Vector vec1, vec2;
					// 指令格式
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
				}
				else if (userCommand[0] == "pN") {
					// 此項讀取"pn" 和 "Cross"一樣 輸出product() 都是算外積

					Vector vec1, vec2;
					// 指令格式
					Format_Two(userCommand, vectors, Error, vec1, vec2);

					if (Error == Correct) {
						// 只處理三維
						if (vec1.getDim() != 3 && vec2.getDim() != 3) {
							Error = Dim_Error;
						}
						else {
							Vector tmp = Cross(vec1, vec2);

							/* 處理輸出 */
							Output->Text += "-->" + Environment::NewLine;
							for (int i = 0; i < tmp.getDim(); i++) {
								Output->Text += tmp.Data[i].ToString();
								if (i != tmp.getDim() - 1)	Output->Text += ",  ";
							}
							Output->Text += Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "IsLI") {
					// 支援多項量輸入
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
							Matrix tmp;
							for (int i = 0; i < vecs.size(); i++) {
								tmp.Data.push_back(vecs[i]);
							}
							std::string Ans = "";
							if (IsLI(tmp)) Ans = "Yes";
							else Ans = "No";
							Output->Text += "-->" + Environment::NewLine + gcnew String(Ans.c_str()) + Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Ob") {
					// 支援多項量輸入
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
							/* 輸出處理 */
							Output->Text += "-->" + Environment::NewLine + gcnew String("normal") + "  " + tmp.size().ToString() + Environment::NewLine;
							for (unsigned int i = 0; i < tmp.size(); i++) {
								for (unsigned int j = 0; j < tmp[i].getDim(); j++) {
									Output->Text += tmp[i].Data[i].ToString();
									if (i != tmp[i].getDim() - 1)	Output->Text += ",  ";
								}
								Output->Text += Environment::NewLine;
							}

						}
					}
				}
				//反之則判斷找不到指令
				else
				{
					Output->Text += "- Command not found -" + Environment::NewLine + "==> \" /help \" to See More" + Environment::NewLine;
				}
				// 指令錯誤
				if (Error == E_Error) {
					Output->Text += "- Command Format Error -" + Environment::NewLine + "==> \" /help \" to See More" + Environment::NewLine;
				}
				else if (Error == VN_Error) {
					Output->Text += "- Variable Name Not Found -" + Environment::NewLine;
				}
				else if (Error == Dim_Error) {
					Output->Text += "- Vector Dimesion Not the Same -" + Environment::NewLine;
				}

			}
			// 如果有 Load Matrix
			else if (dataManager->HasMatrix() && this->VectorLabel->Text == L"Matrix") {

				if (userCommand[0] == "/help" && userCommand[1] == "-m") {
					Output->Text += Environment::NewLine + "Matrix Operation Command Format:" + Environment::NewLine +
						"* mx can be Mutiple Matrix Operation *" + Environment::NewLine + "-- e.g mx = m0 + m1 - m2" + Environment::NewLine +
						"- Print :  print mx" + Environment::NewLine + "- Multiple Matrix Operation : MMO mx" + Environment::NewLine +
						"- Add : Add ( mx , mx )" + Environment::NewLine + "- Sub : Sub ( mx , mx )" + Environment::NewLine +
						"- Multiple : Multi ( mx , mx )" + Environment::NewLine + "- Rank : Rank ( mx )" + Environment::NewLine +
						"- Transpose : Trans ( mx )" + Environment::NewLine + "- Solve Linear System : Solve ( mx \\ mx )" + Environment::NewLine +
						"- Determinants : Det ( mx )" + Environment::NewLine + "- Inverse : Inv ( mx )" + Environment::NewLine +
						"- Adjoint : Adj ( mx )" + Environment::NewLine + "- Eigen Vector and Eigen Value : Eigen ( mx )" + Environment::NewLine +
						"- Power Method : PM ( mx )" + Environment::NewLine + "LeastSquare : LS ( mx , mx )" + Environment::NewLine +
						Environment::NewLine;
				}
				else if (userCommand[0] == "print") {
					bool isIn = false;
					//定意輸出暫存
					//String^ outputTemp = "";
					////透過for迴圈，從向量資料中找出對應變數
					//for (unsigned int i = 0; i < matrices.size(); i++)
					//{
					//	//若變數名稱與指令變數名稱符合
					//	if (userCommand->Length > 1 && userCommand[1] == gcnew String(matrices[i].Name.c_str()))
					//	{
					//		////將輸出格式存入暫存
					//		//outputTemp += "[";
					//		////將輸出資料存入暫存
					//		//for (unsigned int r = 0; r < matrices[i].Data.size(); r++)
					//		//{
					//		//	for (unsigned int c = 0; c < matrices[i].Data[r].getDim(); c++) {
					//		//		outputTemp += matrices[i].Data[r].Data[c].ToString();
					//		//		if (c != matrices[i].Data[r].getDim() - 1)
					//		//			outputTemp += ",";
					//		//	}
					//		//	if(r != matrices[i].Data.size() -1)
					//		//	outputTemp += Environment::NewLine;
					//		//}
					//		////將輸出格式存入暫存，並且換行
					//		//outputTemp += "]" + Environment::NewLine;
					//		////輸出暫存資訊
					//		//Output->Text += gcnew String(matrices[i].Name.c_str()) + " = " + Environment::NewLine + outputTemp;
					//		isIn = true;
					//		Matrix mat = matrices[i];
					//		mat.print(Output);
					//		break;
					//	}
					//}
					Matrix mat = Multi_Matrix_Op(userCommand, matrices, M_Error);
					if (M_Error == M_Correct) {
						mat.print(Output);
					}
				}
				else if (userCommand[0] == "MMO") {
					Matrix mat = Multi_Matrix_Op(userCommand, matrices, M_Error);
					if (M_Error == M_Correct) {
						mat.print(Output);
					}
				}
				else if (userCommand[0] == "Add") {
					Matrix mat1, mat2;
					Format_Two(userCommand, matrices, M_Error, mat1, mat2);
					if (M_Error == M_Correct) {
						if (mat1.getRow() != mat2.getRow() || mat1.getCol() != mat2.getCol()) {
							M_Error = RC_Error;
						}
						else {
							Matrix tmp = mat1 + mat2;
							tmp.print(Output);
						}
					}
				}
				else if (userCommand[0] == "Sub") {
					Matrix mat1, mat2;
					Format_Two(userCommand, matrices, M_Error, mat1, mat2);
					if (M_Error == M_Correct) {
						if (mat1.getRow() != mat2.getRow() || mat1.getCol() != mat2.getCol()) {
							M_Error = RC_Error;
						}
						else {
							Matrix tmp = mat1 - mat2;
							tmp.print(Output);
						}
					}
				}
				else if (userCommand[0] == "Multi") {
					Matrix mat1, mat2;
					Format_Two(userCommand, matrices, M_Error, mat1, mat2);
					if (M_Error == M_Correct) {
						if (mat1.getCol() != mat2.getRow()) {
							M_Error = RC_Error;
						}
						else {
							Matrix tmp = mat1 * mat2;
							tmp.print(Output);
						}
					}
				}
				else if (userCommand[0] == "Rank") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						int rank = mat.Rank();
						Output->Text += "Rank(" + gcnew String(mat.Name.c_str()) + ")" + Environment::NewLine + rank.ToString() + Environment::NewLine;
					}
				}
				else if (userCommand[0] == "Trans") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						mat = Transpose(mat);
						mat.Name = "Trans(" + mat.Name + ")";
						mat.print(Output);
					}
				}
				else if (userCommand[0] == "Solve") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						mat.print(Output);
					}
				}
				else if (userCommand[0] == "Det") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						if (mat.getCol() != mat.getRow()) {
							Output->Text += "- Matrix Must be Square Matrix" + Environment::NewLine;
						}
						else {
							double det = Determinant(mat);
							Output->Text += "Det(" + gcnew String(mat.Name.c_str()) + ")" + Environment::NewLine + det.ToString() + Environment::NewLine;
						}
					}
				}
				else if (userCommand[0] == "Inv") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						if (mat.getCol() != mat.getRow()) {
							Output->Text += "- error" + Environment::NewLine;
						}
						else {
							mat = Inverse(mat);
							mat.Name = "Inv(" + mat.Name + ")";
							mat.print(Output);
						}
					}
				}
				else if (userCommand[0] == "Adj") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						if (mat.getCol() != mat.getRow()) {
							Output->Text += "- Matrix Must be Square Matrix" + Environment::NewLine;
						}
						else {
							mat = Adjoint(mat);
							mat.Name = "Adj(" + mat.Name + ")     " + std::to_string(mat.getCol()) + " " + std::to_string(mat.getRow());
							mat.print(Output);
						}
					}
				}
				else if (userCommand[0] == "Eigen") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						if (mat.getCol() != mat.getRow()) {
							Output->Text += "- Matrix Must be Square Matrix" + Environment::NewLine;
						}
						else if (mat.getCol() > 3) {
							Output->Text += "- error" + Environment::NewLine;
						}
						else {
							int sizeV = mat.getCol();
							mat = Eigen(mat);
							if (mat.Name == "Error") {
								Output->Text += "- error " + Environment::NewLine;
							}
							else {
								Output->Text += "Eigen(" + gcnew String(mat.Name.c_str()) + ")" + Environment::NewLine;
								Matrix eVector, eValue;
								for (int i = 0; i < mat.getRow(); i++) {
									Vector tmpVec, tmpVal;
									for (int j = 0; j < mat.getCol(); j++) {
										if (i < sizeV && j < sizeV) {
											tmpVal.Data.push_back(mat.Data[i].Data[j]);
											//	eValue.Data[i].Data[j] = mat.Data[i].Data[j];
										}
										else {
											tmpVec.Data.push_back(mat.Data[i].Data[j]);
											//	eVector.Data[i].Data[j] = mat.Data[i].Data[j];
										}
									}
									eVector.Data.push_back(tmpVec);
									eValue.Data.push_back(tmpVal);
								}
								eVector.Name = "v";
								eValue.Name = "d";
								eVector.print(Output);
								eValue.print(Output);
							}
						}
					}
				}
				else if (userCommand[0] == "PM") {
					Matrix mat;
					Format_One(userCommand, matrices, M_Error, mat);
					if (!M_Error) {
						if (mat.getCol() != mat.getRow()) {
							Output->Text += "- Matrix Must be Square Matrix" + Environment::NewLine;
						}
						else {
							std::vector<Vector>PM = Power_Method(mat);
							Output->Text += "PM(" + gcnew String(mat.Name.c_str()) + ")" + Environment::NewLine
								+ "v = " + Environment::NewLine;

							for (int i = 0; i < PM.size() && i < 2; i++) {
								if (i == 1) {
									Output->Text += "d = " + Environment::NewLine;
								}
								for (int j = 0; j < PM[i].getDim(); j++) {
									if (j == 0)
										Output->Text += PM[i].Data[j].ToString();
									else
										Output->Text += ",  " + PM[i].Data[j].ToString();
								}
								Output->Text += Environment::NewLine;
							}
						}
					}
				}
				else if (userCommand[0] == "LS") {
					Matrix mat1, mat2;
					Format_Two(userCommand, matrices, M_Error, mat1, mat2);
					if (!M_Error) {
						if (mat2.getRow() != mat1.getRow() || mat2.getCol() != 1) {
							M_Error = RC_Error;
						}
						else {
							Matrix mat = LeastSquare(mat1, mat2);
							mat.Name = "LS(" + mat1.Name + "," + mat2.Name + ")";
							mat.print(Output);
						}
					}
				}
				else {
					Output->Text += "- Command not found -" + Environment::NewLine + "==> \" /help \" to See More" + Environment::NewLine;
				}

				/* Error LOG */
				if (M_Error == M_ERROR) {
					Output->Text += "- Command Format Error" + Environment::NewLine + "==> \" /help \" to See More" + Environment::NewLine;
				}
				else if (M_Error == RC_Error) {
					Output->Text += "- Illegal Operation between Two Matrices" + Environment::NewLine;
				}
				else if (M_Error == VN_ErrorM) {
					Output->Text += "- Variable Name Not Found" + Environment::NewLine;
				}
			}
			else {
				Output->Text += "- Select your File first " + Environment::NewLine;
			}
			userInput = "";
		}
		else
		{
			//將使用者輸入字串(在Text box中)，依'\n'作切割
			array<String^> ^userCommand = Input->Text->Split('\n');
			//並將最後一行，作為目前使用者輸入指令
			userInput = userCommand[userCommand->Length - 1];
		}

	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//在Dialog按下OK便會進入此函式
		//字串轉制string^ to string
		std::string tempFileName;
		MarshalString(openFileDialog1->FileName, tempFileName);
		//將檔案路徑名稱傳入dataManager
		dataManager->SetFileName(tempFileName);
		//清空所有儲存資料
		dataManager->clear();

		if (this->VectorLabel->Text == L"Vector") {
			openVectorDialog1_FileOk();
		}
		else if (this->VectorLabel->Text == L"Matrix") {
			openMatrixDialog1_FileOk();
		}
		else {
			Output->Text += "- File Name Error -" + Environment::NewLine;
		}

	}
	private: System::Void openVectorDialog1_FileOk() {

		//從讀取讀取向量資料
		if (dataManager->LoadVectorData())
		{
			//將VectorList中項目先做清除
			VectorList->Items->Clear();

			//取得所有向量資料
			std::vector<Vector> vectors = dataManager->GetVectors();

			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//將檔案名稱存入暫存
				std::string tempString = vectors[i].Name;
				//將輸出格式存入暫存
				tempString += " [";
				//將輸出資料存入暫存
				for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//將輸出格式存入暫存
				tempString += "]";
				//將項目加入VectorList中
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
		}
	}
	private: System::Void openMatrixDialog1_FileOk() {
		//從讀取讀取向量資料
		if (dataManager->LoadMatrixData())
		{
			//將VectorList中項目先做清除
			VectorList->Items->Clear();

			//取得所有向量資料
			std::vector<Matrix> matrices = dataManager->GetMatrices();

			for (unsigned int i = 0; i < matrices.size(); i++)
			{
				//將檔案名稱存入暫存
				std::string tempString = matrices[i].Name;
				//將輸出格式存入暫存
				tempString += " [";
				//將輸出資料存入暫存
				for (unsigned int r = 0; r < matrices[i].Data.size(); r++)
				{
					for (unsigned int c = 0; c < matrices[i].Data[r].getDim(); c++) {
						std::string scalarString = std::to_string(matrices[i].Data[r].Data[c]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if (r != matrices[i].Data.size() - 1 || c != matrices[i].Data[r].getDim() - 1)
							tempString += ",";
					}
				}
				//將輸出格式存入暫存
				tempString += "]";
				//將項目加入VectorList中
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
		}
	}
	};
}
