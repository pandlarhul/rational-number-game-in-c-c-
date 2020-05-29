#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<bios.h>
				char *p1[]={"PRACTICE QUESTION","PROBLEM SOLVING","EXIT"};
				class Select;
				class Rational;
				class Select
			{
				public:
				int array[10][10],row,column;
				void initial();
				void page(int);
			};

				void Select::initial()
				{
					int gd=DETECT,gm;
					 initgraph(&gd,&gm,"c:\\tc\\bgi");
				}
				void Select::page(int o)
				{
					clearviewport();
					settextstyle(1,0,3);
					for(int i=0;i<3;i++)
					{
					rectangle(95,102+o*24,360,125+o*24);
					outtextxy(100,100+i*24,p1[i]);
					}

				}



				int Score,ques=0;
				class Rational
				{
				public:
				int numerator,denominator;
				int posx(int);
				void initialValue();
				void reduce(Rational &);
				friend void operator >>(istream &,Rational&);
				friend void operator <<(ostream &,Rational&);
				Rational operator +(Rational);
				Rational operator -(Rational);
				Rational operator *(Rational);
				Rational operator /(Rational);
				void startagain(int);
				Rational randomRational();
				friend char createOperation(int);
				friend int operator ==(Rational &,Rational&);
				friend void wrong();
				friend void right();
				void end();
				void startRational();

				};
				int Rational::posx(int i)
				{
				int r,m=1;
				if(i<0)
				{
				i=i*(-1);
				m=-1;
				}

				       if(i>0 && i<10)
				       r=1;
				       else
				       if(i>=10 &&i<100)
				       r=2;
				       else
				       if(i>=100 && i<999)
				       r=3;
				 if(m<0)
				 r=r+1;

				return r;

				}
				void wrong()
				{
				sound(90);
				delay(100);
				nosound();
				}
				void right()
				{
				sound(700);
				delay(100);
				nosound();
				}
				int operator ==(Rational &r1,Rational &r2)
				{
					int check=0;
					int n1,d1,n2,d2;
					n1=r1.numerator;
					n2=r2.numerator;
					d1=r1.denominator;
					d2=r2.denominator;
					if(n2<0 && d2<0)
						{
						n2=(-1)*(n2);
						d2=(-1)*(d2);
						}
					else
					      if(n2>0 && d2<0)
						{
						n2=(-1)*(n2);
						d2=(-1)*(d2);
						}
				      if(n1==n2 && d1==d2)
				      check=1;
				      else
				      check=0;
					return check;
				}
				char createOperation(int a)
				{
				char c;
				switch(a)
					{
					case 0:
					c='+';
					break;
					case 1:
					c='-';
					break;
					case 2:
					c='*';
					break;
					case 3:
					c='/';
					break;
					}
					return   c;
				}
				Rational Rational::randomRational()
				{
				int n1,n2,l=10,r1,r2;
				r1=random(l);
				r2=random(l);
				n1=r1-r2;
				r1=random(l);
				r2=random(l);
				n2=r1-r2;
				Rational r3;
				if(n2==0)
				n2=n2+1;
				if(n1==0)
				n1=n1-3;
				r3.numerator=n1;
				r3.denominator=n2;
				return r3;
				}

				Rational Rational::operator /(Rational r1)
				{
				Rational r2;
				int d1,n1;
				d1=numerator*(r1.denominator);
				n1=denominator*(r1.numerator);
				r2.numerator=d1;
				r2.denominator=n1;
				r2.reduce(r2);
				return r2;
				}
				Rational Rational::operator *(Rational r1)
				{
				Rational r2;
				int d1,n1;
				d1=numerator*(r1.numerator);
				n1=denominator*(r1.denominator);
				r2.numerator=d1;
				r2.denominator=n1;
				r2.reduce(r2);
				return r2;
				}
				Rational Rational::operator -(Rational r1)
				{
				Rational r2;
				int d1,d2,n1,n2;
				d1=numerator*(r1.denominator);
				d2=denominator*(r1.numerator);
				n1=(denominator)*(r1.denominator);
				r2.numerator=d1-d2;
				r2.denominator=n1;
				r2.reduce(r2);
				return r2;
				}
				Rational Rational::operator +(Rational r1)
				{
				Rational r2;
				int d1,d2,n1,n2;
				d1=numerator*(r1.denominator);
				d2=denominator*(r1.numerator);
				n1=denominator*(r1.denominator);
				r2.numerator=d1+d2;
				r2.denominator=n1;
				r2.reduce(r2);
				return r2;
				}
				void Rational::reduce(Rational &r1)
				{

				int a,b,c,d=0;
				a=numerator;
				b=denominator;
				if(b>a)
				     {
				     a=denominator;
				     b=numerator;
				     }
		    if(a==0)
		      {
		      a=0;
		      b=0;
		      }
		      else if(b==0)
			    {
			    cout<<"not defined";
			    }
			  else
			     {
				if(a<0 && b<0)
					{
					c=1;
					a=(-1)*a;
					b=(-1)*b;
					}
				else  if(a<0 && b>0)
				     {
				     c=-1;
				     a=(-1)*a;
				     }
				else  if(a>0 && b<0)
				     {
				     c=-1;
				     b=(-1)*b;
				     }
					else
					c=1;

				while(b!=0)
				       {
					 d=b;
					 b=a%b;
					 a=d;
				       }
					 numerator=numerator/a;
					 denominator=denominator/a;
					 a=numerator;
					 b=denominator;
				 if(a<0 && b<0)
					{
					a=(-1)*(a);
					b=(-1)*(b);
					}
				else
				if(a>0 && b<0)
					{
					a=(-1)*(a);
					b=(-1)*(b);
					}
			       numerator=a;
			       denominator=b;
			     }


				}

				void operator>>(istream &i1,Rational &r1)
				{
				Rational r;
				int wx,wy;
				cout<<"\nenter the Rational number=\n";
				i1>>r1.numerator;
				wx=wherex();
				wy=wherey();
				wx=wx+r.posx(r1.numerator);
				gotoxy(wx,wy-1);

				cout<<"/";
				i1>>r1.denominator;
				}    //input operator


				void operator <<(ostream &o1,Rational &r1)
				{
				    if(r1.numerator!=0 && r1.denominator!=0)
				       {
					//cout<<"\nnumber is=";
					o1<<r1.numerator;
					cout<<"/";
					o1<<r1.denominator;
				       }
				  else if(r1.numerator==0)
					  {
					  r1.numerator=0;
					  r1.denominator=0;
					  cout<<r1.numerator;
					  }
				     else
				     {
				     cout<<(char)224;
				     }

				}           //********output operator
				void Rational::initialValue()
				{
				numerator=0;
				denominator=0;
				}
				void Rational::startagain(int limit)
				{
				int i=0,op,score=0;

				char operation;
				Rational r1,r2,r3,r4;
				randomize();

				right();
				while(i<limit)
				{
				ques=ques+1;
					clrscr();
					cout<<"question no="<<ques;
					cout<<"\n";
					op=random(4);
					r1=randomRational();
					r2=randomRational();
					cout<<r1;
					cout<<"   ";
					operation=createOperation(op);
					cout<<operation;
					cout<<"   ";
					cout<<r2;
					r1.reduce(r1);
					r2.reduce(r2);
					switch(operation)
						{
					    case '+':
					    r3=r1+r2;
					    break;
					    case '-':
					    r3=r1-r2;
					    break;
					    case '*':
					    r3=r1*r2;
					    break;
					    case '/':
					    r3=r1/r2;
					    break;
						}

					cin>>r4;
					if(r3==r4)
					{
					score+=1;
					cout<<"right";
					cout<<"\n";
					right();
					cout<<"press any key to continue";
					getch();
					}
					else
					{
					wrong();
					cout<<"wrong answer";
					cout<<"\nanswer is=";
					cout<<r3;
					cout<<"\n                 press any key to continue";
					getch();
					}
				i+=1;
				}
				Score=score;
				   }

				void Rational::end()
					{
					char *show,*en="press any key to exit",*q="";
					int gd=DETECT,gm,x1,x2;
					initgraph(&gd,&gm,"c:\\tc\\bgi");
					setcolor(3);
					x1=getmaxx()/2;
					x2=getmaxy()/2;
					sprintf(show,"%d",Score);
					sprintf(q,"%d",ques);
					settextstyle(1,0,3);
					outtextxy(x1-100,x2-132,"max. marks=");
					outtextxy(x1+60,x2-132,q);
					outtextxy(x1-100,x2-100,"your score=");
					outtextxy(x1+50,x2-100,show);
					outtextxy(x1-50,x2-50,"Thank you");
					outtextxy(x1-100,x2,en);
					getch();
					closegraph();
					exit(1);
					}
				void Rational::startRational()
				 {
				 clrscr();//****************
					char c;
			int o=0,value,key;
			Select o1;
			o1.initial();
			o1.page(0);
			while(1)
			{       if(kbhit())
				{
				key=bioskey(0);
				if(key==18432 ||key==19200)
				o=o-1;
				else if(key==20480 ||key==19712)
				o=o+1;
				else
				if(key==7181 && o==0)
				{
				clearviewport();

					 char c='y';
					 Rational r1;
					 while(c=='y')
					 {
					 window(1,10,80,18);
					 textbackground(0);
					 textcolor(3);
					 r1.startagain(1);
					 clrscr();
					 cout<<"press y to continue else exit";
					 c=getch();
					 }
					 r1.end();

				getch();
				o1.initial();
				}
				else
				if(key==7181 &&o==1)
					{
				  cout<<"question";
					}
				else
				      break;
				if(o>2)
				o=0;
				else if(o<0)
				o=2;
				o1.page(o);

				}
			 }
				 }
				 int main()
				 {
				 clrscr();
				 Rational r1;
				 r1.startRational();
				 getch();
				 return 0;
				 }


