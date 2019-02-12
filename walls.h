/**
 * Die ‰uﬂeren W‰nde der Welt malen
 */
void draw_walls(){
    
    //Kommentare sind relativ zur Sicht nach (0,0,-1)
    
    //rechte Wand
    mat(WHITE, WHITE, GREY, 120);
    glPushMatrix();
    glTranslatef(600, 0, 0);
    draw_texturierteWand(Xneg, WINDOW_WALL, 1.0, 1.0, 600, 600, 100, 100);
    glPopMatrix();

    //linke Wand
    glPushMatrix();
    glTranslatef(0, 0, 0);
    draw_texturierteWand(Xpos, WINDOW_WALL, 1.0, 1.0, 600, 600, 100, 100);
    glPopMatrix();

    //Himmel
    glPushMatrix();
    glTranslatef(0, 600, 0);
    draw_texturierteWand(Yneg, STARS, 1.0, 1.0, 600, 600, 100, 100);
    glPopMatrix();

    //Boden
    //auﬂen Pavement
    glPushMatrix();
    draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 75, 600, 75, 75);
    glTranslatef(0, 0, -75);
    draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 450, 75, 75, 75);
    glTranslatef(0, 0, -450);
    draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 75, 600, 75, 75);
    glTranslatef(525, 0, 450);
    draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 450, 75, 75, 75);
    glPopMatrix();
    
    //auﬂen Gras
    glPushMatrix();
    glTranslatef(75, 0, -75);
    draw_texturierteWand(Ypos, GRASS, 1.0, 1.0, 75, 450, 75, 75);
    glTranslatef(0, 0, -75);
    draw_texturierteWand(Ypos, GRASS, 1.0, 1.0, 300, 75, 75, 75);
    glTranslatef(0, 0, -300);
    draw_texturierteWand(Ypos, GRASS, 1.0, 1.0, 75, 450, 75, 75);
    glTranslatef(375, 0, 300);
    draw_texturierteWand(Ypos, GRASS, 1.0, 1.0, 300, 75, 75, 75);
    glPopMatrix();
    
    //innen
    glPushMatrix();
    glTranslatef(150, 0, -150);
    for(int i=0; i<4; i++){
        draw_texturierteWand(Ypos, KREIS, 1.0, 1.0, 75, 75, 75, 75);
        glTranslatef(75, 0, 0);
        draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 75, 75, 75, 75);
        glTranslatef(75, 0, 0);
        draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 75, 75, 75, 75);
        glTranslatef(150, 0, 0);
        glRotatef(90, 0, 1, 0);
    }
    glTranslatef(75, 0, -75);
    draw_texturierteWand(Ypos, PAVEMENT, 1.0, 1.0, 150, 150, 75, 75);    
    glPopMatrix();
    


    //near Wand
    glPushMatrix();
    glTranslatef(0, 0, 0);
    draw_texturierteWand(Zneg, CONCRETE_WALL, 1.0, 1.0, 600, 600, 50, 50);
    glPopMatrix();

    //far Wand
    glPushMatrix();
    glTranslatef(0, 0, -600);
    draw_texturierteWand(Zpos, GREY_WALL, 1.0, 1.0, 600, 600, 100, 100);
    glPopMatrix();
    
    
    
    
    //Schild
    glPushMatrix();
    glTranslatef(250, 120, -498);
    draw_texturierteWand(Zpos, SCHILD, 1.0, 1.0, 100, 60, 100, 60);
    draw_texturierteWand(Zneg, SCHILD, 1.0, 1.0, 100, 60, 100, 60);
    glPopMatrix();
}
