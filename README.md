This is a C++ program (using OpenGL) that shows a camera ride through an animated 3D scene.

A few settings and files are necessary to get the program to run. I used the [Dev-CPP IDE](https://www.bloodshed.net/devcpp.html).
- Run the compiler with the flags "-lopengl32 -lglu32 -lglut32 -lgdi32 -lglaux". In Dev-CPP this can be done via the menu under Tools -> Compiler Options.
- Copy "glut.h" and "glaux.h" to the "[Dev-CPP-folder]\include\GL" folder.
- Copy "libglut32.a" and "libglaux.a" to the "[Dev-CPP-folder]\lib" folder.

Press SPACE to start the camera ride. Press ESCAPE to end the program.