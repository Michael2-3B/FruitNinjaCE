/*
 *------------------------------------------------------------------------------------------/
 * Program Name:Fruit Ninja CE                                                              /
 * Author:Michael2_3B                                                                       /
 * Special thanks: MateoC for the toolchain and his programming expertise                   /
 *                 Pieman7373 for artistic help and advice                                  /
 * License:MIT                                                                              /
 * Description: A fruit ninja remake for the CE. Swipe the calculator keys to slice fruits! /
 *------------------------------------------------------------------------------------------/
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
#include <fileioc.h>

/* Include the sprite data */
#include "gfx/logo_gfx.h"

#define PI 3.1415926
#define ONE_SECOND 32768/1

/* Put your function prototypes here */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle, int velocity, int rotation, int rotSpeed);
void moveEnts();
void drawEnts();
void gameOver();
void animateExplosion(int cx, int cy);
bool isSliced(int x1, int y1, int x2, int y2, int j);
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh);
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void print_string_centered(char *str, int y, int offset, uint8_t c);
void keyToXY();
void shake(int s);
void swipe();
void debugDisplay();

/* Put all your globals here */
// entX and entY is x and y values of sprites.
// entAng is the angle at which they are thrown
// entVel is the velocity at which they are thrown
// entRot is the sprites' rotation amount on the screen
// entRotSpeed is how fast the sprite rotates
// when fruits are thrown, entName gets loaded with sprites from sN[], so as to specify which fruit it is at what index
// and of course, these arrays are parallel so that the values at the matching indices give info for the same sprite
double entX[20], entAng[20], entVel[20], entRot[20];
double entY[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int entRotSpeed[20];
int sprites = 13;
int xcount = 0;
gfx_sprite_t *entName[20];
gfx_sprite_t *sN[13] = {watermelon, apple, pear, pineapple, strawberry, red_apple, grapes, kiwi, banana, coconut, lemon, lime, orange};
gfx_sprite_t *sS[26] = {watermelon_top, watermelon_bottom,
                        apple_top, apple_bottom,
                        pear_top, pear_bottom,
                        pineapple_top, pineapple_bottom,
                        strawberry_top, strawberry_bottom,
                        red_apple_top, red_apple_bottom,
                        grape_top, grape_bottom,
                        kiwi_top, kiwi_bottom,
                        banana_top, banana_bottom,
                        coconut_top, coconut_bottom,
                        lemon_top, lemon_bottom,
                        lime_top, lime_bottom,
                        orange_top, orange_bottom
                    };
bool flag=false;
bool pauseflag=true;
bool menuflag=false;
bool comboText=false;
bool zenMode;
int eC=0, all_eC=0, x=0, y=0, i=0, index=0, volleys=0, timeSinceLastSlice=100, combo=0, comboWait=0, theCombo=0;
int mult=1;
int x,x2;
int interval=100;
unsigned int seconds = 0;
unsigned int score, prevScore;
int xList[1000], yList[1000];
kb_key_t key;
gfx_UninitedSprite(sprite_buffer, 64, 64); //sprite buffer for rotating sprites

struct { int highscore, zenhighscore; } file;
char* filename = "FRUITDAT";

void main(void) {

	ti_var_t slot;
	int *temp_ptr;

    /* Variable Declarations */
    char *title = "Fruit Ninja CE";
    char *inf = "Info";
    char *high = "High: ";
    int j, c, jc, jy, menuRock=0, button=0, gameTime;
    bool clockwise=true, exit=false;

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);

    memset(&file,0,sizeof(file));
	ti_CloseAll();
	if(slot = ti_Open(filename,"r")) ti_Read(&file,sizeof(file),1,slot);
    ti_SetArchiveStatus(false, slot);
	ti_CloseAll();

    /* Menu Loop */
    /* Technically I'm redrawing everything each loop */
    MENU:score = 0;
    prevScore = 0;
    gameTime = 0;
    zenMode = false;
    do{
        button = 0;
        do{
            kb_Scan();
            gfx_FillScreen(4);

            gfx_SetColor(1);
            gfx_Rectangle(0,0,320,240);
            gfx_SetColor(2);
            gfx_Rectangle(1,1,318,238);
            gfx_SetColor(3);
            gfx_Rectangle(2,2,316,236);
            gfx_SetColor(0);
            gfx_Rectangle(3,3,314,234);

            gfx_Rectangle(20,50,280,1);
            gfx_FillCircle(80,160,55);
            gfx_FillCircle(191,120,35);
            gfx_FillCircle(269,120,35);
            gfx_FillCircle(230,195,35);
            gfx_SetColor(3);
            gfx_Rectangle(19,49,280,1);
            gfx_SetColor(2);
            gfx_Rectangle(18,48,280,1);
            gfx_SetColor(1);
            gfx_Rectangle(17,47,280,1);

            gfx_SetTextScale(3,3);
            print_string_centered(title, 17, -3, 1);
            print_string_centered(title, 18, -2, 2);
            print_string_centered(title, 19, -1, 3);
            print_string_centered(title, 20, 0, 0);

            gfx_SetTextScale(2,2);
            print_string_centered(high, 60, -100, 0);
            gfx_SetTextXY(95,60);
            gfx_PrintInt(file.highscore, 1);
            print_string_centered("Zen: ", 80, -100, 0);
            gfx_SetTextXY(95,80);
            gfx_PrintInt(file.zenhighscore, 1);
            gfx_SetTextScale(1,1);

            gfx_SetColor(5);
            gfx_FillCircle(80,160,49);
            gfx_FillCircle(191, 120, 30);
            gfx_FillCircle(269, 120, 30);
            gfx_FillCircle(230, 195, 30);

            print_string_centered("Start", 135, -80, 3);
            print_string_centered("Zen", 135, 30, 3);
            print_string_centered(inf, 135, 110, 3);
            print_string_centered("Quit", 210, 70, 3);

            gfx_TransparentSprite(gfx_RotateScaleSprite(watermelon, sprite_buffer, menuRock, 1.3*64), 60, 150);
            gfx_TransparentSprite(gfx_RotateScaleSprite(grapes, sprite_buffer, menuRock, 1.3*64), 168, 97);
            gfx_TransparentSprite(gfx_RotateSprite(pineapple, sprite_buffer, menuRock-30), 255, 97);
            gfx_TransparentSprite(gfx_RotateSprite(bomb, sprite_buffer, menuRock), 214, 170);

            keyToXY();

            if(y>0){
                //put screen swipe locations in array
                xList[index] = x;
                yList[index] = y;
            
                //if there is an active line in the array from swiping
                if(index>0){
                    gfx_SetColor(0);
                    gfx_Line(xList[index-1],yList[index-1],x,y);

                    if(kb_Data[3] == kb_4) //start
                        button = 1;

                    if(kb_Data[5] == kb_9)
                        button = 2;

                    if(kb_Data[6] == kb_Mul || kb_Data[6] == kb_Div) //info
                        button = 3;

                    if(kb_Data[5] == kb_3) //exit
                        button = 4;
                    
                }
                index++;
                i=0;
                if(index==1000) index=0;
            } else { //there was not a swipe over the keys
                if(i < 10) i++;
                if(i==10) index=0;
            }

            gfx_BlitBuffer();

            /* Controls back and forth rocking of menu sprites */
            if(clockwise == true)
                menuRock+=4;

            if(clockwise == false)
                menuRock-=4;

            if(menuRock > 30)
                clockwise = false;

            if(menuRock < -30)
                clockwise = true;

        } while (button==0); //exit the loop once a button is pressed

        if(button==1){
            gfx_SetColor(5);
            j=49;
            jc=1;
            jy=150;
            do{
                gfx_FillCircle(80,160,j);
                if(jy<240){
                    gfx_TransparentSprite(gfx_RotateScaleSprite(watermelon_top, sprite_buffer, menuRock, 1.3*64), 60, jy);
                    gfx_TransparentSprite(gfx_RotateScaleSprite(watermelon_bottom, sprite_buffer, menuRock, 1.3*64), 60, jy+jc);
                }
                gfx_BlitBuffer();

                j += jc;
                jy += jc;
                jc *= 2;

            }while(j<=320);

        } else if(button==2){
            gfx_SetColor(5);
            j=30;
            jc=1;
            jy=100;
            do{
                gfx_FillCircle(191,120,j);
                if(jy<240){
                    gfx_TransparentSprite(gfx_RotateScaleSprite(grape_top, sprite_buffer, menuRock, 1.3*64), 168, jy);
                    gfx_TransparentSprite(gfx_RotateScaleSprite(grape_bottom, sprite_buffer, menuRock, 1.3*64), 168, jy+jc);
                }
                gfx_BlitBuffer();

                j += jc;
                jy += jc;
                jc *= 2;

            }while(j<=320);
            zenMode = true;

        } else if(button==3){
            //Info Menu
            gfx_SetColor(5);
            j=30;
            jc=1;
            jy=100;
            do{
                gfx_FillScreen(4);
                if(j > 0)
                    gfx_FillCircle(269,120,j);
                if(jy<240){
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_top, sprite_buffer, menuRock-30), 255, jy);
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_bottom, sprite_buffer, menuRock-30), 255, jy+jc);
                }
                gfx_BlitBuffer();

                j -= jc;
                jy += jc;
                jc *= 2;

            }while(j>0);
            
            do{
                kb_Scan();
                gfx_FillScreen(4);

                gfx_SetColor(1);
                gfx_Rectangle(0,0,320,240);
                gfx_SetColor(2);
                gfx_Rectangle(1,1,318,238);
                gfx_SetColor(3);
                gfx_Rectangle(2,2,316,236);
                gfx_SetColor(0);
                gfx_Rectangle(3,3,314,234);

                gfx_SetTextScale(2,2);
                print_string_centered(inf, 24, -3, 1);
                print_string_centered(inf, 25, -2, 2);
                print_string_centered(inf, 26, -1, 3);
                print_string_centered(inf,27,0,0);

                gfx_SetTextScale(1,1);
                print_string_centered("Created by Michael2_3B", 70, 0, 0);
                print_string_centered("version 0.0.1", 85, 0, 2);
                print_string_centered("released xx/xx/2020", 100, 0, 0);
                print_string_centered("Special thanks to MateoC for his expertise", 115, 0, 0);
                print_string_centered("and Pieman7373 for artistic help", 130, 0, 0);
                print_string_centered("based on Halfbrick Studios Fruit Ninja", 220, 0, 0);

                gfx_FillCircle(35,55,25);
                gfx_SetColor(5);
                gfx_FillCircle(35,55,20);
                gfx_SetColor(0);
                gfx_TransparentSprite(gfx_RotateSprite(pineapple, sprite_buffer, menuRock-30), 20, 40);
                
                if(clockwise == true)
                menuRock+=2;

                if(clockwise == false)
                menuRock-=2;

                if(menuRock > 30)
                clockwise = false;

                if(menuRock < -30)
                clockwise = true;

                keyToXY();
				swipe();

                gfx_BlitBuffer();
            } while(kb_Data[2] != kb_Recip);

            gfx_SetColor(5);
            j=20;
            jc=1;
            jy=20;
            do{
                gfx_FillScreen(4);
                if(j > 0)
                    gfx_FillCircle(35,35,j);
                if(jy < 240){
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_top, sprite_buffer, menuRock-30), 20, jy);
                    gfx_TransparentSprite(gfx_RotateSprite(pineapple_bottom, sprite_buffer, menuRock-30), 20, jy+jc);
                }
                gfx_BlitBuffer();

                j -= jc;
                jy += jc;
                jc *= 2;

            }while(j>0);

        } else if(button==4){
            gfx_SetColor(0);
            j=1;
            jc=1;
            do{
                gfx_FillCircle(230, 195, j);
                gfx_BlitBuffer();
                j += (int)jc;
                jc *= 2;
            }while(j<=320);
        }
    }while(button == 3);

    if(button==1 || button==2){

	    gfx_SetColor(0);
	    gfx_SetTextScale(3,2);
	    flag = false;
	    score = 0;
        prevScore = 0;
	    all_eC = 0;
        volleys = 0;
        x = 0;
        x2 = 0;
        interval = 100;
        srandom(0);
        if (zenMode == true){
            volleys = 6;
            interval = 50;
            srandom(1);
            rtc_LoadSeconds = rtc_LoadMinutes = rtc_LoadHours = rtc_LoadDays = 0;
            rtc_Control = RTC_ENABLE | RTC_LOAD | RTC_SEC_INT_SOURCE;
            while (rtc_IsBusy());
            rtc_IntAcknowledge = RTC_INT_MASK;
        }

        srand(rtc_Time());

	    /* ---------------------------------------------------------------------------------------------------------*/
	    /* START THE GAME!!!                                                                                        */
	    /* SLICE DEM FRUITS                                                                                         */
	    /* ---------------------------------------------------------------------------------------------------------*/

	    do {
	        gameTime++;
            timeSinceLastSlice++;
	        kb_Scan();
	        gfx_FillScreen(5);
	        gfx_SetTextXY(2,2);
	        gfx_SetTextFGColor(4);
	        gfx_PrintInt(score, 1);
            if(zenMode==true){
                gfx_SetTextXY(272,2);
                gfx_PrintUInt(90-seconds, 2);
            }

            if(kb_Data[1]!=kb_Mode) pauseflag = false;

	        // for in-game debugging
	        debugDisplay();

            if(zenMode==false){
    	        gfx_PrintStringXY("XXX", 248, 2);
    	        gfx_SetTextFGColor(1);
    	        if(xcount==1)
    	        	gfx_PrintStringXY("X", 248, 2);
    	        if(xcount==2)
    	        	gfx_PrintStringXY("XX", 248, 2);
    	        if(xcount==3)
    	        	gfx_PrintStringXY("XXX", 248, 2);
    	        if(xcount>=3){
    	        	exit = true;

                    gameOver();
    	        }
            } else {
                //Display 90 second counter
                if (rtc_IntStatus & RTC_SEC_INT) {
                    seconds++;

                    if(seconds==90){
                        exit = true;
                        gameOver();
                    }

                    rtc_IntAcknowledge = rtc_IntStatus;
                }
            }

            if(comboText==true){
                gfx_SetTextScale(2,2);
                gfx_SetTextFGColor(1);
                gfx_PrintStringXY("combo! +", 190, 220);
                gfx_SetTextXY(300,220);
                gfx_PrintInt(theCombo, 1);

                gfx_SetTextScale(3,2);

                comboWait++;
                if(comboWait>25){
                    comboText=false;
                    comboWait=0;
                }
            }

	        //move entities on the screen
            for(j=-1; j<(int)(all_eC/2); j++)
                moveEnts();

            drawEnts();

	        //interval to throw fruits on the screen
	        if(gameTime == interval){

	            //throwFruit(fruitname,   x,     y, angle, velocity, rotation, rotation speed)
                x = (int)(25+(rand()%250));
	            throwFruit(sN[rand()%sprites], x, 240, PI, 9+(rand()%1), 0, rand()%5);
	            eC++;
	            all_eC++;

                //increase potential volleys every 20 score
                if(score%10==0 && score>0 && volleys<6)
                    volleys++;

                //throw a bomb on the screen
                if((int)(rand() % 10)==1 && zenMode==false){
                    do{
                        x2 = (int)(25+(rand()%250));
                    }while(abs(x2-x)<=48);
                    throwFruit(bomb, x2, 240, PI, 9+(rand()%1), 0, rand()%8);
                    eC++;
                    all_eC++;
                    
                    if(volleys > 0){
                        for(j=0; j<(int)(rand()%volleys); j++){
                            do{
                                x = (int)(25+(rand()%250));
                            }while(abs(x-x2)<=48);
                            throwFruit(sN[rand()%sprites], x, 240, PI, 9+(rand()%1), 0, rand()%5);
                            eC++;
                            all_eC++;
                        }
                    }
                } else {
                    //throw more fruits based on game progression
                    if(volleys > 0){
                        for(j=0; j<(int)(rand()%volleys); j++){
                            throwFruit(sN[rand()%sprites], (int)(25+(rand() % 250)), 240, PI, 9+(rand()%1), 0, rand()%5);
                            eC++;
                            all_eC++;
                        }
                    }
                }

	            gameTime = 0;
	        }

            if(score>0 && score%25<prevScore%25 && zenMode==false){
                prevScore=score;
                throwFruit(pomegranate, 320, 220, 3*PI/2, 8, 0, rand()%5);
                eC++;
                all_eC++;
            }

            if(timeSinceLastSlice > 10){
                if(combo > 2){
                    comboText = true;
                    prevScore = score;
                    score += combo;
                    theCombo = combo;
                }
                combo = 0;
            }

	        // convert key input to x and y locations on screen
	        keyToXY();

	        //if there was a swipe over the keys
	        if(y>0){
	            
	        	//put screen swipe locations in array
	            xList[index] = x;
	            yList[index] = y;
	        
	        	//if there is an active line in the array from swiping
	            if(index>0){
	                gfx_Line(xList[index-1],yList[index-1],x,y);
	                
	                if(eC > 0){ //if whole entity count on the screen is greater than 0 (does not include halves)
	                    for(j=0; j<=20; j++){
	                    	if(entY[j] > 0){
		                        //Detect if line touches sprite
		                        if(isSliced(xList[index-1],yList[index-1],x,y,j)){
		                        	//Something was sliced
		                            if(entName[j] == bomb){
		                                //YOU HIT A BOMB!!!
		                                animateExplosion(entX[j]+20, entY[j]+20);
		                                exit = true;

		                                gameOver();

		                            } else if(entName[j] == pomegranate){
                                        prevScore = score;
                                        score++;
                                    } else { //fruit was sliced
		                                for(c=0; c<=sprites-1; c++){
		                                    if(entName[j] == sN[c]){
		                                    	//throwFruit(fruitname, x, y, angle, velocity, rotation, rotation speed)
		                                    	throwFruit(sS[2*c], entX[j], entY[j], entAng[j], 2, entRot[j], 0);
		                                    	throwFruit(sS[2*c+1], entX[j], entY[j], entAng[j], 0, entRot[j], 0);
		                                    	eC--;
		                                    	all_eC++;
		                                    	entY[j] = 0;
                                                prevScore = score;
		                                        score++;
                                                timeSinceLastSlice = 0;

		                                        if((score%100)==0 && xcount > 0)
		                                        	xcount--;

                                                if(timeSinceLastSlice <= 10)
                                                    combo++;

		                                        c = sprites;
		                                    }
		                                }
		                            }
		                        }
	                    	}
	                    }
	                }
	            }
	            index++;
	            i=0;
	            if(index==1000) index=0;
	        } else { //there was not a swipe over the keys
	        	
	            if(i < 10) i++;
	            if(i==10) index=0;

	        }

	        gfx_BlitBuffer();

	        if(kb_Data[1] == kb_Mode && pauseflag==false){
                pauseflag = true;
	        	gfx_SetColor(4);
	        	gfx_FillRectangle(50,50,220,140);
	        	gfx_SetColor(1);
	            gfx_Rectangle(46,46,228,148);
	            gfx_SetColor(2);
	            gfx_Rectangle(47,47,226,146);
	            gfx_SetColor(3);
	            gfx_Rectangle(48,48,224,144);
	            gfx_SetColor(0);
	            gfx_Rectangle(49,49,222,142);
	            gfx_SetTextScale(3,3);
	            print_string_centered("Paused", 65, 0, 0);
	            gfx_SetTextScale(1,1);
	            print_string_centered("Resume", 175, -70, 2);
                print_string_centered("Menu", 175, 0, 2);
	            print_string_centered("Quit", 175, 70, 2);
	        	gfx_BlitBuffer();
	        	gfx_SetColor(0);
	        	gfx_SetTextScale(3,2);
	        	flag=false;
	        	do{
	        		kb_Scan();
                    if(kb_Data[1]!=kb_Mode) pauseflag = false;
	        		if(kb_Data[1]==kb_Window || (kb_Data[1]==kb_Mode && pauseflag==false)){
                        //resume
	        			flag = true;
                        pauseflag = true;
	        		}
                    if(kb_Data[1]==kb_Zoom){
                        //menu
                        flag = true;
                        menuflag = true;
                        exit = true;
                    }
	        		if(kb_Data[1]==kb_Trace){
                        //quit
	        			flag = true;
                        exit = true;
	        		}
	        	} while (flag==false);

	        }

	    } while (exit==false); //wait until bomb is hit or game loop is otherwise exited

        if(zenMode==false){
            temp_ptr = &file.highscore;
            if (score > *temp_ptr) *temp_ptr = score;
        } else {
            if(kb_Data[1]!=kb_Trace && kb_Data[1]!=kb_Zoom){
                temp_ptr = &file.zenhighscore;
                if (score > *temp_ptr) *temp_ptr = score;
            }
        }

	}

    if (menuflag==true){
        menuflag = false;
        flag = false;
        exit = false;
        xcount = 0;
        seconds = 0;
        all_eC = 0;
        eC = 0;
        for(j=0;j<20;j++)
            entY[j] = 0;
        goto MENU;
    }

    gfx_End();

    if (slot = ti_Open(filename,"w")) ti_Write(&file,sizeof(file),1,slot);
    ti_SetArchiveStatus(true, slot);
	ti_CloseAll();

}

