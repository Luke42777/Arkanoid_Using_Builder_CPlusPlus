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
       //loose    condition
       if(ball->Top  >=  paddle->Top + 15)
       {
           TimerBall->Enabled = false; // turn of timer
           ball->Visible = false; //hide ball
       }
       else if( (ball->Left > paddle->Left - ball->Width/2)
       && (ball->Left < paddle->Left + paddle->Width)
       && (ball->Top + ball->Height  > paddle->Top ))
       {
           if(y > 0) y = -y;
       }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::toTheLeftTimer(TObject *Sender)
{
        if(paddle->Left > 10)
        paddle->Left  -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::toTheRightTimer(TObject *Sender)
{
        if((paddle->Left + paddle->Width) < (background->Width - 10))
        paddle->Left  += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT)
        {
          toTheLeft->Enabled = true;
        }
        if(Key == VK_RIGHT)
        {
          toTheRight->Enabled = true;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT)
        {
            toTheLeft->Enabled = false;
        }
        if(Key == VK_RIGHT)
        {
         toTheRight->Enabled = false;

        }

}
//---------------------------------------------------------------------------

