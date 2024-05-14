#include "fenetre.h"
void init_background(struct_img *background)
{
  background->image = IMG_Load("resources/images/background/back.png");
  background->positionfromimage.x = 0;
  background->positionfromimage.y = 0;
  background->positionfromimage.h = 600;
  background->positionfromimage.w = 600;
 
};
void init_maske(struct_img *maske)
{
  maske->image = IMG_Load("resourcesMinimap/images/background/backgroundmask/backmaske.png");
  maske->positionfromimage.x = 0;
  maske->positionfromimage.y = 0;
  maske->positionfromimage.h = 600;
  maske->positionfromimage.w = 600;
 
};
void initPerso(Personne *p)
{
  p->up = 0;
  p->velocityX = 40;
  p->velocityY = -60;
  p->groundY = 40;
  p->perso.image = IMG_Load("resources/images/sprite sheet/sprite1.png");
  p->perso.positionfromimage.x = 0;
  p->perso.positionfromimage.y = 0;
  p->perso.positionfromimage.h = 47;
  p->perso.positionfromimage.w = 30;
  p->perso.positioninscrenn.x = 286;
  p->perso.positioninscrenn.y = 400;
  p->direction = 0;
  p->deplacement = 0;
  p->tabcollison[0]=1;
   p->tabcollison[1]=1;
     p->tabcollison[2]=1;
   p->tabcollison[3]=1;
};

void animerPerso(Personne *p)
{
  p->perso.positionfromimage.x = p->perso.positionfromimage.x + p->perso.positionfromimage.w;
  if (p->perso.positionfromimage.x > p->perso.image->w - p->perso.positionfromimage.w)
  {
    p->perso.positionfromimage.x = 0;
  }
  if (p->up == 1)
  {
    p->perso.positionfromimage.y = 2 * p->perso.positionfromimage.h;
  }
  else
  {
    p->perso.positionfromimage.y = p->direction * p->perso.positionfromimage.h;
  }
};

void afficherPerso(Personne p, SDL_Surface *screen)
{
  SDL_BlitSurface(p.perso.image, &p.perso.positionfromimage, screen, &p.perso.positioninscrenn);
};

void movePerso(Personne *p, background *bp)
{
  switch (p->direction)
  {
  case 0:
  if(p->tabcollison[0]==0) {
    if (p->perso.positioninscrenn.x > 300)
      bp->background.positionfromimage.x += p->vitesse * p->dt; 
      p->perso.positioninscrenn.x += p->vitesse * p->dt;
  }

    break;
  case 1:
   if(p->tabcollison[1]==0)  {
    if (bp->background.positionfromimage.x == 0 || bp->background.positionfromimage.x >= 2400)
      p->perso.positioninscrenn.x -= p->vitesse * p->dt;
    if (p->perso.positioninscrenn.x > 300 && p->perso.positioninscrenn.x < 310)
      bp->background.positionfromimage.x -= p->vitesse * p->dt;
}
    break;
  }
  if (bp->background.positionfromimage.x < 0)
    bp->background.positionfromimage.x = 0;
  if (bp->background.positionfromimage.x > 2400)
    bp->background.positionfromimage.x = 2400;
};

void saut(Personne *p, float dt, int possol, background *bp)
{
  if (p->up == 1)
  {

    switch (p->direction)
    {
    case 0:
      if(p->tabcollison[0]==0) {
      if (p->perso.positioninscrenn.x > 300)
        bp->background.positionfromimage.x += p->velocityX * dt;
      if (bp->background.positionfromimage.x == 0 || bp->background.positionfromimage.x > 2400)

        p->perso.positioninscrenn.x += p->velocityX * dt;
      }

      break;

    case 1:
     if(p->tabcollison[1]==0) {
      if (bp->background.positionfromimage.x == 0 || bp->background.positionfromimage.x >= 2400)
        p->perso.positioninscrenn.x += (-p->velocityX) * dt;
      if (p->perso.positioninscrenn.x > 300 && p->perso.positioninscrenn.x < 310)

        bp->background.positionfromimage.x += (-p->velocityX) * dt;
      break;
     }
    }
    p->perso.positioninscrenn.y += p->velocityY * dt;
    p->velocityY += p->groundY * dt;
  }
  if (p->tabcollison[3] ==1)
  {
    p->up = 0;

   }
};
void init(Personne *p, int numperso)
{
  p->up = 0;
  p->velocityX = 40;
  p->velocityY = -60;
  p->groundY = 40;
 
  p->perso.positionfromimage.x = 0;
  p->perso.positionfromimage.y = 0;
  p->perso.positionfromimage.h = 47;
  p->perso.positionfromimage.w = 30;
  p->perso.positioninscrenn.x = 286;
  p->perso.positioninscrenn.y = 555;
  p->direction = 0;
  p->deplacement = 0;
  p->vitesse = 0.5;
};




