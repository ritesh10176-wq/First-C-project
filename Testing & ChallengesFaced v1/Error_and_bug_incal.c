#include <stdio.h>
#define PI 3.141592653589793
#define LN2 0.6931471805599453
#define decor1 printf("===========================================\n")

long double facto(int n){ long double f=1; for(int i=n;i>=1;i--) f*=i; return f; }

double power1(double a,double b){ double r=1; for(int i=1;i<=b;i++) r*=a; return r; }

double log1(double x){
	double s=0; int t=0,sign=1;
	while(x>2){ x/=2; t++; }
	for(int i=1;i<1000;i++){ s+=sign*power1(x-1,i)/i; sign=-sign; }
	return s+(t*LN2);                                                                     //wrong input by user handling (check)
	                                                                                      //wrong input for continuing the loop (check)
}                                                                                         //trignomety large input and code crash (fix)
                                                                                          //reduce number of line from original code
                                                                                          //log logic fix for inputs b/w 0-1 and add line for neg inputs in output
                                                                                          //after these aagin test run your code in forked scintofic calculatorr
                                                                                          //  log -ve input vaule handling 
                                                                                          // factorail -ve input value handling
double ratpower(double a,double b){                                                       
	int c=(int)b; b-=c;                                                                   
	double f=1,term=1,p=log1(a)*b;
	for(int i=1;i<=20;i++){ term*=p/i; f+=term; }
	return f*power1(a,c);
}

double tsin(double d){
	int sign=1; if(d>180){ d-=180; d=-d; } if(d>90&&d<=180){ d-=180; d=-d; }
	double r=d*(PI/180),s=0; for(int i=1;i<=17;i+=2){ s+=sign*power1(r,i)/facto(i); sign=-sign; }
	return s;
}

double tcos(double d){ return tsin(90-d); }
double ttan(double d){ return tsin(d)/tcos(d); }
double tcsc(double d){ return 1/tsin(d); }
double tsec(double d){ return 1/tcos(d); }
double tcot(double d){ return 1/ttan(d); }

int main(){
	int choice=1;
	printf("_______________________________________________\n");
	printf("You are currently using a scientific calculator\n");
	printf("_______________________________________________\n");
	printf("You can perform\n1.> Factorial\n2.> Powering\n3.> Trigonometric values\n4.> Logarithmic values\n5.> EXIT\n\n");

	while(choice<=5){
		printf("\nCHOOSE (1-5) TO PERFORM (*5=EXIT): ");
restart:	scanf("%d",&choice);
		if(choice>5){ printf("\nWrong input\nTo continue press any key or 0 to exit: "); int b; scanf("%d",&b); if(b>0) goto restart; else return 0; }

		int inchoice=1;
		switch(choice){
			case 1: while(1){
				int n; printf("\n============Factorial Mode==============\nEnter number: "); scanf("%d",&n);
				printf("Result: %.0Lf\n",facto(n));
				printf("Stop? (0=Yes): "); scanf("%d",&inchoice);
				if(!inchoice){ decor1; printf("Exiting factorial...\n"); decor1; break; }
			} break;

			case 2: while(1){
				double a,b; printf("\n============Power Mode==============\nEnter base and exponent: ");
				scanf("%lf %lf",&a,&b);
				printf("Result: %lf\n",ratpower(a,b));
				printf("Stop? (0=Yes): "); scanf("%d",&inchoice);
				if(!inchoice){ decor1; printf("Exiting power...\n"); decor1; break; }
			} break;

			case 3: while(1){
				int c; double d;
				printf("\n============Trigonometric Mode==============\n1.sin 2.cos 3.tan 4.csc 5.sec 6.cot\nEnter choice: ");
				scanf("%d",&c); printf("Enter angle in degrees: "); scanf("%lf",&d);
				while(d>=360)d-=360; while(d<0)d+=360;
				switch(c){
					case 1: printf("sin@ = %lf\n",tsin(d)); break;
					case 2: printf("cos@ = %lf\n",tcos(d)); break;
					case 3: printf("tan@ = %lf\n",ttan(d)); break;
					case 4: printf("csc@ = %lf\n",tcsc(d)); break;
					case 5: printf("sec@ = %lf\n",tsec(d)); break;
					case 6: printf("cot@ = %lf\n",tcot(d)); break;
					default: printf("Wrong input\n");
				}
				printf("Stop? (0=Yes): "); scanf("%d",&inchoice);
				if(!inchoice){ decor1; printf("Exiting trigonometry...\n"); decor1; break; }
			} break;

			case 4: while(1){
				double x; printf("\n============Log Mode==============\nEnter value: "); scanf("%lf",&x);
				printf("log(a) = %lf\n",log1(x));
				printf("Stop? (0=Yes): "); scanf("%d",&inchoice);
				if(!inchoice){ decor1; printf("Exiting log...\n"); decor1; break; }
			} break;

			case 5: printf("\n...Exiting calculator...\n"); return 0;
			default: decor1; printf("Wrong input\n"); decor1;
		}
	}
	return 0;
}
