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

let validationColor = (isValid: bool) => isValid ? royalblue : red;

let styledInput = (isTouched: bool, isValid: bool) => {
  let inputColor = isTouched ? validationColor(isValid) : `hex("666");

  style([
    marginBottom(16->px),
    minHeight(36->px),
    position(relative),
    verticalAlign(middle),
    before([
      border(1->px, `solid, inputColor),
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
};

let styledInnerInput = (isTouched: bool, isValid: bool) => {
  let bulletColor = isTouched ? validationColor(isValid) : transparent;

  style([
    before([
      backgroundColor(bulletColor),
      border(1->px, `solid, bulletColor),
      borderRadius(`percent(100.0)),
      contentRule(""),
      height(8->px),
      position(`absolute),
      right(14->px),
      top(14->px),
      width(8->px),
    ]),
  ]);
};

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
