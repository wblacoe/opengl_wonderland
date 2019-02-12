/*
  ENTHÄLT DIE METHODEN
    draw_kegel
    draw_kugel
    draw_quader
    draw_zylinder
    draw_kegelstumpf
*/







/**
 * Einen Kegel malen
 * Der mittlere unterste Punkt befindet sich im lokalen Ursprung
 */
void draw_kegel(GLint hoehe, GLint radius){
    
    GLfloat ecken=aufl*2;
    GLfloat theta, theta2, phi;

    //Boden
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(0,-1,0);
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       0,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       0,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
    }
    glEnd();

    
    //Mantel
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(cos(2*PI*i/ecken),
                       j/ecken,
                       sin(2*PI*i/ecken));
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
    }
    glEnd();
    
}






/**
 * Eine Kugel malen
 * Der Mittelpunkt befindet sich im lokalen Ursprung
 */
void draw_kugel(GLint radius){
    
    GLfloat ecken=aufl;
    GLfloat theta, theta2, phi;
    
    glBegin(GL_QUAD_STRIP);
    for(int i1=0; i1<ecken; i1++){ 
        for(int i2=0; i2<=ecken; i2++){ //ein Breitenring
            
            theta=PI*i1/ecken;
            theta2=PI*(i1+1)/ecken;
            phi=2*PI*i2/ecken;
            
            glNormal3f(
            sin(theta)*cos(phi),
            sin(theta)*sin(phi),
            cos(theta));

            glVertex3f(
            radius*sin(theta)*cos(phi),
            radius*sin(theta)*sin(phi),
            radius*cos(theta));
            
            glVertex3f(
            radius*sin(theta2)*cos(phi),
            radius*sin(theta2)*sin(phi),
            radius*cos(theta2));
        }
    }
    glEnd();
    
}





/**
 * Einen Quader malen
 * Der Mittelpunkt befindet sich im lokalen Ursprung
 */
void draw_quader(GLint width, GLint height, GLint depth){
    
    GLfloat ecken = aufl*2;
    
    //vorne
    for(int y=0; y<ecken; y++){
        glBegin(GL_QUAD_STRIP);
        for(int x=0; x<=ecken; x++){
            glNormal3f(0,0,1);
            glVertex3f(-width/2+(width*x/ecken), +height/2-(height*y/ecken), +depth/2);
            glVertex3f(-width/2+(width*x/ecken), +height/2-(height*(y+1)/ecken), +depth/2);
        }
        glEnd();
    }
    
    //rechts
    for(int y=0; y<ecken; y++){
        glBegin(GL_QUAD_STRIP);
        for(int x=0; x<=ecken; x++){
            glNormal3f(1,0,0);
            glVertex3f(+width/2, +height/2-(height*y/ecken), +depth/2-(depth*x/ecken));
            glVertex3f(+width/2, +height/2-(height*(y+1)/ecken), +depth/2-(depth*x/ecken));
        }
        glEnd();
    }
    
    //hinten
    for(int y=0; y<ecken; y++){
        glBegin(GL_QUAD_STRIP);
        for(int x=0; x<=ecken; x++){
            glNormal3f(0,0,-1);
            glVertex3f(+width/2-(width*x/ecken), +height/2-(height*y/ecken), -depth/2);
            glVertex3f(+width/2-(width*x/ecken), +height/2-(height*(y+1)/ecken), -depth/2);
        }
        glEnd();
    }
    
    //links
    for(int y=0; y<ecken; y++){
        glBegin(GL_QUAD_STRIP);
        for(int x=0; x<=ecken; x++){
            glNormal3f(-1,0,0);
            glVertex3f(-width/2, +height/2-(height*y/ecken), -depth/2+(depth*x/ecken));
            glVertex3f(-width/2, +height/2-(height*(y+1)/ecken), -depth/2+(depth*x/ecken));
        }
        glEnd();
    }
    
    //oben
    for(int y=0; y<ecken; y++){
        glBegin(GL_QUAD_STRIP);
        for(int x=0; x<=ecken; x++){
            glNormal3f(0,1,0);
            glVertex3f(-width/2+(width*x/ecken), +height/2, -depth/2+(depth*y/ecken));
            glVertex3f(-width/2+(width*x/ecken), +height/2, -depth/2+(depth*(y+1)/ecken));
        }
        glEnd();
    }

    //unten
    for(int y=0; y<ecken; y++){
        glBegin(GL_QUAD_STRIP);
        for(int x=0; x<=ecken; x++){
            glNormal3f(0,-1,0);
            glVertex3f(-width/2+(width*x/ecken), -height/2, +depth/2-(depth*y/ecken));
            glVertex3f(-width/2+(width*x/ecken), -height/2, +depth/2-(depth*(y+1)/ecken));
        }
        glEnd();
    }
    
    
}




