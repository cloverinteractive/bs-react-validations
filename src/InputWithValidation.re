open BsUuid;

type validation = string => bool;
type validate = (validation, ReactEvent.Keyboard.t) => unit;

type renderState = {
  inputClass: string,
  inputId: string,
  validate: ReactEvent.Keyboard.t => unit,
};

type renderProp = renderState => ReasonReact.reactElement;

let useValidations = (startValid: bool) => {
  let (state, dispatch) = React.useState(() => startValid);

  let validate = (validation, event) => {
    let isValid = event->ReactEvent.Keyboard.target##value->validation;
    dispatch(_ => isValid);
  };

  (state, validate);
};

[@react.component]
let make =
    (
      ~children: ReasonReact.reactElement=React.null,
      ~id: string="",
      ~label: string="",
      ~render: renderProp,
      ~startValid: bool=true,
      ~validation: validation,
    ) => {
  let (isValid, validate) = useValidations(startValid);

  let inputId =
    String.length(id) > 1 ? id : Uuid.V4.create() |> Uuid.V4.toString;

  <div className=Styles.withValidation role="presentation">
    <label className=Styles.label htmlFor=inputId>
      label->React.string
      <div className={Styles.styledInput(isValid)}>
        <div className="styledInnerInput">
          {
            render({
              inputClass: Styles.validatableInput,
              inputId,
              validate: validate(validation),
            })
          }
        </div>
        {isValid ? React.null : children}
      </div>
    </label>
  </div>;
};
