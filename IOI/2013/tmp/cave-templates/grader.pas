program grader;

uses cave;

{$L graderlib.o}
{$LINKLIB c}

function init : longint; cdecl; external;

var
    N: longint;

begin
	N := init();
	exploreCave(N);
    writeln('INCORRECT');
    writeln('Your solution did not call answer().');
end.
