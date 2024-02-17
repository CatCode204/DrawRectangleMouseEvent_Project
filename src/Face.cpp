#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SupportClass.h"

using namespace std;

Face::Face() {
    this->numberVertex = 0;
    this->vertexIdArr = nullptr;
}

Face::Face(int numberVertex,int vertexIdArr[]) {
    this->numberVertex = numberVertex;
    this->vertexIdArr = new int[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexIdArr[i] = vertexIdArr[i];
}

Face::Face(const Face& other) {
    this->numberVertex = other.numberVertex;
    this->vertexIdArr = new int[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexIdArr[i] = other.vertexIdArr[i];
}

Face& Face::operator=(const Face& src) {
    if (this == &src) return *this;
    delete[] vertexIdArr;
    this->numberVertex = src.numberVertex;
    this->vertexIdArr = new int[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexIdArr[i] = src.vertexIdArr[i];
    return *this;
}

Face::~Face() {
    delete[] this->vertexIdArr;
}

int Face::getNumberVertex() {
    return this->numberVertex;
}

void Face::getVertexIdArr(int* &destination) {
    delete[] destination;
    destination = new int[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        destination[i] = this->vertexIdArr[i];
}

void Face::SetFace(int numberVertex,int vertexIdArr[]) {
    delete[] this->vertexIdArr;
    this->numberVertex = numberVertex;
    this->vertexIdArr = new int[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexIdArr[i] = vertexIdArr[i];
}