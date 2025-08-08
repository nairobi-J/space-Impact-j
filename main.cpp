#include <bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "MainMenu.h"
#include<fstream>
using namespace std;
using namespace sf;
int wWidth = 800 , wHeight = 600,  life = 3,level = 0,N=1,score =0,space=0,ymove=0;
vector<pair<double,double> > bullarray;
int main()
{
    // spaceship movement variable
      float x = 0;
    float y = 0;
    int k =0;

// loading images
    Texture spaceship,bg,Ufo,firebul,collisiontxt,coll2txt,coll3txt,welcometxt;
    spaceship.loadFromFile("data/images/newship.png");
     welcometxt.loadFromFile("data/images/interface.jpg");
    bg.loadFromFile("data/images/newback.jpg");
     Ufo.loadFromFile("data/images/ufo.png");
     firebul.loadFromFile("data/images/firebul.png");
     collisiontxt.loadFromFile("data/images/collision.png");
     coll2txt.loadFromFile("data/images/coll2.png");
     coll3txt.loadFromFile("data/images/coll3.png");
     firebul.setSmooth(true);
    bg.setSmooth(true);
        Sprite welcome(welcometxt);
        Sprite SpriteSheet(spaceship);
        Sprite background1(bg),background2(bg);

          Sprite bullet(firebul);
          Sprite collision(collisiontxt);
          Sprite coll3(coll3txt);
    bullet.scale(.2,.3);
    SpriteSheet.scale(.4,.4);
    background1.scale(.6,.6);
    background2.scale(.6,.6);

    Font font;
    string enterstr = "Press Enter";
    Text enter;
     enter.setFont(font);
       enter.setCharacterSize(50);
       enter.setFillColor(Color::Blue);
      enter.setStyle(Text::Bold);



       double backgroundX1 =0;
       double backgroundX2=765;

        SoundBuffer  bulletsoundbuffer,bulletsoundbuffer2,bulletsoundbuffer3;
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
    Sound bulletsound,bulletsound2,bulletsound3;
       bulletsound.setBuffer(bulletsoundbuffer);
        bulletsound2.setBuffer(bulletsoundbuffer2);
        bulletsound3.setBuffer(bulletsoundbuffer3);
 RenderWindow InterFace(VideoMode(wWidth,wHeight), "Interface");
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
                                   if(avent.key.code == Keyboard::Enter)
                                   {
                                       k = 1;
                                       InterFace.close();
                                   }
                               }
                           }
                            InterFace.clear();
                           Texture gameovertxt;
                                     gameovertxt.loadFromFile("data/images/interface.jpg");
                                     Sprite gameoverspt(gameovertxt);
                                        gameoverspt.scale(0.32,0.44);
                                      gameoverspt.setPosition(-50,0);


                                      InterFace.draw(gameoverspt);

                                      //textgameover.setString(gameoverstr);
                                      //InterFace.draw(textgameover);
                                       InterFace.display();

                       }

    RenderWindow MENU(VideoMode(wWidth,wHeight), "Space");
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    RectangleShape background;
    background.setSize(Vector2f(wWidth,wHeight));
    Texture Maintexture;
    Maintexture.loadFromFile("data/images/menuBack.jpg");
    //Sprite bg(Maintexture);
    background.setTexture(&Maintexture);
    background.setFillColor(sf::Color(100, 100, 100)); 
    

    //Texts
     string lifestr = "Life:", scorestr ="Score:",gameoverstr = "Your Score: ";

       font.loadFromFile("data/font/new.ttf");
       Text textscore, textlife,textgameover, textlevel, textlevelintro,textescape;
       textscore.setFont(font);
       textscore.setCharacterSize(30);
       textscore.setFillColor(Color::White);
       textscore.setStyle(Text::Bold);
        textscore.setString(scorestr);
        textscore.setPosition(10,550);


        textlife.setFont(font);
       textlife.setCharacterSize(30);
       textlife.setFillColor(Color::White);
       textlife.setStyle(Text::Bold);
       textlife.setString(lifestr);
        textlife.setPosition(600, 550);


        textgameover.setFont(font);
       textgameover.setCharacterSize(100);
       textgameover.setFillColor(Color::White);
       textgameover.setStyle(Text::Bold);
       textgameover.setString(gameoverstr);
        textgameover.setPosition(120, 350);

        string levelstr = "LEVEL: ";
       textlevel.setFont(font);
      textlevel.setCharacterSize(100);
       textlevel.setFillColor(Color::Blue);
       textlevel.setStyle(Text::Bold);
       textlevel.setString(levelstr);
        textlevel.setPosition(120, 200);

        string escapestr = "Press ESCAPE to Return";
       textescape.setFont(font);
      textescape.setCharacterSize(50);
       textescape.setFillColor(Color::Red);
       textescape.setStyle(Text::Bold);
      textescape.setString(escapestr);
       textescape.setPosition(160, 500);

        string levelintrostr = "Press Up or Down to Change Level";
         textlevelintro.setFont(font);
      textlevelintro.setCharacterSize(50);
       textlevelintro.setFillColor(Color::White);
       textlevelintro.setStyle(Text::Bold);
       textlevelintro.setString(levelintrostr);
        textlevelintro.setPosition(30, 10);




    while(MENU.isOpen()){
            // level generation
             if(level == 0){
            N = 1;
            ymove = 0;
            space = 0;
        }
         if(level == 1){
            N = 1;
            ymove = 1;
            space = 0;
        }
         if(level == 2){
            N = 3;
            ymove = 0;
            space = 1;
        }
         if(level == 3){
            N = 3;
            ymove = 1;
            space = 1;
        }
         float speedup = 0; // ufo speed increment
         vector<float>dir(N,0),dirval(N,0);// vertical movement detection
      vector<Sprite> ufo(N,Sprite(Ufo));// ufo generation
        vector<double>ufoX(N);// ufo horizontal position
        // ufo scale and positioning
        for(int i=0;i<N;i++){
    ufo[i].scale(.2,.2);
    ufoX[i] = 800+ space*rand()%600;
    ufo[i].setPosition( ufoX[i],200 +rand()%200);
    dir[i] = rand()%2;
    dirval[i] = rand()%150;
    }

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
                   RenderWindow Play(VideoMode(wWidth,wHeight), "SPACE__IMAPACT");
                   RenderWindow OPTIONS(VideoMode(wWidth,wHeight), "Options");
                   RenderWindow ABOUT(VideoMode(wWidth,wHeight), "About");
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
                               // gameover window
                               if(life == 0){


                                    RenderWindow GameOver(VideoMode(wWidth,wHeight), "Game Over");
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
                                      GameOver.draw(textescape);
                                       GameOver.display();



                            }
                                score = 0;//score modification
                                Play.clear();
                                Play.close();
                                bullarray.clear();

                               }


                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       Play.close();
                                   }
                               }
                               // bullet generation
                                if(Keyboard:: isKeyPressed(Keyboard::Space) ){ bulletsound.play();
                bullarray.push_back(make_pair(SpriteSheet.getPosition().x + 10,SpriteSheet.getPosition().y+16));
            }

                           }




                           OPTIONS.close();
                           ABOUT.close();
                           y = 0;
        x =0;
        // spaceship movement
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
         // new ufo
         for(int i=0;i<N;i++){
         if(ufoX[i]<-100){
          ufoX[i] = 800+ space*rand()%600;
    ufo[i].setPosition( ufoX[i],200 +rand()%200);
         }
         else{
            ufoX[i] =ufoX[i]-.7-speedup;
         }
         }
