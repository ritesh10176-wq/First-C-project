#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h> // needed for strcmp
#define PI 3.141592653589793
#define LN2 0.6931471805599453
#define decor1 printf("===========================================\n")

// your existing function declarations...
long double facto(int);
double ratpower(double,double);
double power1(double,double);
double tsin (double);
double tcos(double);
double ttan(double);
double tcsc(double);
double tsec(double);
double tcot(double);
double log1(double);

// ================= BENCHMARK FUNCTION ==================
void compare_with_mathh(char* op, double myval, double stdval) {
    double diff = fabs(myval - stdval);
    double percentErr = 0.0;
    if (fabs(stdval) > 1e-12)
        percentErr = (diff / fabs(stdval)) * 100.0;

    printf("   [Benchmark] %-4s | yours: %.10lf | math.h: %.10lf | diff: %.10e | err: %.8lf%%\n",
           op, myval, stdval, diff, percentErr);
}

// ================= MAIN ==================
int main() {
    int choice=1;
    printf("_______________________________________________\n");
    printf("you are currently using a scientific calculator\n");
    printf("_______________________________________________\n");
    printf(" You can perform \n1.>factorial\n2.>powering of a number\n3.>calculate trignometric values\n4.> calculate logrithmic values\n5.>EXIT\n");

    while(choice<=5) {
        printf("\nCHOOSE ANY OF THE ABOVE NUMBER(1-5) TO PERFORM CERTAIN CALC.(*5=EXIT)\n  ");
        scanf("%d",&choice);

        if(choice>5){ printf("\nwrong operation\n"); break; }
        int inchoice=1;

        switch(choice) {

        case 1: { // factorial
            int numfacto;
            while(1){
                printf("\n============factorial mode==============\n");
                printf("enter value to calculate its factorial : ");
                scanf("%d",&numfacto);
                long double my = facto(numfacto);
                printf("\nIts factorial : %.0Lf\n", my);
                long double ref = 1; for(int i=1;i<=numfacto;i++) ref*=i;
                long double diff = fabsl(my - ref);
                double err = (ref != 0) ? ((diff / ref) * 100.0) : 0.0;
                printf("   [Benchmark] factorial(%d) | yours: %.0Lf | ref: %.0Lf | diff: %.0Lf | err: %.8Lf%%\n",
                       numfacto, my, ref, diff, err);

                printf("If you want to stop using factorial enter 0 : ");
                scanf("%d",&inchoice);
                if(inchoice==0){ decor1; printf("exiting factorial...\n"); decor1; break; }
            }
            break;
        }

        case 2: { // power
            while(1){
                double base, exp;
                printf("\n============exponential mode==============\n");
                printf("enter number and its power: ");
                scanf("%lf %lf",&base,&exp);
                double my = ratpower(base,exp);
                printf("\nIts value after powering : %lf\n", my);
                compare_with_mathh("pow", my, pow(base, exp));
                printf("If you want to stop using exponential enter 0 : ");
                scanf("%d",&inchoice);
                if(inchoice==0){ decor1; printf("exiting exponential...\n"); decor1; break; }
            }
            break;
        }

        case 3: { // trigonometry
            while(1){
                int choice3;
                double angldeg;
                printf("\n============trignometric mode==============\n");
                printf("1.> sin@\n2.> cos@\n3.> tan@\n4.> cosec@\n5.> sec@\n6.> cot@\n");
                scanf("%d",&choice3);
                printf("Enter the angle @ in degrees : ");
                scanf("%lf",&angldeg);
                while(angldeg >= 360.0) angldeg -= 360.0;
                while(angldeg < 0.0) angldeg += 360.0;
                double rad = angldeg * PI / 180.0;

                double my, std;
                switch(choice3) {
                    case 1: my=tsin(angldeg); std=sin(rad); printf("sin(%g)=%.6f\n",angldeg,my); compare_with_mathh("sin",my,std); break;
                    case 2: my=tcos(angldeg); std=cos(rad); printf("cos(%g)=%.6f\n",angldeg,my); compare_with_mathh("cos",my,std); break;
                    case 3: my=ttan(angldeg); std=tan(rad); printf("tan(%g)=%.6f\n",angldeg,my); compare_with_mathh("tan",my,std); break;
                    case 4: my=tcsc(angldeg); std=1/sin(rad); printf("csc(%g)=%.6f\n",angldeg,my); compare_with_mathh("csc",my,std); break;
                    case 5: my=tsec(angldeg); std=1/cos(rad); printf("sec(%g)=%.6f\n",angldeg,my); compare_with_mathh("sec",my,std); break;
                    case 6: my=tcot(angldeg); std=1/tan(rad); printf("cot(%g)=%.6f\n",angldeg,my); compare_with_mathh("cot",my,std); break;
                    default: printf("\nwrong input\n"); continue;
                }
                printf("If you want to stop using trignometry enter 0 : ");
                scanf("%d",&inchoice);
                if(inchoice==0){ decor1; printf("exiting trignometry...\n"); decor1; break; }
            }
            break;
        }

        case 4: { // logarithm
            while(1){
                double numlog1;
                printf("\n============log mode==============\n");
                printf("Enter value of log : ");
                scanf("%lf",&numlog1);
                double my = log1(numlog1);
                printf("\nvalue of log a : %lf\n",my);
                compare_with_mathh("ln", my, log(numlog1));
                printf("If you want to stop using log enter 0 : ");
                scanf("%d",&inchoice);
                if(inchoice==0){ decor1; printf("exiting log...\n"); decor1; break; }
            }
            break;
        }

        case 5:
            printf("\n ...exiting calculator... \n");
            return 0;
        }
    }
    return 0;
}

