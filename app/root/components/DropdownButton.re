let caretImg = [%bs.raw
  {|require("../../assets/images/caret-down.svg").default|}
];

[@react.component]
let make = (~onClick: unit => unit, ~children: React.element) => {
  <div className="c-dropdown-btn" onClick={_ => onClick()}>
    children
    <img className="caret-icon" src=caretImg />
  </div>;
};
