grammar avm;

prog : (line)* EOF;

line: TAB? (comment | instruction SP? comment? EOL? | endofread | EOL) ;

comment : COMMENT;

endofread : ENDOFREAD;

instruction
    : opcode SP values
    | opcode EOL?
    ;

opcode
    : 'push'
    | 'pop'
    | 'dump'
    | 'assert'
    | 'add'
    | 'sub'
    | 'mul'
    | 'div'
    | 'mod'
    | 'print'
    | 'exit'
    ;

values
    : type '(' argument ')'
    ;


type
    : 'int8'
    | 'int16'
    | 'int32'
    | 'float'
    | 'double'
    ;

argument
    : N
    | Z;

SP : ' ';

N : '-'?[0-9]+;

Z : '-'?[0-9]+'.'[0-9]+;

COMMENT :';' ~[;\r\n]* -> skip;

EOL : [\r\n]+;

ENDOFREAD: ';;' .*?~[\r\n]*;

TAB : [ \t]+ -> skip;