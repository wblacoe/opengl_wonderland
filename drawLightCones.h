/*
 * Den LichtKegelstumpf der 4 Laternen malen
 */
void draw_lightCones(){

    GLfloat lightConeAlpha = 0.2;
    GLfloat lightConePercentage = 0.95;
    //light_position?[1] ist gleichzeitig die Höhe des LightCone
    
    glPushMatrix();
    glTranslatef(light_position1[0], light_position1[1]*(1-lightConePercentage), light_position1[2]);
    enableTransparency();
    draw_lightCone((int)light_position1[1], lightConePercentage, (int)(tan(180*cutoff/PI)*light_position1[1]), lightConeAlpha);
    disableTransparency();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light_position2[0], light_position2[1]*(1-lightConePercentage), light_position2[2]);
    enableTransparency();
    draw_lightCone((int)light_position2[1], lightConePercentage, (int)(tan(180*cutoff/PI)*light_position2[1]), lightConeAlpha);
    disableTransparency();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light_position3[0], light_position3[1]*(1-lightConePercentage), light_position3[2]);
    enableTransparency();
    draw_lightCone((int)light_position3[1], lightConePercentage, (int)(tan(180*cutoff/PI)*light_position3[1]), lightConeAlpha);
    disableTransparency();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light_position4[0], light_position4[1]*(1-lightConePercentage), light_position4[2]);
    enableTransparency();
    draw_lightCone((int)light_position4[1], lightConePercentage, (int)(tan(180*cutoff/PI)*light_position4[1]), lightConeAlpha);
    disableTransparency();
    glPopMatrix();
}
