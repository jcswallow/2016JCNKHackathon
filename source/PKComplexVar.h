//Created by Joel C. Swallow 8/8/16---
//------------------------------------
#ifndef __PKCOMPLEXVAR_
#define __PKCOMPLEXVAR__

#include <cmath>
#include <iostream>

const double pi = 4*atan(1);	//global declaration....

class PKComplexVar {

	private:
		double fRe;
		double fIm;
		double fMod;
		double fArg;

	public:
		double GetRe();
		double GetIm();
		void Print(int Option);
		void Print();	//overloaded -->default if no option called
		PKComplexVar(double re, double im);
		PKComplexVar();
		PKComplexVar Power(double x);
		PKComplexVar Sqrt();
		PKComplexVar operator + (PKComplexVar);
		PKComplexVar operator - (PKComplexVar);
		PKComplexVar operator * (PKComplexVar);
		PKComplexVar operator / (PKComplexVar);
};

PKComplexVar::PKComplexVar(){
	fRe = 0; 
	fIm = 0;
	fMod = 0;
	fArg = 0;
}

PKComplexVar::PKComplexVar(double re, double im){
	fRe = re;
	fIm = im;
	SetMod(sqrt(re*re + im*im));	//The modulus of the complex number
	SetArg(tan(im/re));	//The argument of the complex number
}

//Get/Set methods ---------------------------------------------------
double PKComplexVar::GetRe(){return fRe;}
double PKComplexVar::GetIm(){return fIm;}
double PKComplexVar::GetMod(){return fMod;}
void PKComplexVar::SetMod(double Mod){fMod=Mod;}
double PKComplexVar::GetArg(){return fArg;}
void PKComplexVar::SetArg(double Arg){fArg=Arg;}
/*
double PKComplexVar::GetP1(){return fP1;}
void PKComplexVar::SetP1(double P1){fP1=P1;}
double PKComplexVar::GetP2(){return fP2;}
void PKComplexVar::SetP2(double P2){fP2=P2;}
*/
//-------------------------------------------------------------------

void PKComplexVar::Print(int Option){
//Should have sevaral ways to print: 
        //z=a+bi
        //z=re^{i\theta}
        //z=a cos(\theta)+ ib sim(\theta)

	if(Option==1){ //Print the complex number in the form z=a+bi
		if(fIm>0){
			std::cout<<fRe<<"+"<<fIm<<"i";
		}
		else{
			std::cout<<fRe fIm<<"i";
		}
	}
	if(Option==2){ //Print the complex number in the form z=re^{i\theta}
		std::cout<<fMod<<"e^(i"<<fArg<<")";
	}
	if(Option==3){ //Print the complex number in the form z=a cos(\theta) + i b sin(\theta)
		if(fIm>0){
			std::cout<<fRe<<"cos("<<fArg<<")+i"<<fIm<<"sin("<<fArg<<")";
		}
		else{
			std::cout<<fRe<<"cos("<<fArg<<")-i"<<-fIm<<"sin("<<fArg<<")";
		}
	}
}

void PKComplexVar::Print(){
//Default print if no option chosen: z=a+bi
	if(fIm>0){
        	std::cout<<fRe<<"+"<<fIm<<"i";
        }
        else{
                std::cout<<fRe fIm<<"i";
        }
}	



PKComplexVar PKComplexVar::operator + (PKComplexVar param){	//To add complex Numbers add the real and imaginary parts seporately
	PKComplexVar temp;
	temp.fRe = fRe + param.fRe;
	temp.fIm = fIm + param.fIm;;
return temp;
}

PKVar PKVar::operator - (PKComplexVar param){ //To cubtract complex numbers subtract the real and imaginary parts
	PKComplexVar temp;
	temp.fRe = fRe - param.fRe;
	temp.fIm = fIm - param.fIm;
return temp;
}

PKVar PKVar::operator * (PKComplexVar param){	//To multiply two complex numbers the moduli multiply and the arguments add
	//z1=a+ib	z2=c+id
	//z1*z2=(ac-bd)+i(bc+ad)

	//z1=r1e^(itheta1)	z2=r2e^(itheta2)
	//z1*z2=(r1*r2)e^(i(theta1+theta2))

	PKComplexVar temp;
	//a=fRe, b=fIm, c=param.fRe, d=param.fIm
	temp.fRe = (fRe*param.fRe)-(fIm*param.fIm);
	temp.fIm = (fIm*param.fRm)+(fRe*param.fIm);

//	temp.fMod = fMod*param.fMod;
	
//	temp.fArg = fArg*param.fArg;	


return temp;
}

PKVar PKComplexVar::operator / (PKComplexVar param){	//To divide a complex number the modui are divided and the arguments subtracted.
	PKComplexVar temp;

	temp.SetMod(temp.GetMod()/param.GetMod());	//r1/r2
	double NewMod=temp.GetMod();

	temp.SetArg(temp.GetArg()-param.GetArg());	//theta1-theta2
	double NewArg=temp.GetArg();

	temp.fRe = NewMod/(sqrt(1+(arctan(NewArg))));
	temp.fIm = NewMod*((arctan(NewArg))/(sqrt(1+((arctan(NewArg))*(arctan(NewArg))))));	//z1/z2=r1/r1 e ^(theta1-theta2)

return temp;
}

//Currently not working...........................
PKComplexVar PKComplexVar::Power(double x){
	PKComplexVar temp;
//	temp.value_ = pow(value_,x);
//	temp.error_ = x*pow(value_,x-1)*error_;
return temp;
}
//................................................

PKComplexVar PKComplexVar::Sqrt(){
	PKComplexVar temp;

	temp.SetMod(sqrt(temp.GetMod));
	double NewMod=temp.GetMod();

	temp.SetArg((temp.GetArg)/2);
	double NewArg=temp.GetArg();

	temp.fRe=NewMod/(sqrt(1+((arctan(NewArg))*(arctan(NewArg)))));	//a=r/sqrt(1+(arctan(theta))^2)
	temp.fIm=(NewMod*arctan(NewArg))/(sqrt(1+((arctan(NewArg)*(arctan(NewArg))))));	//b=(r arctan(theta) )/sqrt(1+(arctan(theta))^2)

return temp;
}
 
#endif
