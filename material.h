/* Methoden:
        mat
        matEmission
*/




/**
 * Materialeigenschaften einstellen
 */
void mat(GLint diffuse, GLint specular, GLint ambient, GLfloat shininess){

    switch(diffuse){
    case WHITE:     glMaterialfv(GL_FRONT, GL_DIFFUSE, white); break;
    case GREY:      glMaterialfv(GL_FRONT, GL_DIFFUSE, grey); break;
    case LIGHTGREY: glMaterialfv(GL_FRONT, GL_DIFFUSE, lightgrey); break;    
    case BLACK:     glMaterialfv(GL_FRONT, GL_DIFFUSE, black); break;
    case RED:       glMaterialfv(GL_FRONT, GL_DIFFUSE, red); break;
    case GREEN:     glMaterialfv(GL_FRONT, GL_DIFFUSE, green); break;
    case BLUE:      glMaterialfv(GL_FRONT, GL_DIFFUSE, blue); break;
    case YELLOW:    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow); break;
    case PURPLE:    glMaterialfv(GL_FRONT, GL_DIFFUSE, purple); break;
    case CYAN:      glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan); break;
    case WOODEN:    glMaterialfv(GL_FRONT, GL_DIFFUSE, wooden); break;
    case DARKWOODEN:glMaterialfv(GL_FRONT, GL_DIFFUSE, darkWooden); break;
    }

    switch(specular){
    case WHITE:     glMaterialfv(GL_FRONT, GL_SPECULAR, white); break;
    case GREY:      glMaterialfv(GL_FRONT, GL_SPECULAR, grey); break;
    case LIGHTGREY: glMaterialfv(GL_FRONT, GL_SPECULAR, lightgrey); break;    
    case BLACK:     glMaterialfv(GL_FRONT, GL_SPECULAR, black); break;
    case RED:       glMaterialfv(GL_FRONT, GL_SPECULAR, red); break;
    case GREEN:     glMaterialfv(GL_FRONT, GL_SPECULAR, green); break;
    case BLUE:      glMaterialfv(GL_FRONT, GL_SPECULAR, blue); break;
    case YELLOW:    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow); break;
    }
    
    switch(ambient){
    case WHITE:     glMaterialfv(GL_FRONT, GL_AMBIENT, white); break;
    case GREY:      glMaterialfv(GL_FRONT, GL_AMBIENT, grey); break;
    case LIGHTGREY: glMaterialfv(GL_FRONT, GL_AMBIENT, lightgrey); break;    
    case BLACK:     glMaterialfv(GL_FRONT, GL_AMBIENT, black); break;
    case RED:       glMaterialfv(GL_FRONT, GL_AMBIENT, red); break;
    case GREEN:     glMaterialfv(GL_FRONT, GL_AMBIENT, green); break;
    case BLUE:      glMaterialfv(GL_FRONT, GL_AMBIENT, blue); break;
    case YELLOW:    glMaterialfv(GL_FRONT, GL_AMBIENT, yellow); break;
    }
    
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    
}


/**
 * Emission von Material einstellen
 */
void matEmission(GLint emission){
    
    switch(emission){
    case WHITE:     glMaterialfv(GL_FRONT, GL_EMISSION, white); break;
    case GREY:      glMaterialfv(GL_FRONT, GL_EMISSION, grey); break;
    case LIGHTGREY: glMaterialfv(GL_FRONT, GL_EMISSION, lightgrey); break;    
    case BLACK:     glMaterialfv(GL_FRONT, GL_EMISSION, black); break;
    case RED:       glMaterialfv(GL_FRONT, GL_EMISSION, red); break;
    case GREEN:     glMaterialfv(GL_FRONT, GL_EMISSION, green); break;
    case BLUE:      glMaterialfv(GL_FRONT, GL_EMISSION, blue); break;
    case YELLOW:    glMaterialfv(GL_FRONT, GL_EMISSION, yellow); break;
    }

}
