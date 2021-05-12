#include "Painter.h"
#include "DaGiacKhac.h"
#include "Oval.h"
#include "Line.h"
#include "Dagiacdeu.h"
#include "Dau.h"
#include "Tamgiac.h"
#include "Tugiac.h"
#include "Hinhkhac.h"
#include <windows.h>
#include "glut.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define clear_id 990099 
static int window;
static int menu_id;
static int submenu_id;
static int submenu_tomau_id;
static int value = 0;

static int submenu_oval_id;
static int submenu_tamgiac_id;
static int submenu_tugiac_id;
static int submenu_dagiacdeu_id;
static int submenu_hinhkhac_id;
static int submenu_dau_id;
static int submenu_select_id;

static int submenu_thuattoan_id;
static bool drawing_mode;

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77


Painter* myPainter = Painter::getInstance();
Point tempPointStart;
Point tempPointEnd;
vector<Point*> tempVert;

void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    }
    else {
        value = num;
        tempVert.clear();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
        if (value > 999) {
            myPainter->setSelected(value - 1000);
            cout << "Select " << myPainter->getSelected()->getType() << endl;
            glutPostRedisplay();
        }
    }

}
void createMenu(void) {
    tempVert.clear();
    //Layout (tang 3)
    //Oval
    submenu_oval_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh tron", id_HinhTron);
    glutAddMenuEntry("Ellipse", id_Ellipse);

    //TamGiac
    submenu_tamgiac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Vuong Can", id_TgVuongCan);
    glutAddMenuEntry("Deu", id_TgDeu);
    //Tugiac
    submenu_tugiac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh Chu Nhat", id_HinhChuNhat);
    glutAddMenuEntry("Hinh Vuong", id_HinhVuong);

    //dagiacdeu
    submenu_dagiacdeu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngu Giac Deu", id_NguGiacDeu);
    glutAddMenuEntry("Luc Giac Deu", id_LucGiacDeu);
    //hinhkhac
    submenu_hinhkhac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngoi Sao", id_NgoiSao);
    glutAddMenuEntry("Mui Ten", id_MuiTen);
    //dau
    submenu_dau_id = glutCreateMenu(menu);
    glutAddMenuEntry("Cheo", id_DauCong);
    glutAddMenuEntry("Xuyet", id_DauTru);

    submenu_thuattoan_id = glutCreateMenu(menu);
    glutAddMenuEntry("Boundary (Default)",Boundary);
    glutAddMenuEntry("FloodFill", Floodfill);

    //submenu selection:
    submenu_select_id = glutCreateMenu(menu);
    for (int i = 0; i < myPainter->getList().size(); i++) {
        string tempStr = myPainter->getList()[i]->getType();
        const char* tempChar = tempStr.c_str();
        glutAddMenuEntry(tempChar, i+1000);
    }

    submenu_id = glutCreateMenu(menu);

    //Layout subMenu (Tang 2)
    glutAddSubMenu("Oval", submenu_oval_id);
    glutAddSubMenu("Tam Giac", submenu_tamgiac_id);

    glutAddSubMenu("Tu Giac", submenu_tugiac_id);
    glutAddMenuEntry("Line", id_Line);
    glutAddSubMenu("Da Giac Deu", submenu_dagiacdeu_id);
    glutAddSubMenu("Hinh Khac", submenu_hinhkhac_id);
    glutAddSubMenu("Dau", submenu_dau_id);
    glutAddMenuEntry("Da Giac Khac", id_Dagiackhac);

    submenu_tomau_id = glutCreateMenu(menu);
    glutAddMenuEntry("Xanh",mauXanh_id);
    glutAddMenuEntry("Do", mauDo_id);
    glutAddMenuEntry("Vang", mauVang_id);
    
    //Layout Menu (tang 1)
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", clear_id);
    glutAddSubMenu("Draw", submenu_id);
    glutAddSubMenu("Select", submenu_select_id);
    glutAddSubMenu("To Mau", submenu_tomau_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);   
    if (value == 1) {
        return; //glutPostRedisplay();
    }
    for (int i = 0; i < myPainter->getList().size(); i++) {
        cout<<myPainter->getList()[i]->getType()<<endl;
        myPainter->getList()[i]->draw();
        //glutPostRedisplay();
    }
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    // Save the left button state
    
    if (button == GLUT_LEFT_BUTTON && value > 0)
    {
        if (state == GLUT_DOWN) {
            tempPointStart.setCoor(x, y);
            Point* addPoint = new Point(x, y);
            tempVert.push_back(addPoint);
        }

    }
    if (button == GLUT_RIGHT_BUTTON && value >0){
        if (state == GLUT_DOWN) {
            tempPointEnd.setCoor(x, y);
            Point* addPoint = new Point(x, y);
            tempVert.push_back(addPoint);
            
            switch (value)
            {
            case id_HinhTron: {
                Shape* a;
                a = new HinhTron(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_Ellipse: {
                Shape* a;
                a = new HinhElip(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_TgVuongCan: {
                Shape* a;
                a = new TGVuongCan(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_TgDeu: {
                Shape* a;
                a = new TGDeu(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_HinhChuNhat: {
                Shape* a;
                a = new HinhChuNhat(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_HinhVuong: {
                Shape* a;
                a = new HinhVuong(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_Line: {
                Shape* a;
                a = new Line(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_NguGiacDeu: {
                Shape* a;
                a = new NguGiacDeu(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_LucGiacDeu: {
                Shape* a;
                a = new LucGiacDeu(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_NgoiSao: {
                Shape* a;
                a = new NgoiSao(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_MuiTen: {
                Shape* a;
                a = new MuiTen(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_DauCong: {
                Shape* a;
                a = new DauCong(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_DauTru: {
                Shape* a;
                a = new DauTru(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case id_Dagiackhac: {
                Shape* a;
                a = new DaGiacKhac(tempVert);
                myPainter->addShape(a);
                glutPostRedisplay();
                break;
            }
            case mauXanh_id: {
                myPainter->fillColor(x,y, mauXanh_id);
                glutPostRedisplay();
                break;
            }
            case mauDo_id: {
                myPainter->fillColor(x, y, mauDo_id);
                glutPostRedisplay();
                break;
            }
            case mauVang_id: {
                myPainter->fillColor(x, y, mauVang_id);
                glutPostRedisplay();
                break;
            }
            case clear_id: {
                myPainter->~Painter();
                myPainter = Painter::getInstance();
                glutPostRedisplay();
                break;
            }
            
            default:
                break;
            }
            
            createMenu();
            myPainter->showList();
        }
    }
 
    // Save the mouse position

}


void keyPressed(unsigned char key, int x, int y) {
    if (myPainter->getSelected() == NULL)
        return;
    switch (key) {
    case 'l' :
    case 'L': {
        myPainter->rotateSelected("LEFT");
        glutPostRedisplay();
        break;
    }
    case 'r':
    case 'R': {
        myPainter->rotateSelected("RIGHT");
        glutPostRedisplay();
        break;
    }
    case '-': {
        myPainter->scaleSelected("DOWN");
        glutPostRedisplay();
        break;
    }
    case '=': {
        myPainter->scaleSelected("UP");
        glutPostRedisplay();
        break;
    }
    }
}

void specialKeys(int key, int x, int y) {
    if (myPainter->getSelected() == NULL)
        return;
    switch (key) {
    case GLUT_KEY_DOWN: {
        myPainter->translateSelected("DOWN");
        glutPostRedisplay();
        break;
    }
    case GLUT_KEY_UP: {
        myPainter->translateSelected("UP");
        glutPostRedisplay();
        break;
    }
    case GLUT_KEY_LEFT: {
        myPainter->translateSelected("LEFT");
        glutPostRedisplay();
        break;
    }
    case GLUT_KEY_RIGHT: {
        myPainter->translateSelected("RIGHT");
        glutPostRedisplay();
        break;
    }
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, h, h, 0);
    glColor3f(0, 0, 1); // blue
    glPointSize(5); //size
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(h, h);
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("Menus and Submenus - Programming Techniques");
    init();
    createMenu();     
    glClearColor(0.0f, 0.0f, 0.0f, 0.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return EXIT_SUCCESS;
}