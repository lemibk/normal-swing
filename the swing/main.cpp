#include<GL/glut.h>
#include<math.h>
float r = 1.0f, g = 0.0f, b = 0.0f;
float tx = 0, ty = -15, tz = 0;
float xr = 0.001, angle = 180.0f, rr = 0.001;
void init() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20, 20, -20, 20, -20, 20);
	glEnable(GL_DEPTH);

}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glRotatef(angle, 0, 0, 1);
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(0, 10, 0);
	glScalef(2,1,1);
	glutSolidCube(2);

	glPopMatrix();
	//the mover
	
	glPushMatrix();
	glTranslatef(0, 9, 0);
	glRotatef(angle, 0, 0, 1);
	//the swing
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, 9, 0);
	glScalef(0.5, 3, 1);
	glRotatef(90, 1, 0, 0);
	GLUquadric* tri = gluNewQuadric();
	gluCylinder(tri, 1, 1, 3, 32, 32);
	glPopMatrix();

	//the cube
	glPushMatrix();
	glTranslatef(0,8,0);
	glColor3f(0, 0, 1);
	glutSolidCube(2);
	glPopMatrix();
	//the mover
	
	glPopMatrix();


	glFlush();




}
void keyPress(unsigned char key, int x, int y) {
	switch (key)
	{
	
	case 'f':
		xr = xr + 0.005;
		break;
	case 's':
		xr = xr - 0.005;
		break;
	case 'p':
		xr = 0;
		angle = 180.0;
		break;
	case 'q':
		xr = 0.05;
		break;

	}
	glutPostRedisplay();
}
void animate() {

	rr = 2*xr;

	if (angle<260) {
		angle = angle + xr;



	}
	else {
		angle = angle - rr;
	}
	


	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Swing");
	init();
	glutKeyboardFunc(keyPress);
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutMainLoop();
}