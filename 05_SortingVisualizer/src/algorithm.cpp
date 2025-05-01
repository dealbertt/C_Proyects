#include <SDL3/SDL_error.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_surface.h>
#include <chrono>
#include <iostream>
#include "../header/algorithm.hpp"
#include "../header/config.hpp"
#include "../header/keyboard.hpp"

#include <mutex>
#include <random>
#include <csignal>


#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_render.h>
#include <string>
#include <thread>

//All the class functions

int Algorithm :: swapElements(std::vector<array_member>&vector, int member1, int member2, SDL_Window *window, SDL_Renderer *renderer){
    int aux[3];

    //clearValueColumn(window, renderer, vector[member1]);
    //clearValueColumn(window, renderer, vector[member2]);
    //reDrawScreen(renderer, vector, member1);

    aux[0] = vector[member1].value;
    aux[1] = vector[member1].rect.y;
    aux[2] = vector[member1].rect.h;

    vector[member1].value = vector[member2].value;
    vector[member1].rect.y = vector[member2].rect.y;
    vector[member1].rect.h = vector[member2].rect.h;

    vector[member2].value = aux[0];
    vector[member2].rect.y= aux[1];
    vector[member2].rect.h= aux[2];


    //updateValueColumn(window, renderer, vector[member1]);
    //updateValueColumn(window, renderer, vector[member2]);
    //reDrawScreen(renderer, vector, member2);

    return 0;
}

int BubbleSort :: SortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer){
    static int i = 0;
    static int j = 0;
    int size = static_cast<int>(vector.size());
    
    if(i == size - 1){
        i = 0;
        j = 0;
        return -2;
    }else{
        if(j >= size - i - 1){
            i++;
            j = 0;
        }

        if(vector[j].value > vector[j + 1].value){
            swapElements(vector, j, j + 1, window, renderer);
            arrayAccesses += 3;
            comparisons++;
        }
        j++;
        return j;
        
    }
    /*
    for(int i = 0; i < (int)vector.size(); i++){
        
        for(int j = 0; j < (int)vector.size() - 1; j++){

            highlightValue(window, renderer, vector[j]);

            if(vector[j].value > vector[j + 1].value){

                swapElements(vector, j, j + 1, window, renderer);
                //accesses += 3;
            }
            //accesses += 2;
        }
    }
    */
    return 0;
}

void BubbleSort :: SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer){
    for(int i = 0; i < (int)array.size(); i++){
        for(int j = 0; j < (int)array.size() - 1; j++){
            mtx.lock();
            if(array[j].value > array[j + 1].value){
                /*
                array_member aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                */
                swapElements(array, j, j + 1, window, renderer);
                arrayAccesses += 3;
            }
            comparisons ++;
            arrayAccesses += 2;
            this->index = j;
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::microseconds(50));
        }

    }
    std::cout << "Bubble Sort finished sorting" << std::endl;
    this->finished = true;

    return;
}

