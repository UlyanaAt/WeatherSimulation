#include "MyForm.h"
#include <time.h>
#include <string>
#include <cmath>
using namespace WeatherSimulation;
using namespace System::Windows::Forms;

// Application entry point
[STAThreadAttribute]
void main(array<String^>^ args) {
    // Initial Application Parameters:
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    WeatherSimulation::MyForm form;
    Application::Run(% form);
    srand(time(NULL));
}

double DoubleRand(double _max, double _min)
{
    double m = _min + double(rand()) / RAND_MAX * (_max - _min);
    return m;
}

System::Void WeatherSimulation::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
    double c = log(DoubleRand(1, 0));
    tau = c / arr[i][i];
    t = t + tau;
    int j = 0;
    float RandNumb = DoubleRand(1, 0);
    while (RandNumb > 0)
    {
        RandNumb = RandNumb - dist[i][j];
        j++;
    }
    i = j - 1;
    chart1->Series[0]->Points->AddXY(t, i);
    g = t / 24;
    g = g * 24;
    if (t < g*2 && g<2*t)
    {
        chart1->Series[1]->Points->AddXY(g, 0);
    }

    if (t > T && k<N)
    {
        Dur[i_prev] = Dur[i_prev] + (t - t_prev);
        i_prev = i;
        t_prev = t;
        k++;
    }
    
    i_prev = i;
    t_prev = t;
}

System::Void WeatherSimulation::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    NumOfClick += 1;

    if (NumOfClick % 2 == 0)
    {
        timer1->Stop();
        if (i = 0)
        {
            pd->Text = "sunny, day: " + ((g / 24) + 1).ToString();
        }
        else if (i = 1)
        {
            pd->Text = "clowdy, day: " + ((g / 24) + 1).ToString();
        }
        else
        {
            pd->Text = "rainy, day: " + ((g / 24) + 1).ToString();
        }

        float dur = Dur[0] + Dur[1] + Dur[2];
        for (int i = 0; i < 3; i++)
        {
            Dur[i] = Dur[i]/dur;
        }
        sun->Text = Dur[0].ToString();
        cl->Text = Dur[1].ToString();
        rain->Text = Dur[2].ToString();
    }
    else
    {
        this->chart1->Series[0]->Points->Clear();
        this->chart1->Series[1]->Points->Clear();
        g = 0;
        i = 0;
        t = 0;
        i_prev = 0;
        t_prev = 0;
        k = 0;
        for (int i = 0; i < 3; i++)
        {
            Dur[i] = 0;
        }
        timer1->Start();
    }
    chart1->Series[0]->Points->AddXY(t, i);
    chart1->Series[1]->Points->AddXY(0, 0);
}


