/**    
 * Eine groﬂe Wand malen, die in Felder unterteilt wird.
 * Die Textur mit dem Index texturID wird dann in jedes
 * Feld genau einmal gemalt.
 *
 * wandBreite MUSS durch feldBreite teilbar sein
 * wandHoehe MUSS durch feldHoehe teilbar sein
 * sonst wird die Wand grˆﬂer als gewollt
 *
 * texturID ist der Index der Textur im globalen textures-Array
 * texturBreite, und texturHoehe sind die PixelMaﬂe der TexturDatei
 */    
void draw_texturierteWand(GLint richtung, GLint texturID, GLfloat texturBreite, GLfloat texturHoehe, GLfloat wandBreite, GLfloat wandHoehe, GLfloat feldBreite, GLfloat feldHoehe){

    GLfloat a = 1.0f; //alpha wird vielleicht noch gebraucht
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[texturID]);



    switch(richtung){


    //falls die Wand nach (-1,0,0) zeigt
    //Ausbreitung von (0,0) nach (-z,+y)
    case(Xneg): 
        for(int y = 0; y<wandHoehe/feldHoehe; y++){ //viele Streifen
            glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            for(int x = 0; x<wandBreite/feldBreite; x++){ //ein Streifen von Feldern
                glTexCoord2f(0.0, 0.0); 
                glVertex4f(0, y*feldHoehe, -(x+1)*feldBreite, a);
                
                glTexCoord2f(texturBreite, 0.0);
                glVertex4f(0, y*feldHoehe, -x*feldBreite, a);
                
                glTexCoord2f(texturBreite, texturHoehe);
                glVertex4f(0, (y+1)*feldHoehe, -x*feldBreite, a);
                
                glTexCoord2f(0.0, texturHoehe);
                glVertex4f(0, (y+1)*feldHoehe, -(x+1)*feldBreite, a);
            }
            glEnd();
        }
    break;


    //falls die Wand nach (1,0,0) zeigt
    //Ausbreitung von (0,0) nach (-z,+y)
    case(Xpos): 
        for(int y = 0; y<wandHoehe/feldHoehe; y++){ //viele Streifen
            glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            for(int x = 0; x<wandBreite/feldBreite; x++){ //ein Streifen von Feldern
                glTexCoord2f(0.0, 0.0); 
                glVertex4f(0, y*feldHoehe, -x*feldBreite, a);
                
                glTexCoord2f(texturBreite, 0.0);
                glVertex4f(0, y*feldHoehe, -(x+1)*feldBreite, a);
                
                glTexCoord2f(texturBreite, texturHoehe);
                glVertex4f(0, (y+1)*feldHoehe, -(x+1)*feldBreite, a);
                
                glTexCoord2f(0.0, texturHoehe);
                glVertex4f(0, (y+1)*feldHoehe, -x*feldBreite, a);
            }
            glEnd();
        }
    break;


    //falls die Wand nach (0,-1,0) zeigt
    //Ausbreitung von (0,0) nach (+x,-z)
    case(Yneg):
        for(int y = 0; y<wandHoehe/feldHoehe; y++){ //viele Streifen
            glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            for(int x = 0; x<wandBreite/feldBreite; x++){ //ein Streifen von Feldern
                glTexCoord2f(0.0, 0.0); 
                glVertex4f(y*feldHoehe, 0, -x*feldBreite, a);
                
                glTexCoord2f(texturBreite, 0.0);
                glVertex4f(y*feldHoehe, 0, -(x+1)*feldBreite, a);
                
                glTexCoord2f(texturBreite, texturHoehe);
                glVertex4f((y+1)*feldHoehe, 0, -(x+1)*feldBreite, a);
                
                glTexCoord2f(0.0, texturHoehe);
                glVertex4f((y+1)*feldHoehe, 0, -x*feldBreite, a);
            }
            glEnd();
        }
    break;


    //falls die Wand nach (0,1,0) zeigt
    //Ausbreitung von (0,0) nach (+x,-z)
    case(Ypos):
        for(int y = 0; y<wandHoehe/feldHoehe; y++){ //viele Streifen
            glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            for(int x = 0; x<wandBreite/feldBreite; x++){ //ein Streifen von Feldern
                glTexCoord2f(0.0, 0.0); 
                glVertex4f((y+1)*feldHoehe, 0, -x*feldBreite, a);
                
                glTexCoord2f(texturBreite, 0.0);
                glVertex4f((y+1)*feldHoehe, 0, -(x+1)*feldBreite, a);
                
                glTexCoord2f(texturBreite, texturHoehe);
                glVertex4f(y*feldHoehe, 0, -(x+1)*feldBreite, a);
                
                glTexCoord2f(0.0, texturHoehe);
                glVertex4f(y*feldHoehe, 0, -x*feldBreite, a);
            }
            glEnd();
        }
    break;


    //falls die Wand nach (0,0,-1) zeigt
    //Ausbreitung von (0,0) nach (+x,+y)
    case(Zneg):
        for(int y = 0; y<wandHoehe/feldHoehe; y++){ //viele Streifen
            glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            for(int x = 0; x<wandBreite/feldBreite; x++){ //ein Streifen von Feldern
                glTexCoord2f(0.0, 0.0); 
                glVertex4f((x+1)*feldBreite, y*feldHoehe, 0, a);
                
                glTexCoord2f(texturBreite, 0.0);
                glVertex4f(x*feldBreite, y*feldHoehe, 0, a);
                
                glTexCoord2f(texturBreite, texturHoehe);
                glVertex4f(x*feldBreite, (y+1)*feldHoehe, 0, a);
                
                glTexCoord2f(0.0, texturHoehe);
                glVertex4f((x+1)*feldBreite, (y+1)*feldHoehe, 0, a);
            }
            glEnd();
        }
    break;


    //falls die Wand nach (0,0,-1) zeigt
    //Ausbreitung von (0,0) nach (+x,+y)
    case(Zpos):
        for(int y = 0; y<wandHoehe/feldHoehe; y++){ //viele Streifen
            glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            for(int x = 0; x<wandBreite/feldBreite; x++){ //ein Streifen von Feldern
                glTexCoord2f(0.0, 0.0); 
                glVertex4f(x*feldBreite, y*feldHoehe, 0, a);
                
                glTexCoord2f(texturBreite, 0.0);
                glVertex4f((x+1)*feldBreite, y*feldHoehe, 0, a);
                
                glTexCoord2f(texturBreite, texturHoehe);
                glVertex4f((x+1)*feldBreite, (y+1)*feldHoehe, 0, a);
                
                glTexCoord2f(0.0, texturHoehe);
                glVertex4f(x*feldBreite, (y+1)*feldHoehe, 0, a);
            }
            glEnd();
        }
    break;
    
    }
    
    glDisable(GL_TEXTURE_2D);
    
}
