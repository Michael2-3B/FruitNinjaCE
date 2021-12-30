
███████╗██████╗░██╗░░░██╗██╗████████╗  ███╗░░██╗██╗███╗░░██╗░░░░░██╗░█████╗░
██╔════╝██╔══██╗██║░░░██║██║╚══██╔══╝  ████╗░██║██║████╗░██║░░░░░██║██╔══██╗
█████╗░░██████╔╝██║░░░██║██║░░░██║░░░  ██╔██╗██║██║██╔██╗██║░░░░░██║███████║
██╔══╝░░██╔══██╗██║░░░██║██║░░░██║░░░  ██║╚████║██║██║╚████║██╗░░██║██╔══██║
██║░░░░░██║░░██║╚██████╔╝██║░░░██║░░░  ██║░╚███║██║██║░╚███║╚█████╔╝██║░░██║
╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░  ╚═╝░░╚══╝╚═╝╚═╝░░╚══╝░╚════╝░╚═╝░░╚═╝

for the TI 84+ CE graphing calculator!
▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ 

created by Michael2_3B
based on Halfbrick Studios Fruit Ninja

released 12/31/2021
version 1.0.0

Comments or questions can be put in the forum thread: ceme.tech/p271518
GitHub Repository: https://github.com/Michael2-3B/FruitNinjaCE

▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ ▬ 

About Fruit Ninja CE
--------------------
Fruit Ninja CE is an arcade game based on the original Halfbrick Studios Fruit Ninja for smartphones, in which you must slice fruits with your finger while avoiding hitting the bombs, in order to get the highest score possible.


There are 2 gamemodes available-

The 1st gamemode is Classic, which includes 13 of your favorite fruits, plus large pomegranates, and includes bombs.
Pomegranates have a high chance of appearing every 25 points you get, and give you the opportunity to slice them multiple times before they disappear. If they are sliced, they will also explode every other fruit on the board, as well as forgiving you for any fruits that fall off the screen while you are slicing it.
Bombs will appear every now and then, and you want to be careful not to hit them, or its game over!
There are also fruit combos, in which you get additional points for 4 or more fruits sliced at the same time.

Classic gamemode also gives you 3 strikes, meaning if you miss a total of 3 fruits without slicing them, you lose.
To make the game slightly easier, and to stay true to the original game, 1 strike will be forgiven every 100 points.


The 2nd gamemode is Zen, in which there are no bombs, no pomegranates, and plenty more fruit combos. As a fair warning, there may be more lag issues in this mode because of the large amount of sprites.

Zen mode offers you 90 seconds to get the maximum amount of points you think you can get.
There are no strikes in zen mode either, so missed fruits are not a big problem.


Once the game ends, your high score will be updated on the main menu, if applicable.




Controls
--------
As there is no touchscreen on the graphing calculators, I have adapted your very own calculator keyboard to be able to handle swiping and slicing interaction much like you'd do on a normal touchscreen. In order to slice, simply drag your finger across the keyboard in any direction, making sure to apply enough pressure to press each button in your motion. Not all the keys correlate to a spot on the screen though, so take a look here:

 -----------------------------------
| math | apps | prgm | vars | clear |
| x^-1 | sin  | cos  | tan  | ^     |
| x^2  | ,    | (    | )    | ÷     |
| log  | 7    | 8    | 9    | *     |
| ln   | 4    | 5    | 6    | -     |
| sto> | 1    | 2    | 3    | +     |
| on   | 0    | .    | (-)  | enter |
 -----------------------------------

Any of the keys shown above, except for the on button, can be used to slice fruits on the screen and interact with the menu.

During the game, you can also use [mode] to pause it, as well as [window] to resume, [zoom] to go to the menu, and [trace] to quit and exit the game entirely.




Installation and Execution
--------------------------
Make sure you install the latest clibs on your calculator first: tiny.cc/clibs
I have included clibs v9.2.2 in the zip file already, but if you are seeing this further in the future you may need to update.

1. To install Fruit Ninja CE on your calculator, connect your computer to your calculator using your favorite usb to mini usb cable.
2. Open TI-Connect CE (https://education.ti.com/en/products/computer-software/ti-connect-ce-sw)
3. Once TI-Connect CE is open, go to "Calculator Explorer" and hit the upload button at the top.
    -If you do not see any connected calculators, make sure the mini usb cable is pushed all the way into the calculator, and make sure the calculator is turned on.
4. Find your clibs.8xg file, and find the FRTNINJA.8xp file included. Select them and make sure all the files are going to the archive.
5. Hit send.
6. Once everything is sent, find FRTNINJA in your programs list on your calculator and hit enter twice to run it.




Version History
---------------
v1.0.0, released 12/31/2021
 -initial release




Additional Notes & Credits
--------------------------
Thank you to MateoC for all your help on this project, and all your work on the C libraries and development of C programming tools for this platform.
Thank you to Pieman7373 for artistic help with some of the fruit sprites!

I do apologize for some of the lag issues in the game, but I did my best to keep the game speed running the same even if there are dropped frames.

If you wish to reset your highscores, use the [2nd] [+] menu in the OS, hit 2 for Mem Management/Delete, scroll down to AppVars, find the file called "FRUITDAT", and delete it.




Legal
-----
I AM NOT MAKING ANY MONEY FROM THIS. This is a game made for fun, for a unique platform, and is merely inspired by the original Fruit Ninja game. All code in this project is my own.



MIT License

Copyright (c) 2021 Michael Baker

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.