/* Additional Functions! */

/* Throw a fruit onto the screen */
void throwFruit(gfx_sprite_t *fruitname, int curX, int curY, int angle, int velocity, int rotation, int rotSpeed){
    int j=0;
    while(entY[j] > 0){
        j++;
    }
    entName[j] = fruitname;
    entX[j] = curX;
    entY[j] = curY;
    entAng[j] = angle;
    entVel[j] = velocity;
    entRot[j] = rotation;
    entRotSpeed[j] = rotSpeed;
}

/* Move any entities that are on the screen */
void moveEnts(){
    int j;
    int c;
    for(j=0; j<20; j++){
        if(entY[j] > 0){
            if(entName[j] == pomegranate){
                //gfx_SetColor(1);
                //rotateTriangle(centerX,centerY,size,rotation);
                //gfx_FillTriangle(entX[j]+19.2,entY[j]-8,entX[j]-8,entY[j]+46.4,entX[j]+46.4,entY[j]+46.4);
            }
            
            entY[j] -= entVel[j];
            entVel[j] -= 0.2;

            if(entName[j] == pomegranate){
                mult = 3;
            } else {
                mult = 1;
            }
            
            entX[j] += mult*sin(entAng[j]);
            entRot[j] += entRotSpeed[j];
            if(entRot[j] > 255)
                entRot[j] = 0;
            if(entY[j] >= 240 || entX[j] >= 320 || entX[j] <= -32){
                entY[j] = 0;
                all_eC--;

                if(entName[j] == bomb){
                	eC--;
                } else if(entName[j] == pomegranate){
                   eC--;
                } else {
                	flag = false;
	            	for(c=0; c<=sprites-1; c++){
	                	if(entName[j] == sN[c]){
	                		flag = true;
	                		c=sprites;
	                	}
	            	}
	            	if(flag==true){
                        if(zenMode==false){
    	            		xcount++;
    	            		shake(3);
                        }
	            		eC--;
	            	}
	            }
            }
        }
    }
}

