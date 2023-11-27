#include <windows.h>
#include <GL/glut.h>
#define PI 3.141592653589793238462643383279502884197
#include<math.h>
#include <stdio.h>
#include <GL/gl.h>
#include <vector>
GLfloat p=-10;
GLfloat m=200;

void init(void)
{
glClearColor(0.7137254901960784,0.8862745098039215,0.9647058823529412,1.0); //GLfloat

//glclear to clear the color buffers
glMatrixMode(GL_PROJECTION); // To specify which matrix

//applies subsequent matrix to projecton matrix stack
glLoadIdentity();
glOrtho(-150.0, 150.0, -150.0, 150.0, -1.0, 1.0);
//gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic

//an orthographic matrix 2D= left right,bottom,top

}

void rectangle_with_border(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat borderWidth){
    // Draw the rectangle
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();

    //  width for the border
    glLineWidth(borderWidth);


    glColor3f(0.0, 0.0, 0.0);

    //  border
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}


void color(GLfloat r, GLfloat g, GLfloat b){
glColor3f(r/255.0,g/255.0,b/255.0);
}


//Traffic light
void drawTrafficLight(GLfloat b)
{
    // pole
    glColor3f(0.4, 0.4, 0.4); // Gray color
    rectangle_with_border(-5 + 1.2 - 115 + 160, -56, -3 + 1.2 - 115 + 160, -56, -3 + 1.2 - 115 + 160, 30, -5 + 1.2 - 115 + 160, 30, 0.1);

    // traffic light box
    glColor3f(1.0, 1.0, 1.0); // Light gray color
    rectangle_with_border(-7 - 115 + 160, 20, 2 - 115 + 160, 20, 2 - 115 + 160, 53, -7 - 115 + 160, 53, 0.1);

    //  red light
    glColor3f(1.0 + (b / 20), 0.0 + (b / 20), 0.0 + (b / 20)); // Red color
    rectangle_with_border(-5 - 115 + 160, 45, 0 - 115 + 160, 45, 0 - 115 + 160, 50, -5 - 115 + 160, 50, 0.1);

    //  yellow light
    glColor3f(1.0 + (b / 20), 1.0 + (b / 20), 0.0 + (b / 20)); // Yellow color
    rectangle_with_border(-5 - 115 + 160, 35, 0 - 115 + 160, 35, 0 - 115 + 160, 40, -5 - 115 + 160, 40, 0.1);

    // green light
    glColor3f(0.0 + (b / 20), 1.0 + (b / 20), 0.0 + (b / 20)); // Green color
    rectangle_with_border(-5 - 115 + 160, 25, 0 - 115 + 160, 25, 0 - 115 + 160, 30, -5 - 115 + 160, 30, 0.1);
}



// bench
void drawBench(GLfloat x, GLfloat y, GLfloat scale)
{
    //bench seat
    glColor3f(0.545, 0.271, 0.075);
    rectangle_with_border(x - 3*scale, y, x + 3*scale, y, x + 3*scale, y - 1*scale, x - 3*scale, y - 1*scale, 0.1);

    //  bench legs
    glColor3f(0.4, 0.2, 0.0);
    rectangle_with_border(x - 2.8*scale, y - 1*scale, x - 2.7*scale, y - 1*scale - 2*scale, x - 2.7*scale, y - 3*scale, x - 2.8*scale, y - 3*scale, 0.1);
    rectangle_with_border(x + 2.7*scale, y - 1*scale, x + 2.8*scale, y - 1*scale - 2*scale, x + 2.8*scale, y - 3*scale, x + 2.7*scale, y - 3*scale, 0.1);
}


// draw circle function

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100;


    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_LINE_LOOP);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}


void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y); //top left
    glVertex2f(x + width, y); //top right
    glVertex2f(x + width, y + height); //bottom right
    glVertex2f(x, y + height); //bottom left
    glEnd();
}





void rectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}






