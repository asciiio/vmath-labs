const e = 0.001;
  var 
    x,y,dx,dy,grad,h,fdx,fdy,fxy,fxy1: double;
begin
  x := 0;
  y := 0;
  h := 0.01;
   repeat
      //begin
       fxy := (-2/3)*(x*x*x)+2*x*y-y*y;
       fdx := -2*x*x+2*y;
       fdy := 2*x-2*y;
       grad := sqrt(fdx * fdx + fdy * fdy);
       x := x - h * fdx;
       y := y - h * fdy;
       fxy1 := (-2/3)*(x*x*x)+2*x*y-y*y;
     //if (fxy1 <= fxy) then begin
        //h := h/2;
        //end;
       //end;
    until ((abs(grad)) < e);
   writeln('Значение функции в точке экстремума: ',fxy:0:3);
   writeln('x = ',x);
   writeln('y = ',y);
End.
