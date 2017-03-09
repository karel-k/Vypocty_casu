/*
 * vypocet_t.h
 *
 *  Created on: 9. 3. 2017
 *      Author: karel.kolomaznik
 */

//#ifndef VYPOCET_T_H_
//#define VYPOCET_T_H_

double vypocet_t(double t_zadani_dne, double t_zadani_casu)
{
	double A, R, N, E, JDN, JD, YYYY, MM, DD, zbytek, t;
	double *ukazatel;
// JD = úplné juliánské datum, se zapoètením èasu v rámci dne, , který ale zaèíná až v poledne.
// Proto je tøeba pøièíst èasový údaj a odeèíst 12 hodin
// MJD = Modifikované Julianske datuma odvozuje se od juliánského data: MJD = JD - 2 400 000.5

	ukazatel = &zbytek;    						// v ukazateli "ukazatel" je hodnota adresy promenne zbytek */
	YYYY = (modf (t_zadani_dne, ukazatel)*10000);
	DD = trunc(zbytek/100) ;
	MM = zbytek - (100 * DD) ;

if (MM <= 2.0)
	A = 1.0;
else
	A = 0.0;
R = YYYY + 4800.0 - A;
N = MM + 12.0 * A - 3.0;
E = DD + floor((153.0 * N + 2.0)/5.0);
JDN = E + (365.0 * R) + floor(R / 4.0) - floor(R / 100.0) + floor(R / 400.0) - 32045.0;
JD = JDN - 0.5 + (t_zadani_casu/24.0);

// t = JD - 2451545.0; 										    // Cas ve dnech od epochy J2000.0
// T = t/36525.0 + 1.0;									    	// Cas v julianskych stoletich od epochy 1950
t = (JD - 2451545.0) / 365250.0;    							// vstup pro VSOP, zlomky stoleti
return (t);
}


// #endif /* VYPOCET_T_H_ */
