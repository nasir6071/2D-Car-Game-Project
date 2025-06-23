#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;

bool isPaused = false; //game pause/on

float carx = 480;     /// This is My Car
float cary = 10;
float randomcar1x = 480;  // Random Car 1 Yellow Car
float randomcar1y = 710;
float randomcar2x = 370;   // Random Car 2 Green Car
float randomcar2y = 1000;
float randomcar3x = 580;   // Random Car 3 Green Car
float randomcar3y = 1300;
float outsiderx = 330;
float outsidery = 0;
float insiderx = 450;
float insidery = 0;


int score = 0;  // Initialize score

/// Forward declaration of displayScore function
void displayScore();



bool isCollision(float x1, float y1, float x2, float y2, float width, float height) {
    return (x1 < x2 + width && x1 + width > x2 && y1 < y2 + height && y1 + height > y2);
}




/// Car Wheel
void carwheel(float x1,float y1, float radius){
  float x=x1;
  float y=y1;

  //float radius=20;
  double pii=3.1416;
  glBegin(GL_TRIANGLE_FAN);
  glColor3ub(0,0,0);
  glVertex2f( x,y );
  for(int i=0;i<=360;i++){  ///i=0,1,2      360

    float a=x+radius*cos(i*(pii/180));
    float b=y+radius*sin(i*(pii/180));
    glVertex2f( a,b);


  }
  glEnd();

}


/// This circle for forest tree
void foresttree(float x1,float y1, float radius){
  float x=x1;
  float y=y1;


  double pii=3.1416;
  glBegin(GL_TRIANGLE_FAN);
  glColor3ub(46, 125, 50);
  glVertex2f( x,y );
  for(int i=0;i<=180;i++){  ///i=0,1,2      360

    float a=x+radius*cos(i*(pii/180));
    float b=y+radius*sin(i*(pii/180));
    glVertex2f( a,b);


  }
  glEnd();
}

/// Sky Moon
void moon(float x1,float y1, float radius){
  float x=x1;
  float y=y1;

  double pii=3.1416;
  glBegin(GL_TRIANGLE_FAN);
  glColor3ub(222,219,214);
  glVertex2f( x,y );
  for(int i=0;i<=360;i++){  ///i=0,1,2      360

    glColor3ub(181,178,174);

    float a=x+radius*cos(i*(pii/180));
    float b=y+radius*sin(i*(pii/180));
    glVertex2f( a,b);


  }
  glEnd();

}


/// This circle for bot tree leaf
void bottreeleaf(float x1,float y1, float radius){
  float x=x1;
  float y=y1;


  double pii=3.1416;
  glBegin(GL_TRIANGLE_FAN);
  glColor3ub(46, 125, 50);
  glVertex2f( x,y );
  for(int i=0;i<=360;i++){  ///i=0,1,2      360



    float a=x+radius*cos(i*(pii/180));
    float b=y+radius*sin(i*(pii/180));
    glVertex2f( a,b);


  }
  glEnd();
}


/// ===========================BackGround Houses
void house(float x, float y){
///House 1
glBegin(GL_QUADS);
glColor3ub(234,182,118);
glVertex2f( x,y );
glVertex2f( x+80,y);
glVertex2f( x+80, y+100);
glVertex2f( x, y+100);
glEnd();
//house 1 Top
glBegin(GL_QUADS);
glColor3ub(234,182,118);
glVertex2f( x, y+100 );
glVertex2f( x+30, y+100);
glVertex2f( x+30, y+120);
glVertex2f( x, y+120);
glEnd();

/// House 2
glBegin(GL_QUADS);
glColor3ub(202,53,23);
glVertex2f( x+20, y);
glVertex2f( x+70, y);
glVertex2f( x+70, y+90);
glVertex2f( x+20, y+90);
glEnd();
// windows 1 for House 2
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+35,y+75 );
glEnd();
// Windows 2 House 2
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+35,y+55 );
glEnd();
// Windows 3 House 2
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+55,y+55 );
glEnd();
// Windows 4 House 2
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+55,y+75 );
glEnd();


