unit artclass;

interface

type
    artArrayType = array[0..499, 0..499] of longint;

function style(H, W : LongInt; var R, G, B : artArrayType) : LongInt;

implementation

function style(H, W : LongInt; var R, G, B : artArrayType) : LongInt;
begin
    style := 2;
end;

end.
