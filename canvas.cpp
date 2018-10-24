# MyContest
#include <iostream>
#include <sstream>
#include <cctype>
class Canvas
{
  static int width,height;
  public:
  Canvas(){}
  void drawCanvas(int w, int h, std::string &scr);
  void drawLine(int x1, int y1, int x2, int y2,std::string &scr);
  void drawRectangle(int x1, int y1, int x2, int y2,std::string &output);
  void fillArea(int x1, int y1, char color,std::string &output);
};

int Canvas::width=0;
int Canvas::height=0;
void Canvas::drawCanvas(int w, int h, std::string &scr)
{
    int i=0;
    int j=0;
    width =w;
    height=h;
    for (i=0;i<=h+1;i++)
    {
        for(j=0;j<w;j++)
        {
            if(i==0 || i==h+1)
                scr+="-";
            else if(j==0 || j==w-1)
                scr+="|";
            else scr+=" ";
            
        }
        scr+="\n";
    }
  
}
void Canvas::drawLine(int x1, int y1, int x2, int y2,std::string &output)
{
    int i=0;
  
  //horizontal line
  bool isVertical=0;
  int lower = 0;
  int upper = 0;
  int yp=0;
  if(y1==y2)
  {
      
	  lower = x1+y1*width+1;
      upper = x2+y2*width; 	
  }
  else if(x1==x2)
  {
      isVertical=1;
      lower = x1+(y1*width);
      upper = x2+(y2*width);
      yp=lower;
  }
  //std::cout<<"lower : "<<lower<<std::endl;
  //std::cout<<"upper : "<<upper<<std::endl;
  for( i=lower;i<=upper;)
  {
      if(output[i]==' ')
      output[i]='x';
      if(isVertical)
        i=i+width+1;
      else
        ++i;
  }
  
 /* if(y1==y2)
  {
      
	  lower = x1+y1*width;
      upper = x2+y2*width; 	
      for(i=lower;i<=upper;i++)
      {
          if(scr[i]==' ')
            scr.replace(i,1,"x");
      }
  }
  //vertical  line
  else if(x1==x2)
  {
      lower = x1+(y2-1)*width;
      upper = x2+(y2-1)*width;
      
      for(i=lower;i<=upper;i=i+width+1)
      {
          if(scr[i]==' ')
		    scr.replace(i,1,"x");
      }
  }*/
  
}

void Canvas::drawRectangle(int x1, int y1, int x2, int y2,std::string &output)
{
    
    drawLine(x1,y1,x2,y1,output);
    drawLine(x1+y2-y1,y2,x2+y2-y1,y2,output);
    drawLine(x1,y1-1,x1,y2,output);
    drawLine(x2-1,y1-1,x2-1,y2,output);
    
    
    
}

void Canvas::fillArea(int x, int y, char color,std::string &output)
{
    int i=0;
    int pos = x+(y-1)*width;
       for( char& c : output )
       {
           if(i!=pos && c==' ')
                c = color;
                ++i;
       }
}
int main()
{
    Canvas cvs;
    std::stringbuf sbuf( std::ios::out ) ; // create a stringbuf
    auto oldbuf = std::cout.rdbuf( std::addressof(sbuf)) ; // associate the stringbuf with std::cout
    
    int w = 20;
    int h = 4;
   
    std::string scr="";
    cvs.drawCanvas(20,4,scr);
    
    
    std::cout << scr ; // use std::cout normally

    std::cout.rdbuf( oldbuf ) ; // restore cout's original buffer

    std::string output = sbuf.str() ; // get a copy of the underlying string
    cvs.drawLine(1,2,6,2,output);
    cvs.drawLine(6,1,6,4,output);
	cvs.drawRectangle(14,1,18,3,output);
	cvs.fillArea(10,3, 'o',output);
    for( char& c : output ) c = std::toupper(c) ; // modify it
    
    std::cout << output ; // print out the modified output
}
