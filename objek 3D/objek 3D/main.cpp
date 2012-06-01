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

GLfloat LightAmbient[]  = {0.5f, 0.5f, 0.5f, 1.0f};  // Gray (constant factor)
GLfloat LightDiffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};  // White (all directions)
// default for specular is black
GLfloat LightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f};  // behind camera (relative to camera)
bool lightingEnabled = false;   // Lighting enabled or disabled

static int kameraX = 0, kameraY = 0, kameraZ = 10, sudut = 0;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.50);
    
    /*GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0, 0, 0, 1.0 };
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);*/   
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 100.0 };
	GLfloat mat_shininess[] = { 50.0 };
    GLfloat mat_emission[]={0,0,0,100};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    
	glLightfv(GL_LIGHT1, GL_AMBIENT,  LightAmbient);  // Setup the ambient component
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  LightDiffuse);  // Setup the diffuse component
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition); // Position light-1
    
    
    
    glEnable(GL_LIGHT1);     // Enable Light-1
    glDisable(GL_LIGHTING);
    
    
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();
    gluLookAt ((GLdouble)kameraX, (GLdouble)kameraY, (GLdouble)kameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glPushMatrix();
        glRotatef((GLfloat)sudut, 0.0, 1.0, 0.0);//(GLfloat)rX, (GLfloat)rY, (GLfloat)rZ);
        //moncong kereta
        
        glPushMatrix();
            glRotated(90, 0, 1, 0);
            glTranslated(0, 0, -2.5);
                glColor3f(0.0f, 0.0f, 0.0f);
                gluCylinder(gluNewQuadric(), 1.2, 1.2, 4, 50, 1);
        glPopMatrix();
        //kabin
        glPushMatrix();
            glScaled(1, 1.2, 1);
            glTranslated(2, 0.35, 0);
                glutSolidCube(2.5);
        glPopMatrix();
        //cerobong asap
        glPushMatrix();
            glTranslated(0, 3, 0);
            glRotated(90, 1, 0, 0);
            glTranslated(-1.3, 0, 0.8);
                gluCylinder(gluNewQuadric(), 0.5, 0.5, 1, 50, 1);
        glPopMatrix();
    
            //roda belakang
            glPushMatrix();
                glTranslated(-1.2, -1.5, -0.8);
                    gluCylinder(gluNewQuadric(), 0.5, 0.5, 0.25, 50, 1);
            glPopMatrix();
            
            glPushMatrix();
                glTranslated(-1.2, -1.5, 0.6);
                    gluCylinder(gluNewQuadric(), 0.5, 0.5, 0.25, 50, 1);
            glPopMatrix();
            //roda depan
            glPushMatrix();
                glTranslated(2, -1.5, -0.8);
                    gluCylinder(gluNewQuadric(), 0.5, 0.5, 0.25, 50, 1);
            glPopMatrix();
            
            glPushMatrix();
                glTranslated(2, -1.5, 0.6);
                    gluCylinder(gluNewQuadric(), 0.5, 0.5, 0.25, 50, 1);
            glPopMatrix();
            //penutup roda
            glPushMatrix();
                glScaled(5, 0.5, 0.25);
                glTranslated(0.1, -2.5, 4);
                    glutSolidCube(1);
            glPopMatrix();
            
            glPushMatrix();
                glScaled(5, 0.5, 0.25);
                glTranslated(0.1, -2.5, -4);
                    glutSolidCube(1);
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
			lightingEnabled = !lightingEnabled;
            if (!lightingEnabled)
                glDisable(GL_LIGHTING);
            else
                glEnable(GL_LIGHTING);
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
    //glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kereta Api");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutSpecialFunc(specialKeyboard);
    glutMainLoop();
    return 0;
}
