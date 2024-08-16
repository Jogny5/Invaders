#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <SDL2/SDL_mixer.h>


char comparar(char *puntaje,char *nuevoptj){			//funcion para comparar, pide puntaje 5(menor) y el nuevo
int i=0;
char auxx[10];
strcpy(auxx,nuevoptj); 

int q=(int)puntaje[0];									
int w=(int)puntaje[1];
int j=(int)puntaje[2];
int k=(int)puntaje[3];


int q2=(int)nuevoptj[0];								
int w2=(int)nuevoptj[1];
int j2=(int)nuevoptj[2];
int k2=(int)nuevoptj[3];


while(i==0){											//compara cada parte del numero de 4 digitos
	if(q2>q){	
		strcpy(nuevoptj,puntaje);						//si el primero es mayor el nuevo ocupa el lugar del ultimo
		strcpy(puntaje,auxx);

	}
	if(q2<q){
		i++;					//da otro valor que no altere el resto
	}
	if(q2==q){											//si es igual pasa al numero siguiente y los compara(1589,1324)
		if(w2>w){
			strcpy(nuevoptj,puntaje);
			strcpy(puntaje,auxx);
		}
		if(w2<w){
			i++;
		}
		if(w2==w){
			if(j2>j){
				strcpy(nuevoptj,puntaje);
				strcpy(puntaje,auxx);
			}
			if(j2<j){
				i++;
			}
			if(j2==j){
				if(k2>k){
					strcpy(nuevoptj,puntaje);
					strcpy(puntaje,auxx);
				}
				if(k2<k){
					i++;
				}
				if(k2==k){
					i++;
				}
			}
		}
	}
	i++;
}

}



//********************************************


char ordenar(char *punt1,char *punt2,char *punt3,char *punt4,char *punt5){

int p=0;
char rr[1]=("");

while(p==0){

	punt4[0,1,2,3,4]=comparar(punt4,punt5);

	punt3[0,1,2,3,4]=comparar(punt3,punt4);

	punt2[0,1,2,3,4]=comparar(punt2,punt3);

	punt1[0,1,2,3,4]=comparar(punt1,punt2);


	punt1[4]=rr[0];
	punt2[4]=rr[0];
	punt3[4]=rr[0];
	punt4[4]=rr[0];
	punt5[4]=rr[0];

	p++;
	}

}


//******************************************************************************************


SDL_Texture* LoadTexture(const char* filepath,SDL_Renderer* renderTarget)
{
	SDL_Texture* texture =NULL;
	SDL_Surface* surface =IMG_Load(filepath);
	texture =SDL_CreateTextureFromSurface(renderTarget,surface);
	SDL_FreeSurface(surface);

	return texture;
}

void render_text(SDL_Renderer *renderer, int x, int y,const char *text,TTF_Font *font,SDL_Rect *rect,SDL_Color *color) 
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, *color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    rect->x = x;
    rect->y = y;
    rect->w = surface->w;
    rect->h = surface->h;

    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_DestroyTexture(texture);
}



