module EnhancedInput = {
  open Validations;

  let useValidations = initialState => {
    let (value, setValue) = React.useState(() => initialState);

    let updateInput = (event: ReactEvent.Form.t): unit => {
      let value = event->ReactEvent.Form.target##value;
      setValue(_ => value);
    };

    (value, updateInput);
  };

  [@react.component]
  let make = () => {
    let (value, updateInput) = useValidations("");

    <InputWithValidation
      id="name"
      label="Name*"
      validation={hasLength(~min=5, ())}
      render={
        ({inputClass, inputId, validate}: InputWithValidation.renderState) =>
          <input
            className=inputClass
            id=inputId
            type_="text"
            placeholder="5 Chars min"
            onChange=updateInput
            onKeyUp=validate
            value
          />
      }>
      <ErrorMessage> "Name is invalid"->React.string </ErrorMessage>
    </InputWithValidation>;
  };
};

ReactDOMRe.renderToElementWithId(<EnhancedInput />, "app");
