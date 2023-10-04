program lab5;
uses crt;
const  e= 0.0001;
var x,y,y1,y2,j11,j12,j21,j22,z1, z2: real;
iter:integer;
function f1(x, y: real): real;
         begin
              f1 := 2*x*x+1/y;
         end;
function f2(x, y: real): real;
         begin
              f2 := x * x *x +12*y-4;
         end;
function p1x(x: real): real;
         begin
              p1x := 4*x;
         end;
function p2x(x: real): real;
         begin
              p2x:= 3*x*x;
         end;
function p1y(y: real): real;
         begin
              p1y := -1/(y*y);
         end;
function p2y(y: real): real;
         begin
              p2y := 12;
         end;

begin
x:=0.5;
y:=2;
  iter:=0;
  repeat
        y1:=-f1(x,y);
        y2:=-f2(x,y);
        j11:=p1x(x);
        j12:=p1y(y);
        j21:=p2x(x);
        j22:=p2y(y);
        z2:=(y2*j11-j21*y1)/(j11*j22-j12*j21);
        z1:=(y1-j12*z2)/j11;
        x:=x+z1;
        y:=y+z2;
        inc(iter);
  until ((abs(z1) < e) and (abs(z2) < e));
  writeln('x= ',x:5:6);
  writeln('y= ',y:5:6);
  writeln('Общее количество итераций равно: ',iter);
  repeat until keypressed;
end.