int main()
{

	int oof=0;

	do
	{
		TTF_Init();

		SDL_Window *window=NULL;

		SDL_Renderer *renderTarget =NULL;

		SDL_Init(SDL_INIT_EVERYTHING);

		Mix_OpenAudio(41000, MIX_DEFAULT_FORMAT, 2, 2048);

		Mix_Music *bgs = Mix_LoadMUS("invadersoundtrack.mp3");

		Mix_PlayMusic(bgs, -1);

		Mix_VolumeMusic(5);

		window =SDL_CreateWindow("Space Invaders",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								1280,
								720,
								SDL_WINDOW_OPENGL);

		renderTarget =SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		SDL_SetRenderDrawColor(renderTarget,0,0,0,0);


// crear texturas con imagen
		SDL_Texture *jugador =LoadTexture("player_n1.png",renderTarget);
		SDL_Texture *enemigo =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo2 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo3 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo4 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo5 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo6 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo11 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo12 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo14 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo15 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo16 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo13 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo21 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo22 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo23 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo24 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo25 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *enemigo26 =LoadTexture("enemy.png",renderTarget);
		SDL_Texture *vida3 =LoadTexture("life.png",renderTarget);
		SDL_Texture *vida2 =LoadTexture("life.png",renderTarget);
		SDL_Texture *vida1 =LoadTexture("life.png",renderTarget);
		SDL_Texture *misil=LoadTexture("bala.jpg",renderTarget);
		SDL_Texture *misilEnemigo=LoadTexture("bala.jpg",renderTarget);
		SDL_Texture *misil2Enemigo=LoadTexture("bala.jpg",renderTarget);
		SDL_Texture *misil3Enemigo=LoadTexture("bala.jpg",renderTarget);
		SDL_Texture *misil4Enemigo=LoadTexture("bala.jpg",renderTarget);
		SDL_Texture *misil5Enemigo=LoadTexture("bala.jpg",renderTarget);
		SDL_Texture *misil6Enemigo=LoadTexture("bala.jpg",renderTarget);

		SDL_Texture *base1=LoadTexture("escudo.png",renderTarget);
		SDL_Texture *base2=LoadTexture("escudo.png",renderTarget);
		SDL_Texture *base3=LoadTexture("escudo.png",renderTarget);
		SDL_Texture *base4=LoadTexture("escudo.png",renderTarget);

		SDL_Rect ba1;
		SDL_Rect ba2;
		SDL_Rect ba3;
		SDL_Rect ba4;

		int rein=0;

		SDL_QueryTexture(base1,NULL,NULL,&ba1.w,&ba1.h);
		
		ba1.w=120;
		ba1.h=50;

		ba1.x=114;
		ba1.y=450;

		SDL_QueryTexture(base2,NULL,NULL,&ba2.w,&ba2.h);

		ba2.w=120;
		ba2.h=50;

		ba2.x=454;
		ba2.y=450;
		
		SDL_QueryTexture(base3,NULL,NULL,&ba3.w,&ba3.h);

		ba3.w=120;
		ba3.h=50;

		ba3.x=722;
		ba3.y=450;
		
		SDL_QueryTexture(base4,NULL,NULL,&ba4.w,&ba4.h);

		ba4.w=120;
		ba4.h=50;

		ba4.x=1020;
		ba4.y=450;

		int contesc1=10, contesc2=10, contesc3=10, contesc4=10;

//crear rectangulos para las estructuras

		SDL_Rect rectTextura;					

		SDL_QueryTexture(jugador,NULL,NULL,&rectTextura.w,&rectTextura.h);
		rectTextura.w=90;
		rectTextura.h=80;

		float posicion_x=590;
		float posicion_y=575;

		SDL_Rect rectres;						

		SDL_QueryTexture(vida3,NULL,NULL,&rectres.w,&rectres.h);
			rectres.w=30;
			rectres.h=30;

			float pos3_x=100;
			float pos3_y=675;

		SDL_Rect recdos;

		SDL_QueryTexture(vida2,NULL,NULL,&recdos.w,&recdos.h);
			recdos.w=30;
			recdos.h=30;

			float pos2_x=135;
			float pos2_y=675;

			SDL_Rect recuno;

		SDL_QueryTexture(vida1,NULL,NULL,&recuno.w,&recuno.h);
			recuno.w=30;
			recuno.h=30;

			float pos1_x=170;
			float pos1_y=675;

	SDL_Rect recEnemigo;

		SDL_QueryTexture(enemigo,NULL,NULL,&recEnemigo.w,&recEnemigo.h);
			recEnemigo.w=80;
			recEnemigo.h=60;

			int posEnemigo_x=200;
			int posEnemigo_y=150;

	SDL_Rect recEnemigo2;

		SDL_QueryTexture(enemigo2,NULL,NULL,&recEnemigo2.w,&recEnemigo2.h);
			recEnemigo2.w=80;
			recEnemigo2.h=60;

			int posEnemigo2_x=110;
			int posEnemigo2_y=150;

	SDL_Rect recEnemigo3;

		SDL_QueryTexture(enemigo3,NULL,NULL,&recEnemigo3.w,&recEnemigo3.h);
			recEnemigo3.w=80;
			recEnemigo3.h=60;

			int posEnemigo3_x=290;
			int posEnemigo3_y=150;

	SDL_Rect recEnemigo4;

		SDL_QueryTexture(enemigo4,NULL,NULL,&recEnemigo4.w,&recEnemigo4.h);
			recEnemigo4.w=80;
			recEnemigo4.h=60;

			int posEnemigo4_x=380;
			int posEnemigo4_y=150;

	SDL_Rect recEnemigo5;

		SDL_QueryTexture(enemigo5,NULL,NULL,&recEnemigo5.w,&recEnemigo5.h);
			recEnemigo5.w=80;
			recEnemigo5.h=60;

			int posEnemigo5_x=470;
			int posEnemigo5_y=150;

	SDL_Rect recEnemigo6;

		SDL_QueryTexture(enemigo6,NULL,NULL,&recEnemigo6.w,&recEnemigo6.h);
			recEnemigo6.w=80;
			recEnemigo6.h=60;

			int posEnemigo6_x=560;
			int posEnemigo6_y=150;

	SDL_Rect recEnemigo11;

		SDL_QueryTexture(enemigo11,NULL,NULL,&recEnemigo11.w,&recEnemigo11.h);
			recEnemigo11.w=80;
			recEnemigo11.h=60;

			int posEnemigo11_x=200;
			int posEnemigo11_y=80;

	SDL_Rect recEnemigo12;

		SDL_QueryTexture(enemigo12,NULL,NULL,&recEnemigo12.w,&recEnemigo12.h);
			recEnemigo12.w=80;
			recEnemigo12.h=60;

			int posEnemigo12_x=110;
			int posEnemigo12_y=80;		

	SDL_Rect recEnemigo13;

		SDL_QueryTexture(enemigo13,NULL,NULL,&recEnemigo13.w,&recEnemigo13.h);
			recEnemigo13.w=80;
			recEnemigo13.h=60;

			int posEnemigo13_x=290;
			int posEnemigo13_y=80;


	SDL_Rect recEnemigo14;

		SDL_QueryTexture(enemigo14,NULL,NULL,&recEnemigo14.w,&recEnemigo14.h);
			recEnemigo14.w=80;
			recEnemigo14.h=60;

			int posEnemigo14_x=380;
			int posEnemigo14_y=80;

	SDL_Rect recEnemigo15;

		SDL_QueryTexture(enemigo15,NULL,NULL,&recEnemigo15.w,&recEnemigo15.h);
			recEnemigo15.w=80;
			recEnemigo15.h=60;

			int posEnemigo15_x=470;
			int posEnemigo15_y=80;		

	SDL_Rect recEnemigo16;

		SDL_QueryTexture(enemigo16,NULL,NULL,&recEnemigo16.w,&recEnemigo16.h);
			recEnemigo16.w=80;
			recEnemigo16.h=60;

			int posEnemigo16_x=560;
			int posEnemigo16_y=80;

	SDL_Rect recEnemigo21;

		SDL_QueryTexture(enemigo11,NULL,NULL,&recEnemigo21.w,&recEnemigo21.h);
			recEnemigo21.w=80;
			recEnemigo21.h=60;

			int posEnemigo21_x=200;
			int posEnemigo21_y=10;

	SDL_Rect recEnemigo22;

		SDL_QueryTexture(enemigo22,NULL,NULL,&recEnemigo22.w,&recEnemigo22.h);
			recEnemigo22.w=80;
			recEnemigo22.h=60;

			int posEnemigo22_x=110;
			int posEnemigo22_y=10;		

	SDL_Rect recEnemigo23;

		SDL_QueryTexture(enemigo23,NULL,NULL,&recEnemigo23.w,&recEnemigo23.h);
			recEnemigo23.w=80;
			recEnemigo23.h=60;

			int posEnemigo23_x=290;
			int posEnemigo23_y=10;


	SDL_Rect recEnemigo24;

		SDL_QueryTexture(enemigo24,NULL,NULL,&recEnemigo24.w,&recEnemigo24.h);
			recEnemigo24.w=80;
			recEnemigo24.h=60;

			int posEnemigo24_x=380;
			int posEnemigo24_y=10;

	SDL_Rect recEnemigo25;

		SDL_QueryTexture(enemigo25,NULL,NULL,&recEnemigo25.w,&recEnemigo25.h);
			recEnemigo25.w=80;
			recEnemigo25.h=60;

			int posEnemigo25_x=470;
			int posEnemigo25_y=10;		

	SDL_Rect recEnemigo26;

		SDL_QueryTexture(enemigo26,NULL,NULL,&recEnemigo26.w,&recEnemigo26.h);
			recEnemigo26.w=80;
			recEnemigo26.h=60;

			int posEnemigo26_x=560;
			int posEnemigo26_y=10;		


		SDL_Color color={255,255,255,0};


//crea superficie con la fuente space invaders
		TTF_Font* font = TTF_OpenFont("space_invaders.ttf",20);
		SDL_Surface *puntj=TTF_RenderText_Solid(font, "SCORE",color);
		SDL_Texture *text=SDL_CreateTextureFromSurface(renderTarget,puntj);



		SDL_Surface *vidas=TTF_RenderText_Solid(font, "VIDAS  ",color);
		SDL_Texture *texturelv=SDL_CreateTextureFromSurface(renderTarget,vidas);


		SDL_Rect textrec;
		textrec.x=10;
		textrec.y=0;

		SDL_Rect reclives;
		reclives.x=10;
		reclives.y=680;

		int velocidad=20;
		const unsigned char *tecla;
		tecla=SDL_GetKeyboardState(NULL);
		int typeEvent;

		char buffer[10];

		char bufferptj1[10];
		char bufferptj2[10];
		char bufferptj3[10];
		char bufferptj4[10];
		char bufferptj5[10];

		int xd=0; //VARIABLE DE PUNTAJE

		int j=snprintf(buffer,10,"%d",xd);



		SDL_QueryTexture(text,NULL,NULL,&textrec.w,&textrec.h);
		SDL_QueryTexture(texturelv,NULL,NULL,&reclives.w,&reclives.h);


		SDL_FreeSurface(puntj);
		SDL_FreeSurface(vidas);


		SDL_Rect rectMisil;

		SDL_Rect puntaje;
		SDL_Rect puntaje1;
		SDL_Rect puntaje2;
		SDL_Rect puntaje3;
		SDL_Rect puntaje4;
		SDL_Rect puntaje5;
		
//dimensiones misil del jugador
		SDL_QueryTexture(misil,NULL,NULL,&rectMisil.w,&rectMisil.h);

		rectMisil.h=50;
		rectMisil.w=35;

		int posMisily = 0 , posMisilx = 0;

		int hayMisil=0;

//misil del enemigo 1
	SDL_Rect rectMisilEnemigo;

		SDL_QueryTexture(misilEnemigo,NULL,NULL,&rectMisilEnemigo.w,&rectMisilEnemigo.h);

		rectMisilEnemigo.h=50;
		rectMisilEnemigo.w=35;

		int posMisilEnemigoy = 0 , posMisilEnemigox = 0;

		int hayMisilEnemigo=0;

//misil del enemigo 2
	SDL_Rect rectMisil2Enemigo;

		SDL_QueryTexture(misil2Enemigo,NULL,NULL,&rectMisil2Enemigo.w,&rectMisil2Enemigo.h);

		rectMisil2Enemigo.h=50;
		rectMisil2Enemigo.w=35;

		int posMisil2Enemigoy = 0 , posMisil2Enemigox = 0;

		int hayMisil2Enemigo=0;

//misil del enemigo 3
	SDL_Rect rectMisil3Enemigo;

		SDL_QueryTexture(misil3Enemigo,NULL,NULL,&rectMisil3Enemigo.w,&rectMisil3Enemigo.h);

		rectMisil3Enemigo.h=50;
		rectMisil3Enemigo.w=35;

		int posMisil3Enemigoy = 0 , posMisil3Enemigox = 0;

		int hayMisil3Enemigo=0;

	SDL_Rect rectMisil4Enemigo;

		SDL_QueryTexture(misil4Enemigo,NULL,NULL,&rectMisil4Enemigo.w,&rectMisil4Enemigo.h);

		rectMisil4Enemigo.h=50;
		rectMisil4Enemigo.w=35;

		int posMisil4Enemigoy = 0 , posMisil4Enemigox = 0;

		int hayMisil4Enemigo=0;
		
	SDL_Rect rectMisil5Enemigo;

		SDL_QueryTexture(misil5Enemigo,NULL,NULL,&rectMisil5Enemigo.w,&rectMisil5Enemigo.h);

		rectMisil5Enemigo.h=50;
		rectMisil5Enemigo.w=35;

		int posMisil5Enemigoy = 0 , posMisil5Enemigox = 0;

		int hayMisil5Enemigo=0;
		
	SDL_Rect rectMisil6Enemigo;

		SDL_QueryTexture(misil6Enemigo,NULL,NULL,&rectMisil6Enemigo.w,&rectMisil6Enemigo.h);

		rectMisil6Enemigo.h=50;
		rectMisil6Enemigo.w=35;

		int posMisil6Enemigoy = 0 , posMisil6Enemigox = 0;

		int hayMisil6Enemigo=0;			

		int contador11=0;
		int contador12=0;
		int contador13=0;
		int contador14=0;
		int contador15=0;
		int contador16=0;

		int contador21=0;
		int contador22=0;
		int contador23=0;
		int contador24=0;
		int contador25=0;
		int contador26=0;

		int velocidadinv=2;


		int cerrarjuego=0;
		int cont=0,contadormuertes=0,v=0;//contador muertes vidas jugador
		while(!cerrarjuego){
			SDL_Event event;
			
			if(SDL_PollEvent(&event))
	        {
	            typeEvent = event.type;

	            if(typeEvent == SDL_QUIT)
	            {
	                cerrarjuego = 1;
	                oof=1;
	            }


	            else if(typeEvent==SDL_KEYDOWN)
	            {
	                if(tecla[SDL_SCANCODE_A])
	                {
	                    posicion_x-=velocidad;
	                }

	                if(tecla[SDL_SCANCODE_D])
	                {
	                    posicion_x+=velocidad;
	                }

	                if(tecla[SDL_SCANCODE_SPACE])
	                {
	                    if(hayMisil==0)
	                    {
	                    	hayMisil=1;
	                    	

	                    }	                    
	                }
	            }
	        }




	        //disparo del enemigo1, dispara cada 250 espacios
	        if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisilEnemigo==0){
	        	hayMisilEnemigo=1;
	        	if(hayMisilEnemigo==1)					//empieza el mov del misil
	       		{
	       			hayMisilEnemigo=2;

	       			posMisilEnemigoy=posEnemigo_y+60;
	       			posMisilEnemigox=posEnemigo_x+15;

	       			rectMisilEnemigo.y = posMisilEnemigoy;			//actualiza posicion
	        		rectMisilEnemigo.x = posMisilEnemigox;
	            
	            	SDL_RenderCopy(renderTarget,misilEnemigo,NULL,&rectMisilEnemigo);
	       		}
	        }
	        if(contador11==1 && contador21==0){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisilEnemigo==0){
	        	hayMisilEnemigo=1;
	        	if(hayMisilEnemigo==1)					//empieza el mov del misil
	       		{
	       			hayMisilEnemigo=2;

	       			posMisilEnemigoy=posEnemigo11_y+60;
	       			posMisilEnemigox=posEnemigo11_x+15;

	       			rectMisilEnemigo.y = posMisilEnemigoy;			//actualiza posicion
	        		rectMisilEnemigo.x = posMisilEnemigox;
	            
	            	SDL_RenderCopy(renderTarget,misilEnemigo,NULL,&rectMisilEnemigo);
	       		}
	        }
	        }
	        if(contador11==1 && contador21==1){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisilEnemigo==0){
	        	hayMisilEnemigo=1;
	        	if(hayMisilEnemigo==1)					//empieza el mov del misil
	       		{
	       			hayMisilEnemigo=2;

	       			posMisilEnemigoy=posEnemigo21_y+60;
	       			posMisilEnemigox=posEnemigo21_x+15;

	       			rectMisilEnemigo.y = posMisilEnemigoy;			//actualiza posicion
	        		rectMisilEnemigo.x = posMisilEnemigox;
	            
	            	SDL_RenderCopy(renderTarget,misilEnemigo,NULL,&rectMisilEnemigo);
	       		}
	        }
	        }


	        //disparo del enemigo2, dispara 250 espacios, +150 para que no dispare en la misma posicion que el enemigo1
	        if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil2Enemigo==0){
	        	hayMisil2Enemigo=1;
	        	if(hayMisil2Enemigo==1)
	       		{
	       			hayMisil2Enemigo=2;

	       			posMisil2Enemigoy=posEnemigo2_y+60;
	       			posMisil2Enemigox=posEnemigo2_x+15;

	       			rectMisil2Enemigo.y = posMisil2Enemigoy;
	        		rectMisil2Enemigo.x = posMisil2Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil2Enemigo,NULL,&rectMisil2Enemigo);
	       		}
	        }
	        if(contador12==1 && contador22==0){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil2Enemigo==0){
	        	hayMisil2Enemigo=1;
	        	if(hayMisil2Enemigo==1)
	       		{
	       			hayMisil2Enemigo=2;

	       			posMisil2Enemigoy=posEnemigo12_y+60;
	       			posMisil2Enemigox=posEnemigo12_x+15;

	       			rectMisil2Enemigo.y = posMisil2Enemigoy;
	        		rectMisil2Enemigo.x = posMisil2Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil2Enemigo,NULL,&rectMisil2Enemigo);
	       		}
	        }
	        }
	        if(contador12==1 && contador22==1){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil2Enemigo==0){
	        	hayMisil2Enemigo=1;
	        	if(hayMisil2Enemigo==1)
	       		{
	       			hayMisil2Enemigo=2;

	       			posMisil2Enemigoy=posEnemigo22_y+60;
	       			posMisil2Enemigox=posEnemigo22_x+15;

	       			rectMisil2Enemigo.y = posMisil2Enemigoy;
	        		rectMisil2Enemigo.x = posMisil2Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil2Enemigo,NULL,&rectMisil2Enemigo);
	       		}
	        }
	        }


	        //disparo del enemigo3, dispara 250 espacios, +300 para que no dispare en la misma posicion que el enemigo1 y 2
	        if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil3Enemigo==0){
	        	hayMisil3Enemigo=1;
	        	if(hayMisil3Enemigo==1)
	       		{
	       			hayMisil3Enemigo=2;

	       			posMisil3Enemigoy=posEnemigo3_y+60;
	       			posMisil3Enemigox=posEnemigo3_x+15;

	       			rectMisil3Enemigo.y = posMisil3Enemigoy;
	        		rectMisil3Enemigo.x = posMisil3Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil3Enemigo,NULL,&rectMisil3Enemigo);
	       		}
	        }
	        if(contador13==1 && contador23==0){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil3Enemigo==0){
	        	hayMisil3Enemigo=1;
	        	if(hayMisil3Enemigo==1)
	       		{
	       			hayMisil3Enemigo=2;

	       			posMisil3Enemigoy=posEnemigo13_y+60;
	       			posMisil3Enemigox=posEnemigo13_x+15;

	       			rectMisil3Enemigo.y = posMisil3Enemigoy;
	        		rectMisil3Enemigo.x = posMisil3Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil3Enemigo,NULL,&rectMisil3Enemigo);
	       		}
	        }
	        }
	        if(contador13==1 && contador23==1){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil3Enemigo==0){
	        	hayMisil3Enemigo=1;
	        	if(hayMisil3Enemigo==1)
	       		{
	       			hayMisil3Enemigo=2;

	       			posMisil3Enemigoy=posEnemigo23_y+60;
	       			posMisil3Enemigox=posEnemigo23_x+15;

	       			rectMisil3Enemigo.y = posMisil3Enemigoy;
	        		rectMisil3Enemigo.x = posMisil3Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil3Enemigo,NULL,&rectMisil3Enemigo);
	       		}
	        }
	        }


	        if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil4Enemigo==0){
	        	hayMisil4Enemigo=1;
	        	if(hayMisil4Enemigo==1)					//empieza el mov del misil
	       		{
	       			hayMisil4Enemigo=2;

	       			posMisil4Enemigoy=posEnemigo4_y+60;
	       			posMisil4Enemigox=posEnemigo4_x+15;

	       			rectMisil4Enemigo.y = posMisil4Enemigoy;			//actualiza posicion
	        		rectMisil4Enemigo.x = posMisil4Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil4Enemigo,NULL,&rectMisil4Enemigo);
	       		}
	        }
	        if(contador14==1 && contador24==0){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil4Enemigo==0){
	        	hayMisil4Enemigo=1;
	        	if(hayMisil4Enemigo==1)					//empieza el mov del misil
	       		{
	       			hayMisil4Enemigo=2;

	       			posMisil4Enemigoy=posEnemigo14_y+60;
	       			posMisil4Enemigox=posEnemigo14_x+15;

	       			rectMisil4Enemigo.y = posMisil4Enemigoy;			//actualiza posicion
	        		rectMisil4Enemigo.x = posMisil4Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil4Enemigo,NULL,&rectMisil4Enemigo);
	       		}
	        }
	        }
	        if(contador14==1 && contador24==1){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil4Enemigo==0){
	        	hayMisil4Enemigo=1;
	        	if(hayMisil4Enemigo==1)					//empieza el mov del misil
	       		{
	       			hayMisil4Enemigo=2;

	       			posMisil4Enemigoy=posEnemigo24_y+60;
	       			posMisil4Enemigox=posEnemigo24_x+15;

	       			rectMisil4Enemigo.y = posMisil4Enemigoy;			//actualiza posicion
	        		rectMisil4Enemigo.x = posMisil4Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil4Enemigo,NULL,&rectMisil4Enemigo);
	       		}
	        }
	        }


	        if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil5Enemigo==0){
	        	hayMisil5Enemigo=1;
	        	if(hayMisil5Enemigo==1)
	       		{
	       			hayMisil5Enemigo=2;

	       			posMisil5Enemigoy=posEnemigo5_y+60;
	       			posMisil5Enemigox=posEnemigo5_x+15;

	       			rectMisil5Enemigo.y = posMisil5Enemigoy;
	        		rectMisil5Enemigo.x = posMisil5Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil5Enemigo,NULL,&rectMisil5Enemigo);
	       		}
	        }
	        if(contador15==1 && contador25==0){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil5Enemigo==0){
	        	hayMisil5Enemigo=1;
	        	if(hayMisil5Enemigo==1)
	       		{
	       			hayMisil5Enemigo=2;

	       			posMisil5Enemigoy=posEnemigo15_y+60;
	       			posMisil5Enemigox=posEnemigo15_x+15;

	       			rectMisil5Enemigo.y = posMisil5Enemigoy;
	        		rectMisil5Enemigo.x = posMisil5Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil5Enemigo,NULL,&rectMisil5Enemigo);
	       		}
	        }
	        }
	        if(contador15==1 && contador25==1){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil5Enemigo==0){
	        	hayMisil5Enemigo=1;
	        	if(hayMisil5Enemigo==1)
	       		{
	       			hayMisil5Enemigo=2;

	       			posMisil5Enemigoy=posEnemigo25_y+60;
	       			posMisil5Enemigox=posEnemigo25_x+15;

	       			rectMisil5Enemigo.y = posMisil5Enemigoy;
	        		rectMisil5Enemigo.x = posMisil5Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil5Enemigo,NULL,&rectMisil5Enemigo);
	       		}
	        }
	        }


	        if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil6Enemigo==0){
	        	hayMisil6Enemigo=1;
	        	if(hayMisil6Enemigo==1)
	       		{
	       			hayMisil6Enemigo=2;

	       			posMisil6Enemigoy=posEnemigo6_y+60;
	       			posMisil6Enemigox=posEnemigo6_x+15;

	       			rectMisil6Enemigo.y = posMisil6Enemigoy;
	        		rectMisil6Enemigo.x = posMisil6Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil6Enemigo,NULL,&rectMisil6Enemigo);
	       		}
	        }
	        if(contador16==1 && contador26==0){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil6Enemigo==0){
	        	hayMisil6Enemigo=1;
	        	if(hayMisil6Enemigo==1)
	       		{
	       			hayMisil6Enemigo=2;

	       			posMisil6Enemigoy=posEnemigo16_y+60;
	       			posMisil6Enemigox=posEnemigo16_x+15;

	       			rectMisil6Enemigo.y = posMisil6Enemigoy;
	        		rectMisil6Enemigo.x = posMisil6Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil6Enemigo,NULL,&rectMisil6Enemigo);
	       		}
	        }
	        }
	        if(contador16==1 && contador26==1){
	        	if((rand() % (1000 + 1 - 0) + 0)%150==0 && hayMisil6Enemigo==0){
	        	hayMisil6Enemigo=1;
	        	if(hayMisil6Enemigo==1)
	       		{
	       			hayMisil6Enemigo=2;

	       			posMisil6Enemigoy=posEnemigo26_y+60;
	       			posMisil6Enemigox=posEnemigo26_x+15;

	       			rectMisil6Enemigo.y = posMisil6Enemigoy;
	        		rectMisil6Enemigo.x = posMisil6Enemigox;
	            
	            	SDL_RenderCopy(renderTarget,misil6Enemigo,NULL,&rectMisil6Enemigo);
	       		}
	        }
	        }






	        if(hayMisilEnemigo==2)					//cuando el misil ya es disparado
	       	{
	       		posMisilEnemigoy+=5;				//el misil se mueve 5 espacios hacia abajo				
	       		SDL_RenderCopy(renderTarget,misilEnemigo,NULL,&rectMisilEnemigo);

	            if(posicion_x-35<=posMisilEnemigox && posicion_x+90>=posMisilEnemigox && posicion_y<=posMisilEnemigoy && posicion_y+120>=posMisilEnemigoy){
	       							//misil entre la posicion mas a la izq del jugador y la posicion mas a la derecha(posicion mas el ancho)+90
	            					//misil entre la posicion mas a la arriba del jugador y la posicion mas abajo(posicion mas el alto)+120

	       				contadormuertes++;							//colision, si el misil y jugador 
	            		switch(contadormuertes){					//resta vidas
	            			case 1:									//si hay colision el contador aumenta y segun el caso saca la imagen de la vida
	            			pos3_x=-50;
	       					pos3_y=-50;
	       					break;
	       					case 2:
	       					pos2_y=-50;
	       					pos2_x=-50;
	       					break;
	       					case 3:
	       					pos1_x=-50;
	       					pos1_y=-50;
	       					break;

	            		}    				
	       				hayMisilEnemigo=0;    			
	       			}	       	 	

	       		if(posMisilEnemigoy>1200)			//limite del misil abajo, si llega a 1200 se termina el proceso de mov del misil
	       		{

	       			hayMisilEnemigo=0;
	       		}
	       	}
	       	if(hayMisil2Enemigo==2)					//lo mismo pero con el misil del enemigo 2, los 3 usan variables distintas para su ejecucion
	       	{
	       		posMisil2Enemigoy+=5;
	       		SDL_RenderCopy(renderTarget,misil2Enemigo,NULL,&rectMisil2Enemigo);

	            if(posicion_x-35<=posMisil2Enemigox && posicion_x+90>=posMisil2Enemigox && posicion_y<=posMisil2Enemigoy && posicion_y+120>=posMisil2Enemigoy){
	       				contadormuertes++;
	            		switch(contadormuertes){
	            			case 1:
	            			pos3_x=-50;
	       					pos3_y=-50;
	       					break;
	       					case 2:
	       					pos2_y=-50;
	       					pos2_x=-50;
	       					break;
	       					case 3:
	       					pos1_x=-50;
	       					pos1_y=-50;
	       					break;

	            		}    				
	       				hayMisil2Enemigo=0;
	       			
	       			}
	       	 	

	       		if(posMisil2Enemigoy>1200)
	       		{

	       			hayMisil2Enemigo=0;
	       		}
	       	}
	       	if(hayMisil3Enemigo==2)							//x3
	       	{
	       		posMisil3Enemigoy+=5;
	       		SDL_RenderCopy(renderTarget,misil3Enemigo,NULL,&rectMisil3Enemigo);

	            if(posicion_x-35<=posMisil3Enemigox && posicion_x+90>=posMisil3Enemigox && posicion_y<=posMisil3Enemigoy && posicion_y+120>=posMisil3Enemigoy){
	       				contadormuertes++;
	            		switch(contadormuertes){
	            			case 1:
	            			pos3_x=-50;
	       					pos3_y=-50;
	       					break;
	       					case 2:
	       					pos2_y=-50;
	       					pos2_x=-50;
	       					break;
	       					case 3:
	       					pos1_x=-50;
	       					pos1_y=-50;
	       					break;

	            		}    				
	       				hayMisil3Enemigo=0;
	       			
	       			}
	       	 	

	       		if(posMisil3Enemigoy>1200)
	       		{

	       			hayMisil3Enemigo=0;
	       		}
	       	}
	       	if(hayMisil4Enemigo==2)					//lo mismo pero con el misil del enemigo 2, los 3 usan variables distintas para su ejecucion
	       	{
	       		posMisil4Enemigoy+=5;
	       		SDL_RenderCopy(renderTarget,misil4Enemigo,NULL,&rectMisil4Enemigo);

	            if(posicion_x-35<=posMisil4Enemigox && posicion_x+90>=posMisil4Enemigox && posicion_y<=posMisil4Enemigoy && posicion_y+120>=posMisil4Enemigoy){
	       				contadormuertes++;
	            		switch(contadormuertes){
	            			case 1:
	            			pos3_x=-50;
	       					pos3_y=-50;
	       					break;
	       					case 2:
	       					pos2_y=-50;
	       					pos2_x=-50;
	       					break;
	       					case 3:
	       					pos1_x=-50;
	       					pos1_y=-50;
	       					break;

	            		}    				
	       				hayMisil4Enemigo=0;
	       			
	       			}
	       	 	

	       		if(posMisil4Enemigoy>1200)
	       		{

	       			hayMisil4Enemigo=0;
	       		}
	       	}
	       	if(hayMisil5Enemigo==2)					//lo mismo pero con el misil del enemigo 2, los 3 usan variables distintas para su ejecucion
	       	{
	       		posMisil5Enemigoy+=5;
	       		SDL_RenderCopy(renderTarget,misil5Enemigo,NULL,&rectMisil5Enemigo);

	            if(posicion_x-35<=posMisil5Enemigox && posicion_x+90>=posMisil5Enemigox && posicion_y<=posMisil5Enemigoy && posicion_y+120>=posMisil5Enemigoy){
	       				contadormuertes++;
	            		switch(contadormuertes){
	            			case 1:
	            			pos3_x=-50;
	       					pos3_y=-50;
	       					break;
	       					case 2:
	       					pos2_y=-50;
	       					pos2_x=-50;
	       					break;
	       					case 3:
	       					pos1_x=-50;
	       					pos1_y=-50;
	       					break;

	            		}    				
	       				hayMisil5Enemigo=0;
	       			}
	       	 	
	       		if(posMisil5Enemigoy>1200)
	       		{

	       			hayMisil5Enemigo=0;
	       		}
	       	}
	       	if(hayMisil6Enemigo==2)					//lo mismo pero con el misil del enemigo 2, los 3 usan variables distintas para su ejecucion
	       	{
	       		posMisil6Enemigoy+=5;
	       		SDL_RenderCopy(renderTarget,misil6Enemigo,NULL,&rectMisil6Enemigo);

	            if(posicion_x-35<=posMisil6Enemigox && posicion_x+90>=posMisil6Enemigox && posicion_y<=posMisil6Enemigoy && posicion_y+120>=posMisil6Enemigoy){
	       				contadormuertes++;
	            		switch(contadormuertes){
	            			case 1:
	            			pos3_x=-50;
	       					pos3_y=-50;
	       					break;
	       					case 2:
	       					pos2_y=-50;
	       					pos2_x=-50;
	       					break;
	       					case 3:
	       					pos1_x=-50;
	       					pos1_y=-50;
	       					break;

	            		}    				
	       				hayMisil6Enemigo=0;	       			
	       			}
	       	 	

	       		if(posMisil6Enemigoy>1200)
	       		{
	       			hayMisil6Enemigo=0;
	       		}
	       	}
			
      
	        int j=snprintf(buffer,10,"%d",xd);

	        render_text(renderTarget,25,35,buffer,font,&puntaje,&color);