void drawBuilding() {
//  larger building
    color(189,68,78);
    rectangle(70, -56, 90, -56, 90, -6, 70, -6);
    //  windows
    int numWindows = 6;
    GLfloat windowWidth = 5;
    GLfloat windowHeight = 3;

    color(25,45,53);

    for (int i = 0; i < numWindows; i++) {
        int row = i / 2;
        int col = i % 2;


        rectangle(72 + col * (windowWidth + 5), -54 + row * 15, 72 + col * (windowWidth + 5) + windowWidth, -54 + row * 15, 72 + col * (windowWidth + 5) + windowWidth, -49 + row * 15 + windowHeight, 72 + col * (windowWidth + 5), -49 + row * 15 + windowHeight);
    }

    // smaller building
    color(196,114,87);
    rectangle(90, -56, 102, -56, 102, 14, 90, 14);

    //  smaller building
    int numSmallWindows = 14; //
    GLfloat smallWindowWidth = 3;
    GLfloat smallWindowHeight = 3;

    color(102,102,102);

    for (int i = 0; i < numSmallWindows; i++) {
        int row = i / 2;
        int col = i % 2;


        rectangle(92 + col * (smallWindowWidth + 2), -54 + row * 10, 92 + col * (smallWindowWidth + 2) + smallWindowWidth, -54 + row * 10, 92 + col * (smallWindowWidth + 2) + smallWindowWidth, -51 + row * 10 + smallWindowHeight, 92 + col * (smallWindowWidth + 2), -51 + row * 10 + smallWindowHeight);
    }

    //Third Buiding
    color(60,108,108);
    drawRectangle(102,-56,30,76);

   color(227,138,120);
    for (int i = 0; i < numSmallWindows; i++) {
        int row = i / 2;
        int col = i % 2;


        rectangle(104 + col * (smallWindowWidth + 2), -54 + row * 10, 104 + col * (smallWindowWidth + 2) + smallWindowWidth, -54 + row * 10, 104 + col * (smallWindowWidth + 2) + smallWindowWidth, -51 + row * 10 + smallWindowHeight, 104 + col * (smallWindowWidth + 2), -51 + row * 10 + smallWindowHeight);
    }



     for (int i = 0; i < numSmallWindows; i++) {
        int row = i / 2;
        int col = i % 2;

        rectangle(119+2 + col * (smallWindowWidth + 2), -54 + row * 10, 119+2 + col * (smallWindowWidth + 2) + smallWindowWidth, -54 + row * 10, 119+2 + col * (smallWindowWidth + 2) + smallWindowWidth, -51 + row * 10 + smallWindowHeight, 119+2 + col * (smallWindowWidth + 2), -51 + row * 10 + smallWindowHeight);
    }
    int numStairwindow=6;
    color(104,81,85);
     for (int i = 0; i < numStairwindow; i++) {
         int stepsize=i*10;
         drawRectangle(116,-50+stepsize,2,7);

     }



}






void triangle(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3){
    glBegin(GL_POLYGON);
glVertex2i(x1,y1);
glVertex2i(x2,y2);
glVertex2i(x3,y3);

glEnd();


}


void half_circle(GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);


    for(int i=0; i<=50; i++){
        GLfloat angle = 2.0f * 3.1416f * (i/100.0);
        GLfloat x = rx * cosf(angle);
        GLfloat y = ry * sinf(angle);

        glVertex2f(x+cx, y+cy);
    }

    glEnd();
}












void leftpilar(){
      glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
   rectangle_with_border(-26,-50,-18,-50,-18,35,-26,35,0.1);



    glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    half_circle(-22,35,6,15);

   glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    triangle(-22,55,-18,45,-26,45);


    glColor3f(0.5686274509803921,0.788235294117647,0.9294117647058824);
    rectangle(-28,35,-28,37,-16,37,-16,35);



}

void rightpilar(){
     glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    rectangle_with_border(26,-50,18,-50,18,35,26,35,0.1);



   glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    half_circle(22,35,6,15);

   glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    triangle(22,55,18,45,26,45);
 glColor3f(0.5686274509803921,0.788235294117647,0.9294117647058824);
    rectangle(28,35,28,37,16,37,16,35);


}


void circle(GLfloat cx,GLfloat cy, GLfloat rx, GLfloat ry){


    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx,cy);


    for( int i=0;i<=101;i++){
        GLfloat angle = 2.0f*3.1416f*(i/100.0);
        GLfloat x = rx*cosf(angle);
        GLfloat y = ry*sinf(angle);

        glVertex2f(x+cx,y+cy);
    }

     glEnd();
}


