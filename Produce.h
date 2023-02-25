#ifndef PRODUCE_H
#define PRODUCE_H

class Produce {
    public:
        Produce();
        void SetAmount(int amount);
        int GetAmount() const;
        void SetName(std::string name);
        std::string GetName() const;
        void Print();
        void PrintHist();

    private:
        int amountSold;
        std::string itemName;

};

// Other Functions
std::string nCharString(size_t n, char c);
void printMenu(std::string menu[], unsigned int numStrings, unsigned char width);
std::string makeUpper(std::string item);
int isOption(int num);



#endif