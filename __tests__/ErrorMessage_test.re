open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("<ErrorMessage />", () => {
  open Expect;

  let wrapper =
    Enzyme.shallow(
      <ErrorMessage> "Some Error Message"->React.string </ErrorMessage>,
    );

  let find = Enzyme.Shallow.find;
  let length = Enzyme.Shallow.length;
  let props = Enzyme.Shallow.jsProps;
  let text = Enzyme.Shallow.text;

  test("renders children", () =>
    wrapper |> text |> expect |> toBe("Some Error Message")
  );

  test("renders a <span />", () =>
    wrapper |> find("span") |> length |> expect |> toBe(1)
  );

  test("it includes default class", () =>
    wrapper->props##className |> expect |> not_ |> toBe("")
  );
});
