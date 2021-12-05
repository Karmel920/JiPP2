//
// Created by volie on 29.11.2021.
//

#ifndef JIPP2_NOTEDIRECTOR_H
#define JIPP2_NOTEDIRECTOR_H

#include <iostream>
#include "Note.h"

using namespace std;

class NoteDirector {
private:
    vector<string> notesList;
    vector<string> :: iterator iter = notesList.begin();

public:
    void addNote(string note);
    void deleteNote(int i);
    void editNote(int i, string note);
    void clearNotesList();
};
#endif //JIPP2_NOTEDIRECTOR_H




