#ifndef _COMMON_H_
#define _COMMON_H_

void init();
void display();
void reshape(int w, int h);
void mouseClick(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char key, int x, int y);
extern int windowWidth;
extern int windowHeight;

#endif
