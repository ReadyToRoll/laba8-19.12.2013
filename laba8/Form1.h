#pragma once

namespace laba8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(484, 367);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(522, 391);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Графики y=f(x)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

		private:
int l, b, h, w;

	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

             h = pictureBox1->Height;            // Ширина
   w = pictureBox1->Width;             // Высота

   // Osi
   e->Graphics->DrawLine(Pens::Black,0,h/2,w,h/2);
    e->Graphics->DrawLine(Pens::Black,w/2,0,w/2,h);
   
   // Strelki
   
    e->Graphics->DrawLine(Pens::Black,w-25,h/2+8,w,h/2);
     e->Graphics->DrawLine(Pens::Black,w-25,h/2-8,w,h/2);
     e->Graphics->DrawLine(Pens::Black,w/2-8,25,w/2,0);
     e->Graphics->DrawLine(Pens::Black,w/2+8,25,w/2,0);
  
   
   // Podpisi
   e->Graphics->DrawString("X",this->Font,Brushes::Black,w-15,h/2-25);
   e->Graphics->DrawString("Y",this->Font,Brushes::Black,w/2-25,5);
  
   double x1, x2, y1, y2, x, y, mx, my, x0, y0, dx,dt;


   x1 = 1;    // from
   x2 = 100;     // to

   dx = 1;     // step

   y1 = 1/1;
   y2 = 1/100;

   x = x1;
   while(x <= x2)
   {
     y = 1/x;
     if (y < y1) y1 = y;
     if (y > y2) y2 = y;
     x+=dx;
   }

   my = 0.5*h/(y2-y1);           // mashtab po osi y
   mx = w/(x2-x1);                 // mashtab po osi x

   x = x1;
   y1=1/x1;
   x+=dx;

   // Grafik:

   while(x <= x2)
   {
      y = 1/x;
      e->Graphics->DrawLine(Pens::Black,(int)(x1*mx+w/2),(int)(h/2-y1*my),(int)(x*mx+w/2),(int)(h/2-y*my));
      x1=x;
      y1=y;
      x+=dx;
   }
 
   //Mashtab:

   x1 = -1.5;    // from
   x2 = 1.5;     // to

   dt = 0.001;     // step

   y1 = -1.5;
   y2 = 1.5;

   my = h/(y2-y1);           // mashtab po osi y
   mx = w/(x2-x1);                 // mashtab po osi x
	
   //Ellips

   double t = 0;
    x1=1.3*Math::Cos(t);
    y1=1.1*Math::Sin(t);
    t+=dt;
   while(t <= 2*3.14)
   {
       x=1.3*Math::Cos(t);
       y=1.1*Math::Sin(t);
       e->Graphics->DrawLine(Pens::Red,(int)(x1*mx+w/2),(int)(h/2-y1*my),(int)(x*mx+w/2),(int)(h/2-y*my));
       t+=dt;
       x1=x;
       y1=y;
   }
			 }
	};
}