void initmap(minimap * m) {


m->minimap.image=IMG_Load("resourcesMinimap/images/minimap/minimap.png");
m->minimap.positioninscrenn.x=0;
m->minimap.positioninscrenn.y=0;


m->bonhomme.image=IMG_Load("resourcesMinimap/images/bonhomme/bonhomme.png");
m->bonhomme.positioninscrenn.x=10;
m->bonhomme.positioninscrenn.y=10;

m->animation.image=IMG_Load("resourcesMinimap/images/sprite sheet/animation.png");
m->animation.positioninscrenn.x=250;
m->animation.positioninscrenn.y=60;
m->animation.positionfromimage.x=0;
m->animation.positionfromimage.y=0;
m->animation.positionfromimage.h=47;
m->animation.positionfromimage.w=30;


TTF_Init(),
m->timestarted=0;
m->time.font=TTF_OpenFont("font.ttf",50);
m->time.color=(SDL_Color){255,255,255};
m->time.postext.x=0;
m->time.postext.y=0;

m->time.text= TTF_RenderText_Blended(m->time.font,"0",m->time.color);
};
void afficherminimap(minimap m,SDL_Surface *screen) {

SDL_BlitSurface(m.minimap.image,NULL,screen,&m.minimap.positioninscrenn);
SDL_BlitSurface(m.bonhomme.image,NULL,screen,&m.bonhomme.positioninscrenn);
SDL_BlitSurface(m.animation.image,&m.animation.positionfromimage,screen,&m.animation.positioninscrenn);

SDL_BlitSurface(m.time.text,NULL,screen,NULL);

};
void Liberer (minimap * m){
SDL_FreeSurface(m->minimap.image);
SDL_FreeSurface(m->bonhomme.image);
SDL_FreeSurface(m->animation.image);

};

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement){
SDL_Rect posJoueurABS;
posJoueurABS.x =posJoueur.x+camera.x;
posJoueurABS.y =posJoueur.y + camera.y;

m->bonhomme.positioninscrenn.x=posJoueurABS.x*redimensionnement/100;
m->bonhomme.positioninscrenn.y=posJoueurABS.y*redimensionnement/100;

};



void sauvgarder(Personne p,background b,char *nomfichier) {

FILE *file=fopen(nomfichier, "w");
fprintf(file,"%d:%d:%d:%d:%d:%d\n",b.background.positionfromimage.x,b.background.positionfromimage.y,b.stage
,p.perso.positioninscrenn.x,p.perso.positioninscrenn.y,p.direction


);
fclose(file);
};

void charger(Personne *p,background *b,char *nomfichier) {


FILE *file=fopen(nomfichier, "r");
fscanf(file,"%hd:%hd:%d:%hd:%hd:%d\n",&b->background.positionfromimage.x,&b->background.positionfromimage.y,&b->stage
,&p->perso.positioninscrenn.x,&p->perso.positioninscrenn.y,&p->direction


);
fclose(file);


};





SDL_Color  GetPixel(SDL_Surface *pSurface,int x,int y)

{
SDL_Color color;
Uint32 col=0;

char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);

SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color); 
}
int collisionPP(Personne *p, SDL_Surface *Masque,background bp) {
int persowidth=24;
int persoheght=39.4;
SDL_Color color ;
//-----right
int x=p->perso.positioninscrenn.x+persowidth+bp.background.positionfromimage.x;
int y=p->perso.positioninscrenn.y+persoheght/2+bp.background.positionfromimage.y;
color=GetPixel(Masque,x,y);
if(color.r==0&&color.g==0&&color.b==0) {
p->tabcollison[0]=1;
}else  {
p->tabcollison[0]=0;
}
//-----left
int x1=p->perso.positioninscrenn.x+bp.background.positionfromimage.x;
int y1=p->perso.positioninscrenn.y+persoheght/2+bp.background.positionfromimage.y;
color=GetPixel(Masque,x1,y1);
if(color.r==0&&color.g==0&&color.b==0) {
p->tabcollison[1]=1;
}else  {
p->tabcollison[1]=0;
};
//-----up
int x2=p->perso.positioninscrenn.x+bp.background.positionfromimage.x+persowidth/2;
int y2=p->perso.positioninscrenn.y+bp.background.positionfromimage.y;
color=GetPixel(Masque,x2,y2);
if(color.r==0&&color.g==0&&color.b==0) {
p->tabcollison[2]=1;
}else  {
p->tabcollison[2]=0;
};
//-----down
int x3=p->perso.positioninscrenn.x+bp.background.positionfromimage.x+persowidth/2;
int y3=p->perso.positioninscrenn.y+bp.background.positionfromimage.y+persoheght;
color=GetPixel(Masque,x3,y3);
if(color.r==0&&color.g==0&&color.b==0) {
p->tabcollison[3]=1;
}else  {
p->tabcollison[3]=0;
};
for (int i = 0; i < 4; i++)
{
printf("tab[%d]=%d\n",i,p->tabcollison[i]);
 }

}

void animerMinimap(minimap *m) {
if(m->animation.positionfromimage.x>m->animation.image->w-m->animation.positionfromimage.w){
m->animation.positionfromimage.x=0;

}else {

m->animation.positionfromimage.x+=m->animation.positionfromimage.w ;

}






};
void calculnewtime(minimap *m){
char time[12];
Uint32 timelapsed =SDL_GetTicks()-m->timestarted;
sprintf(time,"%d",timelapsed/1000);
m->time.text= TTF_RenderText_Blended(m->time.font,time,m->time.color);
}; 
