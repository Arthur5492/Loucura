#ifndef LOGIN_HPP
#define LOGIN_HPP

// #include "../Box\Box.hpp"//Pra toca musica
#include "../Register/Register.cpp"
class Login : public Box
{
  private:
    Register m_register;//Para usar Algumas funcoes do register class
    string gets_username;//username q o usuario digitar
    string gets_password;//Senha que o usuario digitar

    //Database Data
    GetAcc LoadAccount;
    vector<GetAcc> Users;//Get users data
    vector<string> m_AllUsers;
    vector<string>m_AllPass;

    void Message(string message,int color,bool talk);//Printa em um local fixo da tela, e se for fala ou nao
    void Message(string message,int color, int variation, bool talk);//Agora com variacao em x

  protected:
    //User data
    string m_Name;
    string m_Username;
    string m_password;
    int m_id;
    int m_premium;
    int m_status;

    vector<int>m_ownmusics;

    //Soundtracks
    Music *LoginMusic;
  public:
    Login(){};
    ~Login(){
      delete LoginMusic;
    }
////////////////////////////////////////////////////////////////////////////////////////////
    //Creation menu parts
    void Logo();//CRia logo

    void Username();//CRia parte do nome
    void Password();//Cria parte do password
    void LoginButton(bool selected);//Cria opcao de login
    void RegisterButton(bool selected);//CRia parte de registrar botao
    void OptionsBox();//Cria a caixa com todas as opcoes

    pair<bool,bool> SelectOption();//Para o usuario escolher entre se registrar ou logar
    void Inputs(); // Pede os cin caso o usuario escolha login


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
  ///Database
  bool LoadUsersData();
  void SelectAccount(size_t i);
  bool CheckUser();
  //Account Changes
  void Modify();
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
    //Ful created menu
    void FirstLoginScreen();
    pair<bool,bool> CompleteLogin()
    {
      LoadUsersData();//Take all users data
      system("cls");
      Logo();//Mostra logo
      Color(11);
      gotoxy(86,22);
        cout<<"Welcome to SpotCfy!! \\o/";
        OptionsBox();

              if(m_status!=1)
              {
                Message("Press enter to Select Login or Register",3,10,true);
                select->Play("from 0",800);
                pair<bool,bool> option = SelectOption();
                if (option.first==false)//Se clicou em sair
                 return make_pair(false,false);

                  else if(option.first == true && option.second==true)//Se clicou em Login e deu certo
                    return make_pair(true,true);

                      else if (option.first==true && option.second==false)//Se clicou em login e deu errado
                        return make_pair(true,false);

              return make_pair(false,false);
              }
                else
                {
                  Message("Hi :), i tought i would never see you again",3,12,true);
                  _getch();
                  stagelight->Play("from 0",800);
                  system("cls");
                  LoginMusic->Slowing("down",0);
                  delete LoginMusic;
                  return make_pair(true,true);
                }

    }
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
    //Getters
    string GetName(){return m_Name; }
    string GetUsername(){return m_Username; }
    string GetPassword(){return m_password;}
    int GetID(){return m_id; }
    int GetPremium(){return m_premium;}
    vector<int> Get_OwnMusics(){return m_ownmusics;}
    int GetStatus(){return m_status;}

    //Setters
    void TurnPremium()
    {
      m_premium=1;
      LoadAccount.Modify(m_id,m_Name,m_Username,m_password,m_premium,m_status);
    }

    void Friend()
    {
      m_status = 1;
      LoadAccount.Modify(m_id,m_Name,m_Username,m_password,m_premium,m_status);
    }

    void Gambiarra(bool stop)
    {
      Music *Credits;
      if(stop==false)
      {
      if(m_status!=1){
        Credits = new Music("soundtracks\\Credits.mp3","mp3","credits");
      }
        else{
          Credits = new Music("soundtracks\\cry.mp3","mp3","credit");
        }
        Credits->LoadMusic();
        Credits->Play("from 0",600);
      }
        else
        {
          Credits->Slowing("down",0);
          // delete Credits;
        }
    }
};
#endif
