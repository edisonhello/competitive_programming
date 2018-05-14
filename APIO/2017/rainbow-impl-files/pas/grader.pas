program grader;

uses rainbow;

var
    R, C, M, Q : longint;
    sr, sc : longint;
    S : ansistring;
    query : longint;
    ar, ac, br, bc : longint;

begin
    Readln(R, C, M, Q);
    Readln(sr, sc);
    if M > 0 then
        Readln(S);
    
    init(R, C, sr, sc, M, S);
    for query := 0 to Q - 1 do
    begin
        Readln(ar, ac, br, bc);
        Writeln(colour(ar, ac, br, bc));
    end;
end.
