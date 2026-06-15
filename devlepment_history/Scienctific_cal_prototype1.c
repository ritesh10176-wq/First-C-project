# include <stdio.h>
# define PI 3.141592653589793
# define LN2 0.6931471805599453
int facto(int);
float ratpower(float,float);
float power1(float,float);
float tsin (float);
float tcos(float);
float ttan(float);
float tcsc(float);
float tsec(float);
float tcot(float);
float trigno (int,int);
float log1(float);

int main() {
	int choice;

	printf("_______________________________________________\n");
	printf( "you are currently using a scientific calculator\n");
	printf("_______________________________________________\n");

	printf(" You can perform \n1.>factorial\n2.>powering of a number\n3.>calculate trignometric values\n4.> calculate logrithmic values\n\nCHOOSE ANY OF THE ABOVE NUMBER TO PERFORM CERTAIN CALC.\n  ");
	scanf("%d",&choice);
	switch(choice) {

	case 1:
		int numfacto;
		printf("enter value to calculate its factorial : ");
		scanf("%d",&numfacto);
		printf("Its factorial : %d ",facto(numfacto));
		break;
	case 2:
	     float numberpow,powpow;
			printf("enter number and its power(rational/integer) respectively: \n");
			scanf("%f %f",&numberpow,&powpow);
			printf("Its value after powering : %f ",ratpower(numberpow,powpow));
			break;
	case 3:
		int choice3;
		float angldeg;
		printf("Choose trignometric operation you want to perform respectively \n");
		printf("1.> sin@\n2.> cos@\n3.> tan@\n4.> cosec@\n5.> sec@\n6.> cot@\n");
		scanf("%d",&choice3);
		printf("Enter the angle @ in degrees : ");
		scanf("%f",&angldeg);
		while (angldeg >= 360.0)
			angldeg -= 360.0;
		while (angldeg < 0.0)
			angldeg += 360.0;


		//	trigno(choice2,angldeg);
		switch(choice3) {
		case 1:
			printf("value for sin@ : %f\n",tsin(angldeg));
			break;
		case 2:
			printf("value for cos@ : %f\n",tcos(angldeg));
			break;
		case 3:
			printf("value for tan@ : %f\n",ttan(angldeg));
			break; //make trigno metric function more accurate
		case 4:
			printf("value for csc@ : %f\n",tcsc(angldeg));
			break;
		case 5:
			printf("value for sec@ : %f\n",tsec(angldeg));
			break;
		case 6:
			printf("value for cot@ : %f\n",tcot(angldeg));
			break;

		default :
			printf("wrong input \n");
		}
		break;
	case 4 :
		float numlog1;
		printf("Enter value of log : ");
		scanf("%f",&numlog1);
		printf("value of log a : %f \n",log1(numlog1));
		break;

	default:
		printf("you entered wrong input \n");


	}
	return 0;
}

int facto (int numfacto) {
	int f=1;
	for(int i=numfacto ; i>=1; i--) {
		f*=i;
	}
	return f;
}

float ratpower(float numberpow,float powpow ) {
	int tempnum=numberpow;
	int count=0;
	while(powpow>0.99999999){
	  powpow--;              // done to increase accuracy of ratpower function;
	  count++;
	}
	float fractionpow=1; // since in maclaurn exxpansion of e^x first term is 1 + ...here
	float term=1;
	float powx = log1(numberpow)*powpow;
	
    for(int i=1;i<=25;i++){
        term*=powx/i;
        fractionpow+=term;
    }
	float integerpow=power1(numberpow,count);
	return fractionpow * integerpow;
}


float power1(float numberpow,float powpow ) {
	float rslpow=1;

	for(int i=1; i<=powpow; i++) {     // created integer power handling for log functions
		rslpow*=numberpow;
	}
	return rslpow;
}

float tsin (float angldeg) {
	int sign=1;
	if(angldeg>180) {
		angldeg-=180;
		angldeg=-angldeg;
	}
	if(angldeg>90&&angldeg<=180) {
		angldeg-=180;
		angldeg=-angldeg;
	}

	float rad = angldeg*(PI/180);
	float sum=0;
	for(int i=1 ; i<=17; i+=2) {
		sum+=sign*power1(rad,i)/facto(i);
		sign=-sign;
	}
	return sum;
}

float tcos(float angldeg) {
	return tsin(90-angldeg);
}

float ttan (float angldeg) {
	return tsin(angldeg)/tcos(angldeg);
}

float tcsc(float angldeg) {
	return 1/tsin(angldeg);
}

float tsec(float angldeg) {
	return 1/tcos(angldeg);
}

float tcot(float angldeg) {
	return 1/ttan(angldeg);
}

float log1(float numlog1) {
	float sum=0;
	int times2=0;
	int sign=1;
	while(numlog1>2) {
		numlog1/=2;
		times2++;
	}
	for(int i=1; i<25; i++) {
		sum+= sign*power1(numlog1-1,i)/i;
		sign=-sign;
	}
	return sum+(times2*LN2);
}