//movimiento del misil del jugador

	       	if(hayMisil==1)			//inicia el mov del misil con el SPACE
	       	{
	       		hayMisil=2;

	       		posMisily=500;
	       		posMisilx=posicion_x+25;

	       		rectMisil.y = posMisily;				//actualiza posicion
	        	rectMisil.x = posMisilx;
	            
	            SDL_RenderCopy(renderTarget,misil,NULL,&rectMisil);

	       	}

	       	if(hayMisil==2)
	       	{
	       		posMisily-=5;											//el misil se mueve cada 5 espacios hacia arriba
	       		SDL_RenderCopy(renderTarget,misil,NULL,&rectMisil);

	            if(posEnemigo_x-5<=posMisilx && posEnemigo_x+60>=posMisilx && posEnemigo_y-10<=posMisily && posEnemigo_y+60>=posMisily){
	       				posEnemigo_x=-100;		//colision misil con enemigo1
	       				posEnemigo_y=-100;		//si colisiona mueve al enemigo fuera de la pantalla y finaliza la ejecucion del misil
	       				hayMisil=0;
	       				xd+=100;				//puntaje
	       				contador11++;				
	       			}
	       		if(posEnemigo2_x-5<=posMisilx && posEnemigo2_x+60>=posMisilx && posEnemigo2_y-10<=posMisily && posEnemigo2_y+60>=posMisily){
	       				posEnemigo2_x=-100;		//colision misil con enemigo2
	       				posEnemigo2_y=-100;
	       				hayMisil=0;
	       				xd+=100;
	       				contador12++;			
	       			}
	       		if(posEnemigo3_x-5<=posMisilx && posEnemigo3_x+60>=posMisilx && posEnemigo3_y-10<=posMisily && posEnemigo3_y+60>=posMisily){
	       				posEnemigo3_x=-100;		//colision misil con enemigo3
	       				posEnemigo3_y=-100;
	       				hayMisil=0;
	       				xd+=100;
	       				contador13++;
	       			}
	       		if(posEnemigo4_x-5<=posMisilx && posEnemigo4_x+60>=posMisilx && posEnemigo4_y-10<=posMisily && posEnemigo4_y+60>=posMisily){
	       				posEnemigo4_x=-100;		//colision misil con enemigo3
	       				posEnemigo4_y=-100;
	       				hayMisil=0;
	       				xd+=100;
	       				contador14++;
	       			}	
	       		if(posEnemigo5_x-5<=posMisilx && posEnemigo5_x+60>=posMisilx && posEnemigo5_y-10<=posMisily && posEnemigo5_y+60>=posMisily){
	       				posEnemigo5_x=-100;		//colision misil con enemigo3
	       				posEnemigo5_y=-100;
	       				hayMisil=0;
	       				xd+=100;
	       				contador15++;
	       			}	
	       		if(posEnemigo6_x-5<=posMisilx && posEnemigo6_x+60>=posMisilx && posEnemigo6_y-10<=posMisily && posEnemigo6_y+60>=posMisily){
	       				posEnemigo6_x=-100;		//colision misil con enemigo3
	       				posEnemigo6_y=-100;
	       				hayMisil=0;
	       				xd+=100;
	       				contador16++;
	       			}
	       		if(posEnemigo11_x-5<=posMisilx && posEnemigo11_x+60>=posMisilx && posEnemigo11_y-10<=posMisily && posEnemigo11_y+60>=posMisily){
	       				posEnemigo11_x=-100;		
	       				posEnemigo11_y=-100;		
	       				hayMisil=0;
	       				xd+=200;
	       				contador21++;			
	       			}
	       		if(posEnemigo12_x-5<=posMisilx && posEnemigo12_x+60>=posMisilx && posEnemigo12_y-10<=posMisily && posEnemigo12_y+60>=posMisily){
	       				posEnemigo12_x=-100;		
	       				posEnemigo12_y=-100;
	       				hayMisil=0;
	       				xd+=200;
	       				contador22++;			
	       			}
	       		if(posEnemigo13_x-5<=posMisilx && posEnemigo13_x+60>=posMisilx && posEnemigo13_y-10<=posMisily && posEnemigo13_y+60>=posMisily){
	       				posEnemigo13_x=-100;	
	       				posEnemigo13_y=-100;
	       				hayMisil=0;
	       				xd+=200;
	       				contador23++;
	       			}
	       		if(posEnemigo14_x-5<=posMisilx && posEnemigo14_x+60>=posMisilx && posEnemigo14_y-10<=posMisily && posEnemigo14_y+60>=posMisily){
	       				posEnemigo14_x=-100;	
	       				posEnemigo14_y=-100;
	       				hayMisil=0;
	       				xd+=200;
	       				contador24++;
	       			}	
	       		if(posEnemigo15_x-5<=posMisilx && posEnemigo15_x+60>=posMisilx && posEnemigo15_y-10<=posMisily && posEnemigo15_y+60>=posMisily){
	       				posEnemigo15_x=-100;		
	       				posEnemigo15_y=-100;
	       				hayMisil=0;
	       				xd+=200;
	       				contador25++;
	       			}	
	       		if(posEnemigo16_x-5<=posMisilx && posEnemigo16_x+60>=posMisilx && posEnemigo16_y-10<=posMisily && posEnemigo16_y+60>=posMisily){
	       				posEnemigo16_x=-100;	
	       				posEnemigo16_y=-100;
	       				hayMisil=0;
	       				xd+=200;
	       				contador26++;
	       			}
	       		if(posEnemigo21_x-5<=posMisilx && posEnemigo21_x+60>=posMisilx && posEnemigo21_y-10<=posMisily && posEnemigo21_y+60>=posMisily){
	       				posEnemigo21_x=-100;	
	       				posEnemigo21_y=-100;		
	       				hayMisil=0;
	       				xd+=300;				
	       			}
	       		if(posEnemigo22_x-5<=posMisilx && posEnemigo22_x+60>=posMisilx && posEnemigo22_y-10<=posMisily && posEnemigo22_y+60>=posMisily){
	       				posEnemigo22_x=-100;		
	       				posEnemigo22_y=-100;
	       				hayMisil=0;
	       				xd+=300;			
	       			}
	       		if(posEnemigo23_x-5<=posMisilx && posEnemigo23_x+60>=posMisilx && posEnemigo23_y-10<=posMisily && posEnemigo23_y+60>=posMisily){
	       				posEnemigo23_x=-100;	
	       				posEnemigo23_y=-100;
	       				hayMisil=0;
	       				xd+=300;
	       			}
	       		if(posEnemigo24_x-5<=posMisilx && posEnemigo24_x+60>=posMisilx && posEnemigo24_y-10<=posMisily && posEnemigo24_y+60>=posMisily){
	       				posEnemigo24_x=-100;		
	       				posEnemigo24_y=-100;
	       				hayMisil=0;
	       				xd+=300;
	       			}	
	       		if(posEnemigo25_x-5<=posMisilx && posEnemigo25_x+60>=posMisilx && posEnemigo25_y-10<=posMisily && posEnemigo25_y+60>=posMisily){
	       				posEnemigo25_x=-100;		
	       				posEnemigo25_y=-100;
	       				hayMisil=0;
	       				xd+=300;
	       			}	
	       		if(posEnemigo26_x-5<=posMisilx && posEnemigo26_x+60>=posMisilx && posEnemigo26_y-10<=posMisily && posEnemigo26_y+60>=posMisily){
	       				posEnemigo26_x=-100;	
	       				posEnemigo26_y=-100;
	       				hayMisil=0;
	       				xd+=300;
	       			}				

	       		if(posMisily<10)				//si el misil llega muy arriba detiene la ejecucion
	       		{

	       			hayMisil=0;
	       		}
	       	}

	       	int cxd = xd;

	       	while(cxd-3600>=0)
	       	{
	       		cxd-=3600;
	       	}

	       	if(cxd>=800 && cxd<1500){
	       		velocidadinv=3;
	       	}
	       	
	       	if(cxd>=1500){
	       		velocidadinv=5;
	       	}

	       



