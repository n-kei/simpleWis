#include "display.h"
#include "ppmimage.h"

void display_text(int text_area)
{
}

void display_flash(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y;

  for(x=0; x<=601; x++){
    for(y=0; y<=600; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

}

void display_wall0(PpmImage * image)
{
}

void display_wall1(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y;

  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][225];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  
  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][375];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<=375; y++){
    pixel = &image->pixels[76][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=0; x<=75; x++){
    for(y=226; y<=374; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
}


void display_wall2(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y;

  for(x=76; x<=226; x++){
    pixel = &image->pixels[x][225];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=76; x<=226; x++){
    pixel = &image->pixels[x][375];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<=375; y++){
    pixel = &image->pixels[76][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<=375; y++){
    pixel = &image->pixels[226][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
    
  for(x=77; x<=225; x++){
    for(y=226; y<=374; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
}


void display_wall3(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y;

  for(x=225; x<=376; x++){
    pixel = &image->pixels[x][225];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=225; x<=376; x++){
    pixel = &image->pixels[x][375];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<375; y++){
    pixel = &image->pixels[226][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<375; y++){
    pixel = &image->pixels[376][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
    
  for(x=227; x<=375; x++){
    for(y=226; y<=374; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
}

void display_wall4(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y;

  for(x=376; x<=526; x++){
    pixel = &image->pixels[x][225];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=376; x<=526; x++){
    pixel = &image->pixels[x][375];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<375; y++){
    pixel = &image->pixels[376][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<375; y++){
    pixel = &image->pixels[526][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
    
  for(x=377; x<=525; x++){
    for(y=226; y<=374; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
}


void display_wall5(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y;

  for(x=526; x<602; x++){
    pixel = &image->pixels[x][225];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  
  for(x=526; x<602; x++){
    pixel = &image->pixels[x][375];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<=375; y++){
    pixel = &image->pixels[526][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=527; x<602; x++){
    for(y=226; y<=374; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
}

void display_wall6(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=0,y=149; x<=76; y++, x++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  

  for(x=0,y=451; x<=76; x++,y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(y=225; y<=375; y++){
      pixel = &image->pixels[76][y];
      pixel->r = 255;
      pixel->g = 255;
      pixel->b = 255;
  } 
  
  for(x=0, ys=150, ye=450; x<=75; x++, ys++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

}


void display_wall7(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

 
  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][75];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }
  
  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][525];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=76, y=75; x<=226; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=76, y=525; x<=226; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(y=225; y<=375; y++){
      pixel = &image->pixels[226][y];
      pixel->r = 255;
      pixel->g = 255;
      pixel->b = 255;     
  }

  for(y=75; y<=525; y++){
    pixel = &image->pixels[76][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=0; x<=75; x++){
    for(y=76; y<=524; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

  
  for(x=77, ys=77, ye=523; x<=225; x++, ys++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

}


void display_wall8(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(y=75; y<=525; y++){
    pixel = &image->pixels[76][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(y=75; y<=525; y++){
    pixel = &image->pixels[526][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=76; x<=526; x++){
    pixel = &image->pixels[x][75];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }


  for(x=76; x<=526; x++){
    pixel = &image->pixels[x][525];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }
  
  for(x=77; x<=525; x++){
    for(y=76; y<=524; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

}

void display_wall9(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=526; x<=601; x++){
    pixel = &image->pixels[x][75];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }
  
  for(x=526; x<=601; x++){
    pixel = &image->pixels[x][525];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(y=75; y<=525; y++){
    pixel = &image->pixels[526][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(y=225; y<=375; y++){
    pixel = &image->pixels[376][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=376, y=225; x<=526; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }
  
  for(x=376, y=375; x<=526; x++, y++){
      pixel = &image->pixels[x][y];
      pixel->r = 255;
      pixel->g = 255;
      pixel->b = 255;     
  }
  
  for(x=527; x<=601; x++){
    for(y=76; y<=524; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

  for(x=525, ys=77, ye=523; 377<=x; x--, ys++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }
  
}

void display_wall10(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(y=225; y<=375; y++){
    pixel = &image->pixels[526][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=526, y=225; x<=601; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }
  
  for(x=526, y=375; x<=601; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=601, ys=151, ye=449; 527<=x; x--, ys++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

} 

void display_wall11(PpmImage * image)
{
}

void display_wall12(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(y=75; y<=525; y++){
    pixel = &image->pixels[76][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=0, y=0; x<=76; x++,y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=0, y=600; x<=76; x++,y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=1, ys=2, ye=598; x<=75; x++, ys++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

}

void display_wall13(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(y=75; y<=525; y++){
    pixel = &image->pixels[526][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=526, y=75; x<=601; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=526, y=525; x<=601; x++,y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;     
  }

  for(x=601, ys=2, ye=598; 527<=x; x--, ys++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;     
    }
  }

}

void display_wall14(PpmImage * image)
{
}


void display_stepdown1(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y ,ys, ye;

  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][413];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 

  for(x=1, y=488; x<=76; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  
  for(x=0, ys=414, ye=487; x<=75; x++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_stepdown2(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y ,ys, ye;
  
  for(x=526; x<=601; x++){
    pixel = &image->pixels[x][413];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 
  
  for(x=526, y=413; x<=601; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=601, ys=414, ye=487; 527<=x; x--, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_stepdown3(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y ,ys, ye;
  
  for(x=76; x<=151; x++){
    pixel = &image->pixels[x][413];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 
  
  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][488];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 
  
  for(x=76, y=488; x<=151; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=0, y=488; x<=76; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }
  
  for(x=76, ys=414, ye=487; x<=150; x++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=76, ys=414, ye=487; 0<=x; x--, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_stepdown4(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;
  
  for(x=451; x<=526; x++){
    pixel = &image->pixels[x][413];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526; x<=601; x++){
    pixel = &image->pixels[x][488];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526, y=488; 451<=x; x--, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=601, y=488; 526<=x; x--, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526, ys=415, ye=486; 452<=x; x--, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=526, ys=414, ye=487; x<=601; x++, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}
 
void display_stepdown5(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=226; x<=376; x++){
    pixel = &image->pixels[x][413];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=151; x<=451; x++){
    pixel = &image->pixels[x][488];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=151, y=488; x<=226; x++, y--){
      pixel = &image->pixels[x][y];
      pixel->r = 255;
      pixel->g = 255;
      pixel->b = 255;
  }

  for(x=376, y=413; x<=451; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=226; x<=376; x++){
    for(y=414; y<=487; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
  for(x=226, ys=414, ye=487; 151<=x; x--, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=376, ys=414, ye=487; x<=451; x++,ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}


void display_stepdown6(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=76; x<=526; x++){
    pixel = &image->pixels[x][562];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=38, y=600; x<=76; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526, y=562; x<=564; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=76; x<=526; x++){
    for(y=563; y<=599; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=76, ys=563, ye=599; 39<=x; x--, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
  for(x=526, ys=563, ye=599; x<=561; x++, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_stepup1(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y ,ys, ye;

  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][187];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 

  for(x=1, y=112; x<=76; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  
  for(x=0, ys=113, ye=186; x<=75; x++, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_stepup2(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y ,ys, ye;
  
  for(x=526; x<=601; x++){
    pixel = &image->pixels[x][187];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 

  for(x=526, y=187; x<=601; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=601, ys=113, ye=186; 527<=x; x--, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

}

void display_stepup3(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y ,ys, ye;

  for(x=76; x<=151; x++){
    pixel = &image->pixels[x][187];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 

  for(x=0; x<=76; x++){
    pixel = &image->pixels[x][112];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  } 

  for(x=0, y=112; x<=76; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=76, y=112; x<=151; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=76, ys=113, ye=186; x<=150; x++, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=76, ys=113, ye=186; 0<=x; x--, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

}

void display_stepup4(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=451; x<=526; x++){
    pixel = &image->pixels[x][187];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526; x<=601; x++){
    pixel = &image->pixels[x][112];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526, y=112; 451<=x; x--, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=601, y=112; 526<=x; x--, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526, ys=113, ye=186; 452<=x; x--, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=601, ys=113, ye=186; 526<=x; x--, ys++){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

}
 
 
void display_stepup5(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=226; x<=376; x++){
    pixel = &image->pixels[x][187];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=151; x<=451; x++){
    pixel = &image->pixels[x][112];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=151, y=112; x<=226; x++, y++){
      pixel = &image->pixels[x][y];
      pixel->r = 255;
      pixel->g = 255;
      pixel->b = 255;
  }

  for(x=376, y=187; x<=451; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=226; x<=376; x++){
    for(y=113; y<=186; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
  for(x=226, ys=113, ye=186; 151<=x; x--, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=376, ys=113, ye=186; x<=451; x++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_stepup6(PpmImage * image)
{
  PpmPixel *pixel;
  int x, y, ys, ye;

  for(x=76; x<=526; x++){
    pixel = &image->pixels[x][38];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=38, y=0; x<=76; x++, y++){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=526, y=38; x<=564; x++, y--){
    pixel = &image->pixels[x][y];
    pixel->r = 255;
    pixel->g = 255;
    pixel->b = 255;
  }

  for(x=76; x<=526; x++){
    for(y=1; y<=37; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }

  for(x=76, ys=1, ye=37; 39<=x; x--, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
  for(x=526, ys=1, ye=37; x<=561; x++, ye--){
    for(y=ys; y<=ye; y++){
      pixel = &image->pixels[x][y];
      pixel->r = 0;
      pixel->g = 0;
      pixel->b = 0;
    }
  }
  
}

void display_cursor(int cursor_area);

/*
  名前 : display_stepdown_1
  概要 : 
  引数 : なし
  返値 : int command_type  選んだ選択肢についての定数値
*/  

void delete_cusor(int curosr_area);
