#include <bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "MainMenu.h"
#include<fstream>
using namespace std;
using namespace sf;
int wWidth = 800 , wHeight = 600,  life = 3,level = 0,N=1,score =0;
vector<pair<double,double> > bullarray;
int main()
{
      float x = 0;
    float y = 0;
    int k = 0;

    Texture spaceship,bg,Ufo,firebul,collisiontxt,coll2txt,coll3txt;
    spaceship.loadFromFile("data/images/newship.png");
    bg.loadFromFile("data/images/newback.jpg");
     Ufo.loadFromFile("data/images/ufo.png");
     firebul.loadFromFile("data/images/firebul.png");
     collisiontxt.loadFromFile("data/images/collision.png");
     coll2txt.loadFromFile("data/images/coll2.png");
     coll3txt.loadFromFile("data/images/coll3.png");
     firebul.setSmooth(true);
    bg.setSmooth(true);
        Sprite SpriteSheet(spaceship);
        Sprite background1(bg),background2(bg);
        Sprite ufo1(Ufo);
         //Sprite ufo2(Ufo);
         // Sprite ufo3(Ufo);
          Sprite bullet(firebul);
          Sprite collision(collisiontxt);
          Sprite coll3(coll3txt);
    bullet.scale(.2,.3);
    SpriteSheet.scale(.4,.4);
    background1.scale(.6,.6);
    background2.scale(.6,.6);
    ufo1.scale(.2,.2);
   // ufo2.scale(.2,.2);
   // ufo3.scale(.2,.2);
    ufo1.setPosition(800,rand()%500);
   /* ufo2.setPosition(1000,rand()%500);
     ufo3.setPosition(1200,rand()%500);*/

       double backgroundX1 =0;
       double backgroundX2=765;
       double ufoX1 = 800;
       double ufoX2,ufoX3;
       SoundBuffer  bulletsoundbuffer,bulletsoundbuffer2,bulletsoundbuffer3,bulletsoundbuffer4;
       if(!bulletsoundbuffer.loadFromFile("bullet.WAV"));
       {
           cout<<"BULLET";
       }


     if(!bulletsoundbuffer2.loadFromFile("blast.WAV"));
       {
           cout<<"BULLET";
       }
        if(!bulletsoundbuffer3.loadFromFile("blast2.WAV"));
       {
           cout<<"BULLET";
       }
       if(!bulletsoundbuffer4.loadFromFile("ryuk.WAV"));
       {
           cout<<"BULLET";
       }
    Sound bulletsound,bulletsound2,bulletsound3,bulletsound4;
       bulletsound.setBuffer(bulletsoundbuffer);
        bulletsound2.setBuffer(bulletsoundbuffer2);
        bulletsound3.setBuffer(bulletsoundbuffer3);
        bulletsound4.setBuffer(bulletsoundbuffer4);
    RenderWindow InterFace(VideoMode(wWidth,wHeight), "interface");
    RectangleShape background,background8;
    background.setSize(Vector2f(wWidth,wHeight));
    Texture Maintexture;
    Maintexture.loadFromFile("data/images/intrtface.jpg");
    //Sprite bg(Maintexture);
    background.setTexture(&Maintexture);
    //InterFace interface(700, 200);




    //Texts
     string lifestr = "Life:", scorestr ="Score:",gameoverstr = "Your Score: ";
     Font font;
       font.loadFromFile("data/font/Con1.ttf");
       Text textscore, textlife,textgameover, textlevel, textlevelintro;
       textscore.setFont(font);
       textscore.setCharacterSize(30);
       textscore.setColor(Color::White);
       textscore.setStyle(Text::Bold);
        textscore.setString(scorestr);
        textscore.setPosition(10,550);


        textlife.setFont(font);
       textlife.setCharacterSize(30);
       textlife.setColor(Color::White);
       textlife.setStyle(Text::Bold);
       textlife.setString(lifestr);
        textlife.setPosition(600, 550);


        textgameover.setFont(font);
       textgameover.setCharacterSize(100);
       textgameover.setColor(Color::White);
       textgameover.setStyle(Text::Bold);
       textgameover.setString(gameoverstr);
        textgameover.setPosition(120, 350);

        string levelstr = "LEVEL: ";
       textlevel.setFont(font);
      textlevel.setCharacterSize(100);
       textlevel.setColor(Color::Blue);
       textlevel.setStyle(Text::Bold);
       textlevel.setString(levelstr);
        textlevel.setPosition(120, 200);

        string levelintrostr = "Press Up or Down to Change Level";
         textlevelintro.setFont(font);
      textlevelintro.setCharacterSize(50);
       textlevelintro.setColor(Color::White);
       textlevelintro.setStyle(Text::Bold);
       textlevelintro.setString(levelintrostr);
        textlevelintro.setPosition(30, 10);
        while(InterFace.isOpen())
                       {
                           Event avent;
                           while(InterFace.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   InterFace.close();
                               }
                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       k = 1;
                                       InterFace.close();
                                   }
                               }
                           }
                           Texture gameovertxt;
                                     gameovertxt.loadFromFile("data/images/intrtface.jpg");
                                     Sprite gameoverspt(gameovertxt);
                                        gameoverspt.scale(0.32,0.44);
                                      gameoverspt.setPosition(0,0);
                                     InterFace.clear();

                                      InterFace.draw(gameoverspt);
                                      //textgameover.setString(gameoverstr);
                                      //InterFace.draw(textgameover);
                                       InterFace.display();

                       }
                       RenderWindow MENU(VideoMode(wWidth,wHeight), "Space");
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
//RectangleShape background;
    background8.setSize(Vector2f(wWidth,wHeight));
    Texture Maintexture2;
    Maintexture.loadFromFile("data/images/menuBack.jpg");
    //Sprite bg(Maintexture);
    background8.setTexture(&Maintexture);

  if(k == 1) //
  { //
          while(MENU.isOpen()){

        Event event;

        while(MENU.pollEvent(event)){

            if(event.type == Event::Closed){
                MENU.close();
            } //modification
            if(event.type == Event :: KeyReleased)
            {
                if(event.key.code == Keyboard :: Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard :: Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard :: Return)
                {
                   RenderWindow Play(VideoMode(800,600), "SPACE__IMAPACT");
                   RenderWindow OPTIONS(VideoMode(800,600), "Options");
                   RenderWindow ABOUT(VideoMode(800,600), "About");
                   int x = mainMenu.MainMenuPressed();
                   if(x == 0)
                   {
                       while(Play.isOpen())
                       {
                           Event avent;
                           while(Play.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   Play.close();
                               }
                               if(life == 0){


                                    RenderWindow GameOver(VideoMode(800,600), "Game Over");
                                     while(GameOver.isOpen()){

                                        Event evover;
                                         while(GameOver.pollEvent(evover))
                           {
                               if(evover.type == Event::Closed)
                               {
                                   GameOver.close();
                               }
                                 if(evover.key.code == Keyboard::Escape)
                                   {
                                       GameOver.close();
                                   }
                                     }
                                     Texture gameovertxt;
                                     gameovertxt.loadFromFile("data/images/gameover.jpg");
                                     Sprite gameoverspt(gameovertxt);
                                     gameoverspt.scale(1.3,1.3);
                                      gameoverspt.setPosition(-30,-200);
                                     GameOver.clear();

                                      GameOver.draw(gameoverspt);
                                      textgameover.setString(gameoverstr+to_string(score));
                                      GameOver.draw(textgameover);
                                       GameOver.display();



                            }

                             score = 0;

                                Play.close();

                               }


                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       Play.close();
                                   }
                               }
                                if(Keyboard:: isKeyPressed(Keyboard::Space) ){ bulletsound.play();
                bullarray.push_back(make_pair(SpriteSheet.getPosition().x + 10,SpriteSheet.getPosition().y+16));
            }

                           }




                           OPTIONS.close();
                           ABOUT.close();
                           y = 0;
        x =0;
        if(Keyboard::isKeyPressed(Keyboard::Up)){
                 if(SpriteSheet.getPosition().y>=0)
            y = -1;
        }
             if(Keyboard::isKeyPressed(Keyboard::Down)){
                  if(SpriteSheet.getPosition().y<=500)
            y = 1;
             }
             if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(SpriteSheet.getPosition().x<=700)
            x = 1;
             }
             if(Keyboard::isKeyPressed(Keyboard::Left)){
                    if(SpriteSheet.getPosition().x>=0)
            x = -1;
        }
         if(!(Keyboard::isKeyPressed(Keyboard::Up))&&!(Keyboard::isKeyPressed(Keyboard::Down))){
            y = 0;
        }

             if(!(Keyboard::isKeyPressed(Keyboard::Right))&&!(Keyboard::isKeyPressed(Keyboard::Left))){
            x = 0;
             }

       background1.setPosition(backgroundX1 ,0);
         background2.setPosition(backgroundX2,0);
         if(ufoX1<-100){
           ufo1.setPosition(900,rand()%500);
           ufoX1 = 900;
         }
         else{
            ufoX1 -=1;
         }

         if(backgroundX2<0){
         backgroundX1 = 0;
         backgroundX2= backgroundX1 +765;
         }
         backgroundX1-=.2;
        backgroundX2-=.2;

        Play.clear();

         Play.draw(background2);
  Play.draw(background1);

       Play.draw(ufo1);
         // Window.draw(ufo2);
          // Window.draw(ufo3);
  if(!bullarray.empty()){
               Sprite collision(collisiontxt);
               Sprite coll2(coll2txt);
                Sprite coll3(coll3txt);

               collision.scale(.4,.4);
               coll3.scale(.5,.5);
               int f = 0;
            for(int i=0;i<bullarray.size();i++){
                bullarray[i].first +=2;
                if(bullarray[i].first>=ufo1.getPosition().x && bullarray[i].first<=ufo1.getPosition().x+100 && (bullarray[i].second>=ufo1.getPosition().y-20 && bullarray[i].second<=ufo1.getPosition().y + 50)){

                    f = 1;
                    score+=5;
                    collision.setPosition(bullarray[i].first+5,bullarray[i].second+5);

                      coll3.setPosition(bullarray[i].first-4,bullarray[i].second-4);
                      bulletsound2.play();


                   for(int j=0;j<35;j++){
                   Play.draw(collision);

                   Play.display();}

                  for(int j=0;j<35;j++){
                    Play.draw(coll3);
                    Play.display();
                  }

                   ufo1.setPosition(900,rand()%500);
                   ufoX1 = 900;
                   bullarray[i].first = 2000;

                }

                if( bullarray[i].first >=800){
                    continue;
                }

                bullet.setPosition(Vector2f(bullarray[i].first, bullarray[i].second));
                bullet.move(Vector2f(2,0));
                Play.draw(bullet);

            }
             if(f == 1){
                bullarray.pop_back();

            }
        }
          Play.draw(SpriteSheet);

          if(SpriteSheet.getPosition().x + 30 >= ufo1.getPosition().x && SpriteSheet.getPosition().x - 50 <= ufo1.getPosition().x && SpriteSheet.getPosition().y+ 60 >= ufo1.getPosition().y&& SpriteSheet.getPosition().y-70 <= ufo1.getPosition().y){
                   Sprite collision(collisiontxt);
               Sprite coll2(coll2txt);
                Sprite coll3(coll3txt);
               life--;
               collision.scale(.5,.5);
               coll3.scale(.7,.7);
              collision.setPosition(ufo1.getPosition().x-20,ufo1.getPosition().y-20);

                      coll3.setPosition(ufo1.getPosition().x-40,ufo1.getPosition().y-40);

                       ufo1.setPosition(900,rand()%500);
           ufoX1 = 900;
           SpriteSheet.setPosition(0,0);
           bulletsound3.play();
             for(int j=0;j<35;j++){
                   Play.draw(collision);

                    Play.display();}

                  for(int j=0;j<35;j++){
                     Play.draw(coll3);
                    Play.display();
                  }
          }
        SpriteSheet.move(x,y);
        ufo1.move(-1,0);
       textscore.setString(scorestr+to_string(score));
       textlife.setString(lifestr+to_string(life));
       Play.draw(textscore);
        Play.draw(textlife);
        Play.display();

                       }
                   } //
                       if(x == 1)
                   {
                       while(OPTIONS.isOpen())
                       {
                           Event avent;
                           while(OPTIONS.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   OPTIONS.close();
                               }
                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       OPTIONS.close();
                                   }


                               }
                                if(Keyboard::isKeyPressed(Keyboard::Up)){
                                        if(level<3)
                                        level++;
                                    }
                                if(Keyboard::isKeyPressed(Keyboard::Down)){
                                        if(level>0)
                                        level--;
                                   }


                           }
                           Play.close();
                           OPTIONS.clear();
                           ABOUT.close();
                            OPTIONS.draw(textlevelintro);
                             textlevel.setString(levelstr+to_string(level+1));
                             OPTIONS.draw(textlevel);

                          OPTIONS.display();


                       }
                   }
                       if(x == 2)
                   {
                       while(ABOUT.isOpen())
                       {
                           Event avent;
                           while(ABOUT.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   ABOUT.close();
                               }
                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       ABOUT.close();
                                   }
                               }
                           }
                            Texture gameovertxt;
                                     gameovertxt.loadFromFile("data/images/about.jpg");
                                     Sprite gameoverspt(gameovertxt);
                                        gameoverspt.scale(0.48,0.4);
                                      gameoverspt.setPosition(5,5);
                                     ABOUT.clear();

                                      ABOUT.draw(gameoverspt);
                                      //textgameover.setString(gameoverstr);
                                      //InterFace.draw(textgameover);
                                       ABOUT.display();


                       }
                   }
                       if(x == 3)

                      MENU.close();
                      break;
                   //


                }
            }
        }

        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
        life = 3;
       //modification

}

  }//

}
