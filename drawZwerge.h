GLfloat zwerg_position1[] = { 0, 0, -120 };
GLfloat zwerg_position2[] = { 101, 0, -53 };
GLfloat zwerg_position3[] = { 102, 0, 58 };
GLfloat zwerg_position4[] = { 0, 0, 120 };
GLfloat zwerg_position5[] = { -103, 0, 58 };
GLfloat zwerg_position6[] = { -102, 0, -53 };

/**
 * Alle 6 Zwerge malen
 */
void draw_zwerge(){
        
    GLfloat zwerg_glanzZahl = 5.0f;
    
    //1
    glPushMatrix();
    glTranslatef(middleX + zwerg_position1[0], zwerg_position1[1], middleZ + zwerg_position1[2]);
    glRotatef(0, 0, 1, 0);
    if(tanzZeit>=0) tanz(zwerg_tanzID[0]);
    glColor4f(1,0,0,0);
    draw_zwerg(zwerg_farben[0], zwerg_glanzZahl);
    glPopMatrix();
   
    //2
    glPushMatrix();
    glTranslatef(middleX + zwerg_position2[0], zwerg_position2[1], middleZ + zwerg_position2[2]);
    glRotatef(300, 0, 1, 0);
    if(tanzZeit>=0) tanz(zwerg_tanzID[1]);
    draw_zwerg(zwerg_farben[1], zwerg_glanzZahl);
    glPopMatrix();
    
    //3
    glPushMatrix();
    glTranslatef(middleX + zwerg_position3[0], zwerg_position3[1], middleZ + zwerg_position3[2]);
    glRotatef(240, 0, 1, 0);
    if(tanzZeit>=0) tanz(zwerg_tanzID[2]);
    draw_zwerg(zwerg_farben[2], zwerg_glanzZahl);
    glPopMatrix();
    
    //4
    glPushMatrix();
    glTranslatef(middleX + zwerg_position4[0], zwerg_position4[1], middleZ + zwerg_position4[2]);
    glRotatef(180, 0, 1, 0);
    if(tanzZeit>=0) tanz(zwerg_tanzID[3]);
    draw_zwerg(zwerg_farben[3], zwerg_glanzZahl);
    glPopMatrix();
    
    //5
    glPushMatrix();
    glTranslatef(middleX + zwerg_position5[0], zwerg_position5[1], middleZ + zwerg_position5[2]);
    glRotatef(120, 0, 1, 0);
    if(tanzZeit>=0) tanz(zwerg_tanzID[4]);
    draw_zwerg(zwerg_farben[4], zwerg_glanzZahl);
    glPopMatrix();
    
    //6
    glPushMatrix();
    glTranslatef(middleX + zwerg_position6[0], zwerg_position6[1], middleZ + zwerg_position6[2]);
    glRotatef(60, 0, 1, 0);
    if(tanzZeit>=0) tanz(zwerg_tanzID[5]);
    draw_zwerg(zwerg_farben[5], zwerg_glanzZahl);
    glPopMatrix();
 


}
