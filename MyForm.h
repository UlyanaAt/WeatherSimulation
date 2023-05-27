#pragma once

namespace WeatherSimulation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float arr[3][3] = 
	{
		{-0.4 , 0.3, 0.1},  // sunny
		{ 0.4, -0.8, 0.4},  // clowdy
		{ 0.1, 0.4, -0.5}  // rainy
	};

	float dist[3][3] =
	{
		{0, 0.75, 0.25},
		{0.5, 0, 0.5},
		{0.2, 0.8, 0} 
	};

	float Dur[3] = { 0, 0, 0 };

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ pd;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ rain;
	private: System::Windows::Forms::Label^ cl;
	private: System::Windows::Forms::Label^ sun;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pd = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->sun = (gcnew System::Windows::Forms::Label());
			this->cl = (gcnew System::Windows::Forms::Label());
			this->rain = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->IsValueShownAsLabel = true;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(738, 581);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rain);
			this->groupBox1->Controls->Add(this->cl);
			this->groupBox1->Controls->Add(this->sun);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->pd);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(769, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(341, 581);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 49);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start/Stop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Вы остановились на:";
			// 
			// pd
			// 
			this->pd->AutoSize = true;
			this->pd->Location = System::Drawing::Point(77, 52);
			this->pd->Name = L"pd";
			this->pd->Size = System::Drawing::Size(0, 16);
			this->pd->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(77, 232);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Распределение:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(77, 275);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Солнечно:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(77, 315);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Облачно:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(77, 358);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Дождливо:";
			// 
			// sun
			// 
			this->sun->AutoSize = true;
			this->sun->Location = System::Drawing::Point(158, 275);
			this->sun->Name = L"sun";
			this->sun->Size = System::Drawing::Size(0, 16);
			this->sun->TabIndex = 7;
			// 
			// cl
			// 
			this->cl->AutoSize = true;
			this->cl->Location = System::Drawing::Point(151, 315);
			this->cl->Name = L"cl";
			this->cl->Size = System::Drawing::Size(0, 16);
			this->cl->TabIndex = 8;
			// 
			// rain
			// 
			this->rain->AutoSize = true;
			this->rain->Location = System::Drawing::Point(159, 358);
			this->rain->Name = L"rain";
			this->rain->Size = System::Drawing::Size(0, 16);
			this->rain->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1122, 605);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: int NumOfClick;
private: float t, t_prev;
private: float tau = 0;
private: int i, g, k, i_prev;
private: const float T = 50;
private: const int N = 100;
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
