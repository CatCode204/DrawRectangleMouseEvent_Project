#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SupportClass.h"

using namespace std;

Mesh::Mesh() {
    this->numberVertex = 0;
    this->numberFace = 0;
    this->vertexArr = nullptr;
    this->faceArr = nullptr;
}

Mesh::Mesh(int numberVertex,Point3D pointArr[]) {
    this->numberVertex = numberVertex;
    this->vertexArr = new Point3D[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexArr[i] = pointArr[i];
}

Mesh::Mesh(int numberVertex,Point3D pointArr[],int numberFace, Face faceArr[]) {
    this->numberVertex = numberVertex;
    this->numberFace = numberFace;
    this->vertexArr = new Point3D[this->numberVertex];
    this->faceArr = new Face[this->numberFace];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexArr[i] = pointArr[i];
    for (int i=0;i < this->numberFace;++i)
        this->faceArr[i] = faceArr[i];    
}

Mesh::~Mesh() {
    delete[] vertexArr;
    delete[] faceArr;
}

void Mesh::setVertex(int numberVertex, Point3D pointArr[]) {
    delete[] this->vertexArr;
    this->numberVertex = numberVertex;
    this->vertexArr = new Point3D[this->numberVertex];
    for (int i=0;i < this->numberVertex;++i)
        this->vertexArr[i] = pointArr[i];
}

void Mesh::setFace(int numberFace, Face faceArr[]) {
    delete[] this->faceArr;
    this->numberFace = numberFace;
    for (int i=0;i < this->numberFace;++i)
        this->faceArr[i] = faceArr[i];
}

void Mesh::Draw() {
    int* vertexTranverse = nullptr;
    for (int i=0;i < this->numberFace;++i) {
        (this->faceArr[i]).getVertexIdArr(vertexTranverse);
        glBegin(GL_POLYGON);
            for (int j=0;j < (this->faceArr[i]).getNumberVertex();++i)
                glVertex3f(this->vertexArr[vertexTranverse[j]].x,this->vertexArr[vertexTranverse[j]].y,this->vertexArr[vertexTranverse[j]].z);
        glEnd();
        delete[] vertexArr;
    }
}