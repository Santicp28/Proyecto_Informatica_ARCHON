#include "Cambiaforma.h"
#include "Pieza.h"

Cambiaforma::Cambiaforma(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::VARIABLE,              
    Vida_maxima::VARIABLE,                
    Velocidad::VARIABLE,           
    Cadencia::VARIABLE,            
    Velocidad_ataque::VARIABLE,    
	Rango::LARGO,
    b,                             
    TipoMovimiento::VUELA           
) {
}
void Cambiaforma::copiarStatsSuperiores(const Pieza& rival)
{
    // calculamos la diferencia de cada stat (positivo = rival es mejor)
    double difAtaque = rival.getAtaque() - ataque;
    double difVelocidad = rival.getVelocidad() - velocidadMax;
    double difVelAtaque = rival.getVelocidadAtaque() - velocidad_ataque;
    double difCadencia = cadencia - rival.getCadencia(); // invertida: rival menor = rival mejor

    // encuentra la diferencia mayor
    double maxDif = difAtaque;
    int peor = 0;
    if (difVelocidad > maxDif) { maxDif = difVelocidad; peor = 1; }
    if (difVelAtaque > maxDif) { maxDif = difVelAtaque; peor = 2; }
    if (difCadencia > maxDif) { maxDif = difCadencia;   peor = 3; }

    // solo sube el stat con mayor diferencia
    switch (peor) {
    case 0:
        ataque = rival.getAtaque() * 1.1;
        break;
    case 1:
        velocidadMax = rival.getVelocidad() * 1.1;
        break;
    case 2:
        velocidad_ataque = rival.getVelocidadAtaque() * 1.1;
        break;
    case 3:
        cadencia = rival.getCadencia() * 0.66;
        break;
    }
}