void leftgrass(){
     color(34,139,34);
     circle(-20,-50,5,5);

     color(34,139,34);
     circle(-22,-50,5,5);

    color(34,139,34);
     circle(-22,-53,5,5);

      color(34,139,34);
     circle(-23,-54,5,5);

    color(34,139,34);
     circle(-25,-55,5,5);

     color(34,139,34);
     circle(-25,-48,5,5);

    color(34,139,34);
     circle(-23,-45,5,5);


     color(34,139,34);
     circle(-26,-45,5,5);



     color(34,139,34);
     circle(-23,-45,5,5);




    color(34,139,34);
     circle(-25,-48,5,5);

    color(34,139,34);
     circle(-24,-55,5,5);

     color(34,139,34);
     circle(-26,-49,5,5);

      color(34,139,34);
     circle(-28,-54,5,5);

  color(34,139,34);
     circle(-27,-50,5,5);

    color(34,139,34);
     circle(-29,-52,6,6);

    color(34,139,34);
     circle(-21,-55,5,5);


   color(34,139,34);
     circle(-30,-53,5,5);



     color(34,139,34);
     circle(-20,-51,6,6);

}


void rightgrass(){


    color(34,139,34);
     circle(20,-50,5,5);

    color(34,139,34);
     circle(22,-50,5,5);

      color(34,139,34);
     circle(22,-53,5,5);

     color(34,139,34);
     circle(23,-54,5,5);

      color(34,139,34);
     circle(25,-55,5,5);

   color(34,139,34);
     circle(25,-48,5,5);

     color(34,139,34);
     circle(23,-45,5,5);


     color(34,139,34);
     circle(26,-45,5,5);



     color(34,139,34);
     circle(23,-45,5,5);









     color(34,139,34);
     circle(25,-48,5,5);

      color(34,139,34);
     circle(24,-55,5,5);

    color(34,139,34);
     circle(26,-49,5,5);

      color(34,139,34);
     circle(28,-54,5,5);

      color(34,139,34);
     circle(27,-50,5,5);

    color(34,139,34);
     circle(29,-52,6,6);

     color(34,139,34);
     circle(21,-55,5,5);


    color(34,139,34);
     circle(30,-53,5,5);



     color(34,139,34);
     circle(20,-51,6,6);

}



void drawGrass() {
    leftgrass();
    rightgrass();

}



void rooftop(){

    glColor3f(0.3764705882352941,0.6941176470588235,0.9019607843137255);
    rectangle_with_border(-16,25,-16,40,16,40,16,25,0.1);


    glColor3f(1,1,1);
    circle(-12,32.5,1,1);



    glColor3f(1,1,1);
    circle(-8,32.5,1,1);



    glColor3f(1,1,1);
    circle(-4,32.5,1,1);



    glColor3f(1,1,1);
    circle(-0,32.5,1,1);



    glColor3f(1,1,1);
    circle(4,32.5,1,1);





    glColor3f(1,1,1);
    circle(8,32.5,1,1);




    glColor3f(1,1,1);
    circle(12,32.5,1,1);



}



void upperrooftop(){

 glColor3f(0.0784313725490196,0.4666666666666667,0.7294117647058823);
    rectangle_with_border(-13,40,-13,47.5,13,47.5,13,40,0.1);


}





void maindome(){

 glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    triangle(0,75,-6,65,6,65);

    glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    triangle(0,74,-6,65,6,65);

     glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    triangle(0,73,-6,65,6,65);

     glColor3f(0.5686274509803921,0.788235294117647,0.9294117647058824);
    triangle(0,72,-6,65,6,65);

    glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
    triangle(0,71,-6,65,6,65);

    glColor3f(0.5686274509803921,0.788235294117647,0.9294117647058824);
    half_circle(0,47.5,13,20);

}

void halfmoon(){
color(255,255,255);
circle(3,85,10,10);

color(182,226,246);
circle(8,85,12,9);

}

void mainentarnce(){
    glColor3f(0.5254901960784314,0.7529411764705882,0.9019607843137255);
rectangle_with_border(-20,-50,-20,25,20,25,20,-50,0.1);

upperrooftop();
rooftop();
maindome();
halfmoon();

}
void minarleft(){

 glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
glBegin(GL_POLYGON);
glVertex2i(-15,-50);
glVertex2i(-15,-10);
glVertex2i(-10,-10);
glVertex2i(-10,-50);
glEnd();



}
void minarright(){


 glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
glBegin(GL_POLYGON);
glVertex2i(15,-50);
glVertex2i(15,-10);
glVertex2i(10,-10);
glVertex2i(10,-50);
glEnd();



}
void minarcenter(){


 glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
glBegin(GL_POLYGON);
glVertex2i(5,-50);
glVertex2i(5,5);
glVertex2i(-5,5);
glVertex2i(-5,-50);
glEnd();



}





