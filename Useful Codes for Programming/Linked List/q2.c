#include "List.h"
#include "Polynomial.h"
#include<stdlib.h>
#include<stdio.h>
int main(){
	int i,n,inp;
	scanf("%d",&i);
	while(i!=-1){
		switch(i){
			case 1:{
				Polynomial *p1 = (Polynomial*)malloc(sizeof(Polynomial));
    			p1->exponents = llist_new();
    			p1->coeffs = llist_new();
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->coeffs,inp);
				}
				print_polynomial(*p1);
				break;

			}
			case 2:{
				Polynomial *p1 = (Polynomial*)malloc(sizeof(Polynomial));
    			p1->exponents = llist_new();
    			p1->coeffs = llist_new();
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->coeffs,inp);
				}
				int deg=get_degree(*p1);
				printf("%d\n",deg);
				break;
			}
			case 3:{
				Polynomial *p1 = (Polynomial*)malloc(sizeof(Polynomial));
    			p1->exponents = llist_new();
    			p1->coeffs = llist_new();
    			Polynomial *p2 = (Polynomial*)malloc(sizeof(Polynomial));
    			p2->exponents = llist_new();
    			p2->coeffs = llist_new();
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->coeffs,inp);
				}
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p2->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p2->coeffs,inp);
				}

				Polynomial pa = add(*p1,*p2);
				print_polynomial(pa);
				break;

			}
			case 4:{
				Polynomial *p1 = (Polynomial*)malloc(sizeof(Polynomial));
    			p1->exponents = llist_new();
    			p1->coeffs = llist_new();
    			Polynomial *p2 = (Polynomial*)malloc(sizeof(Polynomial));
    			p2->exponents = llist_new();
    			p2->coeffs = llist_new();
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->coeffs,inp);
				}
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p2->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p2->coeffs,inp);
				}
				Polynomial pb = subtract(*p1,*p2);
				print_polynomial(pb);
				break;
			}
			case 5:{
				Polynomial *p1 = (Polynomial*)malloc(sizeof(Polynomial));
    			p1->exponents = llist_new();
    			p1->coeffs = llist_new();
    			Polynomial *p2 = (Polynomial*)malloc(sizeof(Polynomial));
    			p2->exponents = llist_new();
    			p2->coeffs = llist_new();
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->coeffs,inp);
				}
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p2->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p2->coeffs,inp);
				}
				Polynomial pm = multiply(*p1,*p2);
				print_polynomial(pm);
				break;
			}
			case 6:{
				Polynomial *p1 = (Polynomial*)malloc(sizeof(Polynomial));
    			p1->exponents = llist_new();
    			p1->coeffs = llist_new();
    			Polynomial *p2 = (Polynomial*)malloc(sizeof(Polynomial));
    			p2->exponents = llist_new();
    			p2->coeffs = llist_new();
				scanf("%d",&n);
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->exponents,inp);
				}
				for (int i = 0; i < n; ++i)
				{
					scanf("%d",&inp);
					llist_append(p1->coeffs,inp);
				}
				scanf("%d",&n);
				
				long long int val= evaluate(*p1, n);
				break;
			}
		}
		scanf("%d",&i);
	}
}