/// House 3
glBegin(GL_QUADS);
glColor3ub(202,53,23);
glVertex2f( x+75, y);
glVertex2f( x+125, y);
glVertex2f( x+125, y+110);
glVertex2f( x+75, y+110);
glEnd();
// windows 1 for House 3
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+95,y+95 );
glEnd();
// windows 2 for House 3
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+95,y+75 );
glEnd();
// Windows 3 for House 3
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+95,y+55 );
glEnd();
// Windows 4 for House 3
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+110,y+55 );
glEnd();
// Windows 5 for House 3
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+110,y+75 );
glEnd();
// windows 6 for House 3
glPointSize(10);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+110,y+95 );
glEnd();

/// House 5
glBegin(GL_QUADS);
glColor3ub(202,53,23);
glVertex2f( x+140, y);
glVertex2f( x+170, y);
glVertex2f( x+170, y+115);
glVertex2f( x+140, y+115);
glEnd();
// Windows 1 for House 5
glPointSize(8);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+160,y+105 );
glEnd();
// Windows 2 for House 5
glPointSize(8);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+160,y+90 );
glEnd();
// Windows 3 for House 5
glPointSize(8);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+160,y+75 );
glEnd();
// Windows 3 for House 5
glPointSize(8);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+160,y+60 );
glEnd();

/// House 4
glBegin(GL_QUADS);
glColor3ub(230, 126, 34);
glVertex2f( x+125, y);
glVertex2f( x+150, y);
glVertex2f( x+150, y+95);
glVertex2f( x+125, y+95);
glEnd();
// windows 1 for House 4
glPointSize(8);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+135,y+85 );
glEnd();
// Windows 2 for House 4
glPointSize(8);
glBegin(GL_POINTS);
glColor3ub(244, 208, 63);
glVertex2f( x+135,y+65 );
glEnd();


}

/// Bot Gas
void botgas(float x, float y)
{
//Boot gas body
glBegin(GL_QUADS);
glColor3ub(110,44,0);
glVertex2f( x,y );
glVertex2f( x+15, y);
glVertex2f( x+15, y+80);
glVertex2f( x, y+80);
glEnd();

bottreeleaf(x-8,y+90,30);
bottreeleaf(x+20,y+90,30);
bottreeleaf(x+7,y+120, 25);

}

/// BackGround Pahar
void pahar(float x, float y){
//Pahar 1
glBegin(GL_TRIANGLES);
glColor3ub(16,37,51);
glVertex2f( x+0, y+0 );
glVertex2f( x+80, y+0 );
glVertex2f( x+40, y+120);
glEnd();
//Pahar 1
glBegin(GL_TRIANGLES);
glColor3ub(22,62,79);
glVertex2f( x+30, y+0 );
glVertex2f( x+110, y+0 );
glVertex2f( x+70, y+110);
glEnd();

//Pahar 1
glBegin(GL_TRIANGLES);
glColor3ub(35,92,110);
glVertex2f( x+40, y+0 );
glVertex2f( x+140, y+0 );
glVertex2f( x+90, y+110);
glEnd();
//Pahar 1
glBegin(GL_TRIANGLES);
glColor3ub(66,120,140);
glVertex2f( x+60, y+0 );
glVertex2f( x+150, y+0 );
glVertex2f( x+105, y+100);
glEnd();
//Pahar 1
glBegin(GL_TRIANGLES);
glColor3ub(19,54,71);
glVertex2f( x+40, y+0 );
glVertex2f( x+100, y+0 );
glVertex2f( x+70, y+70);
glEnd();

}

/// BackGround Forest
void forest(float x, float y, float radius){

foresttree(x, y, radius);        // Pivot radius 50
foresttree(x+40, y, radius-15);
foresttree(x+90, y, radius-10);
}