void SelectionSort :: SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer){
    int size = array.size();

    for(int i = 0; i < size - 1; i++){
        int min = i;

        for(int j = i + 1; j < size; j++){
            //highlightValue(window, renderer, array[j]);
            if(array[j].value < array[min].value){
                min = j;
            }
            this->index = j;
        }
        //swap the ith value for the min value
        mtx.lock();
        swapElements(array, i, min, window, renderer);
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::microseconds(5000));
        /*
        array_member aux = array[i];
        array[i] = array[min];
        array[min] = aux;
        */
    }
    this->finished = true;

    return;
}
int SelectionSort :: SortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer){
    static int i = 0;
    static int j = 0;
    static int min = i;
    int size = static_cast<int>(vector.size());

    //checking if i can go inside of the first for loop
    if(i == size - 1){
        i = 0;
        j = 0;
        min = i;
        return -2;
        //i cant, meaning i have completed the sorting, so i return -1 to indicate so;
    }
    //i can go inside of the first for loop
    //i assign min to i;

    //then i declare the value of j, to go inside of the second for loop
    //j = i + 1;
    if(j < size){
        //this means it can go inside of the second for loop
        if(vector[j].value < vector[min].value){
            min = j;
        }
        arrayAccesses+=2;
        comparisons++;
        j++;
        return j;
    }else{
        //this means that j > size, so i have to increment i and iterate again the first for loop
        swapElements(vector, i, min, window, renderer);
        arrayAccesses+=4;
        j = i + 1;
        i++;
        min = i;
        return j;
    }
    /*
    auto a = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size - 1; i++){
        int min = i;
            for(int j = i + 1; j < size; j++){
            highlightValue(window, renderer, vector[j]);
            if(vector[j].value < vector[min].value){
                min = j;
            }
        }
        //swap the ith value for the min value
        swapElements(vector, i, min, window, renderer);
    }

    auto b = std::chrono::high_resolution_clock::now();

    std::cout << "Sorting took: " << std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count() << " seconds" << std::endl;
    */

    return 0;
}
void InsertionSort :: SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer){
    int size = array.size();
    for (int i = 1; i < size; i++) {
        array_member key = array[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && array[j].value > key.value) {
            //array[j + 1] = array[j];
            mtx.lock();
            assignNewElement(array, array[j + 1], array[j], window, renderer);
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::microseconds(250));
            j = j - 1;
        }
        //array[j + 1] = key;
        mtx.lock();
        assignNewElement(array, array[j + 1], key, window, renderer);
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::microseconds(250));
    }

    std::cout << "Insertion Sort done" << std::endl;
    this->finished = true;
    return;
}
int InsertionSort :: SortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer){
    static int i = 1;
    static int j = i - 1;
    static array_member key = {0};

    int size = static_cast<int>(vector.size());

    if(i >= size){
        i = 1;
        j = i - 1;
        return -2; //Indicating the end
    }

    if(j == i - 1){
        key.value = vector[i].value;
        key.rect.y = vector[i].rect.y;
        key.rect.h = vector[i].rect.h;
        arrayAccesses++;
    }

    if(j >= 0 && vector[j].value > key.value){
        assignNewElement(vector, vector[j + 1], vector[j], window, renderer);
        j = j - 1;
        comparisons ++;
        arrayAccesses += 3;
        return j;
    }

    assignNewElement(vector, vector[j + 1], key, window, renderer);
    arrayAccesses++;

    i++;
    j = i - 1;

    return j;
    /*
       for (int i = 1; i < n; ++i) {
       int key = arr[i];
       int j = i - 1;

       Move elements of arr[0..i-1], that are
       greater than key, to one position ahead
       of their current position 
       while (j >= 0 && arr[j] > key) {
       arr[j + 1] = arr[j];
       j = j - 1;
       }
       arr[j + 1] = key;
       }
    */
}

int InsertionSort :: assignNewElement(std::vector<array_member>&vector, array_member &member1, array_member &member2, SDL_Window *window, SDL_Renderer *renderer){
    clearValueColumn(window, renderer, member1);

    member1.value = member2.value;
    member1.rect.y = member2.rect.y;
    member1.rect.h = member2.rect.h;

    updateValueColumn(window, renderer, member1);
    return 0;
}

int Algorithm :: loop(SDL_Window *window, SDL_Renderer *renderer, std::vector<array_member> &vector, Uint32 &lastFrameTime){
    this->finished = false;
    bool running = true;
    bool stop = false;

    int index = 0;

    std::cout << "Now sorting with: " << this->getName() << std::endl;
    std::thread sortThread(&Algorithm::SortThread, this, std::ref(vector), window, renderer); 
    while(running){
        //bubbleSort(vector, window, renderer);
        /*

        handleKeyboard(stop);
        if(!stop){
            index = this->SortStep(vector, window, renderer);
        }
        //visualizeArray(renderer, array);

        if(index == -2){ //Vector is sorted
            running = false;
            this->setFinished(true);
        }
        */
        handleKeyboard(stop, sortThread);
        reDrawScreen(renderer, vector, index, lastFrameTime, *this); 
        if(this->finished){
            break;
        }
        //float deltaTime;
    }
    this->showSortedArray(vector, window, renderer, lastFrameTime);
    sortThread.join();
    return 0;
}


