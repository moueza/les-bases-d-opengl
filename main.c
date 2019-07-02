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

}