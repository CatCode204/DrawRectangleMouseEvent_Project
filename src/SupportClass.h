#ifndef __SUPPORTCLASS__
#endif //__SUPPORTCLASS__

struct Point2D {
    float x,y;
    Point2D(float x,float y): x(x),y(y) {}
    Point2D(): x(0), y(0){}
};

struct Point3D {
    float x,y,z;
    Point3D(float x,float y,float z): x(x), y(y), z(z){}
    Point3D(): x(0), y(0), z(0){}
};

class Face {
private:
    int numberVertex;
    int* vertexIdArr;
public:
    Face();
    Face(int numberVertex,int vertexIdArr[]); /*Liet ke cac id cua dinh, ve lan luot tu dinh 0 den numberVertex - 1*/
    Face(const Face& other); /*Ham khoi tao*/
    Face& operator = (const Face& src); /*Ham gan*/
    ~Face(); /*Ham huy*/
    int getNumberVertex();
    void getVertexIdArr(int* &destination);
    void SetFace(int numberVertex, int vertexIdArr[]);
};

class Mesh {
private:
    int numberVertex;
    Point3D* vertexArr;
    int numberFace;
    Face* faceArr;
public:
    Mesh();
    Mesh(int numberVertex, Point3D pointArr[]);
    Mesh(int numberVertex, Point3D pointArr[], int numberFace, Face faceArr[]);
    ~Mesh();
    void setVertex(int numberVertex, Point3D pointArr[]);
    void setFace(int numberFace, Face faceArr[]);
    void Draw();
};