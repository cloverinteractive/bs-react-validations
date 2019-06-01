let emailExpr = [%re "/^([a-z0-9_\\-.])+@([a-z0-9_\\-.])+\\.([a-z]{2,4})$/i"];

let isGreatOrEq = (x: option(int), value: float): bool =>
  switch (x) {
  | Some(x') => float_of_int(x') >= value
  | None => true
  };

let isLowOrEq = (x: option(int), value: float): bool =>
  switch (x) {
  | Some(x') => float_of_int(x') <= value
  | None => true
  };

let isEmail = (value: string): bool => Js.Re.test_(emailExpr, value);

let isIncluded = (xs: list(string), x: string): bool =>
  xs |> List.filter(x' => x' == x) |> List.length >= 1;

let hasLength =
    (~min: option(int)=?, ~max: option(int)=?, (), value: string): bool => {
  let charLength = value->String.length->float_of_int;
  isLowOrEq(min, charLength) && isGreatOrEq(max, charLength);
};

let isNumber = (value: string): bool =>
  !value->Js.Float.fromString->Js.Float.isNaN;

let hasLimit = (~min: option(int)=?, ~max: option(int)=?, (), value: string) =>
  if (isNumber(value)) {
    let parsed = value->Js.Float.fromString;
    isLowOrEq(min, parsed) && isGreatOrEq(max, parsed);
  } else {
    false;
  };

let isPresent = hasLength(~min=1, ());
