/*
    Kevin Funderburg
    GUI - Summer 2019 - Texas State University
    Inroduction to OpenGL
*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glLineWidth(4.0);
    glPointSize(2.0);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);

    //implicit call to paintGL after resized
}

void GLobj::ngon(int n)
{

}

void GLobj::paintShapes()
{   
    glLoadIdentity();
    float radius = 0.5;

    glBegin(GL_POINTS);
        glColor3f ( 2.0, 0.5, 0.0);
        glVertex3f(-4.0, 4.0, 0.0);
        glVertex3f(-3.0, 4.0, 0.0);
        glVertex3f(-2.0, 4.0, 0.0);
        glVertex3f(-1.0, 4.0, 0.0);
        glVertex3f(-0.0, 4.0, 0.0);
        glVertex3f( 1.0, 4.0, 0.0);
        glVertex3f( 2.0, 4.0, 0.0);
        glVertex3f( 3.0, 4.0, 0.0);
        glVertex3f( 4.0, 4.0, 0.0);
    glEnd();
    // White line
    glBegin(GL_LINES);
        glColor3f ( 1.0, 1.8, 4.0);  
        glVertex2f(-3.5, 3.5);
        glVertex2f( 3.5, 3.5);
    glEnd(); 
    // Yellow zig zag  Line strip
    glBegin(GL_LINE_STRIP);
        glColor3f ( 1.0, 1.0, 0.0);  
        glVertex3f( 3.0, 3.0, 0.0);
        glVertex3f(-3.0, 3.0, 0.0);
        glVertex3f( 2.5, 2.5, 0.0);
        glVertex3f(-2.5, 2.5, 0.0);
        glVertex3f( 2.0, 2.0, 0.0);        
    glEnd();
    //Triangle above square
    glBegin(GL_TRIANGLES);
        glColor3f ( 1.5, 0.0, 1.0);  
        glVertex3f(-2.0, 2.0, 0.0);
        glVertex3f( 2.0, 2.0, 0.0);
        glVertex3f( 0.0, 0.5, 0.0);
    glEnd(); 
    //Left Triangle strip
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f ( 0.0,  3.0, 1.5);  
        glVertex3f(-0.5,  0.0, 0.0);
        glVertex3f(-3.0,  1.5, 0.0);
        glVertex3f(-3.0, -1.5, 0.0);
        glVertex3f(-4.5,  0.0, 0.0);
    glEnd(); 
    //Right Triangle strip
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f (2.0,  0.0, 0.5);  
        glVertex3f(0.5,  0.0, 0.0);
        glVertex3f(3.0,  1.5, 0.0);
        glVertex3f(3.0, -1.5, 0.0);
        glVertex3f(4.5,  0.0, 0.0);
    glEnd(); 
    //Center square
    glBegin(GL_QUADS);
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(0, radius, radius);
        glVertex3f(radius, 0, radius);
        glVertex3f(0, -radius, radius);
        glVertex3f(-radius, 0, radius);
    glEnd();
    //Bottom polygon
    glBegin(GL_POLYGON);
        glColor3f ( 3.0,  1.0, 0.5);
        glVertex3f( 0.0, -0.5, radius);
        glVertex3f(-1.0, -2.5, radius);
        glVertex3f(-1.0, -3.5, radius);
        glVertex3f( 0.0, -4.5, radius);
        glVertex3f( 1.0, -3.5, radius);     
        glVertex3f( 1.0, -2.5, radius);
    glEnd();

   
}


//Paints the GL scene
void GLobj::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(45, 0, 1, 1);
    glTranslatef(1, -4.5, 0);

    glBegin(GL_QUADS);
        // Set The Color To Green
        glColor3f(0.0f,1.0f,0.0f);         
        glVertex3f( 1.0f, 1.0f,-1.0f);     
        glVertex3f(-1.0f, 1.0f,-1.0f);     
        glVertex3f(-1.0f, 1.0f, 1.0f);     
        glVertex3f( 1.0f, 1.0f, 1.0f);     
        // Set The Color To Orange
        glColor3f(1.0f,0.5f,0.0f);         
        glVertex3f( 1.0f,-1.0f, 1.0f);    
        glVertex3f(-1.0f,-1.0f, 1.0f);    
        glVertex3f(-1.0f,-1.0f,-1.0f);    
        glVertex3f( 1.0f,-1.0f,-1.0f);    
        // Set The Color To Red
        glColor3f(1.0f,0.0f,0.0f);         
        glVertex3f( 1.0f, 1.0f, 1.0f);   
        glVertex3f(-1.0f, 1.0f, 1.0f);   
        glVertex3f(-1.0f,-1.0f, 1.0f);   
        glVertex3f( 1.0f,-1.0f, 1.0f);   
        // Set The Color To Yellow
        glColor3f (1.0f,1.0f,0.0f);        
        glVertex3f( 1.0f,-1.0f,-1.0f);     
        glVertex3f(-1.0f,-1.0f,-1.0f);     
        glVertex3f(-1.0f, 1.0f,-1.0f);     
        glVertex3f( 1.0f, 1.0f,-1.0f);     
        // Set The Color To Blue
        glColor3f(0.0f,0.0f,1.0f);         
        glVertex3f(-1.0f, 1.0f, 1.0f);    
        glVertex3f(-1.0f, 1.0f,-1.0f);    
        glVertex3f(-1.0f,-1.0f,-1.0f);    
        glVertex3f(-1.0f,-1.0f, 1.0f);    
         // Set The Color To Violet
        glColor3f(1.0f,0.0f,1.0f);        
        glVertex3f( 1.0f, 1.0f,-1.0f);     
        glVertex3f( 1.0f, 1.0f, 1.0f);     
        glVertex3f( 1.0f,-1.0f, 1.0f);     
        glVertex3f( 1.0f,-1.0f,-1.0f);     

     glEnd();

    paintShapes();

    glFlush ();
}

