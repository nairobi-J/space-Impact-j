#include <bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<fstream>
using namespace std;
using namespace sf;
int wWidth = 800 , wHeight = 600;
vector<pair<double,double> > bullarray;
int main()
{
    float x = 0;
    float y = 0;
    RenderWindow Window(VideoMode(wWidth,wHeight), "Space");
    Texture spaceship,bg,Ufo,firebul,collisiontxt,coll2txt,coll3txt;
    spaceship.loadFromFile("data/images/newship.png");
    bg.loadFromFile("data/images/newback.jpg");
     Ufo.loadFromFile("data/images/ufo.png");
     firebul.loadFromFile("data/images/firebul.png");
     //collisiontxt.loadFromFile("data/images/collision.png");
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
       Music music;
       SoundBuffer  bulletsoundbuffer,bulletsoundbuffer2,bulletsoundbuffer3,bulletsoundbuffer4;
       if(!music.openFromFile("ryuk.ogg"));
       {
           cout<<"BULLET";
       }

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

       Sound bulletsound,bulletsound2,bulletsound3,bulletsound4;
       bulletsound4.setBuffer(bulletsoundbuffer4);
       bulletsound.setBuffer(bulletsoundbuffer);
        bulletsound2.setBuffer(bulletsoundbuffer2);
        bulletsound3.setBuffer(bulletsoundbuffer3);


   Clock cloack;
    while(Window.isOpen()){
        Event event;

        while(Window.pollEvent(event)){
               // music.play();


            if(event.type == Event::Closed){
                Window.close();
            }
             if(Keyboard:: isKeyPressed(Keyboard::Space) ){
                bulletsound.play();
                bullarray.push_back(make_pair(SpriteSheet.getPosition().x + 10,SpriteSheet.getPosition().y+16));
            }
        }


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
        /*  if(ufoX2<-100){
            ufoX2 = 1000;
           ufo2.setPosition(ufoX2,rand()%500);

         }
         else{
            ufoX2 -=1;
         }
         if(ufoX3<-100){
            ufoX3 =  1200;
           ufo3.setPosition(ufoX3,rand()%500);

         }
         else{
            ufoX3-=1;
         }*/
         if(backgroundX2<0){
         backgroundX1 = 0;
         backgroundX2= backgroundX1 +765;
         }
         backgroundX1-=.2;
        backgroundX2-=.2;

        Window.clear();

         Window.draw(background2);
  Window.draw(background1);

       Window.draw(ufo1);
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
                    collision.setPosition(bullarray[i].first+5,bullarray[i].second+5);
                     coll2.setPosition(bullarray[i].first+5,bullarray[i].second+5);
                      coll3.setPosition(bullarray[i].first-4,bullarray[i].second-4);

                    bulletsound2.play();
                   for(int j=0;j<35;j++){
                   Window.draw(collision);


                   Window.display();}
                    /* for(int j=0;j<20;j++){
                  Window.draw(coll2);
                   Window.display();
                     }*/
                  for(int j=0;j<35;j++){
                    Window.draw(coll3);

                   Window.display();
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
                Window.draw(bullet);

            }
             if(f == 1){
                bullarray.pop_back();

            }
        }
          Window.draw(SpriteSheet);

          if(SpriteSheet.getPosition().x + 30 >= ufo1.getPosition().x && SpriteSheet.getPosition().x - 50 <= ufo1.getPosition().x && SpriteSheet.getPosition().y+ 60 >= ufo1.getPosition().y&& SpriteSheet.getPosition().y-70 <= ufo1.getPosition().y){
                   Sprite collision(collisiontxt);
               Sprite coll2(coll2txt);
                Sprite coll3(coll3txt);

               collision.scale(.5,.5);
               coll3.scale(.7,.7);
              collision.setPosition(ufo1.getPosition().x-20,ufo1.getPosition().y-20);

                      coll3.setPosition(ufo1.getPosition().x-40,ufo1.getPosition().y-40);

                       ufo1.setPosition(900,rand()%500);
           ufoX1 = 900;
           SpriteSheet.setPosition(0,0);
           bulletsound3.play();
             for(int j=0;j<35;j++){
                   Window.draw(collision);

                   Window.display();}

                  for(int j=0;j<35;j++){
                    Window.draw(coll3);

                   Window.display();
                  }
          }
        SpriteSheet.move(x,y);
        ufo1.move(-1,0);
        //ufo2.move(-1,0);
       // ufo3.move(-1,0);

        Window.display();

    }

}