//
// Created by volie on 29.11.2021.
//

#ifndef JIPP2_TEXTNOTE_H
#define JIPP2_TEXTNOTE_H

#include <iostream>
#include "Note.h"

using namespace std;

class TextNote : public Note{
private:
    string content;

public:
    TextNote(string title);
    string getContent();
    void setContent(string line);
};
#endif //JIPP2_TEXTNOTE_H
