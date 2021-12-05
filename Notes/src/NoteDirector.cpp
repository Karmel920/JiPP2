//
// Created by volie on 29.11.2021.
//

#include "NoteDirector.h"

void NoteDirector::addNote(string note) {
    notesList.push_back(note);
}

void NoteDirector::deleteNote(int i) {
    notesList.erase(iter+i);
}

void NoteDirector::editNote(int i, string note) {
    notesList.at(i) = note;
}

void NoteDirector::clearNotesList() {
    notesList.clear();
}
