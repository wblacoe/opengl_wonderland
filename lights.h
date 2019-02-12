/* Methoden:
        switchOnAllLights
        positionAllLights
        disableLight
        enableLight
*/


GLint lightDistanceFromMiddle = 150;

GLfloat light_position1[] = { middleX - lightDistanceFromMiddle, 300, middleZ + lightDistanceFromMiddle, 1 };
GLfloat light_position2[] = { middleX + lightDistanceFromMiddle, 300, middleZ + lightDistanceFromMiddle, 1 };
GLfloat light_position3[] = { middleX - lightDistanceFromMiddle, 300, middleZ - lightDistanceFromMiddle, 1 };
GLfloat light_position4[] = { middleX + lightDistanceFromMiddle, 300, middleZ - lightDistanceFromMiddle, 1 };

GLfloat runter[] = { 0, -1, 0 }; //wird für Spotlight gebraucht
GLfloat cutoff = 30.0f; //Winkel der Spotlights
GLfloat exponent = 30.0f;


/**
 * Die Parameter für die Lichter 1, 2, 3 und 4 setzen
 */
void switchOnAllLights(){

    //0
    glLightfv(GL_LIGHT0, GL_DIFFUSE, grey);
    glLightfv(GL_LIGHT0, GL_AMBIENT, almostBlack);
    glLightfv(GL_LIGHT0, GL_SPECULAR, grey);
    glEnable(GL_LIGHT0);

    //1
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightgrey);
    glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, runter);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, cutoff);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, exponent);
    
    //2
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightgrey);
    glLightfv(GL_LIGHT2, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT2, GL_SPECULAR, white);
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, runter);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, cutoff);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, exponent);
    
    //3
    glLightfv(GL_LIGHT3, GL_DIFFUSE, lightgrey);
    glLightfv(GL_LIGHT3, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT3, GL_SPECULAR, white);
    glEnable(GL_LIGHT3);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, runter);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, cutoff);
    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, exponent);
    
    //4
    glLightfv(GL_LIGHT4, GL_DIFFUSE, lightgrey);
    glLightfv(GL_LIGHT4, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT4, GL_SPECULAR, white);
    glEnable(GL_LIGHT4);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, runter);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, cutoff);
    glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, exponent);
    
    //5
    glLightfv(GL_LIGHT5, GL_DIFFUSE, lightgrey);
    glLightfv(GL_LIGHT5, GL_AMBIENT, almostBlack);
    glLightfv(GL_LIGHT5, GL_SPECULAR, white);
}


/**
 * Die Position der Lichter 1, 2, 3 und 4 festelegen
 */
void positionAllLights(){  
    
    GLfloat light_position0[] = { middleX, 200.0f, middleZ, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
    glLightfv(GL_LIGHT4, GL_POSITION, light_position4);
    
    GLfloat light_position5[] = { 540, 15, -380, 0 };
    glLightfv(GL_LIGHT5, GL_POSITION, light_position5);
}


/**
 * Ein Licht ausschalten
 */
void disableLight(GLenum lightID){
    glDisable(lightID);
}



/**
 * Ein Licht einschalten
 */
void enableLight(GLenum lightID){
    glEnable(lightID);
}














