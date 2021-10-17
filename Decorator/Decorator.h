//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_DECORATOR_H
#define PATTERNS_DECORATOR_H

#include "../Content/Content.h"
#include "../Content/Audio.h"
#include "../Content/Picture.h"
#include "ContentFile.h"

void testDecorator() {
    std::printf("Made a 2 default contents: audio and picture\n");
    Content* audioFile = new Audio("Shrek_2.mp3");
    audioFile->getContent();
    Content* pictureFile = new Picture();
    pictureFile->getContent();

    std::printf("\nNow made a decorator for audio file\n");
    Content* decorator1 = new ContentFile(audioFile);
    decorator1->getContent();
}

#endif //PATTERNS_DECORATOR_H