/// Road Out Sider Line
void roadsider(float x, float y){


//Road Side Lan Colour Black
glBegin(GL_QUADS);
glColor3ub(28, 27, 27);
glVertex2f( x+0, y+0 );
glVertex2f( x+20, y+0);
glVertex2f( x+20, y+50);
glVertex2f( x+0, y+50);
glEnd();
//Road Side Lan Colour White
glBegin(GL_QUADS);
glColor3ub(255, 255, 255);
glVertex2f( x+0, y+50 );
glVertex2f( x+20, y+50);
glVertex2f( x+20, y+100);
glVertex2f( x+0, y+100);
glEnd();

}

/// Road Insider Line
void insideline(float x, float y){
//Road insider line
glBegin(GL_QUADS);
glColor3ub(255, 255, 255);
glVertex2f( x+0, y+0 );
glVertex2f( x+5, y+0);
glVertex2f( x+5, y+25);
glVertex2f( x+0, y+25);
glEnd();

}


///============================== My Car
void car(float x, float y){
// My car wheel 1
carwheel(x+2,y+20,8);
carwheel(x+2,y+65,8);
carwheel(x+38,y+20,8);
carwheel(x+38,y+65,8);

//My car head
glBegin(GL_QUADS);
glColor3ub(254, 36, 72 );
glVertex2f( x, y+80 );
glVertex2f( x+40, y+80 );
glVertex2f( x+30, y+90);
glVertex2f( x+10, y+90);
glEnd();
//My Car Body
glBegin(GL_QUADS);
glColor3ub(254, 36, 72 );
glVertex2f( x, y );
glVertex2f( x+40, y);
glVertex2f( x+40, y+80);
glVertex2f( x, y+80);
glEnd();
//My car font side top
glBegin(GL_QUADS);
glColor3ub(222, 49, 99 );
glVertex2f( x+5, y+75 );
glVertex2f( x+35,y+75);
glVertex2f( x+30, y+80);
glVertex2f( x+10, y+80);
glEnd();
//My car font side bottom
glBegin(GL_QUADS);
glColor3ub(222, 49, 99 );
glVertex2f( x+5, y+65 );
glVertex2f( x+35,y+65);
glVertex2f( x+35, y+75);
glVertex2f( x+5, y+75);
glEnd();

//My car font glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+15, y+50 );
glVertex2f( x+25,y+50);
glVertex2f( x+35, y+60);
glVertex2f( x+5, y+60);
glEnd();
//My car glass left side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+20 );
glVertex2f( x+10,y+25);
glVertex2f( x+10,y+50);
glVertex2f( x+5, y+55);
glEnd();

//My car glass Right side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+30,y+25 );
glVertex2f( x+35,y+20);
glVertex2f( x+35,y+55);
glVertex2f( x+30,y+50);
glEnd();

//My car Back side glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5,y+15 );
glVertex2f( x+35,y+15);
glVertex2f( x+25,y+25);
glVertex2f( x+15, y+25);
glEnd();
}


/// ====================================Random Car 1 Yellow Car
void randomcar(float x, float y){


// Random car wheel 1
carwheel(x+2,y+30,8);
carwheel(x+2,y+75,8);
carwheel(x+38,y+30,8);
carwheel(x+38,y+75,8);
// Random car head
glBegin(GL_QUADS);
glColor3ub(238, 249, 8 );
glVertex2f( x+10, y );
glVertex2f( x+30, y );
glVertex2f( x+40, y+10);
glVertex2f( x, y+10);
glEnd();
// Random Car Body
glBegin(GL_QUADS);
glColor3ub(238, 249, 8 );
glVertex2f( x, y+10 );
glVertex2f( x+40, y+10);
glVertex2f( x+40, y+90);
glVertex2f( x, y+90);
glEnd();
//My car font side top
glBegin(GL_QUADS);
glColor3ub(216, 226, 12 );
glVertex2f( x+10, y+10 );
glVertex2f( x+30,y+10);
glVertex2f( x+35, y+15);
glVertex2f( x+5, y+15);
glEnd();
//My car font side bottom
glBegin(GL_QUADS);
glColor3ub(216, 226, 12 );
glVertex2f( x+5, y+15 );
glVertex2f( x+35,y+15);
glVertex2f( x+35, y+25);
glVertex2f( x+5, y+25);
glEnd();
//Random car font glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+30 );
glVertex2f( x+35,y+30);
glVertex2f( x+25, y+40);
glVertex2f( x+15, y+40);
glEnd();
//Random car glass left side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+35 );
glVertex2f( x+10,y+40);
glVertex2f( x+10,y+65);
glVertex2f( x+5, y+70);
glEnd();
//My car glass Right side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+30,y+40 );
glVertex2f( x+35,y+35);
glVertex2f( x+35,y+70);
glVertex2f( x+30,y+65);
glEnd();
//My car Back side glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+15,y+65 );
glVertex2f( x+25,y+65);
glVertex2f( x+35,y+75);
glVertex2f( x+5, y+75);
glEnd();

}