void drawEnts(){
    int j;
    for(j=0; j<20; j++){
        if(entY[j] > 0)
            gfx_TransparentSprite(gfx_RotateScaleSprite(entName[j], sprite_buffer, entRot[j], 1.2*64), entX[j], entY[j]);
    }
}

void gameOver(){
    gfx_FillScreen(0);
    gfx_SetTextScale(2,2);
    print_string_centered("Game Over!", 105, 0, 3);
    print_string_centered("Score:", 130, -20, 3);
    gfx_SetTextXY(190,130);
    gfx_SetTextFGColor(3);
    gfx_PrintInt(score, 1);

    gfx_BlitBuffer();
    flag = false;
    do{
        kb_Scan();
        if(kb_Data[6]==kb_Clear || kb_Data[1]==kb_2nd || kb_Data[6]==kb_Enter)
            flag = true;
    } while (flag == false);

    menuflag = true;
}

/* Display the bomb exploding animation */
void animateExplosion(int cx, int cy){
    int z, j, side, sx, sy, sx2, sy2;
    gfx_SetColor(0);
    for(z=0; z<20; z++){
        side = (int)(rand()%4);
        if(side==0){
            sx = 0;
            sy = (int)(rand()%240);

            sx2 = 320;
            sy2 = (int)(rand()%240);

        } else if(side==1){
            sx = (int)(rand()%320);
            sy = 0;

            sx2 = (int)(rand()%320);
            sy2 = 240;

        } else if(side==2){
            sx = 320;
            sy = (int)(rand()%240);

            sx2 = 0;
            sy2 = (int)(rand()%240);

        } else {
            sx = (int)(rand()%320);
            sy = 240;

            sx2 = (int)(rand()%320);
            sy2 = 0;

        }
        if(z>8)
            gfx_FillCircle(cx, cy, (z-12)*(z-12)*(z-12));
        gfx_Line(cx, cy, sx, sy);
        gfx_Line(cx+1, cy+1, sx+1, sy+1);
        gfx_Line(cx, cy, sx2, sy2);
        gfx_Line(cx+1, cy+1, sx2+1, sy2+1);
        gfx_SwapDraw();
        
        shake(5);
    }
}

