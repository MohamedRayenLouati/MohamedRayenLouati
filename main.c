#include"fenetre.h"
int main() {


SDL_Surface* screen ; 
background backgroundst;

int quitter;
SDL_Event event;
Personne p;
uint32_t tprev;
Uint32 t_prev;
int possol;
float dt;
minimap m;


 

SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
screen= SDL_SetVideoMode(600, 600, 32, SDL_RESIZABLE|SDL_HWSURFACE);
quitter=1;
possol=400;
init_background(&backgroundst.background);
init_maske(&backgroundst.masque);

initPerso(&p);
initmap(&m);
//charger(&p,&backgroundst,"save");
 

 

 
 
 
 
 
  

while(quitter){
t_prev=SDL_GetTicks();	
SDL_BlitSurface(backgroundst.background.image,&backgroundst.background.positionfromimage,screen,NULL);
afficherPerso(p,screen);
afficherminimap(m,screen);


SDL_PollEvent(&event);

switch(event.type){
  
  case SDL_QUIT:
  sauvgarder(p,backgroundst,"save");
  quitter=0;
  break;
  
  

  case SDL_KEYDOWN:
switch(event.key.keysym.sym) {


case SDLK_UP:

if(p.up==0){
p.up=1;
p.velocityX=0;
p.velocityY=-80; 
}
break;
case SDLK_RIGHT:
p.deplacement=1;
p.direction=0;
break;
case SDLK_LEFT:
p.deplacement=1;
p.direction=1;
break;
case SDLK_SPACE:
if(p.up==0){
p.up=1;
p.velocityX=60;
p.velocityY=-100; 
}
break;
}
break;



case SDL_KEYUP:
switch(event.key.keysym.sym) {
case SDLK_RIGHT:
p.deplacement=0;
break;
case SDLK_LEFT:
p.deplacement=0;
break;
}
break;


}


 
if(p.deplacement==1){
p.vitesse=0.5;
}else if(p.deplacement==0){
p.vitesse=0; 
}
if(p.up==0){
movePerso(&p,&backgroundst);
}

saut(&p,dt,possol,&backgroundst); 


MAJMinimap(p.perso.positioninscrenn,&m,backgroundst.background.positionfromimage,20);
collisionPP(&p,backgroundst.masque.image,backgroundst);
if(p.tabcollison[3]!=1) {
  p.perso.positioninscrenn.y+=1;
}
animerMinimap(&m);
calculnewtime(&m);
SDL_Flip(screen);
p.dt=SDL_GetTicks()-t_prev;	
dt=(SDL_GetTicks()-t_prev)/100.0;
}




SDL_FreeSurface(backgroundst.background.image);
Liberer(&m);
SDL_Quit();





}