///==================================== Random Car 2 Green Car
void randomcar2(float x, float y){

// Random car wheel 1
carwheel(x+2,y+30,8);
carwheel(x+2,y+75,8);
carwheel(x+38,y+30,8);
carwheel(x+38,y+75,8);
// Random car head
glBegin(GL_QUADS);
glColor3ub(45, 254, 16);
glVertex2f( x+10, y );
glVertex2f( x+30, y );
glVertex2f( x+40, y+10);
glVertex2f( x, y+10);
glEnd();
// Random Car Body
glBegin(GL_QUADS);
glColor3ub(45, 254, 16 );
glVertex2f( x, y+10 );
glVertex2f( x+40, y+10);
glVertex2f( x+40, y+90);
glVertex2f( x, y+90);
glEnd();
//My car font side top
glBegin(GL_QUADS);
glColor3ub(28, 184, 7 );
glVertex2f( x+10, y+10 );
glVertex2f( x+30,y+10);
glVertex2f( x+35, y+15);
glVertex2f( x+5, y+15);
glEnd();
//My car font side bottom
glBegin(GL_QUADS);
glColor3ub(28, 184, 7 );
glVertex2f( x+5, y+15 );
glVertex2f( x+35,y+15);
glVertex2f( x+35, y+25);
glVertex2f( x+5, y+25);
glEnd();
//Random car font glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+30 );
glVertex2f( x+35,y+30);
glVertex2f( x+25, y+40);
glVertex2f( x+15, y+40);
glEnd();
//Random car glass left side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+35 );
glVertex2f( x+10,y+40);
glVertex2f( x+10,y+65);
glVertex2f( x+5, y+70);
glEnd();
//My car glass Right side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+30,y+40 );
glVertex2f( x+35,y+35);
glVertex2f( x+35,y+70);
glVertex2f( x+30,y+65);
glEnd();
//My car Back side glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+15,y+65 );
glVertex2f( x+25,y+65);
glVertex2f( x+35,y+75);
glVertex2f( x+5, y+75);
glEnd();

}

