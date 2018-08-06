program grader;

uses dreaming;

procedure fail(s: string);
begin
    writeln(stderr, s);
    halt(1);
end;

var
    N, M, L, i: longint;
    A, B, T: array of Longint;
    f: text;
    answer: longint;

begin
    assign(f, 'dreaming.in');
    {$I-} reset(f); {$I+}
    if IOResult <> 0 then
        fail('Failed to open input file.');

    readln(f, N, M, L);
    setlength(A, M);
    setlength(B, M);
    setlength(T, M);

    for i := 0 to M-1 do
        readln(f, A[i], B[i], T[i]);
    close(f);

    answer := travelTime(N, M, L, A, B, T);

    writeln(answer);
end.
