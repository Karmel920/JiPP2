//
// Created by volie on 29.11.2021.
//

#ifndef JIPP2_NOTE_H
#define JIPP2_NOTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Note {
private:
    string title;

public:
    Note(string title);
    string getTitle();
    void setTitle(string title);
    virtual string getContent() = 0;
    virtual void setContent(string title) = 0;
};

#endif //JIPP2_NOTE_H