///=================================== Random Car 3 Blue Car
void randomcar3(float x, float y){

// Random car wheel 1
carwheel(x+2,y+30,8);
carwheel(x+2,y+75,8);
carwheel(x+38,y+30,8);
carwheel(x+38,y+75,8);
// Random car head
glBegin(GL_QUADS);
glColor3ub(52, 67, 235);
glVertex2f( x+10, y );
glVertex2f( x+30, y );
glVertex2f( x+40, y+10);
glVertex2f( x, y+10);
glEnd();
// Random Car Body
glBegin(GL_QUADS);
glColor3ub(52, 67, 235 );
glVertex2f( x, y+10 );
glVertex2f( x+40, y+10);
glVertex2f( x+40, y+90);
glVertex2f( x, y+90);
glEnd();
//My car font side top
glBegin(GL_QUADS);
glColor3ub(68, 34, 161 );
glVertex2f( x+10, y+10 );
glVertex2f( x+30,y+10);
glVertex2f( x+35, y+15);
glVertex2f( x+5, y+15);
glEnd();
//My car font side bottom
glBegin(GL_QUADS);
glColor3ub(68, 34, 161 );
glVertex2f( x+5, y+15 );
glVertex2f( x+35,y+15);
glVertex2f( x+35, y+25);
glVertex2f( x+5, y+25);
glEnd();
//Random car font glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+30 );
glVertex2f( x+35,y+30);
glVertex2f( x+25, y+40);
glVertex2f( x+15, y+40);
glEnd();
//Random car glass left side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+5, y+35 );
glVertex2f( x+10,y+40);
glVertex2f( x+10,y+65);
glVertex2f( x+5, y+70);
glEnd();
//My car glass Right side
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+30,y+40 );
glVertex2f( x+35,y+35);
glVertex2f( x+35,y+70);
glVertex2f( x+30,y+65);
glEnd();
//My car Back side glass
glBegin(GL_QUADS);
glColor3ub(36, 254, 254 );
glVertex2f( x+15,y+65 );
glVertex2f( x+25,y+65);
glVertex2f( x+35,y+75);
glVertex2f( x+5, y+75);
glEnd();

}


