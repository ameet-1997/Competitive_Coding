#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "List.h"

typedef struct Polynomial_lst{
	LList* exponents;
	LList* coeffs;
}Polynomial;


/*function to return the degree of the polynomial*/
int get_degree(Polynomial p1);

// print Polynomial
void print_polynomial(Polynomial p1);

/*Multiply two polynomials and return the result*/
Polynomial multiply(Polynomial p1, Polynomial p2);

/*Add two polynomials and return the result*/
Polynomial add(Polynomial p1, Polynomial p2);

/*Subtract second Polynomial from first*/
Polynomial subtract(Polynomial p1, Polynomial p2);

/*Evaluate Polynomial at var=k and return the result*/
long long int evaluate(Polynomial p1, int k);
#endif