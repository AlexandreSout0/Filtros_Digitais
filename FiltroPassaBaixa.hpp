

/*=======================================================================

 __    __   __   _______ .______      ______   ___   ___  __   _______    ______   
|  |  |  | |  | |       \ |   _  \   /  __  \  \  \ /  / |  | |       \  /  __  \  
|  |__|  | |  | |  .--.  ||  |_)  | |  |  |  |  \  V  /  |  | |  .--.  ||  |  |  | 
|   __   | |  | |  |  |  ||      /  |  |  |  |   >   <   |  | |  |  |  ||  |  |  | 
|  |  |  | |  | |  '--'  ||  |\  \ .|  `--'  |  /  .  \  |  | |  '--'  ||  `--'  | 
|__|  |__| |__| |_______/ | _| `._|  \______/  /__/ \__\ |__| |_______/  \______/  
                                                                    Alexandre Souto 
  FILTROS DIGITAIS
	
   Filtro Passa - Baixa IIR de Primeira Ordem.
	FiltroPassaBaixa.hpp

   ARDUINO
   Board: Arduino Uno.
   Compilador: Arduino IDE 1.8.13

   Autor: Alexandre Souto
   Data:  Novembro 2021


				   #########################
				##  |                       | ##
			 ## 	|						|	##
		  ##		|						|	  ##
	    ##			|						|		##
     ##				|						|		  ##
----------------------------------------------------------------
 					6HZ						15HZ				
 			Corte do passa                  corte do passa
 			altas                             baixa
ˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆ^
     
======================================================================= */
namespace DSP
{
	class FiltroPassaBaixa
	{

		private:
			const float k;
			float state;


		public:
			FiltroPassaBaixa(const float &_k)
			: k(_k) // Mantem o k Constante
			{

			}

			FiltroPassaBaixa(const float &fc, const float &dt)
			: k (1.f / ((6.283f * dt * fc) + 1.f))
			{

			}
	
			float update(const float &input)
			{
				this ->state = state;

				state = k * state + (1.f - k) * input;
				return state;

			}

	};
}






