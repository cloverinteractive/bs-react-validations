open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

module ExampleWrapper = {
  [@react.component]
  let make = (~initialText="", ()) => {
    let (value, setValue) = React.useState(() => initialText);

    let updateInput = evt => {
      let value = evt->ReactEvent.Form.target##value;
      setValue(_ => value);
    };

    <ReactValidations
      label="Email"
      validation=Validations.isEmail
      render={
        ({inputClass, inputId, validate}) =>
          <input
            className=inputClass
            id=inputId
            onChange=updateInput
            onKeyUp=validate
            value
          />
      }>
      <ErrorMessage> "Email is invalid"->React.string </ErrorMessage>
    </ReactValidations>;
  };
};

describe("<ReactValidations />", () => {
  open Expect;

  let find = Enzyme.Shallow.find;
  let length = Enzyme.Shallow.length;
  let text = Enzyme.Shallow.text;
  let simulate = Enzyme.Renderer.simulate;

  test("It starts with unvalidated", () => {
    let wrapper = Enzyme.mount(<ExampleWrapper />);
    wrapper |> text |> expect |> not_ |> toContainString("Email is invalid");
  });

  test("Error message renders when invalid", () => {
    let wrapper = Enzyme.mount(<ExampleWrapper initialText="Invalid" />);
    let input = wrapper |> find("input");

    input |> length |> expect |> toBe(1) |> ignore;

    input |> simulate("keyup") |> ignore;

    wrapper |> text |> expect |> toContainString("Email is invalid");
  });

  test("Error message renders when invalid", () => {
    let wrapper =
      Enzyme.mount(<ExampleWrapper initialText="valid@email.tld" />);
    let input = wrapper |> find("input");

    input |> length |> expect |> toBe(1) |> ignore;

    input |> simulate("keyup") |> ignore;

    wrapper |> text |> expect |> not_ |> toContainString("Email is invalid");
  });
});
