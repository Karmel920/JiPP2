//
// Created by volie on 29.11.2021.
//

#include "TextNote.h"

string TextNote::getContent() {
    return content;
}

void TextNote::setContent(string line) {
    this->content = line;
}

TextNote::TextNote(string title) : Note(title) {}
