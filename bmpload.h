/*
    Dieser Quelltext ist aus einem Forum kopiert:
    http://www.astahost.com/index.php?showtopic=14299&mode=threaded&pid=93548
    bzw. (und das ist im Prinzip dieselbe Seite)
    http://www.astahost.com/programming-glut-lesson-6-t14299.html
    Ich habe hinterher nur noch ein wenig die Formatierung verschönert.
*/

#pragma comment(lib, "opengl32.lib")//Link to the OpenGL libraries
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")

#include <windows.h>        // Header File For Windows
#include <gl\gl.h>            // Header File For The OpenGL32 Library
#include <gl\glu.h>            // Header File For The GLu32 Library
#include <gl\glaux.h>        // Header File For The Glaux Library


//Load a texture with linear filtering
bool linearbmp(UINT textureArray[], LPSTR strFileName, int ID){

    if(!strFileName)   return false;//check for a filename
    AUX_RGBImageRec *pBitMap = auxDIBImageLoad(strFileName); //Load our file

    if(pBitMap == NULL)    exit(0);// If no data was loaded then exit the program.
    glGenTextures(1, &textureArray[ID]);//Generate our texture
    glBindTexture(GL_TEXTURE_2D, textureArray[ID]);//bind our texture to texture targets
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);//set linear filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//set linear filtering
    glTexImage2D(GL_TEXTURE_2D, 0, 3, pBitMap->sizeX, pBitMap->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pBitMap->data);//create our texture

    if (pBitMap)    //If pBitMap still has a value then we want to clear it.                                    
    {
        if (pBitMap->data)                                
        {
            free(pBitMap->data);                        
        }
        free(pBitMap);                                    
    }
    return true;
}


//Load a texture with nearest filtering
bool nearestbmp(UINT textureArray[], LPSTR strFileName, int ID){

    if(!strFileName)   return false;//check for a filename
    AUX_RGBImageRec *pBitMap = auxDIBImageLoad(strFileName); //Load our file

    if(pBitMap == NULL)    exit(0);// If no data was loaded then exit the program.
    glGenTextures(1, &textureArray[ID]);//Generate our texture
    glBindTexture(GL_TEXTURE_2D, textureArray[ID]);//bind our texture to texture targets
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);//set linear filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);//set linear filtering
    
    
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    
    
    
    
    
    
    glTexImage2D(GL_TEXTURE_2D, 0, 3, pBitMap->sizeX, pBitMap->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pBitMap->data);//create our texture

    if (pBitMap)    //If pBitMap still has a value then we want to clear it.                                    
    {
        if (pBitMap->data)                                
        {
            free(pBitMap->data);                        
        }
        free(pBitMap);                                    
    }
    return true;
}


//Load a texture with mipmap filtering
bool mipmapbmp(UINT textureArray[], LPSTR strFileName, int ID){

    if(!strFileName)   return false;//check for a filename
    AUX_RGBImageRec *pBitMap = auxDIBImageLoad(strFileName); //Load our file

    if(pBitMap == NULL)    exit(0);// If no data was loaded then exit the program.
    glGenTextures(1, &textureArray[ID]);//Generate our texture
    glBindTexture(GL_TEXTURE_2D, textureArray[ID]);//bind our texture to texture targets
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//set linear filter
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);    //(NEW) set mipmapping filter

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitMap->sizeX, pBitMap->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pBitMap->data); //(NEW)create our mipmap texture

    if (pBitMap)    //If pBitMap still has a value then we want to clear it.                                    
    {
        if (pBitMap->data)                                
        {
            free(pBitMap->data);                        
        }
        free(pBitMap);                                    
    }
    return true;
}
