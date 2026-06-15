# define PI 3.141592653589793
# define LN2 0.6931471805599453
# define decor1 printf("===========================================\n")

long double facto(int);
double ratpower(double,double);
double power1(double,double);  // made specifically to improve efficency while calulating logs with integer power , i did,nt wanted to stess ratpower here ,
double tsin (double);
double tcos(double);
double ttan(double);
double tcsc(double);
double tsec(double);
double tcot(double);
double log1(double);
//reduce number of line from original code
//after these aagin test run your code in forked scintofic calculatorr

int main() {
	char choice[1];
	printf("_______________________________________________\n");
	printf("you are currently using a scientific calculator\n");
	printf("_______________________________________________\n");
	printf("You can perform \n1.>factorial\n2.>powering of a number\n3.>calculate trignometric values\n4.> calculate logrithmic values\n5.>EXIT\n\n");

	while(1) {
		int inchoice=1;
		printf("\nCHOOSE ANY OF THE ABOVE NUMBER(1-5) TO PERFORM CERTAIN CALC.(*5=EXIT)\n ");
		scanf("%s", choice);
		switch(choice[0]) {

		case '1': {
			int numfacto;
			while(1) {
				printf("\n============factorail mode==============\n");
				printf("enter value to calculate its factorial : ");
				scanf("%d",&numfacto);
				printf("\nIts factorial : %.0Lf \n",facto(numfacto));
				printf("If you want to stop using factorial enter 0 : ");
				scanf("%d",&inchoice);
				if(inchoice==0) {
					decor1;
					printf("exiting factorail bye...\n");
					decor1;
					break;
				}
				}
				break;
		}

		case '2':
			while(1) {
				double numberpow,powpow;
				printf("\n============exponential mode==============\n");
				printf("enter number and its power(rational/integer) respectively: \n");
				scanf("%lf %lf",&numberpow,&powpow);
				printf("\nIts value after powering : %lf \n",ratpower(numberpow,powpow));
				printf("If you want to stop using exponential enter 0 : ");
				scanf("%d",&inchoice);
				if(inchoice==0) {
					decor1;
					printf("exiting exponential bye...\n");
					decor1;
					break;
				}
			}
			break;

		case '3': {
			int inloopbreak=1;
			int choice3;
			double angldeg;
			printf("\n============trignometric mode==============\n");
			printf("Choose trignometric operation you want to perform respectively \n");
			printf("1.> sin@\n2.> cos@\n3.> tan@\n4.> cosec@\n5.> sec@\n6.> cot@\n7.>Exit Trignomerty mode\n");
			while(inloopbreak!=0) {
				scanf("%d",&choice3);
				if(choice3<1||choice3>6) {
					printf("\nyou enterd wrong input \n");
					choice3=8;
				}
				else {
					printf("Enter the angle @ in degrees : ");
					scanf("%lf",&angldeg);
					if(angldeg>999999999) {
						printf("\nyou entered value too large\n");
						choice3=7;
					}
					while (angldeg >= 360.0)
						angldeg -= 360.0;
					while (angldeg < 0.0)
						angldeg += 360.0;
				}

				switch(choice3) {
				case 1:
					printf("\nvalue for sin@ : %lf\n",tsin(angldeg));
					break;
		}
				case 2:
					printf("\nvalue for cos@ : %lf\n",tcos(angldeg));
					break;
				case 3:
					printf("\nvalue for tan@ : %lf\n",ttan(angldeg));
					break;
				case 4:
					printf("\nvalue for csc@ : %lf\n",tcsc(angldeg));
					break;
				case 5:
					printf("\nvalue for sec@ : %lf\n",tsec(angldeg));
					break;
				case 6:
					printf("\nvalue for cot@ : %lf\n",tcot(angldeg));
					break;
				case 7:
					inloopbreak=0;
					break;

				default:
					printf("please verify your choices and choose again(*7=EXIT)\n");
				}
				printf("\nhope you are satisfied please choose any operation again to continue... [or press 7 to exit ]\n");
			}
			break;

		case '4' :
			while(1) {
				double numlog1;
				printf("\n============log mode==============\n");
				printf("Enter value of log : ");
				scanf("%lf",&numlog1);
				printf("\nvalue of log a : %lf \n",log1(numlog1));
				printf("If you want to stop using log enter 0 : ");
				scanf("%d",&inchoice);
				if(inchoice==0) {
					decor1;
					printf("exiting log bye...\n");
					decor1;
					break;
				}
			}
			break;
		case '5' :
			printf("\n ...exiting calculator...\n");
			return 0;

		default: 
			decor1;
			printf("\nplease verify your choices again... \n");
			decor1;
			break;
		}
	}
	return 0;
}

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
	int flag=0;
	while (numlog1>0&&numlog1<1) {
		numlog1=1/numlog1;
		flag=1;
	}

	while(numlog1>2) {
		numlog1/=2;
		times2++;
	}
	for(int i=1; i<1000; i++) {
		sum+= sign*power1(numlog1-1,i)/i;
		sign=-sign;
	}

	if(flag==0)return sum+(times2*LN2);
	else return -(sum+(times2*LN2));
}
