//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;    //8 positions left
int y = -8;; // 8 positions up
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
       ball->Left += x;
       ball->Top += y;
       //reflect from left wall

       if(ball->Left  <= background->Left)
       {
        x = -x;
       }

        //refelct from top wall
       if(ball->Top  <= background->Top)
       {
        y = -y;
       }

       //reflect from right wall
       if(ball->Left + ball->Width >= background->Width)
       {
        x = -x;
       }



}
//---------------------------------------------------------------------------
