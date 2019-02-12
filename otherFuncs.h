/**
 * Wenn die Fenstergröße verändert wird
 */
void reshape (int w, int h){
    
    //Zeichne in komplettes Fenster
    glViewport (0,0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);

    //Größenanpassung bei Fensterveränderung
    glLoadIdentity();
    GLfloat laenge = 2000.0f;
    if (w <= h){
       glFrustum(-laenge,
               laenge,
               -laenge*(GLfloat)h/(GLfloat)w,
               laenge*(GLfloat)h/(GLfloat)w,
               -laenge,
               laenge);
    }else{
        glFrustum(-laenge*(GLfloat)w/(GLfloat)h,
                laenge*(GLfloat)w/(GLfloat)h,
                -laenge,
                laenge,
                -laenge,
                laenge);
    }

    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 5, 10000.0);
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