void cloud1(GLfloat p){

    glColor3f(1,1,1);
    circle(-50+p,60,15,17);

     glColor3f(1,1,1);
    circle(-67+p,55,6,6);

     glColor3f(1,1,1);
    circle(-37+p,57,4,8);

      glColor3f(1,1,1);
    circle(-35+p,56,5,6);

     glColor3f(1,1,1);
    circle(-66+p,58,10,6);

    glColor3f(0.7137254901960784,0.8862745098039215,0.9647058823529412);
    rectangle(-80+p,56,-80+p,40,-26+p,40,-26+p,56);
}


void cloud2(GLfloat p){
GLfloat c=p;
p=abs(p);
    color(206,78,82);
    circle(32-c/1,125-c/9,15,20);


  glColor3f(1-(p/1000),1-(p/2000),0+p/10);
    circle(15,115,18,17);

     glColor3f(1-(p/1000),1-(p/2000),0+p/10);
    circle(-5,105,10,10);

     glColor3f(1-(p/1000),1-(p/2000),0+p/10);
    circle(0,108,5,10);

      glColor3f(1-(p/1000),1-(p/2000),0+p/10);
    circle(5,120,10,7);

     glColor3f(1-(p/1000),1-(p/2000),0+p/10);
    circle(35,103,7,7);





    glColor3f(0.7137254901960784,0.8862745098039215,0.9647058823529412);
    rectangle(-30,105,-30,75,50,75,50,105);

}


void cloud3(GLfloat p){

    glColor3f(1,1,1);
    circle(60+p,70,15,17);

     glColor3f(1,1,1);
    circle(77+p,65,6,6);

     glColor3f(1,1,1);
    circle(47+p,67,4,8);

      glColor3f(1,1,1);
    circle(45+p,66,5,6);

     glColor3f(1,1,1);
    circle(77+p,68,10,6);

    glColor3f(0.7137254901960784,0.8862745098039215,0.9647058823529412);
    rectangle(90+p,66,90+p,50,36+p,50,36+p,66);

}







void bird(GLfloat x, GLfloat y,GLfloat scale){






     glColor3f(0,0,0);
    circle(x,y,3*scale,3*scale);

    glColor3f(0.7137254901960784,0.8862745098039215,0.9647058823529412);
    circle(x,y-1,3*scale,3*scale);

     glColor3f(0,0,0);
    circle(x+6*scale,y,3*scale,4*scale);

    glColor3f(0.7137254901960784,0.8862745098039215,0.9647058823529412);
    circle(x+6*scale,y-1,3*scale,4*scale);




}









void environment(GLfloat p){


    cloud1(p);
    cloud2(p);
    cloud3(p);
    bird(-60-p,50,1);
     bird(-55-p,45,0.5);

      bird(-31-p,130,0.7);
     bird(-15-p,100,0.5);
     bird(-25-p,95,0.4);

     bird(60-p,100,0.8);
     bird(75-p,60,0.4);




}





void drawTree(GLfloat x, GLfloat y) {
    //  trunk
    glColor3f(0.5451, 0.2706, 0.0745);
    rectangle(x - 5, y - 10, x + 5, y - 10, x + 5, y + 20, x - 5, y + 20);


    //  leaves
    glColor3f(0.1333, 0.5451, 0.1333);
    circle(x, y + 20+30-20, 15, 20);
    circle(x - 5, y + 25+30-20, 15, 20);
    circle(x + 5, y + 25+30-20, 15, 20);

    //  leaves
    glColor3f(0.1961, 0.8039, 0.1961);

    circle(x, y + 35+50-20, 15, 20);
    circle(x - 10, y + 30+30-20, 15, 18);
    circle(x + 10, y + 30+30-20, 15, 18);






    circle(x - 10, y + 30+43-20, 15, 15);
    circle(x + 10, y + 30+43-20, 15, 15);

}










