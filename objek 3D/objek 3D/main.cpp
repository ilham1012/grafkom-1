//
//  main.cpp
//  objek 3D
//
//  Created by Muhammad Ilham on 5/15/12.
//  Copyright (c) 2012 UNIKOM. All rights reserved.
//

#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

static int kameraX = 0, kameraY = 0, kameraZ = 10, sudut = 0;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();
    gluLookAt ((GLdouble)kameraX, (GLdouble)kameraY, (GLdouble)kameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glPushMatrix();
    glRotatef((GLfloat)sudut, 0.0, 1.0, 0.0);//(GLfloat)rX, (GLfloat)rY, (GLfloat)rZ);
        glPushMatrix();
            glScalef(1.0, 0.8, 1.0);
            glutWireSphere(2, 50, 50);
        glPopMatrix();
        glPushMatrix();
            glScalef(1.5, 0.25, 1.5);
            glutWireSphere(2, 50, 50);
        glPopMatrix();
    glPopMatrix();
    
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
    
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 's':
            if(kameraY > - 15){
                kameraY = kameraY - 5;
            }
			glutPostRedisplay();
			break;
		case 'w':
            if(kameraY < 15){
                kameraY = kameraY + 5;
            }
			glutPostRedisplay();
			break;
        case 'a':
            sudut = sudut + 10;
			glutPostRedisplay();
			break;
        case 'd':
			sudut = sudut - 10;
			glutPostRedisplay();
			break;
        case '1':
			kameraY = 0;
            kameraZ = 0;
            kameraX = 10;
			glutPostRedisplay();
			break;
        case '2':
			kameraY = 0;
            kameraZ = 0;
            kameraX = -10;
			glutPostRedisplay();
			break;
        case '3':
			kameraY = 0;
            kameraZ = 10;
            kameraX = 10;
			glutPostRedisplay();
			break;
        case '4':
			kameraY = 0;
            kameraZ = -10;
            kameraX = -10;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}
/*void specialKeyboard(int key, int x, int y) {
    switch (key)
    {
        case GLUT_KEY_RIGHT:
            sudut = sudut + 10;
			glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            sudut = sudut - 10;
			glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            if(kameraX < 15){
                kameraX = kameraX + 5;
            }            break;
            
        case GLUT_KEY_DOWN:
            if(kameraX > - 15){
                kameraX = kameraX - 5;
            }
            glutPostRedisplay();
            break;
    }
    
}*/

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutSpecialFunc(specialKeyboard);
    glutMainLoop();
    return 0;
}