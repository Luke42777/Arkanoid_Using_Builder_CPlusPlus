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
int toWin = 12;
//---------------------------------------------------------------------------
bool collision(TImage * ball,TImage * brick)
{

   if((ball->Left + ball->Width >= brick->Left)
   && (ball->Left <= brick->Left + brick->Width)
   && (ball->Top + ball->Height >= brick->Top)
   && (ball->Top <= brick->Top + brick->Height))
   {
    return true;
   }
   else
   return false;

}
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
           Button1->Caption = "You loose. Play again?";
           Button1->Visible = true;
       }


       else if( (ball->Left > paddle->Left - ball->Width/2)
       && (ball->Left < paddle->Left + paddle->Width)
       && (ball->Top + ball->Height  > paddle->Top ))
       {
           if(y > 0) y = -y;
       }
/////collisions with bricks////////////////////////////////////////////
        if(collision(ball,brick1) && brick1->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick1->Visible = false;
        }
         if(collision(ball,brick2) && brick2->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick2->Visible = false;
        }
         if(collision(ball,brick3) && brick3->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick3->Visible = false;
        }
        if(collision(ball,brick4) && brick4->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick4->Visible = false;
        }
          if(collision(ball,brick4) && brick4->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick4->Visible = false;
        }
          if(collision(ball,brick5) && brick5->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick5->Visible = false;
        }
         if(collision(ball,brick6) && brick6->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick6->Visible = false;
        }
         if(collision(ball,brick7) && brick7->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick7->Visible = false;
        }
          if(collision(ball,brick8) && brick8->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick8->Visible = false;
        }
         if(collision(ball,brick9) && brick9->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick9->Visible = false;
        }
         if(collision(ball,brick10) && brick10->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick10->Visible = false;
        }
         if(collision(ball,brick11) && brick11->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick11->Visible = false;
        }
         if(collision(ball,brick12) && brick12->Visible == true)
        {
          x = -x; // classic reflecting
          y = -y;
          toWin--;
          brick12->Visible = false;
        }

        if(toWin <= 0)
        {
          TimerBall->Enabled = false;
          ball->Visible = false;
          Button1->Caption = "You win!!! Play again?";
          Button1->Visible = true;
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


void __fastcall TForm1::Button1Click(TObject *Sender)
{
         ball->Visible = true;
        ball->Left = 50;
        ball->Top = 50;

        x = -8;
        y = -8;

        toWin = 12;
        Button1->Visible = false;
        TimerBall->Enabled = true;

        brick1->Visible = true;
        brick2->Visible = true;
        brick3->Visible = true;
        brick4->Visible = true;
        brick5->Visible = true;
        brick6->Visible = true;
        brick7->Visible = true;
        brick8->Visible = true;
        brick9->Visible = true;
        brick10->Visible = true;
        brick11->Visible = true;
        brick12->Visible = true;

}
//---------------------------------------------------------------------------

