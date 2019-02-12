/*

Dies ist OpenGL Wonderland von
   William Blacoe
Abgegeben an Dr. Joseph am 12.03.08

*/

#pragma comment(lib, "opengl32.lib")//Link to the OpenGL libraries
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")

#include <windows.h>
#include <GL\glut.h>
#include <GL\glaux.h>
#include <math.h>
#include <stdio.h>
#include <ctime>




//Trigonometrie
GLfloat lightWinkel=0;
const GLfloat PI = 3.1415926535897932384626433832795;

//Farben als Felder
const GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat grey[] =  { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat lightgrey[] =  { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat black[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat almostBlack[] = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
const GLfloat green[] = { 0.0f, 1.0f, 0.0f, 1.0f };
const GLfloat blue[] = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat yellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat purple[] = { 1.0f, 0.0f, 1.0f, 1.0f };
const GLfloat cyan[] = { 0.0f, 1.0f, 1.0f, 1.0f };
const GLfloat wooden[] = { 0.8f, 0.8f, 0.4f, 1.0f };
const GLfloat darkWooden[] = { 0.3f, 0.3f, 0.1f, 1.0f };

//Farben als Konstanten
//(wird für Material gebraucht)
const GLint WHITE = 0;
const GLint GREY = 1;
const GLint LIGHTGREY = 2;
const GLint BLACK = 3;
const GLint RED = 4;
const GLint GREEN = 5;
const GLint BLUE = 6;
const GLint YELLOW = 7;
const GLint PURPLE = 8;
const GLint CYAN = 9;
const GLint WOODEN = 10;
const GLint DARKWOODEN = 11;

//Richtungen als Konstanten
//(wird für texturierte Wände gebraucht)
const GLint Xneg = 0;
const GLint Xpos = 1;
const GLint Yneg = 2;
const GLint Ypos = 3;
const GLint Zneg = 4;
const GLint Zpos = 5;

//Mitte der Welt
GLint middleX = 300;
GLint middleZ = -300;

//Kamera Einstellungen
GLint eyeX = 50; 
GLint eyeY = 380;
GLint eyeZ = 10;
GLint centerX = 270;
GLint centerY = 50;
GLint centerZ = -350;
GLint schritt = 10;

//Die Dauer einer Kamera-Phase (es gibt 5 Phasen insgesamt)
GLfloat zeitPhase = 100.0f;

//Zeit
GLfloat zeit = 0.0f;
GLfloat zeitMax = zeitPhase * 5; //eine Fahrt dauert soviele Zeiteinheiten
GLfloat tanzZeit = 0.0f;
GLfloat tanzZeitMax = zeitPhase; //ein Tanz dauert soviele Zeiteinheiten

//Texturen
GLuint	textures[8];	//Speicher für Texturen
const GLint CONCRETE_WALL = 0;
const GLint GRASS = 1;
const GLint GREY_WALL = 2;
const GLint PAVEMENT = 3;
const GLint STARS = 4;
const GLint WINDOW_WALL = 5;
const GLint SCHILD = 6;
const GLint KREIS = 7;

//Performance
GLint sleepTime = 50;   //Wie lange zwischen den Zeiteinheiten gewartet wird
GLfloat aufl = 20;      //Auflösung (Standard: 50)


//Eigene Header Dateien
#include "material.h"
#include "drawShapes.h"
#include "otherFuncs.h"
#include "transparency.h"
#include "textur.h"
#include "lights.h"
#include "drawFigures.h"
#include "bmpload.h"
#include "tanzen.h"
#include "drawZwerge.h"
#include "drawLightCones.h"
#include "walls.h"
#include "kamera.h"


/**
 * Init
 */
void init(){
    
/*
    GLint temp[] = { 310, 80, -340, 290, 50, -420};
    eyeX = temp[0];    
    eyeY = temp[1];
    eyeZ = temp[2];
    centerX = temp[3];    
    centerY = temp[4];
    centerZ = temp[5];
*/
    //Hintergrundfarbe schwarz
    glClearColor(0.2, 0.2, 0.2, 0.5);

    //Light Einstellungen
    
    switchOnAllLights();
    
    //Licht Parameter einstellen
    glEnable(GL_LIGHTING);
    
    //Alle Texturen laden
    nearestbmp(textures, "bmp\\concreteWall.bmp", CONCRETE_WALL);
    nearestbmp(textures, "bmp\\grass.bmp", GRASS);
    nearestbmp(textures, "bmp\\greyWall.bmp", GREY_WALL);
    nearestbmp(textures, "bmp\\pavement.bmp", PAVEMENT);
    nearestbmp(textures, "bmp\\stars.bmp", STARS);
    nearestbmp(textures, "bmp\\windowWall.bmp", WINDOW_WALL);
    nearestbmp(textures, "bmp\\schild.bmp", SCHILD);
    nearestbmp(textures, "bmp\\kreis.bmp", KREIS);
    
    //Weitere Parameter einstellen
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, grey);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glEnable(GL_NORMALIZE);

    //Randomizer neu einstellen    
    srand(time(0));
    
}












/**
 * Anzeige
 */
void display(){

    //Bildspeicher und Puffer löschen
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //glPolygonMode(GL_BACK,GL_FILL);
    //glPolygonMode(GL_FRONT, GL_FILL);


    glLoadIdentity();
    glTranslatef(0, 0, -100);
    
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0, 1, 0);
    
    positionAllLights();



    /*
       MALEN
    */



    //Alle 4 Laternen malen
    draw_alleLaternen();    
    
    //Alle 3 Tori malen
    glPushMatrix();
    glTranslatef(-20, 0, 20);
    draw_tori();
    glPopMatrix();

    //Zwerge
    draw_zwerge();
    
    //Tunnel
    glPushMatrix();
    glTranslatef(middleX+230, 0, middleZ+100);
    glRotatef(-90, 1, 0, 0);
    mat(PURPLE, PURPLE, GREY, 80);
    draw_tunnel(200, 35, 30);
    glPopMatrix();

    //Die äußeren Wände der Welt malen
    draw_walls();

    //Sitzbank
    glPushMatrix();
    glTranslatef(85, 0, -230);
    draw_bench();
    glPopMatrix();
    
    //Schild
    glPushMatrix();
    glTranslatef(300, 0, -500);
    mat(GREY, GREY, GREY, 100);
    draw_zylinder(150, 2);
    glPopMatrix();

   
    
        
    //LichtKegel malen (transparent)
    draw_lightCones();

    //Puffer tauschen
    glutSwapBuffers();
}











/**
 * Mouse-Handler
 */
void mouse (int button, int state, int x, int y){
    
    switch(button){
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN)
           glutIdleFunc (moveKamera);
        break;
    case GLUT_MIDDLE_BUTTON:
        if(state == GLUT_DOWN)
           glutIdleFunc (NULL);
        break;
    default: break;
    }
}


/**
 * Keyboard-Handler
 */
void keyboard (unsigned char key, int x, int y){

    switch(key){
    case ' ':
        glutIdleFunc(moveKamera);
        break;
        
    case 27:
    	exit(0);
    	break;
        
    default: //Stillstand
        glutIdleFunc(NULL);
        break;
    }
}





/**
 * Main
 */
int main(int argc, char *argv[ ]){

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); // Double Buffer anfordern
    glutInitWindowSize (700,700);
    glutInitWindowPosition (100,100);
    glutCreateWindow("William Blacoe's OpenGL Wonderland");
    glutFullScreen();
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); //KeyboardHandler einstellen
    glutMouseFunc(mouse); //MausHandler einstellen
    glutMainLoop();
    
    return 0;
}
