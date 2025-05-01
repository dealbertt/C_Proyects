#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <cstdint>
#include <vector>
#include <mutex>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>


typedef struct{
    SDL_FRect rect;
    uint32_t value;
    SDL_Color color;
}array_member;


class Algorithm{
    protected:
        std::string name;
        uint32_t amount;
        uint32_t comparisons;
        uint32_t arrayAccesses;
        bool finished;
        uint16_t index;

    public:
        std::mutex mtx;
        virtual ~Algorithm() = default;
        Algorithm(std::string name, uint32_t comparisons, uint32_t arrayAccesses) : name(name), comparisons(comparisons), arrayAccesses(arrayAccesses) {}

        virtual int SortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer) = 0;
        virtual void SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer) = 0;

        int swapElements(std::vector<array_member>&vector, int member1, int member2);
        int showSortedArray(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer, Uint32 &lastFrameTime);

        int loop(SDL_Window *window, SDL_Renderer *renderer, std::vector<array_member> &vector, Uint32 &lastFrameTime);
        int initializeArray(SDL_Window *window, SDL_Renderer *renderer, std::vector<array_member> &vector, Uint32 &lastFrameTime);

        int displayText(SDL_Renderer *renderer);
        int visualizeArray(SDL_Renderer *renderer, std::vector<array_member> &array);


        //GETTERS
        std::string getName() const { return name;}
        uint32_t getComparisons() const { return comparisons;}
        uint32_t getAccesses() const { return arrayAccesses;}
        bool getFinished() const { return finished;}
        uint16_t getIndex() const {return index;}
        //SETTERS
        void setName(std::string newName) {name = newName;}
        void setComparisons(uint8_t newComparisons) {comparisons = newComparisons;}
        void setAccesses(uint8_t newAccesses) {arrayAccesses = newAccesses;}
        void setFinished(bool newFinished) { finished = newFinished;}
        void setIndex(uint16_t newIndex) { index = newIndex;}

};

class BubbleSort : public Algorithm{

    public:
        using Algorithm :: Algorithm;
        int SortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer) override;
        void SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer) override;
 
};


class SelectionSort : public Algorithm{
    public:
        using Algorithm :: Algorithm;
        int SortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer) override;
        void SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer) override;
};

class InsertionSort : public Algorithm{

    public:
        using Algorithm :: Algorithm;
        int SortStep(std::vector<array_member> &vector, SDL_Window *window, SDL_Renderer *renderer) override;
        void SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer) override;
        int assignNewElement(std::vector<array_member>&vector, array_member &member1, array_member &member2, SDL_Window *window, SDL_Renderer *renderer);

};

class QuickSort: public Algorithm{
    public:
        using Algorithm::Algorithm;

        void SortThread(std::vector<array_member> &array, SDL_Window *window, SDL_Renderer *renderer) override;
        void SortThreadExecution(std::vector<array_member> &array,SDL_Window *window, SDL_Renderer *renderer, uint32_t low, int32_t high);
        int SortStep(std::vector<array_member>&vector, SDL_Window *window, SDL_Renderer *renderer) override;

        int partition(std::vector<array_member> &array, uint32_t low, int32_t high);

};
int highlightValue(SDL_Window *window, SDL_Renderer *renderer, array_member value);

int updateValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value);
int clearValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value);

float reDrawScreen(SDL_Renderer *renderer, std::vector<array_member> &vector, int index, Uint32 &lastFrameTime, Algorithm &algoritm);
#endif
