//
// Created by volie on 29.11.2021.
//

#ifndef JIPP2_LISTNOTE_H
#define JIPP2_LISTNOTE_H

#include <iostream>
#include "Note.h"

using namespace std;

class ListNote : public Note {
private:
    vector<string> content;

public:
    ListNote(string title);
    string getContent();
    void setContent(string line);
};
#endif //JIPP2_LISTNOTE_H
