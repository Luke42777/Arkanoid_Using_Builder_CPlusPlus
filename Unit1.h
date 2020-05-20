//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *TimerBall;
        TImage *paddle;
        TTimer *toTheLeft;
        TImage *brick1;
        TTimer *toTheRight;
        TImage *brick2;
        TImage *brick3;
        TImage *brick4;
        TImage *brick5;
        TImage *brick6;
        TImage *brick7;
        TImage *brick8;
        TImage *brick9;
        TImage *brick10;
        TImage *brick11;
        TImage *brick12;
        TButton *Button1;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall toTheLeftTimer(TObject *Sender);
        void __fastcall toTheRightTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 