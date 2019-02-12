

//Die eye und center-Koordinaten der 5 Kamerafahrt-Phasen
GLfloat anfangsPosition[] = { 50, 380, 10, 270, 50, -350 };
GLfloat tunnelEingang[] = { 520, 20, -180, 500, 30, -300 };
GLfloat tunnelAusgang[] = { 520, 20, -520, 500, 30, -600 };
GLfloat richtungHimmel[] = { 550, 420, -550, 250, 600, -250 };
GLfloat runterInDieEcke[] = { 50, 50, -550, 200, 100, -200 };


/**
 * Kamerafahrt
 */
void moveKamera(){
    
    Sleep(sleepTime);

    //Licht5 (nur) im Tunnel einschalten
    //if(zeit>=62 && zeit<85){
    if(zeitPhase * 62 / 50 <= zeit && zeit < zeitPhase * 85 / 50){
        enableLight(GL_LIGHT5);
    }else{
        disableLight(GL_LIGHT5);
    }
    
    //Phase1
    if(zeit>=zeitPhase*0 && zeit<zeitPhase*1){
        eyeX = (int)(anfangsPosition[0] + (tunnelEingang[0] - anfangsPosition[0]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeY = (int)(anfangsPosition[1] + (tunnelEingang[1] - anfangsPosition[1]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeZ = (int)(anfangsPosition[2] + (tunnelEingang[2] - anfangsPosition[2]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        
        centerX = (int)(anfangsPosition[3] + (tunnelEingang[3] - anfangsPosition[3]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerY = (int)(anfangsPosition[4] + (tunnelEingang[4] - anfangsPosition[4]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerZ = (int)(anfangsPosition[5] + (tunnelEingang[5] - anfangsPosition[5]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
    }
    
    //Phase2
    if(zeit>=zeitPhase*1 && zeit<zeitPhase*2){
        eyeX = (int)(tunnelEingang[0] + (tunnelAusgang[0] - tunnelEingang[0]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeY = (int)(tunnelEingang[1] + (tunnelAusgang[1] - tunnelEingang[1]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeZ = (int)(tunnelEingang[2] + (tunnelAusgang[2] - tunnelEingang[2]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        
        centerX = (int)(tunnelEingang[3] + (tunnelAusgang[3] - tunnelEingang[3]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerY = (int)(tunnelEingang[4] + (tunnelAusgang[4] - tunnelEingang[4]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerZ = (int)(tunnelEingang[5] + (tunnelAusgang[5] - tunnelEingang[5]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
    }

    //Phase3
    if(zeit>=zeitPhase*2 && zeit<zeitPhase*3){
        eyeX = (int)(tunnelAusgang[0] + (richtungHimmel[0] - tunnelAusgang[0]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeY = (int)(tunnelAusgang[1] + (richtungHimmel[1] - tunnelAusgang[1]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeZ = (int)(tunnelAusgang[2] + (richtungHimmel[2] - tunnelAusgang[2]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        
        centerX = (int)(tunnelAusgang[3] + (richtungHimmel[3] - tunnelAusgang[3]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerY = (int)(tunnelAusgang[4] + (richtungHimmel[4] - tunnelAusgang[4]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerZ = (int)(tunnelAusgang[5] + (richtungHimmel[5] - tunnelAusgang[5]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
    }

    //Phase4
    if(zeit>=zeitPhase*3 && zeit<zeitPhase*4){
        eyeX = (int)(richtungHimmel[0] + (runterInDieEcke[0] - richtungHimmel[0]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeY = (int)(richtungHimmel[1] + (runterInDieEcke[1] - richtungHimmel[1]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeZ = (int)(richtungHimmel[2] + (runterInDieEcke[2] - richtungHimmel[2]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        
        centerX = (int)(richtungHimmel[3] + (runterInDieEcke[3] - richtungHimmel[3]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerY = (int)(richtungHimmel[4] + (runterInDieEcke[4] - richtungHimmel[4]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerZ = (int)(richtungHimmel[5] + (runterInDieEcke[5] - richtungHimmel[5]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
    }
    
    //Phase5
    if(zeit>=zeitPhase*4 && zeit<zeitPhase*5){
        eyeX = (int)(runterInDieEcke[0] + (anfangsPosition[0] - runterInDieEcke[0]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeY = (int)(runterInDieEcke[1] + (anfangsPosition[1] - runterInDieEcke[1]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        eyeZ = (int)(runterInDieEcke[2] + (anfangsPosition[2] - runterInDieEcke[2]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        
        centerX = (int)(runterInDieEcke[3] + (anfangsPosition[3] - runterInDieEcke[3]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerY = (int)(runterInDieEcke[4] + (anfangsPosition[4] - runterInDieEcke[4]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
        centerZ = (int)(runterInDieEcke[5] + (anfangsPosition[5] - runterInDieEcke[5]) * ((int)zeit%(int)zeitPhase)/zeitPhase);
    }


    // ZEIT INKREMENTIEREN
    zeit++;
    if(zeit>=zeitMax) zeit=0;
    
    tanzZeit++;
    if(tanzZeit>=tanzZeitMax){
        tanzZeit = -10; //10 Zeiteinheiten Pause
        reassignTanz();
    }    
    
    glutPostRedisplay();

}