// background movement
         if(backgroundX2<0){
         backgroundX1 = 0;
         backgroundX2= backgroundX1 +765;
         }
         backgroundX1-=.2;
        backgroundX2-=.2;

        Play.clear();

         Play.draw(background2);
  Play.draw(background1);

       for(int i=0;i<N;i++){
        Play.draw(ufo[i]);
       }
       //bullet draw
  if(!bullarray.empty()){
               Sprite collision(collisiontxt);
               Sprite coll2(coll2txt);
                Sprite coll3(coll3txt);

               collision.scale(.4,.4);
               coll3.scale(.5,.5);
               int f = 0;
            for(int i=0;i<bullarray.size();i++){
                bullarray[i].first +=2;
                // bullet hit check
                for(int j=0;j<N;j++){
                if(bullarray[i].first>=ufo[j].getPosition().x && bullarray[i].first<=ufo[j].getPosition().x+100 && (bullarray[i].second>=ufo[j].getPosition().y-20 && bullarray[i].second<=ufo[j].getPosition().y + 50)){
                    score+=5;//update score
                    speedup+=.02; // speed increment
                    f = 1;
                    collision.setPosition(bullarray[i].first+5,bullarray[i].second+5);

                      coll3.setPosition(bullarray[i].first-4,bullarray[i].second-4);

                         bulletsound2.play(); // collision sound

                  // collision effect
                   for(int k=0;k<35;k++){
                   Play.draw(collision);

                   Play.display();}


                  for(int k=0;k<35;k++){
                    Play.draw(coll3);
                   Play.display();
                  }
                      ufoX[j] = 800+space*rand()%300;
                   ufo[j].setPosition( ufoX[j],200+rand()%200);

                   bullarray[i].first = 2000;
                }

                }


                if( bullarray[i].first >=800){
                    continue;
                }

                bullet.setPosition(Vector2f(bullarray[i].first, bullarray[i].second));
                bullet.move(Vector2f(2,0));
                Play.draw(bullet);

            }
            // bullet deletion
             if(f == 1){
                bullarray.pop_back();

            }
        }
          Play.draw(SpriteSheet);
