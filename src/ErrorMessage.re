[@react.component]
let make =
    (
      ~children,
      ~className=Styles.errorMessage,
      ~style=ReactDOMRe.Style.make(),
      (),
    ) =>
  <span className style> children </span>;