/* Detect if line goes through sprite */
bool isSliced(int x1, int y1, int x2, int y2, int j){
    float sx = entX[j];
    float sy = entY[j];
    float sw = 1.2*32;
    float sh = 1.2*32;

    bool hit = lineRect(x1, y1, x2, y2, sx, sy, sw, sh);
    
    return hit;
}

/* fancy calculations used in detecting a slice */
/* http://jeffreythompson.org/collision-detection/line-rect.php */
bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh){
    bool left = lineLine(x1, y1, x2, y2, rx, ry, rx, ry+rh);
    bool right = lineLine(x1, y1, x2, y2, rx+rw, ry, rx+rw, ry+rh);
    bool top = lineLine(x1, y1, x2, y2, rx, ry, rx+rw, ry);
    bool bottom = lineLine(x1, y1, x2, y2, rx, ry+rh, rx+rw, ry+rh);

    if(left || right || top || bottom){
        return true;
    } else {
        return false;
    }
}

/* fancy calculations used in detecting a slice */
/* http://jeffreythompson.org/collision-detection/line-rect.php */
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
    float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

    if(uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1){
        return true;
    } else {
        return false;
    }
}

/* Prints a screen centered string, with desired offset and color */
void print_string_centered(char *str, int y, int offset, uint8_t c) {
    gfx_SetTextFGColor(c);
    gfx_PrintStringXY(str, (LCD_WIDTH - gfx_GetStringWidth(str)) / 2 + offset, y);
}

