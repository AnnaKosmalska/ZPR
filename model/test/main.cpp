

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../Board.hpp"


using namespace std;
class Test
{
public:
  void test_board_initGame(int x, int y)
  {
    try
      {
	cout<<"zainicjowanie planszy:\n";
	cout<<Board::getInstance().initGame(x,y)<<endl;
      }
    catch(BaseException& e)
      {
	cout<<"BLAD!\n";
      }
  }
  void test_board_addPlayer(int number)
  {
    try
      {
	for(int i=0; i<number;++i)
	  {
	    cout<<"dodaje gracza o imieniu <<test01>>:\n";
	    cout<<"id gracza: "<<Board::getInstance().addPlayer("test01")<<endl;
	    cout<<"imie gracza: "<<Board::getInstance().getName(0)<<endl;
	  }      
      }
    catch(BaseException& e)
      {
	cout<<"BLAD!\n";
      }
  }
  void test_board(int x, int y)
  {
    try
      {
	for(int i=0; i<y; ++i)
	  {
	    for(int j=0; j<x; ++j)
	      {
		cout<<Board::getInstance().getTile(j,i)<<"\t";
	      }
	    cout<<endl<<endl;
	  }
      }
    catch(BaseException& e)
      {
	cout<<"BLAD!\n";
      }
  }
  void test_board_endTurn()
  {
    cout<<"tura gracza 0: ";
    cout<<Board::getInstance().getCurrentPlayer();
    cout<<"\ntura gracza 1: ";
    Board::getInstance().endTurn();
    cout<<Board::getInstance().getCurrentPlayer();
    cout<<"\ntura gracza 2: ";
    Board::getInstance().endTurn();
    cout<<Board::getInstance().getCurrentPlayer();
    cout<<"\ntura gracza 0: ";
    Board::getInstance().endTurn();
    cout<<Board::getInstance().getCurrentPlayer()<<endl;
  }
  void test_board_choose()
  {
    cout<<"(2,3): "<<Board::getInstance().choose(Board::getInstance().getCurrentPlayer(),2,3)<<endl;
    cout<<"(0,2): "<<Board::getInstance().choose(Board::getInstance().getCurrentPlayer(),0,2)<<endl;
    cout<<"pierwsza wybrana: "<<Board::getInstance().getFirstPicked();
    cout<<"\ndruga wybrana: "<<Board::getInstance().getSecondPicked()<<endl;
  }
  void test_board_choose(int x, int y)
  {
    try
      {
	cout<<"("<<x<<","<<y<<"): "<<Board::getInstance().choose(Board::getInstance().getCurrentPlayer(),x,y)<<endl;
      }
    catch(BaseException& e)
      {
	cout<<"BLAD!\n";
      }
  }

};

int main()
{
  Test test;
  cout<<"testuje klase Board\n\n";
  test.test_board_initGame(6,5);
  cout<<"dodanie przepisowej liczby graczy\n";
  test.test_board_addPlayer(3);
  cout<<"test planszy\n";
  test.test_board(6,5);
  cout<<"test konczenia tury\n";
  test.test_board_endTurn();
  cout<<"test wybierania\n";
  test.test_board_choose();
  cout<<"koniec gry, inicjacja kolejnej\n";
  Board::getInstance().endGame();
  test.test_board_initGame(3,6);
  cout<<"test planszy\n";
  test.test_board(3,6);
  cout<<"dodanie nieprzepisowej liczby graczy\n";
  test.test_board_addPlayer(5);
  cout<<"wybranie karty spoza zakresu: ";
  test.test_board_choose(5,7);
    
}
