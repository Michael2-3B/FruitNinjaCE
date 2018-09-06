/*
 *--------------------------------------
 * Program Name:CSWIPE
 * Author:Michael2_3B
 * License:MIT
 * Description:An experimental C program to swipe like you do in fruit ninja.
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

/* Put your function prototypes here */

/* Put all your globals here */

void main(void) {
    /* Fill in the body of the main function here */
    kb_key_t key;
    int xList[1000];
    int yList[1000];
    int i=0;
    int index=0;
    int x;
    int y;
    int gameTime = 0;
    double speed = 1;
    double entityX[20] = {20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double entityY[20] = {120,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240};
    gfx_Begin();
    gfx_FillScreen(gfx_blue);
    gfx_SetColor(gfx_white);
    gfx_ScaledTransparentSprite_NoClip(watermelon, entityX[0], entityY[0], 3, 3);

    do {
    	kb_Scan();
    	x=0;
    	y=0;
    	if (kb_Data[2]) {
    		key = kb_Data[2];
    		x=32;
    		if(key == kb_Store)
    			y=188;
    		if(key == kb_Ln)
    			y=154;
    		if(key == kb_Log)
    			y=120;
    		if(key == kb_Square)
    			y=85;
    		if(key == kb_Recip)
    			y=51;
    		if(key == kb_Math)
    			y=17;
    	}
    	if (kb_Data[3]) {
    		key = kb_Data[3];
    		x=96;
    		if(key == kb_0)
    			y=222;
    		if(key == kb_1)
    			y=188;
    		if(key == kb_4)
    			y=154;
    		if(key == kb_7)
    			y=120;
    		if(key == kb_Comma)
    			y=85;
    		if(key == kb_Sin)
    			y=51;
    		if(key == kb_Apps)
    			y=17;
    	}
    	if (kb_Data[4]){
    		key = kb_Data[4];
    		x=160;
    		if(key == kb_DecPnt)
    			y=222;
    		if(key == kb_2)
    			y=188;
    		if(key == kb_5)
    			y=154;
    		if(key == kb_8)
    			y=120;
    		if(key == kb_LParen)
    			y=85;
    		if(key == kb_Cos)
    			y=51;
    		if(key == kb_Prgm)
    			y=17;
    	}
    	if (kb_Data[5]) {
    		key = kb_Data[5];
    		x=224;
    		if(key == kb_Chs)
    			y=222;
    		if(key == kb_3)
    			y=188;
    		if(key == kb_6)
    			y=154;
    		if(key == kb_9)
    			y=120;
    		if(key == kb_RParen)
    			y=85;
    		if(key == kb_Tan)
    			y=51;
    		if(key == kb_Vars)
    			y=17;
    	}
    	if (kb_Data[6]) {
    		key = kb_Data[6];
    		x=288;
    		if(key == kb_Enter)
    			y=222;
    		if(key == kb_Add)
    			y=188;
    		if(key == kb_Sub)
    			y=154;
    		if(key == kb_Mul)
    			y=120;
    		if(key == kb_Div)
    			y=85;
    		if(key == kb_Power)
    			y=51;
    		if(key == kb_Clear)
    			y=17;
    	}
    	if(y>0){
    		if(index>0){
    			if(x==xList[index-1] && y==yList[index-1])
    				index--;
    		}
    		xList[index] = x;
    		yList[index] = y;
    		if(index>0)
    			gfx_Line(xList[index-1],yList[index-1],x,y);
    		index++;
    		i=0;
    		if(index==1000)
    			index=0;
    	} else {
    		if(i < 101)
    			i++;
    		if(i==100){
    			gfx_FillScreen(gfx_blue);
    			gfx_ScaledTransparentSprite_NoClip(watermelon, entityX[0], entityY[0], 3, 3);
    			index=0;
    		}
    	}
    	if(index>3){
    		gfx_SetColor(gfx_blue);
    		gfx_Line(xList[index-4],yList[index-4],xList[index-3],yList[index-3]);
    		gfx_SetColor(gfx_white);
    	}
    	
    	/*
    	if(gameTime > 5000){
    		gfx_ScaledTransparentSprite_NoClip(watermelon, entityX[0], entityY[0], 3, 3);
    		entityY[0] -= (int)speed;
    		speed -= 0.01;
    		if(entityY[0] > 240)
    			gameTime = 0;
    	}
    	gameTime++;

    	gfx_Circle_NoClip(160,222.859-(34.286*(log10(key)/log10(2))),10);
    	*/
    
    gfx_End();

}

/* Put other functions here */