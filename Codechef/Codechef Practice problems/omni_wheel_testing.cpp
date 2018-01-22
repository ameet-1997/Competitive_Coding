#include<stdio.h>
#include<math.h>
#define PI 3.14152

int main()
{	float max(float,float);
	int x,y;
	float theta,maxi,o1,o2,o3;
	printf("Enter two integers:");
	scanf("%d%d",&x,&y);
	if ( x > 0 && y < 0 ) 
  {theta = atan( fabs((float)y/x)); // It is in radians
  }
  else if ( x < 0 && y < 0)
  {
  theta = PI - atan( fabs((float)y/x));}
  else if ( x > 0 && y > 0 )
  {theta = 2*PI - atan( fabs((float)y/x));
  }
  
  else if ( x < 0 && y > 0 )
  {theta = PI + atan( fabs((float)y/x));}
  else if ( x == 0 && y < 0 )
  {
  theta = PI/2.0;}
  else if ( x == 0 && y > 0 )
  {
  theta = 3*PI/2.0;}
  else if ( x > 0 && y == 0 )
  {
  theta = 0;}
  else if ( x < 0 && y == 0 )
  {
  theta = PI ;}
  //theta=theta*180/PI;
  printf("%f--------\n",theta);
  maxi=max(max(fabs(cos(theta)),fabs(sin(theta+PI/6))),fabs(sin(PI/6-theta)));
	o1=fabs(cos(theta))/maxi*255;
	o2=fabs(sin(theta+PI/6))/maxi*255;
	o3=fabs(sin(PI/6-theta))/maxi*255;
	printf("**%f--%f--%f--%f--",maxi,o1,o2,o3);
}

float max(float a,float b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