void drawLeftCar(GLfloat m) {
    //  body of the left car
    glColor3f(0.5098039215686274, 0.34509803921568627, 0.6235294117647059);
    rectangle(-60+m, -100, -20+m, -100, -30+m, -90, -50+m, -90);

    //  windows of the left car
    glColor3f(0.8392156862745098, 0.6352941176470588, 0.9098039215686274);
    rectangle(-55+m, -90, -25+m, -90, -35+m, -80, -45+m, -80);

    //  wheels of the left car
    glColor3f(0.0, 0.0, 0.0);
    circle(-48+m, -100, 5, 5);
    circle(-30+m, -100, 5, 5);
}


void drawrightCar(GLfloat m) {


    //  body
    glColor3f(0.41568627450980394, 0.6901960784313725, 0.2980392156862745);
    rectangle(20-m, -110, 60-m, -110, 50-m, -100, 30-m, -100);

    //  windows
    glColor3f(0.7294117647058823, 0.8627450980392157, 0.34509803921568627);
    rectangle(25-m, -100, 55-m, -100, 45-m, -90, 35-m, -90);

    // wheels
    glColor3f(0.0, 0.0, 0.0);
    circle(32-m, -110, 5, 5);
    circle(50-m, -110, 5, 5);
}









void streetline(){
 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(-120,-104,-120,-108,-100,-108,-100,-104);

 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(-90,-104,-90,-108,-70,-108,-70,-104);

 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(-60,-104,-60,-108,-40,-108,-40,-104);

 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(-30,-104,-30,-108,-10,-108,-10,-104);




glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(0,-104,0,-108,20,-108,20,-104);

 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(30,-104,30,-108,50,-108,50,-104);

 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(60,-104,60,-108,80,-108,80,-104);

 glColor3f(0.9647058823529412,0.7254901960784313,0.23137254901960785);
 rectangle(90,-104,90,-108,110,-108,110,-104);




}


void street(){
    glColor3f(0.3411764705882353,0.396078431372549,0.4549019607843137);
    rectangle(-150,-56,-150,-150,150,-150,150,-56);
    streetline();
}











void drawMapleTree(GLfloat x, GLfloat y) {
    // trunk
    glColor3f(0.5451, 0.2706, 0.0745);
    rectangle(x - 2, y - 10, x + 2, y - 10, x + 2, y + 10, x - 2, y + 10);

    //  leaves
    color(184,35,58);
    triangle(x - 10, y + 10, x + 10, y + 10, x, y + 25);
    color(156,20,67);
    triangle(x - 8, y + 20, x + 8, y + 20, x, y + 35);
}

//   maple tree function call
void drawMapleTrees() {
    drawMapleTree(-130, -50);
    drawMapleTree(130, -50);
}

void drawPalmTree(GLfloat x, GLfloat y) {
    // trunk
   color(139,81,49);
    rectangle(x - 2, y - 15, x + 2, y - 15, x + 2, y + 30, x - 2, y + 30);


    color(80,125,36);
    // leaves
    triangle(x - 10, y + 30, x + 10, y + 30, x, y + 50);
    color(73,139,26);
    triangle(x - 8, y + 40, x + 8, y + 40, x, y + 60);
       color(56,140,49);
    triangle(x - 6, y + 50, x + 6, y + 50, x, y + 70);
}

//  palm trees
void drawPalmTrees() {
    drawPalmTree(-140, -50);
    drawPalmTree(140, -50);
}
void trapezium(GLfloat x, GLfloat y){
glBegin(GL_POLYGON);
glVertex2f(x,y);
glVertex2f(x+6,y);
glVertex2f(x+5,y-3);
glVertex2f(x+1,y-3);


glEnd();

}


 void ballonropes(GLfloat m){
     drawLine(140-260-(m/1.5),-53+70-m,138-260-(m/1.5),-48+70-m);
     drawLine(146-260-(m/1.5),-53+70-m,148-260-(m/1.5),-48+70-m);
     drawLine(143-260-(m/1.5),-53+70-m,141-260-(m/1.5),-48+70-m);
     drawLine(143-260-(m/1.5),-53+70-m,145-260-(m/1.5),-48+70-m);

}



void airballoon(GLfloat m){

      //ballons
    color(247,137,126);
    circle(143-260-(m/1.5),0+65-m,15,40);
    color(223,91,75);
    circle(143-260-(m/1.5),-10+67-m,13,37);
    color(247,112,92);
    circle(143-260-(m/1.5),-15+62-m,10,30);



    glColor3f(0.7137254901960784,0.8862745098039215,0.9647058823529412);
    drawRectangle(120-260-(m/1.5),-48+70-m,170,-100);


    color(182,107,87);
    trapezium(140-260-(m/1.5),-53+70-m);
    color(0,0,0);
    ballonropes(m);

}


