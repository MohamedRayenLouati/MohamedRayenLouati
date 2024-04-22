#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct struct_img {
SDL_Surface* image;
SDL_Rect positioninscrenn;
SDL_Rect positionfromimage;
}struct_img;
typedef struct struct_text{
 TTF_Font *font;
 SDL_Color color;
 SDL_Surface* text;
 SDL_Rect postext;
}struct_text;
typedef struct Personne
{
struct_img perso;
int direction;
int deplacement;
double vitesse;
Uint32 dt;
int up;
int velocityY;
int velocityX;
int groundY;
int tabcollison[4];
}Personne;
typedef struct background {
struct_img  background;
struct_img  masque;
int stage;
}background;
typedef struct minimap{
   struct_img minimap;
   struct_img bonhomme ;
   struct_img animation;
   struct_text time ;
   Uint32 timestarted;
}minimap;


 




void initmap(minimap * m);
void afficherminimap(minimap m,SDL_Surface *screen);
void Liberer (minimap * m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
SDL_Color  GetPixel(SDL_Surface *pSurface,int x,int y);
int collisionPP(Personne *p, SDL_Surface *Masque,background bp);
void init_maske(struct_img *maske);
void animerMinimap(minimap *m);
void calculnewtime(minimap *m);