// ================= FUNCTION DEFINITIONS ==================
long double facto (int numfacto) {
	long double f=1;
	for(int i=numfacto ; i>=1; i--) {
		f*=i;
	}
	return f;
}

double ratpower(double numberpow,double powpow ) {
	int tempnum=numberpow;
	int count = (int)powpow;
	powpow = powpow - count;

	double fractionpow=1;
	double term=1;
	double powx = log1(numberpow)*powpow;

	for(int i=1; i<=20; i++) {
		term*=powx/i;
		fractionpow+=term;
	}
	double integerpow=power1(numberpow,count);
	return fractionpow * integerpow;
}

double power1(double numberpow,double powpow ) {
	double rslpow=1;
	for(int i=1; i<=powpow; i++) {
		rslpow*=numberpow;
	}
	return rslpow;
}

double tsin (double angldeg) {
	int sign=1;
	if(angldeg>180) {
		angldeg-=180;
		angldeg=-angldeg;
	}
	if(angldeg>90&&angldeg<=180) {
		angldeg-=180;
		angldeg=-angldeg;
	}

	double rad = angldeg*(PI/180);
	double sum=0;
	for(int i=1 ; i<=17; i+=2) {
		sum+=sign*power1(rad,i)/facto(i);
		sign=-sign;
	}
	return sum;
}

double tcos(double angldeg) {
	return tsin(90-angldeg);
}

double ttan (double angldeg) {
	return tsin(angldeg)/tcos(angldeg);
}

double tcsc(double angldeg) {
	return 1/tsin(angldeg);
}

double tsec(double angldeg) {
	return 1/tcos(angldeg);
}

double tcot(double angldeg) {
	return 1/ttan(angldeg);
}

double log1(double numlog1) {
	double sum=0;
	int times2=0;
	int sign=1;
	while(numlog1>2) {
		numlog1/=2;
		times2++;
	}
	for(int i=1; i<1000; i++) {
		sum+= sign*power1(numlog1-1,i)/i;
		sign=-sign;
	}
	return sum+(times2*LN2);
}
