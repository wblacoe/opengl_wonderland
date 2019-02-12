/* Methoden:
        enableTransparency
        disableTransparency
*/


/**
 * Transparenz anschalten
 */
void enableTransparency(){
    glDisable(GL_LIGHTING);
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

/**
 * (überladene Methode)
 * Transparenz anschalten und Alpha-Wert angeben
 */
void enableTransparency(GLfloat alpha){
    glColor4f(1,1,1,alpha);
    enableTransparency();
}


/**
 * Transparenz ausschalten
 */
void disableTransparency(){
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
}
