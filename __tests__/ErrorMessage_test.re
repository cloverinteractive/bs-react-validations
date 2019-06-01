open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("<ErrorMessage />", () => {
  open Expect;

  let wrapper =
    Enzyme.shallow(
      <ErrorMessage> "Some Error Message"->React.string </ErrorMessage>,
    );

  let find = (wrapper, selector) => wrapper |> Enzyme.Shallow.find(selector);

  test("renders children", () =>
    expect(Enzyme.Shallow.text(wrapper)) |> toBe("Some Error Message")
  );

  test("renders a <span />", () =>
    expect(wrapper->find("span") |> Enzyme.Shallow.length) |> toBe(1)
  );

  test("it includes default class", () =>
    expect(wrapper->Enzyme.Shallow.jsProps##className) |> not_ |> toBe("")
  );
});
