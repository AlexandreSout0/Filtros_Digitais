

/*=======================================================================

 __    __   __   _______ .______      ______   ___   ___  __   _______    ______   
|  |  |  | |  | |       \ |   _  \   /  __  \  \  \ /  / |  | |       \  /  __  \  
|  |__|  | |  | |  .--.  ||  |_)  | |  |  |  |  \  V  /  |  | |  .--.  ||  |  |  | 
|   __   | |  | |  |  |  ||      /  |  |  |  |   >   <   |  | |  |  |  ||  |  |  | 
|  |  |  | |  | |  '--'  ||  |\  \ .|  `--'  |  /  .  \  |  | |  '--'  ||  `--'  | 
|__|  |__| |__| |_______/ | _| `._|  \______/  /__/ \__\ |__| |_______/  \______/  
                                                                    Alexandre Souto 
  FILTROS DIGITAIS

   Filtro Passa - Alta IIR de Primeira Ordem.
	FiltroPassaAlta.hpp

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
	class FiltroPassaAlta
	{

		private:
			const float k;
			float state;
			float _der;

		public:
			FiltroPassaAlta(const float &_k)
			: k(_k) // Mantem o k Constante
			{
				
			}

			FiltroPassaAlta(const float &fc, const float &dt)
			: k (1.f/((6.823f * fc * dt) + 1))
			{

			}

			float update(const float &input)
			{
				this -> state = state;
				this -> _der = _der;
				
				state = k * (state + (input - _der));
				_der = input;

				return state;


			}

	};
}






