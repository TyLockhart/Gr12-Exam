#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(800,600),"Exam Project");
    window.setFramerateLimit(60);
    //Declares
    vector<CircleShape> movingPixel;

    Clock c1;

    //Shapes
    movingPixel.push_back(CircleShape(1));
    movingPixel.back().setPosition(Vector2f(400,300));
    movingPixel.back().setFillColor(Color(255,255,255,255));

    movingPixel[0].setFillColor(Color::Red);
    movingPixel[0].setRadius(2);

    //Ints
    int D1=0;
    int D2=0;
    int decidingValue=0;
    int counterTimeElapsed=5;
    //
    int upCounter=0;
    int downCounter=0;
    int leftCounter=0;
    int rightCounter=0;

    //In game
    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //Movement
        decidingValue=rand()%4;

        //Up
        if(decidingValue==0)
        {
            //cout<<"Up"<<endl;
            upCounter++;
            D1=0;
            D2=5;
        }
        //Down
        if(decidingValue==1)
        {
            //cout<<"Down"<<endl;
            downCounter++;
            D1=0;
            D2=-5;
        }
        //Left
        if(decidingValue==2)
        {
            //cout<<"Left"<<endl;
            leftCounter++;
            D1=-5;
            D2=0;
        }
        //Right
        if(decidingValue==3)
        {
            //cout<<"Right"<<endl;
            rightCounter++;
            D1=5;
            D2=0;
        }

        if(c1.getElapsedTime().asSeconds()>5)
        {
            cout<<"Amount of turns after "+to_string(counterTimeElapsed)+" seconds:"<<endl;
            cout<<"Ups: "+to_string(upCounter)<<endl;
            cout<<"Downs: "+to_string(downCounter)<<endl;
            cout<<"Lefts: "+to_string(leftCounter)<<endl;
            cout<<"Rights: "+to_string(rightCounter)<<endl;
            cout<<""<<endl;
            counterTimeElapsed+=5;
            c1.restart();
        }


        //cout<<D1<<endl;
        //D2=rand()%3;

        movingPixel.push_back(CircleShape(1));
//        if(movingPixel[0].getPosition().x)
        movingPixel.back().setPosition(Vector2f(movingPixel[0].getPosition().x,movingPixel[0].getPosition().y));
        movingPixel.back().setFillColor(Color(255,255,255,255));

        movingPixel[0].move(Vector2f(D1,D2));

        //Hitting left side
        if(movingPixel.back().getPosition().x<0)
        {
            movingPixel[0].setPosition(Vector2f(799,movingPixel.back().getPosition().y));
        }
        //Hitting right side
        if(movingPixel.back().getPosition().x>800)
        {
            movingPixel[0].setPosition(Vector2f(1,movingPixel.back().getPosition().y));
        }
        //Hitting top side
        if(movingPixel.back().getPosition().y<0)
        {
            movingPixel[0].setPosition(Vector2f(movingPixel.back().getPosition().x,599));
        }
        //Hitting bottom side
        if(movingPixel.back().getPosition().y>600)
        {
            movingPixel[0].setPosition(Vector2f(movingPixel.back().getPosition().x,1));
        }


        //place pixel in mid of board, use rand()%3, if #=0, move down etc.., always get
        //position, if pos is say x800 and goes to x801, set pos to x0
        window.clear();
        for ( auto i : movingPixel)
        {
            window.draw(i);
        }
        window.display();
    }

    return 0;
}

