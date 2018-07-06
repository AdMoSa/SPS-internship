#include<iostream>
#include<cmath>

using namespace std;

class Coordinate
{
    public:
    float i,j;
    void getdata()
    {
        cout<<"\nEnter 'x' coordinate : ";
        cin>>i;
        cout<<"Enter 'y' coordinate : ";
        cin>>j;
    }
    void getdata(float x,float y)
    {
        i=x;j=y;
    }
    void display(void)
    {
        cout<<"'x' coordinate is "<<i<<"\n 'y' coordinate is "<<j;
    }
    Coordinate add(Coordinate c2);    //add coordinate c2 to current coordinate
};

Coordinate Coordinate::add(Coordinate c2)
{
    Coordinate c3;
    c3.i= i + c2.i;
    c3.j= j + c2.j;
    return(c3);
}

class Box
{
public:
    Coordinate b1,b2,b3,b4;
    void getdata()
    {
        b1.getdata();
        b2.getdata();
        b3.getdata();
        b4.getdata();
    }

};

class Circle
{
    public:
    float x,y;
    float radius;
};

Circle createnewcircle(Coordinate in)
{
    Circle temp;
    in.getdata();
    temp.x=in.i;
    temp.y=in.j;
    cout<<"\nEnter radius : ";
    cin>>temp.radius;
    return temp;
}
class Root
{
    public:
        float rone,rtwo;
};
Root Solvequadeq(float a,float b,float c)
{
	float d, e;
	Root temp;
	cout << "For the equation of the form- ax^2 + bx + c" << endl;
	d = (b*b) - 4 * a*c;
	e = pow(d, 0.5);
	temp.rone = (-b + e) / (2 * a);
	temp.rtwo = (-b - e) / (2 * a);
	if (d < 0)
		cout << "No real roots possible. Collision doesn't occur";
	else
		//cout << "The roots are" << temp.rone << "and" << temp.rtwo;

	return temp;
}

#define PI 3.14159265

int main()
{
    Box A;
    cout<<"Enter coordinates of the box : ";        //Box is assumed to be parallel to the x axis
    A.getdata();
    Coordinate c1,c2;
    cout<<"The electron is being launched from Coordinates";
    c1.getdata();
    cout<<"Enter the speed of the electron : ";
    float u,v;
    cin>>u;

    cout<<"Enter the angle w.r.t horizontal : ";
    float th,m;
    cin>>th;

    m=tan(th*PI/180);
    cout<<"\nThe equation of line is : "<<"y = "<<m<<"x + "<<c1.j;
    Circle one;
    cout<<"\nCreate new circle object : ";
    one = createnewcircle(c2);
        float x,y,m1;
        Coordinate fc;
        y=A.b4.j;
        x=y-(c1.j);
        fc.getdata(x,y);
        fc.display();
        float vn,vt;
        vn=-u*sin(th*PI/180);
        vt=u*cos(th*PI/180);
        float th1;
        th1=atan2(vn,vt)*180/PI;
        cout<<"\nThe new angle is : "<<th1;
        m1=tan(th1*PI/180);
        float it=fc.j -m1*fc.i;
    cout<<"\nThe new equation of line is : "<<"y= "<<m1<<"x +"<<it;
    float a,b,c;
    a=1+pow(m1,2); b=2*(-one.x+(m1*(it-one.y))); c=pow(one.x,2)+pow((it-one.y),2)-pow(one.radius,2);
    cout<<"\na is : "<<a<<"\nb is : "<<b<<"\nc is : "<<c;
    cout<<"\nSolving the quadratic equation : ";
    Root r1;
    r1= Solvequadeq(a,b,c);
    cout<< "The roots are" << r1.rone << "and" << r1.rtwo;
        float x1,y1,x2,y2,d1,d2;
        Coordinate sc;
        x1=fc.i+r1.rone; y1=fc.j-(m1*r1.rone+it);
        d1=pow(x1,2)+pow(y1,2);
        x2=fc.i+r1.rtwo; y2=fc.j-(m1*r1.rtwo+it);
        d2=pow(x2,2)+pow(y2,2);
        if(d1>=d2)
        {
            x=r1.rtwo; y=m1*r1.rtwo+it;
            sc.getdata(x,y);
        }
        else
        {
            x=r1.rone; y=m1*r1.rone+it;
            sc.getdata(x,y);
        }
        sc.display();

    //To find the angle of contact against the localised normal we only need the slope of the localised normal
    float nm,th2;
    nm=(sc.j-one.y)/(sc.i-one.x);
    //cout<<"\nnm is : "<<nm;
    th2=atan(nm-m1/(1+m1*nm))*180/PI;

    float vn1,vt1;
        vn1=-u*sin(-th2*PI/180);
        vt1=u*cos(-th2*PI/180);
        float th3;
        th3=atan2(vn1,vt1)*180/PI;

    cout<<"\nThe new angle is : "<<th3;
    float m2;
    m2=tan(th3*PI/180);
    float it1=sc.j -m2*sc.i;
    cout<<"\nThe new equation of line is : "<<"y= "<<m2<<"x +"<<it1;
        Coordinate tc;
        float x3,y3;
        y3=A.b1.j;
        x3=y3-it1;
        tc.getdata(x3,y3);
        tc.display();

    float nm1=0,th4;
    //cout<<"\nnm is : "<<nm;
    th4=atan(abs(nm1-m2/(1+m2*nm1)))*180/PI;
    cout<<"\n\nth4 is : "<<th4;
    float vn2,vt2;
        vn2=-u*sin(th4*PI/180);
        vt2=u*cos(th4*PI/180);
        float th5;
        th5=atan2(vn2,vt2)*180/PI;

    cout<<"\n\nThe new angle is : "<<th5;
    float m3;
    m3=tan(th5*PI/180);
    float it2=tc.j -m3*tc.i;
    cout<<"\nThe new equation of line is : "<<"y= "<<m3<<"x +"<<it2;
        Coordinate ex;
        float x4,y4;
        x4=A.b4.i;
        y4=x4+it2;
        ex.getdata(x4,y4);
        cout<<"\nThe ball exits at the coordinates : \n";
        ex.display();

    return 0;
}
