#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <termios.h>
#include <unistd.h>
#include "color.h"
using namespace std;
int main(int argc, char **argv)
{
  void CPrint(int bg, int ft, string str);
  bool in(string str, char num);
  std::vector<std::string> split(const std::string &str, const std::string &pattern);
  int getrandomnum(void);
  bool allletter(string s);
  int getch(void);
  if (argc > 1 && strcmp(argv[1], "--help") == 0)
  {
    cout << "Usage :" << endl;
    cout << "\t--help for help" << endl;
    cout << "\t-nohint hide hints" << endl;
    cout << R"(
                                                        ;r:                                        
                                                       T8L8@i                                      
                                   ;ii...              v@  L@8                                     
                              ;cEMbb8#8b80bOqCxsJii.   L8   :@8v         ;T,                       
                             ;@M          . .;;;iz088N,2#     L8@i     :@$@N                       
                              i@C   .               ;TG@E  ..  ,tp8J  p@;.8L                       
              i0@8@8@Msc..      pD.  ......... . .        ....    v8@8@  8#    ..,:iTUUTJti.       
            t@8#SttsIIp#8@8#q:   L8; ................ . .........  .$q  .@8iE#888@8@8#8@#b888c     
           t@8LLcJJTvTtxL,,$@8#qstbi ..........
           ...................      ;8#bRpU;:vccLcLLirTeq8@,   
           @8vLcTTsTttsr,i#pL.      ... ............................. . .tTLcvJ,issvTcTLxp#GcL8@   
           8#ILstCxzxL;;:v@8xi   . . .   ..............................  UtsTzr;LUTTJJLT#bxcLiS8C  
          ;@#uTiTcii;;;;:;NEL:  . .    L: .............................  vIsxti;ixtTvcGbpccJTrT@8  
          J8ztr:;;;;;;,;x8U    .    ;e#u ...................   ........  ;cUtt;;;rttLN@NTstTTvt8@  
          L@xu8;:;;:;J8@$;       ;#@b@L   .................  .    ..... .iix2i;ii;;:G@Jii;iiv;G@t  
          J8;.eu;;TD#Ru;      .t@8Ni#I  ;  ........... .    c8@i   ....  rirL;;i;;.T@r ,;i;i.;@8   
          U@. ;@8@8U.        x8@v..D# .#8.  ... .          S8Jq@R    ..  ;r;;;iii:i8c   ,..  q8v   
           8@8b,       .   $#8c;;:I8.L#t8i        .;.;Li;G@8ScLG@8N    . ;Liiiii;i@E .eO. ;;N8@    
           M8eLtxt:      .88ziLxEu8@8@ML8@;  ;tJzzpGCSx@8#Tcccciic88C.   ,Liiii;;8# ;Li.   J8@     
            @8  iE88@i  i8@       .;.   U8#. :@v      N8,          t@8T  .LLii;;N8. ;DDc  .8@      
            .88c  b#i. .8@G              @8@  .#;   I@i   .,,iivEIuzMCS8$ .:Li;T8;  .:#@:.8#.      
              R8@8R    :88p00DussviLiiii.v#8@. e@DS8@MiuxESpOOCCLii,  :8i   :;i#v  rDRsiT8b        
               T8M     U8N :TvI0Rb8b8#RpEi.:888#riTIq#888#M2GMDG$NMR0S#8i .   ii  .   .@8:         
              ;8; .si  8@0u8@8@8@8Dbb#b#b8R:,LT;..u8;;iLc0@8eGM#DDqRED@8@8e  .      i8@8           
             i8R;I##8. D88r     ;@;..:iTD@x,;,,:;;S@,     ;EL;:;;iLcxO80uL. ... .  .8qu#M.         
            .8@ML   @R ;#8@D;.   8@eG8@RTi;i:;iJtCJu@8@8b8R8#8@8@8bSL8#        ..LxsD8  @8#        
      ;S#Ui         ;@$x8@;cb#8#pD#NxTi,ixSzCxzTtxSi:;iLxcLiiiri;:,.;#J ci   .  .:i,.    ;8@:      
     8@8S8#8:        iuv#8i;;iivLi;::;;i;s@8@8@8eUciiiii;;;;;;;;;;;;S8$#@D;e@#L    ;ULEGEb@8T      
   .8#     #8i i8@8#8@80, .,;:...          ,;,i;:.,,:,:,,,;;iiLLcLLiTc;28#GvT#8    #8. ...         
   #@.     .@888xr.  L@8L.        .8,       :;          28   ..:,:....,;. .G@x ;i. 8@              
   i8#:    :8O:        @8#b     . ;@L...;;s$DM8#Ui:   :L8L  .              i8t;@8@8@#          xS  
  E8@8#8U. v2    .     :#8c        ,2@###Ei.   ,v0@8@8#L   ..... .         i@i    EL         T@8#8v
 S8;  .iUT,;L  ..   ,..L8@DR8p...                  .;     . .        ;z###8@8b              b@8cc@8
 #i      i;  . .. r8@8@8@8E.R8#8@8O;                   ...       is8@8@8.  ,.         cS;  ;@8crLLx
 #u       ....... S#8G;  t8:     :pR8@8Osi,          .... .:LEb88@8@8@8#8s           :8@#@888zivTTr
 i@8Dt;;.  ......  :,     @E        D8@888#8@80#R@#E. .. .IM#8#888@0xUxE@8;           @8v:t8#zLxtI;
   ;c88u    .....        c8U      M@8G2zSSGGb88@88Si        8@8@@DOSeUuC8@,           S@Ri;,LTCxzL:
     iM.            iD@8@8i    ,b8@qIuI2u2uII#Mz@8    .Tb8@8bE2IxuUuuEUG#8             8@zLc:;;i;;;
      R@@O2svi;;;iI$8@8R$@L    q8OCzSSeS2u2uuD8b8s  L0888bOSIIIIeue2ESeUD@8i            8@sctvi:;;;
     L@8N@#8@8@8$#@#IItTu8i    D#8OCzSuuCIU2Ite8@#T8@8O2ISIeSeSe2ESe2eSSxS@8;          .@8svTCxiitT
      .b8@p0puqbOzGpECOb8@p;J@8@$88#2tIG##ExUz@@8MbMSCUCIU2uE22S2uSUSUuzxe8#c         8#RccTtTzx2xc
       b#8DNpEe#RqO#@#@8DG#8#8UItSR8@0p8q8@Ix8@GTxtUzeGDMGCUzuzuzuIOEeGMOb@b        C8@RcTtttCcvii:
      :#8tzIeSNq#b$qpeSCUUuI#@qxUCUUD#88Sp8#8@8#$RpO0@#E8@R$Rb##88888@8@8@b@8v    u#8E;;LLrisiiLvc;
       .#8US2eIuUUUuU2u2S2ISCp#8GzUSTE@bJb@8SeEMp#@##8pTM8@Gq0qqOqOeSOUUUItE@8$ L8#0;i;,,;:;:;ii;;;
        8@SuE2eueSe2E2ESe2eS2CN88RuCUE8DTR88zxuUICuxI8#sz@8CxCSUuUuUuISS2u2zM@888@OiLzr;cTxLi;;;;;;
        @8IueESE2ESEeE2E2EeE2ECz$8bUzM8@tM#8pUSESeS2u8@Ss@@0C2SE2ESESE2ESEeEzub8@:,txtxUxCtUzCtItT;
        8@#IGEGONOGENOGENOGEGOO2SD88SS8@2M88#uGONEGESb8pUb88M2OOGEGOGONONOGOOIE#8N,iuCUtCtxtCtzxzUU
        ,8bzvsssTtTtTtTtTtTtTtTtccq#scMbLJDbDJvtTsssL2buitb#tTTtTtTtstTtstTsTsLE8#..,::LiLiiiLiriLi
)";
    exit(1);
  }

  string words = R"(
