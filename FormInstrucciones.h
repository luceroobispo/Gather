#pragma once

namespace GatherJuego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormInstrucciones
	/// </summary>
	public ref class FormInstrucciones : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ Instruciones;
	public:
		FormInstrucciones(void)
		{
			InitializeComponent();
			Instruciones = gcnew Bitmap("Instrucciones.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FormInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormInstrucciones::timer1_Tick);
			// 
			// FormInstrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1287, 953);
			this->Name = L"FormInstrucciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"INSTRUCCIONES";
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bgc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bg = bgc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		int ancho, alto;
		ancho = (int)gr->VisibleClipBounds.Width;
		alto = (int)gr->VisibleClipBounds.Height;

		bg->Graphics->DrawImage(Instruciones, 0, 0, ancho, alto);

		bg->Render(gr);

		delete bg;
		delete bgc;
		delete gr;
	}
	};
}