/**
 * Einen Zylinder malen
 * Der mittlere unterste Punkt befindet sich im lokalen Ursprung
 */
void draw_zylinder(GLint hoehe, GLint radius){
    
    GLfloat ecken=aufl*2;
    GLfloat theta, theta2, phi;

    //Boden
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(0,-1,0);
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       0,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       0,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
    }
    glEnd();


    //Deckel
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(0,1,0);
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       hoehe,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       hoehe,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
    }
    glEnd();

    
    //Mantel
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(cos(2*PI*i/ecken),
                       0,
                       sin(2*PI*i/ecken));
            glVertex3f(cos(2*PI*i/ecken)*radius,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*i/ecken)*radius);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*(i+1)/ecken)*radius);
        }
    }
    glEnd();
    
}




/**
 * Einen Kegelstumpf malen
 * Der mittlere unterste Punkt befindet sich im lokalen Ursprung
 * anteil ist zwischen 0 und 1 und besagt, wieviel von dem Kegel
 * behalten wird.
 */
void draw_kegelstumpf(GLint hoehe, GLfloat anteil, GLint radius){
    
    GLfloat ecken=aufl*2;
    GLfloat theta, theta2, phi;

    //Boden
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(0,-1,0);
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       0,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       0,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
    }
    glEnd();


    //Deckel
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(0,1,0);
            glVertex3f(cos(2*PI*i/ecken)*(1-anteil)*radius*j/ecken,
                       anteil*hoehe,
                       sin(2*PI*i/ecken)*(1-anteil)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*(1-anteil)*radius*j/ecken,
                       anteil*hoehe,
                       sin(2*PI*(i+1)/ecken)*(1-anteil)*radius*j/ecken);
        }
    }
    glEnd();

    
    //Mantel
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=(int)((1-anteil)*ecken); j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(cos(2*PI*i/ecken),
                       j/ecken,
                       sin(2*PI*i/ecken));
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
    }
    glEnd();
    
}




/**
 * Einen Torus malen
 * Der mittlere Punkt befindet sich im lokalen Ursprung
 * Der Torus "liegt" auf der x,y - Ebene
 */
void draw_torus(GLint radius_klein, GLint radius_gross){

    GLfloat ecken_klein=2*aufl;
    GLfloat ecken_gross=10*aufl;
    GLfloat theta, theta2, phi;
    
    
    glBegin(GL_QUAD_STRIP);
    for(int i1=0; i1<ecken_gross; i1++){ 
        for(int i2=0; i2<=ecken_klein; i2++){
            
            //Winkel im großen Kreis
            theta=2*PI*i1/ecken_gross;
            theta2=2*PI*(i1+1)/ecken_gross;
            
            //Winkel im kleinen Kreis
            phi=2*PI*i2/ecken_klein;
            
            glNormal3f(
            radius_gross*radius_klein*cos(theta)*cos(phi)+pow(radius_klein,2)*cos(theta)*pow(cos(phi),2),
            radius_gross*radius_klein*sin(theta)*cos(phi)+pow(radius_klein,2)*sin(theta)*pow(cos(phi),2),
            radius_gross*radius_klein*sin(phi)+pow(radius_klein,2)*sin(phi)*cos(phi));
            
            glVertex3f(
            (radius_gross+radius_klein*cos(phi))*cos(theta),
            (radius_gross+radius_klein*cos(phi))*sin(theta),
            radius_klein*sin(phi));

            glVertex3f(
            (radius_gross+radius_klein*cos(phi))*cos(theta2),
            (radius_gross+radius_klein*cos(phi))*sin(theta2),
            radius_klein*sin(phi));
        }
    }
    glEnd();
    
}






/**
 * Den Mantel eines Kegelstumpf malen
 * Hier wird zusätzlich glColor4f() benutzt für Transparenz
 * Der mittlere unterste Punkt befindet sich im lokalen Ursprung
 * anteil ist zwischen 0 und 1 und besagt, wieviel von dem Kegel
 * behalten wird.
 */
