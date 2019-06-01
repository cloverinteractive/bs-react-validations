let emailExpr = [%bs.re "/^([a-z0-9_\-.])+@([a-z0-9_\-.])+\.([a-z]{2,4})$/i"];

let email = (value: string): bool => Js.Re.test_(emailExpr, value);

let length = (~min: int=5, (), value: string): bool =>
  String.length(value) >= min;

let numericality = (value: string): bool =>
  value->Js.Float.fromString->Js.Float.isNaN;

let presence = length(~min=1, ());

let inclusion = (xs: list(string), x: string): bool =>
  xs |> List.filter(x' => x' == x) |> List.length >= 1;
