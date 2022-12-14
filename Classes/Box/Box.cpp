#include "Box.hpp"

void Box::gotoxy(int x,int y){//Poder escolher onde colocar o cursor do cmd
  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/////////////////////////////////////////////////////////////////////////
void Box::LineOfLines(int n)//Faz as ponta da Box
{
  for(int i=1;i<=n;i++)
  {
    printf("_");
  }
}
/////////////////////////////////////////////////////////////////////////
void Box::MakeBox(int x,int y,int tall,int wdt)//Criar o Box
{
    gotoxy(x,y);//Onde vai começar o risco de cima da Box
    LineOfLines(wdt);//Cria o risco de cima
    gotoxy(x,y+tall);//Onde começa o risco de baixo
    LineOfLines(wdt);//Risco de baixo
    for(int i=0;i<tall;i++)//Pra criar os lados
    {
      gotoxy(x-1,y+1+i);
      cout<<"|";
    }

    for(int i=0;i<tall;i++)
    {
        gotoxy(x+wdt,y+1+i);
        cout<<"|";
    }
}
/////////////////////////////////////////////////////////////////////////
void Box::MakeASCII(string Filename, int x, int y)//Colocas os ASCII
{
  Filename = "Marcel/textos/"+Filename;
  ifstream ascii(Filename);// Abre o arquivo começando pela pasta textos

    if(ascii.good())//Se deu certo abrir o arquivo
    {
      string tmp;//string temporaria
      while(getline(ascii,tmp))//Vasculha cada linha e guarda na string
      {
        gotoxy(x,y);//Vai pra posicao informada
        cout<<tmp;//Da cout da string
        y++;//Aumenta a linha
      }
    } else cout<<"Could not find "<<Filename<<" Path";//Se nao for possivel achar o arquivo
  ascii.close();
}
////////////////////////////////////////////////////////////////////////////////////////////
void Box::Wait(int milliseconds)
{
  this_thread::sleep_for(chrono::milliseconds(milliseconds));
}
////////////////////////////////////////////////////////////////////////////////////////////
int Box::SafeCin(string title, int color, int i, int x,int y)//SafeCin for int
{
  gotoxy(x,y);
  cout<<"                              ";
  gotoxy(x,y); //Go to where you want do cin
  Color(color);
  cout<<title;
  Color(7);
  cin >>i;
    return i;
}
string Box::SafeCin(string title, int color, string input,int x, int y)
{
  SafeStringCinRepeat://If user press enter without puttin a word repeat
  gotoxy(x,y);//Go to button position
  cout<<"                              ";//Erase
  gotoxy(x,y);//Go again
  Color(color);//Change Color
  cout<<title;//Cout the title
  Color(7);//Back to normal color
  input="s";
    while(getline(cin,input))
    {
      if(input!="")break;
        else goto SafeStringCinRepeat;//If user press enter without puttin a word repeat
    }
  return input;
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Box::Talk(string Text)
{
  for(size_t i=0;i<Text.size();i++)
  {
    if(_kbhit())
    {
      cout<<Text.at(i);
      continue;
    }
    cout<<Text.at(i);
    if(Text.at(i)=='.' || Text.at(i)==',')
    Wait(500);
      else
      {
        Wait(10);
        talk->Play("from 0",1000);
        Wait(10);
      }
  }
}
void Box::Talk(string Text,int milliseconds)
{
  for(size_t i=0;i<Text.size();i++)
  {
    cout<<Text.at(i);
    talk->Play("from 0",1000);
    Wait(milliseconds);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
///Music Part
// void Box::Play(string Name, string Playtype, int startvolume,string FormatType)
// {
//   char UserPath[MAX_PATH];
//   GetCurrentDirectoryA(MAX_PATH, UserPath);///Get User Path
//   string Path = UserPath;
//   ///Open the Sound
//   if (FormatType =="mp3")
//     FormatType=" mpegvideo ";
//       else FormatType=" waveaudio ";
//   string open = "open C:\\Users\\arthu\\Documents\\BluePen\\Loucura\\Marcel\\sounds\\"+Name+ " type"+FormatType+"alias "+Name;//Set open mp3 name
//   mciSendString(open.c_str(),NULL,0,NULL);
//
//   //Volumes
//   string volume = "setaudio "+ Name + " volume to "+to_string(startvolume);
//   mciSendString(volume.c_str(), NULL, 0, NULL);
//
//   //Play
//   string play = "play " +Name+ " "+Playtype;//Set play mp3 name
//   mciSendString(play.c_str(), NULL, 0, NULL);//Play the mp3
//
//   // cout<<play<<endl;
// }
// ////////////////////////////////////////////////////////////////////////////////////////////
// void Box::PlayFunction(string Name,string Function)
// {
//   Function =Function+" ";
//   string All = Function + Name;
//   // cout<<All<<endl;
//   mciSendString(All.c_str(), NULL, 0, NULL);
// }
// ////////////////////////////////////////////////////////////////////////////////////////////
// int Box::Volume(string Name, bool updown,size_t atual)
// {
//   if(updown == true)
//   {
//     if(atual<1000)
//       atual+=100;
//     else cout<<"Max value achieved"<<endl;
//   }
//     if(updown==false)
//     {
//       if(atual>0)
//         atual-=100;
//           else cout<<"Min value achieved"<<endl;
//     }
//     string newvalue = "setaudio " + Name + " volume to "+to_string(atual);
//       mciSendString(newvalue.c_str(), NULL, 0, NULL);
//       // cout<<newvalue<<endl;
//       return atual;
// }
// ////////////////////////////////////////////////////////////////////////////////////////////
// // int Box::CalmStop(string Name)
// // {
// //
// // }