void draw_lightCone(GLint hoehe, GLfloat anteil, GLint radius, GLfloat alpha){
    
    GLfloat ecken=aufl*2;
    GLfloat theta, theta2, phi;
    
    //Mantel
    
    for(int i=0; i<ecken; i++){ //Winkel
        glBegin(GL_QUAD_STRIP);
        for(int j=(int)((1-anteil)*ecken); j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(cos(2*PI*i/ecken),
                       j/ecken,
                       sin(2*PI*i/ecken));
            glColor4f(0.8-j/ecken, 0.8-j/ecken, 0.0, alpha);
            glVertex3f(cos(2*PI*i/ecken)*radius*j/ecken,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*i/ecken)*radius*j/ecken);
            glColor4f(0.8-j/ecken, 0.8-j/ecken, 0.0, alpha);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius*j/ecken,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*(i+1)/ecken)*radius*j/ecken);
        }
        glEnd();
    }
    
    
}


/**
 * Einen Torus mit Streifen malen
 * Der mittlere Punkt befindet sich im lokalen Ursprung
 * Der Torus "liegt" auf der x,y - Ebene
 */
void draw_torusWithStripes(GLint radius_klein, GLint radius_gross, GLint farbe1, GLint farbe2){

    GLfloat ecken_klein=2*aufl;
    GLfloat ecken_gross=10*aufl;
    GLfloat theta, theta2, phi;
    
    
    glBegin(GL_QUAD_STRIP);
    for(int i1=0; i1<ecken_gross; i1++){ 
        if((int)(10*i1/ecken_gross)%2 == 0){
            mat(farbe1, LIGHTGREY, GREY, 50);
        }else{
            mat(farbe2, LIGHTGREY, GREY, 50);
    }
        for(int i2=0; i2<=ecken_klein; i2++){
            
            //Winkel im großen Kreis
            theta=2*PI*i1/ecken_gross;
            theta2=2*PI*(i1+1)/ecken_gross;
            
            //Winkel im kleinen Kreis
            phi=2*PI*i2/ecken_klein;
            
            glNormal3f(
            radius_gross*radius_klein*cos(theta)*cos(phi)+pow(radius_klein,2)*cos(theta)*pow(cos(phi),2),
            radius_gross*radius_klein*sin(theta)*cos(phi)+pow(radius_klein,2)*sin(theta)*pow(cos(phi),2),
            radius_gross*radius_klein*sin(phi)+pow(radius_klein,2)*sin(phi)*cos(phi));
            
            glVertex3f(
            (radius_gross+radius_klein*cos(phi))*cos(theta),
            (radius_gross+radius_klein*cos(phi))*sin(theta),
            radius_klein*sin(phi));

            glVertex3f(
            (radius_gross+radius_klein*cos(phi))*cos(theta2),
            (radius_gross+radius_klein*cos(phi))*sin(theta2),
            radius_klein*sin(phi));
        }
    }
    glEnd();
    
}



/**
 * Einen Tunnel malen
 */
void draw_tunnel(GLint hoehe, GLint radius_klein, GLint radius_gross){
    
    GLfloat ecken = aufl*2;
    GLint radius;
    
    //kleiner Mantel
    radius = radius_klein;
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(cos(2*PI*i/ecken),
                       0,
                       sin(2*PI*i/ecken));
            glVertex3f(cos(2*PI*i/ecken)*radius,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*i/ecken)*radius);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*(i+1)/ecken)*radius);
        }
    }
    glEnd();
   
   
    //großer Mantel
    radius = radius_gross;
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){ //Winkel
        for(int j=0; j<=ecken; j++){ //Abstand vom Mittelpunkt
            glNormal3f(cos(2*PI*i/ecken),
                       0,
                       sin(2*PI*i/ecken));
            glVertex3f(cos(2*PI*i/ecken)*radius,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*i/ecken)*radius);
            glVertex3f(cos(2*PI*(i+1)/ecken)*radius,
                       (1-j/ecken)*hoehe,
                       sin(2*PI*(i+1)/ecken)*radius);
        }
    }
    glEnd();
    
    
    //Deckel
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){
        glNormal3f(0, 1, 0);
        glVertex3f(cos(2*PI*(i+1)/ecken)*radius_klein,
                   hoehe,
                   sin(2*PI*(i+1)/ecken)*radius_klein);
        glVertex3f(cos(2*PI*(i+1)/ecken)*radius_gross,
                   hoehe,
                   sin(2*PI*(i+1)/ecken)*radius_gross);
    }
    glEnd();


    //Boden
    glBegin(GL_QUAD_STRIP);
    for(int i=0; i<=ecken; i++){
        glNormal3f(0, -1, 0);
        glVertex3f(cos(2*PI*(i+1)/ecken)*radius_gross,
                   0,
                   sin(2*PI*(i+1)/ecken)*radius_gross);
        glVertex3f(cos(2*PI*(i+1)/ecken)*radius_klein,
                   0,
                   sin(2*PI*(i+1)/ecken)*radius_klein);
    }
    glEnd();

}
