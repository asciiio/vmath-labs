program lab2;
uses crt;
var k,razmmatritci,i,n:integer; 
  s,nevyzka1,nevyzka2,nevyzka3:double; 
  elements:array [1..3,1..4]of double; 
  korni:array [1..3]of double;  

Begin
     elements[1,1]:=0.5;
     elements[1,2]:=-1;
     elements[1,3]:=-1;
     elements[1,4]:=0;
     elements[2,1]:=0;
     elements[2,2]:=-1;
     elements[2,3]:=1;
     elements[2,4]:=-2;
     elements[3,1]:=0;
     elements[3,2]:=1;
     elements[3,3]:=-2;
     elements[3,4]:=4.2;
     razmmatritci:=3;
     clrscr;
     writeln('Уравнения вида:');
     writeln('0.5x-z=y');
     writeln('z+2-y=0');
     writeln('y-2z=4.2');
     writeln;
     writeln('Матрица:');
     For k:=1 to razmmatritci do
         begin
              for n:=1 to razmmatritci+1 do
                  write(' ',elements [k,n]:5:2); 
              writeln;
         end;

     for k:=1 to razmmatritci-1 do
         begin
              for n:=k+1 to razmmatritci+1 do
                  elements [k,n]:=elements [k,n]/elements [k,k];
              for i:=k+1 to razmmatritci do
                  begin
                       for n:=k+1 to razmmatritci+1 do
                           elements [i,n]:=elements [i,n]-elements [i,k]*elements [k,n];
                  end;
         end;

     korni[razmmatritci]:=elements[razmmatritci,razmmatritci+1]/elements[razmmatritci,razmmatritci];
     for k:=razmmatritci-1 downto 1 do
         begin
              s:=elements[k,razmmatritci+1];
              for n:=k+1 to razmmatritci do
                  s:=s-korni[n]*elements[k,n];
              korni[k]:=s;
         end;
     writeln;
     writeln('Корни:');
     writeln('x=',korni[1]:0:4);
     writeln('y=',korni[2]:0:4);
     writeln('z=',korni[3]:0:4);

     nevyzka1:=0.5*korni[1]-korni[2]-korni[3];
     nevyzka2:=-korni[2]+korni[3];
     nevyzka3:=korni[2]-2*korni[3];
     writeln;
     writeln('Проверка:');
     writeln('невязка1=',nevyzka1:0:10);
     writeln('невязка2=',nevyzka2:0:10);
     writeln('невязка3=',nevyzka3:0:10);
     writeln;
     writeln('Точность:');
     writeln('невязка1:',nevyzka1-0:0:20);
     writeln('невязка2:',nevyzka2-(-2):0:20);
     writeln('невязка3:',nevyzka3-4.2:0:20);
     repeat until keypressed;
end.