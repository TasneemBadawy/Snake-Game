#include <iostream>
#include <conio.h> // getting the character from console window
#include <algorithm>
#include <windows.h>
using namespace std;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT,RIGHT, UP, DOWN};
eDirection dir;
bool gameOver;
void Setup(){

       gameOver = false;
       dir = STOP;
       x = width / 2;
       y = height / 2 ;
       fruitX = rand() % width;
       fruitY = rand() % height;
     score=0;
}
void Draw(){
  system("cls");// clear console window

  system("color 0A");// change the color cmd screen

  // draw the map top wall

  for(int i=0 ; i < width + 2 ; i++){
      cout<<"#";
  }
cout<<"\n";

     // print the map
     for(int i = 0 ; i < height ; i++){

         for( int j=0 ; j < width ; j++){
              if( j==0){

                  cout<<"#";
              }
             if ( i == y && j == x){
                   cout<<"O";

                   }
             else if ( i == fruitY && j == fruitX){
                  cout<<"F";
             }

            else{
             bool print = false;
                for( int k = 0; k<nTail ; k++){
                        // print the tail

                      if( tailX[k] == j && tailY[k] == i){
                        cout<<"o";
                        print = true;
                      }

                 }
                   if(!print){
                     cout<<" ";
                   }

                }

              if (j == width - 1){
                  cout<<"#";
                  }

         }
         cout<<"\n";
     }

// draw bottom wall

for(int i=0 ; i<width + 2 ; i++){
      cout<<"#";
  }
  cout<<"\n";
   cout<<"Score: "<<score<<"\n";
}

void Input(){
      // if a character in the keyboard is bressed
      if(_kbhit()){
           switch(_getch()) {

     case 'a':
      dir = LEFT;
        break;
     case 'd' :
      dir = RIGHT;
        break;

     case 'w' :
      dir = UP;
         break;
     case 's' :
      dir = DOWN;
          break;
     case 'x' :
      gameOver = true;
      break;
      }

      }
}
void logic(){

int prevX = tailX[0], prevY = tailY[0];

int prev2X, prev2Y;

tailX[0] = x;
tailY[0] = y;

for(int i = 1; i<nTail; i++){
      prev2X = tailX[i];
      prev2Y = tailY[i];
      tailX[i] = prevX;
      tailY[i] = prevY;
      prevX = prev2X;
      prevY = prev2Y;
}

     switch(dir){

      case LEFT:
           x--;
          break;
      case RIGHT:
            x++;
            break;
      case UP:
            y--;
           break;

      case DOWN:
             y++;
            break;

      default:
            break;


        }
        // terminate if hit the wall
        if ( x > width || x < 0 || y > height || y < 0 ){
            gameOver = true ;
        }
        // terminate if the snake hits it self
        for( int i = 0 ; i< nTail ; i++){
            if(tailX[i] == x && tailY[i]==y){
                  gameOver = true;
            }
        }

        if ( x == fruitX && y== fruitY  ){

            score += 10; //inc.score
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
        }
}


int main() {
   Setup();
   while(!gameOver){

      Draw();
      Input();
      logic();
      Sleep(70); // slows the game
   }

    return 0;
}
