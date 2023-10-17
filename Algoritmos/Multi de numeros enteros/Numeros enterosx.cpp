#include <iostream>
#include <math.h>

//Frida Estrada Borja
//Loredo Cortes Luis Josue
//Ramírez Rodriguez Ricardo Daniel

//Analisis de Algoritmos 


int size_base10(int num)						
{									
	int remainder = 1;						 
	int power = 1;							
	int count = 0;						 
	do								
	{								
		remainder = num / power;		
		count++;						
		power *= 10;
	} while (remainder >= 10);
	return count;
}

int max(int num1, int num2)
{				
	if (num1 > num2)						
		return num1;						
	else
		return num2;
}

int karatsuba(int num1, int num2)
{
	int a, b, c, d;								
										
	if ((num1 < 10) && (num2 < 10))					
		return num1 * num2;

	int max_num_of_digits = max(size_base10(num1), size_base10(num2));	
	int half_of_digits = 0;							

	if (max_num_of_digits % 2 == 0)
		half_of_digits = max_num_of_digits / 2;				
	else									
		half_of_digits = (max_num_of_digits / 2) + 1;			

	a = num1 / (int)pow(10, half_of_digits);							
	b = num1 % (int)pow(10, half_of_digits);							
	c = num2 / (int)pow(10, half_of_digits);							
	d = num2 % (int)pow(10, half_of_digits);

	int step1 = karatsuba(a, c);									
	int step2 = karatsuba(b, d);									
	int step3 = karatsuba((a + b), (c + d));						
	int step4 = step3 - step2 - step1;								
	int step5 = (step1 * pow(10, 2* half_of_digits)) + step2 + (step4 * pow(10, half_of_digits));

	return step5;
}

int main()
{
	int input1, input2;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "-    MULTIPLICACIÓN DE DOS NÚMEROS ENTEROS      -" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "- INGRESAR EL PRIMER NÚMERO:                    -" << std::endl;
	std::cout << "  ";
	std::cin >> input1;
	std::cout << "- INGRESAR EL SEGUNDO NÚMERO:                   -" << std::endl;
	std::cout << "  ";
	std::cin >> input2;
	std::cout << "- RESULTADOS DE LA MULTIPLICACIÓN               -" << std::endl;
	std::cout << "- " << input1 << " * " << input2 << " = " << karatsuba(input1, input2) << "                                 -" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	system("PAUSE");
	return 0;
}
