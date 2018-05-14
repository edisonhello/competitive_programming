unit rainbow;

interface
    procedure init(R, C, sr, sc, M : longint; S: ansistring);
    function colour(ar, ac, br, bc : longint) : longint;

implementation
    procedure init(R, C, sr, sc, M : longint; S: ansistring);
    begin
    end;

    function colour(ar, ac, br, bc : longint) : longint;
    begin
        colour := 0;
    end;

end.
