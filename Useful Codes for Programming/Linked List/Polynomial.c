#include "Polynomial.h"
#include<stdio.h>
#include<stdlib.h>



int get_degree(Polynomial p1)  //Function to return the degree of the polynomial
{
    
    int size;   //To store the length of the polynomial
    
    size=llist_size(p1.exponents);
    
    return llist_get(p1.exponents,size-1);
    
    
}
    

    
    
    
    
void print_polynomial(Polynomial p1)   //Prints the polynomial
{
    int size;   //To store the length of the polynomial
    int value;  //To store the given value
    int i;  //Loop variable
    int pe,pc,pre=0,prc=0;
    
    Node *exp,*coef;
    
    
    exp=(p1.exponents)->head;  //Pointers for traversing
    coef=(p1.coeffs)->head;
    
    size=llist_size(p1.exponents);

    i=0;

    while(exp!=NULL)
    {
        value=exp->data;
        if(value==0)
        {
            printf("%d ",coef->data);
        }

        else
        {
            if((coef->data>0)&&(i!=0))
            {
                printf("+ %dx^%d ",coef->data,exp->data);
            }
            else if((coef->data>0)&&(i==0))
            {
                printf("%dx^%d ",coef->data,exp->data);   
            }
            else if((coef->data<0)&&(i!=0))
            {
                printf("- %dx^%d ",-coef->data,exp->data);
            }
            else if((coef->data<0)&&(i==0))
            {
                printf("%dx^%d ",coef->data,exp->data);
            }
        }
        i++;

        exp=exp->next;
        coef=coef->next;
    }

    printf("\n");
        

}




Polynomial add(Polynomial p1, Polynomial p2)  //Adds 2 polynomials and return the result
{
    
    int size_p1,size_p2;   //To store the length of the polynomial
    int value_p1,value_p2;        //To store the given value
    int i,j;  //Loop variable
    
      
    Polynomial p;               //Initialising p
    p.exponents=llist_new();
    p.coeffs=llist_new();
    
    size_p1=llist_size(p1.exponents);   //For p1--------

    size_p2=llist_size(p2.exponents);   //For p2--------
    
    
    
    i=0;
    j=0;
    
    
    while((i<=size_p1-1)&&(j<=size_p2-1))
    {
        if((llist_get(p1.exponents,i))<(llist_get(p2.exponents,j)))
        {
            llist_append(p.exponents,llist_get(p1.exponents,i));
            llist_append(p.coeffs,llist_get(p1.coeffs,i));
            i++;
        }
        
        else if((llist_get(p1.exponents,i))==(llist_get(p2.exponents,j)))
        {   if( (llist_get(p1.coeffs,i) + llist_get(p2.coeffs,j) )!=0)
            {
                llist_append(p.exponents,llist_get(p1.exponents,i));
                llist_append(p.coeffs,llist_get(p1.coeffs,i)+llist_get(p2.coeffs,j));    
            }
            
            i++;
            j++;
        }
        
        else
        {
            llist_append(p.exponents,llist_get(p2.exponents,j));
            llist_append(p.coeffs,llist_get(p2.coeffs,j));
            j++;
        }
    }
    
    
    if(i<=size_p1-1)
    {
        while(i<=size_p1-1)
        {
            llist_append(p.exponents,llist_get(p1.exponents,i));
            llist_append(p.coeffs,llist_get(p1.coeffs,i));
            i++;
        }
    }
    
    else if(j<=size_p2-1)
    {
        while(j<=size_p2-1)
        {
            llist_append(p.exponents,llist_get(p2.exponents,j));
            llist_append(p.coeffs,llist_get(p2.coeffs,j));
            j++;
        }
    }
    
    
    return p;
    
}
            
    
    
    
Polynomial subtract(Polynomial p1, Polynomial p2)   // For subtraction
{
    
    int size_p1,high_p1,size_p2,high_p2;   //To store the length of the polynomial
    int value_p1,value_p2;        //To store the given value
    int i,j;  //Loop variable
    
      
    Polynomial p;               //Initialising p
    p.exponents=llist_new();
    p.coeffs=llist_new();
    
    size_p1=llist_size(p1.exponents);   //For p1--------

    
    size_p2=llist_size(p2.exponents);   //For p2--------
    
    
    
    i=0;
    j=0;
    
    
    while((i<=size_p1-1)&&(j<=size_p2-1))
    {
        if((llist_get(p1.exponents,i))<(llist_get(p2.exponents,j)))
        {
            llist_append(p.exponents,llist_get(p1.exponents,i));
            llist_append(p.coeffs,llist_get(p1.coeffs,i));
            i++;
        }
        
        else if((llist_get(p1.exponents,i))==(llist_get(p2.exponents,j)))
        {
            if( (llist_get(p1.coeffs,i) - llist_get(p2.coeffs,j) )!=0)
            {
                llist_append(p.exponents,llist_get(p1.exponents,i));
                llist_append(p.coeffs,llist_get(p1.coeffs,i)-llist_get(p2.coeffs,j));    
            }
            i++;
            j++;
        }
        
        else
        {
            llist_append(p.exponents,llist_get(p2.exponents,j));
            llist_append(p.coeffs,-llist_get(p2.coeffs,j));
            j++;
        }
    }
    
    
    if(i<=size_p1-1)
    {
        while(i<=size_p1-1)
        {
            llist_append(p.exponents,llist_get(p1.exponents,i));
            llist_append(p.coeffs,llist_get(p1.coeffs,i));
            i++;
        }
    }
    
    else if(j<=size_p2-1)
    {
        while(j<=size_p2-1)
        {
            llist_append(p.exponents,llist_get(p2.exponents,j));
            llist_append(p.coeffs,-llist_get(p2.coeffs,j));
            j++;
        }
    }
    
    
    return p;
    
}

    
    
    
    
    
long long int evaluate(Polynomial p1, int k)  //Evaluates the polynomial
{
    long long int ans=0;
    int size;
    int temp;
    int i,j;  //Loop variable
    long long int mul=1;
    
    size=llist_size(p1.exponents);
    
    for(i=0;i<size;++i)
    {
        temp=llist_get(p1.exponents,i);
        for(j=0;j<temp;++j)
        {
            mul=mul*k;
        }
        
        ans=ans+mul*llist_get(p1.coeffs,i);
        mul=1;
    }
    printf("%lld\n",ans);
    return ans;
    
}
        
        

    
    
    
    
Polynomial multiply(Polynomial p1, Polynomial p2)   //To multiply two polynomials
{
    Polynomial p,temp;
    Node *e1,*e2,*c1,*c2;   //Marker for the polynomials
    
    p.exponents=llist_new();
    p.coeffs=llist_new();
    
    
    temp.exponents=llist_new();
    temp.coeffs=llist_new();
    
    e1=(p1.exponents)->head;
    c1=(p1.coeffs)->head;
    
    e2=(p2.exponents)->head;
    c2=(p2.coeffs)->head;   //Giving the pointer their initial values
    
    
    while(e1!=NULL)
    {
        while(e2!=NULL)
        {
            llist_append(temp.exponents,(e1->data)+(e2->data));
            llist_append(temp.coeffs,(c1->data)*(c2->data));
            e2=e2->next;
            c2=c2->next;
        }
        
        e2=(p2.exponents)->head;
        c2=(p2.coeffs)->head;   
        
        p=add(p,temp);
        
        temp.exponents=llist_new();
        temp.coeffs=llist_new();
        
        e1=e1->next;
        c1=c1->next;
    }
            
    
    return p;
    
}
    
    
    
    
    
    
    
    
    
    