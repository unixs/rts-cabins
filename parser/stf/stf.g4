grammar stf;

stf:
  heading
  node
  space?
  node*
  EOF;

heading:
  MAGIC_HEADING;

node:
  nodeName
  space?
  LEFT_PAREN
  space?
  nodeList?
  space?
  RIGHT_PAREN;

space:
  WS+;

nodeName:
  LETTER (LETTER | DIGIT)*;

nodeList:
  nodeListItem (nodeListDelim nodeListItem)*;

nodeListDelim:
  space;

nodeListItem:
  node | term;

term:
  ident | number | string;

string:
  STRING space? ( PLUS space? STRING )*;

ident:
  LETTER+ ( LETTER | DIGIT | DOT | DASH | PLUS )*;

number:
  DASH? DIGIT+ (DOT DIGIT+)?;


MAGIC_HEADING:
  'SIMISA@@@@@@@@@@JINX0t1t______';

LEFT_PAREN:
  '(';

RIGHT_PAREN:
  ')';

STRING:
  '"' .*? '"';

COMMA:
  ',';

PLUS:
  '+';

LETTER:
  [a-zA-Z_];

DIGIT:
  [0-9];

DASH:
  '-';

DOT:
  '.';

WS:
  [ \t];

NEWLINE:
  [\n\r] -> skip;
