#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<cstdlib>
#include<SDL_mixer.h>

using namespace std;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void InAnh(SDL_Window* &window, SDL_Renderer* &renderer,char s[50]);
int InDiem(SDL_Window* &window, SDL_Renderer* &renderer,char truyendiem[50], char s[50]);
int InTongDiem(SDL_Window* &window, SDL_Renderer* &renderer,char truyendiem[50]);

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 660;
const string WINDOW_TITLE = "Learning Amazing English (by Hoang Anh)";

int main(int argc, char *argv[])
{
    SDL_Rect position;
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    SDL_Event ev;


//SETUP AM THANH
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == 0;

        Mix_Chunk *correct = Mix_LoadWAV("correct.wav");

        Mix_Chunk *incorrect = Mix_LoadWAV("incorrect.wav");

        Mix_Chunk *hoanganh = Mix_LoadWAV("filelistening1.wav");

        Mix_Music *nhacnen1  = Mix_LoadMUS("NhacNen/hello.mp3");

        Mix_Music *nhacnen3someonewhere  = Mix_LoadMUS("NhacNen/nhacnen3.someonewhere.mp3");

        Mix_Music *nhacnen2sobeautiful  = Mix_LoadMUS("NhacNen/nhacnen2.sobeautiful.mp3");

        Mix_Music *nhacnen4inlove  = Mix_LoadMUS("NhacNen/nhacnen4.inlove.mp3");

        Mix_Music *nhacnen5SEP  = Mix_LoadMUS("NhacNen/nhacnen5.SEP.mp3");

    char* s[100];
    s[0] = "AnhVoi/voi.bmp";
    s[1] = "AnhVoi/voichondungA.bmp";
    s[2] = "AnhVoi/voichonsaiB.bmp";
    s[3] = "AnhVoi/voichonsaiC.bmp";
    s[4] = "AnhVoi/voichonsaiD.bmp";


    s[5] = "AnhCaSau/casau.bmp";
    s[6] = "AnhCaSau/casauchonsaiA.bmp";
    s[7] = "AnhCaSau/casauchondungB.bmp";
    s[8] = "AnhCaSau/casauchonsaiC.bmp";
    s[9] = "AnhCaSau/casauchonsaiD.bmp";

    s[10] = "ChuThua/chuthua.bmp";
    s[11] = "ChuThua/chuthuachonsaiA.bmp";
    s[12] = "ChuThua/chuthuachondungB.bmp";
    s[13] = "ChuThua/chuthuachonsaiC.bmp";
    s[14] = "ChuThua/chuthuachonsaiD.bmp";

    s[15] = "AnhRan/ran.bmp";
    s[16] = "AnhRan/ranchonsaiA.bmp";
    s[17] = "AnhRan/ranchonsaiB.bmp";
    s[18] = "AnhRan/ranchonsaiC.bmp";
    s[19] = "AnhRan/ranchondungD.bmp";

    s[20] = "AnhCho/cho.bmp";
    s[21] = "AnhCho/chochonsaiA.bmp";
    s[22] = "AnhCho/chochonsaiB.bmp";
    s[23] = "AnhCho/chochondungC.bmp";
    s[24] = "AnhCho/chochonsaiD.bmp";

    s[25] = "AnhListening1/listening1.bmp";
    s[26] = "AnhListening1/listening1chonsaiA.bmp";
    s[27] = "AnhListening1/listening1chonsaiB.bmp";
    s[28] = "AnhListening1/listening1chonsaiC.bmp";
    s[29] = "AnhListening1/listening1chondungD.bmp";

    s[30] = "AnhOng/ong.bmp";
    s[31] = "AnhOng/ongchonsaiA.bmp";
    s[32] = "AnhOng/ongchonsaiB.bmp";
    s[33] = "AnhOng/ongchondungC.bmp";
    s[34] = "AnhOng/ongchonsaiD.bmp";

    s[35] = "AnhDe/de.bmp";
    s[36] = "AnhDe/dechonsaiA.bmp";
    s[37] = "AnhDe/dechondungB.bmp";
    s[38] = "AnhDe/dechonsaiC.bmp";
    s[39] = "AnhDe/dechonsaiD.bmp";

    s[40] = "MissingWord1/missingword1.bmp";
    s[41] = "MissingWord1/missingword1chondungA.bmp";
    s[42] = "MissingWord1/missingword1chonsaiB.bmp";
    s[43] = "MissingWord1/missingword1chonsaiC.bmp";
    s[44] = "MissingWord1/missingword1chonsaiD.bmp";

    s[45] = "AnhNgua/ngua.bmp";
    s[46] = "AnhNgua/nguachondungA.bmp";
    s[47] = "AnhNgua/nguachonsaiB.bmp";
    s[48] = "AnhNgua/nguachonsaiC.bmp";
    s[49] = "AnhNgua/nguachonsaiD.bmp";

    s[50] = "Swap1/swap1.bmp";
    s[51] = "Swap1/swap1chonsaiA.bmp";
    s[52] = "Swap1/swap1chonsaiB.bmp";
    s[53] = "Swap1/swap1chonsaiC.bmp";
    s[54] = "Swap1/swap1chondungD.bmp";

    s[55] = "MissingWord2/missingword2.bmp";
    s[56] = "MissingWord2/missingword2chonsaiA.bmp";
    s[57] = "MissingWord2/missingword2chonsaiB.bmp";
    s[58] = "MissingWord2/missingword2chondungC.bmp";
    s[59] = "MissingWord2/missingword2chonsaiD.bmp";


    char* truyendiem[50];
    truyendiem[0] = "Score = 0";
    truyendiem[1] = "Scores = 100";
    truyendiem[2] = "Scores = 200";
    truyendiem[3] = "Scores = 300";
    truyendiem[4] = "Scores = 400";
    truyendiem[5] = "Scores = 500";
    truyendiem[6] = "Scores = 600";
    truyendiem[7] = "Scores = 700";
    truyendiem[8] = "Scores = 800";
    truyendiem[9] = "Scores = 900";
    truyendiem[10] = "Scores = 1000";
    truyendiem[11] = "Scores = 1100";
    truyendiem[12] = "Scores = 1200";


int dem = -1;
while (dem == -1)
{
            int temp = 0; //KHONG CHAY QUA 1 LAN VONG IF(DEM = 25) {AUTO STOPMUSIC}
            int sodiem = 0;
            {InAnh(window, renderer, "menu.bmp");}
            while(SDL_PollEvent(&ev) != 0)
            {
                    if(ev.type == SDL_QUIT)
                        {false;}
                    else if(ev.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if(ev.button.x > 645 && ev.button.x < 740 && ev.button.y > 320 && ev.button.y < 380 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {dem = 0;}
                        else if (ev.button.x > 645 && ev.button.x < 745 && ev.button.y > 210 && ev.button.y < 260 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {dem = -2;} //CHOOSE MUSIC
                        else if (ev.button.x > 610 && ev.button.x < 770 && ev.button.y > 123 && ev.button.y < 166 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {dem = -3;} //GUIDE
                        else if (ev.button.x > 590 && ev.button.x < 800 && ev.button.y > 32 && ev.button.y < 92 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {dem = -4;} //INFORMATION

                    }

            };



//MO BANG CHON NHAC
      while(dem == -2)
        {
        InAnh(window, renderer, "choosemusic.bmp");
        while(SDL_PollEvent(&ev) != 0)
            {
                    if(ev.type == SDL_QUIT)
                        {false;}
                    else if(ev.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if(ev.button.x > 290 && ev.button.x < 650 && ev.button.y > 155 && ev.button.y < 212 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {
                                Mix_PlayMusic(nhacnen1, 1);
                                dem = 0;
                        }

                        else if(ev.button.x > 290 && ev.button.x < 650 && ev.button.y > 250 && ev.button.y < 300 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {
                                Mix_PlayMusic(nhacnen2sobeautiful, -1);
                                 dem = 0;
                        }

                        else if(ev.button.x > 290 && ev.button.x < 650 && ev.button.y > 330 && ev.button.y < 380 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {
                                Mix_PlayMusic(nhacnen3someonewhere, -1);
                                 dem = 0;
                        }

                        else if(ev.button.x > 290 && ev.button.x < 650 && ev.button.y > 430 && ev.button.y < 480 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {
                               Mix_PlayMusic(nhacnen4inlove, -1);
                                dem = 0;
                        }

                         else if(ev.button.x > 290 && ev.button.x < 650 && ev.button.y > 515 && ev.button.y < 560 && ev.button.clicks == SDL_BUTTON_LEFT)
                        {
                               Mix_PlayMusic(nhacnen5SEP, -1);
                                dem = 0;
                        }
                         else if(ev.button.y > 565 && ev.button.y < 660 && ev.button.x > 0 && ev.button.x < 169 && ev.button.clicks == SDL_BUTTON_LEFT)
                         {
                             dem = -1;
                         }
                    }
            };
        };



//MO BANG HUONG DAN CHOI
    while(dem == -3)
    {
        InAnh(window, renderer, "huongdan.bmp");
        while(SDL_PollEvent(&ev) != 0)
            {
                    if(ev.type == SDL_QUIT)
                        {false;}
                    else if(ev.type == SDL_MOUSEBUTTONDOWN)
                    {
                         if(ev.button.y > 565 && ev.button.y < 660 && ev.button.x > 0 && ev.button.x < 169 && ev.button.clicks == SDL_BUTTON_LEFT)
                         {
                             dem = -1;
                         }
                    }
            };
    };



//MO BANG THONG TIN TRO CHOI
        while(dem == -4)
        {
        InAnh(window, renderer, "aboutthisamazinggame.bmp");
        while(SDL_PollEvent(&ev) != 0)
            {
                    if(ev.type == SDL_QUIT)
                        {false;}
                    else if(ev.type == SDL_MOUSEBUTTONDOWN)
                    {
                         if(ev.button.y > 565 && ev.button.y < 660 && ev.button.x > 0 && ev.button.x < 169 && ev.button.clicks == SDL_BUTTON_LEFT)
                         {
                             dem = -1;
                         }
                    }
            };
        };


//VONG WHILE THUC HIEN TRO CHOI;
while (dem == 0)
{
    //Mix_PlayMusic(menu, -1);
    //InAnh(window, renderer, s[0]);
    InDiem(window, renderer, truyendiem[0], s[0]);
    while(dem<=59)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
              if(ev.type == SDL_QUIT)
                   {false;}
              else if(ev.type == SDL_MOUSEBUTTONDOWN)
              {

                  //SELECT A
                    if(ev.button.x > 60 && ev.button.x < 378 && ev.button.y > 400 && ev.button.y < 507 && ev.button.clicks == SDL_BUTTON_LEFT)
                    {

                            if(dem == 0 || dem == 40 || dem == 45) {sodiem = sodiem + 1;}
                            InDiem(window, renderer, truyendiem[sodiem], s[dem+1]);
                 //PLAY THE SOUND "CORRECT" FOR EACH QUESTION HAVE THE ANSWER IS 'A'
                            if(!Mix_Playing(1) && dem==0 || dem == 40 || dem == 45)
                            Mix_PlayChannel(1, correct, 0);
                            SDL_Delay(400);   //DELAY TO HEAR THE SOUND

                //PLAY THE SOUND "INCORRECT" FOR QUESTIONS DOESN'T HAVE THE ANSWER IS 'A'
                             if(!Mix_Playing(1) && dem != 0 && dem != 40 && dem != 45)
                             Mix_PlayChannel(1, incorrect, 0);
                             SDL_Delay(400);
                            // Mix_HaltChannel(1);
                //OPEN THE NEXT QUESTION
                            SDL_RenderClear(renderer); //Xoa man hinh

                            dem = dem + 5;
							InDiem(window, renderer, truyendiem[sodiem], s[dem]);


                    }


                //SELECT B
                    else if(ev.button.x > 509 && ev.button.x < 829 && ev.button.y > 400 && ev.button.y < 507 && ev.button.clicks == SDL_BUTTON_LEFT)
                    {
                            if(dem == 5 || dem == 10 || dem == 35) {sodiem = sodiem + 1;}
                            InDiem(window, renderer, truyendiem[sodiem], s[dem+2]);
                //PLAY THE SOUND "CORRECT" FOR QUESTIONS HAVE THE ANSWER IS 'B'
                             if(!Mix_Playing(1) && dem == 5 || dem == 10 || dem == 35)
                             Mix_PlayChannel(1, correct, 0);
                             SDL_Delay(400);

                //PLAY THE SOUND "INCORRECT" FOR QUESTIONS DOESN'T HAVE THE ANSWER IS 'B'
                             if(!Mix_Playing(1) && dem != 5 && dem != 10 && dem != 35 )
                             Mix_PlayChannel(1, incorrect, 0);
                             SDL_Delay(400);

                             SDL_RenderClear(renderer);

                             dem = dem + 5;
                             InDiem(window, renderer, truyendiem[sodiem], s[dem]);
                    }

                //SELLECT C
                     else if(ev.button.x > 60 && ev.button.x < 378 && ev.button.y > 538 && ev.button.y < 648 && ev.button.clicks == SDL_BUTTON_LEFT)
                    {
                            if(dem == 20 || dem == 30 || dem == 55) {sodiem = sodiem + 1;}
                            InDiem(window, renderer, truyendiem[sodiem], s[dem+3]);
                //PLAY THE SOUND "CORRECT" FOR EACH QUESTION HAVE THE ANSWER IS 'C'
                             if(!Mix_Playing(1) && dem == 20 || dem == 30 || dem == 55)
                             Mix_PlayChannel(1, correct, 0);
                             SDL_Delay(400);

                //PLAY THE SOUND "INCORRECT" FOR QUESTIONS DOESN'T HAVE THE ANSWER IS 'C'
                             if(!Mix_Playing(1) && dem != 20 && dem != 30 && dem != 55)
                             Mix_PlayChannel(1, incorrect, 0);
                             SDL_Delay(400);


                             SDL_RenderClear(renderer);

                             dem = dem + 5;
                             InDiem(window, renderer, truyendiem[sodiem], s[dem]);
                    }

                 //SELLECT D
                    else if(ev.button.x > 509 && ev.button.x < 829 && ev.button.y > 538 && ev.button.y < 648 && ev.button.clicks == SDL_BUTTON_LEFT)
                    {

                            if(dem == 15 || dem == 25 || dem == 50) {sodiem = sodiem + 1;}
                            InDiem(window, renderer, truyendiem[sodiem], s[dem+4]);
                //PLAY THE SOUND "CORRECT" FOR EACH QUESTION HAVE THE ANSWER IS 'D'
                             if(!Mix_Playing(1) && dem == 15 || dem == 25 || dem == 50)
                             Mix_PlayChannel(1, correct, 0);
                             SDL_Delay(400);

                //PLAY THE SOUND "INCORRECT" FOR QUESTIONS DOESN'T HAVE THE ANSWER IS 'D'
                             if(!Mix_Playing(1) && dem != 15 && dem != 25 && dem != 50)
                             Mix_PlayChannel(1, incorrect, 0);
                             SDL_Delay(400);

                             SDL_RenderClear(renderer);

                             dem = dem + 5;
                             InDiem(window, renderer, truyendiem[sodiem], s[dem]);
                    }


                    else if(dem == 25 && ev.button.x > 450 && ev.button.x < 500 && ev.button.y > 60 && ev.button.y < 140 && ev.button.clicks == SDL_BUTTON_LEFT)
                    {
                        if(!Mix_Playing(1))
                             Mix_VolumeChunk(hoanganh,128);
                             Mix_PlayChannel(1, hoanganh, 0);

                             SDL_Delay(5000);
                             Mix_HaltChannel(1);
                    }


                     if(dem == 25 && temp == 0) {
                            Mix_PauseMusic();
                         if(!Mix_Playing(1))
                             Mix_VolumeChunk(hoanganh,128);
                             Mix_PlayChannel(1, hoanganh, 0);

                             SDL_Delay(5000);
                             Mix_HaltChannel(1);
                             temp=1;

                     }

                     if(dem != 25) {Mix_ResumeMusic();}

              }

        };
    };
};


//VONG WHILE SAU KHI KET THUC TRO CHOI DE HOI NGUOI CHOI CO MUON QUAY LAI MENU DE CHOI TIEP HAY KHONG

        while(dem>59)
        {

        while(SDL_PollEvent(&ev) != 0)
        {
              if(ev.type == SDL_QUIT)
                   {false;}
                {
                    InTongDiem(window, renderer, truyendiem[sodiem]);

                    if(ev.type == SDL_QUIT)
                        {false;}
                    else if(ev.type == SDL_MOUSEBUTTONDOWN)
                    {
                    if(ev.button.x > 410 && ev.button.x < 490 && ev.button.y > 610 && ev.button.y < 660 && ev.button.clicks == SDL_BUTTON_LEFT)
                    {
                       dem = -1;
                    }
                    else {}

                }
        }
        };
        };



};




    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_Quit();
	TTF_Quit();
    SDL_Quit();



    return 0;
}








void InAnh(SDL_Window* &window, SDL_Renderer* &renderer,char s[100])
{
        SDL_Rect position;
        position.x=0;
        position.y=0;
        position.w=900;
        position.h=660;
        SDL_Surface* surface = IMG_Load(s);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_RenderCopy(renderer, texture, NULL, &position);
        SDL_RenderPresent(renderer);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
}



void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }

}



void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == NULL)
        logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == NULL)
        logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


}



int InDiem(SDL_Window* &window, SDL_Renderer* &renderer,char truyendiem[50],char s[50]) {
if (TTF_Init() < 0) {return -1;}
InAnh(window,renderer,s);
TTF_Font*font=TTF_OpenFont("VeraMoBd.ttf",25);
SDL_Color color={83, 0, 83};
char* diem = truyendiem;
SDL_Surface*textSurface=TTF_RenderText_Solid(font,diem,color);
SDL_Texture*text=SDL_CreateTextureFromSurface(renderer,textSurface);
SDL_FreeSurface(textSurface);
SDL_Rect textRect;
textRect.x=0;
textRect.y=0;
SDL_QueryTexture(text,NULL,NULL,&textRect.w,&textRect.h);
SDL_RenderCopy(renderer,text,NULL,&textRect);
SDL_RenderPresent(renderer);
TTF_CloseFont(font);
SDL_DestroyTexture(text);
return 0;}



int InTongDiem(SDL_Window* &window, SDL_Renderer* &renderer,char truyendiem[50]) {
if (TTF_Init() < 0) {return -1;}
InAnh(window,renderer,"backtomenu.bmp");
TTF_Font*font=TTF_OpenFont("VeraMoBd.ttf",50);
SDL_Color color={0, 139, 204};
char* diem = truyendiem;
SDL_Surface*textSurface=TTF_RenderText_Solid(font,diem,color);
SDL_Texture*text=SDL_CreateTextureFromSurface(renderer,textSurface);
SDL_FreeSurface(textSurface);
SDL_Rect textRect;
textRect.x=274;
textRect.y=500;
SDL_QueryTexture(text,NULL,NULL,&textRect.w,&textRect.h);
SDL_RenderCopy(renderer,text,NULL,&textRect);
SDL_RenderPresent(renderer);
TTF_CloseFont(font);
SDL_DestroyTexture(text);
return 0;}