// spaceship crash check
        for(int j=0;j<N;j++){
          if(SpriteSheet.getPosition().x + 30 >= ufo[j].getPosition().x && SpriteSheet.getPosition().x - 50 <= ufo[j].getPosition().x && SpriteSheet.getPosition().y+ 60 >= ufo[j].getPosition().y&& SpriteSheet.getPosition().y-70 <= ufo[j].getPosition().y){
                   Sprite collision(collisiontxt);

                Sprite coll3(coll3txt);

                life--;// life update
               collision.scale(.5,.5);
               coll3.scale(.7,.7);
              collision.setPosition(ufo[j].getPosition().x-20,ufo[j].getPosition().y-20);

                      coll3.setPosition(ufo[j].getPosition().x-40,ufo[j].getPosition().y-40);
                      // new ufo
                      ufoX[j] = 800+ space*rand()%600;
                     ufo[j].setPosition( ufoX[j],200 +rand()%200);
            // newspaceship
           SpriteSheet.setPosition(0,0);
           bulletsound3.play();
             // collision effect
             for(int k=0;k<35;k++){
                   Play.draw(collision);

                   Play.display();}

                  for(int k=0;k<35;k++){
                   Play.draw(coll3);
                   Play.display();
                  }
          }
        }
        SpriteSheet.move(x,y);
        for(int i=0;i<N;i++){
                if(ymove == 1){
        if(dir[i] == 0){
        ufo[i].move(-.7-speedup,1);
        dirval[i]++;
        if(dirval[i] >= 150){
            dir[i] = 1;

        }
        }
        else{
             ufo[i].move(-.7-speedup,-1);
             dirval[i]--;
             if(dirval[i] <= 0){
                dir[i] = 0;
             }
        }
                }
                else{
                       ufo[i].move(-.7-speedup,0);
                }
        }
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
                              OPTIONS.draw(textescape);

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
                            Play.close();
                           OPTIONS.clear();
                           Texture gameovertxt;
                                     gameovertxt.loadFromFile("data/images/about.jpg");
                                     Sprite gameoverspt(gameovertxt);
                                        gameoverspt.scale(.63,.62);
                                      gameoverspt.setPosition(0,0);
                                     ABOUT.clear();

                                      ABOUT.draw(gameoverspt);
                                      textescape.setPosition(150,50);
                                        textescape.setCharacterSize(30);
                                       ABOUT.draw(textescape);
                                      textgameover.setString(gameoverstr);
                                      InterFace.draw(textgameover);
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


}