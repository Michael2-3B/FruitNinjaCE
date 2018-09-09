/*
 *--------------------------------------
 * Program Name:CSWIPE
 * Author:Michael2_3B
 * License:MIT
 * Description: A fruit ninja remake for the CE. Swipe the calculator keys to slice fruits!
 *--------------------------------------
*/

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>
#include <keypadc.h>

/* Include the sprite data */
#include "gfx/logo_gfx.h"

#define PI 3.1415926

/* Put your function prototypes here */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle, int velocity);
void moveEnts();

/*
gfx_sprite_t *watermelon_out = gfx_MallocSprite(50,50);
gfx_sprite_t *apple_out = gfx_MallocSprite(50,50);
gfx_sprite_t *pear_out = gfx_MallocSprite(50,50);
gfx_sprite_t *pineapple_out = gfx_MallocSprite(50,50);
gfx_sprite_t *strawberry_out = gfx_MallocSprite(50,50);

gfx_ScaleSprite(watermelon, watermelon_out);
gfx_ScaleSprite(apple, apple_out);
gfx_ScaleSprite(pear, pear_out);
gfx_ScaleSprite(pineapple, pineapple_out);
gfx_ScaleSprite(strawberry, strawberry_out);
*/

/* Put all your globals here */
double entX[20], entAng[20], entVel[20];
double entY[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
gfx_sprite_t *entName[20];
gfx_sprite_t *sN[5] = {watermelon, apple, pear, pineapple, strawberry};
const int s=2;
int eC=0;

void main(void) {
    /* Fill in the body of the main function here */
    kb_key_t key;
    int xList[1000], yList[1000];
    int i=0, index=0, gameTime=0, fat=0, x, y, j, randX;
    bool up=true;
    double speed = 1;
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);
    gfx_FillScreen(gfx_blue);
    gfx_SetColor(gfx_white);

    do {
    	gameTime++;
    	kb_Scan();
    	gfx_FillScreen(gfx_blue);

    	if(eC > 0)
    		moveEnts();

    	if(gameTime == 25){
    		randX = (int)(rand() % 320);
    		throwFruit(sN[rand()%5], randX, 240, rand()*PI, 6);
    		gameTime = 0;
    	}

    	x=0;
    	y=0;
    	if (kb_Data[2]) {
    		key = kb_Data[2];
    		x=32;
    		if(key == kb_Store) y=188;
    		if(key == kb_Ln) y=154;
    		if(key == kb_Log) y=120;
    		if(key == kb_Square) y=85;
    		if(key == kb_Recip) y=51;
    		if(key == kb_Math) y=17;
    	}
    	if (kb_Data[3]) {
    		key = kb_Data[3];
    		x=96;
    		if(key == kb_0) y=222;
    		if(key == kb_1) y=188;
    		if(key == kb_4) y=154;
    		if(key == kb_7) y=120;
    		if(key == kb_Comma) y=85;
    		if(key == kb_Sin) y=51;
    		if(key == kb_Apps) y=17;
    	}
    	if (kb_Data[4]){
    		key = kb_Data[4];
    		x=160;
    		if(key == kb_DecPnt) y=222;
    		if(key == kb_2) y=188;
    		if(key == kb_5) y=154;
    		if(key == kb_8) y=120;
    		if(key == kb_LParen) y=85;
    		if(key == kb_Cos) y=51;
    		if(key == kb_Prgm) y=17;
    	}
    	if (kb_Data[5]) {
    		key = kb_Data[5];
    		x=224;
    		if(key == kb_Chs) y=222;
    		if(key == kb_3) y=188;
    		if(key == kb_6) y=154;
    		if(key == kb_9) y=120;
    		if(key == kb_RParen) y=85;
    		if(key == kb_Tan) y=51;
    		if(key == kb_Vars) y=17;
    	}
    	if (kb_Data[6]) {
    		key = kb_Data[6];
    		x=288;
    		if(key == kb_Enter) y=222;
    		if(key == kb_Add) y=188;
    		if(key == kb_Sub) y=154;
    		if(key == kb_Mul) y=120;
    		if(key == kb_Div) y=85;
    		if(key == kb_Power) y=51;
    		if(key == kb_Clear) y=17;
    	}

    	if(y>0){
    		if(index>0){
    			if(x==xList[index-1] && y==yList[index-1]){
    				index--;
    				fat++;
    			}
    		}
    		xList[index] = x;
    		yList[index] = y;
    		if(index>0){
    			gfx_Line(xList[index-1],yList[index-1],x,y);
    			if(fat > 0)
    				gfx_Line(xList[index-1],yList[index-1]-1,x,y-1);
    		}
    		index++;
    		i=0;
    		if(index==1000)
    			index=0;
    	} else {
    		if(i < 101){
    			i++;
    		}
    		if(i==10){
    			index=0;
    			fat=0;
    		}
    	}

    	gfx_SwapDraw();

    } while (kb_Data[1] != kb_2nd);
    
    gfx_End();
}

/* Throw a fruit onto the screen */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle, int velocity){
	int j=0;
	while(entY[j] > 0){
		j++;
	}
	entName[j] = fruitname;
	entX[j] = curX;
	entY[j] = curY;
	entAng[j] = angle;
	entVel[j] = velocity;
	eC++;
}

/* Move any entities that are on the screen */
void moveEnts(){
	int j;
	for(j=0; j<20; j++){
		if(entY[j] > 0){
			gfx_TransparentSprite(entName[j], entX[j], entY[j]);
			entY[j] -= entVel[j];
			entVel[j] -= 0.1;
			entX[j] += 3*cos(entAng[j]);
			if(entY[j] >= 240 || entX[j] >= 320 || entX[j] <= 0){
				entY[j] = 0;
				eC--;
			}
		}
	}
}