//mov invaders
//si y es para el invader se mueve a la derecha, si es impar se mueve a la izquerda

	       	if(posEnemigo_x>0 && posEnemigo_y>0 && posEnemigo_y<700){		//solo se aplica cuando estan en pantalla(x>0,y>0)
	       		if(posEnemigo_y%2==0 && posEnemigo_x<=700){				//se mueve a la derecha si el y es par, con tope x=1000
	       			posEnemigo_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo,NULL,&recEnemigo);
	       		}
	       		if(posEnemigo_y%2==0 && posEnemigo_x>=700 || posEnemigo_x<=200 && posEnemigo_y%2==1){
	       			//y es par x pasa el tope derecha o y es impar x pasa el tope izquierda

	       			posEnemigo_y+=9;									//avanza un numero impar para cambiar la direccion del mov						
	       			SDL_RenderCopy(renderTarget,enemigo,NULL,&recEnemigo);
	       			if(posEnemigo_x>=100){								//inicia el mov hacia la izq o derecha segun corresponda
	       				posEnemigo_x-=velocidadinv;
	       			}
	       			if(posEnemigo_x<=300){
	       				posEnemigo_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo_y%2==1){									//si y es impar se mueve a la izquierda
	       			posEnemigo_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo,NULL,&recEnemigo);
	        	}
	       	}

	       	//lo mismo para el invader 2
	       	if(posEnemigo2_x>0 && posEnemigo2_y>0 && posEnemigo2_y<700){	
	       		if(posEnemigo2_y%2==0 && posEnemigo2_x<=610){
	       			posEnemigo2_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo2,NULL,&recEnemigo2);
	       		}
	       		if(posEnemigo2_y%2==0 && posEnemigo2_x>=610 || posEnemigo2_x<=110 && posEnemigo2_y%2==1){
	       			posEnemigo2_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo2,NULL,&recEnemigo2);
	       			if(posEnemigo2_x>=100){
	       				posEnemigo2_x-=velocidadinv;
	       			}
	       			if(posEnemigo2_x<=300){
	       				posEnemigo2_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo2_y%2==1){
	       			posEnemigo2_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo2,NULL,&recEnemigo2);
	        	}
	       	}
	       	//lo mismo para el invader 3
	       	if(posEnemigo3_x>0 && posEnemigo3_y>0 && posEnemigo3_y<700){
	       		if(posEnemigo3_y%2==0 && posEnemigo3_x<=790){
	       			posEnemigo3_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo3,NULL,&recEnemigo3);
	       		}
	       		if(posEnemigo3_y%2==0 && posEnemigo3_x>=790 || posEnemigo3_x<=290 && posEnemigo3_y%2==1){
	       			posEnemigo3_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo3,NULL,&recEnemigo3);
	       			if(posEnemigo3_x>=100){
	       				posEnemigo3_x-=velocidadinv;
	       			}
	       			if(posEnemigo3_x<=400){						
	       				posEnemigo3_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo3_y%2==1){
	       			posEnemigo3_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo3,NULL,&recEnemigo3);
	        	}
	       	}
	       	if(posEnemigo4_x>0 && posEnemigo4_y>0 && posEnemigo4_y<700){
	       		if(posEnemigo4_y%2==0 && posEnemigo4_x<=880){
	       			posEnemigo4_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo4,NULL,&recEnemigo4);
	       		}
	       		if(posEnemigo4_y%2==0 && posEnemigo4_x>=880 || posEnemigo4_x<=380 && posEnemigo4_y%2==1){
	       			posEnemigo4_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo4,NULL,&recEnemigo4);
	       			if(posEnemigo4_x>=100){
	       				posEnemigo4_x-=velocidadinv;
	       			}
	       			if(posEnemigo4_x<=400){						
	       				posEnemigo4_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo4_y%2==1){
	       			posEnemigo4_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo4,NULL,&recEnemigo4);
	        	}
	       	}
	       	if(posEnemigo5_x>0 && posEnemigo5_y>0 && posEnemigo5_y<700){
	       		if(posEnemigo5_y%2==0 && posEnemigo5_x<=970){
	       			posEnemigo5_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo5,NULL,&recEnemigo5);
	       		}
	       		if(posEnemigo5_y%2==0 && posEnemigo5_x>=970 || posEnemigo5_x<=470 && posEnemigo5_y%2==1){
	       			posEnemigo5_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo5,NULL,&recEnemigo5);
	       			if(posEnemigo5_x>=100){
	       				posEnemigo5_x-=velocidadinv;
	       			}
	       			if(posEnemigo5_x<=500){						
	       				posEnemigo5_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo5_y%2==1){
	       			posEnemigo5_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo5,NULL,&recEnemigo5);
	        	}
	       	}
	       	if(posEnemigo6_x>0 && posEnemigo6_y>0 && posEnemigo6_y<700){
	       		if(posEnemigo6_y%2==0 && posEnemigo6_x<=1060){
	       			posEnemigo6_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo6,NULL,&recEnemigo6);
	       		}
	       		if(posEnemigo6_y%2==0 && posEnemigo6_x>=1060 || posEnemigo6_x<=560 && posEnemigo6_y%2==1){
	       			posEnemigo6_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo6,NULL,&recEnemigo6);
	       			if(posEnemigo6_x>=100){
	       				posEnemigo6_x-=velocidadinv;
	       			}
	       			if(posEnemigo6_x<=600){						
	       				posEnemigo6_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo6_y%2==1){
	       			posEnemigo6_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo6,NULL,&recEnemigo6);
	        	}
	       	}




	       	if(posEnemigo11_x>0 && posEnemigo11_y>0 && posEnemigo11_y<700){
	       		if(posEnemigo11_y%2==0 && posEnemigo11_x<=700){
	       			posEnemigo11_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo11,NULL,&recEnemigo11);
	       		}
	       		if(posEnemigo11_y%2==0 && posEnemigo11_x>=700 || posEnemigo11_x<=200 && posEnemigo11_y%2==1){
	       			posEnemigo11_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo11,NULL,&recEnemigo11);
	       			if(posEnemigo11_x>=100){
	       				posEnemigo11_x-=velocidadinv;
	       			}
	       			if(posEnemigo11_x<=300){						
	       				posEnemigo11_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo11_y%2==1){
	       			posEnemigo11_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo11,NULL,&recEnemigo11);
	        	}
	       	}
	       	if(posEnemigo12_x>0 && posEnemigo12_y>0 && posEnemigo12_y<700){	
	       		if(posEnemigo12_y%2==0 && posEnemigo12_x<=610){
	       			posEnemigo12_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo12,NULL,&recEnemigo12);
	       		}
	       		if(posEnemigo12_y%2==0 && posEnemigo12_x>=610 || posEnemigo12_x<=110 && posEnemigo12_y%2==1){
	       			posEnemigo12_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo12,NULL,&recEnemigo12);
	       			if(posEnemigo12_x>=100){
	       				posEnemigo12_x-=velocidadinv;
	       			}
	       			if(posEnemigo12_x<=300){
	       				posEnemigo12_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo12_y%2==1){
	       			posEnemigo12_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo12,NULL,&recEnemigo12);
	        	}
	       	}	       
	       	if(posEnemigo13_x>0 && posEnemigo13_y>0 && posEnemigo13_y<700){
	       		if(posEnemigo13_y%2==0 && posEnemigo13_x<=790){
	       			posEnemigo13_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo13,NULL,&recEnemigo13);
	       		}
	       		if(posEnemigo13_y%2==0 && posEnemigo13_x>=790 || posEnemigo13_x<=290 && posEnemigo13_y%2==1){
	       			posEnemigo13_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo13,NULL,&recEnemigo13);
	       			if(posEnemigo13_x>=100){
	       				posEnemigo13_x-=velocidadinv;
	       			}
	       			if(posEnemigo3_x<=400){						
	       				posEnemigo13_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo13_y%2==1){
	       			posEnemigo13_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo13,NULL,&recEnemigo13);
	        	}
	       	}
	       	if(posEnemigo14_x>0 && posEnemigo14_y>0 && posEnemigo14_y<700){
	       		if(posEnemigo14_y%2==0 && posEnemigo14_x<=880){
	       			posEnemigo14_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo14,NULL,&recEnemigo14);
	       		}
	       		if(posEnemigo14_y%2==0 && posEnemigo14_x>=880 || posEnemigo14_x<=380 && posEnemigo14_y%2==1){
	       			posEnemigo14_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo14,NULL,&recEnemigo14);
	       			if(posEnemigo14_x>=100){
	       				posEnemigo14_x-=velocidadinv;
	       			}
	       			if(posEnemigo14_x<=400){						
	       				posEnemigo14_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo14_y%2==1){
	       			posEnemigo14_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo14,NULL,&recEnemigo14);
	        	}
	       	}
	       	if(posEnemigo15_x>0 && posEnemigo15_y>0 && posEnemigo15_y<700){
	       		if(posEnemigo15_y%2==0 && posEnemigo15_x<=970){
	       			posEnemigo15_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo15,NULL,&recEnemigo15);
	       		}
	       		if(posEnemigo15_y%2==0 && posEnemigo15_x>=970 || posEnemigo15_x<=470 && posEnemigo15_y%2==1){
	       			posEnemigo15_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo15,NULL,&recEnemigo15);
	       			if(posEnemigo15_x>=100){
	       				posEnemigo15_x-=velocidadinv;
	       			}
	       			if(posEnemigo15_x<=500){						
	       				posEnemigo15_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo15_y%2==1){
	       			posEnemigo15_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo15,NULL,&recEnemigo15);
	        	}
	       	}
	       	if(posEnemigo16_x>0 && posEnemigo16_y>0 && posEnemigo16_y<700){
	       		if(posEnemigo16_y%2==0 && posEnemigo16_x<=1060){
	       			posEnemigo16_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo16,NULL,&recEnemigo16);
	       		}
	       		if(posEnemigo16_y%2==0 && posEnemigo16_x>=1060 || posEnemigo16_x<=560 && posEnemigo16_y%2==1){
	       			posEnemigo16_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo16,NULL,&recEnemigo16);
	       			if(posEnemigo16_x>=100){
	       				posEnemigo16_x-=velocidadinv;
	       			}
	       			if(posEnemigo16_x<=600){						
	       				posEnemigo16_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo16_y%2==1){
	       			posEnemigo16_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo16,NULL,&recEnemigo16);
	        	}
	       	}



	       	if(posEnemigo21_x>0 && posEnemigo21_y>0 && posEnemigo21_y<700){
	       		if(posEnemigo21_y%2==0 && posEnemigo21_x<=700){
	       			posEnemigo21_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo21,NULL,&recEnemigo21);
	       		}
	       		if(posEnemigo21_y%2==0 && posEnemigo21_x>=700 || posEnemigo21_x<=200 && posEnemigo21_y%2==1){
	       			posEnemigo21_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo21,NULL,&recEnemigo21);
	       			if(posEnemigo21_x>=100){
	       				posEnemigo21_x-=velocidadinv;
	       			}
	       			if(posEnemigo21_x<=300){						
	       				posEnemigo21_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo21_y%2==1){
	       			posEnemigo21_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo21,NULL,&recEnemigo21);
	        	}
	       	}
	       	if(posEnemigo22_x>0 && posEnemigo22_y>0 && posEnemigo22_y<700){	
	       		if(posEnemigo22_y%2==0 && posEnemigo22_x<=610){
	       			posEnemigo22_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo22,NULL,&recEnemigo22);
	       		}
	       		if(posEnemigo22_y%2==0 && posEnemigo22_x>=610 || posEnemigo22_x<=110 && posEnemigo22_y%2==1){
	       			posEnemigo22_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo22,NULL,&recEnemigo22);
	       			if(posEnemigo22_x>=100){
	       				posEnemigo22_x-=velocidadinv;
	       			}
	       			if(posEnemigo22_x<=300){
	       				posEnemigo22_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo22_y%2==1){
	       			posEnemigo22_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo22,NULL,&recEnemigo22);
	        	}
	       	}	       
	       	if(posEnemigo23_x>0 && posEnemigo23_y>0 && posEnemigo23_y<700){
	       		if(posEnemigo23_y%2==0 && posEnemigo23_x<=790){
	       			posEnemigo23_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo23,NULL,&recEnemigo23);
	       		}
	       		if(posEnemigo23_y%2==0 && posEnemigo23_x>=790 || posEnemigo23_x<=290 && posEnemigo23_y%2==1){
	       			posEnemigo23_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo23,NULL,&recEnemigo23);
	       			if(posEnemigo23_x>=100){
	       				posEnemigo23_x-=velocidadinv;
	       			}
	       			if(posEnemigo23_x<=400){						
	       				posEnemigo23_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo23_y%2==1){
	       			posEnemigo23_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo23,NULL,&recEnemigo23);
	        	}
	       	}
	       	if(posEnemigo24_x>0 && posEnemigo24_y>0 && posEnemigo24_y<700){
	       		if(posEnemigo24_y%2==0 && posEnemigo24_x<=880){
	       			posEnemigo24_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo24,NULL,&recEnemigo24);
	       		}
	       		if(posEnemigo24_y%2==0 && posEnemigo24_x>=880 || posEnemigo24_x<=380 && posEnemigo24_y%2==1){
	       			posEnemigo24_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo24,NULL,&recEnemigo24);
	       			if(posEnemigo24_x>=100){
	       				posEnemigo24_x-=velocidadinv;
	       			}
	       			if(posEnemigo24_x<=400){						
	       				posEnemigo24_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo24_y%2==1){
	       			posEnemigo24_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo24,NULL,&recEnemigo24);
	        	}
	       	}
	       	if(posEnemigo25_x>0 && posEnemigo25_y>0 && posEnemigo25_y<700){
	       		if(posEnemigo25_y%2==0 && posEnemigo25_x<=970){
	       			posEnemigo25_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo25,NULL,&recEnemigo25);
	       		}
	       		if(posEnemigo25_y%2==0 && posEnemigo25_x>=970 || posEnemigo25_x<=470 && posEnemigo25_y%2==1){
	       			posEnemigo25_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo25,NULL,&recEnemigo25);
	       			if(posEnemigo25_x>=100){
	       				posEnemigo25_x-=velocidadinv;
	       			}
	       			if(posEnemigo25_x<=500){						
	       				posEnemigo25_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo25_y%2==1){
	       			posEnemigo25_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo25,NULL,&recEnemigo25);
	        	}
	       	}
	       	if(posEnemigo26_x>0 && posEnemigo26_y>0 && posEnemigo26_y<700){
	       		if(posEnemigo26_y%2==0 && posEnemigo26_x<=1060){
	       			posEnemigo26_x+=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo26,NULL,&recEnemigo26);
	       		}
	       		if(posEnemigo26_y%2==0 && posEnemigo26_x>=1060 || posEnemigo26_x<=560 && posEnemigo26_y%2==1){
	       			posEnemigo26_y+=9;
	       			SDL_RenderCopy(renderTarget,enemigo26,NULL,&recEnemigo26);
	       			if(posEnemigo26_x>=100){
	       				posEnemigo26_x-=velocidadinv;
	       			}
	       			if(posEnemigo26_x<=600){						
	       				posEnemigo26_x+=velocidadinv;
	       			}
	       		}
	       		if(posEnemigo26_y%2==1){
	       			posEnemigo26_x-=velocidadinv;
	       			SDL_RenderCopy(renderTarget,enemigo26,NULL,&recEnemigo26);
	        	}
	       	}



	       	//If para que los disparos golpeen a los escudos 1

	       	if(rectMisil.y>=400 && rectMisil.y<=500 && rectMisil.x>=89 && rectMisil.x<=234 && hayMisil==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisil=0;
	
	       	}

	       	if(rectMisilEnemigo.y>=400 && rectMisilEnemigo.y<=500 && rectMisilEnemigo.x>=89 && rectMisilEnemigo.x<=234 && hayMisilEnemigo==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisilEnemigo=0;
	
	       	}

	       	if(rectMisil2Enemigo.y>=400 && rectMisil2Enemigo.y<=500 && rectMisil2Enemigo.x>=89 && rectMisil2Enemigo.x<=234 && hayMisil2Enemigo==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisil2Enemigo=0;
	
	       	}

	       	if(rectMisil3Enemigo.y>=400 && rectMisil3Enemigo.y<=500 && rectMisil3Enemigo.x>=89 && rectMisil3Enemigo.x<=234 && hayMisil3Enemigo==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisil3Enemigo=0;
	
	       	}

	       	if(rectMisil4Enemigo.y>=400 && rectMisil4Enemigo.y<=500 && rectMisil4Enemigo.x>=89 && rectMisil4Enemigo.x<=234 && hayMisil4Enemigo==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisil4Enemigo=0;
	
	       	}

	       	if(rectMisil5Enemigo.y>=400 && rectMisil5Enemigo.y<=500 && rectMisil5Enemigo.x>=89 && rectMisil5Enemigo.x<=234 && hayMisil5Enemigo==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisil5Enemigo=0;
	
	       	}

	       	if(rectMisil6Enemigo.y>=400 && rectMisil6Enemigo.y<=500 && rectMisil6Enemigo.x>=89 && rectMisil6Enemigo.x<=234 && hayMisil6Enemigo==2)
	       	{
	       		contesc1--;

	       		
	       		if(contesc1==0)
	       		{
	       		ba1.x=-200;
	       		ba1.y=-200;	
	       		}
	       		

	       		if(contesc1>0) hayMisil6Enemigo=0;
	
	       	}

	       	//If para que los disparos golpeen a los escudos 2

	       	if(rectMisil.y>=400 && rectMisil.y<=500 && rectMisil.x>=419&& rectMisil.x<=574 && hayMisil==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisil=0;
	
	       	}

	       	if(rectMisilEnemigo.y>=400 && rectMisilEnemigo.y<=500 && rectMisilEnemigo.x>=419&& rectMisil.x<=574 && hayMisilEnemigo==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisilEnemigo=0;
	
	       	}

	       	if(rectMisil2Enemigo.y>=400 && rectMisil2Enemigo.y<=500 && rectMisil2Enemigo.x>=419 && rectMisil2Enemigo.x<=574 && hayMisil2Enemigo==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisil2Enemigo=0;
	
	       	}

	       	if(rectMisil3Enemigo.y>=400 && rectMisil3Enemigo.y<=500 && rectMisil3Enemigo.x>=419 && rectMisil3Enemigo.x<=574 && hayMisil3Enemigo==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisil3Enemigo=0;
	
	       	}

	       	if(rectMisil4Enemigo.y>=400 && rectMisil4Enemigo.y<=500 && rectMisil4Enemigo.x>=419 && rectMisil4Enemigo.x<=574 && hayMisil4Enemigo==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisil4Enemigo=0;
	
	       	}

	       	if(rectMisil5Enemigo.y>=400 && rectMisil5Enemigo.y<=500 && rectMisil5Enemigo.x>=419 && rectMisil5Enemigo.x<=574 && hayMisil5Enemigo==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisil5Enemigo=0;
	
	       	}

	       	if(rectMisil6Enemigo.y>=400 && rectMisil6Enemigo.y<=500 && rectMisil6Enemigo.x>=419 && rectMisil6Enemigo.x<=574 && hayMisil6Enemigo==2)
	       	{
	       		contesc2--;

	       		
	       		if(contesc2==0)
	       		{
	       		ba2.x=-200;
	       		ba2.y=-200;	
	       		}
	       		

	       		if(contesc2>0) hayMisil6Enemigo=0;
	       	}

	       	//If para que los disparos golpeen a los escudos 3

	       	if(rectMisil.y>=400 && rectMisil.y<=500 && rectMisil.x>=687 && rectMisil.x<=842 && hayMisil==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisil=0;
	
	       	}

	       	if(rectMisilEnemigo.y>=400 && rectMisilEnemigo.y<=500 && rectMisilEnemigo.x>=687 && rectMisil.x<=842 && hayMisilEnemigo==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisilEnemigo=0;
	
	       	}

	       	if(rectMisil2Enemigo.y>=400 && rectMisil2Enemigo.y<=500 && rectMisil2Enemigo.x>=687 && rectMisil2Enemigo.x<=842 && hayMisil2Enemigo==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisil2Enemigo=0;
	       	}

	       	if(rectMisil3Enemigo.y>=400 && rectMisil3Enemigo.y<=500 && rectMisil3Enemigo.x>=687 && rectMisil3Enemigo.x<=842 && hayMisil3Enemigo==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisil3Enemigo=0;
	
	       	}

	       	if(rectMisil4Enemigo.y>=400 && rectMisil4Enemigo.y<=500 && rectMisil4Enemigo.x>=687 && rectMisil4Enemigo.x<=842 && hayMisil4Enemigo==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisil4Enemigo=0;
	
	       	}

	       	if(rectMisil5Enemigo.y>=400 && rectMisil5Enemigo.y<=500 && rectMisil5Enemigo.x>=687 && rectMisil5Enemigo.x<=842 && hayMisil5Enemigo==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisil5Enemigo=0;
	       	}

	       	if(rectMisil6Enemigo.y>=400 && rectMisil6Enemigo.y<=500 && rectMisil6Enemigo.x>=687 && rectMisil6Enemigo.x<=842 && hayMisil6Enemigo==2)
	       	{
	       		contesc3--;

	       		
	       		if(contesc3==0)
	       		{
	       		ba3.x=-200;
	       		ba3.y=-200;	
	       		}
	       		

	       		if(contesc3>0) hayMisil6Enemigo=0;
	       	}

	       	//If para que los disparos golpeen a los escudos 4

	       	if(rectMisil.y>=400 && rectMisil.y<=500 && rectMisil.x>=985&& rectMisil.x<=1140 && hayMisil==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisil=0;
	
	       	}

	       	if(rectMisilEnemigo.y>=400 && rectMisilEnemigo.y<=500 && rectMisilEnemigo.x>=985&& rectMisil.x<=1140 && hayMisilEnemigo==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisilEnemigo=0;
	
	       	}

	       	if(rectMisil2Enemigo.y>=400 && rectMisil2Enemigo.y<=500 && rectMisil2Enemigo.x>=985 && rectMisil2Enemigo.x<=1140 && hayMisil2Enemigo==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisil2Enemigo=0;
	
	       	}

	       	if(rectMisil3Enemigo.y>=400 && rectMisil3Enemigo.y<=500 && rectMisil3Enemigo.x>=985 && rectMisil3Enemigo.x<=1140 && hayMisil3Enemigo==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisil3Enemigo=0;
	
	       	}

	       	if(rectMisil4Enemigo.y>=400 && rectMisil4Enemigo.y<=500 && rectMisil4Enemigo.x>=985 && rectMisil4Enemigo.x<=1140 && hayMisil4Enemigo==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisil4Enemigo=0;
	
	       	}

	       	if(rectMisil5Enemigo.y>=400 && rectMisil5Enemigo.y<=500 && rectMisil5Enemigo.x>=985 && rectMisil5Enemigo.x<=1140 && hayMisil5Enemigo==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisil5Enemigo=0;
	
	       	}

	       	if(rectMisil6Enemigo.y>=400 && rectMisil6Enemigo.y<=500 && rectMisil6Enemigo.x>=985 && rectMisil6Enemigo.x<=1140 && hayMisil6Enemigo==2)
	       	{
	       		contesc4--;

	       		
	       		if(contesc4==0)
	       		{
	       		ba4.x=-200;
	       		ba4.y=-200;	
	       		}
	       		

	       		if(contesc4>0) hayMisil6Enemigo=0;
	       	}
		



	       	//actualizar todas las posiciones

	       	rectMisil.y = posMisily;
	        rectMisil.x = posMisilx;

	        rectMisilEnemigo.y = posMisilEnemigoy;
	        rectMisilEnemigo.x = posMisilEnemigox;

	        rectMisil2Enemigo.y = posMisil2Enemigoy;
	        rectMisil2Enemigo.x = posMisil2Enemigox;

	        rectMisil3Enemigo.y = posMisil3Enemigoy;
	        rectMisil3Enemigo.x = posMisil3Enemigox;

	        rectMisil4Enemigo.y = posMisil4Enemigoy;
	        rectMisil4Enemigo.x = posMisil4Enemigox;

	        rectMisil5Enemigo.y = posMisil5Enemigoy;
	        rectMisil5Enemigo.x = posMisil5Enemigox;

	        rectMisil6Enemigo.y = posMisil6Enemigoy;
	        rectMisil6Enemigo.x = posMisil6Enemigox;

	       	recEnemigo.y = posEnemigo_y;
	        recEnemigo.x = posEnemigo_x;

	        recEnemigo2.y = posEnemigo2_y;
	        recEnemigo2.x = posEnemigo2_x;

	        recEnemigo3.y = posEnemigo3_y;
	        recEnemigo3.x = posEnemigo3_x;

	        recEnemigo4.y = posEnemigo4_y;
	        recEnemigo4.x = posEnemigo4_x;

	        recEnemigo5.y = posEnemigo5_y;
	        recEnemigo5.x = posEnemigo5_x;

	        recEnemigo6.y = posEnemigo6_y;
	        recEnemigo6.x = posEnemigo6_x;

	        recEnemigo11.y = posEnemigo11_y;
	        recEnemigo11.x = posEnemigo11_x;

	        recEnemigo12.y = posEnemigo12_y;
	        recEnemigo12.x = posEnemigo12_x;

	        recEnemigo13.y = posEnemigo13_y;
	        recEnemigo13.x = posEnemigo13_x;

	        recEnemigo14.y = posEnemigo14_y;
	        recEnemigo14.x = posEnemigo14_x;

	        recEnemigo15.y = posEnemigo15_y;
	        recEnemigo15.x = posEnemigo15_x;

	        recEnemigo16.y = posEnemigo16_y;
	        recEnemigo16.x = posEnemigo16_x;

	        recEnemigo21.y = posEnemigo21_y;
	        recEnemigo21.x = posEnemigo21_x;

	        recEnemigo22.y = posEnemigo22_y;
	        recEnemigo22.x = posEnemigo22_x;

	        recEnemigo23.y = posEnemigo23_y;
	        recEnemigo23.x = posEnemigo23_x;

	        recEnemigo24.y = posEnemigo24_y;
	        recEnemigo24.x = posEnemigo24_x;

	        recEnemigo25.y = posEnemigo25_y;
	        recEnemigo25.x = posEnemigo25_x;

	        recEnemigo26.y = posEnemigo26_y;
	        recEnemigo26.x = posEnemigo26_x;

	        
	        if(xd%3600!=0)
	        {
	        	rein=1;
	        }


	        if(xd>0 && xd%3600==0 && rein==1)
	        {
	        	rein=0;
	           	
	        	velocidadinv=2;

	           	posEnemigo_x=200;
                posEnemigo_y=150;

                posEnemigo2_x=110;
                posEnemigo2_y=150;

                posEnemigo3_x=290;
                posEnemigo3_y=150;

                posEnemigo4_x=380;
                posEnemigo4_y=150;

                posEnemigo5_x=470;
                posEnemigo5_y=150;

                posEnemigo6_x=560;
                posEnemigo6_y=150;


                posEnemigo11_x=200;
                posEnemigo11_y=80;

                posEnemigo12_x=110;
                posEnemigo12_y=80;

                posEnemigo13_x=290;
                posEnemigo13_y=80;

                posEnemigo14_x=380;
                posEnemigo14_y=80;

                posEnemigo15_x=470;
                posEnemigo15_y=80;

                posEnemigo16_x=560;
                posEnemigo16_y=80;

                
                posEnemigo21_x=200;
                posEnemigo21_y=10;

                posEnemigo22_x=110;
                posEnemigo22_y=10;

                posEnemigo23_x=290;
                posEnemigo23_y=10;


                posEnemigo24_x=380;
                posEnemigo24_y=10;

                posEnemigo25_x=470;
                posEnemigo25_y=10;

                posEnemigo26_x=560;
                posEnemigo26_y=10;


                contador11=0;
				contador12=0;
				contador13=0;
				contador14=0;
				contador15=0;
				contador16=0;
				

				contador21=0;
				contador22=0;
				contador23=0;
				contador24=0;
				contador25=0;
				contador26=0;
	        }


			rectTextura.x= posicion_x;
			rectTextura.y= posicion_y;

			rectres.x= pos3_x;
			rectres.y= pos3_y;

			recdos.x= pos2_x;
			recdos.y= pos2_y;

			recuno.x= pos1_x;
			recuno.y= pos1_y;

			//Deteccion de colision para que no el tanque no que OOB 

	        if (posicion_x <= 110) posicion_x = 110;
	        if (posicion_x >= 1140 - rectTextura.w) posicion_x = 1140-rectTextura.w;


			SDL_RenderCopy(renderTarget,jugador,NULL,&rectTextura);
			SDL_RenderCopy(renderTarget,enemigo,NULL,&recEnemigo);
			SDL_RenderCopy(renderTarget,vida3,NULL,&rectres);
			SDL_RenderCopy(renderTarget,vida2,NULL,&recdos);
			SDL_RenderCopy(renderTarget,vida1,NULL,&recuno);
			SDL_RenderCopy(renderTarget,text,NULL,&textrec);
			
			SDL_RenderCopy(renderTarget,texturelv,NULL,&reclives);

			SDL_RenderCopy(renderTarget,base1,NULL,&ba1);
			SDL_RenderCopy(renderTarget,base2,NULL,&ba2);
			SDL_RenderCopy(renderTarget,base3,NULL,&ba3);
			SDL_RenderCopy(renderTarget,base4,NULL,&ba4);


			SDL_RenderPresent(renderTarget); //Actualiza la pantalla con todos los cambios que se han hecho

			SDL_RenderClear(renderTarget); //Limpia la pantalla

			SDL_Delay(1000/60); //FPS por segundo

			if(pos1_x<0){
				cerrarjuego=1;
			}

			//colision invader-jugador
			//si ocupan la misma posicion aumenta el contador de muertes y saca las imagenes de las vidas

			if(posEnemigo_x<=posicion_x && posEnemigo_x+60>=posicion_x && posEnemigo_y<=posicion_y && posEnemigo_y+60>=posicion_y){
	       		contadormuertes++;
	            	switch(contadormuertes){		
	            		case 1:
	            		pos3_x=-50;
	       				pos3_y=-50;
	       				break;
	       				case 2:
	   					pos2_y=-50;
	   					pos2_x=-50;
	   					break;
	   					case 3:
	   					pos1_x=-50;
	   					pos1_y=-50;
	   					break;		
	   				}

	       		}
	       		//colision invader2
	       		if(posEnemigo2_x<=posicion_x && posEnemigo2_x+60>=posicion_x && posEnemigo2_y<=posicion_y && posEnemigo2_y+60>=posicion_y){
	       		contadormuertes++;
	            	switch(contadormuertes){
	            		case 1:
	            		pos3_x=-50;
	       				pos3_y=-50;
	       				break;
	       				case 2:
	       				pos2_y=-50;
	       				pos2_x=-50;
	       				break;
	       				case 3:
	       				pos1_x=-50;
	       				pos1_y=-50;
	       				break;		
	       			}

	       		}
	       		//colision invader3
	       		if(posEnemigo3_x<=posicion_x && posEnemigo3_x+60>=posicion_x && posEnemigo3_y<=posicion_y && posEnemigo3_y+60>=posicion_y){
	       		contadormuertes++;
	            	switch(contadormuertes){
	            		case 1:
	            		pos3_x=-50;
	       				pos3_y=-50;
	       				break;
	       				case 2:
	       				pos2_y=-50;
	       				pos2_x=-50;
	       				break;
	       				case 3:
	       				pos1_x=-50;
	       				pos1_y=-50;
	       				break;		
	       			}

	       		}
	       		if(posEnemigo4_x<=posicion_x && posEnemigo4_x+60>=posicion_x && posEnemigo4_y<=posicion_y && posEnemigo4_y+60>=posicion_y){
	       		contadormuertes++;
	            	switch(contadormuertes){
	            		case 1:
	            		pos3_x=-50;
	       				pos3_y=-50;
	       				break;
	       				case 2:
	       				pos2_y=-50;
	       				pos2_x=-50;
	       				break;
	       				case 3:
	       				pos1_x=-50;
	       				pos1_y=-50;
	       				break;		
	       			}

	       		}
	       		if(posEnemigo5_x<=posicion_x && posEnemigo5_x+60>=posicion_x && posEnemigo5_y<=posicion_y && posEnemigo5_y+60>=posicion_y){
	       		contadormuertes++;
	            	switch(contadormuertes){
	            		case 1:
	            		pos3_x=-50;
	       				pos3_y=-50;
	       				break;
	       				case 2:
	       				pos2_y=-50;
	       				pos2_x=-50;
	       				break;
	       				case 3:
	       				pos1_x=-50;
	       				pos1_y=-50;
	       				break;		
	       			}

	       		}
	       		if(posEnemigo6_x<=posicion_x && posEnemigo6_x+60>=posicion_x && posEnemigo6_y<=posicion_y && posEnemigo6_y+60>=posicion_y){
	       		contadormuertes++;
	            	switch(contadormuertes){
	            		case 1:
	            		pos3_x=-50;
	       				pos3_y=-50;
	       				break;
	       				case 2:
	       				pos2_y=-50;
	       				pos2_x=-50;
	       				break;
	       				case 3:
	       				pos1_x=-50;
	       				pos1_y=-50;
	       				break;		
	       			}

	       		}

		}

			
		SDL_DestroyTexture(misil);
		SDL_DestroyTexture(misilEnemigo);
		SDL_DestroyTexture(misil2Enemigo);
		SDL_DestroyTexture(misil3Enemigo);
		SDL_DestroyTexture(misil4Enemigo);
		SDL_DestroyTexture(misil5Enemigo);
		SDL_DestroyTexture(misil6Enemigo);
		SDL_DestroyTexture(text);
		SDL_DestroyTexture(texturelv);	
		SDL_DestroyTexture(jugador);
		SDL_DestroyTexture(enemigo);
		SDL_DestroyTexture(enemigo2);
		SDL_DestroyTexture(enemigo3);
		SDL_DestroyTexture(enemigo4);
		SDL_DestroyTexture(enemigo5);
		SDL_DestroyTexture(enemigo6);
		SDL_DestroyTexture(enemigo11);
		SDL_DestroyTexture(enemigo12);
		SDL_DestroyTexture(enemigo13);
		SDL_DestroyTexture(enemigo14);
		SDL_DestroyTexture(enemigo15);
		SDL_DestroyTexture(enemigo16);
		SDL_DestroyTexture(enemigo21);
		SDL_DestroyTexture(enemigo22);
		SDL_DestroyTexture(enemigo23);
		SDL_DestroyTexture(enemigo24);
		SDL_DestroyTexture(enemigo25);
		SDL_DestroyTexture(enemigo26);
		SDL_DestroyTexture(vida3);
		SDL_DestroyTexture(vida2);
		SDL_DestroyTexture(vida1);
		Mix_FreeMusic(bgs);
		
		while(cerrarjuego==1 && oof==0)
		{

FILE *p1,*p3;	

p3=fopen("texto.txt","rb");


char puntaje_1[10];				
char puntaje_2[10];
char puntaje_3[10];
char puntaje_4[10];
char puntaje_5[10];

char leer[100],ord[10];									//carpeta a leer
int conta=1;

while(1){
	char *exit=fgets(puntaje_1,10,p3);
	if(exit==NULL){
		break;
	}
	fgets(puntaje_2,10,p3);
	fgets(puntaje_3,10,p3);
	fgets(puntaje_4,10,p3);
	fgets(puntaje_5,10,p3);
	conta++;
	
}


fclose(p3);




strcpy(ord,puntaje_5);
strcpy(puntaje_5,puntaje_4);
strcpy(puntaje_4,puntaje_3);
strcpy(puntaje_3,puntaje_2);
strcpy(puntaje_2,puntaje_1);
strcpy(puntaje_1,ord);

while(v==0){

										//crear punteros al archivo .txt
p1=fopen("texto.txt","w");								//fopen lo inicia ("archivo.txt","formato")
														//formato: r=lee, rb=lee en binario, w=escribe en el archivo, a escribe sin sobreescribir
char rr[1]=("\0");
char otro[10]=("0");								//cadena para puntajes menores a 1000
char nuevo_puntaje[10];
strcpy(nuevo_puntaje,buffer);
int i=0;
if(strlen(nuevo_puntaje)==3){
	strcat(otro,nuevo_puntaje);
	strcpy(nuevo_puntaje,otro);
}


//ver si el puntaje nuevo es mayor al ultimo

puntaje_5[0,1,2,3,4]=comparar(puntaje_5,nuevo_puntaje);
puntaje_5[4]=rr[0];


// ordenar si es hubo algun cambio 						//pendiente

ordenar(puntaje_1,puntaje_2,puntaje_3,puntaje_4,puntaje_5);

puntaje_1[4]=rr[0];
puntaje_2[4]=rr[0];
puntaje_3[4]=rr[0];
puntaje_4[4]=rr[0];
puntaje_5[4]=rr[0];



char inicio[100]="Los 5 mejores puntajes son:";			
//printf("Archivo abierto\n");						
fputs(inicio,p1);								//fputs hace que p1 copie lo de la izquierda al archivo que apunta(.txt)
fputs("\n",p1);
fputs(puntaje_1,p1);
fputs("\n",p1);
fputs(puntaje_2,p1);
fputs("\n",p1);
fputs(puntaje_3,p1);
fputs("\n",p1);
fputs(puntaje_4,p1);
fputs("\n",p1);
fputs(puntaje_5,p1);
fputs("\n",p1);

v++;
fclose(p1);		

int j1=snprintf(bufferptj1,5,"%s",puntaje_1);
int j2=snprintf(bufferptj2,5,"%s",puntaje_2);
int j3=snprintf(bufferptj3,5,"%s",puntaje_3);
int j4=snprintf(bufferptj4,5,"%s",puntaje_4);
int j5=snprintf(bufferptj5,5,"%s",puntaje_5);
								
}
				

			int j1=snprintf(bufferptj1,5,"%s",puntaje_1);
	        int j2=snprintf(bufferptj2,5,"%s",puntaje_2);
	        int j3=snprintf(bufferptj3,5,"%s",puntaje_3);
	        int j4=snprintf(bufferptj4,5,"%s",puntaje_4);
	        int j5=snprintf(bufferptj5,5,"%s",puntaje_5);


	        render_text(renderTarget,600,125,bufferptj1,font,&puntaje1,&color);
	        render_text(renderTarget,600,155,bufferptj2,font,&puntaje2,&color);
	        render_text(renderTarget,600,185,bufferptj3,font,&puntaje3,&color);
	        render_text(renderTarget,600,215,bufferptj4,font,&puntaje4,&color);
	        render_text(renderTarget,600,245,bufferptj5,font,&puntaje5,&color);

			
			SDL_RenderPresent(renderTarget);

			SDL_RenderClear(renderTarget);

			SDL_Surface *top=TTF_RenderText_Solid(font, "TOP 5",color);
			SDL_Texture *texttop=SDL_CreateTextureFromSurface(renderTarget,top);

			SDL_Rect rectop;
			rectop.x=600;
			rectop.y=95;

			
			SDL_QueryTexture(texttop,NULL,NULL,&rectop.w,&rectop.h);

			SDL_RenderCopy(renderTarget,texttop,NULL,&rectop);
			

			SDL_Surface *erre=TTF_RenderText_Solid(font, "PRESIONA R PARA REINICIAR",color);
			SDL_Texture *textrr=SDL_CreateTextureFromSurface(renderTarget,erre);

			SDL_Rect recrr;
			recrr.x=480;
			recrr.y=300;

			
			SDL_QueryTexture(textrr,NULL,NULL,&recrr.w,&recrr.h);

			SDL_RenderCopy(renderTarget,textrr,NULL,&recrr);			

			const unsigned char *tecla1;
			tecla1=SDL_GetKeyboardState(NULL);
			int typeEvent1;

			SDL_Event event1;
			

			if(SDL_PollEvent(&event1))
	        {
	            typeEvent1 = event1.type;

	            if(typeEvent1 == SDL_QUIT)
	            {	
	            	oof=1;
	                break;
	            }






	           if(typeEvent1 == SDL_KEYDOWN)
	            {
	                if(tecla1[SDL_SCANCODE_R])
	                {
	                    break;
	                }

				}
			}
			SDL_DestroyTexture(texttop);
			SDL_DestroyTexture(textrr);
		}	


		SDL_DestroyRenderer(renderTarget);
		SDL_DestroyWindow(window);
		SDL_Quit();
		TTF_Quit();
		Mix_Quit();



}while(oof==0);

	
	return 0;
}