/* Methoden:
        draw_zwerg
        draw_laterne
        draw_alleLaternen
        draw_bench
        draw_tori
*/



/**
 * Einen Gartenzwerg mit der angegeben Farbe und Glanzzahl malen.
 * Der mittlere unterste Punkt des Zwerges befindet sich im Ursprung.
 *     RAHMEN:
 * x: von -53 bis 53
 * y: von 0 bis 105
 * z: von -15 bis 17
 */
void draw_zwerg(GLint zwergFarbe, GLfloat zwergShininess){
    
    //Mütze
    glTranslatef(0, 75, 0); //+45
    mat(zwergFarbe, LIGHTGREY, GREY, zwergShininess);
    draw_kegel(30, 15);
    
    //Kopf
    //lokale Koordinaten: (0, 70, 0);
    glTranslatef(0, -5, 0);
    mat(WOODEN, LIGHTGREY, GREY, zwergShininess);
    draw_kugel(15);

    //Rechtes Auge
    //lokale Koordinaten: (-4, 72, 13);
    glTranslatef(-4, 2, 13);
    glRotatef(90, 1, 0, 0);
    mat(GREY, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(2, 2);    
    glRotatef(-90, 1, 0, 0);

    //Linkes Auge
    //lokale Koordinaten: (4, 72, 13);
    glTranslatef(8, 0, 0);
    glRotatef(90, 1, 0, 0);
    mat(GREY, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(2, 2);   
    glRotatef(-90, 1, 0, 0); 
    
    //Nase
    //lokale Koordinaten: (0, 67, 15);
    glTranslatef(-4, -5, 2);
    glRotatef(90, 1, 0, 0);
    mat(WOODEN, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(5, 2);
    glRotatef(-90, 1, 0, 0);

    //Hals
    //lokale Koordinaten: (0, 50, 0);
    glTranslatef(0, -17, -15);
    mat(WOODEN, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(10, 5);
    
    //Torso
    //lokale Koordinaten: (0, 5, 0);
    glTranslatef(0, -45, 0);
    mat(zwergFarbe, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(45, 15);
    
    //Beide Arme
    //lokale Koordinaten: (30, 40, 0);
    glTranslatef(30, 35, 0);
    glRotatef(90,0,0,1);
    mat(zwergFarbe, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(60, 5);
    glRotatef(-90,0,0,1);
    
    //Rechte Hand
    //lokale Koordinaten: (-33, 40, 0);
    glTranslatef(-63, 0, 0);
    mat(WOODEN, LIGHTGREY, GREY, zwergShininess);
    draw_kugel(5);
    
    //Linke Hand
    //lokale Koordinaten: (33, 40, 0);
    glTranslatef(66, 0, 0);
    mat(WOODEN, LIGHTGREY, GREY, zwergShininess);
    draw_kugel(5);
    
    //Rechter Stiefel
    //lokale Koordinaten: (-7, 0, 13);
    glTranslatef(-40, -40, 13);
    mat(BLACK, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(5, 10);
    
    //Linker Stiefel
    //lokale Koordinaten: (7, 0, 13);
    glTranslatef(14, 0, 0);
    mat(BLACK, LIGHTGREY, GREY, zwergShininess);
    draw_zylinder(5, 10);

}




/**
 * Eine Laterne malen
 * Der unterste Punkt der Laterne ist im lokalen Ursprung
 * Sie ist so gebaut, dass der oberste mittlere Punkt
 * eines LightCones bei (0, 300, 18) liegt und einen Radius von 8 hat
 */
void draw_laterne(){
        
    mat(LIGHTGREY, GREY, GREY, 100);
    draw_zylinder(150, 8);
    
    glTranslatef(0, 150, 0);
    draw_kegel(15, 8);
    draw_zylinder(150, 5);
    
    glTranslatef(0, 152, 13);
    draw_quader(20, 6, 35);
    
    mat(YELLOW, LIGHTGREY, GREY, 10);
    matEmission(YELLOW);
    glTranslatef(0, -4, 5);
    draw_zylinder(1, 8);
    matEmission(BLACK);
}


/**
 * Alle 4 Laternen malen
 */
void draw_alleLaternen(){
    
    //Laterne1
    glPushMatrix();
    glTranslatef(light_position1[0], 0, light_position1[2] + 18);
    glRotatef(180, 0, 1, 0);
    draw_laterne();
    glPopMatrix();
    
    //Laterne2
    glPushMatrix();
    glTranslatef(light_position2[0], 0, light_position2[2] + 18);
    glRotatef(180, 0, 1, 0);
    draw_laterne();
    glPopMatrix();
    
    //Laterne1
    glPushMatrix();
    glTranslatef(light_position3[0], 0, light_position3[2] - 18);
    draw_laterne();
    glPopMatrix();
    
    //Laterne1
    glPushMatrix();
    glTranslatef(light_position4[0], 0, light_position4[2] - 18);
    draw_laterne();
    glPopMatrix();
}



/**
 * Eine Bank malen
 * Wenn man auf der Bank sitzt, dann ist der unterste Punkt
 * des rechten hinteren Beines im lokalen Ursprung
 *    RAHMEN:
 * x: 50
 * y: 80
 * z: 170
 */
void draw_bench(){
    
    glPushMatrix();
    mat(LIGHTGREY, LIGHTGREY, GREY, 30);
    
    glTranslatef(6, 20, 0);
    draw_quader(5, 40, 5);
    
    glTranslatef(34, 0, 0);
    draw_quader(5, 40, 5);
    
    glTranslatef(-17, 18, 0);
    glRotatef(90, 0, 0, 1);
    draw_quader(5, 40, 5);
    glRotatef(-90, 0, 0, 1);
    
    glTranslatef(-17, -18, -150);
    draw_quader(5, 40, 5);
    
    glTranslatef(34, 0, 0);
    draw_quader(5, 40, 5);
    
    glTranslatef(-20, 18, 0);
    glRotatef(90, 0, 0, 1);
    draw_quader(5, 37, 5);
    glRotatef(-90, 0, 0, 1);
    
    glTranslatef(-14, 0, 75);
    glRotatef(90, 1, 0, 0);
    draw_quader(5, 150, 5);
    
    glTranslatef(35, 0, 0);
    draw_quader(5, 150, 5);
    glRotatef(-90, 1, 0, 0);

    glTranslatef(-45, 21, 75);
    glRotatef(25, 0, 0, 1);
    draw_quader(5, 50, 5);
    
    glTranslatef(0, 0, -150);
    draw_quader(5, 50, 5);
    
    mat(DARKWOODEN, LIGHTGREY, GREY, 10);
    
    glTranslatef(3, 20, 75);
    draw_quader(3, 20, 170);

    glTranslatef(0, -25, 0);
    draw_quader(3, 20, 170);
    glRotatef(-25, 0, 0, 1);

    glTranslatef(18, -13, 0);
    draw_quader(18, 3, 170);

    glTranslatef(22, 0, 0);
    draw_quader(18, 3, 170);

    glPopMatrix();
   
}    



/**
 * alle 3 Tori malen
 */
void draw_tori(){
    
    //unterer Torus
    glPushMatrix();
    glTranslatef(100, 10, -100);
    glRotatef(90, 1, 0, 0);
    draw_torusWithStripes(15, 30, BLUE, GREEN);
    glPopMatrix();

    //oberer Torus
    glPushMatrix();
    glTranslatef(100, 40, -100);
    glRotatef(90, 1, 0, 0);
    draw_torusWithStripes(15, 30, RED, CYAN);
    glPopMatrix();

    //stehender Torus
    glPushMatrix();
    glTranslatef(72, 40, -138);
    glRotatef(55, 1, 1, 1);
    draw_torusWithStripes(15, 30, PURPLE, YELLOW);
    glPopMatrix();
}
