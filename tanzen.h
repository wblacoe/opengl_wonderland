/* Methoden:
        tanz1
        tanz2
        tanz3
        tanz4
        tanz
        reassignTanz
*/        



GLint zwerg_farben[] = { RED, GREEN, BLUE, YELLOW, PURPLE, CYAN };
GLint zwerg_tanzID[] = { 4, 1, 2, 4, 3, 2 };
GLint tauschPaar = 0;


void tanz1(){
    glRotatef(360*tanzZeit/tanzZeitMax, 0, 1, 0);
}

void tanz2(){
    glTranslatef(0, 50*4*(0.25-((tanzZeit/tanzZeitMax)-0.5)*((tanzZeit/tanzZeitMax)-0.5)), 0);
}

void tanz3(){
    tanz1();
    tanz2();
}

void tanz4(){
    //erstes Viertel
    if(tanzZeit/tanzZeitMax <= 0.3){
        glTranslatef(0, 0, 240*tanzZeit/tanzZeitMax);
    //viertes Viertel
    }else if(tanzZeit/tanzZeitMax >= 0.7){
        glTranslatef(0, 0, 240*tanzZeit/tanzZeitMax);
        glRotatef(180, 0, 1, 0);
    //zweites und drittes Viertel
    }else{
        glTranslatef(
         48*sin((double)(PI*(tanzZeit-tanzZeitMax*0.3)/(tanzZeitMax*0.4))),
         0,
         120 - 48*cos((double)(PI*(tanzZeit-tanzZeitMax*0.3)/(tanzZeitMax*0.4))));
        glRotatef(-180*(tanzZeit-tanzZeitMax/4)/(tanzZeitMax/2), 0, 1, 0);
    }
}


void tanz(GLint tanzID){
    
    switch(tanzID){
    case 1:
        tanz1();
        break;
    case 2:
        tanz2();
        break;    
    case 3:
        tanz3();
        break;
    case 4:
        tanz4();
        break;
    default:
        break;
    }
}


/**
 * Nach einer Tanzphase werden allen Zwergen
 * neue zufällige Tänze zugeordnet für
 * die nächste Tanzphase
 */
void reassignTanz(){
    
    //Die Farben der letzten Tauschpartner tauschen
    GLint temp = zwerg_farben[tauschPaar];
    zwerg_farben[tauschPaar] = zwerg_farben[tauschPaar+3];
    zwerg_farben[tauschPaar+3] = temp;
    
    //Für alle Zwerge einen zufälligen Tanz auswählen
    for(int i=0; i<6; i++){
        zwerg_tanzID[i] = rand()%4;
    }
    
    //Neue Tauschpartner wählen
    tauschPaar = rand()%3;
    zwerg_tanzID[tauschPaar] = 4;
    zwerg_tanzID[tauschPaar+3] = 4;
}



