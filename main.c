#include <SDL/SDL.h>
#include <GL/GL.h>

SDL_Surface *screen =NULL;
int main(int argc, char *argv[])
{
demarre_opengl();
tourne_cube();
stop_opengl();
}


void demarre_opengl()
{
creer_fenetre_opengl();
init_opengl();
}


void creer_fenetre_opengl()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_GL_SetAttribute(SDL_GL_RED_SIZE,5);
SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,5);
SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,5);

SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);



SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
screen=SDL_SetVideoMode(
800,600,16,
SDL_OPENGL
|SDL_DOUBLEBUF
|SDL_HWSURFACE);

}

init_opengl()
{
/*utilise tt l ecran*/
glViewport(0,0,800,600);

/*les coulh st degradees*/
glShadeModel(GL_SMOOTH);

/*coulh noire lorsq on efface l ecran*/
glClearColor(0.0,0.0,0.0,
1.0);

/*profondeur des pixels lorsq on efface l ecran*/
glClearDepth(1.0);




/*comment choisir si un point est DV 1 autr ou pas Occlusion*/
glDepthFun(GL_LEQUAL);
/*n affiche pas les points caches*/
glEnable(GL_DEPTH_TEST);

/*initialisation de la base (repere en 3 dim)*/
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

/*toutes les faces d un polygone doivent etre dessinées*/
glPolygoneMode(GL_FRONT_AND_BLACK,GL_FILL);
}

void stop_opengl()
{
SDL_Quit();
}


void tourne_cube()
{
int i = 1000;

while (--i)
{
SDL_Delay(30);

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glBegin(GL_QUADS);
/*face du dessous*/
glColor3f(1.0,0.0,0.0);
glVertex3d(-.3,-.3,-.3);
glVertex3d(-.3,-.3,.3);

glVertex3d(.3,-.3,.3);
glVertex3d(.3,-.3,-.3);


/*face de devant*/
glColor3f(0.0,1.0,0.0);
glVertex3d(-.3,-.3,-.3);
glVertex3d(-.3,.3,-.3);

glVertex3d(.3,.3,-.3);
glVertex3d(.3,-.3,-.3);

/*face du dessus*/
glColor3f(1.0,0.0,0.0);
glVertex3d(-.3,.3,-.3);
glVertex3d(-.3,.3,.3);

glVertex3d(.3,.3,.3);
glVertex3d(.3,.3,-.3);


/*face de derriere*/
glColor3f(0.0,1.0,0.0);
glVertex3d(-.3,-.3,.3);
glVertex3d(-.3,.3,.3);

glVertex3d(.3,.3,.3);
glVertex3d(.3,-.3,.3);




/*face de droite*/
glColor3f(0.0,0.0,1.0);
glVertex3d(.3,-.3,-.3);
glVertex3d(.3,.3,-.3);

glVertex3d(.3,.3,.3);
glVertex3d(.3,-.3,.3);



/*face de gauche*/
glColor3f(0.0,0.0,1.0);
glVertex3d(-.3,-.3,-.3);
glVertex3d(-.3,.3,-.3);

glVertex3d(-.3,.3,.3);
glVertex3d(-.3,-.3,.3);

glEnd();

glRotated(5, 1.0,1.0,1.0);

SDL_GL_SwapBuffers();
}
}