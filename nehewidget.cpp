#include "nehewidget.h"

NeHeWidget::NeHeWidget( QWidget* parent, const char* name, bool fs )
    : QGLWidget( parent )
{
    rTri = 0.0;
    rQuad = 0.0;
    fullscreen = fs;
    setGeometry( 0, 0, 640, 480 );//设置窗口的位置，即左上角为(0,0)点，大小为640*480。
//  setCaption( "NeHe's OpenGL Framework" );//设置窗口的标题为“NeHe's OpenGL Framework”。
    setWindowTitle("NeHe's OpenGL Framework");
    if ( fullscreen )
         showFullScreen();

}//这个是构造函数，parent就是父窗口部件的指针，name就是这个窗口部件的名称，fs就是窗口是否最大化。
NeHeWidget::~NeHeWidget()
{
}//这个是析构函数。


void NeHeWidget::initializeGL()
{
  glShadeModel( GL_SMOOTH );//这一行启用smooth shading(阴影平滑)
  qglClearColor( Qt::gray );//这一行设置清除屏幕时所用的颜色也不是最暗
  glClearDepth( 1.0 );//设置深度缓存。
  glEnable( GL_DEPTH_TEST );//启用深度测试。
  glDepthFunc( GL_LEQUAL );//所作深度测试的类型。
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}


void NeHeWidget::paintGL()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );//清楚屏幕和深度缓存。
  glLoadIdentity();//重置当前的模型观察矩阵。

  glTranslatef( -1.5,  0.0, -6.0 );

  glRotatef( rTri,  0.0,  1.0,  0.0 );//三角形旋转

  glBegin( GL_TRIANGLES );//开始绘制三角形
  glColor3f( 1.0, 0.0, 0.0 );
  glVertex3f(  0.0,  1.0,  0.0 );//上顶点
  glColor3f( 0.0, 1.0, 0.0 );
  glVertex3f( -1.0, -1.0,  0.0 );//左下顶点
  glColor3f( 0.0, 0.0, 1.0 );
  glVertex3f(  1.0, -1.0,  0.0 );//右下顶点
  glEnd();//三角形绘制结束。

    glLoadIdentity();//重置模型观察矩阵

  glTranslatef(  1.5,  0.0,  -6.0 );

  glRotatef( rQuad,  1.0,  0.0,  0.0 );//四边形三角形旋转

  glBegin( GL_QUADS );//  开始绘制四边形。
  glColor3f( 0.5, 1, 0.5 );
  glVertex3f( -1.0,  1.0,  0.0 );//  左上顶点。
  glVertex3f(  1.0,  1.0,  0.0 ); // 右上顶点。
  glVertex3f(  1.0, -1.0,  0.0 ); // 右下顶点。
  glVertex3f( -1.0, -1.0,  0.0 ); // 左下顶点。
  glEnd(); //四边形绘制结束

  rTri += 20;
   rQuad -= 20;


}


void NeHeWidget::resizeGL( int width, int height )
{
  if ( height == 0 )
  {
    height = 1;
  }
  glViewport( 0, 0, (GLint)width, (GLint)height );
  glMatrixMode( GL_PROJECTION );//选择投影矩阵。
  glLoadIdentity();//重置投影矩阵。
  gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );//建立透视投影矩阵。
  //很重要

  glMatrixMode( GL_MODELVIEW );//选择模型观察矩阵。
}


void NeHeWidget::keyPressEvent(QKeyEvent *e)
{

    if(e->key()==Qt::Key_F2)
    {
        fullscreen = !fullscreen;
        if ( fullscreen )
        {
            showFullScreen();
        }
        else
        {
            showNormal();
            setGeometry( 0, 0, 640, 480 );
        }
         updateGL();
    }
    if(e->key()==Qt::Key_Escape)
    {
       close();
    }
    if(e->key()==Qt::Key_R)
    {
        update();

    }

}

