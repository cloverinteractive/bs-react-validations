open Css;

let errorMessage =
  style([
    color(red),
    display(block),
    left(`zero),
    marginBottom(16->px),
    position(`relative),
    textAlign(`center),
  ]);

let withValidation = style([position(relative)]);

let label = style([color(black), display(block), fontSize(15->px)]);

let styledInput = (isValid: bool) =>
  style([
    marginBottom(16->px),
    minHeight(36->px),
    position(relative),
    verticalAlign(middle),
    before([
      border(1->px, `solid, isValid ? grey : red),
      boxSizing(borderBox),
      contentRule(""),
      display(`block),
      display(`contents),
      height(36->px),
      left(`zero),
      maxWidth(`percent(100.0)),
      pointerEvents(`none),
      position(`absolute),
      top(`zero),
      width(`percent(100.0)),
      zIndex(1),
    ]),
  ]);

let noShadow = invalid([boxShadow(~x=`zero, ~y=`zero, `transparent)]);

let validatableInput =
  style([
    background(`transparent),
    border(0->px, `solid, `transparent),
    color(black),
    display(`block),
    fontSize(13->px),
    height(14->px),
    invalid([noShadow]),
    minHeight(36->px),
    paddingLeft(16->px),
    paddingRight(40->px),
    position(relative),
    required([noShadow]),
    width(`percent(100.0)),
    zIndex(5),
  ]);