///====================================== myInit
void myInit ()
{

	//glClearColor(0.0, 1.0, 0.0, 0.0);
	//glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
	//glColor3f(0.0, 0.2, 0.0);
	glClearColor(128.0f/255.0f,0, 0, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// setting window dimension in X- and Y- direction
	glOrtho(0, 1000, 0, 800, -10.0, 10.0);


}

///============================================= Display

void display ()
{
glClear(GL_COLOR_BUFFER_BIT);

/// BackGround Bottom Part
glBegin(GL_QUADS);
glColor3ub(3, 252, 65);
glVertex2f( 0,0 );
glVertex2f( 1000, 0);
glVertex2f( 1000, 450);
glVertex2f( 0, 450);
glEnd();


/// BackGround Upper Part Sky
glBegin(GL_QUADS);
glColor3ub(217,238,239);
glVertex2f( 0,450 );
glColor3ub(216,237,238);
glVertex2f( 1000, 450);
glColor3ub(17,54,98);
glVertex2f( 1000, 800);
glColor3ub(10,100,160);
glVertex2f( 0, 800);
glEnd();

/// Star for Sky
glPointSize(2);
glBegin(GL_POINTS);
glColor3ub(242, 245, 249);
for(int i =0; i<70; i++){
    int x = rand()%1000;
    int y =450+ rand()%800;
    glVertex2f( x,y );
}
glEnd();

/// Sky Moon
moon(890,680,40);

/// Background Pahar

pahar(750,450);

/// House
house(0,450);
house(600,450);
house(850,450);

/// Bot Gas
botgas(250,450);


///Back Ground Forset
forest(0,450,50);
forest(150,450,50);
forest(300,450,50);
forest(700,450,50);
forest(800,450,50);
forest(950,450,50);


///Main Road
glBegin(GL_QUADS);
glColor3ub(115, 114, 114);
glVertex2f( 350, 0 );
glVertex2f( 650, 0);
glVertex2f( 650, 800);
glVertex2f( 350, 800);
glEnd();

///Left side road sider (330, 0)
for (int y = 0; y <= 800; y += 100) {
        roadsider(outsiderx, outsidery+y);
    }

///Right side road sider (650,0)
for (int y = 0; y <= 800; y += 100) {
        roadsider(outsiderx+320, outsidery+y);
    }

/// Road inside line 1
for (int y =0; y<=800; y+=50)
{
    insideline(insiderx, insidery+y);
}

/// Road inside line 2
for (int y =0; y<=800; y+=50)
{
    insideline(insiderx + 100, insidery+y);
}



// This is My car
car(carx,cary);

//This is Random Car 1 Yellow Car
randomcar(randomcar1x, randomcar1y);

// This is Random Car 2 Green Car
randomcar2(randomcar2x, randomcar2y);

// This is Random Car 3
randomcar3(randomcar3x, randomcar3y);

/// Display the score
displayScore();

/*
//lines
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f( 250,500 );
glVertex2f( 250, 0 );
glEnd();


//Triangle
glBegin(GL_TRIANGLES);
glColor3f(0,0,0);
glVertex2f( 250,250 );
glVertex2f( 300, 200 );
glVertex2f( 200, 200);
glEnd();

//point

glPointSize(100);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f( 100,100 );
glEnd();

//Quads
glBegin(GL_QUADS);
glColor3ub(128,0,0);
glVertex2f( 0,0 );
glVertex2f( 200, 0 );
glVertex2f( 200, 200);
glVertex2f( 0, 200);
glEnd();

//polygon
glBegin(GL_POLYGON);
glColor3f(0,1,0);
glVertex2f( 100,100 );
glVertex2f( 100, 0 );
glVertex2f( 50, 0 );
glVertex2f( 10, 50 );
glVertex2f( 50, 200 );

glEnd();

*/






glFlush();
}
///==================================================KeyBoard
void my_keyboard(unsigned char key, int x, int y)
{
    cout<<key<<endl;

    //My car control
    if (key == 'p' || key == 'P'){   // Paused the game
        isPaused = !isPaused;
    }
    if (key == 'a' && carx > 360) {  // Move left
            carx -= 40;
        }
    if (key == 'd' && carx < 600) {  // Move right
            carx += 40;
        }
    if (key == 'w' && cary < 710) {  // Move Forward
            cary += 40;
            score += 10; // Increase score by 10
        }
    if (key == 'z' && cary > 10) {   // Move Backward
            cary -= 40;
        }



}


///========================== Display Score

void displayScore() {
    glColor3ub(255, 255, 255); // White color for text
    glRasterPos2f(10, 750);   // Position to display the score
    std::string scoreText = "Score: " + std::to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


///====================================Update

void update(int value) {

    // My Car Control
    if (isPaused) {
        glutTimerFunc(25, update, 0);
        return;
    }

    // Road Control
    // for road outsider line move
    outsidery -= 5;
    if ( outsidery <= -100){
        outsidery =0;
    }
    // For road inisider line move
    insidery-= 5;
    if ( insidery <= -50) {
        insidery = 0; // Reset insidery to create a looping effect
    }


    // Car Control
    // Control Random Car 1 Yellow
    randomcar1y -= 10; // Move the random car down
    if (randomcar1y < -90){
          randomcar1y = 800;                 // Reset vertical position
          randomcar1x = 360 + rand()% 250;   // Random horizontal position within the road's width (180 to 320)
        }

    // Control Random Car 2 Green
    randomcar2y -= 10;
    if (randomcar2y < -90){
          randomcar2y = 800;
          randomcar2x = 360 + rand()% 250;
        }

    // Control Random Car 3 Blue
    randomcar3y -= 10;
    if (randomcar3y < -90){
          randomcar3y = 800;
          randomcar3x = 360 + rand()% 250;
        }


    // End the game
    /*if (isCollision(carx, cary, randomcar1x, randomcar1y, 40, 90) ||
        isCollision(carx, cary, randomcar2x, randomcar2y, 40, 90) ||
        isCollision(carx, cary, randomcar3x, randomcar3y, 40, 90)) {
        //return;
        std::cout << "Game is Over." << std::endl;
        exit(0);
    }*/

    if (isCollision(carx, cary, randomcar1x, randomcar1y, 40, 90) ||
        isCollision(carx, cary, randomcar2x, randomcar2y, 40, 90) ||
        isCollision(carx, cary, randomcar3x, randomcar3y, 40, 90)) {
        std::cout << "Game is Over. Final Score: " << score << std::endl;
        score = 0; // Reset score
        exit(0);   // End the game
    }



	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}



int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 0);

	// Giving name to window
	glutCreateWindow("2D Car Game");
	myInit();

    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
	glutTimerFunc(25, update, 0);

	//glutTimerFunc(25, update, 0);

	glutMainLoop();
}


