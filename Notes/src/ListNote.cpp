//
// Created by volie on 29.11.2021.
//

#include "ListNote.h"

string ListNote::getContent() {
    return content[0];
}

ListNote::ListNote(string title) : Note(title) {}

void ListNote::setContent(string line) {
    content.push_back(line);
}

