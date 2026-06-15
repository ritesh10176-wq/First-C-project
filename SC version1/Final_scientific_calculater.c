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
	printf("you are currently using a scientific calculator\n");
	printf("_______________________________________________\n");
	printf("You can perform \n1.>factorial\n2.>powering of a number\n3.>calculate trignometric values\n4.>calculate natural logrithmic values\n5.>EXIT\n\n");

	while(1) {
		int inchoice = 1;
		printf("\nCHOOSE ANY OF THE ABOVE NUMBER(1-5) TO PERFORM CERTAIN CALC.(*5=EXIT)\n ");

		if (scanf("%s", choice) != 1) {
			printf("Invalid input! Try again.\n");
			clearBuffer();
			continue;
		}
		clearBuffer();
		switch(choice[0]) {

			case '1': {
				int numfacto;
				while(1) {
					printf("\n============factorail mode==============\n");
					printf("enter value to calculate its factorial (floting number are automatically moded): ");
					if (scanf("%d", &numfacto) != 1) {
						printf("Invalid input! Please enter an integer.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();
					
					if(numfacto>1700){printf("Please choose number below 1700 [program reached numerical overflow ]\n\n"); continue;}
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
                    printf("\nIts factorial : %Lf 10^%d\n\n",roundoff,count1);
                        
                    }
                    else if (numfacto < 0 || numfacto != (int)numfacto) {
                    printf("Factorial is not possible for such values — only positive integers are accepted.\n");
                    clearBuffer();
                    continue;
                    }
                    else{ printf("\nIts factorail : %Lf\n\n",roundoff);}
					 
					printf("If you want to stop using factorial enter 0 : ");
					if (scanf("%d", &inchoice) != 1) {
						printf("Invalid input! Please enter an integer.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(inchoice==0) {
						decor1; printf("exiting factorail bye...\n"); decor1; break;
					}
				}
				break;
			}

			case '2': {
				while(1) {
					double numberpow, powpow;
					printf("\n============exponential mode==============\n");
					printf("enter base and exponential(decimal or integer) respectively: \n");
					if (scanf("%lf %lf", &numberpow, &powpow) != 2) {
						printf("Invalid input! Please enter valid numbers.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();
					if(numberpow<0){
					    int outterfalg=0;
					    double imaginarycheck=powpow;
					    while(imaginarycheck>-1){
					        imaginarycheck*=2;
					        if(imaginarycheck==-1||imaginarycheck==1){outterfalg=1;break;}
					    }
			        if(outterfalg==1){printf("Powering such case result in imaginary number please choose another input");continue;}
					
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
                    
              
					printf("\nIts value after powering k: %.15Lf 10^%d\n\n", roundoff1,count2);
                    }
                    else { printf("\nIts value after powering : %Le\n\n",roundoff1);}
					printf("If you want to stop using exponential enter 0 : ");
					if (scanf("%d", &inchoice) != 1) {
						printf("Invalid input! Please enter 0 or 1.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(inchoice==0) {
						decor1; printf("exiting exponential bye...\n"); decor1; break;
					}
				}
				break;
			}

			case '3': {
				int inloopbreak=1, choice3;
				double angldeg;
				printf("\n============trignometric mode==============\n");
				printf("Choose trignometric operation you want to perform respectively \n");
				printf("1.> sin@\n2.> cos@\n3.> tan@\n4.> cosec@\n5.> sec@\n6.> cot@\n7.>Exit Trignomerty mode\n");

				while(inloopbreak!=0) {
					if (scanf("%d", &choice3) != 1) {
						printf("Invalid input! Enter a number between 1-7.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(choice3<1||choice3>6) {
						if(choice3==7) { inloopbreak=0; break; }
						printf("\nyou entered wrong input \n");
						printf("1.> sin@\n2.> cos@\n3.> tan@\n4.> cosec@\n5.> sec@\n6.> cot@\n7.>Exit Trignomerty mode\n");
						continue;
					}

					printf("Enter the angle @ in degrees : ");
					if (scanf("%lf", &angldeg) != 1) {
						printf("Invalid input! Please enter a number again b/w 1-7.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(angldeg>999999999) {
						printf("\nyou entered value too large please choose an operation from 1-7 again \n");
						continue;
					}
					while(angldeg>=360.0) angldeg-=360.0;
					while(angldeg<0.0) angldeg+=360.0;

					switch(choice3) {
						case 1: printf("\nvalue for sin@ : %.10lf\n", tsin(angldeg)); break;
						case 2: printf("\nvalue for cos@ : %.10lf\n", tcos(angldeg)); break;
						case 3: printf("\nvalue for tan@ : %.10lf\n", ttan(angldeg)); break;
						case 4: printf("\nvalue for csc@ : %.10lf\n", tcsc(angldeg)); break;
						case 5: printf("\nvalue for sec@ : %.10lf\n", tsec(angldeg)); break;
						case 6: printf("\nvalue for cot@ : %.10lf\n", tcot(angldeg)); break;
					}
					printf("\nchoose any operation again to continue... [or press 7 to exit ]\n");
                    printf("1.> sin@\n2.> cos@\n3.> tan@\n4.> cosec@\n5.> sec@\n6.> cot@\n7.>Exit Trignomerty mode\n");				
				    }
				break;
			}

			case '4': {
				while(1) {
					double numlog1;
					printf("\n============Natural log mode==============\n");
					printf("Enter value of log : ");
					if (scanf("%lf", &numlog1) != 1) {
						printf("Invalid input! Please enter a number.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();
					if(numlog1==0){printf("log is infinte value ");
				    continue;	}
                    if(numlog1<0){printf("log is not possible for -ve values ");
				    continue;	}
                    
					printf("\nvalue of log a : %lf \n", log1(numlog1));
					printf("If you want to stop using log enter 0 : ");
					if (scanf("%d", &inchoice) != 1) {
						printf("Invalid input! Please enter 0 or 1.\n");
						clearBuffer();
						continue;
					}
					clearBuffer();

					if(inchoice==0) {
						decor1; printf("exiting log bye...\n"); decor1; break;
					}
				}
				break;
			}

			case '5': printf("\n ...exiting calculator...\n"); return 0;

			default: decor1; printf("\nplease verify your choices again... \n"); decor1; break;
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