void drawBus(GLfloat x, GLfloat y,GLfloat m) {
    // body
    glColor3f(0.905, 0.498, 0.235);
    rectangle_with_border(x - 25+m, y - 10, x + 25+m, y - 10, x + 25+m, y + 15, x - 25+m, y + 15, 0.1);

    // windows
    glColor3f(0.678, 0.847, 0.902);
    rectangle_with_border(x - 20+m, y + 5, x - 5+m, y + 5, x - 5+m, y + 12, x - 20+m, y + 12, 0.1);
     color(182,226,246);
    rectangle_with_border(x + 5+m, y + 5, x + 20+m, y + 5, x + 20+m, y + 12, x + 5+m, y + 12, 0.1);

    //  window lines
    glColor3f(0.1, 0.1, 0.1);
    drawLine(x - 12.5+m, y + 5, x - 12.5+m, y + 12);
    drawLine(x + 12.5+m, y + 5, x + 12.5+m, y + 12);

    //  wheels
    glColor3f(0.0, 0.0, 0.0);
    circle(x - 15+m, y - 10, 5, 5);
    circle(x + 15+m, y - 10, 5, 5);
}




void drawMushroomTree(GLfloat x, GLfloat y) {
    // mushroom cap
    color(162,16,16);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float radian = i * (3.1416 / 180);
        float xPos = x + 10 * cos(radian);
        float yPos = y + 15 + 5 * sin(radian);
        glVertex2f(xPos, yPos);
    }
    glEnd();

    // mushroom stem
    color(228,197,151);
    glBegin(GL_POLYGON);
    glVertex2f(x - 3, y - 20);
    glVertex2f(x + 3, y - 20);
    glVertex2f(x + 3, y + 15);
    glVertex2f(x - 3, y + 15);
    glEnd();
}


 void drawBusStop(){

      color(93,111,34);
       drawRectangle(-78-10,0,2,-56);
       color(93,111,34);
      drawRectangle(-49-10,0,2,-56);
      color(93,111,34);
      drawRectangle(-70-10,0,2,-56);
       color(93,111,34);
      drawRectangle(-60-10,0,2,-56);




     color(255,156,1);
     drawRectangle(-80-10,10,35,-10);
     color(150,55,51);
     drawRectangle(-80-10,0,35,-3);
     color(196,114,87);
      drawRectangle(-80-10,-3,35,-8);


      color(162,16,16);
      glRasterPos2f(-70,4);
      char *string="Bus Stop";
       while(*string){
       glutBitmapCharacter(GLUT_BITMAP_8_BY_13,*string++);


       }




 }




void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);



if(p<=10)
    p=p+0.005;
else
    p=-10;

if(m<=200)
    m=m+0.05;
else
    m=-200;

      glutPostRedisplay();
      airballoon(p);
      drawBuilding() ;

environment(p);
leftpilar();
rightpilar();

// mushroom trees

drawMushroomTree(-38, -59);

GLfloat treeSpacing = 80;

// Draw trees

drawTree(55, -50);

drawMapleTrees();
drawPalmTrees();

drawBench(-105, -45,5);

drawBusStop();

leftgrass();
rightgrass();

mainentarnce();

glColor3f(0.09803921568627451,0.5372549019607843,0.788235294117647);
circle(-12.5,-10,2.5,2.5);

circle(0,5,5,5);

circle(12.5,-10,2.5,2.5);

minarleft();
minarright();
minarcenter();

street();
glColor3f( 1 ,1, 1);
rectangle_with_border(-23,-50,-23,-53,23,-53,23,-50,0.5);

glColor3f( 1 ,1, 1);
rectangle_with_border(-25,-53,-25,-56,25,-56,25,-53,0.5);

drawrightCar(m) ;

// Draw buses
drawBus(-40, -125,m*1.5);

drawBus(70, -73,-m*1.2);

drawLeftCar(m*2);

drawTrafficLight(p);

glutPostRedisplay();

glutSwapBuffers();
}



int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
glutInitWindowPosition(0,0);
glutInitWindowSize(1000,1000);
glutCreateWindow("Lab Final");
init();
glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}