int Algorithm :: displayText(SDL_Renderer *renderer){
    int fontSize = 40;
    SDL_Color textColor = {255, 255, 255, 255};
    std::string fontPath = "fonts/FiraCodeNerdFont-Regular.ttf";

    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);

    if(font == NULL){
        std::cout << "Failed to load the font!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::string strComparisons = "Comparisons: " +  std::to_string(getComparisons());
    std::string strAccesses = "Array Accesses: " + std::to_string(getAccesses());
    std::string strName= getName();
    std::string strElements = "Number of elements in array: " + std::to_string(vector.size());
    
    SDL_Surface *surfaceName = TTF_RenderText_Solid(font, strName.c_str(), strName.length(), textColor);
    if(surfaceName == NULL){
        std::cout << "Failed to create the surfaceName!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_Texture *NameMessage = SDL_CreateTextureFromSurface(renderer, surfaceName); 
    if(NameMessage == NULL){
        std::cout << "Failed to create the NameMessage!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    
    SDL_FRect NameRect; //create a rect
    NameRect.x = 0; // controls the rect's y coordinte
    NameRect.y = 0; // controls the rect's y coordinte
    NameRect.w = 250;
    NameRect.h = 50;

    SDL_Surface *surfaceComparisons = TTF_RenderText_Solid(font, strComparisons.c_str(), strComparisons.length(), textColor);
    if(surfaceComparisons == NULL){
        std::cout << "Failed to create the surfaceMessage!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_Texture *ComparisonsMessage = SDL_CreateTextureFromSurface(renderer, surfaceComparisons); 
    if(ComparisonsMessage == NULL){
        std::cout << "Failed to create the Message!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    
    SDL_FRect ComparisonsRect; //create a rect
    ComparisonsRect.x = 300; // controls the rect's y coordinte
    ComparisonsRect.y = 0; // controls the rect's y coordinte
    ComparisonsRect.w = 250;
    ComparisonsRect.h = 50;

    SDL_Surface *surfaceAccesses = TTF_RenderText_Solid(font, strAccesses.c_str(), strAccesses.length(), textColor);
    if(surfaceAccesses == NULL){
        std::cout << "Failed to create the surfaceAccesses!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_Texture *AccessesMessage = SDL_CreateTextureFromSurface(renderer, surfaceAccesses); 
        if(AccessesMessage == NULL){
        std::cout << "Failed to create the Message!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    
    SDL_FRect AccessesRect; //create a rect
    AccessesRect.x = 600; // controls the rect's y coordinte
    AccessesRect.y = 0; // controls the rect's y coordinte
    AccessesRect.w = 250;
    AccessesRect.h = 50;


    SDL_Surface *surfaceElements = TTF_RenderText_Solid(font, strElements.c_str(), strElements.length(), textColor);
    if(surfaceElements == NULL){
        std::cout << "Failed to create the surfaceElements!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_Texture *ElementsMessage = SDL_CreateTextureFromSurface(renderer, surfaceElements); 
    if(ElementsMessage == NULL){
        std::cout << "Failed to create the Message!" << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    
    SDL_FRect ElementsRect; //create a rect
    ElementsRect.x = 900; // controls the rect's y coordinte
    ElementsRect.y = 0; // controls the rect's y coordinte
    ElementsRect.w = 450;
    ElementsRect.h = 50;

    SDL_RenderTexture(renderer, NameMessage, NULL, &NameRect);
    SDL_RenderTexture(renderer, ComparisonsMessage, NULL, &ComparisonsRect);
    SDL_RenderTexture(renderer, AccessesMessage, NULL, &AccessesRect);
    SDL_RenderTexture(renderer, ElementsMessage, NULL, &ElementsRect);

    SDL_DestroyTexture(ComparisonsMessage);
    SDL_DestroySurface(surfaceComparisons);

    SDL_DestroyTexture(NameMessage);
    SDL_DestroySurface(surfaceName);

    SDL_DestroyTexture(AccessesMessage);
    SDL_DestroySurface(surfaceAccesses);

    SDL_DestroyTexture(ElementsMessage);
    SDL_DestroySurface(surfaceElements);

    TTF_CloseFont(font);
    return 0;
}

//All the  "array manipulation" functions
extern Config *config;

std::random_device rd;  // Seed for the random number engine
std::mt19937 gen(rd()); // Mersenne Twister PRNG

int Algorithm :: initializeArray(SDL_Window *window, SDL_Renderer *renderer, std::vector<array_member> &vector, Uint32 &lastFrameTime){

    std::vector<SDL_FRect> rectsToRender;
    rectsToRender.resize(vector.size());

    vector.clear();
    vector.resize(this->amount);

    std::uniform_int_distribution<int> dist(1, config->windowHeigth - 100); // Generates 0 or 1

    float x = 0.0f;

    int width = config->windowWidth / this->amount;
    std::cout << "Optimum width i guess: " << width << std::endl;


    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i = 0; i < (int)vector.size(); i++){
        int guess = dist(gen);
        vector[i].value = guess;
        vector[i].rect  = {x, (float)config->windowHeigth - guess, (float)width, (float)guess};
        vector[i].color = {255, 255, 255, 255};

        rectsToRender.push_back(vector[i].rect);


        reDrawScreen(renderer, vector, i, lastFrameTime, *this);

        //SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFFFFFF);

        x += (width);
    }
    SDL_RenderFillRects(renderer, rectsToRender.data(), rectsToRender.size());

    std::cout << "Vector initialized Correctly" << std::endl;


    return 0;
}

int Algorithm :: visualizeArray(SDL_Renderer *renderer, std::vector<array_member> &array){
    mtx.lock(); 
    //reDrawScreen(renderer, array, 0, Uint32 &lastFrameTime, this);
    mtx.unlock();
    return 0;
}

int highlightValue(SDL_Window *window, SDL_Renderer *renderer, array_member value){
    //SDL_FillSurfaceRect(surface, &value.rect, 0xFFFF0000);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &value.rect);
    //SDL_UpdateWindowSurface(window);

    //SDL_FillSurfaceRect(surface, &value.rect, 0xFFFFFFFF);
    //SDL_UpdateWindowSurface(window);
    
    return 0;
}

int updateValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value){

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &value.rect);

    //SDL_FillSurfaceRect(surface, &value.rect, 0xFFFFFFFF);
    //SDL_UpdateWindowSurface(window);

    return 0;
}

int clearValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &value.rect);

    //SDL_FillSurfaceRect(surface, &value.rect, 0x00000000);

    return 0;
}


int Algorithm :: showSortedArray(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer, Uint32 &lastFrameTime){
    int size = (int)vector.size();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int i = 0; i < size; i++){
        //SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFF0000);
        //SDL_UpdateWindowSurface(window);
        vector[i].color.g = 0;
        vector[i].color.b = 0;
        reDrawScreen(renderer,vector, i, lastFrameTime, *this);
    }

    std::cout << "Array of size: " << size << " sorted!" << std::endl;
    std::cout << "Total comparisons: " << comparisons <<  std::endl;
    std::cout << "Total array Accesses: " << arrayAccesses <<  std::endl;
    return 0;
}

float reDrawScreen(SDL_Renderer *renderer, std::vector<array_member> &vector, int index, Uint32 &lastFrameTime, Algorithm &algoritm){


    Uint32 frameStart = SDL_GetTicks();
    float deltaTime = (frameStart - lastFrameTime);
    lastFrameTime = frameStart;

    Uint32 frameDelay = 1000/config->fps;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    std::vector<SDL_FRect> rectsToRender;
    rectsToRender.reserve(vector.size());

    /*
    for(int i = 0; i < (int)vector.size(); i++){
        if(i == index){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &vector[i].rect);
        }else{
            SDL_SetRenderDrawColor(renderer, vector[i].color.r, vector[i].color.g, vector[i].color.b, 255);
            SDL_RenderFillRect(renderer, &vector[i].rect);
        }
        rectsToRender.push_back(vector[i].rect);
        //this is what was done before, rendering all the different stuff
        //SDL_FillSurfaceRect(surface, &vector[i].rect, 0xFFFFFFFF);
    }
    */
    algoritm.mtx.lock();
    for (const auto& member : vector) {
        rectsToRender.push_back(member.rect);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRects(renderer, rectsToRender.data(), rectsToRender.size());
    //rectsToRender.resize(vector.size());
    //SDL_RenderFillRect(renderer, &rectsToRender[algoritm.getIndex()]);

    algoritm.mtx.unlock();

    algoritm.displayText(renderer);
    SDL_RenderPresent(renderer);


    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
        SDL_Delay(frameDelay);
    }
    return deltaTime;
}