/* Convert keypress to x/y location for swiping */
void keyToXY(){
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
}

/* Shake the screen */
void shake(int s){
	gfx_ShiftDown(s);
    gfx_SwapDraw();
    gfx_ShiftUp(s);
    gfx_SwapDraw();
    gfx_ShiftUp(s);
    gfx_SwapDraw();
    gfx_ShiftDown(s);
    gfx_SwapDraw();
    gfx_ShiftLeft(s);
    gfx_SwapDraw();
    gfx_ShiftRight(s);
    gfx_SwapDraw();
    gfx_ShiftRight(s);
    gfx_SwapDraw();
    gfx_ShiftLeft(s);
    gfx_SwapDraw();
}

/* Draw slicing lines */
void swipe(){
	if(y>0){ //there was a swipe over the keys
        
        xList[index] = x;
        yList[index] = y;
            
        gfx_SetColor(0);
        if(index>0) gfx_Line(xList[index-1],yList[index-1],x,y);

        index++;
        i=0;
        if(index==1000) index=0;

    } else { //there was not a swipe over the keys
        
        if(i < 10) i++;
        if(i==10) index=0;
                
    }
}

/* Debugging Info */
void debugDisplay(){
	int j;
	gfx_SetTextScale(1,1);

	//eC is the amount of entities on the screen that aren't fruit halves
	gfx_PrintStringXY("eC: ", 2, 230);
	gfx_SetTextXY(22,230);
	gfx_PrintInt(eC, 1);

	//all_eC is the total amount of sprites currently onscreen
	gfx_PrintStringXY("all_eC: ", 2, 220);
	gfx_SetTextXY(50,220);
	gfx_PrintInt(all_eC, 1);

	gfx_SetTextScale(3,2);
}




