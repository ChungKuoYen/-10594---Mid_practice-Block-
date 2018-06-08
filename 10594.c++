#include <iostream>
#include <algorithm>
#include <utility>
#include "function.h"



void Block::clockwise90()
{
    Block tmp(*this);


    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            tmp.pattern[j][size-i-1]=pattern[i][j];
        }

    }

        for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            pattern[i][j]=tmp.pattern[i][j];
        }

    }



}
    Block& Block::doublesize()
    {

        Block tmp;

        tmp.size=size*2;
        tmp.buf=new char [size*2*size*2];
        tmp.pattern=new char* [size*2];

        for (int i=0; i<size*size; i++) {

         tmp.buf[(i/size)*size*4+(i%size)*2]=buf[i];
         tmp.buf[(i/size)*size*4+(i%size)*2+1]=buf[i];
         tmp.buf[(i/size)*size*4+size*2+(i%size)*2]=buf[i];
         tmp.buf[(i/size)*size*4+size*2+(i%size)*2+1]=buf[i];



        }
        for (int i=0; i<tmp.size; i++) {
            tmp.pattern[i] = (char*) &tmp.buf[i*tmp.size];
        }

        size=size*2;
        buf=new char [size*size];
        pattern=new char* [size];

         for (int i=0; i<size; i++) {
            pattern[i] = (char*) &buf[i*size];
        }

        for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            pattern[i][j]=tmp.pattern[i][j];
        }

    }



    }
     bool equal(const Block& a, const Block& b)
     {
         Block tmp{a};
          int i=0,flag=1;
          while(i<4)
          {


          for (int i=0; i<std::min(a.size,b.size); i++) {
        for (int j=0; j<std::min(a.size,b.size); j++) {
           if( tmp.pattern[i][j]!=b.pattern[i][j])
           {
               flag=0;
           }
        }

    }
    if(flag==1)
    {
        return true;
    }
    tmp.clockwise90();
    flag=1;
        i++;
          }
          return false;

     }