Earth
moon
sun
star
planet
Venus
Jupiter
Mercury
Mars
Saturn
Uranus
Neptune
Pluto
constellation
Bull
Ram
Crab
Twins
Scorpion
Lion
Balance
Virgin
Goat
Archer
Fishes
asteroid
comet
equator
galaxy
gravity
latitude
longitude
meteor
meteorite
nebula
orbit
revolution
satellite
space
spaceship
sphere
)";
  vector<string> vec = split(words, "\n");
  cout << "\033]0;Wordle  of  space\007";
  CPrint(B_BLACK, F_BLUE, R"(
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@%@@@@@@@@
@@@%@@@@@@@@@@@%@@@%%@@@@%%%@%@%@%%@%%%%%%%%%%%%%%@@@@@%%@%@
@@@@@@@@@@@@%@@%%@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
@@@@@@@@@%@%@@%@%%%%%%%%%%%%%#%%#%%#%%%##%#%#%#%%#%%%%%%%%%%
@@@@@@@@@%%%%%%%%%#%%%%%%#%%%%%###%######%######%#%#%%%%%%%%
@@@@@%%%%%%%%%%%%%%%%%%%%#%%#####*#######*#############%###%
@@@@@%%%%%%%%%%%%#%%%#%#######*##########*###*#*######%#####
@@%%%%%#%%%%%%%%%################*+++=+++==-=-**+*##*##%%%#%
%%%%%%%%%%#*%%#######*###****+++-=:=:+=-===+=.-*-=+*##%%#%+#
%%%%%%%%%##########*- =*=*+*+=-===-=--=-==+=+=+=-*=***##%%%*
%%%%%%#%#%#####*****===+++++=--:::.::--=+++===+*-*+*#%%%####
%%%%%#%%###**+****++*=+*++=-:....::---===++=**+:*#%%%#*##***
%%#%%%%##**-**===++*+=+===:..  .:-=+=-=++#**##%%####%*######
%%#%####*=+#++*++++==+--:::...:-+===+=+++=#+%##*###**#*#####
##%*#*##**+#**=+=====-=++=-:::---**++**#*####*#**#**#######%
####%%%%%%#*#*=-=**===+*-=+*++++*+*****###*#***#*#########%%
############%%##**#**##****###*****#############*#*######%%%
####***####%###%####*%#*#****####*###########*#*###%%%#%%%%%
%##*##*####%###%################*#################*%%%%%%%%%
%%#=#################**###########*#######%##%%%%#%%%%%%%%%%
%%%####################################%%%#%%%%%%%%%%%%%%%%@
%%%%%%%##%%################%%####%##%#%%%%%%%%%%%%%%%%%%%@@@
@@%%%%%%%%%#%%%*%%%%%%%%%%%%#%%%%%%%%%%#%%#%%%%%#%%@%@@%@%@@
@@%%%%%%%%%%%%%%%%%%%%%#%%%%%%%#%%%%%%%%%%%%%%@@@%@@@#@@@@@@
@@@@@@@%@@%%%%%%%%%%@%%%%%%%%%%%%%%%@%%%@@@%@%%@@@@@@@@@@@@@

                                                                              
    :EQb                 gBBBBBd                                      
   :B7BE    7.2X: vqu   BB     BL  .U5I.  .i:5X  JPr    YX5:   :2Xu.  
      Bd   vQQiJBBvrBB :B    :    iBr:7B7 gB5ibBBrrBB .BI.:BB gBr.UB  
      Bb   iB   BB   B .B   rDXBB  II1vBQ PB   B7  LB BB7YsqB  dZIY.  
      BM   7B   QB  .B  QB.    BB BB   BR ZB   BY  SB XB   vq ri  rB2 
      BP   rB   BQ  :B.  XBBBBBB: UBDdPBE PB   BL  uB  qBDQB7 7QBdQB. 
      
		[Press ENTER to continue.]
)");
  cin.get();
  system("clear");
  cout << "Let's play a game of Wordle\n";
  stringstream stream;
  int Num = getrandomnum();
  transform(vec[Num].begin(), vec[Num].end(), vec[Num].begin(), ::toupper);
  cout << "Word length:" + to_string(vec[Num].size()) << endl;
  const char *cmpstr = vec[Num].c_str();
  if (argc == 1)
  {
    for (int i = 0; i < 26; i++)
    {
      stream << (char)('A' + i);
      if (in(vec[Num], 'A' + i))
      {
        CPrint(B_GREEN, F_BLACK, stream.str());
      }
      else
      {
        CPrint(B_BLACK, F_WHITE, stream.str());
      }
      stream.clear();
      stream.str("");
    }
  }
  for (int i = 1; i < 7; ++i)
  {
    cout << endl
         << "Guess " + to_string(i) + "/6:";
    string s;
    while (s.size() != vec[Num].size())
    {
      char temp = getch();
      if (temp == 10)
      {
        if (!s.empty() && s.size() < vec[Num].size())
        {
          const int e = (vec[Num].size() - s.size());
          for (int l = 0; l != e; ++l)
          {
            s += "?";
          }
        }
        break;
      }
      // cout << '(' << (int)temp << ')';
      if (temp >= 65 && temp <= 90)
      {
        cout << temp;
        s += temp;
      }
      if (temp == 127)
      {
        if (!s.empty())
        {
          for (int ii = 0; ii != (int)s.size(); ++ii)
            cout << '\b';
          s = "";
        }
      }
    }
    if (s.empty())
    {
      i--;
      continue;
    }
    cout << endl;
    static int IsCorrect = 0;
    stream.clear();
    for (int ii = 0; ii < (int)s.size(); ++ii)
    {
      stream << s[ii];
      if (in(vec[Num], s[ii]) && s[ii] == cmpstr[ii])
      {
        CPrint(B_BLACK, F_GREEN, stream.str());
        IsCorrect++;
      }
      // else if(ii+1>vec[Num].size()){CPrint(B_RED,F_WHITE,stream.str());}
      else if ((in(vec[Num], s[ii]) && s[ii] != cmpstr[ii]))
      {
        CPrint(B_BLACK, F_YELLOW, stream.str());
      }
      else
      {
        CPrint(B_RED, F_BLACK, stream.str());
      }
      if (IsCorrect == (int)vec[Num].size())
      {
        cout << endl
             << "👀 IMPRESSIVE!";
        exit(0);
      }
      stream.clear();
      stream.str("");
    }
    IsCorrect = 0;
  }
  cout << endl
       << "❗CORRECT:" << vec[Num];
  exit(1);
}

void CPrint(int bg, int ft, string str) { cout << "\033[" + to_string(ft) + ";" + to_string(bg) + "m" + str + "\033[0m"; }
int getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}
bool in(string str, char num)
{
  stringstream s;
  s << (char)(num);
  return str.find(s.str()) == string::npos ? false : true;
}

std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
  // const char* convert to char*
  char *strc = new char[strlen(str.c_str()) + 1];
  strcpy(strc, str.c_str());
  std::vector<std::string> resultVec;
  char *tmpStr = strtok(strc, pattern.c_str());
  while (tmpStr != NULL)
  {
    resultVec.push_back(std::string(tmpStr));
    tmpStr = strtok(NULL, pattern.c_str());
  }

  delete[] strc;

  return resultVec;
}
int getrandomnum()
{
  srand((int)time(NULL));
  return rand() % 40; // 0 TO 40
}
