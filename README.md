# aahlp

Layout-ignorant text alphabetizer

## Description

`aahlp` (the word `alpha` alphebetized. Clever, no?) will alphabetize only alphabetic characters (a-zA-Z) and leave all others alone. This yields an identically formatted text with only the alphabetic charaters in alphabetical order.

## Installation

```bash
make && sudo make install
```

## Usage

```bash
Usage: aahlp <infile>
```

## Example

Shakespeare's Sonnet 29:

```
  When in disgrace with fortune and men's eyes
  I all alone beweep my outcast state,
  And trouble deaf heaven with my bootless cries,
  And look upon myself, and curse my fate,
  Wishing me like to one more rich in hope,
  Featur'd like him, like him with friends possess'd,
  Desiring this man's art, and that man's scope,
  With what I most enjoy contented least;
  Yet in these thoughts my self almost despising,
  Haply I think on thee,-- and then my state,
  Like to the lark at break of day arising
  From sullen earth, sings hymns at heaven's gate;
	For thy sweet love remember'd such wealth brings
	That then I scorn to change my state with kings.
```

After running through `aahlp`:

```
  aaaa aa AaaAaaaa aaaa aaaaaaa aaa aaa'a aaaa
  a bbb bbbcc cccccc cc ddddddd ddDdd,
  ddd deeeeee eeee eeeeee eeee ee eeeeeeee eeeee,
  eee eeee eeee eeeeee, eee eeeee ee efff,
  fFfffFF gg gggg gg ggg hhhh hhhh hh hhhh,
  hhhHhh'h hhhh hhh, hhhh iii Iiii iiiiiii iiiiiii'I,
  iiiIiiii iiIi ijk'k kkk, kkk klll lll'l lllll,
  llLl llll m mmmm mmmmm mmmmmmmmm mnnnn;
  nnn nn nnnnn nnnnnnnn nn nnnn nnnnnn nnnnooooo,
  ooooo o ooooo oo oooo,-- ooo ooop pp ppppr,
  rrrr rr rrr rrrr rr rrrrr ss sss sssssss
  ssss ssssss sssss, sssss sssss ss sssttt't tttt;
	ttt ttt ttttt tttt tttttttt't tttt tttttt Tttttt
	tuuu uuuu u uvvvW ww wWwWww ww yyyyy yYyy yyyyy.
```

## Disclaimer

Example Shakespeare text used is courtesy of [Project Gutenberg](http://www.gutenberg.org/).
