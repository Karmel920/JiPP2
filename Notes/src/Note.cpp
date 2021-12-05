//
// Created by volie on 29.11.2021.
//

#include "Note.h"

Note::Note(string title) : title(title) {}

string Note::getTitle() {
    return title;
}

void Note::setTitle(string title) {
    this->title = title;
}



