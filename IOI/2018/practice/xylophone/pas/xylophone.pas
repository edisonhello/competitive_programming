unit xylophone;

interface

procedure detect_pitch(N: longint);

implementation

uses xylophone_lib;


procedure detect_pitch(N: longint);
var
  x: longint;
  i: longint;
begin
  x := ask(0, N - 1);
  for i := 0 to N - 1 do begin
    answer(i, i);
  end;
end;


end.
