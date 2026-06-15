#include <stdio.h>
#define PI 3.141592653589793
#define LN2 0.6931471805599453
#define decor1 printf("===========================================\n")

long double facto(int);
double ratpower(double,double);
double power1(double,double);
double tsin(double);
double tcos(double);
double ttan(double);
double tcsc(double);
double tsec(double);
double tcot(double);
double log1(double);

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
                                      


int main() {
	char choice[10];
	printf("_______________________________________________\n");
	printf("Welcome to the Scientific Calculator!\n");
	printf("_______________________________________________\n");
	printf("Available options:\n");
	printf("1. Factorial\n");
	printf("2. Power (base ^ exponent)\n");
	printf("3. Trigonometric Functions\n");
	printf("4. Logarithm\n");
	printf("5. Exit\n\n");

	while(1) {
		int inchoice = 1;
		printf("\nEnter your choice (1-5): ");

		if (scanf("%9s", choice) != 1) {
			printf("Invalid input! Please try again.\n");
			clearBuffer();
			continue;
		}
		clearBuffer();
		switch(choice[0]) {

			case '1': {
				int numfacto;
				while(1) {
					printf("\n========== FACTORIAL ==========\n");
					printf("Enter a number: ");
					if (scanf("%d", &numfacto) != 1) {
						printf("Invalid input! Please enter an integer.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();
					
					if(numfacto>1700){printf("Number too large! Please enter below 1700.\n\n"); continue;}
					int count1=0;
					int count2=0;
                    long double roundoff=facto(numfacto);
                    if(numfacto>10){
                   
                    while(roundoff>1000000000){
                        roundoff/=1000000000;
                        count1+=9;
                    }
                    while(roundoff>10){
                        roundoff/=10;
                        count1++;
                    }
                    printf("\nFactorial = %Lf e^%d\n\n",roundoff,count1);
                        
                    }
                    else if(numfacto<0){printf("Factorial is not possible for negative numbers.\n");continue;}
                    else{ printf("\nFactorial = %Lf\n\n",roundoff);}
					 
					printf("Enter 0 to go back, any other key to continue: ");
					if (scanf("%d", &inchoice) != 1) {
						printf("Invalid input! Try again.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(inchoice==0) {
						decor1; printf("Returning to main menu...\n"); decor1; break;
					}
				}
				break;
			}

			case '2': {
				while(1) {
					double numberpow, powpow;
					printf("\n========== POWER FUNCTION ==========\n");
					printf("Enter base and exponent (example: 2 3): ");
					if (scanf("%lf %lf", &numberpow, &powpow) != 2) {
						printf("Invalid input! Please enter two numbers.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();
					if(numberpow<0){
					    int outterfalg=0;
					    double imaginarycheck=powpow;
					    while(imaginarycheck>-1){
					        imaginarycheck*=2;
					        if(imaginarycheck==-1){outterfalg=1;break;}
					    }
			        if(outterfalg==1){printf("Imaginary result! Please enter another input.\n");continue;}
					
					}
						int count2=0;
                    long double roundoff1=ratpower(numberpow,powpow);
                    if(powpow>10||numberpow>10){
                   
                    while(roundoff1>1000000000){
                        roundoff1/=1000000000;
                        count2+=9;
                    }
                    while(roundoff1>10){
                        roundoff1/=10;
                        count2++;
                    }
                    
              
					printf("\nResult = %.15Lf e^%d\n\n", roundoff1,count2);
                    }
                    else { printf("\nResult = %Le\n\n",roundoff1);}
					printf("Enter 0 to go back, any other key to continue: ");
					if (scanf("%d", &inchoice) != 1) {
						printf("Invalid input! Try again.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(inchoice==0) {
						decor1; printf("Returning to main menu...\n"); decor1; break;
					}
				}
				break;
			}

			case '3': {
				int inloopbreak=1, choice3;
				double angldeg;
				printf("\n========== TRIGONOMETRY ==========\n");
				printf("Choose a function:\n");
				printf("1. sin(x)\n2. cos(x)\n3. tan(x)\n4. cosec(x)\n5. sec(x)\n6. cot(x)\n7. Go back\n");

				while(inloopbreak!=0) {
					if (scanf("%d", &choice3) != 1) {
						printf("Invalid input! Enter a number 1–7.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(choice3<1||choice3>6) {
						if(choice3==7) { inloopbreak=0; break; }
						printf("\nInvalid choice! Try again:\n");
						printf("1. sin(x)\n2. cos(x)\n3. tan(x)\n4. cosec(x)\n5. sec(x)\n6. cot(x)\n7. Go back\n");
						continue;
					}

					printf("Enter angle in degrees: ");
					if (scanf("%lf", &angldeg) != 1) {
						printf("Invalid input! Enter a number.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(angldeg>999999999) {
						printf("\nAngle too large! Try again.\n");
						continue;
					}
					while(angldeg>=360.0) angldeg-=360.0;
					while(angldeg<0.0) angldeg+=360.0;

					switch(choice3) {
						case 1: printf("\nsin(%.2lf) = %.10lf\n", angldeg, tsin(angldeg)); break;
						case 2: printf("\ncos(%.2lf) = %.10lf\n", angldeg, tcos(angldeg)); break;
						case 3: printf("\ntan(%.2lf) = %.10lf\n", angldeg, ttan(angldeg)); break;
						case 4: printf("\ncosec(%.2lf) = %.10lf\n", angldeg, tcsc(angldeg)); break;
						case 5: printf("\nsec(%.2lf) = %.10lf\n", angldeg, tsec(angldeg)); break;
						case 6: printf("\ncot(%.2lf) = %.10lf\n", angldeg, tcot(angldeg)); break;
					}
					printf("\nChoose another function or press 7 to go back:\n");
                    printf("1. sin(x)\n2. cos(x)\n3. tan(x)\n4. cosec(x)\n5. sec(x)\n6. cot(x)\n7. Go back\n");				
				    }
				break;
			}

			case '4': {
				while(1) {
					double numlog1;
					printf("\n========== LOGARITHM ==========\n");
					printf("Enter a positive number: ");
					if (scanf("%lf", &numlog1) != 1) {
						printf("Invalid input! Enter a valid number.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();
					if(numlog1==0){printf("Logarithm of 0 is infinite.\n");
				    continue;	}
                    if(numlog1<0){printf("Logarithm not possible for negative numbers.\n");
				    continue;	}
                    
					printf("\nln(%.2lf) = %lf\n", numlog1, log1(numlog1));
					printf("Enter 0 to go back, any other key to continue: ");
					if (scanf("%d", &inchoice) != 1) {
						printf("Invalid input! Try again.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(inchoice==0) {
						decor1; printf("Returning to main menu...\n"); decor1; break;
					}
				}
				break;
			}

			case '5': printf("\nThank you for using the Scientific Calculator. Goodbye!\n"); return 0;

			default: decor1; printf("\nInvalid choice! Please enter a number from 1 to 5.\n"); decor1; break;
		}
	}
	return 0;
}

long double facto(int numfacto) {
	long double f=1;
	for(int i=numfacto; i>=1; i--) f*=i;
	return f;
}

double ratpower(double numberpow,double powpow) {
	int tempflag=0;
	int tempflag2=0;
	if(numberpow<0){numberpow=-numberpow; tempflag=1;}
	if(powpow<0){powpow=-powpow;tempflag2=1;}
	int count=(int)powpow;
	powpow -= count;
	double fractionpow=1, term=1, powx=log1(numberpow)*powpow;
	for(int i=1; i<=20; i++){ term*=powx/i; fractionpow+=term; }
	if(tempflag==1&&tempflag2==0)return -1*fractionpow * power1(numberpow,count);
	else if(tempflag2==1&&tempflag==0) return 1/(fractionpow * power1(numberpow,count));
	else if(tempflag2==1&&tempflag==1){ return -1/(fractionpow * power1(numberpow,count));}
	else return fractionpow * power1(numberpow,count);

    
}

double power1(double numberpow,double powpow) {
	double rslpow=1;
	for(int i=1; i<=powpow; i++) rslpow*=numberpow;
	return rslpow;
}

double tsin(double angldeg) {
	int sign=1;
	if(angldeg>180){ angldeg-=180; angldeg=-angldeg; }
	if(angldeg>90&&angldeg<=180){ angldeg-=180; angldeg=-angldeg; }
	double rad=angldeg*(PI/180), sum=0;
	for(int i=1;i<=17;i+=2){ sum+=sign*power1(rad,i)/facto(i); sign=-sign; }
	return sum;
}

double tcos(double angldeg){ return tsin(90-angldeg); }
double ttan(double angldeg){ return tsin(angldeg)/tcos(angldeg); }
double tcsc(double angldeg){ return 1/tsin(angldeg); }
double tsec(double angldeg){ return 1/tcos(angldeg); }
double tcot(double angldeg){ return 1/ttan(angldeg); }

double log1(double numlog1) {
	double sum=0; int times2=0, sign=1, flag=0;
	while(numlog1>0&&numlog1<1){ numlog1=1/numlog1; flag=1; }
	while(numlog1>2){ numlog1/=2; times2++; }
	for(int i=1;i<1000;i++){ sum+=sign*power1(numlog1-1,i)/i; sign=-sign; }
	if(flag==0) return sum+(times2*LN2);
	else return -(sum+(times2*LN2));
}
