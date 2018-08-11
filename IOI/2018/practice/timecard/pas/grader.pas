program grader;

uses timecard;

function readLongint(): longint;
begin
  if eof then begin
    writeln(stderr, 'Error while reading input.');
    halt(1);
  end;
  {$I-}
  readln(readLongint);
  {$I+}
  if ioresult <> 0 then begin
    writeln(stderr, 'Error while reading input.');
    halt(1);
  end;
end;

function readString(): AnsiString;
begin
  if eof then begin
    writeln(stderr, 'Error while reading input.');
    halt(1);
  end;
  {$I-}
  readln(readString);
  {$I+}
  if ioresult <> 0 then begin
    writeln(stderr, 'Error while reading input.');
    halt(1);
  end;
end;

var
  N: longint;
  S: array of AnsiString;
  i: longint;
begin
  N := readLongint();
  setLength(S, N);
  
  for i := 0 to N - 1 do begin
    S[i] := readString();
  end;
  
  init();
  
  for i := 0 to N - 1 do begin
    writeln(convert(S[i]));
  end;
end.
